/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2016-2023. All rights reserved.
 *
 * Description: Driver Entry Function Declaration.
 * Author: platform drivers
 */

/* 头文件包含 */
#define MPXX_LOG_MODULE_NAME     "[MP12_BOARD]"
#define MPXX_LOG_MODULE_NAME_VAR mp12_board_loglevel

#include "board.h"
#include "board_dts.h"
#include "bfgx_dev.h"
#include "bfgx_core.h"
#include "chr_user.h"
#include "oam_dsm.h"
#include "plat_debug.h"
#include "plat_pm.h"
#include "plat_uart.h"
#include "plat_firmware.h"
#include "plat_firmware_download.h"
#include "plat_cust.h"
#include "pin_config.h"
#include "plat_common_clk.h"
#include "bfgx_data_parse.h"
#include "board_mp12.h"
#ifdef BFGX_UART_DOWNLOAD_SUPPORT
#include "plat_firmware_uart.h"
#endif
#include "plat_cust_mp12.h"
#include "gpio_mp12.h"
#include "chr_devs.h"
#include "mp12_exception_rst.h"

/* mp12 */
#define FIRMWARE_MP12_ASIC_CFG_DIR  "/vendor/firmware/mp12/sprocess/asic"
#define FIRMWARE_MP12_FPGA_CFG_DIR  "/vendor/firmware/mp12/sprocess/fpga"

/* gnss dpe switch */
#define INI_GNSS_DPE_SWICH "gnss_dpe_switch"
/* gnss xw mode */
#define INI_GNSS_XW_MODE "gnss_xw_mode"

STATIC cfg_map_info g_mp12_fpga_cfg_path_in_vendor[] = {
    {
        .idx = BFGX_AND_WIFI_CFG,
        .cfg_path = BFGX_AND_WIFI_CFG_FILE,
    },
    {
        .idx = WIFI_CFG,
        .cfg_path = WIFI_CFG_FILE,
    },
    {
        .idx = BGI_CFG,
        .cfg_path = BGI_CFG_FILE
    },
    {
        .idx = IR_CFG,
        .cfg_path = IR_CFG_FILE
    },
    {
        .idx = BGI_COMB_CFG,
        .cfg_path = BGI_COMB_CFG_FILE
    },
    {
        .idx = WIFI_COMB_CFG,
        .cfg_path = WIFI_COMB_CFG_FILE,
    },
    {
        .idx = IR_COMB_CFG,
        .cfg_path = IR_COMB_CFG_FILE,
    }
};

STATIC cfg_map_info g_mp12_asic_cfg_path_in_vendor[] = {
    {
        .idx = BFGX_AND_WIFI_CFG,
        .cfg_path = BFGX_AND_WIFI_CFG_FILE,
    },
    {
        .idx = WIFI_CFG,
        .cfg_path = WIFI_CFG_FILE,
    },
    {
        .idx = BGI_CFG,
        .cfg_path = BGI_CFG_FILE
    },
    {
        .idx = IR_CFG,
        .cfg_path = IR_CFG_FILE
    },
    {
        .idx = BGI_COMB_CFG,
        .cfg_path = BGI_COMB_CFG_FILE
    },
    {
        .idx = WIFI_COMB_CFG,
        .cfg_path = WIFI_COMB_CFG_FILE,
    },
    {
        .idx = IR_COMB_CFG,
        .cfg_path = IR_COMB_CFG_FILE,
    },
    {
        .idx = OFF_FIND_CFG,
        .cfg_path = OFF_FIND_CFG_FILE,
    }
};

chip_firmware_cfg_str g_mp12_cfg_str[] = {
    {
        .chip_nr = BOARD_VERSION_MP12,
        .is_asic = VERSION_FPGA,
        .cfg_map_size = oal_array_size(g_mp12_fpga_cfg_path_in_vendor),
        .cfg_map = g_mp12_fpga_cfg_path_in_vendor,
        .pre_directory = FIRMWARE_MP12_FPGA_CFG_DIR
    }, {
        .chip_nr = BOARD_VERSION_MP12,
        .is_asic = VERSION_ASIC,
        .cfg_map_size = oal_array_size(g_mp12_asic_cfg_path_in_vendor),
        .cfg_map = g_mp12_asic_cfg_path_in_vendor,
        .pre_directory = FIRMWARE_MP12_ASIC_CFG_DIR
    }
};

STATIC pin_cfg_map_info_t g_mp12_pin_cfg_map[] = {
    {
        .product_id = BOARD_MP12_PRODUCT_ID_1,
        .product_name = DTS_NAME_PHONE,
    },
    {
        .product_id = BOARD_MP12_PRODUCT_ID_2,
        .product_name = DTS_NAME_PC,
    }
};

STATIC bool bgi_is_shutdown(void)
{
    struct ps_core_s *ps_core_d = ps_get_core_reference(BUART);
    if (ps_core_d == NULL) {
        ps_print_info("bfgx not init\n");
        return true;
    }

    return ps_core_chk_bfgx_active(ps_core_d) ? false : true;
}

