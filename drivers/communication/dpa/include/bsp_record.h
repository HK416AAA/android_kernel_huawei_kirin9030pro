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
 *
 */

/**
 *  @brief   header files of record
 *  @file    bsp_record.h
 *  @author
 *  @version v1.0
 *  @date    2023.11.29
 *  @note    修改记录(版本号|修订日期|说明)
 *  v1.0|100.00.00|创建文件
 *  @since
 */
#ifndef __BSP_RECORD_H__
#define __BSP_RECORD_H__

#include <bsp_dpa_errno.h>

/**
* @brief modid
*/

/**
 * @brief record interfaces
 *
 * @par 描述:
 * 维测打点
 *
 * @attention
 * <ul><li>包含时间戳信息</li></ul>
 *
 * @param[in]  mod, id。
 * @param[in]  para0, 自定义信息。
 * @param[in]  para1, 自定义信息。
 * @param[in]  para2, 自定义信息。
 * @param[in]  para3, 自定义信息。
 * @param[out] 无
 *
 * @retval 0,无。
 * @retval ！=0,无。

 * @par 依赖:
 * <ul><li>bsp_print.h：该接口声明所在的头文件。</li></ul>
 */
void bsp_record(unsigned int mod, int para0, int para1, int para2, int para3);
void bsp_record_data(unsigned int mod, unsigned char *addr, unsigned char len);

// demo
enum {
    smod_hash,
};
#undef THIS_SUB_MODU
#define THIS_SUB_MODU smod_hash

#define bsp_dpa_record(para0, para1, para2, para3) \
    bsp_record(((THIS_MODU & BSP_MODE_MASK) << 8) | (THIS_SUB_MODU & 0xFF), (para0), (para1), (para2), (para3))
#define bsp_dpa_record_data(addr, len) \
    bsp_record_data(((THIS_MODU & BSP_MODE_MASK) << 8) | (THIS_SUB_MODU & 0xFF), (addr), (len))
#endif  /* __BSP_RECORD_H__ */
