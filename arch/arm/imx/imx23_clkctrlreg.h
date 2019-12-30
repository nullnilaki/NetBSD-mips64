/* $Id: imx23_clkctrlreg.h,v 1.2 2013/10/07 17:36:40 matt Exp $ */

/*
 * Copyright (c) 2012 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Petri Laakso.
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

#ifndef _ARM_IMX_IMX23_CLKCTRLREG_H_
#define _ARM_IMX_IMX23_CLKCTRLREG_H_

#include <sys/cdefs.h>

#define HW_CLKCTRL_BASE 0x80040000
#define HW_CLKCTRL_SIZE	0x2000

/*
 * PLL Control Register 0.
 */
#define HW_CLKCTRL_PLLCTRL0	0x000
#define HW_CLKCTRL_PLLCTRL0_SET	0x004
#define HW_CLKCTRL_PLLCTRL0_CLR	0x008
#define HW_CLKCTRL_PLLCTRL0_TOG	0x00C

#define HW_CLKCTRL_PLLCTRL0_RSRVD6	__BITS(31, 30)
#define HW_CLKCTRL_PLLCTRL0_LFR_SEL	__BITS(29, 28)
#define HW_CLKCTRL_PLLCTRL0_RSRVD5	__BITS(27, 26)
#define HW_CLKCTRL_PLLCTRL0_CP_SEL	__BITS(25, 24)
#define HW_CLKCTRL_PLLCTRL0_RSRVD4	__BITS(23, 22)
#define HW_CLKCTRL_PLLCTRL0_DIV_SEL	__BITS(21, 20)
#define HW_CLKCTRL_PLLCTRL0_RSRVD3	__BIT(19)
#define HW_CLKCTRL_PLLCTRL0_EN_USB_CLKS	__BIT(18)
#define HW_CLKCTRL_PLLCTRL0_RSRVD2	__BIT(17)
#define HW_CLKCTRL_PLLCTRL0_POWER	__BIT(16)
#define HW_CLKCTRL_PLLCTRL0_RSRVD1	__BITS(15, 0)

/*
 * PLL Control Register 1.
 */
#define HW_CLKCTRL_PLLCTRL1	0x010

#define HW_CLKCTRL_PLLCTRL1_LOCK	__BIT(31)
#define HW_CLKCTRL_PLLCTRL1_FORCE_LOCK	__BIT(30)
#define HW_CLKCTRL_PLLCTRL1_RSRVD1	__BITS(29, 16)
#define HW_CLKCTRL_PLLCTRL1_LOCK_COUNT	__BITS(15, 0)

/*
 * CPU Clock Control Register.
 */
#define HW_CLKCTRL_CPU		0x020
#define HW_CLKCTRL_CPU_SET	0x024
#define HW_CLKCTRL_CPU_CLR	0x028
#define HW_CLKCTRL_CPU_TOG	0x02c

#define HW_CLKCTRL_CPU_RSVD6		__BITS(31, 30)
#define HW_CLKCTRL_CPU_BUSY_REF_XTAL	__BIT(29)
#define HW_CLKCTRL_CPU_BUSY_REF_CPU	__BIT(28)
#define HW_CLKCTRL_CPU_RSVD5		__BIT(27)
#define HW_CLKCTRL_CPU_DIV_XTAL_FRAC_EN	__BIT(26)
#define HW_CLKCTRL_CPU_DIV_XTAL		__BITS(25, 16)
#define HW_CLKCTRL_CPU_RSVD4		__BITS(15, 13)
#define HW_CLKCTRL_CPU_INTERRUPT_WAIT	__BIT(12)
#define HW_CLKCTRL_CPU_RSVD3		__BIT(11)
#define HW_CLKCTRL_CPU_RSVD2		__BIT(10)
#define HW_CLKCTRL_CPU_RSVD1		__BITS(9, 6)
#define HW_CLKCTRL_CPU_DIV_CPU		__BITS(5, 0)

/*
 * AHB, APBH Bus Clock Control Register.
 */
#define HW_CLKCTRL_HBUS		0x030
#define HW_CLKCTRL_HBUS_SET	0x034
#define HW_CLKCTRL_HBUS_CLR	0x038
#define HW_CLKCTRL_HBUS_TOG	0x03c