bool mp12_susbsys_is_shutdown(uint32_t subsystem)
{
    bool is_open = OAL_FALSE;
    if (subsystem == W_SYS) {
        is_open = wlan_is_shutdown();
    } else if (subsystem == B_SYS) {
        is_open = bgi_is_shutdown();
    } else {
        ps_print_err("invalid system:%d error\n", subsystem);
    }
    return is_open;
}

STATIC void board_bfgx_plat_cust_set_mp12(struct ps_core_s *ps_core_d)
{
    plat_cust_data_mp12 *plat_cust = NULL;
    struct ps_plat_s *ps_plat_d = NULL;

    ps_plat_d = (struct ps_plat_s *)ps_core_d->ps_plat;
    if (ps_plat_d == NULL) {
        return;
    }

    plat_cust = (plat_cust_data_mp12 *)get_plat_cust_addr();
    if (plat_cust == NULL) {
        ps_print_err("plat_cust buf not init, please check\n");
        return;
    }

    plat_cust->cfg.buart_rate = ps_plat_d->baud_rate;
    plat_cust->cfg.uart_parity_en = ps_plat_d->paren;
    ps_print_info("[%s]baud_rate set = %lu, uart_parity_en = %u\n",
                  index2name(ps_core_d->uart_index), ps_plat_d->baud_rate, ps_plat_d->paren);
}

void pm_common_send_cmd_to_dev(uint32_t uart_index, uint8_t plt_evt_type)
{
    struct ps_core_s *ps_core_d = NULL;
    int32_t ret = 0;
    int32_t prepare_result;

    ps_core_d = ps_get_core_reference(uart_index);
    if (ps_core_d == NULL) {
        ps_print_err("set pcie clk io fail. ps_core_d is NULL!\n");
        return;
    }

    ret = prepare_to_visit_node(ps_core_d, &prepare_result);
    if (ret < 0) {
        ps_print_err("set pcie clk io fail. visit node fail\n");
        return;
    }

    if (ps_core_d->tty_have_open == false) {
        ps_print_warning("tty has not open. not send msg\n");
    } else {
        ps_tx_sys_cmd(ps_core_d, SYS_MSG, plt_evt_type);
        ps_print_info("set pcie clk io begin. type is %x!\n", plt_evt_type);
    }

    post_to_visit_node(ps_core_d, prepare_result);
}

STATIC int32_t mp12_board_w_power_on(void)
{
    int32_t prepare_result = FAILURE;
    int32_t ret = OAL_FAIL;

    if (bgi_is_shutdown()) {
        ps_print_info("wifi bootup pull up pwr_en\n");
        board_chip_power_on();
    } else {
        /* 1.pcie_clk_req_io存在漏电问题, w打开时, 通过uart给bg发消息, 修改pcie_clk_req_io模式, 配默认值, 如果是sdio场景,
           w起来后会配高阻拉高 */
        pm_common_send_cmd_to_dev(BUART, SYS_CFG_PCIE_IO_DEFAULT);
        /* w和bg子系统en都拉高后, 任一子系统en拉低后, buck在单子系统深睡时无法进入睡眠模式调压,
           可以通过uart消息唤醒bg核, 从而调节buck电压到1.15v */
        ret = pm_visit_node_pre(BUART, &prepare_result);
    }

    if (board_sys_enable(W_SYS)) {
        ps_print_info("wlan sys enable fail");
        if (!bgi_is_shutdown()) {
            pm_visit_node_post(BUART, prepare_result, ret);
        }
        return WIFI_POWER_BFGX_OFF_PULL_WLEN_FAIL;
    }

    if (!bgi_is_shutdown()) {
        pm_visit_node_post(BUART, prepare_result, ret);
    }

    if (mpxx_firmware_download_mode() == MODE_COMBO) {
        if (bgi_is_shutdown()) {
            board_sys_enable(B_SYS);
        }
    }

    return OAL_SUCC;
}

STATIC int32_t mp12_board_bgi_power_on(void)
{
    if (wlan_is_shutdown()) {
        ps_print_info("bcore bootup pull up pwr_en!\n");
        board_chip_power_on();
    } else {
        wlan_pm_disable();
        ps_print_info("wake up wifi before bgi en on!\n");
    }

    board_sys_enable(B_SYS);

    if (!wlan_is_shutdown()) {
        wlan_pm_enable(); // 不用担心会误开低功耗  g_wlan_host_pm_switch表示host是否使能低功耗, 函数里自动返回
    }

    return  SUCC;
}

STATIC int32_t mp12_board_power_on(uint32_t ul_subsystem)
{
    int32_t ret;
    ret = mp12_gugong_subsys_power_on(ul_subsystem);
    if (ret < 0) {
        ps_print_err("subsys:%d gugong check fail\n", ul_subsystem);
        return WIFI_POWER_FAIL;
    }
    if (ul_subsystem == W_SYS) {
        return mp12_board_w_power_on();
    } else if (ul_subsystem == B_SYS) {
        return mp12_board_bgi_power_on();
    } else {
        ps_print_err("power input system:%d error\n", ul_subsystem);
        return WIFI_POWER_FAIL;
    }
}

