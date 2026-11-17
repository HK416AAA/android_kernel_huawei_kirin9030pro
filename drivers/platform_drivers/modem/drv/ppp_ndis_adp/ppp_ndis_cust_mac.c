/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
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
#include <linux/kernel.h>
#include <linux/etherdevice.h>
#include <osl_types.h>
#include <securec.h>

#include <mdrv_bmi_nva.h>
#include <nva_id.h>
#include <bsp_nva.h>
#include <bsp_mci.h>
#include <bsp_ppp_ndis.h>
#include "ppp_ndis_net.h"
#include "ppp_ndis_address.h"
#include "ppp_ndis_adp.h"
#include "ppp_ndis_cust_mac.h"

#define THIS_MODU mod_ppp_ndis

// 网卡默认数量
#define GMAC_NIC_DEFAULT_NUM 1
#define USB_NIC_DEFAULT_NUM 6
#define WIFI_NIC_DEFAULT_NUM 1
#define PCIE_NIC_DEFAULT_NUM 8

// 网卡最大数量
#define CUST_MAC_GMAC_NIC_MAX_NUM 4
#define CUST_MAC_USB_NIC_MAX_NUM 10
#define CUST_MAC_WIFI_NIC_MAX_NUM 4
#define CUST_MAC_PCIE_NIC_MAX_NUM 20
#define CUST_MAC_NIC_RSV_NUM 22

#define PPP_NDIS_CUST_MAC_TIMEOUT_MS (10000)
#define PPP_NDIS_CUST_MAC_MAX_LEN sizeof(struct ppp_ndis_get_all_mac_addr_info)

struct set_mac_state_info {
    unsigned char nic_id;
    unsigned char state;
} __attribute__((packed));

struct ppp_ndis_cust_desc_info {
    unsigned int max_num;
    unsigned int offset;
};

typedef int (*ppp_ndis_cmd_proc_func)(struct ppp_ndis_cust_mac_user_data *param);
struct ppp_ndis_cmd_info {
    unsigned int cmd_id;
    ppp_ndis_cmd_proc_func func;
};

struct ppp_ndis_init_stat {
    unsigned int atp_register_err;
    unsigned int done;
    unsigned int read_nva_nic_num_err;
    unsigned int num_err;
    unsigned int mac_info_err;
    unsigned int nva_nic_num_overflow;
};

struct ppp_ndis_cmd_pre_proc_stat {
    unsigned int proc_cnt;
    unsigned int buf_null;
    unsigned int len_err;
    unsigned int nic_type_err;
    unsigned int cmd_id_err;
};

struct ppp_ndis_set_mac_stat {
    unsigned int proc_cnt;
    unsigned int len_err;
    unsigned int nic_num_err;
    unsigned int recheck_len_err;
    unsigned int nic_id_err;
    unsigned int same;
    unsigned int write_nva_err;
};

struct ppp_ndis_get_mac_stat {
    unsigned int proc_cnt;
    unsigned int len_err;
    unsigned int nic_id_err;
    unsigned int read_nva_mac_err;
    unsigned int nic_id_not_all;
};

struct ppp_ndis_restore_default_stat {
    unsigned int proc_cnt;
    unsigned int len_err;
    unsigned int same;
    unsigned int nic_id_err;
    unsigned int nic_id_not_all;
    unsigned int write_nva_err;
};

struct ppp_ndis_cmd_proc_stat {
    struct ppp_ndis_init_stat init;
    struct ppp_ndis_cmd_pre_proc_stat cmd_pre_proc;
    struct ppp_ndis_set_mac_stat set_mac;
    struct ppp_ndis_get_mac_stat get_mac;
    struct ppp_ndis_restore_default_stat restore_default;
};

static int ppp_ndis_get_nva_mac_info(nv_ppp_ndis_mac_cust_feature_s *mac_info);
static int ppp_ndis_cmd_proc_set_mac_addr(struct ppp_ndis_cust_mac_user_data *param);
static int ppp_ndis_cmd_proc_get_mac_addr(struct ppp_ndis_cust_mac_user_data *param);
static int ppp_ndis_cmd_proc_restore_default_mac_addr(struct ppp_ndis_cust_mac_user_data *param);

