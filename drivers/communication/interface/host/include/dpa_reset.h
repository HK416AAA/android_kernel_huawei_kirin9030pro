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

#ifndef DPA_RESET_H
#define DPA_RESET_H

/**
 * @brief DPA单独复位特性的状态
 */
enum dpa_reset_feature_status {
    DPA_RESET_UNSUPPORT = 0,
    DPA_RESET_SUPPORT = 1
};
/**
 * @brief DPA单独复位是否在运行中的状态
 */
enum dpa_reset_status {
    DPA_RESET_NORMAL = 0,
    DPA_RESET_RESETING = 1
};
/**
 * @brief DPA单独复位执行结果
 */
enum dpa_reset_result {
    DPA_RESET_SUCCESS = 0,
    DPA_RESET_FAIL = 1
};
/**
 * @brief DPA复位回调阶段
 */
typedef enum {
    DPA_RESET_BEFORE, /**< 复位前的回调 */
    DPA_RESET_AFTER,  /**< 复位完成后的回调 */
    DPA_RESET_STAGE_MAX,
} dpa_reset_stage_e;

/**
 * @brief dpa reset回调函数类型
 */
typedef int (*dpa_reset_cb)(dpa_reset_stage_e enparam, int arg);

/**
 * @brief dpa reset回调执行LEVEL；决定复位执行顺序；
 *
 * @attention
 * <ul><li> 如果模块有依赖顺序需要在此处明确列出 </li></ul>
 * <ul><li> DPA_RESET_BEFORE阶段按照顺序执行；DPA_RESET_AFTER阶段按照倒序执行 </li></ul>
 *
 */
typedef enum {
    DPA_RESET_CB_LEVEL_BASE = 0,
    DPA_RESET_CB_LEVEL_APP = DPA_RESET_CB_LEVEL_BASE, /**< APP通知需要放在此处，其他模块放在这之后 */
    DPA_RESET_CB_LEVEL_COMMON, /**< 模块无依赖顺序的放置在LEVEL_COMMON */
    DPA_RESET_CB_LEVEL_STACK,
    DPA_RESET_CB_LEVEL_SMS_NIC,
    DPA_RESET_CB_LEVEL_SMS_GSO,
    DPA_RESET_CB_LEVEL_PFA,
    DPA_RESET_CB_LEVEL_DMI,
    DPA_RESET_CB_LEVEL_FIPC,
    DPA_RESET_CB_LEVEL_DRA,
    DPA_RESET_CB_LEVEL_TST, /**< 模块有依赖顺序的需要在此处明确指出 */
    DPA_RESET_CB_LEVEL_MAX
} dpa_reset_cb_level_e;

struct dpa_reset_ops {
    int (*bsp_dpa_reset_register_cb)(const char *name, dpa_reset_cb func, unsigned int arg, int prior);
};


/**
 * @brief 注册dpa reset内核API
 *
 * @par 描述:
 * 注册dpa reset内核API，注册后ops接口才能使用
 *
 * @retval -1, 表示注册失败
 * @retval 0，表示注册成功
 *
 * @par 依赖:
 * <ul><li>dpa_reset.h：该接口声明所在的头文件。</li></ul>
 */
int dpa_reset_api_register(struct dpa_reset_ops *reset_ops);

/**
 * @brief dpa 单独复位模块回调注册
 *
 * @par 描述:
 * dpa 单独复位模块回调注册,DPA host注册后使用，
 *
 * @param[in]  name 组件注册的名字，最长9个字符（不包括结束符）
 * @param[in]  func 回调函数指针
 * @param[in]  arg 组件数据，在调用回调函数时，作为入参传给注册者
 * @param[in]  prior 回调函数调用优先级，参考dpa_reset_cb_level_e定义，值越小优先级越高
 *
 * @retval =0，表示注册成功。
 * @retval !=0，-ENOSYS表示未提供注册接口，其他表示注册失败。
 *
 * @attention
 * <ul><li> NA </li></ul>
 *
 * @par 依赖:
 * <ul><li>bsp_reset.h：该接口声明所在的头文件。</li></ul>
 *
 */
int dpa_reset_register_cb_ops(const char *name, dpa_reset_cb func, unsigned int arg, int prior);

/**
 * @brief dpa 单独复位模块回调注册
 *
 * @par 描述:
 * dpa 单独复位模块回调注册
 *
 * @param[in]  name 组件注册的名字，最长9个字符（不包括结束符）
 * @param[in]  func 回调函数指针
 * @param[in]  arg 组件数据，在调用回调函数时，作为入参传给注册者
 * @param[in]  prior 回调函数调用优先级，参考dpa_reset_cb_level_e定义，值越小优先级越高
 *
 * @retval =0，表示注册成功。
 * @retval !=0，表示注册失败。
 *
 * @attention
 * <ul><li> NA </li></ul>
 *
 * @par 依赖:
 * <ul><li>bsp_reset.h：该接口声明所在的头文件。</li></ul>
 *
 */
int bsp_dpa_reset_register_cb(const char *name, dpa_reset_cb func, unsigned int arg, int prior);

/**
 * @brief 执行dpa单独复位
 *
 * @par 描述:
 * 执行dpa单独复位
 *
 *
 * @retval =0，表示复位成功。
 * @retval !=0，表示复位失败, 见enum dpa_reset_result。
 *
 * @attention
 * <ul><li> 该接口只能由dump模块调用，其它模块禁止调用 </li></ul>
 * <ul><li> 该接口down信号量，所以不能在中断中调用 </li></ul>
 *
 * @par 依赖:
 * <ul><li>bsp_reset.h：该接口声明所在的头文件。</li></ul>
 *
 */
int bsp_dpa_reset(void);

/**
 * @brief DPA单独复位特性是否打开
 *
 * @par 描述:
 * DPA单独复位特性是否打开
 *
 *
 * @retval 见enum dpa_reset_feature_status。
 *
 * @par 依赖:
 * <ul><li>bsp_reset.h：该接口声明所在的头文件。</li></ul>
 *
 */
enum dpa_reset_feature_status bsp_dpa_reset_is_feature_on(void);

/**
 * @brief DPA单独复位的运行状态
 *
 * @par 描述:
 * DPA单独复位的运行状态
 *
 *
 * @retval 见enum dpa_reset_status。
 *
 * @par 依赖:
 * <ul><li>bsp_reset.h：该接口声明所在的头文件。</li></ul>
 *
 */
enum dpa_reset_status bsp_reset_dpa_is_reboot(void);

/**
 * @brief 其他子系统单独复位DPA侧处理阶段
 */
enum dpa_sys_reset_ops_type {
    DPA_SYS_RESET_OPS_BEFORE_TYPE,
    DPA_SYS_RESET_OPS_AFTER_TYPE,
    DPA_SYS_RESET_OPS_TYPE_MAX
};

#ifdef CONFIG_DPA_MDM_RESET_AGENT
/**
 * @brief 其他子系统单独复位dpa侧处理接口
 *
 * @par 描述:
 * 其他子系统单独复位dpa侧处理接口
 *
 *
 * @retval 0：处理完成;其他：处理失败；
 *
 * @par 依赖:
 * <ul><li>dpa_reset.h：该接口声明所在的头文件。</li></ul>
 *
 */
int dpa_sys_reset(unsigned char sys_type, unsigned char ops_type);
#else
static inline int dpa_sys_reset(unsigned char sys_type, unsigned char ops_type)
{
    return 0;
}
#endif

#endif /*  DPA_RESET_H */