STATIC void mp12_board_w_power_off(void)
{
    board_sys_disable(W_SYS);
    if (bgi_is_shutdown()) {
        ps_print_info("wifi close pull down pwr_en\n");
        board_chip_power_off();
    } else {
        // pcie_clk_req_io存在漏电问题, 共存场景, w关闭时, 通过uart发消息, 修改pcie_clk_req_io模式配高阻拉高
        pm_common_send_cmd_to_dev(BUART, SYS_CFG_PCIE_IO_HIZ);
    }
}

// pcie_clk_req_io存在漏电问题, 非共存场景, bg核打开时, 通过uart发消息, 修改pcie_clk_req_io模式配高阻拉高
void mp12_bfgx_dev_power_on_post(void)
{
    if (get_mpxx_subchip_type() == BOARD_VERSION_MP12 && wlan_is_shutdown()) {
        pm_common_send_cmd_to_dev(BUART, SYS_CFG_PCIE_IO_HIZ);
    }
}

STATIC void mp12_board_bgi_power_off(void)
{
    board_sys_disable(B_SYS);
    if (wlan_is_shutdown()) {
        ps_print_info("bi close pull down pwr_en\n");
        board_sys_disable(W_SYS); // 混合加载模式
        board_chip_power_off();
    }
}

STATIC int32_t mp12_board_power_off(uint32_t ul_subsystem)
{
    if (ul_subsystem == W_SYS) {
        mp12_board_w_power_off();
    } else if (ul_subsystem == B_SYS) {
        mp12_board_bgi_power_off();
    } else {
        ps_print_err("power input system:%d error\n", ul_subsystem);
        return -EFAIL;
    }
    mp12_gugong_subsys_power_off(ul_subsystem);
    return SUCC;
}

#ifndef BFGX_UART_DOWNLOAD_SUPPORT
STATIC int32_t mp12_bfgx_download_handler(struct ps_core_s *ps_core_d, uint32_t cfg, uint32_t sys)
{
    int32_t ret = OAL_SUCC;
    struct pm_top* pm_top_data = pm_get_top();

    if (wlan_is_shutdown()) {
        ret = board_sys_enable(W_SYS);
        if (ret != SUCC) {
            return -EFAIL;
        }
    }

    if (mpxx_firmware_download_mode() == MODE_COMBO &&
        oal_atomic_read(&ps_core_d->ir_only) == 0) {
        if (bgi_is_shutdown() == true) {
            board_sys_enable(B_SYS);
        }
    }

    ret = firmware_download_function(cfg, hcc_get_bus(HCC_EP_WIFI_DEV));
    if (ret != (int32_t)BFGX_POWER_SUCCESS) {
        hcc_bus_disable_state(pm_top_data->wlan_pm_info->pst_bus, OAL_BUS_STATE_ALL);
        ps_print_err("bfgx download firmware fail!\n");
        ret = (ret == -OAL_EINTR) ? BFGX_POWER_DOWNLOAD_FIRMWARE_INTERRUPT : BFGX_POWER_DOWNLOAD_FIRMWARE_FAIL;
    }

    if (wlan_is_shutdown()) {
        hcc_bus_disable_state(pm_top_data->wlan_pm_info->pst_bus, OAL_BUS_STATE_ALL);
        board_sys_disable(W_SYS);
    }

    return ret;
}

STATIC int32_t mp12_get_bfgx_comb_dl_cfg(struct ps_core_s *ps_core_d, uint32_t sys, uint32_t *whitch_cfg)
{
    if (oal_atomic_read(&ps_core_d->ir_only) == 1) {
        *whitch_cfg = IR_COMB_CFG;
    } else if (oal_atomic_read(&ps_core_d->off_find) == 1) {
        *whitch_cfg = OFF_FIND_CFG;
    } else {
        // 混合加载时wifi上电已经加载完所有子系统FRW
        if (wlan_is_shutdown() == false) {
            ps_print_info("board already power on");
            return BFGX_POWER_ALREADY_DOWNLOAD;
        }
        *whitch_cfg = BGI_COMB_CFG;
    }
    return BFGX_POWER_SUCCESS;
}

STATIC int32_t mp12_get_bfgx_separate_cfg(struct ps_core_s *ps_core_d, uint32_t sys, uint32_t *whitch_cfg)
{
    if (oal_atomic_read(&ps_core_d->ir_only) == 1) {
        *whitch_cfg = IR_CFG;
    } else if (oal_atomic_read(&ps_core_d->off_find) == 1) {
        *whitch_cfg = OFF_FIND_CFG;
    } else {
        *whitch_cfg = BGI_CFG;
    }
    return BFGX_POWER_SUCCESS;
}

