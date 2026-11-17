/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 *
 * Description:pcie pm
 * Author: platform drivers
 */

#ifdef _PRE_PLAT_FEATURE_GF6X_PCIE
#define MPXX_LOG_MODULE_NAME "[PCIE_H]"
#define HISI_LOG_TAG           "[PCIE]"
#include "pcie_host.h"
#include "oal_types.h"
#include "pcie_chip_gf61.h"
#include "gf61/pcie_ctrl_rb_regs.h"
#include "gf61/pcie_pcs_rb_regs.h"

#define GLB_CTL_RB_BASE                     (0x40000000)
#define GLB_CTL_RB_PCIE_AUX_CLK_SEL_REG     (0xB4)

#define GF61_PCIE_PHY_PLLTMR0_OFFSET            0x0A24
#define GF61_PCIE_PHY_PLLTMR1_OFFSET            0x0A28
#define GF61_PCIE_PHY_TXDRVTMR_OFFSET           0x0A40
#define GF61_PCIE_PHY_RXEQTMR_OFFSET            0x0A50
#define GF61_PCIE_PHY_BG_CTRL_REG_0_OFFSET      0x0AC8
#define GF61_PCIE_MAC_PCI_ERR_UNCOR_STATUS      0x104 /* PCI_ERR_UNCOR_STATUS_CAP_ID: */
#define GF61_PCIE_MAC_PCI_ERR_COR_STATUS        0x110 /* PCI_ERR_COR_STATUS_CAP_ID: */

#define PCIE_XFER_PENDING_VAL               (0x80)

OAL_STATIC uint32_t g_lp_cfg_value = 0x8;    /* 0x8: S_MAC PCIE_LOW_POWER_REG default value */

typedef struct _pcie_auxclk_timer_config {
    uint32_t offset;
    uint32_t pos;
    uint32_t bits;
    uint32_t val;
} pcie_auxclk_timer_config;

OAL_STATIC pcie_auxclk_timer_config g_pcie_auxclk_switch_rtc[] = {
    { GF61_PCIE_PHY_PLLTMR0_OFFSET, 16, 13, 0x1 },      /* pll_ldo_etmr     [pos:16] [bits:13] */
    { GF61_PCIE_PHY_PLLTMR0_OFFSET, 0, 13, 0x1 },       /* pll_bias_etmr    [pos: 0] [bits:13] */
    { GF61_PCIE_PHY_PLLTMR1_OFFSET, 26, 6, 0x1 },       /* pll_clk_etmr     [pos:26] [bits: 6] */
    { GF61_PCIE_PHY_PLLTMR1_OFFSET, 12, 13, 0x2 },      /* pll_etmr         [pos:12] [bits:13] */
    { GF61_PCIE_PHY_PLLTMR1_OFFSET, 0, 9, 0x1 },        /* pll_vco_etmr     [pos: 0] [bits: 9] */
    { GF61_PCIE_PHY_TXDRVTMR_OFFSET, 20, 5, 0x1 },      /* txvcm_etmr       [pos:20] [bits: 5] */
    { GF61_PCIE_PHY_TXDRVTMR_OFFSET, 0, 18, 0x3 },      /* txhold_etmr      [pos: 0] [bits:18] */
    { GF61_PCIE_PHY_RXEQTMR_OFFSET, 0, 14, 0x1 },       /* rx_eq_tmr        [pos: 0] [bits:14] */
    { GF61_PCIE_PHY_BG_CTRL_REG_0_OFFSET, 0, 9, 0x1 }   /* bg_bias_en_etmr  [pos: 0] [bits: 9] */
};

