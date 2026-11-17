/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */
/*
 * @brief   module_init模块在soc平台acore上底软内部头文件
 * @file    bsp_module_init_soc_modem.h
 * @version v1.0
 * @date    2020.11.20
 * <ul><li>v1.0|2020.11.20|创建文件</li></ul>
 * @since
 */
#ifndef __BSP_MODULE_INIT_SOC_MODEM_H__
#define __BSP_MODULE_INIT_SOC_MODEM_H__

#ifdef __cplusplus
extern "C" {
#endif

/* declare function for drv begin */
extern int bsp_load_image_init(void);
extern int sysctrl_init(void);
extern int bsp_slice_init(void);
extern int bsp_timer_init(void);
extern int bsp_softtimer_init(void);
extern int bsp_ipcmsg_init(void);
extern int bsp_ipc_init(void);
extern int sensorhub_reset_init(void);
extern int bsp_fipc_init(void);
extern int bsp_dump_mem_init(void);
extern int syslog_logmem_init(void);
extern int bsp_udi_init(void);
extern int bsp_reset_init(void);
extern int net_monitor_init(void);
#ifdef ECDC_INIT_ENABLE
extern int ecdc_genetlink_init(void);
extern int llt_shell_verify_init(void);
#endif

#ifdef CONFIG_MDMPM_DEBUG
extern int mdmpm_debug_init(void);
#endif
extern int odt_init(void);
extern int bsp_dump_init(void);
extern int mmc_init(void);
extern int nv_init_dev(void);
extern int om_socket_init(void);
extern int bsp_version_acore_init(void);
extern int ppm_init_phy_port(void);
extern int cpm_port_associate_init(void);
extern int scm_init(void);
extern int bsp_trng_seed_init(void);
extern int bsp_dump_resave_modem_log(void);
extern int dump_mdmap_subsys_exc_stub_init(void);
extern int modem_rfile_init(void);

#ifdef CONFIG_MODEM_PINCTRL
extern int bsp_modem_pinctrl_dts_parse(void);
#endif

#ifdef CONFIG_HEATING_CALIBRATION
extern int heating_calibration_init(void);
#endif

#if defined(CONFIG_KERNEL_DTS_DECOUPLED)
extern int bsp_dt_init(void);
#endif


#ifdef CONFIG_AVS_TEST
extern int avs_test_init(void);
#endif
extern int avs_cfg_init(void);
extern int avs_core_init(void);
#ifdef CONFIG_MODEM_THERMAL_THRES
extern int modem_thermal_init(void);
#endif

extern int bsp_modem_boot_init(void);
extern int modem_efuse_agent_init(void);
extern int virtshl_init(void);
extern int cshell_port_init(void);
extern int modem_log_init(void);
extern int pmic_modem_ocp_init(void);
#ifdef CONFIG_MODEM_CORESIGHT
extern int coresight_trace_init(void);
extern int mdmcp_coresight_init(void);
#endif
#ifdef CONFIG_SYSVIEW
extern int bsp_sysview_init(void);
#endif
extern int modem_power_on_init(void);
extern int sim_hw_service_init(void);
extern int bastet_modem_driver_init(void);

extern int diag_init(void);

#ifdef CONFIG_DRA
extern int dra_init(void);
#endif
#ifdef CONFIG_DPA_DRA
extern int dra_dpa_proxy_init(void);
#endif
#ifdef CONFIG_DPA
extern int dpa_init(void);
#ifndef CONFIG_DPA_V300
extern int dpa_agent_init(void);
#endif
extern int dpa_runtime_init(void);
#ifndef CONFIG_DPA_V300
extern int dpa_debugfs_init(void);
#else
extern int dpa_dvfs_init(void);
#endif
extern int bsp_dpa_fipc_init(void);
extern int bsp_dpa_nmi_init(void);
extern int bsp_dpa_dump_init(void);
#endif

#ifdef CONFIG_SC_GID_CTRL
extern int gid_ctrl_init(void);
#endif
extern int aximem_init(void);
#ifdef CONFIG_NMI
extern int nmi_init(void);
#endif
extern int mloader_verifier_init(void);
extern int mloader_loader_init(void);
extern int mloader_driver_init(void);
extern int lpmcu_modem_init(void);
extern int bsp_pfa_module_init(void);
extern int pfa_filter_init(void);
extern int trans_report_init(void);
#ifdef CONFIG_MLOADER_HOT_PATCH
extern int bsp_modem_hot_patch_b_init(void);
#endif
extern int bsp_memory_init(void);
extern int bsp_memory_layout_init(void);
extern int bsp_memory_report_init(void);
extern int bsp_mperf_init(void);
#ifdef CONFIG_SPPM
extern int sppm_init(void);
#endif
extern int bsp_msg_init(void);
#ifdef CONFIG_BBPDS
extern int bbpds_init(void);
#endif
#ifdef CONFIG_MODEM_AGING
extern int modem_aging_init(void);
#endif
extern int ccpudebug_init(void);
#ifdef CONFIG_VDEV
extern int bsp_vdev_init(void);
#endif
extern int bsp_usb_relay_init(void);

#ifdef CONFIG_DDR_PHONE
extern int bsp_ddr_dump_init(void);
#endif

#ifdef FEATURE_NVA_ON
extern int nva_init(void);
#endif

extern int hmi_init(void);

#ifdef CONFIG_SYSBUS
extern int sys_bus_init(void);
#endif

#ifdef CONFIG_AP_QIC
extern int qic_dump_register_init(void);
#endif

#ifdef CONFIG_MODEM_VBAT
extern int bsp_vbat_init(void);
#endif
#ifdef CONFIG_DPA_OM
extern int bsp_dpa_om_msg_init(void);
extern int bsp_wdt_dpa_init(void);
#ifdef CONFIG_MODEM_CORESIGHT
extern int bsp_dpa_ocd_init(void);
#endif
#endif
#ifdef CONFIG_PMCTRL_BIAS
extern int pmctrl_bias_init(void);
#endif

#ifdef CONFIG_HTS_ADPT
extern int hts_adapter_init(void);
#endif

#ifdef CONFIG_MDM_STR
extern int bsp_mdm_str_init(void);
#endif

#ifdef CONFIG_LLT_MDRV
extern int st_file_init(void);
#endif

#ifdef CONFIG_DPA_MDM_RESET_AGENT
extern int bsp_dpa_modem_reset_init(void);
#endif

#ifdef CONFIG_DPA_HOST_DIAG
extern int diag_dpa_agent_init(void);
#endif

extern int bsp_sysboot_dump_init(void);

/* declare function for drv end */
/*
 * @brief modem初始化函数指针类型
 */
typedef int (*modem_drv_module_init_func)(void);

/* 底软module init分为两个阶段，第一阶段MODEM_MODULE_INIT_START~MODEM_MODULE_INIT_END， 
 * 第二阶段MODEM_MODULE_LATE_INIT_START~MODEM_MODULE_LATE_INIT_END
 */
typedef enum {
    /*底软module init枚举*/
    MODEM_MODULE_INIT_START = 0,
    MLOADER_VERIFIER_INIT = MODEM_MODULE_INIT_START,
    MODEM_DT_INIT,
    MODEM_NVA_INIT,
    MODEM_MEMORY_INIT,
    MODEM_MEMORY_LAYOUT_INIT,
    MODEM_DUMP_RESAVE_LOG,
    MODEM_SYSCTRL_INIT,
    MODEM_SLICE_INIT,
    MODEM_DUMP_MEM_INIT,
    MODEM_SYSBOOT_DUMP_INIT,
    MODEM_SYSLOG_LOGMEM_INIT,
    MODEM_QIC_DUMP_REGISTER_INIT,
    MODEM_IPCMSG_INIT,
    MODEM_IPC_INIT,
    MODEM_SENSORHUB_RESET_INIT,
    MODEM_LOADER_INIT,
    MODEM_AVS_CFG_INIT,
    MODEM_THERMAL_INIT,
    MODEM_NMI_INIT,
    MODEM_TIMER_INIT,
    MODEM_FIPC_INIT,
    MODEM_UDI_INIT,
    MODEM_MSG_INIT,
    MODEM_DUMP_INIT,
    MODEM_EFUSE_AGENT_INIT,
    MODEM_AVS_CORE_INIT,
    MODEM_PMCTRL_BIAS_INIT,
    MODEM_LPMCU_INIT,
    MODEM_GID_CTRL_INIT,
    MODEM_DRA_INIT,
    MODEM_DAP_PROXY_INIT,
    MODEM_DPA_INIT,
    MODEM_DPA_AGENT_INIT,
    MODEM_DPA_RUNTIME_INIT,
    MODEM_DPA_DEBUGFS_INIT,
    MODEM_DPA_DVFS_INIT,
    MODEM_DPA_FIPC_INIT,
    MODEM_DPA_NMI_INIT,
    MODEM_DPA_DUMP_INIT,
    MODEM_AVS_TEST_INIT,
    MODEM_MMC_INIT,
    MODEM_MDM_STR_INIT,
    MODEM_RESET_INIT,
    MODEM_DUMP_MDMPM_SUBSYS_EXC_STUB_INIT,
    MODEM_ECDC_INIT,
    MODEM_LLT_SHELL_VERIFY_INIT,
    MODEM_ODT_INIT,
    MODEM_BBPDS_INIT,
    MODEM_HOT_PATCH_B_INIT,
    MODEM_OM_SOCKET_INIT,
    MODEM_VERSION_ACORE_INIT,
    MODEM_DIAG_INIT,
    MODEM_DIAG_DPA_AGENT_INIT,
    MODEM_AGING_INIT,
    MODEM_PFA_MODULE_INIT,
    MODEM_PFA_FILTER_INIT,
    MODEM_BOOT_INIT,
    MODEM_VERTSHELL_INIT,
    MODME_CSHELL_PORT_INIT,
    MODEM_LOG_INIT,
    MODEM_MDMPM_DEBUG_INIT,
    MODEM_PMIC_OCP_INIT,
    MODEM_VDEV_INIT,
    MODEM_USB_RELAY_INIT,
    MODEM_TRANS_REPORT_INIT,
    MODEM_NET_MONITOR_INIT,
    MODEM_BASTET_DRIVER_INIT,
    MODEM_TRNG_SEED_INIT,
    MODEM_RFILE_INIT,
    MODEM_VBAT_INIT,
    MODEM_DDR_DUMP_INIT,
    MODEM_ST_FILE_INIT,
    //drv module early init结束枚举，添加枚举时需要在该枚举之前
    MODEM_MODULE_INIT_END,
} modem_module_early_init_id_e;

typedef enum {
    /*drv module late init枚举*/
    MODEM_MODULE_LATE_INIT_START = 0,
    MODEM_CP_CORESIGHT_INIT = MODEM_MODULE_LATE_INIT_START,
    MODEM_CORESIGHT_TRACE_INIT,
    MODEM_POWER_ON_INIT,
    MODEM_CCPUDEBUG_INIT,
    MODEM_SYSVIEW_INIT,
    MODEM_SIM_HW_SERVICE_INIT, /*5*/
    MODEM_PINCTRL_DTS_PARSE,
    MODEM_MLOADER_DRIVER_INIT,
    MODEM_DPA_MODEM_RESET_INIT,
    MODEM_MEMORY_REPORT_INIT,
    MODEM_SPPM_INIT, /*10*/
    MODEM_MPERF_INIT,
    MODEM_SYS_BUS_INIT,
    MODEM_HTS_ADAPTER_INIT,
    MODEM_DPA_OM_MSG_INIT,
    MODEM_DPA_OCD_INIT, /*15*/
    MODEM_WDT_DPA_INIT,
    MODEM_HEATING_CALIBRATION_INIT,
    //drv module late init结束枚举，添加枚举时需要在该枚举之前
    MODEM_MODULE_LATE_INIT_END,
} modem_module_late_init_id_e;

struct modem_modult_early_init_info {
    modem_module_early_init_id_e id;
    unsigned char module_name[32];
    modem_drv_module_init_func func;
};

struct modem_modult_late_init_info {
    modem_module_late_init_id_e id;
    unsigned char module_name[32];
    modem_drv_module_init_func func;
};

/*
 * @brief modem初始化函数列表
 */
static struct modem_modult_early_init_info g_modem_modult_early_init_info[] = {
    {MLOADER_VERIFIER_INIT, "mloader_verifier_init", mloader_verifier_init},
    /* pure_initcall */
    {MODEM_DT_INIT, "dt_init",
#if defined(CONFIG_KERNEL_DTS_DECOUPLED)
    bsp_dt_init,
#else
    NULL,
#endif
    },
    {MODEM_NVA_INIT, "nva_init",
#ifdef FEATURE_NVA_ON
    nva_init,
#else
    NULL,
#endif
    },
    {MODEM_MEMORY_INIT, "memory_init",
#ifdef CONFIG_SHARED_MEMORY
    bsp_memory_init,
#else
    NULL,
#endif
    },
    {MODEM_MEMORY_LAYOUT_INIT, "memory_layout_init",
#ifdef CONFIG_MEMORY_LAYOUT
    bsp_memory_layout_init,
#else
    NULL,
#endif
    },

    /* core_initcall */
    {MODEM_DUMP_RESAVE_LOG, "dump_resave_modem_log", bsp_dump_resave_modem_log},
    {MODEM_SYSCTRL_INIT, "sysctrl_init", sysctrl_init},
    {MODEM_SLICE_INIT, "slice_init", bsp_slice_init},
    {MODEM_DUMP_MEM_INIT, "dump_mem_init", bsp_dump_mem_init},
    {MODEM_SYSBOOT_DUMP_INIT, "sysboot_dump_init", bsp_sysboot_dump_init},
    {MODEM_SYSLOG_LOGMEM_INIT, "syslog_logmem_init", syslog_logmem_init},
    {MODEM_QIC_DUMP_REGISTER_INIT, "qic_dump_register_init",
#ifdef CONFIG_AP_QIC
    qic_dump_register_init,
#else
    NULL,
#endif
    },
    {MODEM_IPCMSG_INIT, "ipcmsg_init",
#ifdef CONFIG_MODULE_IPCMSG
    bsp_ipcmsg_init,
#else
    NULL,
#endif
    },
    {MODEM_IPC_INIT, "ipc_init", bsp_ipc_init},
    {MODEM_SENSORHUB_RESET_INIT, "sensorhub_reset_init", sensorhub_reset_init},
    {MODEM_LOADER_INIT, "mloader_loader_init", mloader_loader_init},
    {MODEM_AVS_CFG_INIT, "avs_cfg_init", avs_cfg_init},
    {MODEM_THERMAL_INIT, "modem_thermal_init",
#ifdef CONFIG_MODEM_THERMAL_THRES
    modem_thermal_init,
#else
    NULL,
#endif
    },

    /* arch_initcall */
    {MODEM_NMI_INIT, "nmi_init",
#ifdef CONFIG_NMI
    nmi_init,
#else
    NULL,
#endif
    },
    {MODEM_TIMER_INIT, "timer_init", bsp_timer_init},
    {MODEM_FIPC_INIT, "fipc_init",
#ifdef CONFIG_FIPC_V200
    bsp_fipc_init,
#else
    NULL,
#endif
    },
    {MODEM_UDI_INIT, "udi_init", bsp_udi_init},

    /* arch_initcall_sync */
    {MODEM_MSG_INIT, "msg_init",
#ifdef CONFIG_MODEM_MSG
    bsp_msg_init,
#else
    NULL,
#endif
    },
    {MODEM_DUMP_INIT, "dump_init", bsp_dump_init},
    {MODEM_EFUSE_AGENT_INIT, "efuse_agent_init",
#if (defined(CONFIG_EFUSE) && defined(CONFIG_EFUSE_MODEM_AGENT))
    modem_efuse_agent_init,
#else
    NULL,
#endif
    },
    {MODEM_AVS_CORE_INIT, "avs_core_init", avs_core_init},
    {MODEM_PMCTRL_BIAS_INIT, "pmctrl_bias_init",
#ifdef CONFIG_PMCTRL_BIAS
    pmctrl_bias_init,
#else
    NULL,
#endif
    },
    {MODEM_LPMCU_INIT, "lpmcu_modem_init", lpmcu_modem_init},
    {MODEM_GID_CTRL_INIT, "gid_ctrl_init",
#ifdef CONFIG_SC_GID_CTRL
    gid_ctrl_init,
#else
    NULL,
#endif
    },
    {MODEM_DRA_INIT, "dra_init",
#ifdef CONFIG_DRA
    dra_init,
#else
    NULL,
#endif
    },
    {MODEM_DAP_PROXY_INIT, "dra_dpa_proxy_init",
#ifdef CONFIG_DPA_DRA
    dra_dpa_proxy_init,
#else
    NULL,
#endif
    },
    {MODEM_DPA_INIT, "dpa_init",
#ifdef CONFIG_DPA
    dpa_init,
#else
    NULL,
#endif
    },
    {MODEM_DPA_AGENT_INIT, "dpa_agent_init",
#if (defined(CONFIG_DPA) && !defined(CONFIG_DPA_V300))
    dpa_agent_init,
#else
    NULL,
#endif
    },
    {MODEM_DPA_RUNTIME_INIT, "dpa_runtime_init",
#ifdef CONFIG_DPA
    dpa_runtime_init,
#else
    NULL,
#endif
    },
    {MODEM_DPA_DEBUGFS_INIT, "dpa_debugfs_init",
#if (defined(CONFIG_DPA) && !defined(CONFIG_DPA_V300))
    dpa_debugfs_init,
#else
    NULL,
#endif
    },
    {MODEM_DPA_DVFS_INIT, "dpa_dvfs_init",
#if (defined(CONFIG_DPA) && defined(CONFIG_DPA_V300))
    dpa_dvfs_init,
#else
    NULL,
#endif
    },
    {MODEM_DPA_FIPC_INIT, "bsp_dpa_fipc_init",
#ifdef CONFIG_DPA
    bsp_dpa_fipc_init,
#else
    NULL,
#endif
    },
    {MODEM_DPA_NMI_INIT, "bsp_dpa_nmi_init",
#ifdef CONFIG_DPA
    bsp_dpa_nmi_init,
#else
    NULL,
#endif
    },
    {MODEM_DPA_DUMP_INIT, "bsp_dpa_dump_init",
#ifdef CONFIG_DPA
    bsp_dpa_dump_init,
#else
    NULL,
#endif
    },

    /* subsys_initcall */
    {MODEM_AVS_TEST_INIT, "avs_test_init",
#ifdef CONFIG_AVS_TEST
    avs_test_init,
#else
    NULL,
#endif
    },

    /* fs_initcall */
    {MODEM_MMC_INIT, "mmc_init", mmc_init},
    {MODEM_MDM_STR_INIT, "mdm_str_init",
#ifdef CONFIG_MDM_STR
    bsp_mdm_str_init,
#else
    NULL,
#endif
    },

    /* module_init */
    {MODEM_RESET_INIT, "reset_init", bsp_reset_init},
    {MODEM_DUMP_MDMPM_SUBSYS_EXC_STUB_INIT, "mdmap_subsys_exc_stub_init", dump_mdmap_subsys_exc_stub_init},
    {MODEM_ECDC_INIT, "ecdc_genetlink_init",
#ifdef ECDC_INIT_ENABLE
    ecdc_genetlink_init,
#else
    NULL,
#endif
    },
    {MODEM_LLT_SHELL_VERIFY_INIT, "llt_shell_verify_init",
#ifdef ECDC_INIT_ENABLE
    llt_shell_verify_init,
#else
    NULL,
#endif
    },
    {MODEM_ODT_INIT, "odt_init", odt_init},
    {MODEM_BBPDS_INIT, "bbpds_init",
#ifdef CONFIG_BBPDS
    bbpds_init,
#else
    NULL,
#endif
    },
    {MODEM_HOT_PATCH_B_INIT, "modem_hot_patch_b_init",
#ifdef CONFIG_MLOADER_HOT_PATCH
    bsp_modem_hot_patch_b_init,
#else
    NULL,
#endif
    },
    {MODEM_OM_SOCKET_INIT, "om_socket_init",
#if (defined(CONFIG_OM_SOCKET) || (defined(FEATURE_SVLSOCKET)))
    om_socket_init,
#else
    NULL,
#endif
    },
    {MODEM_VERSION_ACORE_INIT, "version_acore_init", bsp_version_acore_init},
    {MODEM_DIAG_INIT, "diag_init", diag_init},
    {MODEM_DIAG_DPA_AGENT_INIT, "diag_dpa_agent_init",
#ifdef CONFIG_DPA_HOST_DIAG
    diag_dpa_agent_init,
#else
    NULL,
#endif
    },
    {MODEM_AGING_INIT, "modem_aging_init",
#ifdef CONFIG_MODEM_AGING
    modem_aging_init,
#else
    NULL,
#endif
    },
    {MODEM_PFA_MODULE_INIT, "pfa_module_init",
#ifdef CONFIG_PFA
    bsp_pfa_module_init,
#else
    NULL,
#endif
    },
    {MODEM_PFA_FILTER_INIT, "pfa_filter_init",
#ifdef CONFIG_PFA
    pfa_filter_init,
#else
    NULL,
#endif
    },
    {MODEM_BOOT_INIT, "modem_boot_init", bsp_modem_boot_init},
    {MODEM_VERTSHELL_INIT, "virtshl_init",
#ifdef CONFIG_CSHELL
    virtshl_init,
#else
    NULL,
#endif
    },
    {MODME_CSHELL_PORT_INIT, "cshell_port_init",
#ifdef CONFIG_CSHELL
    cshell_port_init,
#else
    NULL,
#endif
    },
    {MODEM_LOG_INIT, "modem_log_init", modem_log_init},
    {MODEM_MDMPM_DEBUG_INIT, "mdmpm_debug_init",
#ifdef CONFIG_MDMPM_DEBUG
    mdmpm_debug_init,
#else
    NULL,
#endif
    },
    {MODEM_PMIC_OCP_INIT, "pmic_modem_ocp_init",
#ifdef CONFIG_PMU_OCP
    pmic_modem_ocp_init,
#else
    NULL,
#endif
    },
    {MODEM_VDEV_INIT, "vdev_init",
#ifdef CONFIG_VDEV
    bsp_vdev_init,
#else
    NULL,
#endif
    },
    {MODEM_USB_RELAY_INIT, "usb_relay_init", bsp_usb_relay_init},
    {MODEM_TRANS_REPORT_INIT, "trans_report_init", 
#ifdef CONFIG_NET_OM
    trans_report_init,
#else
    NULL,
#endif
    },
    {MODEM_NET_MONITOR_INIT, "net_monitor_init",
#ifdef NET_MONITOR
    net_monitor_init,
#else
    NULL,
#endif
    },
    {MODEM_BASTET_DRIVER_INIT, "bastet_modem_driver_init",
#ifdef FEATURE_BASTET
#if (FEATURE_BASTET == FEATURE_ON)
    bastet_modem_driver_init,
#else
    NULL,
#endif // FEATURE_BASTET == FEATURE_ON
#else
    NULL,
#endif  // FEATURE_BASTET
    },
    {MODEM_TRNG_SEED_INIT, "trng_seed_init",
#ifdef CONFIG_TRNG_SEED
    bsp_trng_seed_init,
#else
    NULL,
#endif
    },
    {MODEM_RFILE_INIT, "modem_rfile_init", modem_rfile_init},
    {MODEM_VBAT_INIT, "vbat_init",
#ifdef CONFIG_MODEM_VBAT
    bsp_vbat_init,
#else
    NULL,
#endif
    },
    {MODEM_DDR_DUMP_INIT, "ddr_dump_init",
#ifdef CONFIG_DDR_PHONE
    bsp_ddr_dump_init,
#else
    NULL,
#endif
    },
    {MODEM_ST_FILE_INIT, "st_file_init",
#ifdef CONFIG_LLT_MDRV
    st_file_init,
#else
    NULL,
#endif
    },
};

static struct modem_modult_late_init_info g_modem_modult_late_init_info[] = {
    /* late_initcall */
    {MODEM_CP_CORESIGHT_INIT, "mdmcp_coresight_init",
#ifdef CONFIG_MODEM_CORESIGHT
    mdmcp_coresight_init,
#else
    NULL,
#endif
    },
    {MODEM_CORESIGHT_TRACE_INIT, "coresight_trace_init",
#ifdef CONFIG_MODEM_CORESIGHT
    coresight_trace_init,
#else
    NULL,
#endif
    },
    {MODEM_POWER_ON_INIT, "modem_power_on_init", modem_power_on_init},
    {MODEM_CCPUDEBUG_INIT, "ccpudebug_init",
#ifdef CONFIG_CCPUDEBUG
    ccpudebug_init,
#else
    NULL,
#endif
    },
    {MODEM_SYSVIEW_INIT, "sysview_init",
#ifdef CONFIG_SYSVIEW
    bsp_sysview_init,
#else
    NULL,
#endif
    },
    {MODEM_SIM_HW_SERVICE_INIT, "sim_hw_service_init",
#ifdef CONFIG_SIM_HOTPLUG_SPMI
    sim_hw_service_init,
#else
    NULL,
#endif
    },
    {MODEM_PINCTRL_DTS_PARSE, "modem_pinctrl_dts_parse",
#ifdef CONFIG_MODEM_PINCTRL
    bsp_modem_pinctrl_dts_parse,
#else
    NULL,
#endif
    },
    {MODEM_MLOADER_DRIVER_INIT, "mloader_driver_init", mloader_driver_init},
    {MODEM_DPA_MODEM_RESET_INIT, "dpa_modem_reset_init",
#ifdef CONFIG_DPA_MDM_RESET_AGENT
    bsp_dpa_modem_reset_init,
#else
    NULL,
#endif
    },
    {MODEM_MEMORY_REPORT_INIT, "memory_report_init", bsp_memory_report_init},
    {MODEM_SPPM_INIT, "sppm_init",
#ifdef CONFIG_SPPM
    sppm_init,
#else
    NULL,
#endif
    },
    {MODEM_MPERF_INIT, "mperf_init", bsp_mperf_init},
    {MODEM_SYS_BUS_INIT, "sys_bus_init",
#ifdef CONFIG_SYSBUS
    sys_bus_init,
#else
    NULL,
#endif
    },
    {MODEM_HTS_ADAPTER_INIT, "hts_adapter_init",
#ifdef CONFIG_HTS_ADPT
    hts_adapter_init,
#else
    NULL,
#endif
    },
    {MODEM_DPA_OM_MSG_INIT, "dpa_om_msg_init",
#ifdef CONFIG_DPA_OM
    bsp_dpa_om_msg_init,
#else
    NULL,
#endif
    },
    {MODEM_DPA_OCD_INIT, "dpa_ocd_init",
#if (defined(CONFIG_DPA_OM) && (defined(CONFIG_MODEM_CORESIGHT)))
    bsp_dpa_ocd_init,
#else
    NULL,
#endif
    },
    {MODEM_WDT_DPA_INIT, "wdt_dpa_init",
#ifdef CONFIG_DPA_OM
    bsp_wdt_dpa_init,
#else
    NULL,
#endif
    },
    {MODEM_HEATING_CALIBRATION_INIT, "heating_calibration_init",
#ifdef CONFIG_HEATING_CALIBRATION
    heating_calibration_init,
#else
    NULL,
#endif
    },

};

#ifdef __cplusplus
}
#endif
#endif
