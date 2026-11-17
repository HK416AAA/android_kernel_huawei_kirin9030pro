/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: 短距dmi hcc层对外接口
 * Author: platform drivers
 */

#ifndef CONN_DMI_HCC_H
#define CONN_DMI_HCC_H
#ifdef _PRE_PLAT_FEATURE_DPA

#include "oal_hcc_bus.h"
#include "pcie_host_mpxx.h"
#include "dpa_interface.h"

#define MSG_TRANS_BUF_LEN       64
#define ALIGEN_BYTES            4
#define MAA_ALLOC_MAXLEN        1536
#define NETBUF_MAXLEN           1624
#define MAA_DATA_TAIL_RESV_LEN  24

extern oal_atomic g_dpa_sbuf_switch;

// dmi hcc消息初始化
int32_t dmi_hcc_transfer_init(hcc_bus *bus);
// dmi hcc消息去初始化
void dmi_hcc_transfer_deinit(void);
// dmi hcc消息清理
void dmi_hcc_excep_handle(void);
uint64_t conn_dmi_hcc_get_rx_count(void);
int32_t oal_dmi_transfer_res_init(oal_pcie_res *pst_pci_res);
void oal_dmi_transfer_res_exit(oal_pcie_res *pst_pci_res);
int32_t oal_dmi_host_init(oal_pcie_res *pst_pci_res);
int32_t oal_dmi_transfer_deepwkup_restore(oal_pcie_res *pst_pci_res);
void oal_dmi_transfer_deepsleep_clean(oal_pcie_res *pst_pci_res);
int32_t oal_dmi_sleep_wait_ete_rx_trans_done(oal_pcie_res *pst_pci_res);

int32_t oal_pcie_dmi_suspend(oal_pci_dev_stru *pst_pci_dev, oal_pm_message_t state);
int32_t oal_pcie_dmi_resume(oal_pci_dev_stru *pst_pci_dev);
int32_t oal_pcie_dmi_wake_powerup_handler(void *data);

#endif // CONN_DMI_HCC_H
#endif