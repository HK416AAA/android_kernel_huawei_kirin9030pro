/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: Rectifying MP12 Exceptions.
 * Author: platform drivers
 */

/* 头文件包含 */
#include "plat_debug.h"
#include "plat_firmware.h"
#include "plat_firmware_download.h"
#include "chr_errno.h"
#include "bfgx_core.h"
#include "exception_common.h"
#include "wifi_exception_rst.h"
#include "bfgx_exception_rst.h"
#include "plat_exception_rst.h"
#include "oam_ext_if.h"
#include "plat_pm_wlan.h"
#include "ssi_common.h"
#include "bfgx_dev.h"
#include "ssi_mp12.h"
#include "mp12_exception_rst.h"

#define G_SUBSYS_RST_DELAY  100
#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_MP12_EXCEPTION_RST_C
#define G_CTL_RB_GCPU_CRG_SOFT_RESET_REG 0x43000D0
#define G_CTL_RB_SOFT_RST_GCPU_SYS_PULSE_MASK 2

OAL_STATIC bool is_single_wifi_mp12(void);
OAL_STATIC bool is_ir_mode_need_dfr_mp12(uint32_t subsys_type);
OAL_STATIC void bfgx_excp_power_off(excp_comm_t *node_ptr, uint8_t flag);
OAL_STATIC int32_t firmware_download_mode_combo_mp12(excp_comm_t *node_ptr);
OAL_STATIC int32_t mp12_wifi_firmware_download_do(excp_comm_t *node_ptr);

OAL_STATIC reset_handler_t g_w_sys_func = {
    .get_power_state = get_wifi_subsys_state,
    .pre_do = wifi_reset_pre_do,
    .power_reset = wifi_power_reset,
    .power_off = wifi_excp_power_off,
    .firmware_download_pre = wifi_firmware_download_pre,
    .firmware_download_do = mp12_wifi_firmware_download_do,
    .firmware_download_fail_do = NULL,
    .firmware_download_post = wifi_firmware_download_post,
    .post_do = wifi_reset_post_do
};

OAL_STATIC reset_handler_t g_bgi_sys_func = {
    .get_power_state = get_bfgx_subsys_state,
    .pre_do = bfgx_reset_pre_do,
    .power_reset = bfgx_subsys_power_reset,
    .power_off = bfgx_excp_power_off,
    .firmware_download_pre = NULL,
    .firmware_download_do = bfgx_firmware_download_do,
    .firmware_download_fail_do = bfgx_download_fail_do,
    .firmware_download_post = bfgx_firmware_download_post,
    .post_do = bfgx_reset_post_do
};

OAL_STATIC excp_subsys_cfg_t g_subsys_cfg[] = {
    {
        .subsys_type = EXCP_W_SYS,
        .subsys_name = "EXCP_W_SYS",
        .which_cfg = WIFI_CFG,
        .chr_id = CHR_PLAT_DRV_ERROR_W_SYSTEM_RST,
        .bus_id = UART_BUTT,
        .subsys_reset_func = &g_w_sys_func,
        .slave_pm_flag = OAL_FALSE,
        .core_cfg = NULL
    },
    {
        // .subsys_idx = EXCP_SYS1,
        .subsys_type = EXCP_B_SYS,
        .subsys_name = "EXCP_B_SYS",
        .which_cfg = BGI_CFG,
        .chr_id = CHR_PLAT_DRV_ERROR_B_SYSTEM_RST,
        .bus_id = BUART,
        .subsys_reset_func = &g_bgi_sys_func,
        .slave_pm_flag = OAL_FALSE,
        .core_cfg = NULL
    }
};

