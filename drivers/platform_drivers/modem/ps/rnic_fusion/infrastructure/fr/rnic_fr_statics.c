/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
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
 */
#include "rnic_fr_i.h"
#include "rnic_fr.h"
#include "rnic_log.h"
#include "rnic_fr_statics.h"

void rnic_fr_report_stats(void)
{
	struct rnic_fr_ctx_s *ctx = rnic_fr_get_ctx_ptr();
	struct rnic_fr_stats_rpt_s info = {{0}};

	info.head.snd_pid = RNIC_FIX_PID;
	info.hdr.ver = 101; /* version 101 */
	info.status = ctx->status;

	rnic_trans_report(ID_DIAG_RNIC_FR_STATS, &info, sizeof(info));
}

#ifndef LLT_OS_VER
int rnic_fr_show_stats(void)
{
	struct rnic_fr_ctx_s *ctx = rnic_fr_get_ctx_ptr();
	struct rnic_fr_status_s *status = &ctx->status;

	if (ctx->support == false) {
		pr_err("[RNIC_FR] Feature is not support\n");
		return 1;
	}
	pr_err("[RNIC_FR] show port_num: %u\n", ctx->port_num);
	pr_err("[RNIC_FR] show pif_id: %u\n", ctx->pif_id);

	pr_err("[RNIC_FR] show ul_decode_echo_req: %u\n", status->ul_decode_echo_req);
	pr_err("[RNIC_FR] show ul_decode_udp: %u\n",	  status->ul_decode_udp);
	pr_err("[RNIC_FR] show ul_decode_tcp: %u\n",	  status->ul_decode_tcp);
	pr_err("[RNIC_FR] show ul_decode_ipv6: %u\n",	  status->ul_decode_ipv6);
	pr_err("[RNIC_FR] show ul_decode_frag_pkt: %u\n", status->ul_decode_frag_pkt);
	pr_err("[RNIC_FR] show ul_unsupp_pkt: %u\n",	  status->ul_unsupp_pkt);

	pr_err("[RNIC_FR] show ul_hfw_pkt: %u\n",	  status->ul_hfw_pkt);
	pr_err("[RNIC_FR] show ul_hfw_pkt_fail: %u\n",	  status->ul_hfw_pkt_fail);
	pr_err("[RNIC_FR] show ul_pkt_unmap_fail: %u\n",  status->ul_pkt_unmap_fail);

	pr_err("[RNIC_FR] show dl_decode_echo_req: %u\n", status->dl_decode_echo_req);
	pr_err("[RNIC_FR] show dl_decode_udp: %u\n",	  status->dl_decode_udp);
	pr_err("[RNIC_FR] show dl_decode_tcp: %u\n",	  status->dl_decode_tcp);
	pr_err("[RNIC_FR] show dl_decode_ipv6: %u\n",	  status->dl_decode_ipv6);
	pr_err("[RNIC_FR] show dl_decode_frag_pkt: %u\n", status->dl_decode_frag_pkt);
	pr_err("[RNIC_FR] show dl_unsupp_pkt: %u\n",	  status->dl_unsupp_pkt);
	pr_err("[RNIC_FR] show dl_filter_num: %u\n",	  status->dl_filter_num);
	pr_err("[RNIC_FR] show dl_pif_id_err: %u\n",	  status->dl_pif_id_err);
	pr_err("[RNIC_FR] show add_table_failed: %u\n",	  status->add_table_failed);
	pr_err("[RNIC_FR] show dl_update_hfr_table_fail: %u\n",	status->dl_update_hfr_table_fail);
	pr_err("[RNIC_FR] show dl_update_hfr_table_succ: %u\n",	status->dl_update_hfr_table_succ);

	return 1;
}
#endif