STATIC int32_t mp12_bfgx_download_by_wifi(struct ps_core_s *ps_core_d, uint32_t sys)
{
    int32_t ret;
    uint32_t whitch_cfg;
    int32_t download_mode;

    download_mode = mpxx_firmware_download_mode();
    if ((download_mode >= MODE_DOWNLOAD_BUTT) || (download_mode < 0)) {
        ps_print_err("download mode[%d] not recognize", download_mode);
        return BFGX_POWER_FAILED;
    }

    if (download_mode == MODE_COMBO) {
        ret = mp12_get_bfgx_comb_dl_cfg(ps_core_d, sys, &whitch_cfg);
    } else {
        ret = mp12_get_bfgx_separate_cfg(ps_core_d, sys, &whitch_cfg);
    }

    if (ret == BFGX_POWER_ALREADY_DOWNLOAD) {
        return BFGX_POWER_SUCCESS;
    }

    if (mp12_bfgx_download_handler(ps_core_d, whitch_cfg, sys) != OAL_SUCC) {
        ps_print_info("wifi download bfgx frw fail");
        return BFGX_POWER_DOWNLOAD_FIRMWARE_FAIL;
    }

    return BFGX_POWER_SUCCESS;
}
#else
STATIC int32_t mp12_bfgx_download_by_uart(struct ps_core_s *ps_core_d)
{
    int32_t error;

    st_tty_recv = ps_recv_patch;
    error = ps_core_d->pm_data->download_patch(ps_core_d);
    if (error) { /* if download patch err,and close uart */
        ps_print_err(" download_patch is failed!\n");
        st_tty_recv = ps_core_recv;
        return error;
    }

    ps_print_suc("download_patch is successfully!\n");
    st_tty_recv = ps_core_recv;
    return error;
}

STATIC int32_t mp12_bfgx_firmware_download(struct ps_core_s *ps_core_d)
{
    int32_t error;

    error = mp12_bfgx_download_by_uart(ps_core_d);

    return error;
}
#endif

STATIC void mp12_judge_ir_mode(struct ps_core_s *ps_core_d)
{
    int32_t download_mode;

    download_mode = mpxx_firmware_download_mode();
    if (download_mode == MODE_COMBO) {
        if (wlan_is_shutdown() && bgi_is_shutdown()) {
            oal_atomic_set(&ps_core_d->ir_only, 1);
        }
    } else if (download_mode == MODE_SEPARATE) {
        if (bgi_is_shutdown()) {
            oal_atomic_set(&ps_core_d->ir_only, 1);
        }
    }

#ifdef BFGX_UART_DOWNLOAD_SUPPORT
    // uart加载单红外bin场景, 需要修改uart波特率
    if (oal_atomic_read(&ps_core_d->ir_only) != 0) {
        g_ir_only_baud_rate = UART_BAUD_RATE_2M;
    }
#endif
}

STATIC int32_t mp12_bfgx_dev_power_on(struct ps_core_s *ps_core_d, uint32_t sys, uint32_t subsys)
{
    int32_t ret;
    int32_t error = BFGX_POWER_SUCCESS;

    if ((ps_core_d == NULL) || (ps_core_d->pm_data == NULL)) {
        ps_print_err("ps_core_d is err\n");
        return BFGX_POWER_FAILED;
    }

    if (subsys == BFGX_IR) {
        mp12_judge_ir_mode(ps_core_d);
        ps_print_info("ir mode[%d]\n", oal_atomic_read(&ps_core_d->ir_only));
    }

    bfgx_subsys_trigger_rst_register_set(OAL_TRUE);
    board_bfgx_plat_cust_set_mp12(ps_core_d);
    ret = mp12_board_power_on(sys);
    if (ret) {
        ps_print_err("mp12_board_power_on bfg failed, ret=%d\n", ret);
        error = BFGX_POWER_PULL_POWER_GPIO_FAIL;
        goto bfgx_power_on_fail;
    }

    bfgx_gpio_intr_enable(ps_core_d->pm_data, OAL_TRUE);
    if (open_tty_drv(ps_core_d) != BFGX_POWER_SUCCESS) {
        ps_print_err("open tty fail!\n");
        error = BFGX_POWER_TTY_OPEN_FAIL;
        goto bfgx_power_on_fail;
    }
#ifndef BFGX_UART_DOWNLOAD_SUPPORT
    error = mp12_bfgx_download_by_wifi(ps_core_d, sys);
    if (error != BFGX_POWER_SUCCESS) {
        goto bfgx_power_on_fail;
    }
#else
    error = mp12_bfgx_firmware_download(ps_core_d);
    if (error != BFGX_POWER_SUCCESS) {
        release_tty_drv(ps_core_d);
        goto bfgx_power_on_fail;
    }
#endif
    return BFGX_POWER_SUCCESS;

bfgx_power_on_fail:
    if (error != BFGX_POWER_DOWNLOAD_FIRMWARE_INTERRUPT) {
        hw_mpxx_dsm_client_notify(SYSTEM_TYPE_PLATFORM, DSM_MPXX_DOWNLOAD_FIRMWARE,
                                  "bcpu download firmware failed,wifi %s,ret=%d,process:%s\n",
                                  wlan_is_shutdown() ? "off" : "on", error, current->comm);
    }
    (void)mp12_board_power_off(sys);
    return error;
}