OAL_STATIC reset_handler_t g_reset_handler = {
    .is_ir_mode_need_dfr = is_ir_mode_need_dfr_mp12,
    .is_chip_force_reset = NULL,
    .is_single_wifi = is_single_wifi_mp12,
    .pre_do = chip_mpxx_pre_do,
    .power_reset = chip_mpxx_power_reset,
    .firmware_download_pre = chip_mpxx_firmware_download_pre,
    .firmware_download_do = chip_mpxx_firmware_download_do,
    .firmware_download_mode_combo = firmware_download_mode_combo_mp12,
    .firmware_download_mode_separate = chip_mpxx_firmware_download_mode_separate,
    .firmware_download_fail_do = NULL,
    .firmware_download_post = chip_mpxx_firmware_download_post,
    .post_do = chip_mpxx_post_do
};

OAL_STATIC excp_search_table_t g_excp_table[EXCEPTION_TYPE_BOTTOM] = {
    [BUART_PANIC]             = {BUART_PANIC,             EXCP_B_SYS,      B_CPU,       NULL},
    [GUART_PANIC]             = {GUART_PANIC,             EXCP_B_SYS,      B_CPU,       NULL},
    [HCC_BUS_PANIC]           = {HCC_BUS_PANIC,           EXCP_W_SYS,      W_CPU,       NULL},
    [HCC_BUS_TRANS_FAIL]      = {HCC_BUS_TRANS_FAIL,      EXCP_W_SYS,      W_CPU,       NULL},
    [BUART_WAKEUP_FAIL]       = {BUART_WAKEUP_FAIL,       EXCP_B_SYS,      B_CPU,       NULL},
    [GUART_WAKEUP_FAIL]       = {GUART_WAKEUP_FAIL,       EXCP_B_SYS,      B_CPU,       NULL},
    [WIFI_WAKEUP_FAIL]        = {WIFI_WAKEUP_FAIL,        EXCP_W_SYS,      W_CPU,       NULL},
    [BT_POWERON_FAIL]         = {BT_POWERON_FAIL,         EXCP_B_SYS,      B_CPU,       NULL},
    [GNSS_POWERON_FAIL]       = {GNSS_POWERON_FAIL,       EXCP_B_SYS,      B_CPU,       NULL},
    [IR_POWERON_FAIL]         = {IR_POWERON_FAIL,         EXCP_B_SYS,      B_CPU,       NULL},
    [NFC_POWERON_FAIL]        = {NFC_POWERON_FAIL,        EXCP_UNKOWN_SYS, UNKOWN_CORE, NULL},
    [WIFI_POWERON_FAIL]       = {WIFI_POWERON_FAIL,       EXCP_W_SYS,      W_CPU,       NULL},
    [SLE_POWERON_FAIL]        = {SLE_POWERON_FAIL,        EXCP_B_SYS,      B_CPU,       NULL},
    [BUART_BEATHEART_TIMEOUT] = {BUART_BEATHEART_TIMEOUT, EXCP_B_SYS,      B_CPU,       NULL},
    [GUART_BEATHEART_TIMEOUT] = {GUART_BEATHEART_TIMEOUT, EXCP_B_SYS,      B_CPU,       NULL},
    [BFGX_TIMER_TIMEOUT]      = {BFGX_TIMER_TIMEOUT,      EXCP_ALL_SYS,    ALL_CORE,    NULL}, /* 全系统恢复 */
    [BFGX_ARP_TIMEOUT]        = {BFGX_ARP_TIMEOUT,        EXCP_ALL_SYS,    ALL_CORE,    NULL}, /* 全系统恢复 */
    [WIFI_WATCHDOG_TIMEOUT]   = {WIFI_WATCHDOG_TIMEOUT,   EXCP_W_SYS,      W_CPU,       NULL},
    [SDIO_DUMPBCPU_FAIL]      = {SDIO_DUMPBCPU_FAIL,      EXCP_W_SYS,      W_CPU,       NULL},
    [CHIP_FATAL_ERROR]        = {CHIP_FATAL_ERROR,        EXCP_ALL_SYS,    ALL_CORE,    NULL}, /* 全系统恢复 */
    [GUGONG_POWER_FAIL]       = {GUGONG_POWER_FAIL,       EXCP_ALL_SYS,    ALL_CORE,    NULL}, /* 全系统恢复 */
    [BT_POWER_OFF_FAIL]       = {BT_POWER_OFF_FAIL,       EXCP_B_SYS,      B_CPU,       NULL},
    [GNSS_POWER_OFF_FAIL]     = {GNSS_POWER_OFF_FAIL,     EXCP_B_SYS,      B_CPU,       NULL},
    [IR_POWER_OFF_FAIL]       = {IR_POWER_OFF_FAIL,       EXCP_B_SYS,      B_CPU,       NULL},
    [NFC_POWER_OFF_FAIL]      = {NFC_POWER_OFF_FAIL,      EXCP_UNKOWN_SYS, UNKOWN_CORE, NULL},
    [SLE_POWER_OFF_FAIL]      = {SLE_POWER_OFF_FAIL,      EXCP_B_SYS,      B_CPU,       NULL},
};