static const struct ppp_ndis_cmd_info g_cmd_proc_sets[] = {
    {PPP_NDIS_SET_MAC_ADDR, ppp_ndis_cmd_proc_set_mac_addr},
    {PPP_NDIS_GET_MAC_ADDR, ppp_ndis_cmd_proc_get_mac_addr},
    {PPP_NDIS_RESTORE_DEFAULT_MAC_ADDR, ppp_ndis_cmd_proc_restore_default_mac_addr},
};

static struct ppp_ndis_cust_desc_info g_ppp_nic_cust_desc[PPP_NDIS_NIC_TYPE_LAST] = {
    {CUST_MAC_GMAC_NIC_MAX_NUM, 0},
    {CUST_MAC_USB_NIC_MAX_NUM,  0},
    {CUST_MAC_WIFI_NIC_MAX_NUM, 0},
    {CUST_MAC_PCIE_NIC_MAX_NUM, 0},
};

// 网卡默认数量
static const nv_ppp_ndis_nic_num_feature_s g_nic_default_num = {
    { GMAC_NIC_DEFAULT_NUM, USB_NIC_DEFAULT_NUM, WIFI_NIC_DEFAULT_NUM, PCIE_NIC_DEFAULT_NUM,
      0, 0, 0, 0 },
};

static nv_ppp_ndis_nic_num_feature_s g_nic_num_info;
static nv_ppp_ndis_mac_cust_feature_s g_cust_mac_info;
static struct ppp_ndis_cmd_proc_stat g_cust_stat;

static int ppp_ndis_check_nic_num(unsigned int nic_type, unsigned char nic_num)
{
    if (nic_num == 0 || nic_num > g_nic_num_info.num[nic_type]) {
        return -EINVAL;
    }

    return 0;
}

static int ppp_ndis_check_nic_id(bool allow_zero, unsigned int nic_type, unsigned int nic_id)
{
    if (!allow_zero && (nic_id == 0)) {
        return -EINVAL;
    }

    if (nic_id > g_nic_num_info.num[nic_type]) {
        return -EINVAL;
    }

    return 0;
}

static int ppp_ndis_calc_nva_offset_init(void)
{
    unsigned int i;
    unsigned int offset = 0;

    for (i = 0; i < PPP_NDIS_NIC_TYPE_LAST; i++) {
        if (i > 0) {
            offset += g_nic_num_info.num[i - 1];
        }
        g_ppp_nic_cust_desc[i].offset = offset;
    }

    return 0;
}

static unsigned int ppp_ndis_get_nic_offset(unsigned int nic_type, unsigned int nic_id)
{
    return g_ppp_nic_cust_desc[nic_type].offset + nic_id - 1;
}

static int ppp_ndis_update_cust_addr(unsigned int nic_type, unsigned int nic_id, unsigned char *addr)
{
    int ret;
    unsigned int offset;

    offset = ppp_ndis_get_nic_offset(nic_type, nic_id);

    g_cust_mac_info.mac_info[offset].state = PPP_NDIS_CUST_ENABLE;
    ret = memcpy_s(g_cust_mac_info.mac_info[offset].mac_addr, ETH_ALEN, addr, ETH_ALEN);
    if (ret) {
        ppp_ndis_err("memcpy err\n");
    }

    return ret;
}

static int ppp_ndis_restore_default_addr(unsigned int nic_type, unsigned int nic_id)
{
    int ret;
    unsigned int offset;

    offset = ppp_ndis_get_nic_offset(nic_type, nic_id);

    g_cust_mac_info.mac_info[offset].state = PPP_NDIS_CUST_DISABLE;
    ret = memset_s(g_cust_mac_info.mac_info[offset].mac_addr, ETH_ALEN, 0, ETH_ALEN);
    if (ret) {
        ppp_ndis_err("memset err\n");
    }

    return ret;
}

