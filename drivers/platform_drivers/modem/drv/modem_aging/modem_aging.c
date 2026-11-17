/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2021. All rights reserved.
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

#include <securec.h>
#include <product_config.h>
#include <linux/module.h>
#include <linux/netdevice.h>
#include <linux/delay.h>
#include <msg_id.h>
#include <mdrv_msg.h>
#include <bsp_msg.h>
#include "modem_aging.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

modem_aging_genl_ctrl_s g_modem_aging_ctrl_info;
struct genl_ops g_modem_aging_genl_ops[] = {
    {
        .cmd = MODEM_AGING_GENL_CMD_NV,
        .doit = modem_aging_genl_rcv_handler,
    },
};


void modem_aging_genl_set_port_info(struct genl_info *info)
{
    g_modem_aging_ctrl_info.con_info.net = genl_info_net(info);
    g_modem_aging_ctrl_info.con_info.port_id = info->snd_portid;
    modem_aging_err("port_id:%d\n", info->snd_portid);
}

int modem_aging_genl_rcv_para_check(struct sk_buff *skb, struct genl_info *info)
{
    struct nlmsghdr *nlhdr = NULL;

    if (skb == NULL || info == NULL) {
        modem_aging_err("parameter null\n");
        return -1;
    }

    nlhdr = nlmsg_hdr(skb);
    if (nlhdr == NULL) {
        modem_aging_err("nlhdr is null\n");
        return -1;
    }

    if ((skb->len < NLMSG_LENGTH(GENL_HDRLEN)) || (skb->len < nlhdr->nlmsg_len)) {
        modem_aging_err("skb_len invalid, skb_len=0x%x\n", skb->len);
        return -1;
    }

    return 0;
}

int modem_aging_app_data_handle(unsigned char *data, int data_len)
{
    int ret;
    modem_aging_app_cmd_pkt_s *head = (modem_aging_app_cmd_pkt_s *)data;
    modem_aging_resp_s resp = {0};

    if (data_len < sizeof(modem_aging_app_cmd_pkt_s) || data_len > MODEM_AGING_GENL_RECV_MAX_LEN) {
        modem_aging_err("err genl appdata len\n");
        return -1;
    }

    modem_aging_err("recv cmd:%d OK, data_len:%d\n", head->cmd, data_len);
    ret = modem_aging_msg_send(data, data_len);
    if (ret) {
        resp.cmd = head->cmd;
        resp.result = (unsigned int)ret;
        modem_aging_genl_send_data((unsigned char *)&resp, sizeof(modem_aging_resp_s));
        modem_aging_err("send cmd:%d to tsp fail:0x%x\n", head->cmd, ret);
        return ret;
    }

    return 0;
}

int modem_aging_genl_rcv_handler(struct sk_buff *skb, struct genl_info *info)
{
    unsigned char *data = NULL;
    int data_len;
    int ret;

    ret = modem_aging_genl_rcv_para_check(skb, info);
    if (ret) {
        modem_aging_err("recv para check fail\n");
        return ret;
    }

    modem_aging_genl_set_port_info(info);

    data = (unsigned char *)genlmsg_data(info->genlhdr);
    data_len = genlmsg_len(info->genlhdr);
    if (data_len < 0) {
        modem_aging_err("recv data len < 0\n");
        return -1;
    }

    return modem_aging_app_data_handle(data, data_len);
}

static int modem_aging_genl_send_fragment_data(unsigned char *buf, unsigned int len)
{
    modem_aging_genl_ctrl_s *ctrl_info = &g_modem_aging_ctrl_info;
    struct sk_buff *genl_skb = NULL;
    char *payload_hdr = NULL;
    int ret;
    unsigned int payload_len = NLMSG_ALIGN(len);

    if (ctrl_info->con_info.net == NULL) {
        modem_aging_err("modem_aging genl chan net is null\n");
        return -1;
    }

    genl_skb = genlmsg_new(payload_len, GFP_KERNEL);
    if (genl_skb == NULL) {
        modem_aging_err("nlmsg_new fail\n");
        return -1;
    }

    payload_hdr = genlmsg_put(genl_skb, ctrl_info->con_info.port_id, 0, &ctrl_info->family, 0, MODEM_AGING_GENL_CMD_NV);
    if (payload_hdr == NULL) {
        modem_aging_err("genlmsg_put hdr is NULL\n");
        ret = -1;
        goto err;
    }

    ret = memcpy_s(payload_hdr, len, buf, len);
    if (ret) {
        modem_aging_err("memcpy_s unicast send data fail, ret=0x%x\n", ret);
        goto err;
    }

    skb_put(genl_skb, payload_len);
    genlmsg_end(genl_skb, payload_hdr);

    ret = genlmsg_unicast(ctrl_info->con_info.net, genl_skb, ctrl_info->con_info.port_id);
    if (ret < 0) {
        modem_aging_err("genl data send fail:%d\n", ret);
        return ret;
    }
    modem_aging_err("genl data send ok\n");
    return 0;

err:
    dev_kfree_skb_any(genl_skb);
    return ret;
}


