/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Header file of board pm
 * Author: dpa drivers
 */

#ifndef BOARD_PM_H
#define BOARD_PM_H

#include <stdint.h>
#include "oal_schedule.h"
#include "conn_dmi_msg.h"

typedef union {
    struct {
        uint64_t bar_addr;
        uint32_t bar_size;
        uint16_t pcie_dev_id;
        uint8_t in_excep_flag;      // 0: device探测成功  1: 异常情况下, device探测失败
        uint8_t reserve_1;
        int32_t subchip_type;
        uint8_t reserve[12];        // 预留12字节
    } cfg;
    uint8_t data[CONN_DMI_MSG_DATA_LEN];
} powerup_res_sync_stru;

/* dev define */
typedef enum {
    HCC_EP_WIFI_DEV = 0,
    HCC_EP_GT_DEV,

    HCC_CHIP_MAX_DEV
} hcc_chip_dev;

enum hisi_device_board {
    /* mpxx 项目使用 0 ~ 999 */
    BOARD_VERSION_MP13 = 1,
    BOARD_VERSION_MP15 = 3,
    BOARD_VERSION_MP16 = 4,
    BOARD_VERSION_MP16C = 5,
    BOARD_VERSION_GF61 = 6,
    BOARD_VERSION_MP17C = 7,
    BOARD_VERSION_MP12 = 8,
    BOARD_VERSION_MP17A = 9,
    BOARD_VERSION_MPXX_BUTT,
};

int32_t powerup_process(uint8_t *buf, uint16_t buf_len);
int32_t shutdown_process(uint8_t *buf, uint16_t buf_len);
int32_t dpa_open_top(uint8_t *buf, uint16_t buf_len);
int32_t dpa_open_bottom(uint8_t *buf, uint16_t buf_len);
int32_t dpa_close(uint8_t *buf, uint16_t buf_len);
int32_t wifi_ready_process(uint8_t *buf, uint16_t buf_len);
void board_pm_init(void);
void dpe_dmi_register(void);
int32_t get_mpxx_subchip_type(void);
int32_t dpa_in_excepion_reset(void);
#endif