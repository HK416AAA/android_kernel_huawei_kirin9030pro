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

#if !defined(__PRODUCT_CONFIG_PS_PUB_H__)
#define __PRODUCT_CONFIG_PS_PUB_H__


#ifndef FEATURE_ON
#define FEATURE_ON 1
#endif


#ifndef FEATURE_OFF
#define FEATURE_OFF 0
#endif


#ifndef FEATURE_LTE
#define FEATURE_LTE FEATURE_ON
#endif


#ifndef FEATURE_UE_MODE_NR
#define FEATURE_UE_MODE_NR FEATURE_ON
#endif


#ifndef FEATURE_UE_MODE_XW2
#define FEATURE_UE_MODE_XW2 FEATURE_ON
#endif


#ifndef FEATURE_XW2_ONLY
#define FEATURE_XW2_ONLY FEATURE_OFF
#endif


#ifndef FEATURE_UE_MODE_TTS
#define FEATURE_UE_MODE_TTS FEATURE_ON
#endif


#ifndef FEATURE_WCBS
#define FEATURE_WCBS FEATURE_ON
#endif


#ifndef FEATURE_DCXO_SDIC02_SAMPLE_SHARE
#define FEATURE_DCXO_SDIC02_SAMPLE_SHARE FEATURE_OFF
#endif


#ifndef FEATURE_MULTI_MODEM
#define FEATURE_MULTI_MODEM FEATURE_ON
#endif


#ifndef FEATURE_RNIC_FUSION
#define FEATURE_RNIC_FUSION FEATURE_ON
#endif


#ifndef FEATURE_MODEM1_SUPPORT_WCDMA
#define FEATURE_MODEM1_SUPPORT_WCDMA FEATURE_ON
#endif


#ifndef FEATURE_PTM
#define FEATURE_PTM FEATURE_ON
#endif


#ifndef FEATURE_LTE_R15
#define FEATURE_LTE_R15 FEATURE_ON
#endif


#ifndef FEATURE_LTE_REDUCE_MEASURE_16AFRAN
#define FEATURE_LTE_REDUCE_MEASURE_16AFRAN FEATURE_ON
#endif


#ifndef FEATURE_LTE_JAM_DET
#define FEATURE_LTE_JAM_DET FEATURE_ON
#endif


#ifndef FEATURE_MODEM1_SUPPORT_LTE
#define FEATURE_MODEM1_SUPPORT_LTE FEATURE_ON
#endif


#ifndef NR_MAX_SERVING_CC_NUM
#define NR_MAX_SERVING_CC_NUM 4
#endif


#ifndef NR_MAX_UL_SERVING_CC_NUM
#define NR_MAX_UL_SERVING_CC_NUM 4
#endif


#ifndef NR_MAX_PER_BC_NR_BAND_NUM
#define NR_MAX_PER_BC_NR_BAND_NUM 4
#endif


#ifndef NR_MAX_CG_NUM
#define NR_MAX_CG_NUM 2
#endif


#ifndef NR_MAX_BAND_NUM
#define NR_MAX_BAND_NUM 32
#endif


#ifndef FEATURE_POS_SIB
#define FEATURE_POS_SIB FEATURE_OFF
#endif


#ifndef FEATURE_NR_LPP
#define FEATURE_NR_LPP FEATURE_ON
#endif


#ifndef FEATURE_NR_ECID
#define FEATURE_NR_ECID FEATURE_ON
#endif


#ifndef FEATURE_NR_DL_OTDOA
#define FEATURE_NR_DL_OTDOA FEATURE_OFF
#endif


#ifndef FEATURE_NR_DL_TDOA
#define FEATURE_NR_DL_TDOA FEATURE_OFF
#endif


#ifndef FEATURE_NR_MULTI_RTT
#define FEATURE_NR_MULTI_RTT FEATURE_OFF
#endif


#ifndef FEATURE_NR_DL_AOD
#define FEATURE_NR_DL_AOD FEATURE_OFF
#endif


#ifndef FEATURE_NR_R16
#define FEATURE_NR_R16 FEATURE_ON
#endif


#ifndef FEATURE_NR_R17
#define FEATURE_NR_R17 FEATURE_ON
#endif


#ifndef FEATURE_NR_R18
#define FEATURE_NR_R18 FEATURE_ON
#endif


#ifndef FEATURE_NR_R17_POWER_SAVING
#define FEATURE_NR_R17_POWER_SAVING FEATURE_ON
#endif


#ifndef FEATURE_NR_R17_REDCAP
#define FEATURE_NR_R17_REDCAP FEATURE_OFF
#endif


#ifndef FEATURE_NR_INTRA_UE_MULTIPLEXING
#define FEATURE_NR_INTRA_UE_MULTIPLEXING FEATURE_ON
#endif


#ifndef FEATURE_NR_SPS_HARQ_DEFERRAL
#define FEATURE_NR_SPS_HARQ_DEFERRAL FEATURE_ON
#endif