static unsigned char ppp_ndis_get_cust_state(unsigned int nic_type, unsigned int nic_id)
{
    unsigned int offset;

    offset = ppp_ndis_get_nic_offset(nic_type, nic_id);

    return g_cust_mac_info.mac_info[offset].state;
}

static int ppp_ndis_write_nva_cust_info(unsigned int nic_type)
{
    int ret;
    unsigned int offset;

    offset = ppp_ndis_get_nic_offset(nic_type, 1);

    ret = mdrv_nva_write(NVA_ID_DRV_PPP_NDIS_MAC_CUST, offset * sizeof(struct ppp_ndis_cust_mac),
        &g_cust_mac_info.mac_info[offset], g_nic_num_info.num[nic_type] * sizeof(struct ppp_ndis_cust_mac));

    return ret;
}

static int ppp_ndis_save_mac_addr(struct ppp_ndis_cust_mac_user_data *param, unsigned char nic_num,
    struct ppp_ndis_set_single_mac_addr_info *user_info)
{
    unsigned int i;
    unsigned int update_nva = 0;
    struct ppp_ndis_cust_mac *cur_info = NULL;
    int ret;

    for (i = 0; i < nic_num; i++) {
        if (ppp_ndis_check_nic_id(false, param->nic_type, user_info->nic_id)) {
            g_cust_stat.set_mac.nic_id_err++;
            ppp_ndis_err("error nic_type %d nic_id %d\n", param->nic_type, user_info->nic_id);
            return -ESRCH;
        }

        cur_info = ppp_ndis_get_cust_mac_info(param->nic_type, user_info->nic_id);
        ppp_ndis_info("nic_id %d cur_addr %02X-%02X-%02X-%02X-%02X-%02X, new_addr %02X-%02X-%02X-%02X-%02X-%02X\n",
            user_info->nic_id, cur_info->mac_addr[0], cur_info->mac_addr[1], cur_info->mac_addr[2],
            cur_info->mac_addr[3], cur_info->mac_addr[4], cur_info->mac_addr[5], user_info->addr[0], user_info->addr[1],
            user_info->addr[2], user_info->addr[3], user_info->addr[4], user_info->addr[5]);
        if (memcmp(cur_info->mac_addr, user_info->addr, sizeof(user_info->addr))) {
            update_nva = 1;
            ppp_ndis_update_cust_addr(param->nic_type, user_info->nic_id, user_info->addr);
        }
        user_info++;
    }

    if (update_nva == 0) {
        g_cust_stat.set_mac.same++;
        ppp_ndis_info("no need write nva\n");
        return 0;
    }

    ret = ppp_ndis_write_nva_cust_info(param->nic_type);
    if (ret) {
        g_cust_stat.set_mac.write_nva_err++;
        ppp_ndis_err("set_cust_addr write nva fail\n");
        return ret;
    }

    return 0;
}

static int ppp_ndis_cmd_proc_set_mac_addr(struct ppp_ndis_cust_mac_user_data *param)
{
    int ret;
    struct ppp_ndis_set_multi_mac_addr_info *set_info = NULL;

    g_cust_stat.set_mac.proc_cnt++;
    if (param->data_len < sizeof(struct ppp_ndis_set_multi_mac_addr_info)) {
        g_cust_stat.set_mac.len_err++;
        ppp_ndis_err("error data_len too small %d\n", param->data_len);
        return -ENODATA;
    }

    set_info = (struct ppp_ndis_set_multi_mac_addr_info *)param->data;

    if (ppp_ndis_check_nic_num(param->nic_type, set_info->nic_num)) {
        g_cust_stat.set_mac.nic_num_err++;
        ppp_ndis_err("error nic_type %d nic_num %d\n", param->nic_type, set_info->nic_num);
        return -ESTALE;
    }

    if (param->data_len !=
        sizeof(set_info->nic_num) + set_info->nic_num * sizeof(struct ppp_ndis_set_single_mac_addr_info)) {
        g_cust_stat.set_mac.recheck_len_err++;
        ppp_ndis_err("error data_len overflow %d, nic_num %d\n", param->data_len, set_info->nic_num);
        return -EOVERFLOW;
    }

    ret = ppp_ndis_save_mac_addr(param, set_info->nic_num, set_info->addr_infos);

    return ret;
}

