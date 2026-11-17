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
#ifndef __BSP_NMI_H
#define __BSP_NMI_H


#ifdef __cplusplus
extern "C" {
#endif

#define NMI_TRIGGER_TAG (0xFFFFFFF0)

/* 优先级高的先处理，优先级数字越小越高 */
typedef enum _dpa_nmi_num {
    DPA_NMI_RESET = 0,
    DPA_NMI_DUMP,
    DPA_NMI_SEC_DUMP,
    DPA_NMI_DPA_SAMPLER,
    DPA_NMI_TEST,
    DPA_NMI_MAX
} dpa_nmi_num;

enum nmi_handler_return_value {
    NMI_RETURN_RUNNING = 0,             /* NMI钩子退出后，系统继续运行 */
    NMI_ENTER_LOOP_1_NO_RETRUN = 1,     /* NMI钩子退出后，系统进行死循环，不响应NMI */
    NMI_ENTER_WFE_NO_RETRUN = 2,        /* NMI钩子退出后，系统进入WFE循环，响应NMI */
    NMI_ENTER_WFE_DISABLE_NMI_NO_RETRUN /* NMI钩子退出后，系统进入WFE循环，不再响应NMI */
};

/**
 * @brief 触发DPA的NMI
 *
 * @par 描述:
 * 触发DPA的NMI
 *
 * @param[in] nmi_id, 用户申请的NMI ID,该nmi_id需要与DPA firmware上申请的nmi_id一致
 *
 * @retval 0 触发成功；其他，返回失败；
 *
 * @attention
 * <ul><li> nmi_id需要与DPA firmware中申请的nmi_id一致 </li></ul>
 * <ul><li> 接口中有延时操作用于check DPA上响应的情况 </li></ul>
 *
 * @par 依赖:
 * <ul><li>bsp_nmi.h：该接口声明所在的头文件。</li></ul>
 *
 * @see bsp_send_dpa_nmi
 */
int bsp_send_dpa_nmi(dpa_nmi_num nmi_id);

/**
 * @brief 触发DPA指定线程上的NMI
 *
 * @par 描述:
 * 触发DPA指定线程上的NMI
 *
 * @param[in] core_mask, 需要触发的DPA的逻辑线程core_mask，例如,0x3，代表触发DPA逻辑线程0\1上的NMI
 * @param[in] nmi_id, 用户申请的NMI ID,该nmi_id需要与DPA firmware上申请的nmi_id一致
 *
 * @retval 0 触发成功；其他，返回失败；
 *
 * @attention
 * <ul><li> nmi_id需要与DPA firmware中申请的nmi_id一致 </li></ul>
 *
 * @par 依赖:
 * <ul><li>bsp_nmi.h：该接口声明所在的头文件。</li></ul>
 *
 * @see bsp_dpa_reset_register_host_idle
 */
int bsp_dpa_nmi_trigger(unsigned int core_mask, dpa_nmi_num nmi_id);

/**
 * @brief 清除DPA上的NMI触发源
 *
 * @par 描述:
 * 清除DPA上的NMI触发源
 *
 * @param[in] 无
 *
 * @retval 0 清除成功；其他，返回失败；
 *
 * @par 依赖:
 * <ul><li>bsp_nmi.h：该接口声明所在的头文件。</li></ul>
 *
 */
int bsp_nmi_clear(void);

#ifdef __cplusplus /* __cplusplus */
}
#endif /* __cplusplus */
#endif
