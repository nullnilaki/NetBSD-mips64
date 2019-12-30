/*	$NetBSD: vmparam.h,v 1.39 2019/06/28 15:17:44 tsutsui Exp $	*/

/*
 * Copyright (c) 1988 University of Utah.
 * Copyright (c) 1982, 1986, 1990, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * the Systems Programming Group of the University of Utah Computer
 * Science Department.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * from: Utah $Hdr: vmparam.h 1.16 91/01/18$
 *
 *	@(#)vmparam.h	8.2 (Berkeley) 4/19/94
 */

#ifndef _X68K_VMPARAM_H_
#define	_X68K_VMPARAM_H_

/*
 * Machine dependent constants for X68K
 */

/*
 * hp300 pmap derived m68k ports can use 4K or 8K pages.
 * The page size is specified by PGSHIFT in <machine/param.h>.
 * Override the PAGE_* definitions to be compile-time constants.
 */
#define	PAGE_SHIFT	PGSHIFT
#define	PAGE_SIZE	(1 << PAGE_SHIFT)
#define	PAGE_MASK	(PAGE_SIZE - 1)

/*
 * USRSTACK is the top (end) of the user stack.
 */
#define	USRSTACK	VM_MAXUSER_ADDRESS	/* Start of user stack */

/*
 * Virtual memory related constants, all in bytes
 */
#ifndef MAXTSIZ
#define	MAXTSIZ		(32*1024*1024)		/* max text size */
#endif
#ifndef DFLDSIZ
#define	DFLDSIZ		(16*1024*1024)		/* initial data size limit */
#endif
#ifndef MAXDSIZ
#define	MAXDSIZ		(64*1024*1024)		/* max data size */
#endif
#ifndef	DFLSSIZ
#define	DFLSSIZ		(512*1024)		/* initial stack size limit */
#endif
#ifndef	MAXSSIZ
#define	MAXSSIZ		MAXDSIZ			/* max stack size */
#endif

/*
 * PTEs for mapping user space into the kernel for phyio operations.
 * One page is enough to handle 4Mb of simultaneous raw IO operations.
 */
#ifndef USRIOSIZE
#define USRIOSIZE	(1 * NPTEPG)	/* 4mb */
#endif

/*
 * Mach derived constants
 */

/* user/kernel map constants */
#define VM_MIN_ADDRESS		((vaddr_t)0)
#define VM_MAXUSER_ADDRESS	((vaddr_t)0xFFF00000)
#define VM_MAX_ADDRESS		((vaddr_t)0xFFF00000)
#define VM_MIN_KERNEL_ADDRESS	((vaddr_t)0)
#define VM_MAX_KERNEL_ADDRESS	((vaddr_t)(0-PAGE_SIZE*NPTEPG))

/* virtual sizes (bytes) for various kernel submaps */
#define VM_PHYS_SIZE		(USRIOSIZE*PAGE_SIZE)

/* # of kernel PT pages (initial only, can grow dynamically) */
#define VM_KERNEL_PT_PAGES	((vsize_t)4)

/*
 * Constants which control the way the VM system deals with memory segments.
 */
#define	VM_PHYSSEG_MAX		3
#define VM_PHYSSEG_STRAT	VM_PSTRAT_BIGFIRST
				/* Actually VM_PSTRAT_UPPERFIRST is needed */

#define	VM_NFREELIST		2
#define	VM_FREELIST_DEFAULT	0
#define	VM_FREELIST_HIGHMEM	VM_FREELIST_DEFAULT
#define	VM_FREELIST_MAINMEM	1

#define	__HAVE_PMAP_PHYSSEG

/*
 * pmap-specific data stored in the vm_physmem[] array.
 */
struct pmap_physseg {
	struct pv_header *pvheader;	/* pv table for this seg */
};

#endif /* _X68K_VMPARAM_H_ */
