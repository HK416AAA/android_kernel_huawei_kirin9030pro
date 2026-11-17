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

#if !defined(__PRODUCT_CONFIG_NRPS_H__)
#define __PRODUCT_CONFIG_NRPS_H__


#ifndef FEATURE_ON
#define FEATURE_ON 1
#endif


#ifndef FEATURE_OFF
#define FEATURE_OFF 0
#endif


#ifndef FEATURE_MLOG
#define FEATURE_MLOG FEATURE_OFF
#endif


#ifndef FEATURE_DT
#define FEATURE_DT FEATURE_ON
#endif


#ifndef FEATURE_NSSAI_AUTH
#define FEATURE_NSSAI_AUTH FEATURE_ON
#endif


#ifndef FEATURE_EAP_TLS_AUTH
#define FEATURE_EAP_TLS_AUTH FEATURE_OFF
#endif


#ifndef FEATURE_LADN
#define FEATURE_LADN FEATURE_ON
#endif


#ifndef NMAC_MAX_UL_ENTITY_NUM
#define NMAC_MAX_UL_ENTITY_NUM 4
#endif


#ifndef NLL2_MAX_CELL_NUM
#define NLL2_MAX_CELL_NUM 10
#endif


#ifndef NLL2_MAX_UL_CELL_NUM
#define NLL2_MAX_UL_CELL_NUM 4
#endif


#ifndef NLL2_MAX_UL_HARQ_NUM
#define NLL2_MAX_UL_HARQ_NUM 32
#endif


#ifndef NLL2_MAX_DL_HARQ_NUM
#define NLL2_MAX_DL_HARQ_NUM 32
#endif


#ifndef NLL2_MAX_UL_TB_NUM
#define NLL2_MAX_UL_TB_NUM 1
#endif


#ifndef NLL2_MAX_DL_TB_NUM
#define NLL2_MAX_DL_TB_NUM 2
#endif


#ifndef FEATURE_MODEM1_SUPPORT_NR
#define FEATURE_MODEM1_SUPPORT_NR FEATURE_ON
#endif


#ifndef FEATURE_N2N_AUTO_BGS
#define FEATURE_N2N_AUTO_BGS FEATURE_ON
#endif


#ifndef NR_MAX_PER_PLMN_NRSA_BC_NUM
#define NR_MAX_PER_PLMN_NRSA_BC_NUM 512
#endif


#ifndef NR_MAX_PER_PLMN_ENDC_BC_NUM
#define NR_MAX_PER_PLMN_ENDC_BC_NUM 2048
#endif


#ifndef NR_MAX_PER_PLMN_NRDC_BC_NUM
#define NR_MAX_PER_PLMN_NRDC_BC_NUM 1
#endif


#ifndef NR_MAX_PER_PLMN_TXSW_NRSA_BC_NUM
#define NR_MAX_PER_PLMN_TXSW_NRSA_BC_NUM 190
#endif


#ifndef NR_MAX_PER_PLMN_TXSW_ENDC_BC_NUM
#define NR_MAX_PER_PLMN_TXSW_ENDC_BC_NUM 1
#endif


#ifndef NR_MAX_PER_PLMN_DAPS_BC_NUM
#define NR_MAX_PER_PLMN_DAPS_BC_NUM 32
#endif


#ifndef NR_MAX_NRSA_BC_NUM
#define NR_MAX_NRSA_BC_NUM 512
#endif


#ifndef NR_MAX_NRSA_BC_NUM_MODEM1
#define NR_MAX_NRSA_BC_NUM_MODEM1 512
#endif


#ifndef NR_MAX_ENDC_BC_NUM
#define NR_MAX_ENDC_BC_NUM 2048
#endif


#ifndef NR_MAX_ENDC_BC_NUM_MODEM1
#define NR_MAX_ENDC_BC_NUM_MODEM1 2048
#endif


#ifndef NR_MAX_NRDC_BC_NUM
#define NR_MAX_NRDC_BC_NUM 1
#endif


#ifndef NR_MAX_NRDC_BC_NUM_MODEM1
#define NR_MAX_NRDC_BC_NUM_MODEM1 1
#endif


#ifndef NR_MAX_TXSW_NRSA_BC_NUM
#define NR_MAX_TXSW_NRSA_BC_NUM 190
#endif


#ifndef NR_MAX_TXSW_NRSA_BC_NUM_MODEM1
#define NR_MAX_TXSW_NRSA_BC_NUM_MODEM1 190
#endif


#ifndef NR_MAX_TXSW_ENDC_BC_NUM
#define NR_MAX_TXSW_ENDC_BC_NUM 1
#endif


#ifndef NR_MAX_TXSW_ENDC_BC_NUM_MODEM1
#define NR_MAX_TXSW_ENDC_BC_NUM_MODEM1 1
#endif


#ifndef NR_MAX_DAPS_BC_NUM
#define NR_MAX_DAPS_BC_NUM 32
#endif


#ifndef NR_MAX_DAPS_BC_NUM_MODEM1
#define NR_MAX_DAPS_BC_NUM_MODEM1 32
#endif


