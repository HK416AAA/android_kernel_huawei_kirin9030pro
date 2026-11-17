/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: PCIe chs platform functions.
 *
 * This software is distributed under the terms of the GNU General
 * Public License ("GPL") as published by the Free Software Foundation,
 * either version 2 of that License or (at your option) any later version.
 */

#include <linux/delay.h>
#include <linux/gpio.h>
#ifdef CONFIG_HIPCIE_SUPPORT_FFA
#include <platform_include/see/ffa/ffa_plat_drv.h>
#include <platform_include/see/ffa/ffa_msg_id.h>
#else
#include <platform_include/see/bl31_smc.h>
#endif
#include <linux/iommu/mm_svm.h>
#include <linux/arm-smccc.h>
#include <linux/of_address.h>
#include <linux/clk.h>
#include <linux/gpio.h>
#include <linux/of_gpio.h>
#include <linux/of.h>
#include <linux/jiffies.h>
#include <securec.h>
#include <doze.h>

#include "../hi_pcie_defines.h"
#include "../ctrl/hi_pcie_ctrl_common.h"
#include "../phy/hi_pcie_combphy.h"
#include "../phy/hi_pcie_kphy.h"
#include "../phy/hi_pcie_combphy_firmware.h"
#include "../ctrl/hi_pcie_ctrl_dfx.h"
#include "../hi_pcie_external_api.h"
#include "hi_pcie_idle.h"

#ifdef CONFIG_HIPCIE_TEST
#include "../test/hi_pcie_test.h"
#endif

atomic_t pcie_fnpll_cnt = ATOMIC_INIT(0);
atomic_t pcie_tcu_sd_cnt = ATOMIC_INIT(0);
atomic_t hsdt_pcie_common_rst_cnt = ATOMIC_INIT(0); // bit3 tcu, bit15 fsm
atomic_t hsdt_pcie_common_clk_cnt = ATOMIC_INIT(0); // bit10 tcu, bit14 fsm
atomic_t pcie_tcu_pwr_cnt = ATOMIC_INIT(0);
atomic_t plat_config_cnt = ATOMIC_INIT(0);

static DEFINE_SPINLOCK(pcie_fnpll_lock);
static DEFINE_SPINLOCK(smmu_tcu_lock);

#define ENABLE 1
#define DISABLE 0

#define AOCRGSCPEREN6						0x1D0
#define AOCRGSCCLKDIV3						0x25C
#define AOCRGAO_AUTODIV2					0x500
#define AOCRGSCCLKDIV12						0x288
#define AOCRGSCCLKDIV16						0x298
#define SCPERSTAT0                          0x16C
#define SCPERSTAT1                           0x17C
#define SCPERSTAT2                          0x19C
#define SCPERSTAT3                          0x1AC
#define SCPERCLKEN1                         0x178

#define HSDT_PEREN0							0x000
#define HSDT_PERDIS0						0x004
#define HSDT_PERCLKEN0						0x008
#define HSDT_PERSTAT0						0x00C
#define HSDT_PEREN1							0x010
#define HSDT_PERDIS1						0x014
#define HSDT_PERCLKEN1						0x018
#define HSDT_PERSTAT1						0x01C
#define HSDT_PEREN4							0x040
#define HSDT_PERDIS4						0x044
#define HSDT_PERRSTEN0						0x060
#define HSDT_PERRSTDIS0						0x064
#define HSDT_PERRSTSTAT0					0x068
#define HSDT_CRG_PCIECTRL0					0x300
#define HSDT_CRG_PCIECTRL1					0x304
#define HSDT_CRG_PERI_AUTODIV3				0x35C

#define HIPCIE_RSTEN0_X1					0x190
#define HIPCIE_RSTDIS0_X1					0x194
#define HIPCIE_ICG_EN0_X1					0x160
#define HIPCIE_ICG_EN1_X1					0x170
#define HIPCIE_ICG_DIS0_X1					0x164
#define HIPCIE_ICG_DIS1_X1					0x174
#define PCIEX1_0_CTRL0						0x300
#define PCIEX1_1_CTRL0						0x304

#define PCIE_CLKREQ_LOW						0

#define HIPCIE_SOC2PHY_ISOEN				0x000
#define HIPCIE_PHY_CFG0						0x034
#define HIPCIE_PHY_CFG1						0x038
#define HIPCIE_MISC_CFG9_V3					0x05C
#define HIPCIE_MISC_STATE0					0x100
#define HIPCIE_CTRL_STAT2					0x408
#define HIPCIE_CTRL_REG31					0x7C
#define HIPCIE_CLKREQ_IN_N_CTRL				0x90
#define HIPCIE_CON_CLKREQ_IN_N_CNT_BASE		0x98
#define HIPCIE_SC_PCIE_CTRL_STAT17			0x444
#define HIPCIE_SC_PCIE_CTRL_STAT18			0x448
#define HIPCIE_SC_PCIE_CTRL_STAT19			0x290
#define HIPCIE_SC_PCIE_CTRL_STAT20			0x294

#define HIPCIE_MISC_CFG14					0x088
#define HIPCIE_MISC_CFG15					0x08C

#define DEBOUNCE_CYCLES						0x80000240

#define FNPLL_PCIE_ANALOG_CFG0				0x0008
#define FNPLL_PCIE_ANALOG_CFG1				0x000C
#define FNPLL_PCIE_ANALOG_CFG2				0x0010
#define FNPLL_PCIE_ANALOG_CFG3				0x0014
#define FNPLL_PCIE_ADPLL_ATUNE_CFG			0x0018
#define FNPLL_PCIE_ADPLL_PTUNE_CFG			0x001C
#define FNPLL_PCIE_DTC_CFG					0x0024
#define FNPLL_PCIE_FTDC_CFG					0x0028
#define FNPLL_PCIE_FDTC_LMS_CFG				0x002C
#define FNPLL_PCIE_DTC_LMS_CFG				0x0030
#define FNPLL_PCIE_LPF_BW_I_T01				0x0034
#define FNPLL_PCIE_LPF_BW_P_T01				0x0038
#define FNPLL_PCIE_ADPLL_DCO_TMODE			0x003C
#define FNPLL_PCIE_ADPLL_LPF_TEST_CFG		0x0040
#define FNPLL_PCIE_ADPLL_DSM_CFG			0x0044
#define FNPLL_PCIE_ADPLL_FTDC_LOCK_THR		0x0048
#define FNPLL_PCIE_ADPLL_FTDC_UNLOCK_THR	0x004C
#define FNPLL_PCIE_CHAOS_CNT_THR_CFG		0x0050
#define FNPLL_PCIE_ADPLL_CLK_EN_CFG0		0x0054
#define FNPLL_PCIE_MAN_TRIG_LMS_CNT_CFG		0x005C
#define FNPLL_PCIE_DTC_LINEAR_TEST_MODE		0x0060
#define FNPLL_PCIE_FREZ_LMS_PTHR			0x0064
#define FNPLL_PCIE_ACQ_CNT_THR_CFG			0x0068
#define FNPLL_PCIE_ADPLL_DLY_CFG			0x006C
#define FNPLL_PCIE_PTUNE_FBDIV				0x0070
#define PCIE_PLL_ATUNE_CODE_BIN				0x0080
#define PCIE_PLL_FCW_RO						0x0084
#define PCIE_PLL_DTC_MAX					0x0088
#define PCIE_PLL_FDTC_STAT					0x008C
#define PCIE_PLL_ADPLL_DTC_CONV_COEF		0x0090
#define PCIE_PLL_A2D_ADPLL_FTDC				0x0094
#define PCIE_PLL_FTDC_MAX_MIN				0x0098
#define PCIE_PLL_ADPLL_LPF_OUT				0x00AC
#define PCIE_PLL_RECORD_TIME				0x00C0
#define PCIE_PLL_DCO_WORD_AFTER_CL			0x00D0

#define FNPLL_FTDC_LOCK_THR_DEFAULT			0x000240FF

#define HSDT_CRG_PCIEPLL_PERI_STAT1			0x104
#define HSDT_CRG_PCIEPLL_PERI_STAT2			0x108
#define HSDT_CRG_PCIEPLL_PCIE_CTRL0			0x190
#define HSDT_CRG_PCIEPLL_PCIE_FCW			0x194
#define HSDT_CRG_PCIEPLL_STATE				0x204

#define PCIEPLL_STATE_OPEN					0x1
#define PCIEPLL_STATE_CLOSE					0x2
#define PCIEPLL_STATE_MASK					0x3

#define FNPLL_LOCK_TIMEOUT					20
#define FNPLL_LOCK_BIT						(0x1 << 4)

#define HSDT_SCTRL_SMMU_SD					0x094

#define BASE_ADDR_NUM						32
#define RC_ID0								0
#define RC_ID1								1

#define SC_PCIE_SMMU_CTRL_AW_NS				0x200
#define SC_PCIE_SMMU_CTRL_AR_NS				0x204
#define SC_PCIE_BDF0_NS						0x24C
#define SC_PCIE_NSSID_CTRL_NS				0x28C

#define MAX_SSID_NUM						16
#define PCIE_FNPLL_RETRY_TIME				0x2

static struct {
	void __iomem *aocrg_base;
	void __iomem *hsdtcrg_base;
	void __iomem *pcie_fnpll_base;
	void __iomem *hsdtsctrl_base;
	void __iomem *hsdtxctrl_base;
} plat_config = {
	NULL, NULL, NULL, NULL, NULL
};

struct hi_pcie_chs {
	struct hi_pcie *pcie;
	struct hi_pcie_ctrl *ctrl;

	void __iomem *sysctrl_base;
	void __iomem *ctrl_base;
	void __iomem *phy_base;
	void __iomem *tbu_base;
	void __iomem *phy_pcs_base;

	bool fnpll_hw_auto_open;
	int level2_irq;
	u32 clkreq_gpio;
	u32 ftdc_lock_thr;
};

struct {
	u32 smmu_id;
	u32 sid;
	u32 mode_reg;
	u32 aw_reg;
	u32 ar_reg;
	u32 bdf_reg;
	atomic_t *tcu_pwr_cnt;
	spinlock_t *tcu_lock;
} chs_pcie_smmu[] = {
	{
		3, 14,
		SC_PCIE_NSSID_CTRL_NS,
		SC_PCIE_SMMU_CTRL_AW_NS,
		SC_PCIE_SMMU_CTRL_AR_NS,
		SC_PCIE_BDF0_NS,
		&pcie_tcu_pwr_cnt,
		&smmu_tcu_lock,
	},
	{
		3, 15,
		SC_PCIE_NSSID_CTRL_NS,
		SC_PCIE_SMMU_CTRL_AW_NS,
		SC_PCIE_SMMU_CTRL_AR_NS,
		SC_PCIE_BDF0_NS,
		&pcie_tcu_pwr_cnt,
		&smmu_tcu_lock,
	},
};

struct pcie_behavior {
	int behavior_id;
	int size;
	u32 base_addr[BASE_ADDR_NUM];
	u32 val[BASE_ADDR_NUM];
};

enum {
	PCIE_RST = 0,
	PCIE_UNRST,
	OPEN_SYSCLK,
	CLOSE_SYSCLK,
	SC_RST,
	SC_UNRST,
	EN_SC_CLK,
	DIS_SC_CLK,
	OE_IE_CFG_RC,
	OE_IE_CFG_EP,
	OE_IE_RST,
	CTRL_SD_EXIT,
	SMMU_SD_EXIT,
	PHY_RST_N_SEL,
	PHY_PORN_RST,
	PHY_APB_UNRESET,
	PHY_APB_RESET,
	PHY_RESET_N,
	PIPE_RESET_N,
	CTRL_PORN_UNRST,
	CTRL_PORN_RST,
	PIPE_CLK_STABLE,
	PU_RX_TERMIANTION,
	CLKREQ_IDLE_TIMEOUT,
	CLKREQ_NO_DELAY,
	QIC_POWER_DOMAIN_ENTER,
	QIC_POWER_DOMAIN_EXIT,
	OPEN_RST_ITNR,
	BEHAVIOR_MAX,
};

struct hi_pcie_behavior {
	int id;
	struct pcie_behavior behavior[BEHAVIOR_MAX];
};

