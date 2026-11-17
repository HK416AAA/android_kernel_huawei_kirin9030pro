/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2025. All rights reserved.
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
 */

#ifndef _DPA_PROC_H_
#define _DPA_PROC_H_

#include <linux/remoteproc.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 描述dpa wakeup source 结构体名称
 */
struct dpa_wakeup_source;

struct dpa_nve {
    unsigned int wifi_boot;
    unsigned int modem_boot;
};

typedef enum {
    RUN_MODE_DPA = 0, /* 正常版本 */
    RUN_MODE_ACPU,   /* RECOVERY */
    RUN_MODE_INVALID
} boot_mode;

struct dpa_rproc_ops {
    int (*dpa_get_status)(void);
    struct dpa_wakeup_source *(*dpa_wakeup_source_register)(const char *name);
    int (*dpa_wakeup_source_unregister)(struct dpa_wakeup_source *ws);
    int (*dpa_pm_stay_awake)(struct dpa_wakeup_source *ws);
    int (*dpa_pm_stay_awake_with_autosuspend)(struct dpa_wakeup_source *ws, unsigned int msec);
    int (*dpa_pm_relax)(struct dpa_wakeup_source *ws);
};

/**
 * @brief WAN(Modem)是否走ACPU通道
 *
 * @par 描述:
 * WAN(Modem)是否走ACPU通,实现在内核侧，无需注册
 *
 * @retval true, 表示走ACPU通道
 * @retval false，表示默认走DPA通道
 *
 * @par 依赖:
 * <ul><li>dpa_rproc.h：该接口声明所在的头文件。</li></ul>
 */
bool dpa_wan_path_switch_acpu(void);

/**
 * @brief WAN(Modem)通路切换
 *
 * @par 描述:
 * WAN(Modem)切换通路,实现在内核侧，无需注册
 *
 * @param[in] value, 非0：切到通路2；0：恢复通路
 * 
 * @retval NA
 *
 * @par 依赖:
 * <ul><li>dpa_rproc.h：该接口声明所在的头文件。</li></ul>
 */
void dpa_wan_default_path_switch(uint32_t value);

/**
 * @brief WLAN(WiFi)是否走ACPU通道
 *
 * @par 描述:
 * WLAN(WiFi)是否走ACPU通,实现在内核侧，无需注册
 *
 * @retval true, 表示走ACPU通道
 * @retval false，表示默认走DPA通道
 *
 * @par 依赖:
 * <ul><li>dpa_rproc.h：该接口声明所在的头文件。</li></ul>
 */
bool dpa_wlan_path_switch_acpu(void);

/**
 * @brief WLAN(WiFi)通路切换
 *
 * @par 描述:
 * WLAN(WiFi)通路切换，实现在内核侧，无需注册
 * @param[in] value, 非0：切会ACPU；0：恢复通路
 * 
 * @retval NA
 *
 * @par 依赖:
 * <ul><li>dpa_rproc.h：该接口声明所在的头文件。</li></ul>
 */
void dpa_wlan_default_path_switch(uint32_t value);

/**
 * @brief 注册dpa rproc内核API
 *
 * @par 描述:
 * 注册dpa rproc内核API，注册后ops接口才能使用
 *
 * @retval -1, 表示注册失败
 * @retval 0，表示注册成功
 *
 * @par 依赖:
 * <ul><li>dpa_rproc.h：该接口声明所在的头文件。</li></ul>
 */
int bsp_dpa_register(struct dpa_rproc_ops *rproc_ops);

/**
 * @brief 获取DPA的状态，如果DPA的状态位
 *
 * @par 描述:
 * 获取DPA状态
 *
 * @retval -1, 表示DPA未使能，对应API接口未支持
 * @retval 其他，参考rproc_state定义。
 *
 * @par 依赖:
 * <ul><li>dpa_rproc.h：该接口声明所在的头文件。</li></ul>
 */
int dpa_get_status_ops(void);

 /**
 * @brief 向dws框架注册
 *
 * @par 描述:
 * 用户通过此接口注册到dws框架，并返回对应的ws句柄，需要DPA host注册后使用
 *
 * @param[in] name, 用户名称
 *
 * @retval 非NULL,注册成功
 * @retval NULL,注册失败或则API未提供
 *
 */
struct dpa_wakeup_source *dpa_wakeup_source_register_ops(const char *name);

 /**
 * @brief 向dws框架去注册
 *
 * @par 描述:
 * 用户通过此接口从dws框架去注册，需要DPA host注册后使用
 *
 * @param[in] ws, ws句柄
 *
 * 
 * @retval 0, 成功
 * @retval 非0, -ENOSYS, 对应API接口未注册；其他，失败
 *
 */
int dpa_wakeup_source_unregister_ops(struct dpa_wakeup_source *ws);

 /**
 * @brief 持有唤醒DPA锁
 *
 * @par 描述:
 * 用户通过此接口唤醒DPA，在无业务下需要主动释放唤醒票，和dpa_pm_relax_ops配对使用，需要DPA host注册后使用
 *
 * @attention
 * <ul><li>此接口为同步接口，会出现阻塞上下文的情况</li></ul>
 *
 * @param[in] ws, ws句柄
 *
 * @retval 0, 成功
 * @retval 非0, -ENOSYS, 对应API接口未注册；其他，失败
 *
 */
int dpa_pm_stay_awake_ops(struct dpa_wakeup_source *ws);

 /**
 * @brief 持有唤醒DPA锁并在设置时间后放锁
 *
 * @par 描述:
 * 用户通过此接口唤醒DPA，并按照用户设置时间放锁，需要DPA host注册后使用
 *
 * @attention
 * <ul><li>此接口为同步接口，会出现阻塞上下文的情况</li></ul>
 *
 * @param[in] ws, ws句柄
 * @param[in] msec, 超时放锁时间，单位ms
 *
 * @retval 0, 成功
 * @retval 非0, -ENOSYS, 对应API接口未注册；其他，失败
 *
 */
int dpa_pm_stay_awake_with_autosuspend_ops(struct dpa_wakeup_source *ws, unsigned int msec);

 /**
 * @brief 释放唤醒DPA锁
 *
 * @par 描述:
 * 用户通过此接口放唤醒DPA锁，释放前需要持有唤醒DPA锁，和dpa_pm_stay_awake_ops配对使用，需要DPA host注册后使用
 *
 * @param[in] ws, ws句柄
 *
 * @retval 0, 成功
 * @retval 非0, -ENOSYS, 对应API接口未注册；其他，失败
 *
 */
int dpa_pm_relax_ops(struct dpa_wakeup_source *ws);

#ifdef __cplusplus
}
#endif
#endif
