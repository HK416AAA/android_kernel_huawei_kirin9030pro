/*
 * ffts_hw_config.c
 *
 * ffts hardware config
 *
 * Copyright (c) 2023-2030 Huawei Technologies Co., Ltd.
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
#ifndef _FFTS_HW_CONFIG_H_
#define _FFTS_HW_CONFIG_H_

#include <linux/types.h>
#include <linux/atomic.h>

#include "inc/ffts_common.h"
#include "dfx/bbox/ffts_dfx_black_box.h"
#include "core/ffts_proc_ctx.h"
#include "core/ffts_ioctl_services.h"

#define FFTS_RTB_ADDR_L_MASK 0xFF80
#define FFTS_RTB_ADDR_H_MASK 0xFFFFFFF0000
#define FFTS_SIG_CTX_NUM_MAX 32767
#define FFTS_SIG_HASH_NUM 7
#define FFTS_SIG_INFO_NUM 8

struct ffts_ready_task_qos {
	unsigned int rd_ptr : 13;
	unsigned int ostd_l : 3;
	unsigned int wt_ptr : 13;
	unsigned int ostd_h : 3;
};

struct ffts_hw_proc_ctx {
	unsigned int  rtb_full_state : 8; /* bit[0-7] */
	unsigned int  irq_en : 8; /* bit[8-15] */

	unsigned int  tcnt : 16; /* bit[16-31] */
	unsigned int  scnt : 16; /* bit[32-47] */
	unsigned int  vcnt : 16; /* bit[48-63] */

	unsigned int  tcb_vaddr_l : 32; /* bit[64-95] */

	unsigned int  tcb_vaddr_h : 7; /* bit[96-102] */
	unsigned int  reserved1 : 1; /* bit[103] */
	unsigned int  hw1_type_en : 4; /* bit[104-107] */
	unsigned int  hw2_type_en : 4; /* bit[108-111] */
	unsigned int  reserved2 : 7; /* bit[112-118] */
	unsigned int  rtb_addr_l : 9;

	unsigned int  rtb_addr_h : 28; /* bit[119-143] */
	unsigned int  rtb_st : 2; /* bit[156-157] */
	unsigned int  valid : 1; /* bit[158] */
	unsigned int  reserved3 : 1; /* bit[159] */

	struct ffts_ready_task_qos ready_task_qos[8]; /* bit[160-415] */
	unsigned int ready_task_req_cnt_l : 32; /* bit[416-447] */
	unsigned int ready_task_req_cnt_h : 32; /* bit[448-479] */
	unsigned int  reserved4 : 16; /* bit[480-495] */
	unsigned int  reserved5 : 16; /* bit[496-511] */
};

struct ffts_hw_thread_ctx {
	unsigned long long  sq_wr_idx : 8; /* bit[0-7] */
	unsigned long long  sq_rd_idx : 8; /* bit[8-15] */
	unsigned long long  sq_vld : 1; /* bit[16] */
	unsigned long long  sync_wait : 1; /* bit[17] */
	unsigned long long  sync_err : 1; /* bit[18] */
	unsigned long long  qos_k : 3; /* bit[19-21] */
	unsigned long long  reserved1 : 1; /* bit[22] */
	unsigned long long  sq_addr_l : 9; /* bit[23-47] */

	unsigned long long  sq_addr_h : 28; /* bit[23-47] */
	unsigned long long  valid : 1; /* bit[60-60] */
	unsigned long long  err : 1; /* bit[61-61] */
	unsigned long long  reserved2 : 2; /* bit[62-63] */
};

struct ffts_hw_task_ctx {
	unsigned long long status : 4; /* bit[0-3] */
	unsigned long long procid : 12; /* bit[4-15] */
	unsigned long long parent_task_idx : 16; /* bit[16-31] */
	unsigned long long funcptr1 : 32; /* bit[32-63] */
	unsigned long long funcptr2 : 7; /* bit[64-70] */
	unsigned long long is_ss : 1; /* bit[71] */
	unsigned long long dep_cnt : 4; /* bit[72-75] */
	unsigned long long qos : 3; /* bit[76-78] */
	unsigned long long auto_rel : 1; /* bit[79] */
	unsigned long long wait_submit_cnt : 16; /* bit[80-95] */
	unsigned long long wait_child_cnt : 16; /* bit[96-111] */
	unsigned long long hwtype : 6; /* bit[112-117] */
	unsigned long long user_bit : 1; /* bit[118] */
	unsigned long long sync_flag : 1; /* bit[119] */
	unsigned long long err_process : 1; /* bit[120] */
	unsigned long long err_group : 3; /* bit[121-123] */
	unsigned long long rdy_task_opc : 3; /* bit[124-126] */
	unsigned long long user_cancel : 1; /* bit[127] */
	unsigned long long other[6];
};

