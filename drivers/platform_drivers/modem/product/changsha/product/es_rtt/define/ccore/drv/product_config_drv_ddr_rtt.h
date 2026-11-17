/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2021. All rights reserved.
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
 * * 3) Neither the name of ****** nor the names of its contributors may
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

#if !defined(__PRODUCT_CONFIG_DRV_DDR_RTT_H__)
#define __PRODUCT_CONFIG_DRV_DDR_RTT_H__


#ifndef DDR_MCORE_DTS_SIZE
#define DDR_MCORE_DTS_SIZE 0x100000
#endif


#ifndef DDR_RESERVED_SIZE
#define DDR_RESERVED_SIZE 0xC00000
#endif


#ifndef NPHY_HARQ_BUF_SIZE
#define NPHY_HARQ_BUF_SIZE 0x1C60000
#endif


#ifndef DDR_PDE_IMAGE_SIZE
#define DDR_PDE_IMAGE_SIZE 0x400000
#endif


#ifndef DDR_RFIC_IMAGE_SIZE
#define DDR_RFIC_IMAGE_SIZE 0x180000
#endif


#ifndef DDR_SHARED_SEC_SIZE
#define DDR_SHARED_SEC_SIZE 0x80000
#endif


#ifndef DDR_PSA_IMAGE_SIZE
#define DDR_PSA_IMAGE_SIZE 0x1000000
#endif


#ifndef DDR_MCORE_UNCACHE_SIZE
#define DDR_MCORE_UNCACHE_SIZE 0x1000000
#endif


#ifndef DDR_MCORE_DTS_ADDR
#define DDR_MCORE_DTS_ADDR 0xA7C00000
#endif


#ifndef DDR_RESERVED_ADDR
#define DDR_RESERVED_ADDR 0xA7D00000
#endif


#ifndef NPHY_HARQ_BUF_ADDR
#define NPHY_HARQ_BUF_ADDR 0xA8900000
#endif


#ifndef DDR_PDE_IMAGE_ADDR
#define DDR_PDE_IMAGE_ADDR 0xAA560000
#endif


#ifndef DDR_RFIC_IMAGE_ADDR
#define DDR_RFIC_IMAGE_ADDR 0xAA960000
#endif


#ifndef DDR_SHARED_SEC_ADDR
#define DDR_SHARED_SEC_ADDR 0xAAAE0000
#endif


#ifndef DDR_PSA_IMAGE_ADDR
#define DDR_PSA_IMAGE_ADDR 0xAAB60000
#endif


#ifndef DDR_MCORE_UNCACHE_ADDR
#define DDR_MCORE_UNCACHE_ADDR 0xABB60000
#endif


#ifndef DDR_MEM_LAYOUT_SIZE
#define DDR_MEM_LAYOUT_SIZE 0x1000
#endif


#ifndef DDR_SHARED_NSRO_SIZE
#define DDR_SHARED_NSRO_SIZE 0x00D7F000
#endif


#ifndef DDR_MCU_SIZE
#define DDR_MCU_SIZE 0x00080000
#endif


#ifndef DDR_SHARED_UNSEC_SIZE
#define DDR_SHARED_UNSEC_SIZE 0x001C0000
#endif


#ifndef DDR_EARLY_LOG_SIZE
#define DDR_EARLY_LOG_SIZE 0x00040000
#endif


#ifndef DDR_MNTN_SIZE
#define DDR_MNTN_SIZE 0x00400000
#endif


#ifndef DDR_MEM_LAYOUT_ADDR
#define DDR_MEM_LAYOUT_ADDR 0x1E000000
#endif


#ifndef DDR_SHARED_NSRO_ADDR
#define DDR_SHARED_NSRO_ADDR 0x1E001000
#endif


#ifndef DDR_MCU_ADDR
#define DDR_MCU_ADDR 0x1ED80000
#endif


#ifndef DDR_SHARED_UNSEC_ADDR
#define DDR_SHARED_UNSEC_ADDR 0x1EE00000
#endif


#ifndef DDR_EARLY_LOG_ADDR
#define DDR_EARLY_LOG_ADDR 0x1EFC0000
#endif


#ifndef DDR_MNTN_ADDR
#define DDR_MNTN_ADDR 0x1F000000
#endif


#ifndef DDR_ODT_SIZE
#define DDR_ODT_SIZE 0x4000000
#endif


#ifndef ODT_RTT_REG_SIZE
#define ODT_RTT_REG_SIZE 0x2000
#endif


#ifndef DDR_TRACE_SIZE
#define DDR_TRACE_SIZE 0xA00000
#endif


#ifndef DDR_L2DLE_SIZE
#define DDR_L2DLE_SIZE 0x80000
#endif


#ifndef DDR_ODT_ADDR
#define DDR_ODT_ADDR 0xB0F80000
#endif


#ifndef ODT_RTT_REG_ADDR
#define ODT_RTT_REG_ADDR 0xB4F80000
#endif


#ifndef DDR_TRACE_ADDR
#define DDR_TRACE_ADDR 0xB4F82000
#endif


#ifndef DDR_L2DLE_ADDR
#define DDR_L2DLE_ADDR 0xB5982000
#endif

#endif /* __PRODUCT_CONFIG_H__ */
