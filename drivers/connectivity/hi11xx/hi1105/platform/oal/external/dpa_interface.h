/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description:dpa_interface.h header file
 * Author: platform drivers
 */

#ifndef DPA_INTERFACE_H
#define DPA_INTERFACE_H

#ifdef _PRE_PLAT_FEATURE_DPA
#include <dpa/dpa_dra.h>
#include <dpa/dpa_dmi.h>
#include <dpa/dpa_reset.h>
#include <dpa/dpa_rproc.h>

#define external_dpa_dmi_msg_free_ops dpa_dmi_msg_free_ops
#define external_dpa_dmi_client_request_ops dpa_dmi_client_request_ops
#define external_dpa_dmi_client_init_ops dpa_dmi_client_init_ops
#define external_dpa_dmi_client_register_ops dpa_dmi_client_register_ops
#define external_dpa_dmi_msg_alloc_ops dpa_dmi_msg_alloc_ops
#define external_dpa_data_alloc_ops dpa_data_alloc_ops
#define external_dpa_data_free_ops dpa_data_free_ops
#define external_dpa_data_phys_to_virt_ops dpa_data_phys_to_virt_ops
#define external_dpa_data_wlan_dev_probe_ops dpa_data_wlan_dev_probe_ops
#define external_dpa_data_wlan_dev_remove_ops dpa_data_wlan_dev_remove_ops

#define external_dpa_get_status_ops dpa_get_status_ops
#define external_dpa_wlan_path_switch_acpu dpa_wlan_path_switch_acpu
#define external_dpa_reset_register_cb_ops dpa_reset_register_cb_ops
#endif
#endif