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

#ifndef _BSP_DPA_ERRNO_H_
#define _BSP_DPA_ERRNO_H_
/**
 *  @brief   header files of errno
 *  @file    bsp_dpa_errno.h
 *  @author
 *  @version v1.0
 *  @date    2023.11.29
 *  @note    修改记录(版本号|修订日期|说明)
 *  v1.0|100.00.00|创建文件
 *  @since
 */

#define BSP_MODE_MASK 0x7FFF

/**
* @brief drv错误码
*
* @par 使用方法:
 * <ul><li>在.c文件开始位置中定义THIS_MODU一级模块，THIS_SUB_MODE二级模块(可缺省)</li></ul>
 * <ul><li>在异常分支返回处调用 BSP_DPA_ERRNO_OS_GEN(errno)</li></ul>
 * <ul><li>示例：</li></ul>
 * <ul><li>#undef THIS_MODU</li></ul>
 * <ul><li>#define THIS_MODU mod_om</li></ul>
 * <ul><li>#undef THIS_SUB_MODU</li></ul>
 * <ul><li>#define THIS_SUB_MODU smod_wdt</li></ul>
 * <ul><li>#include <bsp_errno.h></li></ul>
 * <ul><li>#define om_errno 1</li></ul>
 * <ul><li>return BSP_DPA_ERRNO_OS_GEN(om_errno);</li></ul>
 *
 * @par 依赖:
 * <ul><li>THIS_MODU是一级模块，如mod_om，需要定义在bsp_errno.h中的bsp_modid_e</li></ul>
 *
* @par 描述:
 * <ul><li>THIS_SUB_MODU是二级模块，如smod_wdt，需要定义在自己模块的头文件中</li></ul>
 * <ul><li>错误码errno，需要定义在自己模块的头文件中，0-15是公共errno，不要使用</li></ul>
 * <ul><li>错误码各bit位定义</li></ul>
 * <ul><li>BIT: 31      27-16       15-8        0-7</li></ul>
 * <ul><li>DES: 符号位  一级模块名   二级模块名   错误码</li></ul>
  *<ul><li>MAX: 1       32766       255         255</li></ul>
* @attention
* <ul><li>此错误码为负数</li></ul>
*/
#undef THIS_SUB_MODU
#define THIS_SUB_MODU 0
#define BSP_DPA_ERRNO_OS_GEN(errno) (0x80000000 | ((THIS_MODU & BSP_MODE_MASK) << 16) | ((THIS_SUB_MODU & 0xFF) << 8) | ((errno)&0xFF))

/**
* @brief os错误码格式
*
* @par 使用方法:
 * <ul><li>与BSP_DPA_ERRNO_OS_GEN一致</li></ul>
 *
 * @par 依赖:
 * <ul><li>THIS_MODU是一级模块，如mod_om，需要定义在bsp_errno.h中的bsp_modid_e</li></ul>
 *
* @attention
* <ul><li>此错误码为负数</li></ul>
*/
#define BSP_DPA_ERRNO_OS_GEN(errno) (0x7FFFFFFF & BSP_DPA_ERRNO_OS_GEN(errno))
/**
* @brief modid
*/
enum bsp_modid_e {
    mod_dpa_os = 0,
    mod_dpa_om = 1,
    MAX_DPA_MODID = 0xFFFF, 
};
/**
* @brief common errno
*/
enum bsp_common_errno_e {
    SUCCESS = 0,    /**< 0 成功 */
    BSP_ENXIO = 1, /**< 1 No such device or address 没有那个设备或地址 */
    BSP_EACCES = 2, /**< 2 Permission denied 权限不够 */
    BSP_EBUSY = 3, /**< 3 Device or resource busy 设备或资源忙 */
    BSP_EINVAL = 4, /**< 4 Invalid argument 无效的参数 */
    BSP_ENOSPC = 5, /**< 5 No space left 没有空间 */
    BSP_ERANGE = 6, /**< 6 result notrepresentable  超出范围 */
    BSP_ENODATA = 7, /**< 7 No data available 没有可用的数据 */
    BSP_ECOMM = 8, /**< 8 Communication error 通讯错误 */
    BSP_EPROTO = 9, /**< 9 Protocol error 协议错误 */
    BSP_EBADMSG = 10, /**< 10 Not a data message 错误的消息 */
    BSP_EMSGSIZE = 11, /**< 11 Message too long 消息过长 */
    BSP_ECONNABORTED = 12, /**< 12 connection abort 连接断开 */
    BSP_ETIMEDOUT = 13, /**< 13 timed out 超时 */

    ERRNO_MAX = 15, /**< 15 common max*/
};
#endif