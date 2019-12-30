/* $NetBSD: if_admswreg.h,v 1.1 2007/03/20 08:52:02 dyoung Exp $ */

/*-
 * Copyright (c) 2007 Ruslan Ermilov and Vsevolod Lobko.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or
 * without modification, are permitted provided that the following
 * conditions are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 * 3. The names of the authors may not be used to endorse or promote
 *    products derived from this software without specific prior
 *    written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
 * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 */
/*
 * Copyright (c) 2001 Wasabi Systems, Inc.
 * All rights reserved.
 *
 * Written by Jason R. Thorpe for Wasabi Systems, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed for the NetBSD Project by
 *	Wasabi Systems, Inc.
 * 4. The name of Wasabi Systems, Inc. may not be used to endorse
 *    or promote products derived from this software without specific prior
 *    written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef	_IF_ADMSWREG_H_
#define	_IF_ADMSWREG_H_

/* ADMSW_ definitions Copyright (c) 2007 David Young. */
#define	ADMSW_BOOT_DONE		0x0008
#define	ADMSW_BOOT_DONE_BO	__BIT(0)
#define	ADMSW_SW_RES		0x000c
#define	ADMSW_SW_RES_SWR	__BITS(31, 0)
#define	ADMSW_INT_ST		0x00b0
#define	ADMSW_INT_MASK		0x00b4

#define	ADMSW_INTR_RSVD	__BITS(31, 25)
#define	ADMSW_INTR_CPUH	__BIT(24)
#define	ADMSW_INTR_SDE	__BIT(23)
#define	ADMSW_INTR_RDE	__BIT(22)
#define	ADMSW_INTR_W1TE	__BIT(21)
#define	ADMSW_INTR_W0TE	__BIT(20)
#define	ADMSW_INTR_MI	__BIT(19)
#define	ADMSW_INTR_PSC	__BIT(18)
#define	ADMSW_INTR_BCS	__BIT(16)
#define	ADMSW_INTR_MD	__BIT(15)
#define	ADMSW_INTR_GQF	__BIT(14)
#define	ADMSW_INTR_CPQ	__BIT(13)
#define	ADMSW_INTR_P5QF	__BIT(11)
#define	ADMSW_INTR_P4QF	__BIT(10)
#define	ADMSW_INTR_P3QF	__BIT(9)
#define	ADMSW_INTR_P2QF	__BIT(8)
#define	ADMSW_INTR_P1QF	__BIT(7)
#define	ADMSW_INTR_P0QF	__BIT(6)
#define	ADMSW_INTR_LDF	__BIT(5)
#define	ADMSW_INTR_HDF	__BIT(4)
#define	ADMSW_INTR_RLD	__BIT(3)
#define	ADMSW_INTR_RHD	__BIT(2)
#define	ADMSW_INTR_SLD	__BIT(1)
#define	ADMSW_INTR_SHD	__BIT(0)

#define	ADMSW_INT_FMT	\
	"\x10"\
	"\x01SHD"\
	"\x02SLD"\
	"\x03RHD"\
	"\x04RLD"\
	"\x05HDF"\
	"\x06LDF"\
	"\x07P0QF"\
	"\x08P1QF"\
	"\x09P2QF"\
	"\x0aP3QF"\
	"\x0bP4QF"\
	"\x0cP5QF"\
	"\x0e"\
	"CPQ"\
	"\x0fGQF"\
	"\x10MD"\
	"\x11"\
	"BCS"\
	"\x13PSC"\
	"\x14MI"\
	"\x15W0TE"\
	"\x16W1TE"\
	"\x17RDE"\
	"\x18SDE"\
	"\x19"\
	"CPUH"

#define	CODE_REG		0x0000
#define	SFTREST_REG		0x0004
#define	BOOT_DONE_REG		0x0008
#define	GLOBAL_ST_REG		0x0010
#define	PHY_ST_REG		0x0014
#define		PHY_ST_LINKUP		(1 << 0)
#define		PHY_ST_100M		(1 << 8)
#define		PHY_ST_FDX		(1 << 16)
#define	PORT_ST_REG		0x0018
#define	MEM_CONTROL_REG		0x001C	
#define	SW_CONF_REG		0x0020

