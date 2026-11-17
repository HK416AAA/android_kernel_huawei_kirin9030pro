/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
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

#ifndef AVS_COLLECTION_H
#define AVS_COLLECTION_H

#define MAX_U64_STR_SIZE 16
#define MAX_FILE_SIZE 1024
#define AVS_COLLECT_MODE 0644
#define AVS_FILE_DATA_CHMOD 0755

#define WRITE_HPM_TEST_DATA 0
#define WRITE_SINGLE_HPM_TEST_DATA 1
#define WRITE_VTRIM_TEST_DATA 2
#define VTRIM_TEST_TEMP 0xff

#define HPM_TEST_CONFIG_FILE_PATH "/data/avs_test/hpm_test.txt"
#define VTRIM_TEST_CONFIG_FILE_PATH "/data/avs_test/vtrim_test.txt"

#define AVS_TEST_FILE_NAME_LEN 64
#define TEMP_STR_NAME_LEN 20
#define RESULT_DATA_LINE_LEN 512
#define VTRIM_CFG_LINE 3

typedef struct {
    struct workqueue_struct *avs_coll_wq;
    struct work_struct avs_coll_work;
} avs_coll_workqueue_s;

typedef enum {
    HPM_G_0,
    HPM_G_1,
    HPM_G_2,
    HPM_G_3,
    HPM_G_MAX,
} hpm_group_e;

typedef enum {
    HPM_VT0,
    HPM_VT1,
    HPM_VT2,
    HPM_VT3,
    HPM_VT4,
    HPM_VT5,
    HPM_VT6,
    HPM_VT7,
    HPM_VT8,
    HPM_VT9,
    HPM_VT10,
    HPM_VT11,
    HPM_VT12,
    HPM_VT13,
    HPM_VT14,
    HPM_VT15,
    HPM_VT16,
    HPM_VT17,
    HPM_VT18,
    HPM_VT19,
    HPM_VT20,
    HPM_VT21,
    HPM_VT22,
    HPM_VT23,
    HPM_VT24,
    HPM_VT25,
    HPM_VT26,
    HPM_VT27,
    HPM_VT28,
    HPM_VT29,
    HPM_VT_MAX
} hpm_vt_e;

typedef enum {
    CFG_CORE_ID = 0,
    CFG_TEMP_NUM,
    CFG_VOLT_NUM,
    CFG_TEMP_STEP,
    CFG_VOLT_STEP,
    CFG_TARGET_TEMP_GAP,
    CFG_UPPER_LIMIT_TEMP,
    CFG_LOWER_LIMIT_TEMP,
    CFG_UPPER_LIMIT_VOLT,
    CFG_LOWER_LIMIT_VOLT,
    CFG_HPM_TEST_NUM_MAX,
} avs_coll_test_cfg_e;

typedef enum {
    CFG_VTRIM_TEST_CORE_ID = 0,
    CFG_VTRIM_TEST_GROUP_ID,
    CFG_VTRIM_TEST_TARGET_HPM_NUM,
    CFG_VTRIM_TEST_MAX_VOLT,
    CFG_VTRIM_TEST_MIN_VOLT,
    CFG_VTRIM_TEST_NUM_MAX,
} avs_vtrim_test_cfg_e;

typedef enum {
    AVS_COLL_HPM_TEMP_UP_TEST = 0,
    AVS_COLL_HPM_TEMP_DOWN_TEST,
    AVS_COLL_HPM_SINGLE_TEST,
    AVS_COLL_VTRIM_TEST,
    AVS_COLL_TEST_MAX,
} avs_coll_test_type_e;

typedef struct {
    u16 volt;
    u16 hpm_value[HPM_G_MAX][HPM_VT_MAX];
} hpm_value;

typedef struct {
    hpm_value hpm_val;
} avs_hpm_coll_result;

typedef struct {
    u8 core_id;
    u8 temp_flag; // 0: temp up, 1: temp down
    u8 temp_num;
    u8 volt_num;
    u8 temp_step;
    u8 volt_step;
    u8 target_temp_gap;
    u8 upper_limit_temp;
    u8 lower_limit_temp;
    u16 upper_limit_volt;
    u16 lower_limit_volt;
} avs_hpm_coll_cfg;

typedef struct {
    u8* share_mem;
    signed char cur_test_temp;
    avs_hpm_coll_result *hpm_coll_res; /* 测试结果数组，数组长度为volt数量 */
    avs_hpm_coll_cfg hpm_coll_cfg;
} avs_hpm_coll_test_ctrl;

typedef struct {
    u8* share_mem;
    signed char cur_test_temp;
    avs_hpm_coll_result hpm_single_result;
} avs_hpm_single_test_ctrl;

typedef struct {
    u8 core_id;
    u16 group_id;
    u16 target_hpm_num;
    u16 target_hpm_gap[HPM_VT_MAX];
    u16 target_hpm_val[HPM_VT_MAX];
    u32 vtrim_test_max_volt;
    u32 vtrim_test_min_volt;
} avs_vtrim_test_cfg;

typedef struct {
    avs_vtrim_test_cfg vtrim_test_cfg;
    u32 vtrim_test_res[HPM_VT_MAX];
} avs_vtrim_test_ctrl;

int avs_coll_test_init(void);

#endif