/*
 * BFGX_BT = 0x00,
 * BFGX_FM = 0x01,
 * BFGX_GNSS = 0x02,
 * BFGX_IR = 0x03,
 * BFGX_NFC = 0x04,
 * BFGX_SLE = 0x05,
 * BFGX_BUTT = 0x06
 */
OAL_STATIC uint32_t g_bgfx_poweron_fail_table[BFGX_BUTT] = {
    BT_POWERON_FAIL,
    FM_POWERON_FAIL,
    GNSS_POWERON_FAIL,
    IR_POWERON_FAIL,
    NFC_POWERON_FAIL,
    SLE_POWERON_FAIL
};

OAL_STATIC uint32_t g_bgfx_poweroff_fail_table[BFGX_BUTT] = {
    BT_POWER_OFF_FAIL,
    FM_POWER_OFF_FAIL,
    GNSS_POWER_OFF_FAIL,
    IR_POWER_OFF_FAIL,
    NFC_POWER_OFF_FAIL,
    SLE_POWER_OFF_FAIL
};

OAL_STATIC uint32_t g_excp_sys_map[EXCP_SYS_BUTT] = {
    W_SYS,
    B_SYS,
    SYS_BUTT,
};

OAL_STATIC excp_panic_table_t g_panic_table[] = {
    {BUART_PANIC, BUART},
};

OAL_STATIC excp_chip_cfg_t g_chip_cfg = {
    .chip_type = BOARD_VERSION_MP12,
    .chip_name = BOARD_VERSION_NAME_MP12,
    .subsys_cnt = oal_array_size(g_subsys_cfg),
    .subsys_cfg = g_subsys_cfg,
    .chip_reset_func = &g_reset_handler,
    .excp_search = g_excp_table,
    .excp_search_size = EXCEPTION_TYPE_BOTTOM,
    .bfgx_poweron_fail = g_bgfx_poweron_fail_table,
    .poweron_fail_size = BFGX_BUTT,
    .bfgx_poweroff_fail = g_bgfx_poweroff_fail_table,
    .poweroff_fail_size = BFGX_BUTT,
    .excp_sys_map = g_excp_sys_map,
    .sys_map_size = EXCP_SYS_BUTT,
    .panic_table = g_panic_table,
    .panic_table_size = oal_array_size(g_panic_table)
};

oal_mutex_stru g_bfgx_trigger_mutex;
OAL_STATIC oal_bool_enum g_bfgx_subsys_trigger_rst_en = OAL_TRUE;

typedef struct {
    uint32_t panic_type;     /* abort,wdt or other */
    uint32_t version;        /* for script parse */
    uint32_t reg_store_addr; /* reference to g_ulRegStoreAddr */
    uint32_t memdump_addr;
    uint32_t memdump_size;
    uint32_t overflow_flag;  /* if deadbeaf means the mem overflow */
} wcpu_memdump_hdr_t;

typedef struct apb_bus_err {
    uint16_t spmi_apb;
    uint16_t reserved;
} apb_bus_err_t;

typedef struct {
    uint16_t efuse_lotid0;
    uint16_t efuse_lotid1;
    uint16_t efuse_lotid2;
    uint16_t efuse_lotid3;
    uint16_t efuse_lotid4;
    uint16_t efuse_lotid5;
    uint16_t efuse_waferid;
    uint16_t efuse_diex;
    uint16_t efuse_diey;
    uint16_t efuse_iddq;
} die_id_reg_info_t;