#define	CPUP_CONF_REG		0x0024
#define		CPUP_CONF_DCPUP		0x00000001
#define		CPUP_CONF_CRCP		0x00000002
#define		CPUP_CONF_BTM		0x00000004
#define		CPUP_CONF_DUNP_SHIFT	9
#define		CPUP_CONF_DUNP_MASK	(0x3F << CPUP_CONF_DUNP_SHIFT)
#define		CPUP_CONF_DMCP_SHIFT	16
#define		CPUP_CONF_DMCP_MASK	(0x3F << CPUP_CONF_DMCP_SHIFT)
#define		CPUP_CONF_DBCP_SHIFT	24
#define		CPUP_CONF_DBCP_MASK	(0x3F << CPUP_CONF_DBCP_SHIFT)

#define	PORT_CONF0_REG		0x0028
#define		PORT_CONF0_DP_MASK	0x0000003F
#define		PORT_CONF0_EMCP_MASK	0x00003F00
#define		PORT_CONF0_EMCP_SHIFT	8
#define		PORT_CONF0_EMBP_MASK	0x003F0000
#define		PORT_CONF0_EMBP_SHIFT	16
#define	PORT_CONF1_REG		0x002C
#define	PORT_CONF2_REG		0x0030

#define	VLAN_G1_REG		0x0040
#define	VLAN_G2_REG		0x0044
#define	SEND_TRIG_REG		0x0048
#define	SRCH_CMD_REG		0x004C
#define	ADDR_ST0_REG		0x0050
#define	ADDR_ST1_REG		0x0054
#define	MAC_WT0_REG		0x0058
#define		MAC_WT0_WRITE	0x00000001
#define		MAC_WT0_WRITE_DONE	0x00000002
#define		MAC_WT0_FILTER_EN	0x00000004
#define		MAC_WT0_VLANID_SHIFT	3
#define		MAC_WT0_VLANID_MASK	0x00000038
#define		MAC_WT0_VLANID_EN	0x00000040
#define		MAC_WT0_PORTMAP_MASK	0x00001F80
#define		MAC_WT0_PORTMAP_SHIFT	7
#define		MAC_WT0_AGE_MASK	(0x7	<<	13)
#define		MAC_WT0_AGE_STATIC	(0x7	<<	13)
#define		MAC_WT0_AGE_VALID	(0x1	<<	13)
#define		MAC_WT0_AGE_EMPTY	0
#define	MAC_WT1_REG		0x005C
#define	BW_CNTL0_REG		0x0060
#define	BW_CNTL1_REG		0x0064
#define	PHY_CNTL0_REG		0x0068
#define	PHY_CNTL1_REG		0x006C
#define	FC_TH_REG		0x0070
#define		FC_TH_FCS_MASK		0x01FF0000
#define		FC_TH_D2R_MASK		0x0000FF00
#define		FC_TH_D2S_MASK		0x000000FF
#define	ADJ_PORT_TH_REG		0x0074
#define	PORT_TH_REG		0x0078
#define	PHY_CNTL2_REG		0x007C
#define		PHY_CNTL2_AUTONEG	(1 << 0)
#define		PHY_CNTL2_ANE_MASK	0x0000001F
#define		PHY_CNTL2_SC_MASK	0x000003E0
#define		PHY_CNTL2_SC_SHIFT	5
#define		PHY_CNTL2_100M		(1 << PHY_CNTL2_SC_SHIFT)
#define		PHY_CNTL2_DC_MASK	0x00007C00
#define		PHY_CNTL2_DC_SHIFT	10
#define		PHY_CNTL2_FDX		(1 << PHY_CNTL2_DC_SHIFT)
#define		PHY_CNTL2_RFCV_MASK	0x000F8000
#define		PHY_CNTL2_RFCV_SHIFT	15
#define		PHY_CNTL2_PHYR_MASK	0x01F00000
#define		PHY_CNTL2_PHYR_SHIFT	20
#define		PHY_CNTL2_AMDIX_MASK	0x3E000000
#define		PHY_CNTL2_AMDIX_SHIFT	25
#define		PHY_CNTL2_RMAE		0x40000000
#define	PHY_CNTL3_REG		0x0080
#define 	PHY_CNTL3_RNT         0x00000400

