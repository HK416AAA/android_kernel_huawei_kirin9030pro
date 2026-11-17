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

#if !defined(__PRODUCT_CONFIG_PAM_H__)
#define __PRODUCT_CONFIG_PAM_H__


#ifndef FEATURE_ON
#define FEATURE_ON 1
#endif


#ifndef FEATURE_OFF
#define FEATURE_OFF 0
#endif


#ifndef FEATURE_VSIM
#define FEATURE_VSIM FEATURE_ON
#endif


#ifndef FEATURE_PHONE_USIM
#define FEATURE_PHONE_USIM FEATURE_ON
#endif


#ifndef FEATURE_SC_DTS_CFG
#define FEATURE_SC_DTS_CFG FEATURE_OFF
#endif


#ifndef FEATURE_SC_SHARE_PARTITION
#define FEATURE_SC_SHARE_PARTITION FEATURE_OFF
#endif


#ifndef FEATURE_PIN_CRYPTO_PROTECT
#define FEATURE_PIN_CRYPTO_PROTECT FEATURE_ON
#endif


#ifndef FEATURE_REDUCE_MEM
#define FEATURE_REDUCE_MEM FEATURE_OFF
#endif


#ifndef FEATURE_SINGLEMODEM_DUALSLOT
#define FEATURE_SINGLEMODEM_DUALSLOT FEATURE_OFF
#endif


#ifndef FEATURE_PAM_DSDA
#define FEATURE_PAM_DSDA FEATURE_OFF
#endif


#ifndef SIGNALING_PLANE_BIND_CORE_MASK
#define SIGNALING_PLANE_BIND_CORE_MASK 2
#endif


#ifndef PAM_CT_ENABLED
#endif


#ifndef PAM_HF_ENABLED
#endif


#ifndef PAM_BT_ENABLED
#endif


#ifndef MFG_PLATFORM
#define MFG_PLATFORM 3
#endif


#ifndef PAM_DYNAMIC_ENABLED
#define PAM_DYNAMIC_ENABLED FEATURE_ON
#endif


#ifndef FEATURE_BIP
#define FEATURE_BIP FEATURE_OFF
#endif


#ifndef FEATURE_MEP
#define FEATURE_MEP FEATURE_OFF
#endif

#endif /* __PRODUCT_CONFIG_H__ */