typedef struct {
    uint32_t mstatus;
    uint32_t mepc;
    uint32_t tp;    /* X4 */
    uint32_t sp;    /* X2 */

    uint32_t s11;   /* X27 */
    uint32_t s10;   /* X26 */
    uint32_t s9;    /* X25 */
    uint32_t s8;    /* X24 */
    uint32_t s7;    /* X23 */
    uint32_t s6;    /* X22 */
    uint32_t s5;    /* X21 */
    uint32_t s4;    /* X20 */
    uint32_t s3;    /* X19 */
    uint32_t s2;    /* X18 */

    uint32_t s1;    /* X9 */
    uint32_t s0;    /* X8 */

    uint32_t t6;    /* X31 */
    uint32_t t5;    /* X30 */
    uint32_t t4;    /* X29 */
    uint32_t t3;    /* X28 */

    uint32_t a7;    /* X17 */
    uint32_t a6;    /* X16 */
    uint32_t a5;    /* X15 */
    uint32_t a4;    /* X14 */
    uint32_t a3;    /* X13 */
    uint32_t a2;    /* X12 */
    uint32_t a1;    /* X11 */
    uint32_t a0;    /* X10 */

    uint32_t t2;    /* X7 */
    uint32_t t1;    /* X6 */
    uint32_t t0;    /* X5 */

    uint32_t ra;    /* X1 */
} task_context_t;

typedef struct {
    uint32_t ccause;
    uint32_t mcause;
    uint32_t mtval;
    uint32_t gp;
    task_context_t task_context;
} exc_context_t;

typedef struct {         /* 180Byte */
    wcpu_memdump_hdr_t hdr;    /* 24Byte */
    exc_context_t exc_context;           /* 128Byte */
    apb_bus_err_t apb_bus;          /* 4Byte */
    die_id_reg_info_t *die_id_info;
} wcpu_panic_memdump_t;

OAL_STATIC void bfgx_subsys_info_print_mp12(uint32_t reboot_reason)
{
    switch (reboot_reason) {
        case REBOOT_CAUSE_BGI_WATCHDOG:
            declare_dft_trace_key_info("bfgx_exception_bgi_watchdog_timeout", OAL_DFT_TRACE_FAIL);
            oam_error_log0(0, OAM_SF_DFR, "bfgx exception: bgi_watchdog_timeout");
            break;
        case REBOOT_CAUSE_B_PLT_HARDFAULT:
            declare_dft_trace_key_info("bfgx_exception_subsys_is_platform", OAL_DFT_TRACE_FAIL);
            oam_error_log0(0, OAM_SF_DFR, "bfgx exception subsys is: platform");
            break;
        case REBOOT_CAUSE_GNSS_HARDFAULT:
            declare_dft_trace_key_info("bfgx_exception_subsys_is_gnss", OAL_DFT_TRACE_FAIL);
            oam_error_log0(0, OAM_SF_DFR, "bfgx exception subsys is: gnss");
            break;
        case REBOOT_CAUSE_BTC_HARDFAULT:
            declare_dft_trace_key_info("bfgx_exception_subsys_is_btc", OAL_DFT_TRACE_FAIL);
            oam_error_log0(0, OAM_SF_DFR, "bfgx exception subsys is: btc");
            break;
        case REBOOT_CAUSE_BTH_HARDFAULT:
            declare_dft_trace_key_info("bfgx_exception_subsys_is_bth", OAL_DFT_TRACE_FAIL);
            oam_error_log0(0, OAM_SF_DFR, "bfgx exception subsys is: bth");
            break;
        case REBOOT_CAUSE_B_PATCH_HARDFAULT:
            declare_dft_trace_key_info("bfgx_exception_subsys_is_patch", OAL_DFT_TRACE_FAIL);
            oam_error_log0(0, OAM_SF_DFR, "bfgx exception subsys is: patch");
            break;
        default:
            declare_dft_trace_key_info("bfgx_exception_subsys_is_others", OAL_DFT_TRACE_FAIL);
            oam_error_log0(0, OAM_SF_DFR, "bfgx exception subsys is: others");
            break;
    }
}