#ifndef FEATURE_NR_PUCCH_CELL_SWITCHING
#define FEATURE_NR_PUCCH_CELL_SWITCHING FEATURE_ON
#endif


#ifndef FEATURE_NR_FEMIMO
#define FEATURE_NR_FEMIMO FEATURE_ON
#endif


#ifndef FEATURE_NR_NONPMI
#define FEATURE_NR_NONPMI FEATURE_ON
#endif


#ifndef FEATURE_NR_MBS_BROADCAST
#define FEATURE_NR_MBS_BROADCAST FEATURE_ON
#endif


#ifndef FEATURE_NR_EMIMO
#define FEATURE_NR_EMIMO FEATURE_ON
#endif


#ifndef FEATURE_NR_URLLC
#define FEATURE_NR_URLLC FEATURE_OFF
#endif


#ifndef FEATURE_NR_ERACH
#define FEATURE_NR_ERACH FEATURE_OFF
#endif


#ifndef FEATURE_NR_UL_POS
#define FEATURE_NR_UL_POS FEATURE_ON
#endif


#ifndef FEATURE_NR_DAPS
#define FEATURE_NR_DAPS FEATURE_ON
#endif


#ifndef FEATURE_NR_U
#define FEATURE_NR_U FEATURE_OFF
#endif


#ifndef FEATURE_NR_CFG_GRANT_ENHANCE
#define FEATURE_NR_CFG_GRANT_ENHANCE FEATURE_ON
#endif


#ifndef FEATURE_NR_PUSCH_REPETITION
#define FEATURE_NR_PUSCH_REPETITION FEATURE_ON
#endif


#ifndef FEATURE_NR_ENHANCED_POWER_CTRL
#define FEATURE_NR_ENHANCED_POWER_CTRL FEATURE_OFF
#endif


#ifndef FEATURE_NR_SINGLE_DCI
#define FEATURE_NR_SINGLE_DCI FEATURE_ON
#endif


#ifndef FEATURE_NR_FSA
#define FEATURE_NR_FSA FEATURE_ON
#endif


#ifndef FEATURE_NR_COMPLEMENTARY_TDD
#define FEATURE_NR_COMPLEMENTARY_TDD FEATURE_OFF
#endif


#ifndef MULTI_MODEM_NUMBER
#define MULTI_MODEM_NUMBER 3
#endif


#ifndef FEATURE_IP_STACK
#define FEATURE_IP_STACK FEATURE_ON
#endif


#ifndef FEATURE_CRYPTO_ALGO
#define FEATURE_CRYPTO_ALGO FEATURE_ON
#endif


#ifndef NR_MAX_SRS_RES_SET_NUM
#define NR_MAX_SRS_RES_SET_NUM 4
#endif


#ifndef NR_MAX_SRS_RES_NUM
#define NR_MAX_SRS_RES_NUM 12
#endif


#ifndef NR_MAX_SRS_RES_NUM_PER_SET
#define NR_MAX_SRS_RES_NUM_PER_SET 4
#endif


#ifndef NR_MAX_SRS_POS_RES_SET_NUM
#define NR_MAX_SRS_POS_RES_SET_NUM 1
#endif


#ifndef NR_MAX_SRS_POS_RES_NUM
#define NR_MAX_SRS_POS_RES_NUM 2
#endif


#ifndef NR_MAX_SRS_POS_RES_NUM_PER_SET
#define NR_MAX_SRS_POS_RES_NUM_PER_SET 2
#endif


#ifndef NR_MAX_CSI_RPT_NUM
#define NR_MAX_CSI_RPT_NUM 48
#endif


#ifndef NR_MAX_CSI_SP_TRIG_STATE_NUM
#define NR_MAX_CSI_SP_TRIG_STATE_NUM 4
#endif


#ifndef NR_MAX_AP_NZP_CSI_RES_NUM_PER_SET
#define NR_MAX_AP_NZP_CSI_RES_NUM_PER_SET 8
#endif


#ifndef NR_MAX_CSI_AP_TRIG_STATE_NUM
#define NR_MAX_CSI_AP_TRIG_STATE_NUM 15
#endif


#ifndef NR_MAX_RPT_CFG_NUM_PER_TRIG
#define NR_MAX_RPT_CFG_NUM_PER_TRIG 10
#endif


#ifndef NR_MAX_PL_REF_RS_NUM
#define NR_MAX_PL_REF_RS_NUM 8
#endif


#ifndef NR_MAX_PUCCH_SPTL_RELATION_NUM
#define NR_MAX_PUCCH_SPTL_RELATION_NUM 8
#endif


#ifndef NR_MAX_CORESET_NUM
#define NR_MAX_CORESET_NUM 5
#endif


#ifndef NR_MAX_CFG_GRANT_NUM_ALL_CC
#define NR_MAX_CFG_GRANT_NUM_ALL_CC 1
#endif


#ifndef NR_MAX_CFG_GRANT_NUM_PER_BWP
#define NR_MAX_CFG_GRANT_NUM_PER_BWP 1
#endif