static int ppp_nids_get_mac_addr_fill_resp(struct ppp_ndis_cust_mac_user_data *param)
{
    unsigned int ret;
    int i;
    struct ppp_ndis_cust_mac *info = NULL;
    struct ppp_ndis_get_all_mac_addr_info *get_info = NULL;
    struct ppp_ndis_get_single_mac_addr_info *sg_mac_info = NULL;

    get_info = (struct ppp_ndis_get_all_mac_addr_info *)param->data;
    sg_mac_info = get_info->addr_infos;

    // nic_num
    get_info->nic_num = g_nic_num_info.num[param->nic_type];

    // nic_addr
    for (i = 0; i < g_nic_num_info.num[param->nic_type]; i++) {
        info = ppp_ndis_get_cust_mac_info(param->nic_type, i + 1);
        if (info == NULL) {
            ppp_ndis_err("error cust info null\n");
            return -EIO;
        }

        // state
        sg_mac_info->state = info->state;

        // mac_addr
        ret = memcpy_s(sg_mac_info->addr, ETH_ALEN, info->mac_addr, ETH_ALEN);
        if (ret) {
            ppp_ndis_err("error memcpy fail %d\n", ret);
            return -EIO;
        }
        sg_mac_info++;
    }

    param->data_len = sizeof(struct ppp_ndis_get_all_mac_addr_info) +
        get_info->nic_num * sizeof(struct ppp_ndis_get_single_mac_addr_info);

    return 0;
}

static int ppp_ndis_cmd_proc_get_mac_addr(struct ppp_ndis_cust_mac_user_data *param)
{
    int ret;
    struct ppp_ndis_get_all_mac_addr_info *get_info = NULL;

    g_cust_stat.get_mac.proc_cnt++;
    // 传入data_len
    if (param->data_len != sizeof(struct ppp_ndis_get_all_mac_addr_info)) {
        g_cust_stat.get_mac.len_err++;
        ppp_ndis_err("error data_len too small %d expect %lu\n", param->data_len,
            sizeof(struct ppp_ndis_get_all_mac_addr_info));
        return -ENODATA;
    }

    get_info = (struct ppp_ndis_get_all_mac_addr_info *)param->data;
    if (get_info->nic_id != 0) {
        g_cust_stat.get_mac.nic_id_not_all++;
        ppp_ndis_err("error nic id %d must be 0\n", get_info->nic_id);
        return -EFBIG;
    }

    // 读取nva
    ret = ppp_ndis_get_nva_mac_info(&g_cust_mac_info);
    if (ret) {
        g_cust_stat.get_mac.read_nva_mac_err++;
        ppp_ndis_err("error read nva fail %d\n", ret);
        return -EIO;
    }

    ret = ppp_nids_get_mac_addr_fill_resp(param);

    return ret;
}

static int ppp_ndis_restore_default_mac_addr(struct ppp_ndis_cust_mac_user_data *param)
{
    int ret;
    unsigned int i;
    unsigned char nic_num;
    unsigned char cur_state;
    unsigned int update_nva = 0;

    nic_num = g_nic_num_info.num[param->nic_type];
    for (i = 0; i < nic_num; i++) {
        cur_state = ppp_ndis_get_cust_state(param->nic_type, i + 1);
        if (cur_state == PPP_NDIS_CUST_ENABLE) {
            ppp_ndis_restore_default_addr(param->nic_type, i + 1);
            update_nva = 1;
        }
    }

    if (update_nva == 0) {
        g_cust_stat.restore_default.same++;
        ppp_ndis_err("no need write nva\n");
        return 0;
    }

    ret = ppp_ndis_write_nva_cust_info(param->nic_type);
    if (ret) {
        g_cust_stat.restore_default.write_nva_err++;
        ppp_ndis_err("restore default write nva fail\n");
        return ret;
    }

    return 0;
}

