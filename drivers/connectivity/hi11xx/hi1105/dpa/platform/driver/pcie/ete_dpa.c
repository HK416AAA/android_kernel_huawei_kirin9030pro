/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description:ete_dpa.c
 * Author: dpa drivers
 */

#define MPXX_LOG_MODULE_NAME "[PCIE_ETE_H]"
#define HISI_LOG_TAG           "[PCIE_ETE]"

#include "oal_util.h"
#include "pcie_host.h"
#include "pcie_chip.h"
#include "oam_logger.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_DPA_FILE_ID_ETE_DPA_C

OAL_STATIC int32_t oal_pcie_ete_sleep_request_host(hcc_bus_t *pst_bus)
{
    oal_pcie_res *pst_pci_lres = get_pcie_res();
    if (oal_warn_on(pst_pci_lres == NULL)) {
        return -OAL_ENODEV;
    }
    return oal_ete_sleep_request_host_check(pst_pci_lres->pst_pci_res);
}

int32_t oal_pcie_rx_netbuf(hcc_bus_t *pst_bus, oal_netbuf_head_stru *pst_head)
{
    oal_pcie_res *pst_pci_lres;

    pst_pci_lres = get_pcie_res();
    oal_reference(pst_pci_lres);
    return OAL_SUCC;
}

OAL_STATIC int32_t oal_pcie_ete_tx_netbuf(hcc_bus_t *pst_bus, oal_netbuf_head_stru *pst_head,
                                          hcc_netbuf_queue_type_t qtype)
{
    int32_t ret;
    oal_pcie_res *pst_pci_lres = get_pcie_res();
    if (oal_warn_on(pst_pci_lres == NULL)) {
        return -OAL_ENODEV;
    }

    // HCC状态已在外部check
    ret = oal_ete_send_netbuf_list(pst_pci_lres->pst_pci_res, pst_head, qtype);
    return ret;
}

OAL_STATIC void oal_pcie_host_ip_ete_exit(oal_pcie_res *pst_pci_lres)
{
    oam_warning_log0(0, OAM_SF_DPA, "oal_pcie_host_ip_ete_exit");
    (void)oal_ete_ip_exit(pst_pci_lres->pst_pci_res);
}

OAL_STATIC void oal_pcie_host_ip_ete_init(oal_pcie_res *pst_pci_lres)
{
    oam_warning_log0(0, OAM_SF_DPA, "oal_pcie_host_ip_ete_init");
    (void)oal_ete_ip_init(pst_pci_lres->pst_pci_res);
}

OAL_STATIC OAL_INLINE void oal_ete_bus_power_down(oal_pcie_res *pst_pci_lres)
{
    /* should stop ete when wifi poweroff too */
    oal_pcie_host_ip_ete_exit(pst_pci_lres);
    oal_disable_pcie_irq(pst_pci_lres);
    oal_ete_transfer_res_exit(pst_pci_lres->pst_pci_res);
    oal_pcie_change_link_state(pst_pci_lres->pst_pci_res, PCI_WLAN_LINK_DOWN);
    oal_pcie_disable_regions(pst_pci_lres->pst_pci_res);
}

OAL_STATIC OAL_INLINE int32_t oal_ete_bus_power_up(oal_pcie_res *pst_pci_lres)
{
    int32_t ret;
    oam_warning_log0(0, OAM_SF_DPA, "power patch lauch");

    oal_pcie_enable_regions(pst_pci_lres->pst_pci_res);
    oal_enable_pcie_irq(pst_pci_lres);
    ret = oal_ete_transfer_res_init(pst_pci_lres->pst_pci_res);
    if (ret != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "oal_ete_transfer_res_init failed");
        return ret;
    }
    oal_pcie_host_ip_ete_init(pst_pci_lres);
    oal_pcie_change_link_state(pst_pci_lres->pst_pci_res, PCI_WLAN_LINK_WORK_UP);

    return OAL_SUCC;
}

OAL_STATIC int32_t oal_pcie_ete_power_action(hcc_bus_t *pst_bus, hcc_bus_power_action_type action)
{
    int32_t ret = OAL_SUCC;
    oal_pcie_res *pst_pci_lres;

    pst_pci_lres = get_pcie_res();
    if (oal_warn_on(pst_pci_lres == NULL)) {
        oam_error_log0(0, OAM_SF_DPA, "pci ete res is null");
        return -OAL_ENODEV;
    }

    if (action == HCC_BUS_POWER_DOWN) {
        oal_ete_bus_power_down(pst_pci_lres);
    }

    if (action == HCC_BUS_POWER_UP) {
        ret = oal_ete_bus_power_up(pst_pci_lres);
    }

    return ret;
}

