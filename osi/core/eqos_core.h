/*
 * Copyright (c) 2018-2019, NVIDIA CORPORATION. All rights reserved.
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
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef EQOS_CORE_H_
#define EQOS_CORE_H_

/* These bits control the threshold (fill-level of Rx queue) at which
 * the flow control is asserted or de-asserted
 */
#define FULL_MINUS_1_5K		(unsigned int)1
#define FULL_MINUS_2_K		(unsigned int)2
#define FULL_MINUS_2_5K		(unsigned int)3
#define FULL_MINUS_3_K		(unsigned int)4
#define FULL_MINUS_4_K		(unsigned int)6
#define FULL_MINUS_6_K		(unsigned int)10
#define FULL_MINUS_10_K		(unsigned int)18
#define FULL_MINUS_16_K		(unsigned int)30

/**
 *	MTL queue operation mode
 *	EQOS_MTL_QUEUE_DISABLED - queue disabled
 *	EQOS_MTL_QUEUE_QAVB - queue in AVB mode
 *	EQOS_MTL_QUEUE_QDCB - queue in DCB mode
 *	EQOS_MTL_QUEUE_QGENERIC - queue in gerneric mode
 */
#define EQOS_MTL_QUEUE_DISABLED	0x0U
#define EQOS_MTL_QUEUE_AVB	0x1U
#define EQOS_MTL_QUEUE_DCB	0x2U
#define EQOS_MTL_QUEUE_GENERIC	0x3U

/* MDC Clock Selection define*/
#define EQOS_CSR_60_100M	0x0	/* MDC = clk_csr/42 */
#define EQOS_CSR_100_150M	0x1	/* MDC = clk_csr/62 */
#define EQOS_CSR_20_35M		0x2	/* MDC = clk_csr/16 */
#define EQOS_CSR_35_60M		0x3	/* MDC = clk_csr/26 */
#define EQOS_CSR_150_250M	0x4	/* MDC = clk_csr/102 */
#define EQOS_CSR_250_300M	0x5	/* MDC = clk_csr/124 */
#define EQOS_CSR_300_500M	0x6	/* MDC = clk_csr/204 */
#define EQOS_CSR_500_800M	0x7	/* MDC = clk_csr/324 */

#define FIFO_SIZE_B(x) (x)
#define FIFO_SIZE_KB(x) ((x) * 1024U)

/*  per queue fifo size programmable value */
#define EQOS_256	0x00U
#define EQOS_512	0x01U
#define EQOS_1K		0x03U
#define EQOS_2K		0x07U
#define EQOS_4K		0x0FU
#define EQOS_8K		0x1FU
#define EQOS_9K		0x23U
#define EQOS_16K	0x3FU
#define EQOS_32K	0x7FU
#define EQOS_36K	0x8FU

/* EQOS HW Registers */
#define EQOS_DMA_SBUS		0x1004
#define EQOS_DMA_BMR		0x1000
#define EQOS_MMC_CNTRL		0x0700
#define EQOS_MAC_MA0HR		0x0300
#define EQOS_MAC_MA0LR		0x0304
#define EQOS_MAC_MCR		0x0000
#define EQOS_MAC_VLAN_TAG	0x0050
#define EQOS_MAC_VLANTIR	0x0060
#define EQOS_MAC_IMR		0x00B4
#define EQOS_DMA_ISR		0x1008
#define EQOS_MAC_ISR		0x00B0
#define EQOS_MAC_RQC1R		0x00A4
#define EQOS_MMC_TX_INTR_MASK	0x0710
#define EQOS_MMC_RX_INTR_MASK	0x070C
#define EQOS_MMC_IPC_RX_INTR_MASK	0x0800
#define EQOS_MAC_RQC0R		0x00A0
#define EQOS_MAC_PMTCSR		0x00C0
#define EQOS_MAC_PCS		0x00F8
#define EQOS_MAC_ANS		0x00E4
#define EQOS_RXQ_TO_DMA_CHAN_MAP	0x03020100U
#define EQOS_MAC_EXTR		0x0004
#define EQOS_MAC_RX_FLW_CTRL	0x0090
#define EQOS_MAC_QX_TX_FLW_CTRL(x)	((0x0004U * (x)) + 0x0070U)