static int ppp_ndis_cmd_proc_restore_default_mac_addr(struct ppp_ndis_cust_mac_user_data *param)
{
    int ret;
    struct ppp_ndis_restore_default_mac_addr_info *restore_info = NULL;

    g_cust_stat.restore_default.proc_cnt++;

    // 传入data_len
    if (param->data_len != sizeof(struct ppp_ndis_restore_default_mac_addr_info)) {
        g_cust_stat.get_mac.len_err++;
        ppp_ndis_err("error data_len %d too small\n", param->data_len);
        return -ENODATA;
    }

    restore_info = (struct ppp_ndis_restore_default_mac_addr_info *)param->data;
    if (restore_info->nic_id != 0) {
        g_cust_stat.restore_default.nic_id_not_all++;
        ppp_ndis_err("error nic id %d must be 0\n", restore_info->nic_id);
        return -EFBIG;
    }

    ret = ppp_ndis_restore_default_mac_addr(param);

    return ret;
}

static int ppp_ndis_cust_mac_proc_func(unsigned char *buffer, unsigned int len)
{
    struct ppp_ndis_cust_mac_user_data *param = NULL;
    unsigned int i;

    g_cust_stat.cmd_pre_proc.proc_cnt++;
    if (buffer == NULL) {
        g_cust_stat.cmd_pre_proc.buf_null++;
        ppp_ndis_err("error buffer args\n");
        return -EINVAL;
    }

    if (len < sizeof(struct ppp_ndis_cust_mac_user_data)) {
        g_cust_stat.cmd_pre_proc.len_err++;
        ppp_ndis_err("error len %d args\n", len);
        return -ERANGE;
    }

    param = (struct ppp_ndis_cust_mac_user_data *)buffer;

    if (param->nic_type >= PPP_NDIS_NIC_TYPE_LAST) {
        g_cust_stat.cmd_pre_proc.nic_type_err++;
        ppp_ndis_err("error nic_type %d args\n", param->nic_type);
        return -EPERM;
    }

    ppp_ndis_info("nic_type %d cmd_id %d\n", param->nic_type, param->cmd_id);
    for (i = 0; i < ARRAY_SIZE(g_cmd_proc_sets); i++) {
        if (param->cmd_id == g_cmd_proc_sets[i].cmd_id) {
            return g_cmd_proc_sets[i].func(param);
        }
    }

    g_cust_stat.cmd_pre_proc.cmd_id_err++;
    ppp_ndis_err("cmd_id %d not support\n", param->cmd_id);

    return -ENOSYS;
}

static int ppp_ndis_get_nva_nic_num(nv_ppp_ndis_nic_num_feature_s *nic_num)
{
    int ret;
    unsigned int i;
    nv_ppp_ndis_nic_num_feature_s cust_nic;

    ret = bsp_nv_read(NVA_ID_DRV_PPP_NDIS_NIC_NUM, (unsigned char *)&cust_nic, sizeof(nv_ppp_ndis_nic_num_feature_s));
    if (ret) {
        g_cust_stat.init.read_nva_nic_num_err++;
        ppp_ndis_err("nic_num read nva fail, use defualt nic_num\n");
        ret = memcpy_s(nic_num, sizeof(nv_ppp_ndis_nic_num_feature_s), &g_nic_default_num,
            sizeof(nv_ppp_ndis_nic_num_feature_s));
        return ret;
    }

    // 校验
    for (i = 0; i < PPP_NDIS_NIC_TYPE_LAST; i++) {
        if (cust_nic.num[i] > g_ppp_nic_cust_desc[i].max_num) {
            cust_nic.num[i] = g_ppp_nic_cust_desc[i].max_num;
            ppp_ndis_err("nic_type %d num %d overflow, max_num %d\n", i, cust_nic.num[i],
                g_ppp_nic_cust_desc[i].max_num);
            g_cust_stat.init.nva_nic_num_overflow++;
        }
    }

    ret = memcpy_s(nic_num, sizeof(nv_ppp_ndis_nic_num_feature_s), &cust_nic, sizeof(nv_ppp_ndis_nic_num_feature_s));
    return ret;
}

