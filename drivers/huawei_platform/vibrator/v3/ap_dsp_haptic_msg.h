/*
 * ap_dsp_haptic_msg.h
 *
 * common define for ap to dsp haptic msg
 *
 * Copyright (c) 2024 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#ifndef __AP_DSP_HAPTIC_MSG_H__
#define __AP_DSP_HAPTIC_MSG_H__

#include <linux/types.h>

/* define msg head tag for ap to dsp */
struct haptic_start_msg_t {
	uint16_t msg_id;
	uint16_t reversed;
	uint32_t session_id;
	uint32_t data_len;
	uint32_t sample_rate;
	uint32_t ch_num;
	uint32_t default_re0;
	uint32_t default_re1;
	uint32_t default_haptic0_f0;
	uint32_t default_haptic1_f0;
	uint32_t start_time;
	bool is_auto_brake;
	bool is_update_default_re; // only factory test stage need update default re
	bool is_sync_stream;
	uint8_t resv;
	uint32_t vendor_id;
	int32_t depth;
	uint32_t calib_haptic0_f0;
	uint32_t calib_haptic1_f0;
};

struct haptic_stop_msg_t {
	uint16_t msg_id;
	uint16_t reversed;
};

struct haptic_f0_start_msg {
	uint16_t msg_id;
	uint16_t reversed;
	uint32_t vendor_id;
	uint32_t default_re[2]; // default_re[1] is not used for single haptic
};

struct haptic_update_sh_buf_msg_t {
	uint16_t msg_id;
	uint16_t reversed;
	uint32_t data_len;
};

struct haptic_set_params_msg {
	uint16_t msg_id;
	uint16_t reserved;
	uint32_t pa_version;
};

/* define msg head tag for dsp to ap */
struct haptic_start_cnf_msg {
	uint16_t msg_id;
	uint16_t reversed;
	uint32_t session_id;
	int32_t ret;
};

struct haptic_f0_start_cnf_msg_t {
	uint16_t msg_id;
	uint16_t reserved;
	int32_t haptic_f0_val[2]; // haptic_f0_val[1] is not used for single haptic
};

struct haptic_play_done_to_ap_msg {
	uint16_t msg_id;
	uint16_t reserved;
	uint32_t session_id;
	uint32_t new_re[2]; // new_re[1] is not used for single haptic
	uint32_t new_f0[2]; // new_f0[1] is not used for single haptic
};

struct req_haptic_data_msg {
	uint16_t msg_id;
	uint16_t reversed;
};

/* define msg info for hal to kernel */
struct haptic_cali_rst_t {
	int cal_rst;
	int cali_val;
};

#endif