const struct hi_pcie_behavior pcie_init_step[] = {
	{ RC_ID0,
		{
			{ PCIE_RST, 1, { HSDT_PERRSTEN0 },
				{ (BIT(30) | BIT(28) | BIT(19) | BIT(11) | BIT(9) | BIT(8) | BIT(7) | BIT(5) | BIT(0)) } },
			{ PCIE_UNRST, 1, { HSDT_PERRSTDIS0 }, { (BIT(30) | BIT(28) | BIT(19) | BIT(11) | BIT(8) | BIT(5) | BIT(0)) } },
			// pciephy_ref_soft bit6/pcieio_soft bit7/tcu bit10/tbu bit11/mudp bit14 bit16/int_par bit15
			{ OPEN_SYSCLK, 1, { HSDT_PEREN1 }, { 0x1A3F } },
			{ CLOSE_SYSCLK, 1, { HSDT_PERDIS1 }, { 0x1AFF } },
			{ SC_RST, 1, { HIPCIE_RSTEN0_X1 }, { 0xFFFFFFFFU } },
			{ SC_UNRST, 1, { HIPCIE_RSTDIS0_X1 }, { 0xFFFFFFFFU } },
			{ EN_SC_CLK, 2, { HIPCIE_ICG_EN0_X1, HIPCIE_ICG_EN1_X1 }, { 0xFFFFFFFFU, 0xFFFFFFFFU } },
			{ DIS_SC_CLK, 2, { HIPCIE_ICG_DIS0_X1, HIPCIE_ICG_DIS1_X1 }, { 0xFFFFFFFFU, 0xFFFFFFFFU } },
			{ OE_IE_CFG_RC, 1, { PCIEX1_0_CTRL0 }, { BIT(27) } },
			{ OE_IE_CFG_EP, 1, { PCIEX1_0_CTRL0 }, { (BIT(11) | BIT(9) | BIT(6)) } },
			{ OE_IE_RST, 1, { PCIEX1_0_CTRL0 }, { (BIT(11) | BIT(27)) } },
			{ CTRL_SD_EXIT, 0, {}, {} },
			{ SMMU_SD_EXIT, 1, { HSDT_SCTRL_SMMU_SD }, { BIT(1) } },
			{ PHY_RST_N_SEL, 1, { HIPCIE_PHY_CFG0 }, { BIT(5) } },
			{ PHY_PORN_RST, 1, { HIPCIE_PHY_CFG0 }, { (BIT(2)) } },
			{ PHY_APB_UNRESET, 1, { HSDT_PERRSTDIS0 }, { BIT(9) } },
			{ PHY_APB_RESET, 1, { HSDT_PERRSTEN0 }, { BIT(9) } },
			{ PHY_RESET_N, 1, { HIPCIE_PHY_CFG0 }, { (BIT(4)) } },
			{ PIPE_RESET_N, 0, { HIPCIE_PHY_CFG0 }, { (BIT(6) | BIT(7)) } },
			{ CTRL_PORN_UNRST, 1, { HSDT_PERRSTDIS0 }, { (BIT(7)) } },
			{ CTRL_PORN_RST, 1, { HSDT_PERRSTEN0 }, { (BIT(7)) } },
			{ PIPE_CLK_STABLE, 1, { HIPCIE_CTRL_STAT2 }, { (BIT(19)) } },
			{ PU_RX_TERMIANTION, 1, { HIPCIE_PHY_CFG1 }, { (BIT(0) | BIT(16)) } },
			{ CLKREQ_IDLE_TIMEOUT, 0, {},{} },
			{ CLKREQ_NO_DELAY, 0, {}, {} },
			{ QIC_POWER_DOMAIN_ENTER, 1, { 0x424 }, { BIT(4) } },
			{ QIC_POWER_DOMAIN_EXIT, 1, { 0x424 }, { BIT(4) } },
			{ OPEN_RST_ITNR, 2, { HIPCIE_MISC_CFG14, HIPCIE_MISC_CFG15 }, { BIT(0), BIT(0) } },
		}
	}, { RC_ID1,
		{
			{ PCIE_RST, 1, { HSDT_PERRSTEN0 },
				{ (BIT(29) | BIT(27) | BIT(25) | BIT(23) | BIT(22) | BIT(21) | BIT(20) | BIT(18) | BIT(10)) } },
			{ PCIE_UNRST, 1, { HSDT_PERRSTDIS0 }, { (BIT(29) | BIT(27) | BIT(25) | BIT(22) | BIT(20) | BIT(18) | BIT(10)) } },
			// hsdt_ioc bit2/pciephy_ref_soft bit4/pcieio_soft bit5/Sctrl bit11/dfa bit15/
			{ OPEN_SYSCLK, 1, { HSDT_PEREN0 }, { 0x43FC5 } },
			{ CLOSE_SYSCLK, 1, { HSDT_PERDIS0 }, { 0x437F1 } },
			{ SC_RST, 1, { HIPCIE_RSTEN0_X1 }, { 0xFFFFFFFFU } },
			{ SC_UNRST, 1, { HIPCIE_RSTDIS0_X1 }, { 0xFFFFFFFFU } },
			{ EN_SC_CLK, 2, { HIPCIE_ICG_EN0_X1, HIPCIE_ICG_EN1_X1 }, { 0xFFFFFFFFU, 0xFFFFFFFFU } },
			{ DIS_SC_CLK, 2, { HIPCIE_ICG_DIS0_X1, HIPCIE_ICG_DIS1_X1 }, { 0xFFFFFFFFU, 0xFFFFFFFFU } },
			{ OE_IE_CFG_RC, 1, { PCIEX1_1_CTRL0 }, { BIT(27) } },
			{ OE_IE_CFG_EP, 1, { PCIEX1_1_CTRL0 }, { (BIT(11) | BIT(9) | BIT(6)) } },
			{ OE_IE_RST, 1, { PCIEX1_1_CTRL0 }, { (BIT(11) | BIT(27)) } },
			{ CTRL_SD_EXIT, 0, {}, {} },
			{ SMMU_SD_EXIT, 1, { HSDT_SCTRL_SMMU_SD }, { BIT(2) } },
			{ PHY_RST_N_SEL, 1, { HIPCIE_PHY_CFG0 }, { BIT(5) } },
			{ PHY_PORN_RST, 1, { HIPCIE_PHY_CFG0 }, { (BIT(2)) } },
			{ PHY_APB_UNRESET, 1, { HSDT_PERRSTDIS0 }, { BIT(23) } },
			{ PHY_APB_RESET, 1, { HSDT_PERRSTEN0 }, { BIT(23) } },
			{ PHY_RESET_N, 1, { HIPCIE_PHY_CFG0 }, { (BIT(4)) } },
			{ PIPE_RESET_N, 0, { HIPCIE_PHY_CFG0 }, { (BIT(6) | BIT(7)) } },
			{ CTRL_PORN_UNRST, 1, { HSDT_PERRSTDIS0 }, { (BIT(21)) } },
			{ CTRL_PORN_RST, 1, { HSDT_PERRSTEN0 }, { (BIT(21)) } },
			{ PIPE_CLK_STABLE, 1, { HIPCIE_CTRL_STAT2 }, { (BIT(19)) } },
			{ PU_RX_TERMIANTION, 1, { HIPCIE_PHY_CFG1 }, { (BIT(0) | BIT(16)) } },
			{ CLKREQ_IDLE_TIMEOUT, 0, {},{} },
			{ CLKREQ_NO_DELAY, 0, {}, {} },
			{ QIC_POWER_DOMAIN_ENTER, 1, { 0x424 }, { BIT(5) } },
			{ QIC_POWER_DOMAIN_EXIT, 1, { 0x424 }, { BIT(5) } },
			{ OPEN_RST_ITNR, 2, { HIPCIE_MISC_CFG14, HIPCIE_MISC_CFG15 }, { BIT(0), BIT(0) } },
		}
	}
};

#ifdef CONFIG_HIPCIE_IDLE
enum {
	OPEN_RFF_CLK = 0,
	CLOSE_RFF_CLK,
	IDLE_BEHAVIOR_MAX,
};

struct hi_pcie_idle_behavior {
	u32 ctrl_id;
	u32 port_id;
	struct pcie_behavior behavior[IDLE_BEHAVIOR_MAX];
};

const struct hi_pcie_idle_behavior pcie_idle_step[] = {
	{ RC_ID0, 0,
		{
			{ OPEN_RFF_CLK, 1, { HSDT_PEREN1 }, { (BIT(2) | BIT(1)) } }, // debounce/hp/phy_ref hardware control
			{ CLOSE_RFF_CLK, 1, { HSDT_PERDIS1 }, { (BIT(2) | BIT(1)) } }, // debounce/hp/phy_ref hardware control
			// OPEN_IO_CLK/CLOSE_IO_CLK hardware control
		}
	}, { RC_ID1, 0,
		{
			{ OPEN_RFF_CLK, 1, { HSDT_PEREN0 }, { (BIT(7) | BIT(6)) } }, // debounce/hp/phy_ref hardware control
			{ CLOSE_RFF_CLK, 1, { HSDT_PERDIS0 }, { (BIT(7) | BIT(6)) } }, // debounce/hp/phy_ref hardware control
			// OPEN_IO_CLK/CLOSE_IO_CLK hardware control
		}
	}
};
#endif

u32 chs_pcie_ao_crg_reg_readl(struct hi_pcie_chs *plat, u32 reg)
{
	return readl(plat_config.aocrg_base + reg);
}

void chs_pcie_ao_crg_reg_writel(struct hi_pcie_chs *plat, u32 val, u32 reg)
{
	hi_pcie_pr_d("%s, value %x, reg %x", __func__, val, reg);
	writel(val, plat_config.aocrg_base + reg);
}

u32 chs_pcie_hsdt_crg_reg_readl(struct hi_pcie_chs *plat, u32 reg)
{
	return readl(plat_config.hsdtcrg_base + reg);
}

void chs_pcie_hsdt_crg_reg_writel(struct hi_pcie_chs *plat, u32 val, u32 reg)
{
	hi_pcie_pr_d("%s, value %x, reg %x", __func__, val, reg);
	writel(val, plat_config.hsdtcrg_base + reg);
}

u32 chs_pcie_sysctrl_readl(struct hi_pcie_chs *plat, u32 reg)
{
	return readl(plat->sysctrl_base + reg);
}

void chs_pcie_sysctrl_writel(struct hi_pcie_chs *plat, u32 val, u32 reg)
{
	hi_pcie_pr_d("%s, value %x, reg %x", __func__, val, reg);
	writel(val, plat->sysctrl_base + reg);
}

u32 chs_pcie_hsdt_sctrl_reg_readl(struct hi_pcie_chs *plat, u32 reg)
{
	return readl(plat_config.hsdtsctrl_base + reg);
}

void chs_pcie_hsdt_sctrl_reg_writel(struct hi_pcie_chs *plat, u32 val, u32 reg)
{
	hi_pcie_pr_d("%s, value %x, reg %x", __func__, val, reg);
	writel(val, plat_config.hsdtsctrl_base + reg);
}

u32 chs_pcie_hsdt_xctrl_reg_readl(struct hi_pcie_chs *plat, u32 reg)
{
	return readl(plat_config.hsdtxctrl_base + reg);
}

void chs_pcie_hsdt_xctrl_reg_writel(struct hi_pcie_chs *plat, u32 val, u32 reg)
{
	hi_pcie_pr_d("%s, value %x, reg %x", __func__, val, reg);
	writel(val, plat_config.hsdtxctrl_base + reg);
}

u32 chs_pcie_fnpll_reg_readl(struct hi_pcie_chs *plat, u32 reg)
{
	return readl(plat_config.pcie_fnpll_base + reg);
}

void chs_pcie_fnpll_reg_writel(struct hi_pcie_chs *plat, u32 val, u32 reg)
{
	hi_pcie_pr_d("%s, value %x, reg %x", __func__, val, reg);
	writel(val, plat_config.pcie_fnpll_base + reg);
}

void chs_pcie_vote_doze(struct hi_pcie *pcie, bool enable)
{
	int ret;
	int vote_id = ((pcie->ctrl_id == RC_ID0) ? DOZE_CLIENT_PCIE0 : DOZE_CLIENT_PCIE1);

	if (enable)
		ret = vote_enable_doze(vote_id);
	else
		ret = vote_disable_doze(vote_id);

	if (ret < 0)
		hi_pcie_pr_e("pcie %u enable/disable=%d doze fail", pcie->ctrl_id, enable);
}