#define	PRI_CNTL_REG		0x0084
#define	VLAN_PRI_REG		0x0088
#define	TOS_EN_REG		0x008C
#define	TOS_MAP0_REG		0x0090
#define	TOS_MAP1_REG		0x0094
#define	CUSTOM_PRI1_REG		0x0098
#define	CUSTOM_PRI2_REG		0x009C

#define	EMPTY_CNT_REG		0x00A4
#define	PORT_CNT_SEL_REG	0x00A8
#define	PORT_CNT_REG		0x00AC

#define	INT_MASK	0x1FDEFFF

#define	GPIO_CONF0_REG		0x00B8
#define	GPIO_CONF2_REG		0x00BC

#define	SWAP_IN_REG		0x00C8
#define	SWAP_OUT_REG		0x00CC

#define	SEND_HBADDR_REG		0x00D0
#define	SEND_LBADDR_REG		0x00D4
#define	RECV_HBADDR_REG		0x00D8
#define	RECV_LBADDR_REG		0x00DC
#define	SEND_HWADDR_REG		0x00E0
#define	SEND_LWADDR_REG		0x00E4
#define	RECV_HWADDR_REG		0x00E8
#define	RECV_LWADDR_REG		0x00EC

#define	TIMER_INT_REG		0x00F0
#define	TIMER_REG		0x00F4

#define	PORT0_LED_REG		0x0100
#define	PORT1_LED_REG		0x0104
#define	PORT2_LED_REG		0x0108
#define	PORT3_LED_REG		0x010c
#define	PORT4_LED_REG		0x0110

/* Hardware descriptor format */
struct admsw_desc {
        volatile uint32_t data;
        volatile uint32_t cntl;
        volatile uint32_t len;
        volatile uint32_t status;
} __attribute__((__packed__, __aligned__(4)));

#define ADM5120_DMA_MASK        0x01ffffff
#define ADM5120_DMA_OWN         0x80000000      /* buffer owner */
#define ADM5120_DMA_RINGEND     0x10000000      /* Last in DMA ring */
#define ADM5120_DMA_BUF2ENABLE	0x80000000

#define ADM5120_DMA_PORTID      0x00007000
#define ADM5120_DMA_PORTSHIFT   12
#define ADM5120_DMA_LEN         0x07ff0000
#define ADM5120_DMA_LENSHIFT    16
#define	ADM5120_DMA_TYPE	0x00000003
#define	ADM5120_DMA_TYPE_IP	0x00000000
#define	ADM5120_DMA_TYPE_PPPOE	0x00000001
#define	ADM5120_DMA_CSUM	0x80000000
#define	ADM5120_DMA_CSUMFAIL	0x00000008

#define SW_DEVS 6

#if 0
/*	CODE_REG	*/
#define	CODE_ID_MASK	0x00FFFF
#define	CODE_ADM5120_ID	0x5120

#define	CODE_REV_MASK	0x0F0000
#define	CODE_REV_SHIFT	16
#define	CODE_REV_ADM5120_0	0x8

#define	CODE_CLK_MASK	0x300000
#define	CODE_CLK_SHIFT	20

#define	CPU_CLK_175MHZ	0x0
#define	CPU_CLK_200MHZ	0x1
#define	CPU_CLK_225MHZ	0x2
#define	CPU_CLK_250MHZ	0x3

#define	CPU_SPEED_175M	(175000000/2)
#define	CPU_SPEED_200M	(200000000/2)
#define	CPU_SPEED_225M	(225000000/2)
#define	CPU_SPEED_250M	(250000000/2)