OAL_STATIC int32_t oal_pcie_ete_pending_signal_process(hcc_bus_t *hi_bus)
{
    int32_t ret = 0;
    oal_pcie_res *pst_pci_lres = get_pcie_res();
    if (oal_unlikely(pst_pci_lres == NULL)) {
        oam_warning_log0(0, OAM_SF_DPA, "pst_pci_lres is null");
        return 0;
    }

    if (oal_ete_host_pending_signal_check(pst_pci_lres->pst_pci_res) == OAL_TRUE) {
        ret = oal_ete_host_pending_signal_process(pst_pci_lres->pst_pci_res);
    } else {
        oam_info_log0(0, OAM_SF_DPA, "pcie tx pending signal was cleared");
    }

    return ret;
}

OAL_STATIC int32_t oal_pcie_ete_tx_condition(hcc_bus_t *pst_bus, hcc_netbuf_queue_type_t qtype)
{
    oal_pcie_res *pst_pci_lres = get_pcie_res();
    if (oal_warn_on(pst_pci_lres == NULL)) {
        oam_error_log0(0, OAM_SF_DPA, "pci ete res is null");
        return OAL_FALSE;
    }

    return oal_pcie_ete_tx_is_idle(pst_pci_lres->pst_pci_res, qtype);
}

// TODO 需要考虑A核和dpa_cpu看到的 mem_bar 物理地址相同，最好由pcie/dpa提供接口
OAL_STATIC int32_t oal_pcie_master_address_switch(hcc_bus_t *hi_bus, uint64_t src_addr,
                                                  uint64_t* dst_addr, int32_t is_host_va)
{
    int32_t ret = OAL_FALSE;
    pci_addr_map addr_map;

    pcie_res *pst_pci_res = NULL;
    oal_pcie_res *pst_pci_lres = get_pcie_res();
    if (oal_unlikely(pst_pci_lres == NULL)) {
        oam_error_log0(0, OAM_SF_DPA, "pst_pci_lres is null");
        return -OAL_ENODEV;
    }

    pst_pci_res = pst_pci_lres->pst_pci_res;

    if (oal_unlikely(pst_pci_res == NULL)) {
        oam_error_log0(0, OAM_SF_DPA, "pst_pci_res is null");
        return -OAL_ENODEV;
    }

    if (oal_warn_on(dst_addr == NULL)) {
        return -OAL_EINVAL;
    }

    *dst_addr = 0x0;

    if (is_host_va == OAL_FALSE) {
        /* device cpu address -> host virtual address */
        ret = oal_pcie_inbound_ca_to_va(pst_pci_res, src_addr, &addr_map);
        if (ret == OAL_SUCC) {
            *dst_addr = (uint64_t)addr_map.va;
        }
        return ret;
    } else {
        /* host virtual address -> device cpu address */
        ret = oal_pcie_inbound_va_to_ca(pst_pci_res, src_addr, dst_addr);
        return ret;
    }
}

OAL_STATIC int32_t oal_pcie_slave_address_switch(hcc_bus_t *hi_bus, uint64_t src_addr,
                                                 uint64_t* dst_addr, int32_t is_host_iova)
{
    pcie_res *pst_pci_res = NULL;
    oal_pcie_res *pst_pci_lres = get_pcie_res();
    if (oal_unlikely(pst_pci_lres == NULL)) {
        oam_error_log0(0, OAM_SF_DPA, "pst_pci_lres is null");
        return -OAL_ENODEV;
    }

    pst_pci_res = pst_pci_lres->pst_pci_res;

    if (oal_unlikely(pst_pci_res == NULL)) {
        oam_error_log0(0, OAM_SF_DPA, "pst_pci_res is null");
        return -OAL_ENODEV;
    }

    if (oal_warn_on(dst_addr == NULL)) {
        return -OAL_EINVAL;
    }

    return oal_pcie_host_slave_address_switch(pst_pci_res, src_addr, dst_addr, is_host_iova);
}

OAL_STATIC hcc_bus_ops_t g_pcie_ete_opt_ops = {
    .rx_queue_sched = oal_pcie_rx_netbuf,
    .tx_queue_sched = oal_pcie_ete_tx_netbuf,
    .sleep_request_host = oal_pcie_ete_sleep_request_host,
    .power_action = oal_pcie_ete_power_action,
    .tx_condition = oal_pcie_ete_tx_condition,
    .pending_signal_process = oal_pcie_ete_pending_signal_process,
    .master_address_switch = oal_pcie_master_address_switch,
    .slave_address_switch = oal_pcie_slave_address_switch,
};

void oal_pcie_ete_bus_ops_init(hcc_bus_t *pst_bus)
{
    pst_bus->ops = &g_pcie_ete_opt_ops;
}
