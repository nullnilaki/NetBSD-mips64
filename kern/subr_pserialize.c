/*	$NetBSD: subr_pserialize.c,v 1.17 2019/12/05 03:21:29 riastradh Exp $	*/

/*-
 * Copyright (c) 2010, 2011 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * Passive serialization.
 */

#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD: subr_pserialize.c,v 1.17 2019/12/05 03:21:29 riastradh Exp $");

#include <sys/param.h>
#include <sys/atomic.h>
#include <sys/cpu.h>
#include <sys/evcnt.h>
#include <sys/kmem.h>
#include <sys/mutex.h>
#include <sys/pserialize.h>
#include <sys/xcall.h>

struct pserialize {
	lwp_t *			psz_owner;
};

static kmutex_t			psz_lock	__cacheline_aligned;
static struct evcnt		psz_ev_excl	__cacheline_aligned =
    EVCNT_INITIALIZER(EVCNT_TYPE_MISC, NULL, "pserialize", "exclusive access");
EVCNT_ATTACH_STATIC(psz_ev_excl);

/*
 * pserialize_init:
 *
 *	Initialize passive serialization structures.
 */
void
pserialize_init(void)
{

	mutex_init(&psz_lock, MUTEX_DEFAULT, IPL_NONE);
}

/*
 * pserialize_create:
 *
 *	Create and initialize a passive serialization object.
 */
pserialize_t
pserialize_create(void)
{
	pserialize_t psz;

	psz = kmem_zalloc(sizeof(*psz), KM_SLEEP);
	return psz;
}

/*
 * pserialize_destroy:
 *
 *	Destroy a passive serialization object.
 */
void
pserialize_destroy(pserialize_t psz)
{

	KASSERT(psz->psz_owner == NULL);
	kmem_free(psz, sizeof(*psz));
}

/*
 * pserialize_perform:
 *
 *	Perform the write side of passive serialization.  This operation
 *	MUST be serialized at a caller level (e.g. with a mutex or by a
 *	single-threaded use).
 */
void
pserialize_perform(pserialize_t psz)
{

	KASSERT(!cpu_intr_p());
	KASSERT(!cpu_softintr_p());

	if (__predict_false(panicstr != NULL)) {
		return;
	}
	KASSERT(psz->psz_owner == NULL);

	if (__predict_false(mp_online == false)) {
		psz_ev_excl.ev_count++;
		return;
	}

	psz->psz_owner = curlwp;

	/*
	 * Broadcast a NOP to all CPUs and wait until all of them complete.
	 */
	xc_barrier(XC_HIGHPRI);

	KASSERT(psz->psz_owner == curlwp);
	psz->psz_owner = NULL;
	mutex_enter(&psz_lock);
	psz_ev_excl.ev_count++;
	mutex_exit(&psz_lock);
}

int
pserialize_read_enter(void)
{
	int s;

	s = splsoftserial();
	curcpu()->ci_psz_read_depth++;
	__insn_barrier();
	return s;
}

void
pserialize_read_exit(int s)
{

	KASSERT(kpreempt_disabled());

	__insn_barrier();
	if (__predict_false(curcpu()->ci_psz_read_depth-- == 0))
		panic("mismatching pserialize_read_exit()");
	splx(s);
}

/*
 * pserialize_in_read_section:
 *
 *	True if the caller is in a pserialize read section.  To be used
 *	only for diagnostic assertions where we want to guarantee the
 *	condition like:
 *
 *		KASSERT(pserialize_in_read_section());
 */
bool
pserialize_in_read_section(void)
{

	return kpreempt_disabled() && curcpu()->ci_psz_read_depth > 0;
}

/*
 * pserialize_not_in_read_section:
 *
 *	True if the caller is not in a pserialize read section.  To be
 *	used only for diagnostic assertions where we want to guarantee
 *	the condition like:
 *
 *		KASSERT(pserialize_not_in_read_section());
 */
bool
pserialize_not_in_read_section(void)
{
	bool notin;

	kpreempt_disable();
	notin = (curcpu()->ci_psz_read_depth == 0);
	kpreempt_enable();

	return notin;
}
