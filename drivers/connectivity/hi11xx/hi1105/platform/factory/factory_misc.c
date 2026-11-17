/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 *
 * Description: factory test
 * Author: platform drivers
 */

/* 头文件包含 */
#include "board_mp13.h"
#include "plat_firmware.h"
#include "plat_pm.h"

typedef struct {
    uint32_t gpio_base_addr;
    uint32_t dev2host_gpio_bit;
    uint32_t host2dev_gpio_bit;
    uint32_t output_dir_addr_offset;
    uint32_t output_value;
    uint32_t input_dir_addr_offset;
    uint32_t input_value;
    uint32_t set_addr_offset;
    uint32_t get_addr_offset;
    uint32_t clear_addr_offset;
} fac_wlan_gpio_info;

typedef struct {
    int32_t chip_type;
    uint32_t dev_ready_addr;
    fac_wlan_gpio_info wlan_gpio_info;
} fac_misc_info;

static fac_misc_info g_fac_misc_chip_tbl[] = {
    {BOARD_VERSION_MP13,  0x50000000, {0x50004000, BIT0,  BIT1,  0x04, 0x01, 0x04, 0x00, 0x00, 0x50, 0x00}},
    {BOARD_VERSION_MP15,  0x50000000, {0x50004000, BIT0,  BIT1,  0x04, 0x01, 0x04, 0x00, 0x00, 0x50, 0x00}},
    {BOARD_VERSION_MP16,  0x40000000, {0x40005000, BIT12, BIT13, 0x04, 0x01, 0x04, 0x00, 0x00, 0x50, 0x00}},
    {BOARD_VERSION_MP16C, 0x40000000, {0x40005000, BIT12, BIT13, 0x04, 0x01, 0x04, 0x00, 0x00, 0x50, 0x00}},
    {BOARD_VERSION_GF61,  0x40000000, {0x40005000, BIT12, BIT13, 0x04, 0x01, 0x04, 0x00, 0x00, 0x50, 0x00}},
    {BOARD_VERSION_MP17C, 0x04000000, {0x0400E000, BIT12, BIT13, 0x40, 0x01, 0x3C, 0x01, 0x30, 0x00, 0x34}},
    {BOARD_VERSION_MP12,  0x04000000, {0x0400E000, BIT1,  BIT0,  0x40, 0x01, 0x3C, 0x01, 0x30, 0x00, 0x34}},
    {BOARD_VERSION_MP17A, 0x04000000, {0x0400E000, BIT12, BIT13, 0x40, 0x01, 0x3C, 0x01, 0x30, 0x00, 0x34}},
};

extern int32_t g_ft_fail_powerdown_bypass;

OAL_STATIC fac_misc_info *get_fac_misc_info(void)
{
    uint16_t loop;
    int32_t chip_type = get_mpxx_subchip_type();
    for (loop = 0; loop < oal_array_size(g_fac_misc_chip_tbl); ++loop) {
        if (g_fac_misc_chip_tbl[loop].chip_type == chip_type) {
            return &g_fac_misc_chip_tbl[loop];
        }
    }

    return NULL;
}

int32_t factory_check_device_ready(void)
{
    uint16_t value;
    int32_t ret;
    uint32_t check_addr;
    fac_misc_info *misc_info = get_fac_misc_info();

    if (misc_info == NULL) {
        return -OAL_EFAIL;
    }

    check_addr = misc_info->dev_ready_addr;
    value = 0;

    ret = read_device_reg16(check_addr, &value);
    if (ret) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "read 0x%x reg failed, ret=%d", check_addr, ret);
        return -OAL_EFAIL;
    }

    /* 读到0x101表示成功 */
    if (value != 0x101) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "device sysctrl reg error, value=0x%x", value);
        return -OAL_EFAIL;
    }

    return OAL_SUCC;
}

OAL_STATIC int32_t factory_set_gpio_direction(uint32_t address, uint16_t gpio_bit, uint32_t gpio_bit_value)
{
    uint16_t value = 0;
    int32_t ret;
    uint8_t bit_idx;

    ret = read_device_reg16(address, &value);
    if (ret) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "read 0x%x reg failed, ret=%d", address, ret);
        return -OAL_EFAIL;
    }

    for (bit_idx = 0; bit_idx < NUM_16_BITS; ++bit_idx) {
        if (oal_get_bits(gpio_bit, 1, bit_idx)) {
            oal_write_bits(value, gpio_bit_value, 1, bit_idx);
        }
    }

    ret = write_device_reg16(address, value);
    if (ret) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "write 0x%x reg failed,value=0x%x, ret=%d", address, value, ret);
        return -OAL_EFAIL;
    }

    return OAL_SUCC;
}

