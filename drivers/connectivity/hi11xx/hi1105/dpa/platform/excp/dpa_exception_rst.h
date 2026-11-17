/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 *
 * Description: DPA异常处理头文件, 异常处理提交
 * Author: dpa drivers
 */

#ifndef DPA_EXCEPTION_RST_H
#define DPA_EXCEPTION_RST_H

/* DPA异常类型 */
enum exception_type_enum {
    EXCEPTION_TYPE_PLAT_PM = 0,
    EXCEPTION_TYPE_PLAT_PCIE = 1,
    EXCEPTION_TYPE_WIFI = 2,
    EXCEPTION_TYPE_ACPU_MSG = 3,
    EXCEPTION_TYPE_BOTTOM
};

/* DPA提交异常处理请求接口 */
int32_t dpa_exception_submit(uint32_t mod_id, uint8_t *buf, uint8_t buf_len);
/* DPA异常处理注册接口 */
int32_t dpa_exception_register(uint8_t *excep_id, mdrv_task_id task_id, uint32_t event);
/* DPA异常DFR发送接口 */
int32_t dpa_exception_handler(uint32_t excep_id);
/* DPA异常处理上电初始化 */
void exception_module_init(void);
void exception_module_deinit(void);
/* DPA异常处理初始化 */
void exception_open_init(void);

#endif