/* EQOS MTL registers*/
#define EQOS_MTL_CHX_TX_OP_MODE(x)	((0x0040U * (x)) + 0x0D00U)
#define EQOS_MTL_TXQ_QW(x)		((0x0040U * (x)) + 0x0D18U)
#define EQOS_MTL_CHX_RX_OP_MODE(x)	((0x0040U * (x)) + 0x0D30U)
#define EQOS_MTL_TXQ_ETS_CR(x)		((0x0040U * (x)) + 0x0D10U)
#define EQOS_MTL_TXQ_ETS_SSCR(x)	((0x0040U * (x)) + 0x0D1CU)
#define EQOS_MTL_TXQ_ETS_HCR(x)		((0x0040U * (x)) + 0x0D20U)
#define EQOS_MTL_TXQ_ETS_LCR(x)		((0x0040U * (x)) + 0x0D24U)
#define EQOS_MTL_RXQ_DMA_MAP0		0x0C30
#define EQOS_MTL_OP_MODE		0x0C00

/* EQOS Wrapper registers*/
#define EQOS_PAD_AUTO_CAL_CFG		0x8804U
#define EQOS_PAD_AUTO_CAL_STAT		0x880CU
#define EQOS_PAD_CRTL			0x8800U
#define EQOS_CLOCK_CTRL_0		0x8000U

/* EQOS Register BIT Masks */
#define EQOS_PAD_AUTO_CAL_CFG_ENABLE		OSI_BIT(29)
#define EQOS_PAD_AUTO_CAL_CFG_START		OSI_BIT(31)
#define EQOS_PAD_AUTO_CAL_STAT_ACTIVE		OSI_BIT(31)
#define EQOS_PAD_CRTL_E_INPUT_OR_E_PWRD		OSI_BIT(31)
#define EQOS_MMC_CNTRL_CNTRST			OSI_BIT(0)
#define EQOS_MMC_CNTRL_RSTONRD			OSI_BIT(2)
#define EQOS_MMC_CNTRL_CNTPRST			OSI_BIT(4)
#define EQOS_MMC_CNTRL_CNTPRSTLVL		OSI_BIT(5)
#define EQOS_MTL_QTOMR_FTQ			OSI_BIT(0)
#define EQOS_MTL_TSF				OSI_BIT(1)
#define EQOS_MTL_TXQEN				OSI_BIT(3)
#define EQOS_MTL_RSF				OSI_BIT(5)
#define EQOS_MCR_TE				OSI_BIT(0)
#define EQOS_MCR_RE				OSI_BIT(1)
#define EQOS_MCR_DM				OSI_BIT(13)
#define EQOS_MCR_FES				OSI_BIT(14)
#define EQOS_MCR_PS				OSI_BIT(15)
#define EQOS_MCR_JE				OSI_BIT(16)
#define EQOS_MCR_JD				OSI_BIT(17)
#define EQOS_MCR_ACS				OSI_BIT(20)
#define EQOS_MCR_CST				OSI_BIT(21)
#define EQOS_MCR_S2KP				OSI_BIT(22)
#define EQOS_IMR_RGSMIIIE			OSI_BIT(0)
#define EQOS_IMR_PCSLCHGIE			OSI_BIT(1)
#define EQOS_IMR_PCSANCIE			OSI_BIT(2)
#define EQOS_IMR_PMTIE				OSI_BIT(4)
#define EQOS_IMR_LPIIE				OSI_BIT(5)
#define EQOS_MAC_PCS_LNKSTS			OSI_BIT(19)
#define EQOS_MAC_PCS_LNKMOD			OSI_BIT(16)
#define EQOS_MAC_PCS_LNKSPEED			(OSI_BIT(17) | OSI_BIT(18))
#define EQOS_MAC_PCS_LNKSPEED_10		0x0U
#define EQOS_MAC_PCS_LNKSPEED_100		OSI_BIT(17)
#define EQOS_MAC_PCS_LNKSPEED_1000		OSI_BIT(18)
#define EQOS_MAC_VLANTIR_VLTI			OSI_BIT(20)
#define EQOS_MAC_VLANTR_EVLS_ALWAYS_STRIP	((unsigned int)0x3 << 21U)
#define EQOS_MAC_VLANTR_EVLRXS			OSI_BIT(24)
#define EQOS_MAC_VLANTR_DOVLTC			OSI_BIT(20)
#define EQOS_MAC_VLANTR_ERIVLT			OSI_BIT(27)
#define EQOS_MAC_VLANTIRR_VLTI			OSI_BIT(20)
#define EQOS_MAC_VLANTIRR_CSVL			OSI_BIT(19)
#define EQOS_DMA_SBUS_BLEN4			OSI_BIT(1)
#define EQOS_DMA_SBUS_BLEN8			OSI_BIT(2)
#define EQOS_DMA_SBUS_BLEN16			OSI_BIT(3)
#define EQOS_DMA_SBUS_EAME			OSI_BIT(11)
#define EQOS_DMA_BMR_SWR			OSI_BIT(0)
#define EQOS_DMA_BMR_DPSW			OSI_BIT(8)
#define EQOS_MAC_RQC1R_MCBCQEN			OSI_BIT(20)
#define EQOS_MTL_QTOMR_FTQ_LPOS			OSI_BIT(0)
#define EQOS_DMA_ISR_MACIS			OSI_BIT(17)
#define EQOS_MAC_ISR_RGSMIIS			OSI_BIT(0)
#define EQOS_MTL_TXQ_QW_ISCQW			OSI_BIT(4)
#define EQOS_DMA_SBUS_RD_OSR_LMT		0x001F0000U
#define EQOS_DMA_SBUS_WR_OSR_LMT		0x1F000000U
#define EQOS_MTL_TXQ_SIZE_SHIFT			16U
#define EQOS_MTL_RXQ_SIZE_SHIFT			20U
#define EQOS_MAC_ENABLE_LM			OSI_BIT(12)
#define EQOS_RX_CLK_SEL				OSI_BIT(8)
#define EQOS_MAX_TC				8U
#define EQOS_MTL_TXQ_ETS_CR_SLC_MASK		(OSI_BIT(6) | OSI_BIT(5) | \
						 OSI_BIT(4))