#define HW_CLKCTRL_HBUS_RSRVD4			__BITS(31, 30)
#define HW_CLKCTRL_HBUS_BUSY			__BIT(29)
#define HW_CLKCTRL_HBUS_DCP_AS_ENABLE		__BIT(28)
#define HW_CLKCTRL_HBUS_PXP_AS_ENABLE		__BIT(27)
#define HW_CLKCTRL_HBUS_APBHDMA_AS_ENABLE	__BIT(26)
#define HW_CLKCTRL_HBUS_APBXDMA_AS_ENABLE	__BIT(25)
#define HW_CLKCTRL_HBUS_TRAFFIC_JAM_AS_ENABLE	__BIT(24)
#define HW_CLKCTRL_HBUS_TRAFFIC_AS_ENABLE	__BIT(23)
#define HW_CLKCTRL_HBUS_CPU_DATA_AS_ENABLE	__BIT(22)
#define HW_CLKCTRL_HBUS_CPU_INSTR_AS_ENABLE	__BIT(21)
#define HW_CLKCTRL_HBUS_AUTO_SLOW_MODE		__BIT(20)
#define HW_CLKCTRL_HBUS_RSRVD2			__BIT(19)
#define HW_CLKCTRL_HBUS_SLOW_DIV		__BITS(18, 16)
#define HW_CLKCTRL_HBUS_RSRVD1			__BITS(15, 6)
#define HW_CLKCTRL_HBUS_DIV_FRAC_EN		__BIT(5)
#define HW_CLKCTRL_HBUS_DIV			__BITS(4, 0)

/*
 * APBX Clock Control Register.
 */
#define HW_CLKCTRL_XBUS	0x040

#define HW_CLKCTRL_XBUS_BUSY	__BIT(31)
#define HW_CLKCTRL_XBUS_RSVD2	__BITS(30, 11)
#define HW_CLKCTRL_XBUS_RSVD1	__BIT(10)
#define HW_CLKCTRL_XBUS_DIV	__BITS(9, 0)

/*
 * XTAL Clock Control Register.
 */
#define HW_CLKCTRL_XTAL		0x050
#define HW_CLKCTRL_XTAL_SET	0x054
#define HW_CLKCTRL_XTAL_CLR	0x058
#define HW_CLKCTRL_XTAL_TOG	0x05C

#define HW_CLKCTRL_XTAL_UART_CLK_GATE		__BIT(31)
#define HW_CLKCTRL_XTAL_FILT_CLK24M_GATE	__BIT(30)
#define HW_CLKCTRL_XTAL_PWM_CLK24M_GATE		__BIT(29)
#define HW_CLKCTRL_XTAL_DRI_CLK24M_GATE		__BIT(28)
#define HW_CLKCTRL_XTAL_DIGCTRL_CLK1M_GATE	__BIT(27)
#define HW_CLKCTRL_XTAL_TIMROT_CLK32K_GATE	__BIT(26)
#define HW_CLKCTRL_XTAL_RSRVD1			__BITS(25, 2)
#define HW_CLKCTRL_XTAL_DIV_UART		__BITS(1, 0)

/*
 * PIX (LCDIF) Clock Control Register.
 */
#define HW_CLKCTRL_PIX	0x060

#define HW_CLKCTRL_PIX_CLKGATE	__BIT(31)
#define HW_CLKCTRL_PIX_RSRVD2	__BIT(30)
#define HW_CLKCTRL_PIX_BUSY	__BIT(29)
#define HW_CLKCTRL_PIX_RSRVD1	__BITS(28, 13)
#define HW_CLKCTRL_PIX_DIV_FRAC_EN	__BIT(12)
#define HW_CLKCTRL_PIX_DIV	__BITS(11, 0)

/*
 * Synchronous Serial Port Clock Control Register.
 */
#define HW_CLKCTRL_SSP	0x070

#define HW_CLKCTRL_SSP_CLKGATE	__BIT(31)
#define HW_CLKCTRL_SSP_RSVD3	__BIT(30)
#define HW_CLKCTRL_SSP_BUSY	__BIT(29)
#define HW_CLKCTRL_SSP_RSVD2	__BITS(28, 10)
#define HW_CLKCTRL_SSP_RSVD1	__BIT(9)
#define HW_CLKCTRL_SSP_DIV	__BITS(8, 0)