static int ppp_ndis_get_nva_mac_info(nv_ppp_ndis_mac_cust_feature_s *cust_info)
{
    int ret;
    unsigned int i;
    unsigned int j;
    unsigned int offset;

    ret = bsp_nv_read(NVA_ID_DRV_PPP_NDIS_MAC_CUST, (unsigned char *)cust_info, sizeof(nv_ppp_ndis_mac_cust_feature_s));
    if (ret) {
        ppp_ndis_err("cust mac read nva fail, use defualt mac address\n");
        ret = memset_s(cust_info, sizeof(nv_ppp_ndis_mac_cust_feature_s), 0, sizeof(nv_ppp_ndis_mac_cust_feature_s));
    }

    for (i = 0; i < PPP_NDIS_NIC_TYPE_LAST; i++) {
        for (j = 0; j < g_nic_num_info.num[i]; j++) {
            offset = ppp_ndis_get_nic_offset(i, j + 1);
            if (cust_info->mac_info[offset].state != PPP_NDIS_CUST_ENABLE) {
                // 使用默认mac地址
                ret = memset_s(cust_info->mac_info[offset].mac_addr, ETH_ALEN, 0, ETH_ALEN);
            }
        }
    }

    return ret;
}

int ppp_ndis_cust_mac_init(void)
{
    int ret;
    unsigned int max_len;

    ppp_ndis_info("[init] cust mac start\n");

    (void)memset_s(&g_cust_stat, sizeof(g_cust_stat), 0, sizeof(g_cust_stat));

    ret = ppp_ndis_get_nva_nic_num(&g_nic_num_info);
    if (ret) {
        g_cust_stat.init.num_err++;
        ppp_ndis_err("read nva nic_num err = %d\n", ret);
        return ret;
    }

    ret = ppp_ndis_get_nva_mac_info(&g_cust_mac_info);
    if (ret) {
        g_cust_stat.init.mac_info_err++;
        ppp_ndis_err("read nva mac info err = %d\n", ret);
        return ret;
    }

    ppp_ndis_calc_nva_offset_init();
    max_len = sizeof(struct ppp_ndis_cust_mac_user_data) + PPP_NDIS_CUST_MAC_MAX_LEN;
    ret = bsp_mci_atp_mod_register(ATP_MOD_ID_CUST_MAC, ppp_ndis_cust_mac_proc_func, PPP_NDIS_CUST_MAC_TIMEOUT_MS,
        max_len);
    if (ret) {
        g_cust_stat.init.atp_register_err++;
        ppp_ndis_err("atp register error, err = %d\n", ret);
        return ret;
    }

    g_cust_stat.init.done++;
    ppp_ndis_info("[init] cust mac ok\n");
    return 0;
}

struct ppp_ndis_cust_mac *ppp_ndis_get_cust_mac_info(unsigned int nic_type, unsigned int nic_id)
{
    unsigned int offset;

    if (nic_type >= PPP_NDIS_NIC_TYPE_LAST) {
        ppp_ndis_err("error nic_type %d\n", nic_type);
        return NULL;
    }

    if (ppp_ndis_check_nic_id(false, nic_type, nic_id)) {
        ppp_ndis_err("nic id %d err\n", nic_id);
        return NULL;
    }

    offset = ppp_ndis_get_nic_offset(nic_type, nic_id);

    return &g_cust_mac_info.mac_info[offset];
}

