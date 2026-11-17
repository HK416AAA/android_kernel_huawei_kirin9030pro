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

#if !defined(__PRODUCT_CONFIG_TLPS_H__)
#define __PRODUCT_CONFIG_TLPS_H__


#ifndef FEATURE_ON
#define FEATURE_ON 1
#endif


#ifndef FEATURE_OFF
#define FEATURE_OFF 0
#endif


#ifndef FEATURE_IMS
#define FEATURE_IMS FEATURE_ON
#endif


#ifndef FEATURE_LPP_ECID
#define FEATURE_LPP_ECID FEATURE_ON
#endif


#ifndef FEATURE_LPP_OTDOA
#define FEATURE_LPP_OTDOA FEATURE_OFF
#endif


#ifndef FEATURE_LPP_GNSS
#define FEATURE_LPP_GNSS FEATURE_ON
#endif


#ifndef FEATURE_LPP_EPDU
#define FEATURE_LPP_EPDU FEATURE_OFF
#endif


#ifndef FEATURE_LPP_SUPL
#define FEATURE_LPP_SUPL FEATURE_ON
#endif


#ifndef FEATURE_AUTO_ANALYSIS
#define FEATURE_AUTO_ANALYSIS FEATURE_ON
#endif


#ifndef FEATURE_LTE_ASN_CUT
#define FEATURE_LTE_ASN_CUT FEATURE_ON
#endif


#ifndef FEATURE_IMS_USSD
#define FEATURE_IMS_USSD FEATURE_ON
#endif


#ifndef FEATURE_IMS_SMS
#define FEATURE_IMS_SMS FEATURE_ON
#endif


#ifndef FEATURE_IMS_VOWIFI
#define FEATURE_IMS_VOWIFI FEATURE_ON
#endif


#ifndef FEATURE_IMS_URSP
#define FEATURE_IMS_URSP FEATURE_ON
#endif


#ifndef FEATURE_IMS_VIDEO
#define FEATURE_IMS_VIDEO FEATURE_ON
#endif


#ifndef FEATURE_IMS_RTT
#define FEATURE_IMS_RTT FEATURE_ON
#endif


#ifndef FEATURE_IMS_FUSIONCALL
#define FEATURE_IMS_FUSIONCALL FEATURE_ON
#endif


#ifndef FEATURE_IMS_PCSCF_UNAVAILABLE
#define FEATURE_IMS_PCSCF_UNAVAILABLE FEATURE_ON
#endif


#ifndef FEATURE_IMS_DC
#define FEATURE_IMS_DC FEATURE_ON
#endif


#ifndef FEATURE_LL2_SUPPORT_ROHC_PROFILE_6
#define FEATURE_LL2_SUPPORT_ROHC_PROFILE_6 FEATURE_ON
#endif


#ifndef FEATURE_LRRC_VOS_PRINT_CUT_DEFAULT_OFF
#define FEATURE_LRRC_VOS_PRINT_CUT_DEFAULT_OFF FEATURE_OFF
#endif


#ifndef FEATURE_PSUP_MEM_DEBUG
#define FEATURE_PSUP_MEM_DEBUG FEATURE_ON
#endif


#ifndef LTE_MAX_PER_CLOUD_CA_PLMN_NUM
#define LTE_MAX_PER_CLOUD_CA_PLMN_NUM 1536
#endif


#ifndef FEATURE_THROT_GCF
#define FEATURE_THROT_GCF FEATURE_ON
#endif


#ifndef FEATURE_THROT_T3585
#define FEATURE_THROT_T3585 FEATURE_ON
#endif


#ifndef FEATURE_THROT_BACKOFF
#define FEATURE_THROT_BACKOFF FEATURE_ON
#endif


#ifndef FEATURE_THROT_OTHERS
#define FEATURE_THROT_OTHERS FEATURE_ON
#endif


#ifndef FEATURE_APN_BASED_BO_TIMER_PARA_RPT
#define FEATURE_APN_BASED_BO_TIMER_PARA_RPT FEATURE_ON
#endif


#ifndef FEATURE_NSSAI_BASED_BO_TIMER_PARA_RPT
#define FEATURE_NSSAI_BASED_BO_TIMER_PARA_RPT FEATURE_ON
#endif


#ifndef FEATURE_LTE_R16
#define FEATURE_LTE_R16 FEATURE_ON
#endif


#ifndef FEATURE_CSS_CLOUD
#define FEATURE_CSS_CLOUD FEATURE_ON
#endif


#ifndef FEATURE_CSS_HISTORY_INFO_SHARE
#define FEATURE_CSS_HISTORY_INFO_SHARE FEATURE_ON
#endif


#ifndef FEATURE_CSS_SRCH
#define FEATURE_CSS_SRCH FEATURE_ON
#endif


#ifndef FEATURE_LTE_PWS_DECREASE
#define FEATURE_LTE_PWS_DECREASE FEATURE_OFF
#endif


#ifndef FEATURE_LTE_SI_DECREASE
#define FEATURE_LTE_SI_DECREASE FEATURE_OFF
#endif


#ifndef FEATURE_LTE_CA
#define FEATURE_LTE_CA FEATURE_ON
#endif


#ifndef FEATURE_LTE_EXT_VER
#define FEATURE_LTE_EXT_VER FEATURE_ON
#endif


#ifndef FEATURE_HPS
#define FEATURE_HPS FEATURE_ON
#endif


#ifndef FEATURE_IMS_MEM_DECREASE
#define FEATURE_IMS_MEM_DECREASE FEATURE_OFF
#endif


#ifndef FEATURE_REDISTRIBUTION
#define FEATURE_REDISTRIBUTION FEATURE_OFF
#endif


#ifndef PS_IMS_CMPNT_FEATURE
#define PS_IMS_CMPNT_FEATURE FEATURE_OFF
#endif


#ifndef FEATURE_DSDS_VERSION_7
#define FEATURE_DSDS_VERSION_7 FEATURE_ON
#endif


#ifndef FEATURE_IMS_DUMP_MAINTAIN
#define FEATURE_IMS_DUMP_MAINTAIN FEATURE_ON
#endif


#ifndef FEATURE_GPS_SENSOR_HUB
#define FEATURE_GPS_SENSOR_HUB FEATURE_OFF
#endif

#endif /* __PRODUCT_CONFIG_H__ */
