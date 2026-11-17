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

#if !defined(__PRODUCT_CONFIG_FESS_RF_H__)
#define __PRODUCT_CONFIG_FESS_RF_H__


#ifndef RFIC_BOARD_TYPE_FPGA
#define RFIC_BOARD_TYPE_FPGA 0
#endif


#ifndef RFIC_BOARD_TYPE_SFT
#define RFIC_BOARD_TYPE_SFT 1
#endif


#ifndef RFIC_BOARD_TYPE_ASIC
#define RFIC_BOARD_TYPE_ASIC 2
#endif


#ifndef RFIC_BOARD_TYPE_SDAT
#define RFIC_BOARD_TYPE_SDAT 3
#endif


#ifndef RFIC_BOARD_TYPE_EMU
#define RFIC_BOARD_TYPE_EMU 4
#endif


#ifndef RFIC_BOARD_TYPE
#define RFIC_BOARD_TYPE RFIC_BOARD_TYPE_EMU
#endif


#ifndef HI6365CS_ENABLED
#endif


#ifndef HI6355ES_ENABLED
#endif


#ifndef HI6336CS_ENABLED
#endif


#ifndef HI6366CS_ENABLED
#define HI6366CS_ENABLED
#endif


#ifndef HI6355V200_ENABLED
#endif


#ifndef HI6356_ENABLED
#define HI6356_ENABLED
#endif


#ifndef HI6356V200_ENABLED
#define HI6356V200_ENABLED
#endif


#ifndef HI6358_ENABLED
#define HI6358_ENABLED
#endif


#ifndef HI6371_ENABLED
#endif


#ifndef HI6358_RSIP_VERSION
#define HI6358_RSIP_VERSION 1
#endif


#ifndef HI6371_RSIP_VERSION
#define HI6371_RSIP_VERSION 1
#endif

#endif /* __PRODUCT_CONFIG_H__ */