#define	CPU_NAND_BOOT	0x01000000
#define	CPU_DCACHE_2K_WAY	(0x1	<<	25)
#define	CPU_DCACHE_2WAY	(0x1	<<	26)
#define	CPU_ICACHE_2K_WAY	(0x1	<<	27)
#define	CPU_ICACHE_2WAY	(0x1	<<	28)

#define	CPU_GMII_SUPPORT	0x20000000

#define	CPU_PQFP_MODE	(0x1	<<	29)

#define	CPU_CACHE_LINE_SIZE	16

/*	SftRest_REG	*/
#define	SOFTWARE_RESET	0x1

/*	Boot_done_REG	*/
#define	BOOT_DONE	0x1

/*	SWReset_REG	*/
#define	SWITCH_RESET	0x1

/*	Global_St_REG	*/
#define	DATA_BUF_BIST_FAILED	(0x1	<<	0)
#define	LINK_TAB_BIST_FAILED	(0x1	<<	1)
#define	MC_TAB_BIST_FAILED	(0x1	<<	2)
#define	ADDR_TAB_BIST_FAILED	(0x1	<<	3)
#define	DCACHE_D_FAILED	(0x3	<<	4)
#define	DCACHE_T_FAILED	(0x1	<<	6)
#define	ICACHE_D_FAILED	(0x3	<<	7)
#define	ICACHE_T_FAILED	(0x1	<<	9)
#define	BIST_FAILED_MASK	0x03FF

#define	ALLMEM_TEST_DONE	(0x1	<<	10)

#define	SKIP_BLK_CNT_MASK	0x1FF000
#define	SKIP_BLK_CNT_SHIFT	12


/*	PHY_st_REG	*/
#define	PORT_LINK_MASK	0x0000001F
#define	PORT_MII_LINKFAIL	0x00000020
#define	PORT_SPEED_MASK	0x00001F00

#define	PORT_GMII_SPD_MASK	0x00006000
#define	PORT_GMII_SPD_10M	0
#define	PORT_GMII_SPD_100M	0x00002000
#define	PORT_GMII_SPD_1000M	0x00004000

#define	PORT_DUPLEX_MASK	0x003F0000
#define	PORT_FLOWCTRL_MASK	0x1F000000

#define	PORT_GMII_FLOWCTRL_MASK	0x60000000
#define	PORT_GMII_FC_ON	0x20000000
#define	PORT_GMII_RXFC_ON	0x20000000
#define	PORT_GMII_TXFC_ON	0x40000000

/*	Port_st_REG	*/
#define	PORT_SECURE_ST_MASK	0x001F
#define	MII_PORT_TXC_ERR	0x0080

/*	Mem_control_REG	*/
#define	SDRAM_SIZE_4MBYTES	0x0001
#define	SDRAM_SIZE_8MBYTES	0x0002
#define	SDRAM_SIZE_16MBYTES	0x0003
#define	SDRAM_SIZE_64MBYTES	0x0004
#define	SDRAM_SIZE_128MBYTES	0x0005
#define	SDRAM_SIZE_MASK	0x0007

#define	MEMCNTL_SDRAM1_EN	(0x1	<<	5)

#define	ROM_SIZE_DISABLE	0x0000
#define	ROM_SIZE_512KBYTES	0x0001
#define	ROM_SIZE_1MBYTES	0x0002
#define	ROM_SIZE_2MBYTES	0x0003
#define	ROM_SIZE_4MBYTES	0x0004
#define	ROM_SIZE_8MBYTES	0x0005
#define	ROM_SIZE_MASK	0x0007

#define	ROM0_SIZE_SHIFT	8
#define	ROM1_SIZE_SHIFT	16