#define EQOS_MTL_TXQ_ETS_CR_CC			OSI_BIT(3)
#define EQOS_MTL_TXQ_ETS_CR_AVALG		OSI_BIT(2)
#define EQOS_MTL_TXQ_ETS_CR_CC_SHIFT		3U
#define EQOS_MTL_TXQ_ETS_CR_AVALG_SHIFT		2U
#define EQOS_MTL_TXQ_ETS_QW_ISCQW_MASK		0x000FFFFFU
#define EQOS_MTL_TXQ_ETS_SSCR_SSC_MASK		0x00003FFFU
#define EQOS_MTL_TXQ_ETS_HCR_HC_MASK		0x1FFFFFFFU
#define EQOS_MTL_TXQ_ETS_LCR_LC_MASK		0x1FFFFFFFU
#define EQOS_MTL_TXQEN_MASK			(OSI_BIT(3) | OSI_BIT(2))
#define EQOS_MTL_TXQEN_MASK_SHIFT		2U
#define EQOS_MTL_RXQ_OP_MODE_FEP		OSI_BIT(4)
#define EQOS_MTL_OP_MODE_DTXSTS			OSI_BIT(1)
#define EQOS_MAC_EXTR_DCRCC			OSI_BIT(16)
#define EQOS_MAC_QX_TX_FLW_CTRL_TFE		OSI_BIT(1)
#define EQOS_MAC_RX_FLW_CTRL_RFE		OSI_BIT(0)
#define EQOS_MAC_PAUSE_TIME			0xFFFF0000U
#define EQOS_MAC_PAUSE_TIME_MASK		0xFFFF0000U
#define EQOS_MTL_RXQ_OP_MODE_EHFC		OSI_BIT(7)
#define EQOS_MTL_RXQ_OP_MODE_RFA_SHIFT		8U
#define EQOS_MTL_RXQ_OP_MODE_RFA_MASK		0x00003F00U
#define EQOS_MTL_RXQ_OP_MODE_RFD_SHIFT		14U
#define EQOS_MTL_RXQ_OP_MODE_RFD_MASK		0x000FC000U

void update_ehfc_rfa_rfd(unsigned int rx_fifo, unsigned int *value);
#endif
