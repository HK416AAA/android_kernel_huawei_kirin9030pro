/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2025. All rights reserved.
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

#ifndef _DUMP_MEM_H
#define _DUMP_MEM_H

#include "adrv_om.h"
#include "bsp_dump.h"
#include <linux/types.h>
#include <linux/list.h>
#include <linux/spinlock.h>

#ifdef __cplusplus
extern "C" {
#endif

/* field number supported by area */
#define DUMP_FIELD_MAX_NUM 80
/* diferfent area has different field max num */
#define DUMP_FIELD_GLOBAL_MAX_NUM 120

#define DUMP_BUILD_TIME_LEN 32
#define DUMP_PRODUCT_LEN 32
#define DUMP_PRODUCT_VERSION_LEN 32
#define DUMP_UUID_LEN 40
#define DUMP_IMAGEID_LEN 72
#define DUMP_DESC_LEN 48
#define DUMP_DATETIME_LEN 24
#define DUMP_BASEINFO_EXC_DESC_LEN 48
#define DUMP_NAME_LEN 16
#define DUMP_NAME_LEN_SHORT 12

/* field status */
enum {
    DUMP_FIELD_UNUSED = 0,
    DUMP_FIELD_USED = 1,
};

/* areas, max number is 32 */
typedef enum {
    DUMP_AREA_DPAHOST,
    DUMP_AREA_DPAFW,
    DUMP_AREA_DPA_TEEOS,
    DUMP_AREA_DPA_LPMCU,
    DUMP_AREA_BUTT
} dump_area_id_e;

/* struct dump_global_base_info_s中的e_core信息，与RDR枚举保持一致 */
typedef enum {
    DUMP_EXC_CORE_AP = RDR_AP,
    DUMP_EXC_CORE_CP = RDR_CP,
    DUMP_EXC_CORE_LPMCU = RDR_LPM3,
    DUMP_EXC_CORE_MODEMAP = RDR_MODEMAP,
    DUMP_EXC_CORE_DPA = RDR_DPA,
} dump_exc_core_e;

/* 头部接口要与rdr_area.h中定义格式相同 */
#define DUMP_GLOBALE_TOP_HEAD_MAGIC (0x4e524d53)
struct dump_global_top_head_s {
    u32 magic;
    u32 version;
    u32 area_number;
    u32 codepatch;
    u8 build_time[DUMP_BUILD_TIME_LEN];
    u8 product_name[DUMP_PRODUCT_LEN];
    u8 product_version[DUMP_PRODUCT_VERSION_LEN];
    u8 version_uuid[DUMP_UUID_LEN];
};

struct dump_global_area_s {
    u32 offset;
    u32 length;
};

struct dump_global_base_info_s {
    u32 modid;
    u32 arg1;
    u32 arg2;
    u32 e_core; /* @see dump_exc_core_e */
    u32 e_type;
    u32 start_flag;
    u32 savefile_flag;
    u32 reboot_flag;
    u8 e_module[DUMP_NAME_LEN];
    u8 e_desc[DUMP_DESC_LEN];
    u32 timestamp;
    u8 datetime[DUMP_DATETIME_LEN];
};

struct dump_global_struct_s {
    struct dump_global_top_head_s top_head;
    struct dump_global_base_info_s base_info;
    struct dump_global_area_s area_info[DUMP_AREA_BUTT];
    u32 resv_offset;
    u8 padding2[4]; /* add 4 paddings */
};

struct dump_area_mntn_addr_info_s {
    void *vaddr;
    void *paddr;
    u32 len;
};

#define DUMP_SAVE_SUCCESS 0xA4A4A4A4
typedef struct {
    u32 done_flag; // @see DUMP_SAVE_SUCCESS
    u32 voice_flag;
    u32 resave_sec_log;
    u32 modem_reset_flag;
} dump_area_share_info_s;

#define DUMP_AREA_HEAD_NAME (8)
/* area head  */
typedef struct {
    u32 magic_num;
    u32 field_num;
    u8 name[DUMP_AREA_HEAD_NAME];
    dump_area_share_info_s share_info;
} dump_area_head_s;

/* field map */
typedef struct {
    u32 field_id;
    u32 offset_addr;
    u32 length;
    u16 version;
    u16 status;
    u8 field_name[DUMP_NAME_LEN];
} dump_field_map_s;

/* area */
struct dump_area_s {
    dump_area_head_s area_head;
    dump_field_map_s fields[DUMP_FIELD_MAX_NUM];
};

struct dump_field_self_info_s {
    u32 magic_num;
    u32 reserved;
    void *phy_addr;
    void *virt_addr;
};
#define DUMP_LEVEL1_AREA_MAGICNUM (0x4e656464)
#define DUMP_LEVEL1_AREA_EXPIRED_MAGICNUM (0x6464654e)

#define DUMP_FIXED_FIELD(p, id, name, offset, size, version_id) do { \
    ((dump_field_map_s *)(p))->field_id = (id);                                                                  \
    ((dump_field_map_s *)(p))->length = (size);                                                                  \
    ((dump_field_map_s *)(p))->offset_addr = (u32)(offset);                                                      \
    ((dump_field_map_s *)(p))->version = version_id;                                                             \
    ((dump_field_map_s *)(p))->status = DUMP_FIELD_USED;                                                         \
    if (memcpy_s((char *)(((dump_field_map_s *)(p))->field_name), sizeof(((dump_field_map_s *)(p))->field_name), \
                 (char *)(name),                                                                                 \
                 strlen((char *)(name)) < sizeof(((dump_field_map_s *)(p))->field_name)                          \
                        ? strlen((char *)(name))                                                                    \
                        : sizeof(((dump_field_map_s *)(p))->field_name))) {                                         \
        dump_debug("er\n");                                                                                       \
    }                                                                                                            \
} while (0)

