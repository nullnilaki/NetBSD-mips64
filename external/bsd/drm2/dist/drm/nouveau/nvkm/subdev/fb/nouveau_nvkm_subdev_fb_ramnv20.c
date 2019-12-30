/*	$NetBSD: nouveau_nvkm_subdev_fb_ramnv20.c,v 1.2 2018/08/27 04:58:33 riastradh Exp $	*/

/*
 * Copyright 2013 Red Hat Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors: Ben Skeggs
 */
#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD: nouveau_nvkm_subdev_fb_ramnv20.c,v 1.2 2018/08/27 04:58:33 riastradh Exp $");

#include "ram.h"

int
nv20_ram_new(struct nvkm_fb *fb, struct nvkm_ram **pram)
{
	struct nvkm_device *device = fb->subdev.device;
	u32 pbus1218 =  nvkm_rd32(device, 0x001218);
	u32     size = (nvkm_rd32(device, 0x10020c) & 0xff000000);
	u32     tags =  nvkm_rd32(device, 0x100320);
	enum nvkm_ram_type type = NVKM_RAM_TYPE_UNKNOWN;
	int ret;

	switch (pbus1218 & 0x00000300) {
	case 0x00000000: type = NVKM_RAM_TYPE_SDRAM; break;
	case 0x00000100: type = NVKM_RAM_TYPE_DDR1 ; break;
	case 0x00000200: type = NVKM_RAM_TYPE_GDDR3; break;
	case 0x00000300: type = NVKM_RAM_TYPE_GDDR2; break;
	}

	ret = nvkm_ram_new_(&nv04_ram_func, fb, type, size, tags, pram);
	if (ret)
		return ret;

	(*pram)->parts = (nvkm_rd32(device, 0x100200) & 0x00000003) + 1;
	return 0;
}