OAL_STATIC pcie_auxclk_timer_config g_pcie_auxclk_switch_tcxo[] = {
    { GF61_PCIE_PHY_PLLTMR0_OFFSET, 16, 13, 0xC4 },     /* pll_ldo_etmr     [pos:16] [bits:13] */
    { GF61_PCIE_PHY_PLLTMR0_OFFSET, 0, 13, 0xC4 },      /* pll_bias_etmr    [pos: 0] [bits:13] */
    { GF61_PCIE_PHY_PLLTMR1_OFFSET, 26, 6, 0x2 },       /* pll_clk_etmr     [pos:26] [bits: 6] */
    { GF61_PCIE_PHY_PLLTMR1_OFFSET, 12, 13, 0x3C0 },    /* pll_etmr         [pos:12] [bits:13] */
    { GF61_PCIE_PHY_PLLTMR1_OFFSET, 0, 9, 0x18 },       /* pll_vco_etmr     [pos: 0] [bits: 9] */
    { GF61_PCIE_PHY_TXDRVTMR_OFFSET, 20, 5, 0x2 },      /* txvcm_etmr       [pos:20] [bits: 5] */
    { GF61_PCIE_PHY_TXDRVTMR_OFFSET, 0, 18, 0x783 },    /* txhold_etmr      [pos: 0] [bits:18] */
    { GF61_PCIE_PHY_RXEQTMR_OFFSET, 0, 14, 0xC0 },      /* rx_eq_tmr        [pos: 0] [bits:14] */
    { GF61_PCIE_PHY_BG_CTRL_REG_0_OFFSET, 0, 9, 0x61 }  /* bg_bias_en_etmr  [pos: 0] [bits: 9] */
};

int32_t oal_pcie_device_phy_config_gf61(oal_pcie_linux_res *pcie_res)
{
    if (pcie_res == NULL) {
        pci_print_log(PCI_LOG_ERR, "ptr pcie_res is NULL");
        return OAL_FAIL;
    }

    g_lp_cfg_value = oal_readl(pcie_res->ep_res.pst_pci_ctrl_base + PCIE_CTRL_RB_LOW_POWER_CFG_OFF);

    if (oal_pcie_eye_param_change_gf61(pcie_res) != OAL_SUCC) {
        pci_print_log(PCI_LOG_ERR, "set pcie param error, not change pcie speed");
        return OAL_FAIL;
    }
    /* GEN1->GENx link speed change */
    (void)oal_pcie_link_speed_change_gf61(pcie_res);
    return OAL_SUCC;
}

OAL_STATIC int32_t oal_pcie_auxclk_switch_phy_timer_adapter(oal_pcie_linux_res *pcie_res, uint32_t clk_mode)
{
    int32_t ret;
    int32_t cnt;
    uint32_t reg;
    uint32_t base_addr = GF61_PCIE_PHY_BASE_ADDRESS;
    pci_addr_map addr_map;

    /* phy addr */
    ret = oal_pcie_inbound_ca_to_va(pcie_res, base_addr, &addr_map);
    if (ret != OAL_SUCC) {
        return -OAL_EFAIL;
    }
    if (clk_mode == AUXCLK_TCXO) {
        for (cnt = 0; cnt < oal_array_size(g_pcie_auxclk_switch_tcxo); cnt++) {
            reg = oal_readl(addr_map.va + g_pcie_auxclk_switch_tcxo[cnt].offset);
            oal_setl_bits((void*)(addr_map.va + g_pcie_auxclk_switch_tcxo[cnt].offset),
                          g_pcie_auxclk_switch_tcxo[cnt].pos, g_pcie_auxclk_switch_tcxo[cnt].bits,
                          g_pcie_auxclk_switch_tcxo[cnt].val);
            pci_print_log(PCI_LOG_INFO, "PCIe phy reg config: change from 0x%x to 0x%x",
                          reg, oal_readl(addr_map.va + g_pcie_auxclk_switch_tcxo[cnt].offset));
        }
    } else {
        for (cnt = 0; cnt < oal_array_size(g_pcie_auxclk_switch_rtc); cnt++) {
            reg = oal_readl(addr_map.va + g_pcie_auxclk_switch_rtc[cnt].offset);
            oal_setl_bits((void*)(addr_map.va + g_pcie_auxclk_switch_rtc[cnt].offset),
                          g_pcie_auxclk_switch_rtc[cnt].pos, g_pcie_auxclk_switch_rtc[cnt].bits,
                          g_pcie_auxclk_switch_rtc[cnt].val);
            pci_print_log(PCI_LOG_INFO, "PCIe phy reg config: change from 0x%x to 0x%x",
                          reg, oal_readl(addr_map.va + g_pcie_auxclk_switch_rtc[cnt].offset));
        }
    }
    return OAL_SUCC;
}

