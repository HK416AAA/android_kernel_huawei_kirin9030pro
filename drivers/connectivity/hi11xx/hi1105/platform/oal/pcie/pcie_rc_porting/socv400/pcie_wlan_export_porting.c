/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 *
 * Description:pcie driver
 * Author: platform drivers
 */

#ifdef _PRE_PLAT_FEATURE_HI110X_PCIE
#ifdef _PRE_WLAN_EXPORT_PCIE

#include "pcie_rc_port.h"
#include "plat_pm.h"

#define WIFI_POWERUP_DONE_TIMEOUT 2000
#define RC_CFG_DWORD_NUM        1024
#define RC_CFG_SAVE_BUFF_SIZE   RC_CFG_DWORD_NUM * NUM_4_BYTES

static uint32_t *g_rc_cfg_buff = NULL;

OAL_STATIC void oal_pcie_free_dev_rc_cfg_save_buff(void)
{
    if (g_rc_cfg_buff != NULL) {
        os_mem_kfree(g_rc_cfg_buff);
        g_rc_cfg_buff = NULL;
    }
}

OAL_STATIC int32_t oal_pcie_save_dev_rc_config(oal_pci_dev_stru *pst_pci_dev)
{
    int32_t ret;
    uint32_t i;
    uint32_t *pst_rc_cfg_buff = NULL;
    oal_pci_dev_stru *pst_rc_dev = NULL;

    /* get rc dev */
    pst_rc_dev = pci_upstream_bridge(pst_pci_dev);
    if (pst_rc_dev == NULL) {
        pci_print_log(PCI_LOG_ERR, "no RC controller dev");
        return -OAL_ENODEV;
    }

    /* malloc buffer for save rc config */
    pst_rc_cfg_buff = (uint32_t *)os_kmalloc_gfp(RC_CFG_SAVE_BUFF_SIZE);
    if (pst_rc_cfg_buff == NULL) {
        pci_print_log(PCI_LOG_ERR, "cfg_buff kmalloc fail");
        return -OAL_EFAIL;
    }
    memset_s(pst_rc_cfg_buff, RC_CFG_SAVE_BUFF_SIZE, 0, RC_CFG_SAVE_BUFF_SIZE);

    /* save all 4096 bytes rc config reg */
    for (i = 0; i < RC_CFG_DWORD_NUM; i++) {
        /* 4 bytes each save */
        ret = oal_pci_read_config_dword(pst_rc_dev, i * NUM_4_BYTES, &pst_rc_cfg_buff[i]);
        if (ret) {
            pci_print_log(PCI_LOG_ERR, "Fail rd rc:[0x%8x:0x%8x], ret=%d", i * NUM_4_BYTES, pst_rc_cfg_buff[i], ret);
            os_mem_kfree(pst_rc_cfg_buff);
            return -OAL_EFAIL;
        }
    }

    g_rc_cfg_buff = pst_rc_cfg_buff;

    pci_print_log(PCI_LOG_INFO, "save rc config success");
    return OAL_SUCC;
}

OAL_STATIC int32_t oal_pcie_restore_dev_rc_config(oal_pci_dev_stru *pst_pci_dev)
{
    int32_t ret;
    uint32_t i;
    oal_pci_dev_stru *pst_rc_dev = NULL;

    /* first wlan0 up try save rc config */
    if (g_rc_cfg_buff == NULL) {
        pci_print_log(PCI_LOG_INFO, "first init try save rc config");
        return oal_pcie_save_dev_rc_config(pst_pci_dev);
    }

    /* get rc dev */
    pst_rc_dev = pci_upstream_bridge(pst_pci_dev);
    if (pst_rc_dev == NULL) {
        pci_print_log(PCI_LOG_ERR, "no RC controller dev");
        return -OAL_ENODEV;
    }

    /* restore all 4096 bytes rc config reg */
    for (i = 0; i < RC_CFG_DWORD_NUM; i++) {
        ret = oal_pci_write_config_dword(pst_rc_dev, i * NUM_4_BYTES, g_rc_cfg_buff[i]); /* 4 bytes */
        if (ret) {
            pci_print_log(PCI_LOG_ERR, "write rc config [%d] failed", i * NUM_4_BYTES);
            return -OAL_EFAIL;
        }
    }

    pci_print_log(PCI_LOG_INFO, "restore rc config success");

    return OAL_SUCC;
}