STATIC int32_t mp12_bfgx_dev_power_off(struct ps_core_s *ps_core_d, uint32_t sys, uint32_t subsys)
{
    struct pm_drv_data *pm_data = NULL;

    ps_print_info("%s sys[%d] subsys[%d] \n", __func__, sys, subsys);
    if ((ps_core_d == NULL) || (ps_core_d->pm_data == NULL)) {
        ps_print_err("ps_core_d is err\n");
        return BFGX_POWER_FAILED;
    }

    pm_data = ps_core_d->pm_data;
    bfgx_gpio_intr_enable(pm_data, OAL_FALSE);

    if (wait_bfgx_memdump_complete(ps_core_d) != EXCEPTION_SUCCESS) {
        ps_print_err("wait memdump complete failed\n");
    }

    if (release_tty_drv(ps_core_d) != SUCCESS) {
        /* 代码执行到此处，说明六合一所有业务都已经关闭，无论tty是否关闭成功，device都要下电 */
        ps_print_err("wifi off, close tty is err!");
    }

    pm_data->bfgx_dev_state = BFGX_SLEEP;
    pm_data->uart_state = UART_NOT_READY;

    (void)mp12_board_power_off(sys);

    if (subsys == BFGX_IR) {
        oal_atomic_set(&ps_core_d->ir_only, 0);
    }
    bfgx_subsys_trigger_rst_register_set(OAL_FALSE);
    return BFGX_POWER_SUCCESS;
}

STATIC int32_t mp12_wlan_firmware_download(void)
{
    int32_t ret;
    if ((mpxx_firmware_download_mode() == MODE_COMBO)) {
        if (bgi_is_shutdown()) {
            ret = firmware_download_function(BFGX_AND_WIFI_CFG, hcc_get_bus(HCC_EP_WIFI_DEV));
            board_sys_disable(B_SYS);
        }  else {
            ret = firmware_download_function(WIFI_COMB_CFG, hcc_get_bus(HCC_EP_WIFI_DEV));
        }
    } else {
        ret = firmware_download_function(WIFI_CFG, hcc_get_bus(HCC_EP_WIFI_DEV));
    }

    return ret;
}

STATIC int32_t mp12_wlan_power_on(void)
{
    int32_t ret, error;
    struct wlan_pm_s *wlan_pm_info = wlan_pm_get_drv();

    error = mp12_board_power_on(W_SYS);
    if (error != SUCC) {
        ps_print_err("board power on fail\n");
        goto wifi_power_fail;
    }

    hcc_bus_power_action(hcc_get_bus(HCC_EP_WIFI_DEV), HCC_BUS_POWER_PATCH_LOAD_PREPARE);

    error = mp12_wlan_firmware_download();
    if (error != (int32_t)WIFI_POWER_SUCCESS) {
        ps_print_err("firmware download fail\n");
        if (error == -OAL_EINTR) {
            error = WIFI_POWER_ON_FIRMWARE_DOWNLOAD_INTERRUPT;
        } else if (error == -OAL_ENOPERMI) {
            error = WIFI_POWER_ON_FIRMWARE_FILE_OPEN_FAIL;
        } else {
            error = WIFI_POWER_BFGX_OFF_FIRMWARE_DOWNLOAD_FAIL;
        }
        goto wifi_power_fail;
    } else {
        wlan_pm_info->wlan_power_state = POWER_STATE_OPEN;
    }

    ret = hcc_bus_power_action(hcc_get_bus(HCC_EP_WIFI_DEV), HCC_BUS_POWER_PATCH_LAUCH);
    if (ret != 0) {
        declare_dft_trace_key_info("wlan_poweron HCC_BUS_POWER_PATCH_LAUCH by gpio_fail", OAL_DFT_TRACE_FAIL);
        error = WIFI_POWER_BFGX_OFF_BOOT_UP_FAIL;
        chr_exception_report(CHR_PLATFORM_EXCEPTION_EVENTID, CHR_SYSTEM_PLAT, CHR_LAYER_DRV,
                             CHR_PLT_DRV_EVENT_OPEN, CHR_PLAT_DRV_ERROR_WCPU_BOOTUP);
        goto wifi_power_fail;
    }

    return WIFI_POWER_SUCCESS;
wifi_power_fail:
    if (error != (int32_t)WIFI_POWER_ON_FIRMWARE_DOWNLOAD_INTERRUPT &&
        error != (int32_t)WIFI_POWER_ON_FIRMWARE_FILE_OPEN_FAIL) {
        hw_mpxx_dsm_client_notify(SYSTEM_TYPE_PLATFORM, DSM_MPXX_DOWNLOAD_FIRMWARE,
                                  "%s: failed to download firmware, bfgx %s, error=%d\n",
                                  __FUNCTION__, bgi_is_shutdown() ? "off" : "on", error);
    }
    ssi_dump_err_regs(SSI_ERR_FIRMWARE_DOWN_FAIL);
    return error;
}

