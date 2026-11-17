/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
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

#ifndef DPA_DUMP_H
#define DPA_DUMP_H

typedef void (*dump_hook)(void);


/**
 * @brief dpa_dump_bsp_dpa_dump_register_field接口申请维测内存使用的枚举
 *
 * @par 描述:
 * dpa_dump_bsp_dpa_dump_register_field接口申请维测内存使用的枚举, 枚举值需要与dpa_host中的定义保持一致
 */
typedef enum {
    /**< 10100000-101fffff modid划分给WLAN业务 */
    OM_DPAHOST_WLAN_FIELD_BEGIN = 0x10100000,
    OM_DPAHOST_WLAN_FIELD_END = 0x101fffff,
} dpa_om_filed_id_enum;

/**
 * @brief DPA HOST各组件复位modid, 用于system_error接口，若需新增modid, 请在此处添加,host和fw需保持一致
 */
typedef enum {
    /**< 其他组件的modid在此处分段添加 */
    WLAN_ERRNO_START = 0x10000,
    WLAN_ERRNO_DMI_EXCEP = 0x10001,
    WLAN_ERRNO_BUTT = 0x1ffff,
    NSTACK_ERRNO_START = 0x20000,
    NSTACK_ERRNO_BUTT = 0x2ffff,
    BOOSTER_ERRNO_START = 0x30000,
    BOOSTER_ERRNO_BUTT = 0x3ffff,
} dpa_om_errno_enum;

// 分支拼接兼容性要求，新增接口只允许向后添加，不允许插入和删除
struct dpa_dump_ops {
    void (*dpa_system_error)(unsigned int mod_id, unsigned int arg1, unsigned int arg2, char *arg3_virt_addr, unsigned int arg3_length);
    unsigned char *(*bsp_dpa_dump_register_field)(unsigned int field_id, const char *field_name, unsigned int length, unsigned short version);
    int (*bsp_dpa_dump_register_hook)(const char *name, dump_hook p_func);
};

/**
 * @brief 注册dpa dump内核API
 *
 * @par 描述:
 * 注册dpa dump内核API，注册后ops接口才能使用
 *
 * @retval <0, 表示注册失败
 * @retval 0，表示注册成功
 *
 * @par 依赖:
 * <ul><li>dpa_dump.h：该接口声明所在的头文件。</li></ul>
 */
int dpa_dump_api_register(const struct dpa_dump_ops *dump_ops);


/**
 * @brief 触发DPA子系统复位
 * @par 描述:
 * 让子系统进入复位，并生成复位日志；
 *
 * @retval -ENOSYS, 接口不存在
 * @retval 0，调用成功
 *
 * @attention
 * <ul><li> system_error接口本身不会返回错误，但如果dpa接口没有挂接，此时返回-ENOSYS </li></ul>
 * <ul><li> mod_id需要根据各个组件划分的范围填写，不可随意传入, @see dpa_om_errno_enum</li></ul>
 * @param[in]  mod_id , 异常错误码
 * @param[in]  arg1, 异常参数1
 * @param[in]  arg2, 异常参数2
 * @param[in]  arg3_virt_addr, 异常参数3的虚拟地址
 * @param[in]  arg3_length, 异常参数3长度
 *
 */
int dpa_dump_dpa_system_error_ops(unsigned int mod_id, unsigned int arg1, unsigned int arg2, char *arg3_virt_addr, unsigned int arg3_length);

/**
 * @brief 申请维测内存
 * @par 描述:
 * 申请维测内存，在维测内存中记录的日志可以随mimidump保存
 *
 * @attention
 * <ul><li> field_id需要严格按照给各个模块划分的传入 @see dpa_om_filed_id_enum</li></ul>
 * @param[in]  field_id , 维测空间的field
 * @param[in]  field_name, 维测空间的名称
 * @param[in]  length,  申请维测内存的长度
 * @param[in]  version, 维测内存的版本号，各组件自行定义，用于离线日志解析
 *
 * @retval NULL,申请空间失败, 可能是内存不足，或者接口不存在
 * @retval != NULL,申请空间成功，返回为该filedid分配的虚拟地址
 * @see enum om_filed_id_enum
 */
unsigned char *dpa_dump_register_field_ops(unsigned int field_id, const char *field_name, unsigned int length, unsigned short version);

/**
 * @brief 注册异常回调函数
 * @par 描述:
 * 异常后，会回调注册的回调函数，各个模块可以在回调中完成相应的动作,禁止在其中执行阻塞性操作
 * 若需要执行读写文件，sleep等会导致任务切换的操作，请使用dpa_dump_register_async_callback_ops接口(当前未对外封装，如有需要，请联系模块维护人)
 *
 * @param[in]  name , 异常回调名称
 * @param[in]  p_func , 回调函数的地址
 * @retval -1, 注册失败
 * @retval 其他注册回调成功
 */
int dpa_dump_register_hook_ops(const char *name, dump_hook p_func);

#endif /*  DPA_dump_H */