OAL_STATIC int32_t factory_set_gpio_value(int32_t gpio, int32_t gpio_lvl, uint32_t address, uint16_t value)
{
    int32_t ret;

    ret = write_device_reg16(address, value);
    if (ret) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "write 0x%x reg failed,value=0x%x, ret=%d", address, value, ret);
        return -OAL_EFAIL;
    }

    oal_msleep(1);

    if (oal_gpio_get_value(gpio) != gpio_lvl) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "pull gpio to %d failed!", gpio_lvl);
        ssi_dump_gpio();
        return -OAL_EFAIL;
    }

    return OAL_SUCC;
}

OAL_STATIC int32_t factory_check_gpio_value(int32_t gpio, int32_t gpio_lvl, uint32_t address, uint16_t check_bit)
{
    uint16_t read;
    int32_t ret;

    gpio_direction_output(gpio, gpio_lvl);
    oal_msleep(1);

    read = 0;
    ret = read_device_reg16(address, &read);
    if (ret) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "read 0x%x reg failed, ret=%d", address, ret);
        return -OAL_EFAIL;
    }

    oal_print_mpxx_log(MPXX_LOG_DBG, "read 0x%x reg=0x%x", address, read);

    read &= check_bit;

    if (((gpio_lvl == GPIO_HIGHLEVEL) && (read == 0)) || ((gpio_lvl == GPIO_LOWLEVEL) && (read != 0))) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "pull gpio to %d failed!", gpio_lvl);
        ssi_dump_gpio();
        return -OAL_EFAIL;
    }

    return OAL_SUCC;
}

OAL_STATIC int32_t factory_check_wlan_wakeup_host(void)
{
    int32_t i;
    int32_t ret;
    int32_t gpio_num;
    const uint32_t ul_test_times = 2;
    uint32_t gpio_base_addr, gpio_set_addr, gpio_clr_addr, gpio_dir_addr;
    uint32_t gpio_bit;
    fac_misc_info *misc_info = get_fac_misc_info();

    if (misc_info == NULL) {
        return -OAL_EFAIL;
    }

    gpio_num = conn_get_gpio_number_by_type(W_WKUP_HOST);
    gpio_base_addr = misc_info->wlan_gpio_info.gpio_base_addr;
    gpio_set_addr = gpio_base_addr + misc_info->wlan_gpio_info.set_addr_offset;
    gpio_clr_addr = gpio_base_addr + misc_info->wlan_gpio_info.clear_addr_offset;
    gpio_dir_addr = gpio_base_addr + misc_info->wlan_gpio_info.output_dir_addr_offset;
    gpio_bit = misc_info->wlan_gpio_info.dev2host_gpio_bit;

    if (gpio_num == 0) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "wlan_wakeup_host gpio is zero!");
        return -OAL_EIO;
    }

    ret = factory_set_gpio_direction(gpio_dir_addr, gpio_bit, misc_info->wlan_gpio_info.output_value);
    if (ret < 0) {
        return ret;
    }

    for (i = 0; i < ul_test_times; i++) {
        ret = factory_set_gpio_value(gpio_num, GPIO_HIGHLEVEL, gpio_set_addr, gpio_bit);
        if (ret < 0) {
            return ret;
        }

        ret = factory_set_gpio_value(gpio_num, GPIO_LOWLEVEL, gpio_clr_addr, gpio_bit);
        if (ret < 0) {
            return ret;
        }

        oal_print_mpxx_log(MPXX_LOG_INFO, "check d2h wakeup io %d times ok", i + 1);
    }

    oal_print_mpxx_log(MPXX_LOG_INFO, "check d2h wakeup io done");
    return OAL_SUCC;
}