/*	SW_conf_REG	*/
#define	SW_AGE_TIMER_MASK	0x000000F0
#define	SW_AGE_TIMER_DISABLE	0x0
#define	SW_AGE_TIMER_FAST	0x00000080
#define	SW_AGE_TIMER_300SEC	0x00000010
#define	SW_AGE_TIMER_600SEC	0x00000020
#define	SW_AGE_TIMER_1200SEC	0x00000030
#define	SW_AGE_TIMER_2400SEC	0x00000040
#define	SW_AGE_TIMER_4800SEC	0x00000050
#define	SW_AGE_TIMER_9600SEC	0x00000060
#define	SW_AGE_TIMER_19200SEC	0x00000070
//#define	SW_AGE_TIMER_38400SEC	0x00000070

#define	SW_BC_PREV_MASK	0x00000300
#define	SW_BC_PREV_DISABLE	0
#define	SW_BC_PREV_64BC	0x00000100
#define	SW_BC_PREV_48BC	0x00000200
#define	SW_BC_PREV_32BC	0x00000300

#define	SW_MAX_LEN_MASK	0x00000C00
#define	SW_MAX_LEN_1536	0
#define	SW_MAX_LEN_1522	0x00000800
#define	SW_MAX_LEN_1518	0x00000400

#define	SW_DIS_COLABT	0x00001000

#define	SW_HASH_ALG_MASK	0x00006000
#define	SW_HASH_ALG_DIRECT	0
#define	SW_HASH_ALG_XOR48	0x00002000
#define	SW_HASH_ALG_XOR32	0x00004000

#define	SW_DISABLE_BACKOFF_TIMER	0x00008000

#define	SW_BP_NUM_MASK	0x000F0000
#define	SW_BP_NUM_SHIFT	16
#define	SW_BP_MODE_MASK	0x00300000
#define	SW_BP_MODE_DISABLE	0
#define	SW_BP_MODE_JAM	0x00100000
#define	SW_BP_MODE_JAMALL	0x00200000
#define	SW_BP_MODE_CARRIER	0x00300000
#define	SW_RESRV_MC_FILTER	0x00400000
#define	SW_BISR_DISABLE	0x00800000

#define	SW_DIS_MII_WAS_TX	0x01000000
#define	SW_BISS_EN	0x02000000
#define	SW_BISS_TH_MASK	0x0C000000
#define	SW_BISS_TH_SHIFT	26
#define	SW_REQ_LATENCY_MASK	0xF0000000
#define	SW_REQ_LATENCY_SHIFT	28


/*	CPUp_conf_REG	*/
#define	SW_CPU_PORT_DISABLE	0x00000001
#define	SW_PADING_CRC	0x00000002
#define	SW_BRIDGE_MODE	0x00000004

#define	SW_DIS_UN_SHIFT	9
#define	SW_DIS_UN_MASK	(0x3F	<<	SW_DIS_UN_SHIFT)
#define	SW_DIS_MC_SHIFT	16
#define	SW_DIS_MC_MASK	(0x3F	<<	SW_DIS_MC_SHIFT)
#define	SW_DIS_BC_SHIFT	24
#define	SW_DIS_BC_MASK	(0x3F	<<	SW_DIS_BC_SHIFT)


/*	Port_conf0_REG	*/
#define	SW_DISABLE_PORT_MASK	0x0000003F
#define	SW_EN_MC_MASK	0x00003F00
#define	SW_EN_MC_SHIFT	8
#define	SW_EN_BP_MASK	0x003F0000
#define	SW_EN_BP_SHIFT	16
#define	SW_EN_FC_MASK	0x3F000000
#define	SW_EN_FC_SHIFT	24


/*	Port_conf1_REG	*/
#define	SW_DIS_SA_LEARN_MASK	0x0000003F
#define	SW_PORT_BLOCKING_MASK	0x00000FC0
#define	SW_PORT_BLOCKING_SHIFT	6
#define	SW_PORT_BLOCKING_ON	0x1

#define	SW_PORT_BLOCKING_MODE_MASK	0x0003F000
#define	SW_PORT_BLOCKING_MODE_SHIFT	12
#define	SW_PORT_BLOCKING_CTRLONLY	0x1

