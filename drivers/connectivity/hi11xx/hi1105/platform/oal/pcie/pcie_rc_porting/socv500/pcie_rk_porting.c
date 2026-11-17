/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 *
 * Description:pcie driver
 * Author: platform drivers
 */

#ifdef _PRE_PLAT_FEATURE_HI110X_PCIE
#ifdef _PRE_CONFIG_RK_PCIE
#include "pcie_rc_port.h"
#include "oam_ext_if.h"
#include "plat_pm.h"
#include "plat_exception_rst.h"
void oal_pcie_wlan_pm_vote(hcc_bus *hi_bus, uint8_t uc_allow)
{
}

void oal_pcie_deregister_event(oal_pcie_linux_res *pst_pci_lres)
{
    int rc_idx;
    rc_idx = oal_pcie_get_pcie_rc_idx(pst_pci_lres->pst_pcie_dev);
    rk_pcie_event_unregister(rc_idx);
    return;
}

void oal_pcie_linkdown_callback(void *dev)
{
    oal_pcie_linux_res *pst_pci_lres = NULL;
    oal_pci_dev_stru *pst_pci_dev = NULL;

    if (dev == NULL) {
        oal_io_print("pcie linkdown, dev is null!!\n");
        return;
    }

    pst_pci_dev = (oal_pci_dev_stru *)dev;
    if (pst_pci_dev == NULL) {
        oal_io_print("pcie linkdown, pci dev is null!!\n");
        return;
    }

    pst_pci_lres = (oal_pcie_linux_res *)oal_pci_get_drvdata(pst_pci_dev);
    if (pst_pci_lres == NULL) {
        oal_io_print("pcie linkdown, lres is null\n");
        return;
    }

    if (pst_pci_lres->pst_bus == NULL) {
        oal_io_print("pcie linkdown, pst_bus is null\n");
        return;
    }

    oal_io_print("pcie dev[%s] [%d:%d] linkdown\n",
                 dev_name(&pst_pci_dev->dev), pst_pci_dev->vendor, pst_pci_dev->device);
    declare_dft_trace_key_info("pcie_link_down", OAL_DFT_TRACE_EXCEP);

    oal_pcie_change_link_state(pst_pci_lres->pst_pci_res, PCI_WLAN_LINK_DOWN);

    hcc_bus_exception_submit(pst_pci_lres->pst_bus, HCC_BUS_TRANS_FAIL);
}

void oal_pcie_register_event(oal_pci_dev_stru *pst_pci_dev, oal_pcie_linux_res *pst_pci_lres)
{
    int rc_idx;
    rc_idx = oal_pcie_get_pcie_rc_idx(pst_pci_lres->pst_pcie_dev);
    rk_pcie_event_register(pst_pci_dev, rc_idx, oal_pcie_linkdown_callback, 0x2);
    return;
}

int32_t oal_pcie_pm_control(struct pci_dev *pdev, u32 rc_idx, int power_option)
{
    return rk_pcie_pm_control(power_option, rc_idx, pdev);
}

int32_t oal_pcie_power_notifiy_register(struct pci_dev *pdev, u32 rc_idx, int (*poweron)(void *data),
                                        int (*poweroff)(void *data), void *data)
{
    return rk_pcie_power_notifiy_register(rc_idx, poweron, poweroff, data);
}

int32_t oal_pcie_host_aspm_init(oal_pcie_linux_res *pst_pci_lres)
{
    return OAL_SUCC;
}

int32_t oal_pcie_get_mps(oal_pci_dev_stru *pst_pcie_dev)
{
    return OAL_SUCC;
}

int32_t oal_pcie_mps_init(oal_pcie_linux_res *pst_pci_lres)
{
    return OAL_SUCC;
}

int32_t oal_pcie_enumerate(int32_t rc_idx)
{
    return rk_pcie_enumerate(rc_idx);
}

int32_t oal_pcie_get_rc_link_quality_info(oal_pcie_linux_res *pst_pci_lres, uint32_t *d2h_ber)
{
    *d2h_ber = 0;
    return OAL_SUCC;
}
#endif
#endif // _PRE_PLAT_FEATURE_HI110X_PCIE
