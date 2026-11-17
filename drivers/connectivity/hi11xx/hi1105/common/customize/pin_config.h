/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: pin_config.c header file
 * Author: common drivers
 */

#ifndef PIN_CONFIG_H
#define PIN_CONFIG_H

#include "plat_type.h"

typedef union pin_cfg_data {
    uint32_t d32;
    struct  {
        uint32_t pin_mode     : 8;    /* 管脚模式 */
        uint32_t pin_ds       : 4;    /* 驱动能力 */
        uint32_t pin_pd       : 1;    /* 下拉 */
        uint32_t pin_pu       : 1;    /* 上拉 */
        uint32_t pin_ie       : 1;    /* 输入使能 */
        uint32_t pin_st       : 1;    /* 施密特状态 */
        uint32_t pin_index    : 10;   /* 管脚编号 */
        uint32_t reserved     : 5;    /* reserved */
        uint32_t pin_cfg_en   : 1;    /* 管脚配置使能 */
    } b;
} pin_cfg_data_t;

typedef struct pin_cfg_header {
    uint32_t head_magic;
    uint32_t crc;
    uint16_t pin_num;
    uint16_t pin_cfg_flag;
} pin_cfg_header_t;

typedef struct pin_cfg_image_info {
    uint32_t product_id;
    uint32_t addr;
    uint32_t load_addr;
    uint32_t length;
} pin_cfg_image_info_t;

typedef struct pin_cfg_package_header {
    uint32_t head_magic;
    uint32_t cfg_num;
    uint32_t offset;
    uint32_t length;
} pin_cfg_package_header_t;

typedef struct pin_cfg_map_info {
    uint32_t product_id;
    uint8_t *product_name;
} pin_cfg_map_info_t;

#define CUSTOM_PIN_CONFIG_FILE_NAME "pin_cfg.bin"
#define PACKAGE_HEADER_LEN          16
#define IMAGE_INFO_LEN              16
#define PACKAGE_HEAD_MAGIC          0x5A5A5A5A
/* product pin cfg name */
#define DTS_NAME_PHONE        "phone"
#define DTS_NAME_PC           "pc"

/*
 * pin cfg product id: 芯片对应的BOARD_VERSION(2B) + product index(2B)
 * 需要与芯片对应的product_id.json中的
 */
/*
 * mp12 product id: 0x00080001 ~ 0x0008FFFF
 */
#define BOARD_MP12_PRODUCT_ID_1     0x00080001      /* phone */
#define BOARD_MP12_PRODUCT_ID_2     0x00080002
#define BOARD_MP12_PRODUCT_ID_3     0x00080003

int32_t set_pin_config_buf(char *file_name, uint32_t id);
uint8_t *get_pin_config_buf_addr(void);
uint32_t get_pin_config_len(void);
uint32_t get_pin_config_load_addr(void);
int32_t pin_config_buff_is_set(void);
void pin_config_parameter_free(void);
#endif
