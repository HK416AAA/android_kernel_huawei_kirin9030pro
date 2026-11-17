/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2025. All rights reserved.
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
#include <product_config.h>
#include <securec.h>
#include <linux/delay.h>
#include <linux/ktime.h>
#include <linux/timekeeping.h>
#include <linux/workqueue.h>
#include <osl_types.h>
#include <osl_malloc.h>
#include <bsp_dt.h>
#include <bsp_dump.h>
#include <bsp_file_ops.h>
#include <dump_infra.h>
#include <dump_rdr_wrapper.h>
#include <dump_logs.h>
#include <dump_exc_mgr.h>
#include <dump_subsys_mgr.h>
#include "dump_log_cut_strategy.h"
#include "dump_log_strategy.h"

#ifndef CONFIG_BBOX_LOG_DIR
#define DUMP_LOG_ROOT "/data/hisi_logs"
#define DUMP_MODEM_RESET_LOG_DIR "/data/hisi_logs/modem_log"
#define DUMP_MODEM_RESET_LOG_PATH ("/data/hisi_logs/modem_log" "/reset_history.log")

#error NO BBOX_LOG_DIR DEFINED

#else
// CONFIG_BBOX_LOG_DIR 以'/'结尾,例如"/data/xx_logs/"
#define DUMP_LOG_ROOT CONFIG_BBOX_LOG_DIR
#define DUMP_MODEM_RESET_LOG_DIR (CONFIG_BBOX_LOG_DIR "modem_log")
#define DUMP_MODEM_RESET_LOG_PATH (CONFIG_BBOX_LOG_DIR "modem_log/reset_history.log")
#endif

#define DUMP_WAIT_MODEM_RESETLOG_CNT 200
#define DUMP_WAIT_MODEM_RESETLOG_SLEEP_MS 500

#define DUMP_MODEM_RST_INFO_MAGIC 0x5A5A0001
#define DUMP_MODEM_RST_POLICY_NUM 8
#define DUMP_MODEM_RST_RECORD_NUM 128

// 设置一个上限，一般modid段不会太多；若该值增加太大，那dump_log_cut_dts_cfg的实现需要修改，不能用静态成员，需要malloc内存
#define DUMP_MODEM_RST_POLICY_MODID_MAX_NUM 16

enum dump_modem_rst_policy {
    DUMP_MODEM_POLICY_SOC_AVS_ONOFF = 0, // 后面把avs onoff和log_cut_strategy合并
    DUMP_MODEM_POLICY_CUT_MODEM_BETA_LOG = 1,
    DUMP_MODEM_POLICY_BUTT,
    // 枚举数量需小于 DUMP_MODEM_RST_POLICY_NUM
};

struct dump_modem_rst_record {
    u32 modid;
    u32 time; /* 1970年开始的秒数 */
    u32 subsys;
    u32 resv;
};

struct dump_modem_rst_policy_record {
    u32 from_seq_id;
    u32 policy;
};

struct dump_modem_rst_info {
    u32 magic;
    u32 seq_id;
    u32 resv0;
    u32 resv1;
    struct dump_modem_rst_policy_record policy_info[DUMP_MODEM_RST_POLICY_NUM];
    struct dump_modem_rst_record rst_info[DUMP_MODEM_RST_RECORD_NUM];
};

struct dump_log_cut_dts_cfg {
    u32 time_th_second;
    u32 max_save_cnt;
    u32 inited;
};

struct dump_modem_rst_history_ctrl {
    u32 log_inited;
    struct workqueue_struct *wq;
    struct work_struct init_work;
};


struct dump_beta_log_cut_policy {
    u32 save_cnt : 8;
    u32 last_apply_id : 8;
    u32 reserved1 : 16; /* 保留 */
};

typedef void (*dump_modem_rst_history_policy_func_t)(void);
void dump_modem_rst_history_update_log_cut_policy(void);

#define DUMP_BETA_LOG_STRATEGY_GEN_POLICY(seq_id, save_cnt) (u32)((((seq_id) & 0xFFFF) << 8) | ((save_cnt) & 0xFF))
#define DUMP_BETA_LOG_STRATEGY_GET_SAVE_CNT_FROM_POLICY(policy) (u32)((policy) & 0xFF)
#define DUMP_BETA_LOG_STRATEGY_GET_SEQ_ID_FROM_POLICY(policy) (u32)(((policy) >> 8) & 0xFFFF)
#define DUMP_BETA_LOG_STRATEGY_IS_SEQ_ID_EQ_POLICY(seq_id, policy) (((seq_id) & 0xFFFF) == (((policy) >> 8) & 0xFFFF))