static int chs_pcie_clk_check(struct hi_pcie_chs *plat)
{
	u32 val;
	// 19.2M, aux clk check
	val = chs_pcie_ao_crg_reg_readl(plat, SCPERSTAT3);
	hi_pcie_pr_e("ack_clk_pcie_aux(1): reg %x, value %x", SCPERSTAT3, (val>>17) & 0x3);
	val = chs_pcie_ao_crg_reg_readl(plat, SCPERSTAT2);
	hi_pcie_pr_e("clk_hsdt0_pcie_aux(1): reg %x, value %x", SCPERSTAT2, (val>>18) & 0x1);
	val = chs_pcie_ao_crg_reg_readl(plat, SCPERSTAT0);
	hi_pcie_pr_e("clk_pcie01_aux(0x3): reg %x, value %x", SCPERSTAT0, (val>>13) & 0x3);

	val = chs_pcie_ao_crg_reg_readl(plat, SCPERSTAT1);
	hi_pcie_pr_e("st_clk_hsdt_subsys(1): reg %x, value %x", SCPERSTAT3, (val>>26) & 0x1);
	return 0;
}

static void chs_pcie_clk_config(struct hi_pcie_chs *plat)
{
	u32 val;
	/* clk_hsdt_subsys set to 238.74M */
	chs_pcie_ao_crg_reg_writel(plat, 0x003F0006, AOCRGSCCLKDIV3);

	// autofs PCIE_on
	chs_pcie_ao_crg_reg_writel(plat, 0x07E0283F, AOCRGAO_AUTODIV2);
	chs_pcie_hsdt_crg_reg_writel(plat, 0x0, HSDT_CRG_PERI_AUTODIV3);

	// diable auto frequency modulation bypass
	val = chs_pcie_ao_crg_reg_readl(plat, AOCRGAO_AUTODIV2);
	val &= ~BIT(0); // peri_div_auto_reduce_bypass
	chs_pcie_ao_crg_reg_writel(plat, val, AOCRGAO_AUTODIV2);

	// auto frequency modulation monitor clk enable
	val = chs_pcie_ao_crg_reg_readl(plat, AOCRGSCPEREN6);
	val |= BIT(4);
	chs_pcie_ao_crg_reg_writel(plat, val, AOCRGSCPEREN6);
}

void chs_pcie_noc_power_exit(struct hi_pcie_chs *plat, bool exit)
{
	int step;
	u32 val_mask;
	u32 reg;
	int behavior = exit ? QIC_POWER_DOMAIN_EXIT : QIC_POWER_DOMAIN_ENTER;
	int size = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].size;

	for (step = 0; step < size; step++) {
		reg = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].base_addr[step];
		val_mask = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].val[step];
		if (exit)
			chs_pcie_hsdt_xctrl_reg_writel(plat, val_mask << 16, reg);
		else
			chs_pcie_hsdt_xctrl_reg_writel(plat, (val_mask << 16) | val_mask, reg);;
	}
}

int chs_pcie_noc_idle_check(struct hi_pcie_chs *plat, bool exit)
{
	int step;
	u32 val_mask;
	u32 reg;
	u32 val;
	u32 time = 1000;
	int behavior = exit ? QIC_POWER_DOMAIN_EXIT : QIC_POWER_DOMAIN_ENTER;
	int size = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].size;
	u32 state_offset = 0x4;

	for (step = 0; step < size; step++) {
		reg = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].base_addr[step];
		reg = reg + state_offset;
		val_mask = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].val[step];
		val = chs_pcie_hsdt_xctrl_reg_readl(plat, reg);
		while (((val & val_mask) != 0) == exit) {
			udelay(1);
			if (time == 0) {
				hi_pcie_pr_e("noc power %s idle failed : %u", exit ? "exit" : "enter", val);
				return -1;
			}
			time--;
			val = chs_pcie_hsdt_xctrl_reg_readl(plat, reg);
		}
	}
	return 0;
}

static int chs_pcie_qic_power_domain_exit(struct hi_pcie_chs *plat, bool exit)
{
	chs_pcie_noc_power_exit(plat, exit);
	return chs_pcie_noc_idle_check(plat, exit);
}

static void chs_pcie_rst_cfg(struct hi_pcie_chs *plat, int behavior)
{
	u32 val_mask;
	u32 reg;
	int size = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].size;
	int step;

	for (step = 0; step < size; step++) {
		reg = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].base_addr[step];
		val_mask = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].val[step];
		chs_pcie_hsdt_crg_reg_writel(plat, val_mask, reg);
	}
}

static void chs_pcie_common_rst_cfg(struct hi_pcie_chs *plat)
{
	if (atomic_sub_return(1, &hsdt_pcie_common_rst_cnt) == 0) {
		hi_pcie_pr_d("pcie common rst_cfg");
		chs_pcie_hsdt_crg_reg_writel(plat, BIT(3), HSDT_PERRSTEN0); // tocheck tcu | fsm
	}
}

static void chs_pcie_common_unrst_cfg(struct hi_pcie_chs *plat)
{
	if (atomic_add_return(1, &hsdt_pcie_common_rst_cnt) == 1) {
		hi_pcie_pr_d("pcie common unrst_cfg");
		chs_pcie_hsdt_crg_reg_writel(plat, BIT(3), HSDT_PERRSTDIS0); // tocheck tcu | fsm
	}
}

static void chs_pcie_common_clk_cfg(struct hi_pcie_chs *plat)
{
	if (atomic_add_return(1, &hsdt_pcie_common_clk_cnt) == 1) {
		hi_pcie_pr_d("pcie common clk_cfg");
		chs_pcie_hsdt_crg_reg_writel(plat, BIT(10), HSDT_PEREN1); // tcu
	}
}

static void chs_pcie_common_clk_uncfg(struct hi_pcie_chs *plat)
{
	if (atomic_sub_return(1, &hsdt_pcie_common_clk_cnt) == 0) {
		hi_pcie_pr_d("pcie common clk_uncfg");
		chs_pcie_hsdt_crg_reg_writel(plat, BIT(10), HSDT_PERDIS1);
	}
}

static void chs_pcie_hardware_clk_cfg(struct hi_pcie_chs *plat, bool open)
{
	u32 val_mask;
	u32 reg;
	if (open) {
		// close clk soft gate phy_ref_soft/pcieio_soft
		reg = ((plat->pcie->ctrl_id == RC_ID0) ? HSDT_PERDIS1 : HSDT_PERDIS0);
		val_mask = chs_pcie_hsdt_crg_reg_readl(plat, reg);
		val_mask |= ((plat->pcie->ctrl_id == RC_ID0) ? (BIT(6) | BIT(7)) : (BIT(4) | BIT(5)));
		chs_pcie_hsdt_crg_reg_writel(plat, val_mask, reg);

		// open clk hardware gate, enable
		reg = ((plat->pcie->ctrl_id == RC_ID0) ? HSDT_CRG_PCIECTRL0 : HSDT_CRG_PCIECTRL1);
		val_mask = chs_pcie_hsdt_crg_reg_readl(plat, reg);
		val_mask &= ~(BIT(1) | BIT(0)); // phy_ref_hard_bypass=0x0/pcieio_soft=0x0
		chs_pcie_hsdt_crg_reg_writel(plat, val_mask, reg);
		hi_pcie_pr_d("close clk soft gate, open hardware gate");
	} else {
		// close clk hardware gate, bypass
		reg = ((plat->pcie->ctrl_id == RC_ID0) ? HSDT_CRG_PCIECTRL0 : HSDT_CRG_PCIECTRL1);
		val_mask = chs_pcie_hsdt_crg_reg_readl(plat, reg);
		val_mask |= (BIT(1) | BIT(0)); // phy_ref_hard_bypass=0x1/pcieio_soft=0x1
		val_mask |= BIT(11); // pcieio_oe_en_hard bypass
		chs_pcie_hsdt_crg_reg_writel(plat, val_mask, reg);
		hi_pcie_pr_d("open clk soft gate, close hardware gate");
	}
}

static void chs_pcie_sysclk_ctrl(struct hi_pcie_chs *plat, bool open)
{
	u32 val_mask;
	u32 reg;
	int behavior = open ? OPEN_SYSCLK : CLOSE_SYSCLK;
	int size = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].size;
	int step;

	for (step = 0; step < size; step++) {
		reg = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].base_addr[step];
		val_mask = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].val[step];
		chs_pcie_hsdt_crg_reg_writel(plat, val_mask, reg);
	}
}

void chs_pcie_sc_rst_cfg(struct hi_pcie_chs *plat, bool reset)
{
	int step;
	u32 val;
	u32 val_mask;
	u32 reg;
	int behavior = reset ? SC_RST : SC_UNRST;
	int size = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].size;

	for (step = 0; step < size; step++) {
		reg = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].base_addr[step];
		val_mask = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].val[step];

		val = chs_pcie_sysctrl_readl(plat, reg);
		val = val | val_mask;
		chs_pcie_sysctrl_writel(plat, val, reg);
	}
}

void chs_pcie_sc_clk_ctrl(struct hi_pcie_chs *plat, bool open)
{
	u32 val;
	u32 val_mask;
	u32 reg;
	int behavior = open ? EN_SC_CLK : DIS_SC_CLK;
	int size = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].size;
	int step;

	for (step = 0; step < size; step++) {
		reg = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].base_addr[step];
		val_mask = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].val[step];

		val = chs_pcie_sysctrl_readl(plat, reg);
		val = val | val_mask;
		chs_pcie_sysctrl_writel(plat, val, reg);
	}
}

static void chs_pcie_fnpll_cfg_init(struct hi_pcie_chs *plat)
{
	chs_pcie_fnpll_reg_writel(plat, 0x000000CA, FNPLL_PCIE_ANALOG_CFG0);
	chs_pcie_fnpll_reg_writel(plat, 0x0000000C, FNPLL_PCIE_ANALOG_CFG1);
	chs_pcie_fnpll_reg_writel(plat, 0x16204036, FNPLL_PCIE_ANALOG_CFG2);
	chs_pcie_fnpll_reg_writel(plat, 0x00000000, FNPLL_PCIE_ANALOG_CFG3);
	chs_pcie_fnpll_reg_writel(plat, 0x0032C000, FNPLL_PCIE_ADPLL_ATUNE_CFG);
	chs_pcie_fnpll_reg_writel(plat, 0x026020A0, FNPLL_PCIE_ADPLL_PTUNE_CFG);
	chs_pcie_fnpll_reg_writel(plat, 0x00012D3F, FNPLL_PCIE_DTC_CFG);
	chs_pcie_fnpll_reg_writel(plat, 0x05366E1F, FNPLL_PCIE_FTDC_CFG);

	chs_pcie_fnpll_reg_writel(plat, 0x6420030A, FNPLL_PCIE_FDTC_LMS_CFG);
	chs_pcie_fnpll_reg_writel(plat, 0x5620163F, FNPLL_PCIE_DTC_LMS_CFG);
	chs_pcie_fnpll_reg_writel(plat, 0x20037015, FNPLL_PCIE_LPF_BW_I_T01);
	chs_pcie_fnpll_reg_writel(plat, 0x00003B25, FNPLL_PCIE_LPF_BW_P_T01);
	chs_pcie_fnpll_reg_writel(plat, 0x00000000, FNPLL_PCIE_ADPLL_DCO_TMODE);
	chs_pcie_fnpll_reg_writel(plat, 0x00010000, FNPLL_PCIE_ADPLL_LPF_TEST_CFG);
	chs_pcie_fnpll_reg_writel(plat, 0x00000003, FNPLL_PCIE_ADPLL_DSM_CFG);
	chs_pcie_fnpll_reg_writel(plat, plat->ftdc_lock_thr, FNPLL_PCIE_ADPLL_FTDC_LOCK_THR);

	chs_pcie_fnpll_reg_writel(plat, 0x0100103F, FNPLL_PCIE_ADPLL_FTDC_UNLOCK_THR);
	chs_pcie_fnpll_reg_writel(plat, 0x81000A0A, FNPLL_PCIE_CHAOS_CNT_THR_CFG);
	chs_pcie_fnpll_reg_writel(plat, 0x8858D00F, FNPLL_PCIE_ADPLL_CLK_EN_CFG0);
	chs_pcie_fnpll_reg_writel(plat, 0x00000000, FNPLL_PCIE_MAN_TRIG_LMS_CNT_CFG);
	chs_pcie_fnpll_reg_writel(plat, 0x00100010, FNPLL_PCIE_DTC_LINEAR_TEST_MODE);
	chs_pcie_fnpll_reg_writel(plat, 0x0020A420, FNPLL_PCIE_FREZ_LMS_PTHR);
	chs_pcie_fnpll_reg_writel(plat, 0x01FE1FFF, FNPLL_PCIE_ACQ_CNT_THR_CFG);
	chs_pcie_fnpll_reg_writel(plat, 0x000FF102, FNPLL_PCIE_ADPLL_DLY_CFG);
	chs_pcie_fnpll_reg_writel(plat, 0x00000000, FNPLL_PCIE_PTUNE_FBDIV);

	udelay(1);
}

