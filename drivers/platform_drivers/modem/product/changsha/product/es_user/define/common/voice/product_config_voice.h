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

#if !defined(__PRODUCT_CONFIG_VOICE_H__)
#define __PRODUCT_CONFIG_VOICE_H__


#ifndef FEATURE_ON
#define FEATURE_ON 1
#endif


#ifndef FEATURE_OFF
#define FEATURE_OFF 0
#endif


#ifndef FEATURE_JSCD
#define FEATURE_JSCD FEATURE_ON
#endif


#ifndef FEATURE_TTY
#define FEATURE_TTY FEATURE_OFF
#endif


#ifndef FEATURE_ECALL
#define FEATURE_ECALL FEATURE_OFF
#endif


#ifndef FEATURE_AMR_SPLC
#define FEATURE_AMR_SPLC FEATURE_ON
#endif


#ifndef FEATURE_EFR_SPLC
#define FEATURE_EFR_SPLC FEATURE_ON
#endif


#ifndef FEATURE_DUAL_FLOW
#define FEATURE_DUAL_FLOW FEATURE_ON
#endif


#ifndef FEATURE_DTMF_ELIMINATE
#define FEATURE_DTMF_ELIMINATE FEATURE_OFF
#endif


#ifndef FEATURE_AUDIO
#define FEATURE_AUDIO FEATURE_OFF
#endif


#ifndef FEATURE_FAULT_INJECT
#define FEATURE_FAULT_INJECT FEATURE_OFF
#endif


#ifndef FEATURE_MBB_MODULE_AUDIO
#define FEATURE_MBB_MODULE_AUDIO FEATURE_OFF
#endif


#ifndef FEATURE_MOS_INJECT
#define FEATURE_MOS_INJECT FEATURE_OFF
#endif


#ifndef FEATURE_REMOTE_CALL
#define FEATURE_REMOTE_CALL FEATURE_OFF
#endif


#ifndef FEATURE_AMRWB_SPLC
#define FEATURE_AMRWB_SPLC FEATURE_ON
#endif


#ifndef FEATURE_AMRWB_IO_SUPPORT
#define FEATURE_AMRWB_IO_SUPPORT FEATURE_ON
#endif


#ifndef FEATURE_PS_VOICE_CMPNT_FEATURE
#define FEATURE_PS_VOICE_CMPNT_FEATURE FEATURE_OFF
#endif


#ifndef VOICE_NORMAL_TASK_COREMASK
#define VOICE_NORMAL_TASK_COREMASK 2
#endif


#ifndef FEATURE_EVS_SUPPORT
#define FEATURE_EVS_SUPPORT FEATURE_ON
#endif


#ifndef FEATURE_VOICE_STREAM
#define FEATURE_VOICE_STREAM FEATURE_OFF
#endif


#ifndef FEATURE_MODEM_LOOP
#define FEATURE_MODEM_LOOP FEATURE_OFF
#endif


#ifndef FEATURE_AI_CODEC_SUPPORT
#define FEATURE_AI_CODEC_SUPPORT FEATURE_ON
#endif


#ifndef VOICE_L1DTCM_SIZE
#define VOICE_L1DTCM_SIZE 0
#endif

#endif /* __PRODUCT_CONFIG_H__ */
