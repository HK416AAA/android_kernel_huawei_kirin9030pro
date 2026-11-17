/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: pcie_chip adapter
 * Author: dpa drivers
 */

#define MPXX_LOG_MODULE_NAME "[PCIEC]"
#define HISI_LOG_TAG           "[PCIEC]"

#include "mp17c/host_ctrl_rb_regs.h"
#include "mp17c/pcie_ctrl_rb_regs.h"
#include "mp17c/pcie_pcs_rb_regs.h"
#include "chip/mp17c/pcie_soc_mp17c.h"
#include "pcie_chip.h"
#include "oam_logger.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_DPA_FILE_ID_PCIE_CHIP_MP17C_C

/* mp17c Registers */
#define PA_PCIE_CTRL_BASE_ADDR      PCIE_CTRL_RB_BASE /* 对应PCIE_CTRL页 */
#define PA_PCIE_DBI_BASE_ADDRESS    0x04900000
#define PA_ETE_CTRL_BASE_ADDRESS    HOST_CTRL_RB_BASE
#define PA_GLB_CTL_BASE_ADDR        0x04000000
#define PA_GLB_CTL_W_BASE_ADDR      0x04002000
#define PA_PMU_CMU_CTL_BASE         0x04008000
#define PA_PMU2_CMU_IR_BASE         0x0401A000
#define DEV_VERSION_CPU_ADDR        0x002001b4
#define DEV_BOOT_SHAREMEM_CPU_ADDR  0x002001dc /* 存放bootloader pcie share memory地址 */
#define DEV_PCIE_SDIO_SEL           0x64 /* mp17c 寄存器地址与mp6c不同 */

int32_t oal_pcie_get_bar_region_info_mp17c(pcie_res *pst_pci_res, oal_pcie_region **region_base, uint32_t *region_num);

static int32_t oal_pcie_host_slave_address_switch_mp17c(pcie_res *pst_pci_res, uint64_t src_addr,
                                                        uint64_t *dst_addr, int32_t is_host_iova)
{
    if (is_host_iova == OAL_TRUE) {
        if (oal_likely((src_addr < (HISI_PCIE_MASTER_END_ADDRESS)))) {
            *dst_addr = src_addr + HISI_PCIE_IP_REGION_OFFSET;
            oam_info_log2(0, OAM_SF_DPA, "pcie_hostca2devva ok, hostca high:0x%x, low:0x%x",
                          ADDR_HIGH(*dst_addr), ADDR_LOW(*dst_addr));
            return OAL_SUCC;
        }
    } else {
        if (oal_likely((((src_addr >= HISI_PCIE_SLAVE_START_ADDRESS)
                       && (src_addr < (HISI_PCIE_SLAVE_END_ADDRESS)))))) {
            *dst_addr = src_addr - HISI_PCIE_IP_REGION_OFFSET;
            oam_info_log2(0, OAM_SF_DPA, "pcie_devva2hostca ok, devva high:0x%x, low:0x%x",
                          ADDR_HIGH(*dst_addr), ADDR_LOW(*dst_addr));
            return OAL_SUCC;
        }
    }

    oam_error_log3(0, OAM_SF_DPA, "pcie_slave_address_switch[%d] failed, src_addr high:0x%x, low:0x%x",
                   is_host_iova, ADDR_HIGH(src_addr), ADDR_LOW(src_addr));
    return -OAL_EFAIL;
}

/* device intx/msi init */
static int32_t oal_ete_intr_init(pcie_res *pst_pci_res)
{
    hreg_host_intr_mask intr_mask;

    /* enable interrupts */
    if (pst_pci_res->pst_pci_ctrl_base == NULL) {
        oam_warning_log0(0, OAM_SF_DPA, "pst_pci_ctrl_base is null");
        return -OAL_ENODEV;
    }

    hreg_get_val(intr_mask, pst_pci_res->pst_pci_ctrl_base + PCIE_CTRL_RB_HOST_INTR_MASK_OFF);

    intr_mask.bits.host2device_tx_intr_mask = 0;
    intr_mask.bits.device2host_tx_intr_mask = 0;
    intr_mask.bits.device2host_rx_intr_mask = 0;
    intr_mask.bits.device2host_intr_mask = 0;

    /* WiFi中断需要在WiFi回调注册后Unmask */
    intr_mask.bits.mac_n1_intr_mask = 0;
    intr_mask.bits.mac_n2_intr_mask = 0;
    intr_mask.bits.phy_n1_intr_mask = 1;
    intr_mask.bits.phy_n2_intr_mask = 1;
    intr_mask.bits.mac_n3_intr_mask = 0;

    hreg_set_val(intr_mask, pst_pci_res->pst_pci_ctrl_base + PCIE_CTRL_RB_HOST_INTR_MASK_OFF);
    hreg_get_val(intr_mask, pst_pci_res->pst_pci_ctrl_base + PCIE_CTRL_RB_HOST_INTR_MASK_OFF);
    oam_warning_log1(0, OAM_SF_DPA, "pcie intr mask=0x%x", intr_mask.as_dword);

    /* unmask all ete host int */
    oal_writel(0x0, pst_pci_res->ete_info.reg.ete_intr_mask_addr);

    /* 检测到中断事件，但是host侧不处理 */
    pst_pci_res->ete_info.int_event_ignore_mask = (1 << HOST2DEVICE_TX_INTR_MASK);

    return OAL_SUCC;
}