__ro_after_init struct dump_log_cut_dts_cfg g_dump_beta_log_strategy_dts_cfg;
__ro_after_init struct dump_modem_rst_info *g_dump_modem_rst_info;
struct dump_modem_rst_history_ctrl g_dump_rst_history_ctrl;
const dump_modem_rst_history_policy_func_t g_dump_modem_rst_history_policy_cbs[] = {
    dump_modem_rst_history_update_log_cut_policy,
};

u32 dump_check_modem_fulldump_log_need_cut(void)
{
    return 0; // 非OHOS版本，直接返回0，不进行日志裁剪
}

int dump_modem_rst_history_record_flush(void)
{
    struct file *fd = NULL;
    unsigned long fs;
    int ret;
    loff_t pos = 0;

    if (g_dump_modem_rst_info == NULL) {
        return DUMP_ERROR;
    }

    fd = dump_open(DUMP_MODEM_RESET_LOG_PATH, O_CREAT | O_RDWR | O_SYNC, DUMP_LOG_FILE_AUTH);
    if (fd == NULL) {
        return DUMP_ERROR;
    }

    fs = get_fs();
    set_fs((mm_segment_t)KERNEL_DS);

    ret = kernel_write(fd, g_dump_modem_rst_info, sizeof(struct dump_modem_rst_info), &pos);
    if (ret != sizeof(struct dump_modem_rst_info)) {
        dump_error("dump avs file write fail\n");
    }

    (void)vfs_fsync(fd, 0);
    (void)filp_close(fd, NULL);
    set_fs(fs);
    return DUMP_OK;
}

void dump_modem_rst_history_update_record(u32 modid, u32 time, u32 subsys)
{
    u32 cur_idx = g_dump_modem_rst_info->seq_id % DUMP_MODEM_RST_RECORD_NUM;
    g_dump_modem_rst_info->rst_info[cur_idx].modid = modid;
    g_dump_modem_rst_info->rst_info[cur_idx].time = time;
    g_dump_modem_rst_info->rst_info[cur_idx].subsys = subsys;
    g_dump_modem_rst_info->seq_id++;
}

void dump_modem_rst_history_update_log_cut_policy(void)
{
    u32 cur_seq_id = g_dump_modem_rst_info->seq_id;
    u32 record_num = cur_seq_id >= DUMP_MODEM_RST_RECORD_NUM ? DUMP_MODEM_RST_RECORD_NUM : cur_seq_id;
    u32 start_idx = g_dump_modem_rst_info->policy_info[DUMP_MODEM_POLICY_CUT_MODEM_BETA_LOG].from_seq_id;
    u32 curr_policy = g_dump_modem_rst_info->policy_info[DUMP_MODEM_POLICY_CUT_MODEM_BETA_LOG].policy;
    u32 max_save_cnt = g_dump_beta_log_strategy_dts_cfg.max_save_cnt;
    u32 time_th = g_dump_beta_log_strategy_dts_cfg.time_th_second;
    u32 idx, time_start, curr_save_cnt;

    if (!g_dump_beta_log_strategy_dts_cfg.inited) {
        dump_print("no beta log cut cfg\n");
        return;
    }

    curr_save_cnt = DUMP_BETA_LOG_STRATEGY_GET_SAVE_CNT_FROM_POLICY(curr_policy);

    // 异常处理，start index不应大于current index, 不用考虑回卷，因为即使最快1分钟复位1次，U32数据也足够记录了
    // 初始条件处理，如果start_idx == 0, 说明之前没有记录复位信息，需要初始化策略信息；此时不用考虑回卷，因为实际设备不可能复位U32_MAX次
    if ((start_idx > cur_seq_id) || (start_idx == 0)) {
        // 异常时重新计数，以当前为第一次保存log时间记录
        g_dump_modem_rst_info->policy_info[DUMP_MODEM_POLICY_CUT_MODEM_BETA_LOG].from_seq_id = cur_seq_id;
        g_dump_modem_rst_info->policy_info[DUMP_MODEM_POLICY_CUT_MODEM_BETA_LOG].policy =
            DUMP_BETA_LOG_STRATEGY_GEN_POLICY(cur_seq_id, 1);
        return;
    }
    // 计算可用复位信息记录数
    if (cur_seq_id - start_idx < record_num) {
        record_num = cur_seq_id - start_idx;
    }

    // 如果当前时间与上次policy时间间隔大于time_th，则重置策略
    idx = (start_idx - 1) % DUMP_MODEM_RST_RECORD_NUM;
    time_start = g_dump_modem_rst_info->rst_info[idx].time;
    idx = (cur_seq_id - 1) % DUMP_MODEM_RST_RECORD_NUM;
    if (g_dump_modem_rst_info->rst_info[idx].time - time_start >= time_th) {
        g_dump_modem_rst_info->policy_info[DUMP_MODEM_POLICY_CUT_MODEM_BETA_LOG].from_seq_id = cur_seq_id;
        g_dump_modem_rst_info->policy_info[DUMP_MODEM_POLICY_CUT_MODEM_BETA_LOG].policy =
            DUMP_BETA_LOG_STRATEGY_GEN_POLICY(cur_seq_id, 1);
        return;
    }

    // 如果间隔在time_th里，则判断curr_save_cnt是否>=max_save_cnt
    if (curr_save_cnt < max_save_cnt) {
        g_dump_modem_rst_info->policy_info[DUMP_MODEM_POLICY_CUT_MODEM_BETA_LOG].policy =
            DUMP_BETA_LOG_STRATEGY_GEN_POLICY(cur_seq_id, curr_save_cnt + 1);
        return;
    }

    // 剩余情况：在time_th里并且max_save_cnt已存满，不更新policy，直接返回
    return;
}