static int chs_pcie_fnpll_freq_init(struct hi_pcie_chs *plat, int cnt)
{
	u32 val;
	u32 val_mask = FNPLL_LOCK_BIT;
	u32 timeout = FNPLL_LOCK_TIMEOUT;

	// EN=0&&BYPASS=1
	chs_pcie_hsdt_crg_reg_writel(plat, 0x00000002, HSDT_CRG_PCIEPLL_PCIE_CTRL0);
	chs_pcie_hsdt_crg_reg_writel(plat, 0x2C455555, HSDT_CRG_PCIEPLL_PCIE_FCW);
	// EN=1&&BYPASS=1
	chs_pcie_hsdt_crg_reg_writel(plat, 0x00000003, HSDT_CRG_PCIEPLL_PCIE_CTRL0);

	udelay(50);

	val = chs_pcie_hsdt_crg_reg_readl(plat, HSDT_CRG_PCIEPLL_STATE);
	while ((val & val_mask) == 0) {
		udelay(10);
		if (timeout == 0) {
			hi_pcie_pr_e("FNPLL lock timeout, val 0x%x, try time: %d",val, cnt + 1);
			return -1;
		}
		timeout--;
		val = chs_pcie_hsdt_crg_reg_readl(plat, HSDT_CRG_PCIEPLL_STATE);
	}

	// EN=1&&BYPASS=0
	chs_pcie_hsdt_crg_reg_writel(plat, 0x00000001, HSDT_CRG_PCIEPLL_PCIE_CTRL0);

	hi_pcie_pr_i("FNPLL lock succ, try time: %d", cnt + 1);
	return 0;
}

static int chs_pcie_fnpll_cfg(struct hi_pcie_chs *plat,  bool is_idle)
{
	int ret = 0;
	int i;
	u32 fnpll_val;
	u32 fnpll_state;
	unsigned long flag;

#ifdef CONFIG_HIPCIE_TEST
	if ((!is_idle) && (stub_hi_pcie_fault_injection(HIPCIE_FAULT_INIT_TYPE_FNPLL_CFG) != 0x0))
		return -1;
#else
	(void)is_idle;
#endif

	spin_lock_irqsave(&pcie_fnpll_lock, flag);

	fnpll_val = chs_pcie_hsdt_crg_reg_readl(plat, HSDT_CRG_PCIEPLL_PCIE_CTRL0);
	fnpll_state = chs_pcie_hsdt_crg_reg_readl(plat, HSDT_CRG_PCIEPLL_STATE);
	hi_pcie_pr_i("[%s]fnpll_ctrl[0x%x]=0x%x, fnpll_stat[0x%x]=0x%x", __func__, HSDT_CRG_PCIEPLL_PCIE_CTRL0, fnpll_val,
		HSDT_CRG_PCIEPLL_STATE, fnpll_state);
	if ((fnpll_val & PCIEPLL_STATE_MASK) == PCIEPLL_STATE_CLOSE) {
		for (i = 0; i < PCIE_FNPLL_RETRY_TIME; i++) {
			chs_pcie_fnpll_cfg_init(plat);
			ret = chs_pcie_fnpll_freq_init(plat, i);
			if (ret == 0)
				break;
		}
		if (i == PCIE_FNPLL_RETRY_TIME) {
			hi_pcie_pr_e("FNPLL Lock Failed!");
			goto FNPLL_END;
		}
	}

FNPLL_END:
	atomic_or((1 << plat->pcie->ctrl_id), &pcie_fnpll_cnt);
	hi_pcie_pr_e("+%s+ pcie_fnpll_cnt = %d ", __func__, atomic_read(&pcie_fnpll_cnt));
	spin_unlock_irqrestore(&pcie_fnpll_lock, flag);

	return ret;
}

static int chs_pcie_phy_clk_uncfg(struct hi_pcie_chs *plat)
{
	unsigned long flag;
	spin_lock_irqsave(&pcie_fnpll_lock, flag);

	atomic_andnot(1 << plat->pcie->ctrl_id, &pcie_fnpll_cnt);
	hi_pcie_pr_e("+%s+ pcie_fnpll_cnt = %d ", __func__, atomic_read(&pcie_fnpll_cnt));
	if (atomic_read(&pcie_fnpll_cnt) == 0) {
		chs_pcie_hsdt_crg_reg_writel(plat, 0x00000002, HSDT_CRG_PCIEPLL_PCIE_CTRL0);
	}

	spin_unlock_irqrestore(&pcie_fnpll_lock, flag);
	return 0;
}

void chs_pcie_oe_ie_cfg(struct hi_pcie_chs *plat, int behavior)
{
	int step;
	u32 val;
	u32 val_mask;
	u32 reg;
	int size = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].size;

	for (step = 0; step < size; step++) {
		reg = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].base_addr[step];
		val_mask = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].val[step];

		val = chs_pcie_hsdt_crg_reg_readl(plat, reg);
		val = val | val_mask;
		if (plat->pcie->mode == PCIE_MODE_RC)
			val &= 0xCFFFF5BFU;
		else
			val &= 0xC7FFFFFFU;
		chs_pcie_hsdt_crg_reg_writel(plat, val, reg);
	}
}

void chs_pcie_oe_ie_rst(struct hi_pcie_chs *plat, int behavior)
{
	int step;
	u32 val;
	u32 val_mask;
	u32 reg;
	int size = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].size;

	for (step = 0; step < size; step++) {
		reg = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].base_addr[step];
		val_mask = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].val[step];

		val = chs_pcie_hsdt_crg_reg_readl(plat, reg);
		val = val | val_mask;
		val &= 0xCFFFFDBF;
		chs_pcie_hsdt_crg_reg_writel(plat, val, reg);
	}
}

void chs_pcie_clkreq_idle_timeout_cfg(struct hi_pcie_chs *plat)
{
	u32 val;
	u32 reg;
	int size;
	int step;
	int behavior = CLKREQ_IDLE_TIMEOUT;

	size = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].size;
	for (step = 0; step < size; step++) {
		reg = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].base_addr[step];
		val = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].val[step];
		chs_pcie_sysctrl_writel(plat, val, reg);
	}
}

void chs_pcie_clkreq_debounce_cfg(struct hi_pcie_chs *plat)
{
	// 2.5.1.2 CLKREQ# debounce cfg
	chs_pcie_sysctrl_writel(plat, DEBOUNCE_CYCLES, HIPCIE_CTRL_REG31);

	// 2.5.1.3 CLKREQ# delay send controller
	if (!plat->fnpll_hw_auto_open) {
		chs_pcie_sysctrl_writel(plat, BIT(4) | BIT(20), HIPCIE_CLKREQ_IN_N_CTRL); // bit4=0x1
		return;
	}
	chs_pcie_sysctrl_writel(plat, BIT(20), HIPCIE_CLKREQ_IN_N_CTRL); // bit4=0x0
	chs_pcie_sysctrl_writel(plat, 0x0, HIPCIE_CON_CLKREQ_IN_N_CNT_BASE); // @todo 0x0
}

void chs_pcie_iso_ctrl_cfg(struct hi_pcie_chs *plat, bool enable)
{
	u32 val;
	u32 reg = HIPCIE_SOC2PHY_ISOEN;
	if (!enable) {
		val = chs_pcie_sysctrl_readl(plat, reg);
		val = val & 0xFFFFFFFCU;
		chs_pcie_sysctrl_writel(plat, val, reg);
	}
}

void chs_pcie_ctrl_memsd_exit(struct hi_pcie_chs *plat, int behavior)
{
	int step;
	u32 val_mask;
	u32 reg;
	int size = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].size;

	for (step = 0; step < size; step++) {
		reg = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].base_addr[step];
		val_mask = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].val[step];
		chs_pcie_sysctrl_writel(plat, val_mask, reg);
	}
}

void chs_pcie_smmu_memsd_exit(struct hi_pcie_chs *plat, int behavior, bool enable)
{
	int step;
	u32 val;
	u32 val_mask;
	u32 reg;
	int size = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].size;
	if (enable) {
		if (atomic_add_return(1, &pcie_tcu_sd_cnt) == 1)
			chs_pcie_hsdt_sctrl_reg_writel(plat, 0x10000, HSDT_SCTRL_SMMU_SD);
	} else {
		if (atomic_sub_return(1, &pcie_tcu_sd_cnt) == 0)
			chs_pcie_hsdt_sctrl_reg_writel(plat, 0x10001, HSDT_SCTRL_SMMU_SD);
	}

	for (step = 0; step < size; step++) {
		reg = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].base_addr[step];
		val_mask = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].val[step];
		val = chs_pcie_hsdt_sctrl_reg_readl(plat, reg);
		if (enable) {
			val &= ~val_mask;
		} else {
			val |= val_mask;
		}
		val |= (val_mask << 16);
		chs_pcie_hsdt_sctrl_reg_writel(plat, val, reg);
	}
}

void chs_pcie_mem_sd_exit(struct hi_pcie_chs *plat, bool enable)
{
	chs_pcie_ctrl_memsd_exit(plat, CTRL_SD_EXIT);

	chs_pcie_smmu_memsd_exit(plat, SMMU_SD_EXIT, enable);
}

void chs_pcie_do_phy_reset(struct hi_pcie_chs *plat, int behavior, bool reset)
{
	int step;
	u32 reg;
	u32 val;
	int size = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].size;

	for (step = 0; step < size; step++) {
		reg = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].base_addr[step];
		val = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].val[step];
		if (reset)
			val <<= 16;
		else
			val |= (val << 16);
		chs_pcie_sysctrl_writel(plat, val, reg);
	}
}

void chs_pcie_phy_apb_reset(struct hi_pcie_chs *plat, int behavior)
{
	int step;
	u32 reg;
	u32 val_mask;
	int size = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].size;

	for (step = 0; step < size; step++) {
		reg = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].base_addr[step];
		val_mask = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].val[step];
		chs_pcie_hsdt_crg_reg_writel(plat, val_mask, reg);
	}
}

void chs_pcie_phy_refclk_sel(struct hi_pcie_chs *plat)
{
	u32 val;
	struct hi_pcie_ctrl *ctrl = plat->ctrl;

	if (ctrl->pcie->mode == PCIE_MODE_RC)
		return;
	// ep from pcie_clkio
	val = chs_pcie_sysctrl_readl(plat, HIPCIE_PHY_CFG0);
	val |= (BIT(10) | BIT(26));
	chs_pcie_sysctrl_writel(plat, val, HIPCIE_PHY_CFG0);
}

void chs_pcie_phy_cfg_x1(struct hi_pcie_chs *plat)
{
	struct hi_pcie_ctrl *ctrl = plat->ctrl;
	struct hi_pcie_phy *phy = &plat->pcie->phy;

	if (ctrl->pcie->mode == PCIE_MODE_EP)
	    pcie_kphy_pcs_clk_sel(phy);

	pcie_kphy_setup_chs(phy);

	if (plat->pcie->phy_dfx_ops && plat->pcie->phy_dfx_ops->phy_param_change)
		plat->pcie->phy_dfx_ops->phy_param_change(phy);

	chs_pcie_do_phy_reset(plat, PHY_RESET_N, false);
	chs_pcie_do_phy_reset(plat, PIPE_RESET_N, false);
}

void chs_pcie_phy_cfg(struct hi_pcie_chs *plat)
{
	if (plat->pcie->chip_type == BOARD_FPGA) {
		chs_pcie_do_phy_reset(plat, PHY_RESET_N, false);
		chs_pcie_do_phy_reset(plat, PIPE_RESET_N, false);
		return;
	}

	chs_pcie_phy_cfg_x1(plat);
}