#define	SW_EN_PORT_AGE_MASK	0x03F00000
#define	SW_EN_PORT_AGE_SHIFT	20
#define	SW_EN_SA_SECURED_MASK	0xFC000000
#define	SW_EN_SA_SECURED_SHIFT	26


/*	Port_conf2_REG	*/
#define	SW_GMII_AN_EN	0x00000001
#define	SW_GMII_FORCE_SPD_MASK	0x00000006
#define	SW_GMII_FORCE_SPD_10M	0
#define	SW_GMII_FORCE_SPD_100M	0x2
#define	SW_GMII_FORCE_SPD_1000M	0x4

#define	SW_GMII_FORCE_FULL_DUPLEX	0x00000008

#define	SW_GMII_FORCE_RXFC	0x00000010
#define	SW_GMII_FORCE_TXFC	0x00000020

#define	SW_GMII_EN	0x00000040
#define	SW_GMII_REVERSE	0x00000080

#define	SW_GMII_TXC_CHECK_EN	0x00000100

#define	SW_LED_FLASH_TIME_MASK	0x00030000
#define	SW_LED_FLASH_TIME_30MS	0
#define	SW_LED_FLASH_TIME_60MS	0x00010000
#define	SW_LED_FLASH_TIME_240MS	0x00020000
#define	SW_LED_FLASH_TIME_480MS	0x00030000


/*	Send_trig_REG	*/
#define	SEND_TRIG_LOW	0x0001
#define	SEND_TRIG_HIGH	0x0002


/*	Srch_cmd_REG	*/
#define	SW_MAC_SEARCH_START	0x000001
#define	SW_MAX_SEARCH_AGAIN	0x000002


/*	MAC_wt0_REG	*/
#define	SW_MAC_WRITE	0x00000001
#define	SW_MAC_WRITE_DONE	0x00000002
#define	SW_MAC_FILTER_EN	0x00000004
#define	SW_MAC_VLANID_SHIFT	3
#define	SW_MAC_VLANID_MASK	0x00000038
#define	SW_MAC_VLANID_EN	0x00000040
#define	SW_MAC_PORTMAP_MASK	0x00001F80
#define	SW_MAC_PORTMAP_SHIFT	7
#define	SW_MAC_AGE_MASK	(0x7	<<	13)
#define	SW_MAC_AGE_STATIC	(0x7	<<	13)
#define	SW_MAC_AGE_VALID	(0x1	<<	13)
#define	SW_MAC_AGE_EMPTY	0

/*	BW_cntl0_REG	*/
#define	SW_PORT_TX_NOLIMIT	0
#define	SW_PORT_TX_64K	1
#define	SW_PORT_TX_128K	2
#define	SW_PORT_TX_256K	3
#define	SW_PORT_TX_512K	4
#define	SW_PORT_TX_1M	5
#define	SW_PORT_TX_4M	6
#define	SW_PORT_TX_10MK	7

/*	BW_cntl1_REG	*/
#define	SW_TRAFFIC_SHAPE_IPG	(0x1	<<	31)

/*	PHY_cntl0_REG	*/
#define	SW_PHY_ADDR_MASK	0x0000001F
#define	PHY_ADDR_MAX	0x1f
#define	SW_PHY_REG_ADDR_MASK	0x00001F00
#define	SW_PHY_REG_ADDR_SHIFT	8
#define	PHY_REG_ADDR_MAX	0x1f
#define	SW_PHY_WRITE	0x00002000
#define	SW_PHY_READ	0x00004000
#define	SW_PHY_WDATA_MASK	0xFFFF0000
#define	SW_PHY_WDATA_SHIFT	16


/*	PHY_cntl1_REG	*/
#define	SW_PHY_WRITE_DONE	0x00000001
#define	SW_PHY_READ_DONE	0x00000002
#define	SW_PHY_RDATA_MASK	0xFFFF0000
#define	SW_PHY_RDATA_SHIFT	16

/*	FC_th_REG	*/
/*	Adj_port_th_REG	*/
/*	Port_th_REG	*/