void dump_modem_rst_history_update_policy(void)
{
    u32 i;
    for (i = 0; i < ARRAY_SIZE(g_dump_modem_rst_history_policy_cbs); i++) {
        g_dump_modem_rst_history_policy_cbs[i]();
    }
}

void dump_modem_rst_history_record_once(u32 modid, u32 subsys)
{
    time64_t txc = ktime_get_real_seconds();
    u32 cur_time = (u32)txc;

    dump_modem_rst_history_update_record(modid, cur_time, subsys);
    dump_modem_rst_history_update_policy();
    dump_modem_rst_history_record_flush();
}

void dump_save_modem_rst_log(const dump_exc_log_desc_s *exc_desc, void *priv_data)
{
    UNUSED(priv_data);
    if (g_dump_rst_history_ctrl.log_inited != 1) {
        return;
    }
    if (!dump_valid_exc_desc(exc_desc)) {
        dump_debug("exc_desc inv\n");
        return;
    }

    if (exc_desc->exc_info->subsys_info.e_from_subsys >= DUMP_SUBSYS_MDMBUTT) {
        dump_print("avs_chk:not mdm_exc\n");
        return;
    }

    // normal reset的数据无意义，不进行记录
    if (exc_desc->exc_info->exc_cfg->exc_type != CP_S_NORMALRESET) {
        dump_modem_rst_history_record_once(exc_desc->exc_info->subsys_info.modid, exc_desc->exc_info->subsys_info.e_from_subsys);
    }
}

int dump_modem_rst_history_file_init(struct file *fd)
{
    int ret;
    loff_t pos = 0;
    g_dump_modem_rst_info->magic = DUMP_MODEM_RST_INFO_MAGIC;
    g_dump_modem_rst_info->seq_id = 0;
    ret = kernel_write(fd, g_dump_modem_rst_info, sizeof(struct dump_modem_rst_info), &pos);
    if (ret != sizeof(struct dump_modem_rst_info)) {
        dump_error("dump rst history file init fail %d\n", ret);
        /* 写文件失败不影响重新统计异常信息，只是之前的信息丢失了，默认关avs、复位日志限频重新统计，并重新统计异常复位信息 */
    }
    return DUMP_OK;
}

int dump_read_modem_rst_history_log_from_file(struct file *fd)
{
    int ret;
    ret = kernel_read(fd, g_dump_modem_rst_info, sizeof(struct dump_modem_rst_info), 0);
    if (ret != sizeof(struct dump_modem_rst_info)) {
        dump_error("dump avs file read fail\n");
        return dump_modem_rst_history_file_init(fd);
    }
    if (g_dump_modem_rst_info->magic != DUMP_MODEM_RST_INFO_MAGIC) {
        dump_error("dump avs file check fail\n");
        return dump_modem_rst_history_file_init(fd);
    }
    return DUMP_OK;
}

int dump_modem_rst_log_init(void)
{
    int ret = DUMP_OK;
    unsigned long fs;
    loff_t pos = 0;
    struct file *fd = NULL;

    fd = dump_open(DUMP_MODEM_RESET_LOG_PATH, O_CREAT | O_RDWR | O_SYNC, DUMP_LOG_FILE_AUTH);
    if (fd == NULL) {
        return DUMP_ERRNO_FILE_OPEN;
    }

    fs = get_fs();
    set_fs((mm_segment_t)KERNEL_DS);
    pos = vfs_llseek(fd, 0, SEEK_END);
    if (pos < sizeof(struct dump_modem_rst_info)) {
        ret = dump_modem_rst_history_file_init(fd);
    } else {
        ret = dump_read_modem_rst_history_log_from_file(fd);
    }

    (void)vfs_fsync(fd, 0);
    (void)filp_close(fd, NULL);
    set_fs(fs);

    return ret;
}

