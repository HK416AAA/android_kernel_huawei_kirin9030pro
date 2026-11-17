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
 */

#ifndef PS_BMI_RNIC_STATS_H
#define PS_BMI_RNIC_STATS_H

#ifdef __cplusplus
extern "C" {
#endif

#define RNIC_NETDEV_NAME_SIZE 16

enum rnic_stats_msg_id_e {
	/* Notify RNIC to initiate data static request */
	ID_RNIC_STATS_CONTRL_REQ = 0,
	/* Response to RNIC static contrl request */
	ID_RNIC_STATS_CONTRL_CNF = 1,
	/* RNIC actively report the status */
	ID_RNIC_STATS_INFO_RPT = 2,
};

/*
 * 1. Only supports reporting of data service network card statistics: RMNET0 - RMNET11.
 * 2. The UL data bytes contains the length of the MAC header, the IP header and TCP/UDP header.
 * 3. The DL data bytes contains the length of the IP header and TCP/UDP header.
 * 3. IP fragment packets are not counted.
 */
struct rnic_stats_info_s {
	unsigned long long rpt_time;
	char netdev_name[RNIC_NETDEV_NAME_SIZE]; // RMNET0-RMNET11. Strings contains the terminator
	unsigned int modem_id;
	unsigned int ul_udp_pkts;
	unsigned int ul_udp_bytes;
	unsigned int ul_tcp_pkts;
	unsigned int ul_tcp_bytes;

	unsigned int dl_udp_pkts;
	unsigned int dl_udp_bytes;
	unsigned int dl_tcp_pkts;
	unsigned int dl_tcp_bytes;
};

/*
 * 1. When applying for message memory, you need to include the length of msghdr
 * 2. ID_RNIC_STATS_CONTRL_REQ:
 *    struct rnic_stats_msghdr_s + struct rnic_stats_ctl_req_s
 * 3. ID_RNIC_STATS_CONTRL_CNF:
 *    struct rnic_stats_msghdr_s + struct rnic_stats_ctl_cnf_s
 * 4. ID_RNIC_STATS_INFO_RPT
 *    struct rnic_stats_msghdr_s + struct rnic_stats_info_rpt_s
 */
struct rnic_stats_msghdr_s {
	unsigned int msg_id; // rnic_stats_msg_id
	unsigned int msg_len; // Indicates the length of the msg_content
	unsigned char msg_content[0];
};

/*
 * The maximum number of arrays contained in net_info is the number of RMNET: 12
 */
struct rnic_stats_info_rpt_s {
	unsigned int net_num;
	struct rnic_stats_info_s net_info[0];
};

struct rnic_stats_ctl_req_s {
	unsigned int start_flag; // 0: Stop 1: Start
	unsigned int rpt_period; // Unit ms
};

struct rnic_stats_ctl_cnf_s {
	unsigned int result; // 0: success 1: failed
};

#ifdef __cplusplus
}
#endif

#endif /* PS_BMI_RNIC_STATS_H */