static void oal_ete_res_init(pcie_res *pst_pci_res)
{
    pcie_ete_reg *reg = &pst_pci_res->ete_info.reg;

    reg->host_intr_sts_addr = pst_pci_res->pst_pci_ctrl_base +
                              PCIE_CTRL_RB_HOST_INTR_STATUS_OFF;
    reg->host_intr_clr_addr = pst_pci_res->pst_pci_ctrl_base +
                              PCIE_CTRL_RB_HOST_INTR_CLR_OFF;
    reg->ete_intr_sts_addr = pst_pci_res->pst_ete_base +
                             HOST_CTRL_RB_PCIE_CTL_ETE_INTR_STS_OFF;
    reg->ete_intr_clr_addr = pst_pci_res->pst_ete_base +
                             HOST_CTRL_RB_PCIE_CTL_ETE_INTR_CLR_OFF;
    reg->ete_intr_mask_addr = pst_pci_res->pst_ete_base +
                              HOST_CTRL_RB_PCIE_CTL_ETE_INTR_MASK_OFF;
    reg->ete_dr_empty_sts_addr = pst_pci_res->pst_ete_base +
                                     HOST_CTRL_RB_PCIE_CTRL_ETE_CH_DR_EMPTY_INTR_STS_OFF;
    reg->ete_dr_empty_clr_addr = pst_pci_res->pst_ete_base +
                                 HOST_CTRL_RB_PCIE_CTRL_ETE_CH_DR_EMPTY_INTR_CLR_OFF;
    reg->h2d_intr_addr = pst_pci_res->pst_pci_ctrl_base + PCIE_CTRL_RB_HOST2DEVICE_INTR_SET_OFF;
    reg->host_intr_mask_addr = pst_pci_res->pst_pci_ctrl_base + PCIE_CTRL_RB_HOST_INTR_MASK_OFF;
}

static void oal_pcie_chip_info_cb_init(pcie_chip_cb *cb, int32_t device_id)
{
    cb->pcie_host_slave_address_switch = oal_pcie_host_slave_address_switch_mp17c;
    cb->pcie_get_bar_region_info = oal_pcie_get_bar_region_info_mp17c;
    cb->ete_address_init = oal_ete_res_init;
    cb->ete_intr_init = oal_ete_intr_init;
}

int32_t oal_pcie_chip_info_init_mp17c(pcie_res *pst_pci_res, int32_t device_id)
{
    oam_warning_log0(0, OAM_SF_DPA, "oal_pcie_chip_info_init_mp17c");
    pst_pci_res->chip_info.addr_info.pcie_ctrl = PA_PCIE_CTRL_BASE_ADDR;
    pst_pci_res->chip_info.addr_info.dbi = PA_PCIE_DBI_BASE_ADDRESS;
    pst_pci_res->chip_info.addr_info.ete_ctrl = PA_ETE_CTRL_BASE_ADDRESS;
    pst_pci_res->chip_info.addr_info.glb_ctrl = PA_GLB_CTL_BASE_ADDR;
    pst_pci_res->chip_info.addr_info.pmu_ctrl = PA_PMU_CMU_CTL_BASE;
    pst_pci_res->chip_info.addr_info.pmu2_ctrl = PA_PMU2_CMU_IR_BASE;
    pst_pci_res->chip_info.addr_info.ch_sel = PA_GLB_CTL_W_BASE_ADDR + DEV_PCIE_SDIO_SEL;
    pst_pci_res->chip_info.addr_info.boot_version = DEV_VERSION_CPU_ADDR;
    pst_pci_res->chip_info.addr_info.sharemem_addr = PCIE_CTRL_RB_HOST_DEVICE_REG1_REG;
    pst_pci_res->chip_info.addr_info.boot_sharemem = DEV_BOOT_SHAREMEM_CPU_ADDR;

    oal_pcie_chip_info_cb_init(&pst_pci_res->chip_info.cb, device_id);

    return OAL_SUCC;
}
