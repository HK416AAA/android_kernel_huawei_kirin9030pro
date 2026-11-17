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

#if !defined(__PRODUCT_CONFIG_GUCAS_H__)
#define __PRODUCT_CONFIG_GUCAS_H__


#ifndef FEATURE_ON
#define FEATURE_ON 1
#endif


#ifndef FEATURE_OFF
#define FEATURE_OFF 0
#endif


#ifndef FEATURE_NFEXT
#define FEATURE_NFEXT FEATURE_ON
#endif


#ifndef FEATURE_PPP
#define FEATURE_PPP FEATURE_OFF
#endif


#ifndef VISP_IMS_NIC_CNT
#define VISP_IMS_NIC_CNT 8
#endif


#ifndef FEATURE_DSDS
#define FEATURE_DSDS FEATURE_ON
#endif


#ifndef GAS_PTL_VER_PRE_R99
#define GAS_PTL_VER_PRE_R99 PS_PTL_VER_PRE_R99
#endif


#ifndef GAS_PTL_VER_R99
#define GAS_PTL_VER_R99 PS_PTL_VER_R99
#endif


#ifndef GAS_PTL_VER_R3
#define GAS_PTL_VER_R3 PS_PTL_VER_R3
#endif


#ifndef GAS_PTL_VER_R4
#define GAS_PTL_VER_R4 PS_PTL_VER_R4
#endif


#ifndef GAS_PTL_VER_R5
#define GAS_PTL_VER_R5 PS_PTL_VER_R5
#endif


#ifndef GAS_PTL_VER_R6
#define GAS_PTL_VER_R6 PS_PTL_VER_R6
#endif


#ifndef GAS_PTL_VER_R7
#define GAS_PTL_VER_R7 PS_PTL_VER_R7
#endif


#ifndef GAS_PTL_VER_R8
#define GAS_PTL_VER_R8 PS_PTL_VER_R8
#endif


#ifndef GAS_PTL_VER_R9
#define GAS_PTL_VER_R9 PS_PTL_VER_R9
#endif


#ifndef GAS_UE_REL_VER
#define GAS_UE_REL_VER GAS_PTL_VER_R9
#endif


#ifndef FEATURE_DL_E_CELL_FACH
#define FEATURE_DL_E_CELL_FACH FEATURE_OFF
#endif


#ifndef FEATURE_UL_E_CELL_FACH
#define FEATURE_UL_E_CELL_FACH FEATURE_OFF
#endif


#ifndef FEATURE_VAMOS
#define FEATURE_VAMOS FEATURE_OFF
#endif


#ifndef FEATURE_L2G_ANR
#define FEATURE_L2G_ANR FEATURE_ON
#endif


#ifndef FEATURE_L2W_ANR
#define FEATURE_L2W_ANR FEATURE_ON
#endif


#ifndef FEATURE_CPC
#define FEATURE_CPC FEATURE_ON
#endif


#ifndef FEATURE_E_FDPCH
#define FEATURE_E_FDPCH FEATURE_ON
#endif


#ifndef FEATURE_DPCH_SF512
#define FEATURE_DPCH_SF512 FEATURE_OFF
#endif


#ifndef FEATURE_UL_E_L2
#define FEATURE_UL_E_L2 FEATURE_OFF
#endif


#ifndef FEATURE_GAS_CSEL
#define FEATURE_GAS_CSEL FEATURE_OFF
#endif


#ifndef FEATURE_NON_SEQU_RCV
#define FEATURE_NON_SEQU_RCV FEATURE_ON
#endif


#ifndef FEATURE_GSM_FAKE_STATION_3
#define FEATURE_GSM_FAKE_STATION_3 FEATURE_ON
#endif


#ifndef FEATURE_HIGH_SPEED_SET_FREQUENCY_OFFSET
#define FEATURE_HIGH_SPEED_SET_FREQUENCY_OFFSET FEATURE_ON
#endif


#ifndef FEATURE_SENSOR_W2L_RESEL_PUNISH
#define FEATURE_SENSOR_W2L_RESEL_PUNISH FEATURE_ON
#endif


#ifndef FEATURE_SENSOR_FREQUENTLY_OOS_RESTRAIN
#define FEATURE_SENSOR_FREQUENTLY_OOS_RESTRAIN FEATURE_ON
#endif


#ifndef FEATURE_W2G_RESTRAIN
#define FEATURE_W2G_RESTRAIN FEATURE_ON
#endif


#ifndef FEATURE_FAKE_STATION
#define FEATURE_FAKE_STATION FEATURE_ON
#endif


#ifndef FEATURE_MAC_EHS
#define FEATURE_MAC_EHS FEATURE_ON
#endif

#endif /* __PRODUCT_CONFIG_H__ */
