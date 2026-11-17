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

#include <linux/skbuff.h>
#include <linux/module.h>
#include <linux/pm_wakeup.h>
#include <linux/delay.h>
#include <net/genetlink.h>
#include "securec.h"
#include "ps_bmi_hmi_genl.h"
#include "ps_hmi_genl_i.h"

#ifndef STATIC
#define STATIC static
#endif

#define GENL_MAX_DATA_LEN (NLMSG_DEFAULT_SIZE - GENL_HDRLEN - sizeof(struct ps_hmi_genl_hdr_s))
#define GENL_HDR_LEN (NLMSG_HDRLEN + GENL_HDRLEN)
#define GENL_SEND_TRY_TIMES 5

enum ps_hmi_genl_state {
	GENL_DISCONNECT,
	GENL_CONNECT,
	CENL_BUTT,
};

struct ps_hmi_genl_chan_s {
	struct genl_info info;
	u32 port_id;
	struct net *net;
};

struct ps_hmi_genl_ctx_s {
	struct genl_family family;
	struct ps_hmi_genl_chan_s chn_info[PS_HMI_GENL_BUTT];
	ps_hmi_genl_rcv_entry rcv_entry[PS_HMI_GENL_BUTT];
	struct wakeup_source *wakelock;
	enum ps_hmi_genl_state state;
};

STATIC struct ps_hmi_genl_ctx_s *ps_hmi_genl_ctx_ptr;

STATIC s32 ps_hmi_genl_rcv_para_check(struct sk_buff *skb, struct genl_info *info)
{
	struct nlmsghdr *nlhdr = NULL;

	if (skb == NULL || info == NULL) {
		pr_err("ps_hmi_genl_rcv_para_check, parameter NULL\n");
		return -1;
	}

	nlhdr = nlmsg_hdr(skb);
	if (nlhdr == NULL) {
		pr_err("ps_hmi_genl_rcv_para_check, nlhdr is NULL\n");
		return -1;
	}

	if (skb->len < GENL_HDR_LEN) {
		pr_err("ps_hmi_genl_rcv_para_check, skb len:%d\n", skb->len);
		return -1;
	}

	return 0;
}

STATIC s32 ps_hmi_genl_send(struct ps_hmi_genl_hdr_s *hdr)
{
	struct ps_hmi_genl_ctx_s *ctx = ps_hmi_genl_ctx_ptr;
	struct ps_hmi_genl_chan_s *chn = NULL;
	struct sk_buff *skb = NULL;
	void *msg_head = NULL;
	u32 payload_len;
	s32 ret;

	if (hdr->msg_type >= PS_HMI_GENL_BUTT) {
		pr_err("ps_hmi_genl_send, msg_type is invaild %d\n", hdr->msg_type);
		return -1;
	}

	chn = &ctx->chn_info[hdr->msg_type];
	if (chn->net == NULL) {
		pr_err("ps_hmi_genl_send, chn->net is NULL\n");
		return -1;
	}

	payload_len = NLMSG_ALIGN(hdr->msg_len + sizeof(*hdr));
	skb = genlmsg_new(payload_len, GFP_KERNEL);
	if (skb == NULL) {
		pr_err("ps_hmi_genl_send, genlmsg_new failed\n");
		return -1;
	}

	msg_head = genlmsg_put(skb, chn->port_id, 0, &ctx->family, 0, PS_HMI_GENL_CMD_REQ);

	//add the data without attribute type
	ret = nla_put_nohdr(skb, payload_len, hdr);
	if (ret) {
		pr_err("ps_hmi_genl_send, nla_put_nohdr failed, ret %d\n", ret);
		nlmsg_free(skb);
		return ret;
	}

	genlmsg_end(skb, msg_head);

	ret = genlmsg_unicast(chn->net, skb, chn->port_id);
	if (ret < 0) {
		pr_err("genlmsg_unicast failed, ret=%d\n", ret);
		return ret;
	}
	return 0;
}

s32 ps_hmi_genl_send_msg(struct ps_hmi_genl_hdr_s *hdr)
{
	struct ps_hmi_genl_ctx_s *ctx = ps_hmi_genl_ctx_ptr;
	u32 try_time = 0;
	s32 ret;

	if (!ctx || ctx->state != GENL_CONNECT) {
		pr_err("ps_hmi_genl_send_msg state is abnormal");
		return -1;
	}

	if (hdr->msg_len > GENL_MAX_DATA_LEN) {
		pr_err("ps_hmi_genl_send_msg length is too big: %d\n", hdr->msg_len);
		return -1;
	}
	__pm_stay_awake(ctx->wakelock);
try:
	ret = ps_hmi_genl_send(hdr);
	if (ret == -ECONNREFUSED) {
		ctx->state = GENL_DISCONNECT;
	} else if (ret == -EAGAIN) {
		try_time++;
		if (try_time >= GENL_SEND_TRY_TIMES) {
			pr_err("try 5 times, send failed ret:%d\n", ret);
			__pm_relax(ctx->wakelock);
			return ret;
		}
		msleep(1);
		goto try;
	}

	__pm_relax(ctx->wakelock);
	return ret;
}

