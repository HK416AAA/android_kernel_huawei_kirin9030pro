/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2018. All rights reserved.
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

/**
 * @brief   reset模块在acore上的对外头文件
 * @file    mdrv_reset.h
 * @version v1.0
 * @date    2024.12.23
 * @note    修改记录(版本号|修订日期|说明)
 * <ul><li>v1.0|2024.12.23|创建文件</li></ul>
 * @since   非融合版本
 */

#ifndef __MDRV_RESET_H__
#define __MDRV_RESET_H__

/**
 * @brief 单独复位回调阶段
 */
typedef enum {
    MDRV_RESET_CB_BEFORE, /**< 复位前的回调 */
    MDRV_RESET_CB_AFTER,  /**< 复位完成后的回调 */
    MDRV_RESET_RESETTING, /**< 复位过程中的回调 */
    MDRV_RESET_ESCAPE,    /**< 复位逃生时的回调 */
    MDRV_RESET_CB_INVALID,
} drv_reset_cb_moment_e;

/**
 * @brief 单独复位回调函数优先级
 * @par 描述: 单独复位回调执行顺序，单独复位前从小到大，单独复位后从大到小
 */
enum MDRV_RESET_CB_PIOR {
    MDRV_RESET_CB_PIOR_MIN = 0,
    MDRV_RESET_CB_PIOR_ICC = 0,
    MDRV_RESET_CB_PIOR_DPA = 2,
    MDRV_RESET_CB_PIOR_PFA = 3,
    MDRV_RESET_CB_PIOR_RNIC = 4,
    MDRV_RESET_CB_PIOR_USB = 5,
    MDRV_RESET_CB_PIOR_DRA = 6,
    MDRV_RESET_CB_PIOR_PFA_TFT = 7,
    MDRV_RESET_CB_PIOR_GMAC = 8,
    MDRV_RESET_CB_PIOR_IQI = 9,
    MDRV_RESET_CB_PIOR_SOUND = 10,
    MDRV_RESET_CB_PIOR_MPERF = 11,
    // MDRV_RESET_CB_PIOR_<组件名>
    // ...
    MDRV_RESET_CB_PIOR_CSHELL = 16,
    MDRV_RESET_CB_PIOR_RFILE,
    MDRV_RESET_CB_PIOR_PCIE_PM,
    MDRV_RESET_CB_PIOR_DUMPAP = 45,
    MDRV_RESET_CB_PIOR_DUMPCP = 46,
    MDRV_RESET_CB_PIOR_DUMPNR = 47,
    MDRV_RESET_CB_PIOR_DUMPM3 = 48,
    MDRV_RESET_CB_PIOR_DIAG = 49,
    MDRV_RESET_CB_PIOR_ONOFF = 50,
    MDRV_RESET_CB_PIOR_ALL = 51,

    MDRV_RESET_CB_PIOR_MAX
};

/**
 * @brief reset回调函数格式
 */
typedef int (*pdrv_reset_cbfun)(drv_reset_cb_moment_e enparam, int userdata);

/**
 * @brief 注册reset回调函数。
 *
 * @par 描述:
 * 向单独复位框架注册单独复位前、后阶段回调函数。
 * 单独复位前：停止业务、不访问Modem、IP进入idle状态。
 * 单独复位后：恢复与Modem之间交互。
 *
 * @attention
 * <ul><li> 回调函数建议不要有阻塞性操作，如果有阻塞性操作，一定要有超时保护（ms级别） </li></ul>
 *
 * @param[in]  pname 上层组件注册的名字，最长9个字符（不包括结束符），底软负责存储
 * @param[in]  pcbfun 回调函数指针
 * @param[in]  userdata 上层组件数据，在调用回调函数时，作为入参传给注册者
 * @param[in]  priolevel 回调函数调用优先级，参考emum MDRV_RESET_CB_PIOR定义
 *
 * @retval =0，表示注册成功。
 * @retval =1，表示注册失败。
 *
 * @par 依赖:
 * <ul><li>mdrv_reset.h：该接口声明所在的头文件。</li></ul>
 *
 * @see pdrv_reset_cbfun、MDRV_RESET_CB_PIOR
 */
int mdrv_reset_register_notify(const char *pname, pdrv_reset_cbfun pcbfun, int userdata, int priolevel);

#endif