/*
 * General-Purpose Media Interface Clock Control Register.
 */
#define HW_CLKCTRL_GPMI	0x080

#define HW_CLKCTRL_GPMI_CLKGATE	__BIT(31)
#define HW_CLKCTRL_GPMI_RSVD3	__BIT(30)
#define HW_CLKCTRL_GPMI_BUSY	__BIT(29)
#define HW_CLKCTRL_GPMI_RSVD2	__BITS(28, 11)
#define HW_CLKCTRL_GPMI_RSVD1	__BIT(10)
#define HW_CLKCTRL_GPMI_DIV	__BIT(9, 0)

/*
 * SPDIF Clock Control Register.
 */
#define HW_CLKCTRL_SPDIF	0x090

#define HW_CLKCTRL_SPDIF_CLKGATE	__BIT(31)
#define HW_CLKCTRL_SPDIF_RSRVD		__BITS(30, 0)

/*
 * EMI Clock Control Register.
 */
#define HW_CLKCTRL_EMI	0x0a0

#define HW_CLKCTRL_EMI_CLKGATE		__BIT(31)
#define HW_CLKCTRL_EMI_SYNC_MODE_EN	__BIT(30)
#define HW_CLKCTRL_EMI_BUSY_REF_XTAL	__BIT(29)
#define HW_CLKCTRL_EMI_BUSY_REF_EMI	__BIT(28)
#define HW_CLKCTRL_EMI_BUSY_REF_CPU	__BIT(27)
#define HW_CLKCTRL_EMI_BUSY_SYNC_MODE	__BIT(26)
#define HW_CLKCTRL_EMI_RSVD5		__BITS(25, 18)
#define HW_CLKCTRL_EMI_RSVD4		__BIT(17)
#define HW_CLKCTRL_EMI_RSVD3		__BIT(16)
#define HW_CLKCTRL_EMI_RSVD2		__BITS(15, 12)
#define HW_CLKCTRL_EMI_DIV_XTAL		__BITS(11, 8)
#define HW_CLKCTRL_EMI_RSVD1		__BITS(7, 6)
#define HW_CLKCTRL_EMI_DIV_EMI		__BITS(5, 0)

/*
 * SAIF Clock Control Register.
 */
#define HW_CLKCTRL_SAIF	0x0c0

#define HW_CLKCTRL_SAIF_CLKGATE		__BIT(31)
#define HW_CLKCTRL_SAIF_RSRVD2		__BIT(30)
#define HW_CLKCTRL_SAIF_BUSY		__BIT(29)
#define HW_CLKCTRL_SAIF_RSRVD1		__BITS(28, 17)
#define HW_CLKCTRL_SAIF_DIV_FRAC_EN	__BIT(16)
#define HW_CLKCTRL_SAIF_DIV		__BITS(15, 0)

/*
 * TV Encoder Clock Control Register.
 */
#define HW_CLKCTRL_TV	0x0d0

#define HW_CLKCTRL_TV_CLK_TV108M_GATE	__BIT(31)
#define HW_CLKCTRL_TV_CLK_TV_GATE	__BIT(30)
#define HW_CLKCTRL_TV_RSRVD		__BITS(29, 0)

/*
 * ETM Clock Control Register.
 */
#define HW_CLKCTRL_ETM	0x0e0

#define HW_CLKCTRL_ETM_CLKGATE		__BIT(31)
#define HW_CLKCTRL_ETM_RSRVD2		__BIT(30)
#define HW_CLKCTRL_ETM_BUSY		__BIT(29)
#define HW_CLKCTRL_ETM_RSRVD1		__BITS(28, 7)
#define HW_CLKCTRL_ETM_DIV_FRAC_EN	__BIT(6)
#define HW_CLKCTRL_ETM_DIV		__BITs(5, 0)

/*
 * Fractional Clock Control Register.
 */
#define HW_CLKCTRL_FRAC		0x0f0
#define HW_CLKCTRL_FRAC_SET	0x0f4
#define HW_CLKCTRL_FRAC_CLR	0x0f8
#define HW_CLKCTRL_FRAC_TOG	0x0fC

