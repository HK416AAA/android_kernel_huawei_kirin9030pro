/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 */
/**
 *  @brief   header files of dump
 *  @file    bsp_dump.h
 *  @author
 *  @version v1.0
 *  @date    2023.11.29
 *  @note    修改记录(版本号|修订日期|说明)
 *  v1.0|100.00.00|创建文件
 *  @since
 */
#ifndef __BSP_DUMP_H__
#define __BSP_DUMP_H__

#include "linux/types.h"
#include "bsp_om_enum.h"

typedef enum {
    DUMP_SAVE_DPA_DUMP = 0,
    DUMP_SAVE_RESET_LOG, /**< 1 */
    DUMP_SAVE_DPA_DUMP_BACKUP, /**< 2 */
    DUMP_SAVE_DPA_KO, /**< 3 */
    DUMP_SAVE_DPA_DTCM, /**< 4 */
    DUMP_SAVE_DPA_ITCM, /**< 5 */
    DUMP_SAVE_DPA_DDR, /**< 6 */
    DUMP_SAVE_HOST_KMSG, /**< 7 */
    DUMP_SAVE_DRA_CMA_MEM, /**< 8 */
    DUMP_SAVE_LOG_BUTT,
} dump_save_file_id_e;

typedef void (*dump_hook)(void);
typedef void (*save_hook)(const char *path);

/**
 * @brief 申请维测内存
 * @par 描述:
 * 申请维测内存，在维测内存中记录的日志可以随mimidump保存
 *
 * @attention
 * <ul><li> field_id需要严格按照给各个模块划分的传入</li></ul>
 * @param[in]  field_id , 维测空间的field
 * @param[in]  field_name, 维测空间的名称
 * @param[in]  length,  申请维测内存的长度
 * @param[in]  version, 维测内存的版本号
 *
 * @retval NULL,申请空间失败
 * @retval != NULL,申请空间成功，返回为该filedid分配的虚拟地址
 * @see enum om_filed_id_enum
 */
unsigned char *bsp_dpa_dump_register_field(unsigned int field_id, const char *field_name, unsigned int length, unsigned short version);

/**
 * @brief 查询指定fieldid对应的维测空间的虚拟地址
 * @par 描述:
 * 根据field id查询对应的field id的维测空间的虚拟地址
 *
 * @attention
 * <ul><li> field_id需要严格按照给各个模块划分的传入</li></ul>
 * @param[in]  field_id , 维测空间的field
 *
 * @retval NULL,查询地址失败
 * @retval != NULL,返回对应fieldid的虚拟地址
 * @par 依赖:
 * <ul><li>mdrv_om_get_field_phy_addr。</li></ul>
 * @see enum om_filed_id_enum
 */
unsigned char *bsp_dpa_dump_get_field_addr(unsigned int field_id);

/**
 * @brief 查询指定fieldid对应的维测空间的物理地址
 * @par 描述:
 * 根据field id查询对应的field id的维测空间的物理地址
 *
 * @attention
 * <ul><li> field_id需要严格按照给各个模块划分的传入</li></ul>
 * @param[in]  field_id , 维测空间的field
 *
 * @retval NULL,查询地址失败
 * @retval != NULL,返回对应fieldid的物理地址
 * @par 依赖:
 * <ul><li>bsp_dpa_dump_get_field_phy_addr。</li></ul>
 * @see enum om_filed_id_enum
 */
unsigned char *bsp_dpa_dump_get_field_phy_addr(unsigned int field_id);

/**
 * @brief 注册异常回调函数
 * @par 描述:
 * 异常后，会回调注册的回调函数，各个模块可以在回调中完成相应的动作,禁止在其中执行阻塞性操作
 * 若需要执行读写文件，sleep等会导致任务切换的操作，请使用bsp_dpa_dump_register_async_callback接口
 *
 * @param[in]  name , 异常回调名称
 * @param[in]  p_func , 回调函数的地址
 * @retval -1, 注册失败
 * @retval 其他注册回调成功
 */
int bsp_dpa_dump_register_hook(const char *name, dump_hook p_func);

enum dump_callback_subsys {
    DUMP_DPAHOST_CALLBACK = 0, /* 主要用于异步回调，在dpa host子系统完成后执行 */
    DUMP_DPAFW_CALLBACK, /* 主要用于异步回调，在dpa fw子系统完成或超时后执行 */
    DUMP_COMMON_CALLBACK, /* 主要用于异步回调，在所有子系统完成或超时之后执行 */
     /* DUMP_MODEM_AGENT_CALLBACK 主要用于异步回调，仅在modem异常需要DPA保存相关log时执行，注意DPA异常时不会执行该回调，
      *  并且此时DPA正在运行，该回调里也不要做阻塞DPA或者破坏性操作
      */
    DUMP_MODEM_AGENT_CALLBACK,
    DUMP_CALLBACK_BUTT,
};

#define DUMP_MOUDLE_CALLBACK_PRIO_LOWEST 49

/* @berif 注册dump异步回调接口
 * @par 描述:
 *      与dump_register_hook的区别在于，异步回调在任务上下文调用，若是PANIC这类异常，异步回调不会被调用
 * @param[in]  subsys, 回调归属于哪个子系统，例如如果归属于CP，那么在CP dump完成后就会被调用，不用等其他所有子系统完成
 * @param[in]  prio, 优先级，越低越好，最大不超过49，否则返回失败
 * @param[in]  func, 回调函数
 * @retval BSP_ERROR, 失败
 * @retval 其他值, 成功
 */
int bsp_dpa_dump_register_async_callback(enum dump_callback_subsys subsys, unsigned int prio, dump_hook func);

/* @berif 注册dump文件保存回调
 * @par 描述:
 *      异常后，如果需要将自己的数据保存为文件，则需要注册此回调，传入文件对应的枚举
 * @param[in]  id, 文件对应的枚举
 * @param[in]  func, 回调函数
 * @retval BSP_ERROR, 失败
 * @retval 其他值, 成功
 */
int bsp_dpa_dump_register_log_notifier(dump_save_file_id_e id, save_hook func);

/* @berif 将数据保存成文件
 * @par 描述:
 *      用于在bsp_dpa_dump_register_log_notifier接口注册的回调中，将自身数据写入文件的接口
 * @param[in]  dir, 目录名，需要以/结尾，如果保存到dump目录中间那个，可以直接传入save_hook回调中的目录
 * @param[in]  file_name, 文件名
 * @param[in]  address, 要保存的数据的虚拟地址，不能是ioremap的地址(要保证该地址能memcpy访问)
 * @param[in]  length, 要保存的数据的长度
 * @retval BSP_ERROR, 失败
 * @retval 其他值, 成功
 */
int bsp_dpa_dump_log_save(const char *dir, const char *file_name, const void *address, unsigned int length);

/**
 * @brief 触发DPA子系统复位
 * @par 描述:
 * 让子系统进入复位，并生成复位日志
 *
 * @attention
 * <ul><li> mod_id需要根据各个组件划分的范围填写，不可随意传入, @see bsp_om_enum.h 中的 om_errno_enum</li></ul>
 * @param[in]  mod_id , 异常错误码
 * @param[in]  arg1, 异常参数1
 * @param[in]  arg2, 异常参数2
 * @param[in]  arg3_virt_addr, 异常参数3的虚拟地址
 * @param[in]  arg3_length, 异常参数3长度
 *
 */
void dpa_system_error(unsigned int mod_id, unsigned int arg1, unsigned int arg2, char *arg3_virt_addr, unsigned int arg3_length);

#endif