/*	PHY_cntl2_REG	*/
#define	SW_PHY_AN_MASK	0x0000001F
#define	SW_PHY_SPD_MASK	0x000003E0
#define	SW_PHY_SPD_SHIFT	5
#define	SW_PHY_DPX_MASK	0x00007C00
#define	SW_PHY_DPX_SHIFT	10
#define	SW_FORCE_FC_MASK	0x000F8000
#define	SW_FORCE_FC_SHIFT	15
#define	SW_PHY_NORMAL_MASK	0x01F00000
#define	SW_PHY_NORMAL_SHIFT	20
#define	SW_PHY_AUTOMDIX_MASK	0x3E000000
#define	SW_PHY_AUTOMDIX_SHIFT	25
#define	SW_PHY_REC_MCCAVERAGE	0x40000000


/*	PHY_cntl3_REG	*/
/*	Pri_cntl_REG	*/
/*	VLAN_pri_REG	*/
/*	TOS_en_REG	*/
/*	TOS_map0_REG	*/
/*	TOS_map1_REG	*/
/*	Custom_pri1_REG	*/
/*	Custom_pri2_REG	*/
/*	Empty_cnt_REG	*/
/*	Port_cnt_sel_REG	*/
/*	Port_cnt_REG	*/


/*	SW_Int_st_REG	&	SW_Int_mask_REG	*/
#define	SEND_H_DONE_INT	0x0000001
#define	SEND_L_DONE_INT	0x0000002
#define	RX_H_DONE_INT	0x0000004
#define	RX_L_DONE_INT	0x0000008
#define	RX_H_DESC_FULL_INT	0x0000010
#define	RX_L_DESC_FULL_INT	0x0000020
#define	PORT0_QUE_FULL_INT	0x0000040
#define	PORT1_QUE_FULL_INT	0x0000080
#define	PORT2_QUE_FULL_INT	0x0000100
#define	PORT3_QUE_FULL_INT	0x0000200
#define	PORT4_QUE_FULL_INT	0x0000400
#define	PORT5_QUE_FULL_INT	0x0000800

#define	CPU_QUE_FULL_INT	0x0002000
#define	GLOBAL_QUE_FULL_INT	0x0004000
#define	MUST_DROP_INT	0x0008000
#define	BC_STORM_INT	0x0010000

#define	PORT_STATUS_CHANGE_INT	0x0040000
#define	INTRUDER_INT	0x0080000
#define	WATCHDOG0_EXPR_INT	0x0100000
#define	WATCHDOG1_EXPR_INT	0x0200000
#define	RX_DESC_ERR_INT	0x0400000
#define	SEND_DESC_ERR_INT	0x0800000
#define	CPU_HOLD_INT	0x1000000
#define	SWITCH_INT_MASK	0x1FDEFFF


/*	GPIO_conf0_REG	*/
#define	GPIO0_INPUT_MODE	0x00000001
#define	GPIO1_INPUT_MODE	0x00000002
#define	GPIO2_INPUT_MODE	0x00000004
#define	GPIO3_INPUT_MODE	0x00000008
#define	GPIO4_INPUT_MODE	0x00000010
#define	GPIO5_INPUT_MODE	0x00000020
#define	GPIO6_INPUT_MODE	0x00000040
#define	GPIO7_INPUT_MODE	0x00000080

#define	GPIO0_OUTPUT_MODE	0
#define	GPIO1_OUTPUT_MODE	0
#define	GPIO2_OUTPUT_MODE	0
#define	GPIO3_OUTPUT_MODE	0
#define	GPIO4_OUTPUT_MODE	0
#define	GPIO5_OUTPUT_MODE	0
#define	GPIO6_OUTPUT_MODE	0
#define	GPIO7_OUTPUT_MODE	0