#ifndef NR_MAX_SPS_NUM_PER_BWP
#define NR_MAX_SPS_NUM_PER_BWP 1
#endif


#ifndef FEATURE_PERASN_OVER_16K
#define FEATURE_PERASN_OVER_16K FEATURE_OFF
#endif


#ifndef FEATURE_LPP
#define FEATURE_LPP FEATURE_ON
#endif


#ifndef PROTOL_STACK_ENG
#endif


#ifndef FEATRUE_PS_USER_LOG
#define FEATRUE_PS_USER_LOG FEATURE_ON
#endif


#ifndef FEATURE_PARALLEL_SRCH
#define FEATURE_PARALLEL_SRCH FEATURE_ON
#endif


#ifndef FEATURE_PARALLEL_SRCH_PROTECT
#define FEATURE_PARALLEL_SRCH_PROTECT FEATURE_OFF
#endif


#ifndef FEATURE_VOICE_MODULE_DEPLOY
#define FEATURE_VOICE_MODULE_DEPLOY FEATURE_ON
#endif


#ifndef FEATURE_CELL_SCAN
#define FEATURE_CELL_SCAN FEATURE_ON
#endif


#ifndef FEATURE_LTEV
#define FEATURE_LTEV FEATURE_ON
#endif


#ifndef FEATURE_PC5_DATA_CHANNEL
#define FEATURE_PC5_DATA_CHANNEL FEATURE_ON
#endif


#ifndef FEATURE_ASAN
#define FEATURE_ASAN FEATURE_OFF
#endif


#ifndef FEATURE_SPR
#define FEATURE_SPR FEATURE_ON
#endif


#ifndef FEATURE_MOVE_DOWN
#define FEATURE_MOVE_DOWN FEATURE_ON
#endif


#ifndef PS_GU_CMPNT_FEATURE
#define PS_GU_CMPNT_FEATURE FEATURE_OFF
#endif


#ifndef PS_NR_CMPNT_FEATURE
#define PS_NR_CMPNT_FEATURE FEATURE_OFF
#endif


#ifndef PS_LTE_SIDELINK_CMPNT_FEATURE
#define PS_LTE_SIDELINK_CMPNT_FEATURE FEATURE_OFF
#endif


#ifndef FEATURE_RADIO_TEST
#define FEATURE_RADIO_TEST FEATURE_OFF
#endif


#ifndef FEATURE_MBB_PRODUCT
#define FEATURE_MBB_PRODUCT FEATURE_OFF
#endif


#ifndef FEATURE_RCPT_CELL
#define FEATURE_RCPT_CELL FEATURE_ON
#endif


#ifndef FEATURE_NRPS_ITF_NEXT_GENERATION
#define FEATURE_NRPS_ITF_NEXT_GENERATION FEATURE_ON
#endif


#ifndef RRC_PINGPONG_PCELL_NODE_NUM
#define RRC_PINGPONG_PCELL_NODE_NUM 12
#endif


#ifndef FEATURE_MAXS
#define FEATURE_MAXS FEATURE_ON
#endif


#ifndef L2DLE_VERSION
#define L2DLE_VERSION 2
#endif


#ifndef L2DLE_SUB_VERSION
#define L2DLE_SUB_VERSION 10
#endif


#ifndef ULCIPHER_VERSION
#define ULCIPHER_VERSION 2
#endif


#ifndef ULCIPHER_SUB_VERSION
#define ULCIPHER_SUB_VERSION 10
#endif


#ifndef BBPSTU_VERSION
#define BBPSTU_VERSION 2
#endif


#ifndef BBPSTU_SUB_VERSION
#define BBPSTU_SUB_VERSION 10
#endif


#ifndef FEATURE_MOVE_DOWN_CONN_MEAS
#define FEATURE_MOVE_DOWN_CONN_MEAS FEATURE_ON
#endif


#ifndef FEATURE_SUPPORT_TLS
#define FEATURE_SUPPORT_TLS FEATURE_ON
#endif


#ifndef FEATURE_PUSH
#define FEATURE_PUSH FEATURE_ON
#endif


#ifndef PS_TTS_CMPNT_FEATURE
#define PS_TTS_CMPNT_FEATURE FEATURE_OFF
#endif


#ifndef FEATURE_UE_MODE_XW1
#define FEATURE_UE_MODE_XW1 FEATURE_ON
#endif


#ifndef FEATURE_BASTET
#define FEATURE_BASTET FEATURE_ON
#endif


#ifndef FEATURE_UE_MODE_XW1_ASN1VER3
#define FEATURE_UE_MODE_XW1_ASN1VER3 FEATURE_ON
#endif


#ifndef FEATURE_UE_MODE_XW1_ASN1VER4
#define FEATURE_UE_MODE_XW1_ASN1VER4 FEATURE_OFF
#endif

#endif /* __PRODUCT_CONFIG_H__ */