STATIC int32_t mp12_wlan_power_off(void)
{
    struct wlan_pm_s *wlan_pm_info = wlan_pm_get_drv();

    /* 先关闭SDIO TX通道 */
    hcc_bus_disable_state(hcc_get_bus(HCC_EP_WIFI_DEV), OAL_BUS_STATE_TX);

    /* wakeup dev,send poweroff cmd to wifi */
    if (wlan_pm_poweroff_cmd() != OAL_SUCC) {
        /* wifi self close 失败了也继续往下执行，uart关闭WCPU，异常恢复推迟到wifi下次open的时候执行 */
        declare_dft_trace_key_info("wlan_poweroff_cmd_fail", OAL_DFT_TRACE_FAIL);
        chr_exception_report(CHR_PLATFORM_EXCEPTION_EVENTID, CHR_SYSTEM_PLAT, CHR_LAYER_DRV,
                             CHR_PLT_DRV_EVENT_CLOSE, CHR_PLAT_DRV_ERROR_CLOSE_WCPU);
    }
    hcc_bus_disable_state(hcc_get_bus(HCC_EP_WIFI_DEV), OAL_BUS_STATE_ALL);

    (void)mp12_board_power_off(W_SYS);

    if (wlan_pm_info != NULL) {
        wlan_pm_info->wlan_power_state = POWER_STATE_SHUTDOWN;
    }
    return SUCCESS;
}

STATIC void mp12_power_state_change(int32_t type, int32_t flag)
{
    if (flag == BOARD_POWER_ON) {
        conn_set_gpio_level(type, GPIO_LEVEL_LOW);
        mdelay(10); /* delay 10ms */
        conn_set_gpio_level(type, GPIO_LEVEL_HIGH);
        mdelay(60); // 60ms  w打开场景, 需要50ms解复位cpu, 然后hcc才能够使用
    } else if (flag == BOARD_POWER_OFF) {
        conn_set_gpio_level(type, GPIO_LEVEL_LOW);
        mdelay(10); /* delay 10ms */
    }
}

STATIC int32_t mp12_board_power_reset(uint32_t ul_subsystem)
{
    int32_t ret;
    board_sys_disable(B_SYS);
#ifndef BFGX_UART_DOWNLOAD_SUPPORT
    board_sys_disable(W_SYS);
#endif
    board_chip_power_off();
    board_chip_power_on();
#ifndef BFGX_UART_DOWNLOAD_SUPPORT
    ret = board_sys_enable(W_SYS);
#endif
    ret = board_sys_enable(B_SYS);
    return ret;
}

STATIC void board_callback_init_mp12_power(void)
{
    g_st_board_info.bd_ops.bfgx_dev_power_on = mp12_bfgx_dev_power_on;
    g_st_board_info.bd_ops.bfgx_dev_power_off = mp12_bfgx_dev_power_off;
    g_st_board_info.bd_ops.wlan_power_on = mp12_wlan_power_on;
    g_st_board_info.bd_ops.wlan_power_off = mp12_wlan_power_off;
    g_st_board_info.bd_ops.board_power_on = mp12_board_power_on;
    g_st_board_info.bd_ops.board_power_off = mp12_board_power_off;
    g_st_board_info.bd_ops.susbsys_is_shutdown = mp12_susbsys_is_shutdown;
    g_st_board_info.bd_ops.power_state_change = mp12_power_state_change;
    g_st_board_info.bd_ops.board_power_reset = mp12_board_power_reset;
    g_st_board_info.bd_ops.board_power_notify = NULL;
    g_st_board_info.bd_ops.board_error_handler = NULL;
    g_st_board_info.bd_ops.bfgx_dev_power_on_post = mp12_bfgx_dev_power_on_post;
}

STATIC void board_get_gnss_dpe_switch(plat_cust_data_mp12 *cust)
{
    int32_t cfg_value;
    int32_t ret;

    cust->cfg.gnss_dpe_switch = 0;

    /* 获取ini的配置值 */
    ret = get_cust_conf_int32(INI_MODU_GNSS, INI_GNSS_DPE_SWICH, &cfg_value);
    if (ret == INI_FAILED) {
        return;
    }

    cust->cfg.gnss_dpe_switch = (uint32_t)cfg_value;
    ps_print_info("get gnss dpe switch =%d\n", cust->cfg.gnss_dpe_switch);
}

STATIC void board_get_sensorhub_enable(plat_cust_data_mp12 *cust)
{
    int32_t cfg_value;
    int32_t ret;

    cust->cfg.sensorhub_enable = OAL_TRUE;

    /* 获取ini的配置值 */
    ret = get_cust_conf_int32(INI_MODU_PLAT, "plat_sensorhub_enable", &cfg_value);
    if (ret == INI_FAILED) {
        return;
    }

    if ((cfg_value == OAL_FALSE) || (cfg_value == OAL_TRUE)) {
        cust->cfg.sensorhub_enable = cfg_value;
    }

    ps_print_info("get plat_sensorhub_enable =%d\n", cust->cfg.sensorhub_enable);
}

STATIC void board_get_slave_monitor(plat_cust_data_mp12 *cust)
{
    int32_t cfg_value;
    int32_t ret;

    cust->cfg.slave_monitor = OAL_FALSE;

    /* 获取ini的配置值 */
    ret = get_cust_conf_int32(INI_MODU_PLAT, "pcie_slave_monitor_switch", &cfg_value);
    if (ret == INI_FAILED) {
        return;
    }

    cust->cfg.slave_monitor = (uint32_t)cfg_value;
    ps_print_info("get slave_monitor =%d\n", cust->cfg.slave_monitor);
}