#define DUMP_LOAD_MAGIC 0xEEEE1234
typedef struct {
    u32 magic_num;          /* dump加载信息区标识，用于兼容之前版本 */
    u32 dpa_ddr;            /* MODEM DDR加载地址 */
    u32 dpa_dump;           /* MODEM可维可测内存加载地址 */
    u32 ds0l1mem;    /* TSP DSS0 L1 MEM */
    u32 ds1l1mem;    /* TSP DSS1 L1 MEM */
    u32 ds2l1mem;    /* TSP DSS2 L1 MEM */
    u32 ds3l1mem;    /* TSP DSS2 L1 MEM */
    u32 cma_img;  /* cma内存 */
    u32 cma_cache;  /* cma内存 */
    u32 cma_uncache;  /* cma内存 */
    u32 cma_ap_share;  /* cma内存 */
    u32 cma_dfa_share;  /* cma内存 */
    u32 dpa_ddr_cut_size;  /* DPA DDR 裁剪ro/rx size */
    u32 dpa_ddr_data_size;  /* DPA DDR 裁剪必须要保存的data段大小 */
    u32 dpa_fw_ddr_addr;  /* DPA FW 加载静态DDR基地址 */
} dump_load_info_s;

/* 地址随机化需要将偏移offset记录到dump空间尾部 */
#define DUMP_ASLR_START_MAGIC 0x5a5a5a5a
#define DUMP_ASLR_END_MAGIC 0xa5a5a5a5
typedef struct {
    u32 start_magic; /* 0x5a5a5a5a */
    /* 添加aslr需要按照逆序添加 */
    u32 dpafw_aslr_offset;
    u32 end_magic; /* 0xa5a5a5a5 */
} dump_aslr_info_s;

typedef enum {
    DUMP_CTX_TASK = 0x0,
    DUMP_CTX_INT = 0x1
} dump_reboot_ctx_e;

#define DUMP_DPA_CPU_REGS_NUM 37
#define DUMP_DPA_CPUINFO_CALLSTACK_LEN 10
#define DUMP_FLAG_INT_ENTER 0xAAAA0000
#define DUMP_FLAG_INT_EXIT 0xBBBB0000

/* 32位架构CPUINFO */
typedef struct {
    u32 cpu_state;                 /* cpu 状态 */
    dump_reboot_ctx_e current_ctx; /* cpu上下文 */
    u32 current_int;               /* 当前的中断 */
    u32 current_task;              /* 当前正在运行的任务 */
    u8 task_name[DUMP_NAME_LEN];   /* 任务名 */
    u32 reg_set[DUMP_DPA_CPU_REGS_NUM];     /* 寄存器信息 */
    unsigned long callstack[DUMP_DPA_CPUINFO_CALLSTACK_LEN]; /* 调用栈的原始PC信息 */
} dump_dpa_cpu_info_s;

// dump内部使用
int bsp_dpa_dump_mem_init(void);
u8 *bsp_dpa_dump_get_field_map(u32 field_id);
int bsp_dpa_dump_get_area_info(dump_area_id_e areaid, struct dump_area_mntn_addr_info_s *area_info);
u8 *bsp_dpa_dump_get_field_phy_addr(u32 field_id);

#ifdef __cplusplus
}
#endif

#endif /* _DUMP_MEM_H */