void chs_pcie_phy_init(struct hi_pcie_chs *plat)
{
	chs_pcie_do_phy_reset(plat, PHY_RST_N_SEL, false); // 2.9.1
	chs_pcie_do_phy_reset(plat, PHY_PORN_RST, false); // 2.9.2
	chs_pcie_phy_apb_reset(plat, PHY_APB_UNRESET); // 2.9.3
	chs_pcie_phy_refclk_sel(plat);

	chs_pcie_phy_cfg(plat);
}

void chs_pcie_reset_phy(struct hi_pcie_chs *plat)
{
	chs_pcie_do_phy_reset(plat, PIPE_RESET_N, true);
	chs_pcie_do_phy_reset(plat, PHY_RESET_N, true);
	chs_pcie_phy_apb_reset(plat, PHY_APB_RESET);
	chs_pcie_do_phy_reset(plat, PHY_PORN_RST, true);
}

int chs_pcie_perst_from_gpio(struct hi_pcie_chs *plat, int pull_up)
{
	int ret = 0;
	struct hi_pcie_port *port = NULL;
	list_for_each_entry(port, &plat->pcie->ports, node) {
		if (pull_up && port->poweron_callback)
			ret = port->poweron_callback(port->power_callback_data);
		else if (!pull_up && port->poweroff_callback)
			ret = port->poweroff_callback(port->power_callback_data);
		if (ret != 0)
			return ret;
	}
	return 0;
}

#define HIPCIE_MISC_CFG4_X4 0x044
#define SC_PCIE_CTRL_12		0x030

int chs_pcie_perst_from_pinctrl(struct hi_pcie_chs *plat, int pull_up)
{
	u32 val;

	val = chs_pcie_sysctrl_readl(plat, SC_PCIE_CTRL_12);
	if (pull_up) {
		// bit 0 set 1, bit 1 set 1
		val = val | BIT(0) | BIT(1);
	} else {
		// bit 0 set 0, bit 1 set 1
		val = val & 0xFFFFFFFEU;
		val = val | BIT(1);
	}
	chs_pcie_sysctrl_writel(plat, val, SC_PCIE_CTRL_12);

	return 0;
}

int chs_pcie_perst_config(struct hi_pcie_chs *plat, int pull_up)
{
	int ret;

#ifdef CONFIG_HIPCIE_TEST
	u32 type = ((pull_up == ENABLE) ? HIPCIE_FAULT_INIT_TYPE_PERST : HIPCIE_FAULT_EXIT_TYPE_PERST);
	if (stub_hi_pcie_fault_injection(type))
		return -1;
#endif

	if (plat->pcie->mode == PCIE_MODE_EP)
		return 0;

	if (pull_up)
		usleep_range(10, 11);

	if (plat->pcie->chip_type == BOARD_FPGA) {
		ret = chs_pcie_perst_from_pinctrl(plat, pull_up);
	} else {
		ret = chs_pcie_perst_from_gpio(plat, pull_up);
	}

	if (ret)
		hi_pcie_pr_e("Failed to pulse perst signal");

	usleep_range(10, 11);
	return ret;
}

void chs_pcie_ctrl_por_n_rst(struct hi_pcie_chs *plat, bool reset)
{
	u32 val_mask;
	u32 reg;
	int step;
	int behavior = reset ? CTRL_PORN_RST : CTRL_PORN_UNRST;
	int size = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].size;

	for (step = 0; step < size; step++) {
		reg = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].base_addr[step];
		val_mask = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].val[step];
		chs_pcie_hsdt_crg_reg_writel(plat, val_mask, reg);
	}
}

bool chs_pcie_is_pipe_clk_stable(struct hi_pcie_chs *plat, int behavior)
{
	int step;
	u32 val_mask;
	u32 reg;
	u32 val;
	u32 time = 100; /* try 100 times */
	int size = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].size;

#ifdef CONFIG_HIPCIE_TEST
	if (stub_hi_pcie_fault_injection(HIPCIE_FAULT_INIT_TYPE_PIPECLK))
		return false;
#endif

	for (step = 0; step < size; step++) {
		reg = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].base_addr[step];
		val_mask = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].val[step];
		val = chs_pcie_sysctrl_readl(plat, reg);
		while ((val & val_mask) != 0) {
			mdelay(1);
			if (time == 0) {
				hi_pcie_pr_e("PIPE clk is not stable, val = 0x%x", val);
				return false;
			}
			time--;
			val = chs_pcie_sysctrl_readl(plat, reg);
		}
	}

	hi_pcie_pr_d("PIPE clk is stable in (1000-%u)*100 us", time);
	return true;
}

void chs_pcie_rx_term_cfg(struct hi_pcie_chs *plat, int behavior)
{
	int step;
	u32 val_mask;
	u32 reg;
	u32 val;
	int size = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].size;

	for (step = 0; step < size; step++) {
		reg = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].base_addr[step];
		val_mask = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].val[step];
		val = chs_pcie_sysctrl_readl(plat, reg);
		val = val | val_mask;
		chs_pcie_sysctrl_writel(plat, val, reg);
	}
}

void chs_pcie_firewall_fix(struct hi_pcie_chs *plat)
{
#ifdef CONFIG_HIPCIE_SUPPORT_FFA
	int ret;
	struct ffa_send_direct_data args = {0};

	args.data0 = FID_PCIE_SET_MEM_UNSEC;
	args.data1 = (u64)plat->pcie->ctrl_id;

	ret = ffa_platdrv_send_msg(&args);
	if (ret != 0) {
		hi_pcie_pr_e("fix firewall failed");
		return;
	}
	hi_pcie_pr_d("fix firewall by tzsp");
#else
	struct arm_smccc_res res;
	arm_smccc_smc((u64)FID_PCIE_SET_MEM_UNSEC, (u64)plat->pcie->ctrl_id,
		0, 0, 0, 0, 0, 0, &res);
	hi_pcie_pr_d("fix firewall by atf");
#endif
}

static noinline uint64_t chs_pcie_tbu_bypass(struct hi_pcie_chs *plat)
{
#ifdef CONFIG_HIPCIE_SUPPORT_FFA
	int ret;
	struct ffa_send_direct_data args = {0};

	args.data0 = FID_PCIE_SET_TBU_BYPASS;
	args.data1 = (u64)plat->pcie->ctrl_id;

	ret = ffa_platdrv_send_msg(&args);
	if (ret != 0) {
		hi_pcie_pr_e("Bypass TBU failed, ret = %d", ret);
	}
	hi_pcie_pr_i("set tbu bypass by tzsp");
	return args.data0;
#else
	struct arm_smccc_res res;
	arm_smccc_smc((u64)FID_PCIE_SET_TBU_BYPASS, (u64)plat->pcie->ctrl_id,
		0, 0, 0, 0, 0, 0, &res);
	hi_pcie_pr_i("set tbu bypass by atf");
	return res.a0;
#endif
}

bool chs_pcie_is_smmu_bypass(struct hi_pcie_chs *plat)
{
	if (IS_ENABLED(CONFIG_MM_IOMMU_DMA) && !plat->pcie->bypass_smmu)
		return false;
	return true;
}

#define TBU_CONFIG_TIMEOUT			1000
#define PCIE_TBU_CR					0x0
#define PCIE_TBU_CRACK				0x4
#define PCIE_TBU_EN_REQ_BIT			BIT(0)
#define PCIE_TBU_EN_ACK_BIT			BIT(0)
#define PCIE_TBU_CONNCT_STATUS_BIT	BIT(1)
#define PCIE_TBU_TOK_TRANS_MSK		(0xFF << 8)
#define PCIE_TBU_TOK_TRANS			0x8
#define PCIE_TBU_DEFALUT_TOK_TRANS	0xF

void chs_pcie_init_smmu_map(struct hi_pcie_chs *plat)
{
	u32 i;
	u32 reg_val;
	u32 cdx = plat->pcie->ctrl_id;

	reg_val = chs_pcie_sysctrl_readl(plat, chs_pcie_smmu[cdx].mode_reg);
	reg_val |= BIT(0);
	chs_pcie_sysctrl_writel(plat, reg_val, chs_pcie_smmu[cdx].mode_reg);

	reg_val = chs_pcie_sysctrl_readl(plat, chs_pcie_smmu[cdx].aw_reg);
	reg_val |= chs_pcie_smmu[cdx].sid << 8;
	reg_val |= 1 << 28;
	chs_pcie_sysctrl_writel(plat, reg_val, chs_pcie_smmu[cdx].aw_reg);

	reg_val = chs_pcie_sysctrl_readl(plat, chs_pcie_smmu[cdx].ar_reg);
	reg_val |= chs_pcie_smmu[cdx].sid << 8;
	reg_val |= 1 << 28;
	chs_pcie_sysctrl_writel(plat, reg_val, chs_pcie_smmu[cdx].ar_reg);
}

int chs_pcie_tbu_config(struct hi_pcie_chs *plat, u32 enable)
{
	u32 reg_val;
	u32 tok_trans_gnt;
	u32 time = TBU_CONFIG_TIMEOUT;

	chs_pcie_init_smmu_map(plat);

	reg_val = readl(plat->tbu_base + PCIE_TBU_CR); // enable req
	if (enable)
		reg_val |= PCIE_TBU_EN_REQ_BIT;
	else
		reg_val &= ~PCIE_TBU_EN_REQ_BIT;
	writel(reg_val, plat->tbu_base + PCIE_TBU_CR);

	reg_val = readl(plat->tbu_base + PCIE_TBU_CRACK);
	while ((reg_val & PCIE_TBU_EN_ACK_BIT) == 0) {
		udelay(1);
		if (time == 0) {
			hi_pcie_pr_e("TBU req(en/dis) not been acknowledged");
			return -1;
		}
		time--;
		reg_val = readl(plat->tbu_base + PCIE_TBU_CRACK);
	}

	reg_val = readl(plat->tbu_base + PCIE_TBU_CRACK);
	if (enable) {
		if ((reg_val & PCIE_TBU_CONNCT_STATUS_BIT) == 0) {
			hi_pcie_pr_e("TBU connecting failed");
			return -1;
		}
	} else {
		if ((reg_val & PCIE_TBU_CONNCT_STATUS_BIT) != 0) {
			hi_pcie_pr_e("TBU is disconnect from TCU fail");
			return -1;
		}
	}

	if (enable) {
		reg_val = readl(plat->tbu_base + PCIE_TBU_CRACK);
		tok_trans_gnt = (reg_val & PCIE_TBU_TOK_TRANS_MSK) >> PCIE_TBU_TOK_TRANS;
		if (tok_trans_gnt < PCIE_TBU_DEFALUT_TOK_TRANS) {
			hi_pcie_pr_e("tok_trans_gnt[%d] is less than setting", tok_trans_gnt);
			return -1;
		}
	}

#ifdef CONFIG_HIPCIE_TEST
	u32 type = (u32)((enable == ENABLE) ? HIPCIE_FAULT_INIT_TYPE_TBU : HIPCIE_FAULT_EXIT_TYPE_TBU);
	if (stub_hi_pcie_fault_injection(type))
		return -1;
#endif

	return 0;
}

static u32 chs_pcie_get_smmuid(struct hi_pcie *pcie)
{
	return chs_pcie_smmu[pcie->ctrl_id].smmu_id;
}
static atomic_t *chs_pcie_get_tcu_pwrcnt(struct hi_pcie *pcie)
{
	return chs_pcie_smmu[pcie->ctrl_id].tcu_pwr_cnt;
}
 
static spinlock_t *chs_pcie_get_tcu_lock(struct hi_pcie *pcie)
{
	return chs_pcie_smmu[pcie->ctrl_id].tcu_lock;
}

