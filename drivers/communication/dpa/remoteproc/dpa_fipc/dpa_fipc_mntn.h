/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2020. All rights reserved.
 */

#ifndef _DPA_FIPC_DEBUG_H
#define _DPA_FIPC_DEBUG_H

#include "bsp_slice.h"
#include "dpa_fipc_device.h"

struct dpa_fipc_debug_info {
    unsigned int last_send_stamp; // 最近发送的时间戳
    int last_send_errno; // 错误码
    unsigned int last_send_done_stamp; // 最近发送完成的时间戳
    unsigned int last_recv_stamp; // 最近接收的时间戳
};

struct dpa_fipc_rst_info {
    unsigned int last_before_rst_tm;
    unsigned int last_before_rst_failed_tm;
    unsigned int last_after_rst_tm;
    unsigned int last_after_rst_failed_tm;
    unsigned int last_failed_pipe_id;
    int last_failed_ret;
};

struct dpa_fipc_pmsr_info {
    unsigned int last_pre_suspend_tm;
    unsigned int last_pre_suspend_tm_failed;
    unsigned int last_post_suspend_tm;
    unsigned int last_post_suspend_tm_failed;
    unsigned int last_pre_resume_tm;
    unsigned int last_pre_resume_tm_failed;
    unsigned int last_post_resume_tm;
    unsigned int last_post_resume_tm_failed;
    unsigned int failed_cnt;
    unsigned int last_failed_pipe;
    unsigned int last_failed_ret;
};

int dpa_fipc_debug_init(unsigned int pipe_num);
void dpa_fipc_debug_info_update_send(unsigned int pipe_id, int ret);
void dpa_fipc_debug_info_update_send_done(unsigned int pipe_id);
void dpa_fipc_debug_info_update_recv(unsigned int pipe_id);
unsigned int dpa_fipc_chn_send_recv_tm_dump(unsigned char *buf, unsigned int len);
void dpa_fipc_mntn_report_pipe_regs(struct dpa_fipc_device_t *pdev, unsigned int pipe_id);
unsigned int dpa_fipc_rst_dump(unsigned char *buf, unsigned int len);
unsigned int dpa_fipc_pmsr_dump(unsigned char *buf, unsigned int len);
void dpa_fipc_mntn_print_pipe_regs(struct dpa_fipc_device_t *pdev, unsigned int pipe_id);
#endif