__init int dump_modem_rst_history_cfg_init(void)
{
    int ret = DUMP_OK;
    device_node_s *dev_node = NULL;

    dev_node = bsp_dt_find_compatible_node(NULL, NULL, "driver,mdm_dump_cut_cfg");
    if (unlikely(dev_node == NULL)) {
        ret = DUMP_ERRNO_DTS_NODE;
        goto err;
    }
    if (bsp_dt_property_read_u32(dev_node, "time_th", (u32 *)&g_dump_beta_log_strategy_dts_cfg.time_th_second)) {
        ret = DUMP_ERRNO_DTS_PROP;
        goto err;
    }
    if (bsp_dt_property_read_u32(dev_node, "max_save_cnt", (u32 *)&g_dump_beta_log_strategy_dts_cfg.max_save_cnt)) {
        ret = DUMP_ERRNO_DTS_PROP;
        goto err;
    }
    if (g_dump_beta_log_strategy_dts_cfg.max_save_cnt > DUMP_MODEM_RST_RECORD_NUM) {
        ret = DUMP_ERRNO_INVA_PARAM;
        goto err;
    }

    g_dump_beta_log_strategy_dts_cfg.inited = 1;
    return DUMP_OK;

err:
    (void)memset_s(&g_dump_beta_log_strategy_dts_cfg, sizeof(struct dump_log_cut_dts_cfg), 0, sizeof(struct dump_log_cut_dts_cfg));
    return ret;
}

void dump_modem_rst_file_init_work(struct work_struct *work)
{
    int ret;
    unsigned long fs;
    struct kstat stat;
    int timeout = DUMP_WAIT_MODEM_RESETLOG_CNT;
    u32 ready = 0;

    while (timeout) {
        timeout--;
        fs = get_fs();
        set_fs(KERNEL_DS);
        ret = vfs_stat(DUMP_LOG_ROOT, &stat);
        set_fs(fs);
        if (ret) {
            msleep(DUMP_WAIT_MODEM_RESETLOG_SLEEP_MS);
            continue; 
        }
        ready = 1;
        break;
    }
    if (!ready) {
        dump_error("check logdir ret %d\n", ret);
        return;
    }
    ret = dump_modem_rst_log_init();
    if (ret != DUMP_OK) {
        dump_error("init dump_modem_rst_history cfg ret %d\n", ret);
        return;
    }

    g_dump_rst_history_ctrl.log_inited = 1;
    return;
}

__init int dump_modem_rst_history_record_init(void)
{
    int ret;
    dump_work_s work;

    /* 申请成功后，后面禁止释放；因为即使没有dts_cfg或者没有成功创建文件，该变量设计上，也会在复位、msg等场景使用；
     * 这样启动依然有机会进行avs止血等方案，只是每次掉电后之前的策略数据会丢失
     */
    g_dump_modem_rst_info = osl_malloc(sizeof(struct dump_modem_rst_info));
    if (g_dump_modem_rst_info == NULL) {
        return DUMP_ERRNO_MEM_OPS;
    }
    (void)memset_s(g_dump_modem_rst_info, sizeof(struct dump_modem_rst_info), 0, sizeof(struct dump_modem_rst_info));

    INIT_WORK(&g_dump_rst_history_ctrl.init_work, dump_modem_rst_file_init_work);
    g_dump_rst_history_ctrl.wq = alloc_workqueue("mdmdump_hisroty", WQ_UNBOUND | WQ_HIGHPRI, 1);
    queue_work(g_dump_rst_history_ctrl.wq, &g_dump_rst_history_ctrl.init_work);


    work.work_type = DUMP_WORK_ASYNC;
    work.work_fn = dump_save_modem_rst_log;
    work.prior = DUMP_WORK_PRIO_ASYNC_HOOK_COMMON_UPDATE_RST_HISOTRY;
    work.priv_data = NULL;
    dump_subsys_add_work(DUMP_SUBSYS_COMM, &work);

    ret = dump_modem_rst_history_cfg_init();
    if (ret != DUMP_OK) {
        dump_error("init modem_dump_rst_history cfg ret %d\n", ret);
        return ret;
    }

    return DUMP_OK;
}