#ifndef NR_MAX_LTE_FSD_PARA_NUM
#define NR_MAX_LTE_FSD_PARA_NUM 256
#endif


#ifndef NR_MAX_LTE_FSU_PARA_NUM
#define NR_MAX_LTE_FSU_PARA_NUM 256
#endif


#ifndef NR_MAX_SIMPLE_FSC_NUM_PER_SUPER_FSC
#define NR_MAX_SIMPLE_FSC_NUM_PER_SUPER_FSC 16
#endif


#ifndef NRRC_MAX_CODEBOOK_VARIANTS_NUM
#define NRRC_MAX_CODEBOOK_VARIANTS_NUM 32
#endif


#ifndef NR_MAX_PER_BC_LTE_BAND_NUM
#define NR_MAX_PER_BC_LTE_BAND_NUM 5
#endif


#ifndef NR_MAX_PER_BAND_CC_NUM
#define NR_MAX_PER_BAND_CC_NUM 6
#endif


#ifndef NR_MAX_L2DLE_NRLC_ENTITY_NUM
#define NR_MAX_L2DLE_NRLC_ENTITY_NUM 32
#endif


#ifndef NR_MAX_L2DLE_PDCP_ENTITY_NUM
#define NR_MAX_L2DLE_PDCP_ENTITY_NUM 32
#endif


#ifndef NLL2_L2DLE_MAX_CC_NUM
#define NLL2_L2DLE_MAX_CC_NUM 5
#endif


#ifndef NLL2_DL_MAX_CB_PLANE_NUM
#define NLL2_DL_MAX_CB_PLANE_NUM 160
#endif


#ifndef NUP_CACHE_L2TCM_SIZE
#define NUP_CACHE_L2TCM_SIZE 0
#endif


#ifndef NUP_UNCACHE_UNBAK_L2TCM_SIZE
#define NUP_UNCACHE_UNBAK_L2TCM_SIZE 0
#endif


#ifndef NUP_UNCACHE_BAK_L2TCM_SIZE
#define NUP_UNCACHE_BAK_L2TCM_SIZE 0
#endif


#ifndef NR_MAX_CC_NUM_ALL_MODEM
#define NR_MAX_CC_NUM_ALL_MODEM 8
#endif


#ifndef NR_MAX_CG_NUM_ALL_MODEM
#define NR_MAX_CG_NUM_ALL_MODEM 4
#endif


#ifndef FEATURE_ENDC
#define FEATURE_ENDC FEATURE_ON
#endif


#ifndef FEATURE_CUST_OM
#define FEATURE_CUST_OM FEATURE_ON
#endif


#ifndef FEATURE_CAG
#define FEATURE_CAG FEATURE_OFF
#endif


#ifndef FEATURE_NR_CHO
#define FEATURE_NR_CHO FEATURE_ON
#endif


#ifndef FEATURE_NR_MDT
#define FEATURE_NR_MDT FEATURE_OFF
#endif


#ifndef FEATURE_NRDC
#define FEATURE_NRDC FEATURE_ON
#endif


#ifndef FEATURE_NR_RACS
#define FEATURE_NR_RACS FEATURE_OFF
#endif


#ifndef FEATURE_NR_USERLIST_SKIP_FREQ
#define FEATURE_NR_USERLIST_SKIP_FREQ FEATURE_ON
#endif


#ifndef FEATURE_NEDC
#define FEATURE_NEDC FEATURE_OFF
#endif


#ifndef FEATURE_NR_CLOUD
#define FEATURE_NR_CLOUD FEATURE_ON
#endif


#ifndef PFA_VERSION
#define PFA_VERSION 2
#endif


#ifndef PFA_SUB_VERSION
#define PFA_SUB_VERSION 0
#endif


#ifndef FEATURE_DIU_SUPPORT_PS_SECU
#define FEATURE_DIU_SUPPORT_PS_SECU FEATURE_ON
#endif


#ifndef FEATURE_DIU_KEY_EXT_SUPPORT
#define FEATURE_DIU_KEY_EXT_SUPPORT FEATURE_ON
#endif


#ifndef FEATURE_TSN
#define FEATURE_TSN FEATURE_OFF
#endif


#ifndef FEATURE_SUPPORT_MAC_ADDRESS_RANGE
#define FEATURE_SUPPORT_MAC_ADDRESS_RANGE FEATURE_OFF
#endif


#ifndef NUP_BUFF_MEM_TYPE
#define NUP_BUFF_MEM_TYPE 6
#endif


#ifndef NUP_L1DTCM_SIZE
#define NUP_L1DTCM_SIZE 106496
#endif


#ifndef FEATURE_SUPPORT_NLL2_MEMPOOL_OPT
#define FEATURE_SUPPORT_NLL2_MEMPOOL_OPT FEATURE_ON
#endif


#ifndef FEATURE_NPDCP_UL_PERFORMANCE
#define FEATURE_NPDCP_UL_PERFORMANCE FEATURE_OFF
#endif


#ifndef FEATURE_XW_BAND_SCAN
#define FEATURE_XW_BAND_SCAN FEATURE_OFF
#endif

#endif /* __PRODUCT_CONFIG_H__ */