STATIC void board_get_gnss_xw_mode(plat_cust_data_mp12 *cust)
{
    int32_t cfg_value;
    int32_t ret;

    cust->cfg.gnss_xw_mode = 0;

    /* 获取ini的配置值 */
    ret = get_cust_conf_int32(INI_MODU_GNSS, INI_GNSS_XW_MODE, &cfg_value);
    if (ret == INI_FAILED) {
        ps_print_info("no xw mode ini\n");
        return;
    }

    cust->cfg.gnss_xw_mode = (uint8_t)cfg_value;
    ps_print_info("get gnss xw mode =%d\n", cust->cfg.gnss_xw_mode);
}

STATIC void board_get_pm_linkdown(plat_cust_data_mp12 *cust)
{
    int32_t cfg_value;
    int32_t ret;

    cust->cfg.pm_linkdown = OAL_FALSE;

    /* 获取ini的配置值 */
    ret = get_cust_conf_int32(INI_MODU_PLAT, "pcie_pm_linkdown_switch", &cfg_value);
    if (ret == INI_FAILED) {
        return;
    }

    cust->cfg.pm_linkdown = (uint8_t)cfg_value;
    ps_print_info("get pm_linkdown =%d\n", cust->cfg.pm_linkdown);
}

STATIC int32_t pin_config_get_product_id(uint8_t *name, uint32_t *id)
{
    uint32_t product_name_size;
    uint8_t *product_name = NULL;
    uint32_t loop;

    for (loop = 0; loop < oal_array_size(g_mp12_pin_cfg_map); loop++) {
        product_name_size = (uint32_t)(OAL_STRLEN(g_mp12_pin_cfg_map[loop].product_name) + 1);
        product_name = (uint8_t *)os_kzalloc_gfp(product_name_size);
        if (product_name == NULL) {
            return -ENOMEM;
        }

        if (!os_str_cmp(name, g_mp12_pin_cfg_map[loop].product_name)) {
            *id = (uint32_t)g_mp12_pin_cfg_map[loop].product_id;
            os_mem_kfree(product_name);
            return BOARD_SUCC;
        }
        os_mem_kfree(product_name);
    }
    return BOARD_FAIL;
}

STATIC void board_pin_config_init_mp12(void)
{
    struct device_node *np = NULL;
    uint32_t id;
    char* file_path = NULL;
    int32_t ret;
    uint32_t path_len;
    const char *name = NULL;

    ret = get_board_dts_node(&np, DTS_NODE_MPXX_WIFI);
    if (ret != BOARD_SUCC) {
        ps_print_err("DTS read node %s fail!!!\n", DTS_NODE_MPXX_WIFI);
        return;
    }

    if (!of_property_read_bool(np, DTS_PROP_MPXX_PIN_CONFIG_NAME)) {
        ps_print_info("pin_config_name node not exists! not support pin_cfg!\n");
        return;
    }

    /* 读取DTS中节点pin_config_name的名字 */
    ret = of_property_read_string(np, DTS_PROP_MPXX_PIN_CONFIG_NAME, &name);
    if (ret < 0) {
        ps_print_err("read pin_config_name fail!\n");
        return;
    }

    /* 根据pin_config_name匹配相关的product_id */
    ret = pin_config_get_product_id((uint8_t *)name, (uint32_t *)&id);
    if (ret != BOARD_SUCC) {
        ps_print_err("cannot find product id!\n");
        return;
    }
    ps_print_info("pin_config_name: %s, product_id: %x\n", name, id);

    path_len = (uint32_t)(OAL_STRLEN(FIRMWARE_MP12_ASIC_CFG_DIR) + sizeof(char) +
               OAL_STRLEN(CUSTOM_PIN_CONFIG_FILE_NAME) + 1);
    file_path = (uint8_t *)os_kzalloc_gfp(path_len);
    if (file_path == NULL) {
        return;
    }

    ret = sprintf_s(file_path, path_len, "%s/%s", FIRMWARE_MP12_ASIC_CFG_DIR, CUSTOM_PIN_CONFIG_FILE_NAME);
    ps_print_info("pin config file_path name: %s\n", file_path);

    /* 读取pin_cfg.bin中相对的pinmux配置 */
    ret = set_pin_config_buf(file_path, id);
    if (ret != SUCC) {
        ps_print_err("set pin config buf fail, ret = %x\n", ret);
    }
    os_mem_kfree(file_path);
}

STATIC void board_get_auto_cg_set(plat_cust_data_mp12 *cust)
{
    int32_t cfg_value;
    int32_t ret;

    cust->cfg.auto_cg = 0;

    /* 获取ini的配置值 */
    ret = get_cust_conf_int32(INI_MODU_PLAT, "auto_cg_switch", &cfg_value);
    if (ret == INI_FAILED) {
        ps_print_err("auto_cg_switch not find\n");
        return;
    }

    cust->cfg.auto_cg = (uint8_t)cfg_value;
    ps_print_info("get auto_cg =%d\n", cust->cfg.auto_cg);
}

