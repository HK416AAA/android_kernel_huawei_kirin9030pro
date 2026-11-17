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

#if !defined(__PRODUCT_CONFIG_FESS_BB_H__)
#define __PRODUCT_CONFIG_FESS_BB_H__


#ifndef FESS_FEATURE_ENG_VERSION
#define FESS_FEATURE_ENG_VERSION FEATURE_OFF
#endif


#ifndef FEATURE_SUPPORT_HF
#define FEATURE_SUPPORT_HF FEATURE_OFF
#endif


#ifndef FEATURE_SUPPORT_LTEV
#define FEATURE_SUPPORT_LTEV FEATURE_ON
#endif


#ifndef FEATURE_SUPPORT_RFIC1
#define FEATURE_SUPPORT_RFIC1 FEATURE_OFF
#endif


#ifndef FEATURE_SUPPORT_SPT
#define FEATURE_SUPPORT_SPT FEATURE_OFF
#endif


#ifndef BBIC_PMA_VER
#define BBIC_PMA_VER 17101
#endif


#ifndef BBIC_PCS_VER
#define BBIC_PCS_VER 620
#endif


#ifndef BBIC_UART_VER
#define BBIC_UART_VER 5
#endif


#ifndef BBIC_INTERRUPT_VER
#define BBIC_INTERRUPT_VER 2
#endif


#ifndef BBIC_ALINK_VER
#define BBIC_ALINK_VER 2
#endif


#ifndef BBIC_CLK_VER
#define BBIC_CLK_VER 2
#endif


#ifndef BBIC_BBDBG_VER
#define BBIC_BBDBG_VER 3
#endif

#endif /* __PRODUCT_CONFIG_H__ */