OAL_STATIC uint32_t oal_pcie_bus_search_target(struct pci_bus *bus, uint32_t ven_id, uint32_t dev_id)
{
    struct pci_dev *dev;
    uint32_t cnt = 0;

    list_for_each_entry(dev, &bus->devices, bus_list) {
        if (dev->vendor == ven_id && dev->device == dev_id) {
            cnt++;
            ps_print_info("find hi110x dev success");
            /* save rc config */
            oal_pcie_save_dev_rc_config(dev);
        }
        ps_print_info("(%s: 0x%x, 0x%x, 0x%x)", pci_name(dev), dev->bus->number, dev->vendor, dev->device);
    }

    list_for_each_entry(dev, &bus->devices, bus_list) {
        if (dev->subordinate) {
            cnt += oal_pcie_bus_search_target(dev->subordinate, ven_id, dev_id);
        }
    }

    return cnt;
}

OAL_STATIC int32_t oal_pcie_try_rescan_dev(void)
{
    int cnt = 0;
    struct pci_bus *bus = NULL;

    power_state_change(CHIP_POWR, BOARD_POWER_OFF);
    power_state_change(W_POWER, BOARD_POWER_OFF);
    mdelay(WIFI_POWERUP_DONE_TIMEOUT);
    power_state_change(CHIP_POWR, BOARD_POWER_ON);
    power_state_change(W_POWER, BOARD_POWER_ON);
    mdelay(WIFI_POWERUP_DONE_TIMEOUT);
    ps_print_info("start try rescan pcie");

    pci_lock_rescan_remove();
    while ((bus = pci_find_next_bus(bus)) != NULL) {
        pci_rescan_bus(bus);
        cnt += oal_pcie_bus_search_target(bus, PCIE_HISI_VENDOR_ID, PCIE_HISI_DEVICE_ID_MP15);
    }
    pci_unlock_rescan_remove();

    ps_print_info("Scan and enum [%d]pcs 110x PCIe device", cnt);
    if (cnt == 0) {
        return -OAL_EFAIL;
    }
    return OAL_SUCC;
}

void oal_pcie_wlan_pm_vote(hcc_bus *hi_bus, uint8_t uc_allow)
{
}

void oal_pcie_deregister_event(oal_pcie_linux_res *pst_pci_lres)
{
    /* call by oal_pcie_remove */
    if (oal_get_pcie_linux_res() == NULL) {
        pci_print_log(PCI_LOG_INFO, "oal_pcie_deregister_event:: free rc cfg save buff");
        oal_pcie_free_dev_rc_cfg_save_buff();
    }
}

void oal_pcie_register_event(oal_pci_dev_stru *pst_pci_dev, oal_pcie_linux_res *pst_pci_lres)
{
}

int32_t oal_pcie_pm_control(struct pci_dev *pdev, u32 rc_idx, int power_option)
{
    if (power_option == PCIE_POWER_ON) {
        pci_print_log(PCI_LOG_INFO, "oal_pcie_pm_control::power on with restore host rc cfg");
        return oal_pcie_restore_dev_rc_config(pdev);
    }
    pci_print_log(PCI_LOG_WARN, "oal_pcie_pm_control option[%d] with export", power_option);
    return OAL_SUCC;
}

int32_t oal_pcie_power_notifiy_register(struct pci_dev *pdev, u32 rc_idx, int (*poweron)(void *data),
                                        int (*poweroff)(void *data), void *data)
{
    if ((poweron != NULL) && (data != NULL)) {
        pci_print_log(PCI_LOG_INFO, "pci_power_notify_register:: run poweron");
        return poweron(data);
    } else if ((poweroff != NULL) && (data != NULL)) {
        pci_print_log(PCI_LOG_INFO, "pci_power_notify_register:: run poweroff");
        return poweroff(data);
    } else if ((pdev == NULL) && (poweron == NULL) && (poweroff == NULL) && (data == NULL)) {
        pci_print_log(PCI_LOG_WARN, "pci_power_notify_register:: free rc cfg save buff");
        oal_pcie_free_dev_rc_cfg_save_buff();
    }
    return OAL_SUCC;
}

int32_t oal_pcie_host_aspm_init(oal_pcie_linux_res *pst_pci_lres)
{
    return OAL_SUCC;
}

int32_t oal_pcie_get_mps(oal_pci_dev_stru *pst_pcie_dev)
{
    return OAL_SUCC;
}

/* Max Payload Size Supported,  must config beofre pcie access */
int32_t oal_pcie_mps_init(oal_pcie_linux_res *pst_pci_lres)
{
    return OAL_SUCC;
}

int32_t oal_pcie_enumerate(int32_t rc_idx)
{
    return oal_pcie_try_rescan_dev();
}
#endif // _PRE_WLAN_EXPORT_PCIE
#endif // _PRE_PLAT_FEATURE_HI110X_PCIE
