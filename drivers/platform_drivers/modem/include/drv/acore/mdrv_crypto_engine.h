/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
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
 * @brief   crypto_engine模块在acore上的对外头文件
 * @file    mdrv_crypto_engine.h
 * @version v1.0
 * @date    2025.06.12
 * @note    修改记录(版本号|修订日期|说明)
 * <ul><li>v1.0|xxx.xx.xx|创建文件</li></ul>
 * @since
 */
#ifndef __MDRV_CRYPTO_ENGINE_H__
#define __MDRV_CRYPTO_ENGINE_H__

/**
 * @brief 频率档位 枚举类型，低频、常频、高频
 */
enum crypto_engine_freq_state {
    CRYPTO_ENGINE_FREQ_LOW = 0,
    CRYPTO_ENGINE_FREQ_MIDDLE = 1,
    CRYPTO_ENGINE_FREQ_HIGH = 2,
    CRYPTO_ENGINE_FREQ_MAX,
};

/**
 * @brief 设置加解密引擎频率接口
 * @par 描述:
 * 根据枚举类型设置频率
 *
 * @attention
 * <ul>
 * <li>state 需要设置的频率状态，支持的频率为低频/常频/高频, 具体频率与平台相关</li>
 * <li>业务完成后需要将频率调整为低频</li>
 * <li>当加解密业务完成后，需要将频率调整为低频，否则会增大系统功耗</li>
 * <li>如果没有业务，系统进入低功耗之前，需要调整频率为低频</li>
 * <li>在任务上下文调用</li>
 * </ul>
 * @param[in]  state, 需要设置的频率，见enum crypto_engine_freq_state
 *
 * @retval 0,表示函数执行成功
 * @retval !=0,表示函数执行失败
 */

int mdrv_crypto_engine_set_freq(enum crypto_engine_freq_state state);

#endif
