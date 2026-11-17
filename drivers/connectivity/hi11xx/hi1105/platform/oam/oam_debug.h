/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description:oam_log.c header file
 * Author: platform drivers
 */

#ifndef OAM_DEBUG_H
#define OAM_DEBUG_H
#include "oal_types.h"
#include "oal_kernel_file.h"
#include "oal_hcc_test_enhance.h"
#include "oal_hcc_host_if.h"

#define OAM_DEBUG_SUCCESS 0
#define OAM_DEBUG_FAILED 1
#define OAM_DEBUG_INPUT_ERROR 2
#define OAM_DEBUG_RW_BUSY      3
#define OAM_DEBUG_DATA_SEND_FAILED 4
#define OAM_DEBUG_DATA_SEND_TIMEOUT 5
#define OAM_DEBUG_BIT_SET_ERROR 6
#define OAM_DEBUG_GET_HCC_ERROR 7
#define OAM_DEBUG_ALLOC_MEM_ERROR 8
#define OAM_DEBUG_MEMCPY_ERROR 9
#define OAM_DEBUG_HCC_TX_ERROR 10
#define OAM_DEBUG_PARAM_BUF_ERROR 11
#define OAM_DEBUG_PRINT_BIT_ERROR 12

#define PS_REG_DATA_SIZE                21            /* 寄存器读写包size */
#define OAM_SUBSYS_NAME_SIZE            12

typedef enum {
    OAM_DBG_SUBSYS_WIFI = 0,
    OAM_DBG_SUBSYS_BT = 1,
    OAM_DBG_SUBSYS_SLE = 2,
    OAM_DBG_SUBSYS_IR = 3,
    OAM_DBG_SUBSYS_GNSS = 4,
    OAM_DBG_SUBSYS_GLP = 5,
    OAM_DBG_SUBSYS_BUTT
} plat_oam_dbg_subsys_t;

typedef uint8_t (*oam_dbg_uart_get_index_func_t)(plat_oam_dbg_subsys_t subsys_index);

/* 读写寄存器操作类型定义 */
typedef enum {
    OAM_DBG_REG_WRITE_32,
    OAM_DBG_REG_READ_32,
    OAM_DBG_REG_WRITE_16,
    OAM_DBG_REG_READ_16,
    OAM_DBG_REG_WRITE_BIT_MASK_32,
    OAM_DBG_REG_WRITE_BIT_MASK_16,
    OAM_DBG_REG_CLEAR_BIT_MASK_32,
    OAM_DBG_REG_CLEAR_BIT_MASK_16,
    OAM_DBG_REG_OPT_TYPE_BUTT
} oam_dbg_opt_type_t;

/* 读写寄存器结构体定义 */
typedef struct {
    uint8_t frame_start;
    uint8_t func_type;
    uint8_t prim_id;
    uint8_t reserved;
    uint16_t frame_len;
    uint16_t sn;
    uint32_t mem_addr;
    uint16_t mem_bit_width; // 寄存器读写位宽；2:16bit,4:32bit
    uint8_t mode;
    uint8_t off_load_core_mode;
    uint32_t data;
    uint8_t frame_end;
} ps_reg_data_info_t;

typedef struct {
    uint8_t subsys[OAM_SUBSYS_NAME_SIZE];
    uint32_t opt_type;
    uint32_t reg_addr;
    uint32_t reg_value;
    int32_t result;
    oal_completion readback_comp;
    oam_dbg_uart_get_index_func_t uart_index_func;
} oal_oam_dbg_item_t;

extern oal_oam_dbg_item_t g_oam_dbg_info;
extern oal_spin_lock_stru g_oam_dbg_info_lock;

ssize_t oam_dbg_send_data_to_device(uint8_t *subsys, uint32_t opt_type, uint32_t reg_addr, uint32_t reg_value);
void oam_dbg_readback_info_func(uint32_t reg_addr, uint32_t reg_value);
void oam_dbg_uart_get_index_callback_register(oam_dbg_uart_get_index_func_t func);
void oam_dbg_hcc_ack_handle(oal_netbuf_stru *pst_netbuf);
ssize_t oam_debug_data_value_print_bits(char *buf, int32_t count, void *data, uint32_t size);
bool oam_dbg_get_reg_func_enable(void);

#endif /* end of oam_debug.h */
