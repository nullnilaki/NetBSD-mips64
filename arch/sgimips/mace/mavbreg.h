/* $NetBSD: mavbreg.h,v 1.1 2007/04/13 03:37:42 jmcneill Exp $ */
/* $OpenBSD: mavbreg.h,v 1.1 2005/01/02 19:25:41 kettenis Exp $	*/

/*
 * Copyright (c) 2005 Mark Kettenis
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * MACE Moosehead A/V Board register definitions.
 */

#define MAVB_CONTROL				0x00
#define  MAVB_CONTROL_RESET			0x0000000000000001
#define  MAVB_CONTROL_CODEC_PRESENT		0x0000000000000002
#define  MAVB_CONTROL_VOLUME_BUTTON_UP		0x0000000001000000
#define  MAVB_CONTROL_VOLUME_BUTTON_DOWN	0x0000000000800000

#define MAVB_CODEC_CONTROL			0x08
#define  MAVB_CODEC_READ			0x0000000000010000
#define  MAVB_CODEC_WORD_SHIFT			0
#define  MAVB_CODEC_WORD_MASK			0x000000000000ffff
#define  MAVB_CODEC_ADDRESS_SHIFT		17
#define  MAVB_CODEC_ADDRESS_MASK		0x000000000000001f

#define MAVB_CODEC_STATUS			0x18
#define MAVB_CHANNEL1_CONTROL			0x20
#define MAVB_CHANNEL2_CONTROL			0x40
#define MAVB_CHANNEL3_CONTROL			0x60
#define  MAVB_CHANNEL_RESET			0x0000000000000400
#define  MAVB_CHANNEL_DMA_ENABLE		0x0000000000000200
#define  MAVB_CHANNEL_INT_DISABLED		0x0000000000000000
#define  MAVB_CHANNEL_INT_25			0x0000000000000020
#define  MAVB_CHANNEL_INT_50			0x0000000000000040
#define  MAVB_CHANNEL_INT_75			0x0000000000000060
#define  MAVB_CHANNEL_INT_EMPTY			0x0000000000000080
#define  MAVB_CHANNEL_INT_NOT_EMPTY		0x00000000000000a0
#define  MAVB_CHANNEL_INT_FULL			0x00000000000000c0
#define  MAVB_CHANNEL_INT_NOT_FULL		0x00000000000000e0

#define MAVB_CHANNEL1_READ_PTR			0x28
#define MAVB_CHANNEL1_WRITE_PTR			0x30
#define MAVB_CHANNEL1_DEPTH			0x38
#define MAVB_CHANNEL2_READ_PTR			0x48
#define MAVB_CHANNEL2_WRITE_PTR			0x50
#define MAVB_CHANNEL2_DEPTH			0x58

#define MAVB_NREGS				0x80