OAL_STATIC void wlan_subsys_info_print_mp12(uint8_t *pst_buf)
{
    wcpu_panic_memdump_t *last_dump = (wcpu_panic_memdump_t*)pst_buf;
    switch (last_dump->hdr.panic_type) {
        case REBOOT_CAUSE_WL_WATCHDOG:
            declare_dft_trace_key_info("wlan_exception_wifi_watchdog_timeout", OAL_DFT_TRACE_FAIL);
            oam_error_log0(0, OAM_SF_DFR, "wlan exception: wifi_watchdog_timeout");
            break;
        case REBOOT_CAUSE_WL_PLT_HARDFAULT:
            declare_dft_trace_key_info("wlan_exception_subsys_is_platform", OAL_DFT_TRACE_FAIL);
            oam_error_log2(0, OAM_SF_DFR, "wlan exception subsys is: platform, with pc: %x, lr: %x",
                           last_dump->exc_context.task_context.mepc, last_dump->exc_context.task_context.ra);
            break;
        case REBOOT_CAUSE_WL_HARDFAULT:
            declare_dft_trace_key_info("wlan_exception_subsys_is_wifi", OAL_DFT_TRACE_FAIL);
            oam_error_log2(0, OAM_SF_DFR, "wlan exception subsys is: wifi, with pc: %x, lr: %x",
                           last_dump->exc_context.task_context.mepc, last_dump->exc_context.task_context.ra);
            break;
        case REBOOT_CAUSE_WL_PATCH_HARDFAULT:
            declare_dft_trace_key_info("wlan_exception_subsys_is_patch", OAL_DFT_TRACE_FAIL);
            oam_error_log2(0, OAM_SF_DFR, "wlan exception subsys is: patch, with pc: %x, lr: %x",
                           last_dump->exc_context.task_context.mepc, last_dump->exc_context.task_context.ra);
            break;
        default:
            declare_dft_trace_key_info("wlan_exception_subsys_is_others", OAL_DFT_TRACE_FAIL);
            oam_error_log2(0, OAM_SF_DFR, "wlan exception subsys is: others, with pc: %x, lr: %x",
                           last_dump->exc_context.task_context.mepc, last_dump->exc_context.task_context.ra);
            break;
    }
}

OAL_STATIC void bfgx_excp_power_off(excp_comm_t *node_ptr, uint8_t flag)
{
    bfgx_subsys_power_off_proc(node_ptr, flag, B_SYS);
}

OAL_STATIC bool is_single_wifi_mp12(void)
{
    if ((board_subsys_is_shutdown(B_SYS) == true) &&
        (board_subsys_is_shutdown(W_SYS) == false)) {
        return OAL_TRUE;
    }

    return OAL_FALSE;
}

/* 返回false不需要做dfr */
OAL_STATIC bool is_ir_mode_need_dfr_mp12(uint32_t subsys_type)
{
    if ((ps_core_ir_only_mode() == OAL_TRUE) && subsys_type == EXCP_B_SYS) {
        return OAL_FALSE;
    }

    return OAL_TRUE;
}

OAL_STATIC int32_t mp12_wifi_firmware_download_do(excp_comm_t *node_ptr)
{
    oal_reference(node_ptr);
    if (mpxx_firmware_download_mode() != MODE_COMBO) {
        return firmware_download_function(WIFI_CFG, hcc_get_bus(HCC_EP_WIFI_DEV));
    } else {
        return firmware_download_function(WIFI_COMB_CFG, hcc_get_bus(HCC_EP_WIFI_DEV));
    }
}