#define	GPIO0_INPUT_MASK	0x00000100
#define	GPIO1_INPUT_MASK	0x00000200
#define	GPIO2_INPUT_MASK	0x00000400
#define	GPIO3_INPUT_MASK	0x00000800
#define	GPIO4_INPUT_MASK	0x00001000
#define	GPIO5_INPUT_MASK	0x00002000
#define	GPIO6_INPUT_MASK	0x00004000
#define	GPIO7_INPUT_MASK	0x00008000

#define	GPIO0_OUTPUT_EN	0x00010000
#define	GPIO1_OUTPUT_EN	0x00020000
#define	GPIO2_OUTPUT_EN	0x00040000
#define	GPIO3_OUTPUT_EN	0x00080000
#define	GPIO4_OUTPUT_EN	0x00100000
#define	GPIO5_OUTPUT_EN	0x00200000
#define	GPIO6_OUTPUT_EN	0x00400000
#define	GPIO7_OUTPUT_EN	0x00800000

#define	GPIO_CONF0_OUTEN_MASK	0x00ff0000

#define	GPIO0_OUTPUT_HI	0x01000000
#define	GPIO1_OUTPUT_HI	0x02000000
#define	GPIO2_OUTPUT_HI	0x04000000
#define	GPIO3_OUTPUT_HI	0x08000000
#define	GPIO4_OUTPUT_HI	0x10000000
#define	GPIO5_OUTPUT_HI	0x20000000
#define	GPIO6_OUTPUT_HI	0x40000000
#define	GPIO7_OUTPUT_HI	0x80000000

#define	GPIO0_OUTPUT_LOW	0
#define	GPIO1_OUTPUT_LOW	0
#define	GPIO2_OUTPUT_LOW	0
#define	GPIO3_OUTPUT_LOW	0
#define	GPIO4_OUTPUT_LOW	0
#define	GPIO5_OUTPUT_LOW	0
#define	GPIO6_OUTPUT_LOW	0
#define	GPIO7_OUTPUT_LOW	0


/*	GPIO_conf2_REG	*/
#define	EXTIO_WAIT_EN	(0x1	<<	6)
#define	EXTIO_CS1_INT1_EN	(0x1	<<	5)
#define	EXTIO_CS0_INT0_EN	(0x1	<<	4)

/*	Timer_int_REG	*/
#define	SW_TIMER_INT_DISABLE	0x10000
#define	SW_TIMER_INT	0x1

/*	Timer_REG	*/
#define	SW_TIMER_EN	0x10000
#define	SW_TIMER_MASK	0xffff
#define	SW_TIMER_10MS_TICKS	0x3D09
#define	SW_TIMER_1MS_TICKS	0x61A
#define	SW_TIMER_100US_TICKS	0x9D


/*	Port0_LED_REG,	Port1_LED_REG,	Port2_LED_REG,	Port3_LED_REG,	Port4_LED_REG*/
#define	GPIOL_INPUT_MODE	0x00
#define	GPIOL_OUTPUT_FLASH	0x01
#define	GPIOL_OUTPUT_LOW	0x02
#define	GPIOL_OUTPUT_HIGH	0x03
#define	GPIOL_LINK_LED	0x04
#define	GPIOL_SPEED_LED	0x05
#define	GPIOL_DUPLEX_LED	0x06
#define	GPIOL_ACT_LED	0x07
#define	GPIOL_COL_LED	0x08
#define	GPIOL_LINK_ACT_LED	0x09
#define	GPIOL_DUPLEX_COL_LED	0x0A
#define	GPIOL_10MLINK_ACT_LED	0x0B
#define	GPIOL_100MLINK_ACT_LED	0x0C
#define	GPIOL_CTRL_MASK	0x0F

#define	GPIOL_INPUT_MASK	0x7000
#define	GPIOL_INPUT_0_MASK	0x1000
#define	GPIOL_INPUT_1_MASK	0x2000
#define	GPIOL_INPUT_2_MASK	0x4000

#define	PORT_LED0_SHIFT	0
#define	PORT_LED1_SHIFT	4
#define	PORT_LED2_SHIFT	8
#endif
#endif /* _IF_ADMSWREG_H_ */
