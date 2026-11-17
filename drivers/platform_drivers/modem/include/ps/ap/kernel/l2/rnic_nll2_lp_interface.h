/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
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
 *
 */

#ifndef RNIC_NLL2_LP_INTERFACE_H
#define RNIC_NLL2_LP_INTERFACE_H

#include "rnic_nll2_base_interface.h"

#ifdef __cplusplus
extern "C" {
#endif

enum rnic_nll2_voip_state_e {
	NLL2_RNIC_VOIP_START          = 0x00,
	NLL2_RNIC_VOIP_STOP           = 0x01,
	NLL2_RNIC_VOIP_STATE_BUTT
};

/* ID_NLL2_RNIC_VOIP_STATE_IND */
struct nll2_rnic_voip_state_ind_s {
	struct rnic_nll2_msg_head_s msg_head;
	unsigned short modem_id;
	unsigned char voip_state; /* rnic_nll2_voip_state_e */
	unsigned char reserve;
	unsigned int app_uid;
};

/* ID_NLL2_RNIC_RATE_ADJUST_IND */
struct nll2_rnic_rate_adjust_ind_s {
	struct rnic_nll2_msg_head_s msg_head;
	unsigned short modem_id;
	unsigned short rate_high_thr; /* unit: Kbps */
	unsigned char adjust_flag; /* rate adjust indication. 1: start adjust; 0: cancel adjust. */
	unsigned char reserve[3];
};

#ifdef __cplusplus
}
#endif

#endif