typedef union {
	uint32_t value;
	struct {
		uint32_t valid : 1;   // bit 0
		uint32_t rsv : 3;   // bit 1~3  reserved
		uint32_t src_id : 6;   // bit 4~9
		uint32_t dst_id : 6;   // bit 10~15
		uint32_t uid : 12;  // bit 16~27  reserved
		uint32_t rsv1 : 4;
	} data;
} ffts_hts_auth_table;
 
#pragma pack(1)
 
struct ffts_hw_sig_value {
	unsigned long long signature : 39;       /* bit[0-38] */
	unsigned long long rsd1 : 1;             /* bit[39] */
	unsigned long long vld : 1;          	 /* bit[40] */
	unsigned long long status : 1;           /* bit[41] */
	unsigned long long rsd2 : 2;             /* bit[42-43] */
	unsigned long long procid : 12;          /* bit[44-55] */
	unsigned long long veridx : 16;         /* bit[56-71] */
};
 
struct ffts_hw_task_ctx_sig_info {
	unsigned long long veridx : 16;         /* bit[0-15] */
	unsigned long long sighashidx : 3;      /* bit[16-18] */
	unsigned long long sigidx : 17;         /* bit[19-35] */
	unsigned long long rsd2 : 10;           /* bit[36-45] */
	unsigned long long sigType : 2;         /* bit[46-47 */
};
 
struct ffts_hw_sig_ctx {
	struct ffts_hw_sig_value sig_value[FFTS_SIG_HASH_NUM];
	unsigned long long rsd : 8;
};
 
#pragma pack()

typedef struct{
	int (*hold_cb)(void);
	int (*release_cb)(u16 uid);
} hw_proc_block_cb;

typedef int (*ffap1_clear_cb)(u16);

enum HW_BLOCK_STATE{
	HW_BLOCK_IDLE = 0,
	HW_BLOCK_RUNNING = 1,
	HW_BLOCK_RUNNING_ = 2,
	HW_BLOCK_COMPLETE = 3,
};

typedef enum {
	TASK_STATUS_IDLE = 0,
	TASK_STATUS_PENDING = 1,
	TASK_STATUS_READY = 2,
	TASK_STATUS_BLOCKED = 3,
	TASK_STATUS_FINISHED = 4,
	TASK_STATUS_WAIT_SUBMIT = 5,
	TASK_STATUS_READY_NOT_PUSH = 6,
	TASK_STATUS_MAX = 7,
} task_status_e;

struct ffts_task_status_info {
	uint16_t taskStatusCnt[TASK_STATUS_MAX];
	uint16_t taskRequestStatusCnt[TASK_STATUS_MAX];
};

int ffts_plat_set_hw_proc_ctx(u16 uid, phys_addr_t rtb_addr);
int ffts_plat_reset_hw_proc_ctx(u16 uid);
int ffts_set_tcb_procctx_table(int uid, vir_addr_t tcb_addr);

int ffts_plat_set_hw_thread_ctx(u16 ffts_tid, struct ffts_mem_info *sq_des);
int ffts_plat_reset_hw_thread_ctx(u16 ffts_tid);
void ffts_plat_thread_switch_config(u8 lpid, u16 uid, u16 ffts_tid, u8 qos);

void ffts_plat_proc_block_handle(struct ffts_dev_ctx *dev_ctx, struct ffts_proc_ctx *proc_ctx);
void ffts_ffap1_clear_handle(struct ffts_dev_ctx *dev_ctx, u16 task_id);
void ffts_plat_dump_info(struct ffts_dev_ctx *dev_ctx);

void ffts_set_hw_powerdown_flag(ffts_hw_t hw_type);
uint32_t ffts_check_hw_block_state(ffts_hw_t hw_type);
void ffts_hw_proc_block_regist(void* hw_ffap1_status_hold_cb, void* hw_resource_clear_cb, ffts_hw_t hw_type);
void ffts_hw_proc_block_unregist(ffts_hw_t hw_type);
void ffts_ffap1_clear_entry_regist(ffap1_clear_cb clear_cb, ffts_hw_t hw_type);
void ffts_ffap1_clear_entry_unregist(ffts_hw_t hw_type);
void ffts_insert_global_excp_info(u16 uid, u16 modelid, u16 taskid);
int ffts_get_global_excp_info(u16 uid, struct ffts_global_excp_info *global_excp_info);
int ffts_check_global_block_state(ffts_hw_t hw_type);
int ffts_hw_block_en(ffts_hw_t hw_type);
int ffts_hw_block_dis(ffts_hw_t hw_type);
void ffts_hw_block_rdr_exception_report(ffts_hw_t hw_type);
void ffts_cache_cmo_flush(void);
int ffts_set_device_info_mem_size(ffts_device_info_t *device_info);
int ffts_get_map_info(struct ffts_proc_ctx *proc_ctx, ffts_mem_type map_type,
	unsigned long *base, unsigned long *len, struct list_head **vma_list);

int ffts_get_qos_task_cnt(u16 uid, u8 qos);
void ffts_plat_get_task_status_info(u16 uid, struct ffts_task_status_info *task_info);
void ffts_dump_task_info(u16 uid, u16 tid, u16 taskidx);
#endif