static int chs_pcie_smmu_tcu_cfg(struct hi_pcie_chs *plat, bool enable)
{
	int ret = 0;
	unsigned long flag;
	atomic_t *tcu_pwr_cnt = chs_pcie_get_tcu_pwrcnt(plat->pcie);
	spinlock_t *tcu_lock = chs_pcie_get_tcu_lock(plat->pcie);
	u32 smmu_id = chs_pcie_get_smmuid(plat->pcie);

#ifdef CONFIG_HIPCIE_TEST
	u32 type = ((enable == true) ? HIPCIE_FAULT_INIT_TYPE_TCU : HIPCIE_FAULT_EXIT_TYPE_TCU);
	if (stub_hi_pcie_fault_injection(type))
		return -1;
#endif

	spin_lock_irqsave(tcu_lock, flag);

	if(enable) {
		chs_pcie_common_unrst_cfg(plat);
		chs_pcie_common_clk_cfg(plat);

		ret = mm_smmu_nonsec_tcuctl(smmu_id);
		if (ret) {
			hi_pcie_pr_e("TCU nonsec cfg Failed");
			goto CFG_END;
		}

		if (atomic_read(tcu_pwr_cnt) == 0) {
			ret = mm_smmu_poweron(plat->pcie->dev);
			if (ret) {
				hi_pcie_pr_e("TCU power on Failed");
				goto CFG_END;
			}
		}
		atomic_or((1 << plat->pcie->ctrl_id), tcu_pwr_cnt);
	} else {
		atomic_andnot(1 << plat->pcie->ctrl_id, tcu_pwr_cnt);
		if (atomic_read(tcu_pwr_cnt) == 0) {
			ret = mm_smmu_poweroff(plat->pcie->dev);
			if (ret) {
				hi_pcie_pr_e("TCU power off failed");
				goto CFG_END;
			}
		}

		chs_pcie_common_clk_uncfg(plat);
		chs_pcie_common_rst_cfg(plat);
	}

CFG_END:
	spin_unlock_irqrestore(tcu_lock, flag);
	hi_pcie_pr_i("tcu_pwr_cnt=%d, enable=%d", atomic_read(tcu_pwr_cnt), enable);
	return ret;
}

static int chs_pcie_enable_smmu(struct hi_pcie_chs *plat)
{
	int ret;

	ret = chs_pcie_smmu_tcu_cfg(plat, true);
	if(ret)
		return ret;

	ret = chs_pcie_tbu_config(plat, ENABLE);
	if (ret) {
		hi_pcie_pr_e("TBU config Failed");
		return -1;
	}

	hi_pcie_pr_d("TBU init Done");
	return 0;
}

int chs_pcie_disable_smmu(struct hi_pcie_chs *plat)
{
	atomic_t *tcu_pwr_cnt;
	if (chs_pcie_is_smmu_bypass(plat)) {
		hi_pcie_pr_e("smmu bypassed");
		return 0;
	}

	tcu_pwr_cnt = chs_pcie_get_tcu_pwrcnt(plat->pcie);
	if ((atomic_read(tcu_pwr_cnt) && BIT(plat->pcie->ctrl_id)) == 0)
		return 0;

	(void)chs_pcie_tbu_config(plat, DISABLE);

	return chs_pcie_smmu_tcu_cfg(plat, false);
}

int chs_pcie_smmu_init(struct hi_pcie_chs *plat)
{
	if (chs_pcie_is_smmu_bypass(plat)) {
		if (chs_pcie_tbu_bypass(plat)) {
			hi_pcie_pr_e("Bypass TBU failed");
			return -1;
		}

		return 0;
	}

	return chs_pcie_enable_smmu(plat);
}

void chs_pcie_open_rst_int(struct hi_pcie_chs *plat, int behavior)
{
	u32 val;
	u32 val_mask;
	u32 reg;
	int step;
	int size;

	if (plat->pcie->mode == PCIE_MODE_RC)
		return;

	size = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].size;
	for (step = 0; step < size; step++) {
		reg = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].base_addr[step];
		val_mask = pcie_init_step[plat->pcie->ctrl_id].behavior[behavior].val[step];

		val = chs_pcie_sysctrl_readl(plat, reg);
		val = val | val_mask;
		chs_pcie_sysctrl_writel(plat, val, reg);
	}
}

static void chs_pcie_axi_timeout_set(struct hi_pcie_chs *plat)
{
	u32 val;

	val = chs_pcie_sysctrl_readl(plat, HIPCIE_MISC_CFG9_V3);
	val &= ~(0x3F << 16);
	val |= (0x2F << 16);
	chs_pcie_sysctrl_writel(plat, val, HIPCIE_MISC_CFG9_V3);
}

void chs_pcie_perst_fail(struct hi_pcie_chs *plat)
{
	hi_pcie_pr_e("+%s+", __func__);
	chs_pcie_sc_clk_ctrl(plat, false);
	chs_pcie_reset_phy(plat);
	chs_pcie_sc_rst_cfg(plat, true);

	chs_pcie_oe_ie_rst(plat, OE_IE_RST);

	chs_pcie_hardware_clk_cfg(plat, false);

	chs_pcie_phy_clk_uncfg(plat);

	chs_pcie_sysclk_ctrl(plat, false);
	chs_pcie_rst_cfg(plat, PCIE_RST);
}

static void chs_pcie_pll_state_dump(struct hi_pcie_chs *plat)
{
	int i;
	u32 val;
	static struct {
		u32 reg;
		const char *desc;
	} pcie_pll_info[] = {
		{ FNPLL_PCIE_ADPLL_FTDC_LOCK_THR, "FNPLL_PCIE_ADPLL_FTDC_LOCK_THR" },
		{ PCIE_PLL_ATUNE_CODE_BIN, "PCIE_PLL_ATUNE_CODE_BIN" },
		{ PCIE_PLL_FCW_RO, "PCIE_PLL_FCW_RO" },
		{ PCIE_PLL_DTC_MAX, "PCIE_PLL_DTC_MAX" },
		{ PCIE_PLL_FDTC_STAT, "PCIE_PLL_FDTC_STAT" },
		{ PCIE_PLL_ADPLL_DTC_CONV_COEF, "PCIE_PLL_ADPLL_DTC_CONV_COEF" },
		{ PCIE_PLL_A2D_ADPLL_FTDC, "PCIE_PLL_A2D_ADPLL_FTDC" },
		{ PCIE_PLL_FTDC_MAX_MIN, "PCIE_PLL_FTDC_MAX_MIN" },
		{ PCIE_PLL_ADPLL_LPF_OUT, "PCIE_PLL_ADPLL_LPF_OUT" },
		{ PCIE_PLL_RECORD_TIME, "PCIE_PLL_RECORD_TIME" },
		{ PCIE_PLL_DCO_WORD_AFTER_CL, "PCIE_PLL_DCO_WORD_AFTER_CL" },
	};

	hi_pcie_pr_i("PCIePll info");

	for (i = 0; i < ARRAY_SIZE(pcie_pll_info); i++) {
		val = chs_pcie_ao_crg_reg_readl(plat, pcie_pll_info[i].reg);
		hi_pcie_pr_i("PCIePll %s reg [0x%x] is [0x%x]", pcie_pll_info[i].desc, pcie_pll_info[i].reg, val);
	}
}

static int chs_pcie_dump_hsdtcrg_info(struct hi_pcie *pcie);

void chs_pcie_fnpll_cfg_fail(struct hi_pcie_chs *plat)
{
	hi_pcie_pr_e("+%s+", __func__);

	chs_pcie_pll_state_dump(plat);
	chs_pcie_dump_hsdtcrg_info(plat->pcie);

	chs_pcie_sc_clk_ctrl(plat, false);
	chs_pcie_sc_rst_cfg(plat, true);
	chs_pcie_hardware_clk_cfg(plat, false);
	chs_pcie_phy_clk_uncfg(plat);

	chs_pcie_sysclk_ctrl(plat, false);
	chs_pcie_rst_cfg(plat, PCIE_RST);
}

int chs_pcie_turn_on(struct hi_pcie *pcie)
{
	int ret;
	struct hi_pcie_chs *plat = (struct hi_pcie_chs *)pcie->plat;
	unsigned long flags = 0;

	hi_pcie_pr_d("+%s+", __func__);

	if (atomic_read(&(pcie->is_power_on))) {
		hi_pcie_pr_e("PCIe%u already power on", pcie->ctrl_id);
		return 0;
	}

	chs_pcie_vote_doze(pcie, false);

	chs_pcie_clk_check(plat);

	chs_pcie_clk_config(plat);

	chs_pcie_qic_power_domain_exit(plat, false); // 2.3.1

	chs_pcie_rst_cfg(plat, PCIE_RST); // 2.3.2
	chs_pcie_rst_cfg(plat, PCIE_UNRST); // 2.3.3
	chs_pcie_sysclk_ctrl(plat, true); // 2.3.4
	chs_pcie_hardware_clk_cfg(plat, true);

	chs_pcie_sc_rst_cfg(plat, false); // 2.3.6
	chs_pcie_sc_clk_ctrl(plat, true); // 2.3.7

	ret = chs_pcie_fnpll_cfg(plat, false); // 2.3.8
	if(ret) {
		chs_pcie_fnpll_cfg_fail(plat);
		return -1;
	}

	if (plat->pcie->mode == PCIE_MODE_RC)
		chs_pcie_oe_ie_cfg(plat, OE_IE_CFG_RC);
	else
		chs_pcie_oe_ie_cfg(plat, OE_IE_CFG_EP);

	chs_pcie_clkreq_idle_timeout_cfg(plat); // 
	chs_pcie_clkreq_debounce_cfg(plat); // 2.5

	chs_pcie_iso_ctrl_cfg(plat, DISABLE); // 2.6

	chs_pcie_phy_init(plat); // 2.7 FPGA or X1

	ret = chs_pcie_perst_config(plat, ENABLE);
	if(ret) {
		chs_pcie_perst_fail(plat);
		return -1;
	}

	chs_pcie_ctrl_por_n_rst(plat, false); // 2.10

	chs_pcie_mem_sd_exit(plat, ENABLE);

	chs_pcie_axi_timeout_set(plat);

	flags = hi_pcie_idle_spin_lock(pcie->idle, flags);
	atomic_add(1, &(pcie->is_power_on));
	hi_pcie_idle_spin_unlock(pcie->idle, flags);

	pcie_ctrl_enable_irq(pcie->ctrl);
	enable_irq((u32)plat->level2_irq);
	hi_pcie_idle_mask_int(pcie->idle);

	hi_pcie_pr_d("-%s-", __func__);
	return 0;
}

int chs_pcie_turn_off(struct hi_pcie *pcie)
{
	int ret;
	struct hi_pcie_chs *plat = (struct hi_pcie_chs *)pcie->plat;
	unsigned long flags = 0;

	hi_pcie_pr_d("+%s+", __func__);

	if (atomic_read(&(pcie->is_power_on)) == 0) {
		hi_pcie_pr_e("PCIe%u already power down", pcie->ctrl_id);
		return 0;
	}

	hi_pcie_idle_mask_int(pcie->idle);
	hi_pcie_idle_clear_irq(pcie->idle);
	udelay(5);

	pcie_ctrl_disable_irq(pcie->ctrl);
	disable_irq((u32)plat->level2_irq);
	hi_pcie_idle_disable_irq(pcie->idle);

	pcie_core_flush_work(pcie);

	flags = hi_pcie_idle_spin_lock(pcie->idle, flags);
	atomic_sub(1, &(pcie->is_power_on));
	hi_pcie_idle_spin_unlock(pcie->idle, flags);

	hi_pcie_32k_idle_exit(pcie->idle);  // 1.1

	chs_pcie_qic_power_domain_exit(plat, false); // 1.2

	ret = pcie_ctrl_reset(pcie->ctrl); // 1.3
	if (ret)
		return ret;

	chs_pcie_disable_smmu(plat); // 1.4

	chs_pcie_ctrl_por_n_rst(plat, true); // 1.5

	chs_pcie_sc_clk_ctrl(plat, false); // 1.6

	chs_pcie_reset_phy(plat); // 1.8

	chs_pcie_sc_rst_cfg(plat, true); // 1.3.1

	chs_pcie_perst_config(plat, DISABLE);

	chs_pcie_oe_ie_rst(plat, OE_IE_RST); // 1.10.1

	chs_pcie_hardware_clk_cfg(plat, false);

	chs_pcie_phy_clk_uncfg(plat);

	chs_pcie_mem_sd_exit(plat, DISABLE);

	chs_pcie_sysclk_ctrl(plat, false);

	chs_pcie_rst_cfg(plat, PCIE_RST);

	chs_pcie_vote_doze(pcie, true);

	hi_pcie_pr_d("-%s-", __func__);
	return 0;
}