#define HW_CLKCTRL_FRAC_CLKGATEIO	__BIT(31)
#define HW_CLKCTRL_FRAC_IO_STABLE	__BIT(30)
#define HW_CLKCTRL_FRAC_IOFRAC		__BITS(29, 24)
#define HW_CLKCTRL_FRAC_CLKGATEPIX	__BIT(23)
#define HW_CLKCTRL_FRAC_PIX_STABLE	__BIT(22)
#define HW_CLKCTRL_FRAC_PIXFRAC		__BITS(21, 16)
#define HW_CLKCTRL_FRAC_CLKGATEEMI	__BIT(15)
#define HW_CLKCTRL_FRAC_EMI_STABLE	__BIT(14)
#define HW_CLKCTRL_FRAC_EMIFRAC		__BITS(13, 8)
#define HW_CLKCTRL_FRAC_CLKGATECPU	__BIT(7)
#define HW_CLKCTRL_FRAC_CPU_STABLE	__BIT(6)
#define HW_CLKCTRL_FRAC_CPUFRAC		__BITS(5, 0)

/*
 * Fractional Clock Control Register 1.
 */
#define HW_CLKCTRL_FRAC1	0x100
#define HW_CLKCTRL_FRAC1_SET	0x104
#define HW_CLKCTRL_FRAC1_CLR	0x108
#define HW_CLKCTRL_FRAC1_TOG	0x10C

#define HW_CLKCTRL_FRAC1_CLKGATEVID	__BIT(31)
#define HW_CLKCTRL_FRAC1_VID_STABLE	__BIT(30)
#define HW_CLKCTRL_FRAC1_RSRVD1		__BITS(29, 0)

/*
 * Clock Frequency Sequence Control Register.
 */
#define HW_CLKCTRL_CLKSEQ	0x110
#define HW_CLKCTRL_CLKSEQ_SET	0x114
#define HW_CLKCTRL_CLKSEQ_CLR	0x118
#define HW_CLKCTRL_CLKSEQ_TOG	0x11c

#define HW_CLKCTRL_CLKSEQ_RSRVD1	__BITS(31, 9)
#define HW_CLKCTRL_CLKSEQ_BYPASS_ETM	__BIT(8)
#define HW_CLKCTRL_CLKSEQ_BYPASS_CPU	__BIT(7)
#define HW_CLKCTRL_CLKSEQ_BYPASS_EMI	__BIT(6)
#define HW_CLKCTRL_CLKSEQ_BYPASS_SSP	__BIT(5)
#define HW_CLKCTRL_CLKSEQ_BYPASS_GPMI	__BIT(4)
#define HW_CLKCTRL_CLKSEQ_BYPASS_IR	__BIT(3)
#define HW_CLKCTRL_CLKSEQ_RSRVD0	__BIT(2)
#define HW_CLKCTRL_CLKSEQ_BYPASS_PIX	__BIT(1)
#define HW_CLKCTRL_CLKSEQ_BYPASS_SAIF	__BIT(0)

/*
 * System Software Reset Register.
 */
#define HW_CLKCTRL_RESET	0x120

#define HW_CLKCTRL_RESET_RSRVD	__BITS(31, 2)
#define HW_CLKCTRL_RESET_CHIP	__BIT(1)
#define HW_CLKCTRL_RESET_DIG	__BIT(0)

/*
 * CLKCTRL Status.
 */
#define HW_CLKCTRL_STATUS	0x130

#define HW_CLKCTRL_STATUS_CPU_LIMIT	__BITS(31, 30)
#define HW_CLKCTRL_STATUS_RSRVD		__BITS(29, 0)

/*
 * CLKCTRL Version Register.
 */
#define HW_CLKCTRL_VERSION	0x140

#define HW_CLKCTRL_VERSION_MAJOR	__BITS(31, 24)
#define HW_CLKCTRL_VERSION_MINOR	__BITS(23, 16)
#define HW_CLKCTRL_VERSION_STEP		__BITS(15, 0)

#endif /* !_ARM_IMX_IMX23_CLKCTRLREG_H_ */