OAL_STATIC int32_t factory_check_host_wakeup_wlan(void)
{
    int32_t i;
    int32_t ret;
    int32_t gpio_num;
    const uint32_t ul_test_times = 2;
    uint32_t gpio_base_addr, gpio_get_addr, gpio_dir_addr;
    uint32_t gpio_bit;

    fac_misc_info *misc_info = get_fac_misc_info();

    if (misc_info == NULL) {
        return -OAL_EFAIL;
    }

    gpio_base_addr = misc_info->wlan_gpio_info.gpio_base_addr;
    gpio_get_addr = gpio_base_addr + misc_info->wlan_gpio_info.get_addr_offset;
    gpio_dir_addr = gpio_base_addr + misc_info->wlan_gpio_info.input_dir_addr_offset;
    gpio_bit = misc_info->wlan_gpio_info.host2dev_gpio_bit;
    gpio_num = conn_get_gpio_number_by_type(HOST_WKUP_W);
    if (gpio_num <= 0) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "host_wakeup_wlan gpio is zero!");
        return -OAL_EIO;
    }

    ret = factory_set_gpio_direction(gpio_dir_addr, gpio_bit, misc_info->wlan_gpio_info.input_value);
    if (ret < 0) {
        return ret;
    }

    for (i = 0; i < ul_test_times; i++) {
        ret = factory_check_gpio_value(gpio_num, GPIO_HIGHLEVEL, gpio_get_addr, gpio_bit);
        if (ret < 0) {
            return ret;
        }

        ret = factory_check_gpio_value(gpio_num, GPIO_LOWLEVEL, gpio_get_addr, gpio_bit);
        if (ret < 0) {
            return ret;
        }
        oal_print_mpxx_log(MPXX_LOG_INFO, "check h2d wakeup io %d times ok", i + 1);
    }

    oal_print_mpxx_log(MPXX_LOG_INFO, "check h2d wakeup io done");
    return 0;
}

OAL_STATIC int32_t factory_test_device_io(void)
{
    int32_t ret;
    struct wlan_pm_s *wlan_pm_info = wlan_pm_get_drv();
    if (wlan_pm_info == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "wlan_pm_info is NULL!");
        return -FAILURE;
    }

    hcc_bus_and_wake_lock(wlan_pm_info->pst_bus);
    /* power on wifi, need't download firmware */
    ret = board_power_on(W_SYS);
    if (ret) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "power on wlan failed=%d", ret);
        hcc_bus_and_wake_unlock(wlan_pm_info->pst_bus);
        return ret;
    }

    hcc_bus_power_action(hcc_get_bus(HCC_EP_WIFI_DEV), HCC_BUS_POWER_PATCH_LOAD_PREPARE);
    ret = hcc_bus_reinit(wlan_pm_info->pst_bus);
    if (ret != OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "reinit bus %d failed, ret=%d", wlan_pm_info->pst_bus->bus_type, ret);
        goto error;
    }

    wlan_pm_init_dev();

    ret = factory_check_device_ready();
    if (ret) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "check_device_ready failed, ret=%d", ret);
        goto error;
    }

    /* check io */
    ret = factory_check_host_wakeup_wlan();
    if (ret) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "check_host_wakeup_wlan failed, ret=%d", ret);
        goto error;
    }

    ret = factory_check_wlan_wakeup_host();
    if (ret) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "check_wlan_wakeup_host failed, ret=%d", ret);
        goto error;
    }

    hcc_bus_disable_state(hcc_get_bus(HCC_EP_WIFI_DEV), OAL_BUS_STATE_ALL);
    (void)board_power_off(W_SYS);
    hcc_bus_and_wake_unlock(wlan_pm_info->pst_bus);
    return OAL_SUCC;

error:
    if (!g_ft_fail_powerdown_bypass) {
        hcc_bus_disable_state(hcc_get_bus(HCC_EP_WIFI_DEV), OAL_BUS_STATE_ALL);
        (void)board_power_off(W_SYS);
    }
    hcc_bus_and_wake_unlock(wlan_pm_info->pst_bus);
    return ret;
}

int32_t factory_dev_io_test(void)        // GPIO测试接口
{
    int32_t ret;
    declare_time_cost_stru(cost);
    struct pm_top* pm_top_data = pm_get_top();

    if (oal_mutex_trylock(&pm_top_data->host_mutex) == 0) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "get lock fail!");
        return -EINVAL;
    }

    if (!bfgx_is_shutdown()) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "bfgx is open, test abort!");
        bfgx_print_subsys_state(BUART);
        oal_mutex_unlock(&pm_top_data->host_mutex);
        return -OAL_ENODEV;
    }

    if (!wlan_is_shutdown()) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "wlan is open, test abort!");
        oal_mutex_unlock(&pm_top_data->host_mutex);
        return -OAL_ENODEV;
    }

    oal_get_time_cost_start(cost);

    ret = factory_test_device_io();
    if (ret < 0) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dev io test fail!");
    }
    oal_get_time_cost_end(cost);
    oal_calc_time_cost_sub(cost);
    oal_print_mpxx_log(MPXX_LOG_INFO, "mp13 device io test cost %llu us", time_cost_var_sub(cost));

    oal_mutex_unlock(&pm_top_data->host_mutex);
    return ret;
}
EXPORT_SYMBOL(factory_dev_io_test);