int chs_pcie_parse_base_config(struct platform_device *pdev, struct hi_pcie_chs *plat)
{
	int ret;
	ret = device_property_read_u32(&pdev->dev, "clkreq_gpio", &plat->clkreq_gpio);
	if (ret != 0) {
		hi_pcie_pr_e("clkreq_gpio not find");
		plat->clkreq_gpio = 0;
	}
	hi_pcie_pr_i("clkreq_gpio = %u", plat->clkreq_gpio);

	ret = device_property_read_u32(&pdev->dev, "ftdc_lock_thr", &plat->ftdc_lock_thr);
	if (ret != 0)
		plat->ftdc_lock_thr = FNPLL_FTDC_LOCK_THR_DEFAULT;

	hi_pcie_pr_i("ftdc_lock_thr = 0x%08x", plat->clkreq_gpio);

	return 0;
}

int chs_pcie_parse_pcie_base(struct platform_device *pdev, struct hi_pcie_chs *plat)
{
	struct resource *phy_pcs;
	struct resource *sysctrl;
	struct resource *tbu;

	phy_pcs = platform_get_resource_byname(pdev, IORESOURCE_MEM, "phy");
	plat->phy_pcs_base = devm_ioremap_resource(&pdev->dev, phy_pcs);
	if (IS_ERR(plat->phy_pcs_base)) {
		hi_pcie_pr_e("Failed to get PCIe pcs base");
		return -1;
	}

	plat->pcie->phy.phy_base = plat->phy_pcs_base;
	plat->pcie->phy.lane_num = PCIE_LANE_X1;
	plat->pcie->phy.link_num = plat->pcie->port_num;

	sysctrl = platform_get_resource_byname(pdev, IORESOURCE_MEM, "apb");
	plat->sysctrl_base = devm_ioremap_resource(&pdev->dev, sysctrl);
	if (IS_ERR(plat->sysctrl_base)) {
		hi_pcie_pr_e("Failed to get PCIe sysctrl base");
		return -1;
	}

	tbu = platform_get_resource_byname(pdev, IORESOURCE_MEM, "tbu");
	plat->tbu_base = devm_ioremap_resource(&pdev->dev, tbu);
	if (IS_ERR(plat->tbu_base)) {
		hi_pcie_pr_e("Failed to get PCIe tbu base");
		return -1;
	}

	return 0;
}

int chs_pcie_parse_plat_base(struct platform_device *pdev, struct hi_pcie_chs *plat)
{
	struct device_node *np;
	int i;
	static struct {
		void __iomem **base;
		const char *compatible;
		u32 index;
	} plat_base_list[] = {
		{ &plat_config.aocrg_base, "hisilicon,ao_crg", 0 },
		{ &plat_config.hsdtcrg_base, "hisilicon,hsdt_crg", 0 },
		{ &plat_config.hsdtsctrl_base, "hisilicon,hsdt_sysctrl", 0 },
		{ &plat_config.hsdtxctrl_base, "hisilicon,hsdt_ctrl", 0 },
		{ &plat_config.pcie_fnpll_base, "hi_pcie,plat_base", 0 },
	};

	if (atomic_add_return(1, &plat_config_cnt) != 1)
		return 0;

	for (i = 0; i < ARRAY_SIZE(plat_base_list); i++) {
		np = of_find_compatible_node(NULL, NULL, plat_base_list[i].compatible);
		if (!np) {
			hi_pcie_pr_e("Failed to get %s node", plat_base_list[i].compatible);
			goto unmap_base;
		}
		*plat_base_list[i].base = of_iomap(np, plat_base_list[i].index);
		if (*plat_base_list[i].base == NULL) {
			hi_pcie_pr_e("Failed to iomap %s-%u", plat_base_list[i].compatible,
				plat_base_list[i].index);
			goto unmap_base;
		}
	}

	return 0;

unmap_base:
	for (i = 0; i < ARRAY_SIZE(plat_base_list); i++) {
		if (*plat_base_list[i].base != NULL) {
			iounmap(*plat_base_list[i].base);
			*plat_base_list[i].base = NULL;
		}
	}
	return -1;
}

static struct {
	u32 ctrl_id;
	const char *phy_compatibal;
} chs_phy_compatible[] = {
	{
		RC_ID0, "pcie0,kphy",
	},
	{
		RC_ID1, "pcie1,kphy",
	},
};

int chs_pcie_parse_phy_param(struct platform_device *pdev, struct hi_pcie_chs *plat)
{
	int ret;
	const char *phy_compatibal_name;
	struct device_node *node;
	u32 size = 0;
	u32 *reg = NULL;
	u32 *val = NULL;

	phy_compatibal_name = chs_phy_compatible[plat->pcie->ctrl_id].phy_compatibal;
	hi_pcie_pr_e("get node phy_node_name %s", phy_compatibal_name);

	node = of_find_compatible_node(plat->pcie->dev->of_node, NULL, phy_compatibal_name);
	if (node == NULL) {
		hi_pcie_pr_e("get plat(%s) node failed", phy_compatibal_name);
		return -EINVAL;
	}

	ret = of_property_read_u32(node, "change-param-size", &size);
	if ((ret != 0) || size == 0) {
		hi_pcie_pr_e("need not change phy param, ret = %d, size = %u", ret, size);
		return 0;
	}
	hi_pcie_pr_e("get phy param size = %u", size);

	plat->pcie->phy.phy_change.change_param_size = size;
	reg = (u32 *)devm_kzalloc(&pdev->dev, sizeof(u32) * size, GFP_KERNEL);
	if (!reg) {
		hi_pcie_pr_e("reg malloc failed");
		return -ENOMEM;
	}
	val = (u32 *)devm_kzalloc(&pdev->dev, sizeof(u32) * size, GFP_KERNEL);
	if (!val) {
		hi_pcie_pr_e("val malloc failed");
		goto free_reg;
	}

	ret = of_property_read_u32_array(node, "change-param", val, size);
	if (ret) {
		hi_pcie_pr_e("get change phy param failed, ret = %d", ret);
		goto free_val;
	}

	ret = of_property_read_u32_array(node, "change-param-reg", reg, size);
	if (ret) {
		hi_pcie_pr_e("get change phy param reg failed, ret = %d", ret);
		goto free_val;
	}

	plat->pcie->phy.phy_change.change_param = val;
	plat->pcie->phy.phy_change.change_param_addr = reg;

	return 0;

free_val:
	devm_kfree(&pdev->dev, val);

free_reg:
	devm_kfree(&pdev->dev, reg);
	return ret;
}

int chs_pcie_parse_plat_config(struct platform_device *pdev, struct hi_pcie_chs *plat)
{
	int ret;

	ret = chs_pcie_parse_base_config(pdev, plat);
	if (ret != 0)
		return ret;

	ret = chs_pcie_parse_pcie_base(pdev, plat);
	if (ret != 0)
		return ret;

	ret = chs_pcie_parse_plat_base(pdev, plat);
	if (ret != 0)
		return ret;

	ret = chs_pcie_parse_phy_param(pdev, plat);
	if (ret != 0)
		return ret;

	return 0;
}

#define AXI_TIMEOUT_MASK	BIT(11)
#define AXI_TIMEOUT_CLR		BIT(9)
#define AXI_TIMEOUT_STATUS	BIT(19)

#define SC_PCIE_CTRL_STAT21			0x298
#define SC_PCIE_CTRL_STAT22			0x29C
#define SC_PCIE_CTRL_STAT23			0x2A0
#define SC_PCIE_CTRL_STAT24			0x2A4
#define SC_PCIE_CTRL_STAT25			0x2A8
#define AXI_TIMEOUT_MID_MASK	    0xFF

static void chs_pcie_print_soc_addr_and_mid(struct hi_pcie_chs *plat)
{
	u32 val;
	val = chs_pcie_sysctrl_readl(plat, SC_PCIE_CTRL_STAT21);
	hi_pcie_pr_e("axi timeout armid: %d, awmid: %d", ((val >> 8) & AXI_TIMEOUT_MID_MASK), (val & AXI_TIMEOUT_MID_MASK));

	val = chs_pcie_sysctrl_readl(plat, SC_PCIE_CTRL_STAT22);
	hi_pcie_pr_e("axi timeout araddr_h: 0x%x", val);
	val = chs_pcie_sysctrl_readl(plat, SC_PCIE_CTRL_STAT23);
	hi_pcie_pr_e("axi timeout araddr_l: 0x%x", val);
	val = chs_pcie_sysctrl_readl(plat, SC_PCIE_CTRL_STAT24);
	hi_pcie_pr_e("axi timeout awaddr_h: 0x%x", val);
	val = chs_pcie_sysctrl_readl(plat, SC_PCIE_CTRL_STAT25);
	hi_pcie_pr_e("axi timeout awaddr_l: 0x%x", val);
}

irqreturn_t chs_pcie_level2_handler(int irq, void *arg)
{
	u32 val;
	struct hi_pcie_chs *plat = arg;
	struct hi_pcie_port *port = NULL;
	struct hi_pcie *pcie = plat->pcie;

	hi_pcie_pr_i("pcie plat level2 handler enter");

	val = chs_pcie_sysctrl_readl(plat, HIPCIE_MISC_STATE0);
	if ((val & AXI_TIMEOUT_STATUS) == AXI_TIMEOUT_STATUS) {
		hi_pcie_pr_e("pcie axi timeout happended");
		chs_pcie_print_soc_addr_and_mid(plat);
		list_for_each_entry(port, &pcie->ports, node)
			schedule_work(&port->events_work[HI_PCIE_EVENT_AXI_TIMEOUT]);
	}

	val = chs_pcie_sysctrl_readl(plat, HIPCIE_PHY_CFG0);
	val |= AXI_TIMEOUT_MASK | AXI_TIMEOUT_CLR | (AXI_TIMEOUT_MASK << 16) | (AXI_TIMEOUT_CLR << 16);
	chs_pcie_sysctrl_writel(plat, val, HIPCIE_PHY_CFG0);

	hi_pcie_handle_int(plat->ctrl);

	val = chs_pcie_sysctrl_readl(plat, HIPCIE_PHY_CFG0);
	val &= ~AXI_TIMEOUT_MASK;
	val |= (AXI_TIMEOUT_MASK << 16);
	chs_pcie_sysctrl_writel(plat, val, HIPCIE_PHY_CFG0);

	return IRQ_HANDLED;
}

int chs_pcie_register_int(struct platform_device *pdev, struct hi_pcie_chs *plat)
{
	int irq;
	int ret;

	irq = platform_get_irq(pdev, INT_INDEX_LEVEL2);
	if (irq <= 0) {
		hi_pcie_pr_e("get level2 irq-%dfailed", irq);
		return -1;
	}
	ret = devm_request_irq(&pdev->dev, irq, chs_pcie_level2_handler,
			(unsigned long)IRQF_TRIGGER_HIGH, "pcie_level2", plat);
	if (ret != 0) {
		hi_pcie_pr_e("request level2 irq-%dfailed", irq);
		return ret;
	}
	plat->level2_irq = irq;
	disable_irq((u32)irq);

	return 0;
}

int chs_pcie_phy_register(struct hi_pcie_chs *plat)
{
	pcie_kphy_dfx_register(plat->pcie);
	return 0;
}

int chs_pcie_pwron_callback(void *data)
{
	struct hi_pcie_port *port = data;
	return gpio_direction_output(port->reset_gpio, ENABLE);
}

int chs_pcie_pwroff_callback(void *data)
{
	struct hi_pcie_port *port = data;
	return gpio_direction_output(port->reset_gpio, DISABLE);
}

void chs_pcie_pwr_callback_register(struct hi_pcie *pcie)
{
	struct hi_pcie_port *port = NULL;
	list_for_each_entry(port, &pcie->ports, node) {
		if (port->disable)
			continue;
		if (port->ep_device_type != PCIE_DEVICE_HI110X) {
			port->poweron_callback = chs_pcie_pwron_callback;
			port->poweroff_callback = chs_pcie_pwroff_callback;
			port->power_callback_data = port;
		}
	}
}