STATIC void ps_hmi_genl_set_port_info(unsigned short msg_type, struct genl_info *info)
{
	struct ps_hmi_genl_ctx_s *ctx = ps_hmi_genl_ctx_ptr;

	ctx->chn_info[msg_type].net = genl_info_net(info);
	ctx->chn_info[msg_type].port_id = info->snd_portid;
}

STATIC s32 ps_hmi_genl_rcv(struct sk_buff *skb, struct genl_info *info)
{
	struct ps_hmi_genl_ctx_s *ctx = ps_hmi_genl_ctx_ptr;
	struct ps_hmi_genl_hdr_s *hdr = NULL;
	u8 *data = NULL;
	s32 ret;

	if (!ctx) {
		pr_err("ps_hmi_genl_rcv ctx is null");
		return -1;
	}

	ret = ps_hmi_genl_rcv_para_check(skb, info);
	if (ret)
		return ret;

	data = genlmsg_data(nlmsg_data(nlmsg_hdr(skb)));
	hdr = (struct ps_hmi_genl_hdr_s *)data;
	if (skb->len <= GENL_HDR_LEN + sizeof(*hdr)) {
		pr_err("ps_hmi_genl_rcv, skb len:%d\n", skb->len);
		return -1;
	}

	if (hdr->msg_type == PS_HMI_GENL_RNIC_STATS) {
		if (ctx->rcv_entry[hdr->msg_type])
			ctx->rcv_entry[hdr->msg_type](hdr);
		else
			pr_err("ps_hmi_genl_rcv rcv_entry is null");

		ps_hmi_genl_set_port_info(hdr->msg_type, info);
	}

	ctx->state = GENL_CONNECT;
	return 0;
}

struct genl_ops ps_hmi_genl_ops[] = {
	{
		.cmd = PS_HMI_GENL_CMD_REQ,
		.doit = ps_hmi_genl_rcv,
	},
};

s32 ps_hmi_genl_rcv_cb_regiester(ps_hmi_genl_rcv_entry rcv, u32 msg_type)
{
	struct ps_hmi_genl_ctx_s *ctx = ps_hmi_genl_ctx_ptr;

	if (!ctx || msg_type >= PS_HMI_GENL_BUTT)
		return -1;

	ctx->rcv_entry[msg_type] = rcv;
	return 0;
}

s32 ps_hmi_genl_init(void)
{
	struct ps_hmi_genl_ctx_s *ctx = NULL;
	s32 ret = 0;

	ctx = kzalloc(sizeof(struct ps_hmi_genl_ctx_s), GFP_KERNEL);
	if (!ctx) {
		pr_err("ps_hmi_genl_init kzalloc fialed!\n");
		return -1;
	}

	ctx->family.hdrsize = 0;
	ctx->family.version = PS_HMI_GENL_VERSION;
	ctx->family.ops = ps_hmi_genl_ops;
	ctx->family.n_ops = ARRAY_SIZE(ps_hmi_genl_ops);

	ret = strncpy_s(ctx->family.name, sizeof(ctx->family.name),
			PS_HMI_GENL_NAME, sizeof(PS_HMI_GENL_NAME));
	if (ret) {
		pr_err("ps_hmi_genl_init strncpy genl name failed, ret=%d\n", ret);
		goto ctx_free;
	}

	ret = genl_register_family(&ctx->family);
	if (ret) {
		pr_err("ps_hmi_genl_init genl_register_family failed, ret=%d\n", ret);
		goto ctx_free;
	}

	ctx->wakelock = wakeup_source_register(NULL, "ps_hmi_genl");
	if (!ctx->wakelock) {
		pr_err("ps_hmi_genl_init wakelock register fail\n");
		goto unregister;
	}

	ps_hmi_genl_ctx_ptr = ctx;
	return ret;

unregister:
	(void)genl_unregister_family(&ctx->family);

ctx_free:
	kfree(ctx);
	return ret;
}

void ps_hmi_genl_exit(void)
{
	struct ps_hmi_genl_ctx_s *ctx = ps_hmi_genl_ctx_ptr;

	if (ctx) {
		(void)genl_unregister_family(&ctx->family);

		ctx->state = GENL_DISCONNECT;

		kfree(ctx);
	}
	ps_hmi_genl_ctx_ptr = NULL;
}

#if !IS_ENABLED(CONFIG_MODEM_DRIVER)
module_init(ps_hmi_genl_init);
module_exit(ps_hmi_genl_exit);
#endif