STATIC void board_get_low_temp_protect_set(plat_cust_data_mp12 *cust)
{
#if defined(CONFIG_FACTORY_MODE) || defined(FACTORY_VERSION)
    cust->cfg.low_temp_protect_switch = 0; // 产测默认关闭低温保护
#else
    int32_t cfg_value;
    int32_t ret;

    cust->cfg.low_temp_protect_switch = 1; // 默认打开低温保护

    /* 获取ini的配置值 */
    ret = get_cust_conf_int32(INI_MODU_PLAT, "low_temp_protect_switch", &cfg_value);
    if (ret == INI_FAILED) {
        ps_print_info("low_temp_protect_switch not find\n");
        return;
    }

    cust->cfg.low_temp_protect_switch = (uint8_t)cfg_value;
#endif
    ps_print_info("get low_temp_protect_switch =%d\n", cust->cfg.low_temp_protect_switch);
}

STATIC void board_get_lp_eng_set(plat_cust_data_mp12 *cust)
{
    int32_t cfg_value;
    int32_t ret;

    cust->cfg.lp_eng_switch = 0;

    /* 获取ini的配置值 */
    ret = get_cust_conf_int32(INI_MODU_PLAT, "lp_eng_switch", &cfg_value);
    if (ret == INI_FAILED) {
        ps_print_info("lp_eng_switch not find\n");
        return;
    }

    cust->cfg.lp_eng_switch = (uint8_t)cfg_value;
    ps_print_info("get lp_eng_switch =%d\n", cust->cfg.lp_eng_switch);
}

STATIC void board_get_clk_32k_freq(plat_cust_data_mp12 *cust)
{
    int32_t cfg_value;
    int32_t ret;

    cust->cfg.clk_32k_freq = 32764500; // 默认设置32K时钟频率为32764500mhz(毫赫兹)

    /* 获取ini的配置值 */
    ret = get_cust_conf_int32(INI_MODU_PLAT, "clk_32k_freq", &cfg_value);
    if (ret == INI_FAILED) {
        return;
    }

    cust->cfg.clk_32k_freq = (uint32_t)cfg_value;

    ps_print_info("get clk_32k_freq =%u\n", cust->cfg.clk_32k_freq);
}

STATIC void board_plat_cust_init_mp12(void)
{
    int32_t ret;
    plat_cust_data_mp12 plat_cust;

    memset_s(&plat_cust, sizeof(plat_cust), 0, sizeof(plat_cust));
    plat_cust.cfg.release_version = (hi110x_get_release_type() == MPXX_VTYPE_RELEASE) ? OAL_TRUE : OAL_FALSE;

    board_get_gnss_dpe_switch(&plat_cust);
    board_get_pm_linkdown(&plat_cust);
    board_get_sensorhub_enable(&plat_cust);
    board_get_gnss_xw_mode(&plat_cust);
    board_get_slave_monitor(&plat_cust);
    board_get_auto_cg_set(&plat_cust);
    board_get_lp_eng_set(&plat_cust);
    board_get_clk_32k_freq(&plat_cust);
    board_get_low_temp_protect_set(&plat_cust);

    ret = set_plat_cust_buf((uint8_t *)&plat_cust, sizeof(plat_cust_data_mp12));
    if (ret != SUCC) {
        ps_print_err("set plat cust buf fail, ret = %d\n", ret);
        return;
    }
    ps_print_info("set plat cust buf succ, vtype=%d\n", hi110x_get_release_type());
}

#ifdef CONFIG_HI1102_PLAT_HW_CHR
static void chr_mp12_pmu_event_err_reg_info(uint8_t* report, uint16_t len)
{
    chr_inner_report_info *pmu_report = (chr_inner_report_info *)report;
    uint8_t* data = report + sizeof(chr_inner_report_info);
    if (len - sizeof(chr_inner_report_info) - 4 * sizeof(uint8_t) < 0) { /* 4: 携带4个数据据 */
        ps_print_err("%s mem overlap\n", __FUNCTION__);
        return;
    }
    chr_warning("[sys_id:0x%x]pmu_irq_err_reg_info: reg0_high_8bit[0x%x], reg0_low_8bit[0x%x], reg1_high_8bit[0x%x], "\
        // irq 0:存储pmu中断状态寄存器0 bit[15:8] 1:存储bit[7:0] 2:存储pmu中断状态寄存器1 bit[15:8] 3:存储bit[7:0]
        "reg1_low_8bit[0x%x]\n", pmu_report->module, data[0], data[1], data[2], data[3]);
    declare_dft_trace_key_info("pmu_error_report", OAL_DFT_TRACE_FAIL);
}
#endif

int32_t board_info_init_mp12(void)
{
    board_callback_init_dts();
    board_callback_init_mp12_power();
    board_clk_init(DET_NONE, CLK_INIT_INI);
    chip_firmware_cfg_register(g_mp12_cfg_str, oal_array_size(g_mp12_cfg_str));
    board_plat_cust_init_mp12();
#ifdef CONFIG_HI1102_PLAT_HW_CHR
    chr_cust_register(CHR_PLAT_INNER_ERROR_PMU_EVENT_REG_ERR, chr_mp12_pmu_event_err_reg_info);
#endif
    board_pin_config_init_mp12();
    return BOARD_SUCC;
}