OAL_STATIC int32_t firmware_download_mode_combo_mp12(excp_comm_t *node_ptr)
{
    int32_t ret = EXCEPTION_SUCCESS;
    excp_chip_cfg_t *chip_cfg = NULL;
    excp_chip_res_t *chip_res = oal_container_of(node_ptr, excp_chip_res_t, node);

    chip_cfg = chip_res->chip_cfg;
    if (oal_unlikely(chip_cfg->chip_reset_func->is_single_wifi == NULL)) {
        ps_print_err("%s: is_single_wifi is NULL\n", __func__);
        return -EXCEPTION_FAIL;
    }

    /* 混合加载: 单wifi场景, 全部加载 */
    if (chip_cfg->chip_reset_func->is_single_wifi() == OAL_TRUE) {
        ps_print_info("%s: firmware_download BFGX_AND_WIFI_CFG"NEWLINE, __func__);
        ret = firmware_download_function(BFGX_AND_WIFI_CFG, hcc_get_bus(HCC_EP_WIFI_DEV));
        return ret;
    }

    /* 组合加载选BGI_COMB_CFG, 后续会下电再上电 */
    if (board_subsys_is_shutdown(B_SYS) == false) {
        ps_print_info("%s: firmware_download BGI_COMB_CFG"NEWLINE, __func__);
        ret = firmware_download_function(BGI_COMB_CFG, hcc_get_bus(HCC_EP_WIFI_DEV));
        wifi_power_reset(NULL); /* BGI_COMB_CFG有QUIT命令退出加载循环, 所以需要拉w_en重新进bootloader接着加载wifi frw */
    }
    board_sys_disable(B_SYS);

    if (board_subsys_is_shutdown(W_SYS) == false) {
        ps_print_info("%s: firmware_download WIFI_COMB_CFG"NEWLINE, __func__);
        ret = firmware_download_function(WIFI_COMB_CFG, hcc_get_bus(HCC_EP_WIFI_DEV));
    }

    if (board_subsys_is_shutdown(B_SYS) == false) {
        board_sys_enable(B_SYS);
    }

    return ret;
}

OAL_STATIC void bfgx_subsys_trigger_rst_mp12(uint32_t sub_index)
{
#ifdef PLATFORM_DEBUG_ENABLE
    struct ps_core_s *ps_core_d = NULL;
    ps_core_d = ps_get_core_reference(BUART);

    if (plat_is_dfr_enable() == OAL_TRUE) {
        return;
    }
    if (bfgx_subsys_trigger_rst_register_get() == OAL_FALSE) {
        return;
    }

    if (wait_bfgx_memdump_complete(ps_core_d) != EXCEPTION_SUCCESS) {
        ps_print_err("try wait memdump complete failed\n");
        return;
    }
    ps_print_info("ssi_write_bgi_reset\n");
    ssi_write_value32_test(G_CTL_RB_GCPU_CRG_SOFT_RESET_REG, G_CTL_RB_SOFT_RST_GCPU_SYS_PULSE_MASK);
    bfgx_subsys_trigger_rst_register_set(OAL_FALSE);
#endif
}

excp_chip_cfg_t *get_mp12_chip_cfg(void)
{
    bfgx_subsys_info_register(bfgx_subsys_info_print_mp12);
    wlan_subsys_info_register(wlan_subsys_info_print_mp12);
    bfgx_subsys_trigger_rst_register(bfgx_subsys_trigger_rst_mp12);
    bfgx_subsys_trigger_rst_register_set(OAL_TRUE);
    wlan_wakeup_ack_irq_loss_dump_set(OAL_TRUE);
    ssi_dump_cpu_trace_register(mp12_ssi_dump_cpu_trace);
    return &g_chip_cfg;
}

void bfgx_subsys_trigger_rst_register_set(oal_bool_enum en)
{
    mutex_lock(&g_bfgx_trigger_mutex);
    g_bfgx_subsys_trigger_rst_en = en;
    mutex_unlock(&g_bfgx_trigger_mutex);
}

oal_bool_enum bfgx_subsys_trigger_rst_register_get(void)
{
    return g_bfgx_subsys_trigger_rst_en;
}