int modem_aging_genl_send_data(unsigned char *buf, unsigned int len)
{
    int ret;
    unsigned int retry_cnt = 0;

    osl_sem_down(&g_modem_aging_ctrl_info.con_info.chan_sem);

    ret = modem_aging_genl_send_fragment_data(buf, len);
    while ((ret == -EAGAIN) && retry_cnt < MODEM_AGING_RESP_RETRY_MAX_CNT) {
        msleep(MODEM_AGING_RESP_RETRY_MSLEEP_TIME);
        ret = modem_aging_genl_send_fragment_data(buf, len);
        retry_cnt++;
    }
    if (ret) {
        modem_aging_err("genl send data fail, retry_cnt:%d\n", retry_cnt);
    } else {
        modem_aging_err("genl send data ok, retry_cnt:%d\n", retry_cnt);
    }

    osl_sem_up(&g_modem_aging_ctrl_info.con_info.chan_sem);

    return ret;
}

int modem_aging_msg_send(unsigned char *data, unsigned int len)
{
    modem_aging_msg_head_s *head = NULL;
    unsigned int total_len = sizeof(modem_aging_msg_head_s) + len;
    int ret;

    head = (modem_aging_msg_head_s *)mdrv_msg_alloc(DRV_MID_MODEM_AGING_APSS, total_len, MSG_FULL_LEN);
    if (head == NULL) {
        modem_aging_err("msg malloc fail\n");
        return -1;
    }

    MDRV_MSG_HEAD_FILL(head, DRV_MID_MODEM_AGING_APSS, DRV_MID_MODEM_AGING_TSP, len);

    if (memcpy_s(head->data, len, data, len)) {
        modem_aging_err("msg data send memcpy fail\n");
    }

    ret = mdrv_msg_send(head, 0);
    if (ret) {
        modem_aging_err("msg send fail:%d\n", ret);
        mdrv_msg_free(DRV_MID_MODEM_AGING_APSS, (void *)head);
    }
    modem_aging_err("msg send ok, len:%d\n", len);
    return ret;
}

int modem_aging_msg_chan_proc(const struct msg_addr *src, void *msg, unsigned int len)
{
    modem_aging_resp_s *resp = NULL;

    if ((src == NULL) || (msg == NULL) || (len != sizeof(modem_aging_resp_s))) {
        modem_aging_err("msglite para invalid, len=0x%x\n", len);
        return -1;
    }

    if (unlikely((src->core != MSG_CORE_TSP) || (src->chnid != MSG_CHN_MODEM_AGING))) {
        modem_aging_err("src core or chan id invalid, core=0x%x, chan=0x%x\n", src->core, src->chnid);
        return -1;
    }

    resp = (modem_aging_resp_s *)msg;
    modem_aging_err("genl send resp:%d, result:%d\n", resp->cmd, resp->result);

    return modem_aging_genl_send_data(msg, len);
}

int mdoem_aging_msglite_init(void)
{
    struct msgchn_attr attr = {0};
    bsp_msgchn_attr_init(&attr);

    attr.chnid = MSG_CHN_MODEM_AGING;
    attr.coremask = MSG_CORE_MASK(MSG_CORE_TSP);
    attr.lite_notify = modem_aging_msg_chan_proc;

    return bsp_msg_lite_open(&g_modem_aging_ctrl_info.con_info.msglite_chan, &attr);
}

int modem_aging_genl_init(void)
{
    int ret = BSP_OK;

    modem_aging_err("modem_aging genl init start\n");

    g_modem_aging_ctrl_info.family.hdrsize = 0;
    g_modem_aging_ctrl_info.family.version = MODEM_AGING_GENL_VERSION;
    g_modem_aging_ctrl_info.family.ops = g_modem_aging_genl_ops;
    g_modem_aging_ctrl_info.family.n_ops = ARRAY_SIZE(g_modem_aging_genl_ops);
    ret = strncpy_s(g_modem_aging_ctrl_info.family.name, sizeof(g_modem_aging_ctrl_info.family.name), MODEM_AGING_GENL_NAME,
                    sizeof(MODEM_AGING_GENL_NAME));
    if (ret) {
        modem_aging_err("strcpy genl name failed, ret=0x%x\n", ret);
        return ret;
    }

    ret = genl_register_family(&g_modem_aging_ctrl_info.family);
    if (ret) {
        modem_aging_err("genl_register_family failed, ret=0x%x\n", ret);
    }

    osl_sem_init(1, &g_modem_aging_ctrl_info.con_info.chan_sem);

    modem_aging_err("modem_aging genl init succ\n");
    return ret;
}

int modem_aging_init(void)
{
    int ret;

    ret = mdoem_aging_msglite_init();
    if (ret) {
        modem_aging_err("msglite init fail:0x%x\n", ret);
        return ret;
    }

    ret = modem_aging_genl_init();
    if (ret) {
        modem_aging_err("genl init fail:0x%x\n", ret);
        return ret;
    }

    modem_aging_err("modem aging init ok\n");
    return 0;
}

#if !IS_ENABLED(CONFIG_MODEM_DRIVER)
module_init(modem_aging_init);
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