int chs_pcie_init(struct platform_device *pdev, struct hi_pcie *pcie)
{
	int ret;
	struct hi_pcie_chs *plat;

	hi_pcie_pr_d("+%s+", __func__);

	if ((pcie->ctrl_id > RC_ID1) || (pcie->port_num > 1))
		return -EINVAL;

	plat = devm_kzalloc(&pdev->dev, sizeof(struct hi_pcie_chs), GFP_KERNEL);
	if (plat == NULL)
		return -ENOMEM;

	pcie->plat = (void *)plat;
	plat->pcie = pcie;
	plat->ctrl = pcie->ctrl;

	ret = chs_pcie_parse_plat_config(pdev, plat);
	if (ret != 0) {
		devm_kfree(&pdev->dev, plat);
		return ret;
	}

	if (plat->pcie->mode == PCIE_MODE_RC) {
		ret = chs_pcie_register_int(pdev, plat);
		if (ret != 0) {
			devm_kfree(&pdev->dev, plat);
			return ret;
		}
	}

	chs_pcie_phy_register(plat);

	chs_pcie_pwr_callback_register(plat->pcie);

	hi_pcie_pr_d("-%s-", __func__);
	return ret;
}

static int chs_pcie_phy_chk_recfg_ffe(struct hi_pcie_port *port)
{
	int ret;
	struct hi_pcie_phy *phy = &port->pcie->phy;

	if (port->pcie->chip_type == BOARD_FPGA)
		return 0;

	ret = pcie_kphy_check_status(phy);
	if (ret) {
		hi_pcie_pr_e("phy check fail");
		pcie_kphy_dump_status(phy);
		return -1;
	}

	hi_pcie_pr_d("phy check succ");
	pcie_kphy_cfg_ffe_chs(phy);

	return 0;
}

int chs_pcie_start_link(struct hi_pcie *pcie)
{
	int ret;
	struct hi_pcie_chs *plat = (struct hi_pcie_chs *)pcie->plat;
	struct hi_pcie_port *port = NULL;

	hi_pcie_pr_d("+%s+", __func__);

	list_for_each_entry(port, &pcie->ports, node) {
		if (port->disable)
			continue;
		chs_pcie_phy_chk_recfg_ffe(port);
	}

	if (!chs_pcie_is_pipe_clk_stable(plat, PIPE_CLK_STABLE)) { // 2.13.1
		hi_pcie_pr_e("PIPE clk is not stable");
		return -1;
	}
	hi_pcie_pr_d("PIPE clk is stable");

	chs_pcie_rx_term_cfg(plat, PU_RX_TERMIANTION); // 2.13.4

	chs_pcie_qic_power_domain_exit(plat, true); // 2.14

	chs_pcie_firewall_fix(plat); // 2.16

	ret = chs_pcie_smmu_init(plat);
	if (ret)
		return ret;

	chs_pcie_open_rst_int(plat, OPEN_RST_ITNR);

	hi_pcie_idle_clear_irq(pcie->idle);
	hi_pcie_32k_idle_init(pcie->idle);
	hi_pcie_idle_enable_irq(pcie->idle);

	return 0;
}

#ifdef CONFIG_HIPCIE_IDLE
static int chs_pcie_idle_init(struct hi_pcie *pcie)
{
	struct hi_pcie_chs *plat = (struct hi_pcie_chs *)pcie->plat;
	pcie->idle->idle_reg_base = plat->sysctrl_base;
	return 0;
}

static void chs_pcie_idle_reg_cfg(struct hi_pcie *pcie, int index, u32 step)
{
	u32 base_step;
	u32 reg;
	u32 val;

	for (base_step = 0; base_step < pcie_idle_step[index].behavior[step].size; base_step++) {
		reg = pcie_idle_step[index].behavior[step].base_addr[base_step];
		val = pcie_idle_step[index].behavior[step].val[base_step];
		chs_pcie_hsdt_crg_reg_writel(pcie->plat, val, reg);
	}
	return;
}

int chs_pcie_enter_idle(struct hi_pcie *pcie, u32 port_id)
{
	int i;
	u32 ltssm_state;
	u32 clkreq_state;
	struct hi_pcie_chs *plat = (struct hi_pcie_chs *)pcie->plat;
	if (atomic_read(&(pcie->is_power_on)) == 0)
		goto end;

	for (i = 0; i < ARRAY_SIZE(pcie_idle_step); i++) {
		if (pcie_idle_step[i].ctrl_id == pcie->ctrl_id &&
			pcie_idle_step[i].port_id == port_id) {
			break;
		}
	}

	if (i == ARRAY_SIZE(pcie_idle_step)) {
		hi_pcie_pr_e("[%s], port %u/%u enter idle fail", __func__, pcie->ctrl_id, port_id);
		return -1;
	}

	ltssm_state = chs_pcie_sysctrl_readl(plat, HIPCIE_SC_PCIE_CTRL_STAT19) & 0x3F;
	clkreq_state = chs_pcie_sysctrl_readl(plat, HIPCIE_SC_PCIE_CTRL_STAT20);

	hi_pcie_pr_e("[%s]ltssm_state=0x%x, clkreq_state=0x%x", __func__, ltssm_state, clkreq_state);
	if ((ltssm_state != HIPCIE_LTSSM_L1_STATE) || ((clkreq_state & BIT(5)) == 0x0))
		goto end;

	chs_pcie_phy_clk_uncfg(pcie->plat);

	chs_pcie_idle_reg_cfg(pcie, i, CLOSE_RFF_CLK);

	chs_pcie_vote_doze(pcie, true);

end:
	return 0;
}

int chs_pcie_exit_idle(struct hi_pcie *pcie, u32 port_id)
{
	int ret;
	int i;
	if (atomic_read(&(pcie->is_power_on)) == 0)
		goto end;

	for (i = 0; i < ARRAY_SIZE(pcie_idle_step); i++) {
		if (pcie_idle_step[i].ctrl_id == pcie->ctrl_id &&
			pcie_idle_step[i].port_id == port_id) {
			break;
		}
	}

	if (i == ARRAY_SIZE(pcie_idle_step)) {
		hi_pcie_pr_e("[%s], port %u/%u match idle fail", __func__, pcie->ctrl_id, port_id);
		return -1;
	}

	chs_pcie_vote_doze(pcie, false);

	/* fnpll must be locked before io enable */
	ret = chs_pcie_fnpll_cfg(pcie->plat, true);
	if (ret) {
		hi_pcie_pr_e("[%s], port %u/%u exit idle fail, FNPLL lock failed!", __func__, pcie->ctrl_id, port_id);
		return -1;
	}

	chs_pcie_idle_reg_cfg(pcie, i, OPEN_RFF_CLK);

end:
	return 0;
}
#else
static int chs_pcie_idle_init(struct hi_pcie *pcie)
{
	(void)pcie;
	return 0;
}

int chs_pcie_enter_idle(struct hi_pcie *pcie, u32 port_id)
{
	(void)pcie;
	(void)port_id;
	return 0;
}

int chs_pcie_exit_idle(struct hi_pcie *pcie, u32 port_id)
{
	(void)pcie;
	(void)port_id;
	return 0;
}
#endif

int chs_pcie_get_ssid_by_dev(struct hi_pcie *pcie, struct pci_dev *pdev)
{
	(void)pcie;
	(void)pdev;
	return 0;
}

static int chs_pcie_dump_aocrg_info(struct hi_pcie *pcie)
{
	struct hi_pcie_chs *plat = (struct hi_pcie_chs *)pcie->plat;

	int i;
	u32 val;
	static struct {
		u32 reg;
		const char *desc;
	} aocrg_info[] = {
		{ AOCRGSCCLKDIV12, "SEL" },
		{ AOCRGSCCLKDIV16, "DIV" },
		{ AOCRGSCPEREN6, "PER CLKEN1" },
		{ AOCRGSCCLKDIV3, "PER STAT1" },
		{ AOCRGAO_AUTODIV2, "PER RST STAT0" },
		{ SCPERCLKEN1, "AUX CLK STATUS" },
		{ SCPERSTAT2, "AUX PCIE SYS GATE" },
		{ SCPERSTAT0, "AUX PCIE GATE" },
	};

	hi_pcie_pr_i("PCIe Aocrg info");

	for (i = 0; i < ARRAY_SIZE(aocrg_info); i++) {
		val = chs_pcie_ao_crg_reg_readl(plat, aocrg_info[i].reg);
		hi_pcie_pr_i("Aocrg %s reg [0x%x] is [0x%x]", aocrg_info[i].desc, aocrg_info[i].reg, val);
	}

	return 0;
}

static int chs_pcie_dump_hsdtcrg_info(struct hi_pcie *pcie)
{
	struct hi_pcie_chs *plat = (struct hi_pcie_chs *)pcie->plat;

	int i;
	u32 val;
	static struct {
		u32 reg;
		const char *desc;
	} hsdtcrg_info[] = {
		{ HSDT_PERCLKEN0, "PER CLKEN0" },
		{ HSDT_PERSTAT0, "PER STAT0" },
		{ HSDT_PERCLKEN1, "PER CLKEN1" },
		{ HSDT_PERSTAT1, "PER STAT1" },
		{ HSDT_PERRSTSTAT0, "PER RST STAT0" },
		{ HSDT_CRG_PCIEPLL_PCIE_CTRL0, "PCIEPLL PCIE CTRL0" },
		{ HSDT_CRG_PCIECTRL0, "PCIECTRL0" },
		{ HSDT_CRG_PCIECTRL1, "PCIECTRL1" },
		{ HSDT_CRG_PCIEPLL_STATE, "PCIEPLL STATE" },
		{ HSDT_CRG_PCIEPLL_PERI_STAT1, "PERI_STAT1" },
		{ HSDT_CRG_PCIEPLL_PERI_STAT2, "PERI_STAT2" },
	};

	hi_pcie_pr_i("PCIe Hsdtcrg info");

	for (i = 0; i < ARRAY_SIZE(hsdtcrg_info); i++) {
		val = chs_pcie_hsdt_crg_reg_readl(plat, hsdtcrg_info[i].reg);
		hi_pcie_pr_i("Hsdtcrg %s reg [0x%x] is [0x%x]", hsdtcrg_info[i].desc, hsdtcrg_info[i].reg, val);
	}

	return 0;
}

static int chs_pcie_dump_sysctrl_info(struct hi_pcie *pcie)
{
	struct hi_pcie_chs *plat = (struct hi_pcie_chs *)pcie->plat;
	
	int i;
	u32 val;
	static struct {
		u32 reg;
		const char *desc;
	} sysctrl_info[] = {
		{ HIPCIE_MISC_STATE0, "pcie misc state0" },
		{ HIPCIE_SC_PCIE_CTRL_STAT17, "sc pcie ctrl stat17" },
		{ HIPCIE_SC_PCIE_CTRL_STAT18, "sc pcie ctrl stat18" },
		{ HIPCIE_SC_PCIE_CTRL_STAT19, "sc pcie ctrl stat19" },
		{ HIPCIE_SC_PCIE_CTRL_STAT20, "sc pcie ctrl stat20" },
	};

	hi_pcie_pr_i("PCIe Sysctrl info");

	for (i = 0; i < ARRAY_SIZE(sysctrl_info); i++) {
		val = chs_pcie_sysctrl_readl(plat, sysctrl_info[i].reg);
		hi_pcie_pr_i("Sysctrl %s reg [0x%x] is [0x%x]", sysctrl_info[i].desc, sysctrl_info[i].reg, val);
	}

	return 0;
}

static int chs_pcie_dump_plat_info(struct hi_pcie *pcie)
{
	chs_pcie_dump_aocrg_info(pcie);
	chs_pcie_dump_hsdtcrg_info(pcie);
	chs_pcie_dump_sysctrl_info(pcie);

	return 0;
}

struct hi_pcie_platform_ops platform_ops = {
	.plat_init			= chs_pcie_init,
	.plat_on			= chs_pcie_turn_on,
	.plat_off			= chs_pcie_turn_off,
	.start_link			= chs_pcie_start_link,
#ifdef CONFIG_HIPCIE_IDLE
	.idle_init			= chs_pcie_idle_init,
	.enter_idle			= chs_pcie_enter_idle,
	.exit_idle			= chs_pcie_exit_idle,
#endif
	.init_phy			= NULL,
	.get_ssid_by_dev	= chs_pcie_get_ssid_by_dev,
	.open_sscg          = NULL,
	.dump_plat_info		= chs_pcie_dump_plat_info,
};

int hi_pcie_register_ops(struct platform_device *pdev, struct hi_pcie *pcie)
{
	pcie->plat_ops = &platform_ops;

	hi_pcie_ctrl_register(pcie);
	hi_pcie_dfx_register(pcie);
	return 0;
}