OAL_STATIC int32_t oal_pcie_auxclk_switch_gf61(oal_pcie_linux_res *pcie_res, aux_clk_mode clk_mode)
{
    int32_t ret;
    pci_addr_map addr_map;
    uint32_t cpu_address = GLB_CTL_RB_BASE;

    ret = oal_pcie_inbound_ca_to_va(pcie_res, cpu_address, &addr_map);
    if (ret != OAL_SUCC) {
        oal_io_print("oal_pcie_auxclk_switch[%d], 0x%8x unmap, read failed!\n", clk_mode, cpu_address);
        return -OAL_ENOMEM;
    }

    if (clk_mode == AUXCLK_TCXO) {
        // rtc->tcxo, 不回读，使用保存的值，配置拉高xfer_pending信号，使链路维持在L0状态
        oal_writel(PCIE_XFER_PENDING_VAL | g_lp_cfg_value,
                   pcie_res->ep_res.pst_pci_ctrl_base + PCIE_CTRL_RB_LOW_POWER_CFG_OFF);
        oal_pcie_auxclk_switch_phy_timer_adapter(pcie_res, AUXCLK_TCXO);
        oal_writel(0x0, (void *)addr_map.va + GLB_CTL_RB_PCIE_AUX_CLK_SEL_REG);
    } else {
        // tcxo->rtc,回读一下寄存器，再配置拉高xfer_pending信号，使链路维持在L0状态
        g_lp_cfg_value = oal_readl(pcie_res->ep_res.pst_pci_ctrl_base + PCIE_CTRL_RB_LOW_POWER_CFG_OFF);
        oal_writel(PCIE_XFER_PENDING_VAL | g_lp_cfg_value,
                   pcie_res->ep_res.pst_pci_ctrl_base + PCIE_CTRL_RB_LOW_POWER_CFG_OFF);
        oal_pcie_auxclk_switch_phy_timer_adapter(pcie_res, AUXCLK_RTC);
        oal_writel(0x3, (void *)addr_map.va + GLB_CTL_RB_PCIE_AUX_CLK_SEL_REG);
    }
    // 拉低xfer_pending信号
    oal_writel((g_lp_cfg_value & (~(PCIE_XFER_PENDING_VAL))),
               pcie_res->ep_res.pst_pci_ctrl_base + PCIE_CTRL_RB_LOW_POWER_CFG_OFF);
    return OAL_SUCC;
}

int32_t oal_pcie_device_aspm_init_gf61(oal_pcie_linux_res *pcie_res)
{
    uint32_t value;
    if (g_pcie_aspm_enable) {
        value = oal_readl(pcie_res->ep_res.pst_pci_ctrl_base + PCIE_CFG_OFF);
        value |= (1 << 1);
        value |= (1 << 3);  // 3, bit pos
        oal_writel(value, pcie_res->ep_res.pst_pci_ctrl_base + PCIE_CFG_OFF);

        oal_pcie_device_xfer_pending_sig_clr(pcie_res, OAL_TRUE);

        oal_print_mpxx_log(MPXX_LOG_INFO, "cfg reg:0x%x, low_power_cfg reg:0x%x",
                           oal_readl(pcie_res->ep_res.pst_pci_ctrl_base + PCIE_CFG_OFF),
                           oal_readl(pcie_res->ep_res.pst_pci_ctrl_base + PCIE_LOW_POWER_CFG_OFF));
    }
    return OAL_SUCC;
}

int32_t oal_pcie_device_auxclk_init_gf61(oal_pcie_linux_res *pcie_res)
{
    return OAL_SUCC;
}

void oal_pcie_device_aspm_ctrl_gf61(oal_pcie_linux_res *pcie_res, oal_bool_enum clear)
{
    return;
}

int32_t pcie_pm_chip_init_gf61(oal_pcie_linux_res *pcie_res, int32_t device_id)
{
    oal_pcie_ep_res *ep_res = &pcie_res->ep_res;

    ep_res->chip_info.cb.pm_cb.pcie_device_aspm_init = oal_pcie_device_aspm_init_gf61;
    ep_res->chip_info.cb.pm_cb.pcie_device_auxclk_init = oal_pcie_device_auxclk_init_gf61;
    ep_res->chip_info.cb.pm_cb.pcie_device_auxclk_switch = oal_pcie_auxclk_switch_gf61;
    ep_res->chip_info.cb.pm_cb.pcie_device_aspm_ctrl = oal_pcie_device_aspm_ctrl_gf61;
    ep_res->chip_info.cb.pm_cb.pcie_device_phy_config = oal_pcie_device_phy_config_gf61;
    return OAL_SUCC;
}
#endif