static void ppp_ndis_init_stat_show(struct ppp_ndis_init_stat *stat)
{
    bsp_err("=============init================");
    bsp_err("read_nva_nic_num_err %d\n", stat->read_nva_nic_num_err);
    bsp_err("nic_num err          %d\n", stat->num_err);
    bsp_err("mac_info_err         %d\n", stat->mac_info_err);
    bsp_err("nva_nic_num_overflow %d\n", stat->nva_nic_num_overflow);
    bsp_err("atp_register_err     %d\n", stat->atp_register_err);
    bsp_err("init done            %d\n", stat->done);
    bsp_err("\n");
}

static void ppp_ndis_cmd_pre_proc_stat_show(struct ppp_ndis_cmd_pre_proc_stat *stat)
{
    bsp_err("=============cmd_pre_proc================");
    bsp_err("proc_cnt     %d\n", stat->proc_cnt);
    bsp_err("buf_null     %d\n", stat->buf_null);
    bsp_err("len_err      %d\n", stat->len_err);
    bsp_err("nic_type_err %d\n", stat->nic_type_err);
    bsp_err("cmd_id_err   %d\n", stat->cmd_id_err);
    bsp_err("\n");
}

static void ppp_ndis_set_mac_stat_show(struct ppp_ndis_set_mac_stat *stat)
{
    bsp_err("=============set_mac_stat================");
    bsp_err("proc_cnt         %d\n", stat->proc_cnt);
    bsp_err("len_err          %d\n", stat->len_err);
    bsp_err("nic_num_err      %d\n", stat->nic_num_err);
    bsp_err("recheck_len_err  %d\n", stat->recheck_len_err);
    bsp_err("nic_id_err       %d\n", stat->nic_id_err);
    bsp_err("same             %d\n", stat->same);
    bsp_err("write_nva_err    %d\n", stat->write_nva_err);
    bsp_err("\n");
}

static void ppp_ndis_get_mac_stat_show(struct ppp_ndis_get_mac_stat *stat)
{
    bsp_err("=============get_mac_stat================");
    bsp_err("proc_cnt         %d\n", stat->proc_cnt);
    bsp_err("len_err          %d\n", stat->len_err);
    bsp_err("nic_id_err       %d\n", stat->nic_id_err);
    bsp_err("recheck_len_err  %d\n", stat->read_nva_mac_err);
    bsp_err("nic_id_not_all   %d\n", stat->nic_id_not_all);
    bsp_err("\n");
}

static void ppp_ndis_restore_default_stat_show(struct ppp_ndis_restore_default_stat *stat)
{
    bsp_err("=============restore_default_stat================");
    bsp_err("proc_cnt         %d\n", stat->proc_cnt);
    bsp_err("len_err          %d\n", stat->len_err);
    bsp_err("nic_id_err       %d\n", stat->nic_id_err);
    bsp_err("same             %d\n", stat->same);
    bsp_err("nic_id_not_all   %d\n", stat->nic_id_not_all);
    bsp_err("write_nva_err    %d\n", stat->write_nva_err);
    bsp_err("\n");
}

int ppp_ndis_cust_mac_stat_show(void)
{
    ppp_ndis_init_stat_show(&g_cust_stat.init);
    ppp_ndis_cmd_pre_proc_stat_show(&g_cust_stat.cmd_pre_proc);
    ppp_ndis_set_mac_stat_show(&g_cust_stat.set_mac);
    ppp_ndis_get_mac_stat_show(&g_cust_stat.get_mac);
    ppp_ndis_restore_default_stat_show(&g_cust_stat.restore_default);
    return 0;
}

int ppp_ndis_debug_mac_info(unsigned int nic_type, unsigned int nic_id)
{
    struct ppp_ndis_cust_mac *info = NULL;

    info = ppp_ndis_get_cust_mac_info(nic_type, nic_id);
    if (info == NULL) {
        return -1;
    }

    ppp_ndis_err("state %d addr %02X-%02X-%02X-%02X-%02X-%02X\n", info->state, info->mac_addr[0], info->mac_addr[1],
        info->mac_addr[2], info->mac_addr[3], info->mac_addr[4], info->mac_addr[5]);

    return 0;
}
