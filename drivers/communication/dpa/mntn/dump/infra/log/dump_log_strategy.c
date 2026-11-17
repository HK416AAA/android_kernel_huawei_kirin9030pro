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
#include <linux/delay.h>
#include <linux/version.h>
#include <bsp_dt.h>
#include <securec.h>
#include <linux/list.h>
#include <linux/slab.h>
#include <bsp_print.h>
#include <bsp_slice.h>
#include <bsp_file_ops.h>
#include <dump_infra.h>
#include <dump_rdr_wrapper.h>
#include "dump_logs.h"
#include "dump_log_strategy.h"
#include "dump_log_parser.h"
#include "dump_log_cut_strategy.h"

dump_file_info_s g_dump_file_info;

bool dump_get_link_status(void)
{
    return g_dump_file_info.link_enable;
}

int dump_match_log_strategy(const char *file_name, struct dump_file_save_strategy *output)
{
    int index = 0;
    u32 log_sum = g_dump_file_info.log_sum;
    struct dump_file_save_strategy *save_strategy = g_dump_file_info.log_strategy;
    if (file_name == NULL || output == NULL || save_strategy == NULL) {
        return DUMP_ERROR;
    }
    if (memset_s(output, sizeof(struct dump_file_save_strategy), 0, sizeof(struct dump_file_save_strategy)) != EOK) {
        dump_error("set err\n");
        return DUMP_ERROR;
    }
    for (index = 0; index < log_sum; index++) {
        if (strncmp(file_name, save_strategy[index].data_head.filename,
            sizeof(save_strategy[index].data_head.filename)) != 0) {
            continue;
        }
        if (memcpy_s(output, sizeof(struct dump_file_save_strategy), &save_strategy[index],
            sizeof(save_strategy[index])) != EOK) {
            dump_error("cpy err\n");
            return DUMP_ERROR;
        }
        /* 拼接非压缩时，直接拼接；拼接且压缩时，最后在压缩应用中压缩再拼接 */
        if (output->is_append == 0 || output->data_head.magic != DUMP_FILE_TRANS_MAGIC ||
            output->data_head.links != DUMP_FILE_LINKS_MAGIC) {
            return DUMP_ERROR;
        }
        // 压缩文件且压缩服务存在时，不拼接，先压缩
        // dpa 无压缩功能，不压缩
        if (output->is_compress == 1) {
            dump_warning("not support compress log\n");
            return DUMP_ERROR;
        }
        // 如果是beta日志不满足上传限制，先不拼接
        // 该实现能满足当前场景，但若后续有拼接到不同目标文件的需求，此处需要修改
        if (dump_check_dpa_fulldump_log_need_cut()) {
                return DUMP_ERROR;
        }
        return DUMP_OK;
    }
    return DUMP_ERROR;
}


void dump_show_strategy(void)
{
    u32 size;
    int i = 0;
    struct dump_file_save_strategy *log_strategy = g_dump_file_info.log_strategy;
    dump_print("enable:%d\n", g_dump_file_info.link_enable);
    if (log_strategy == NULL) {
        dump_error("g_dump_file_info.log_strategy is null\n");
        return;
    }
    size = g_dump_file_info.log_sum;
    dump_error("log_sum:%u\n", size);
    for (i = 0; i < size; i++) {
        dump_print("filename: %s, dst_file: %s\n", log_strategy[i].data_head.filename,
            log_strategy[i].data_head.dstfilename);
        dump_print("compress: %u, append: %u\n", log_strategy[i].is_compress, log_strategy[i].is_append);
    }
}

int dump_link_probe_src_list(device_node_s *child, struct dump_file_save_strategy *log_strategy, uintptr_t srclist_size,
    struct dump_dstname_list *dstname_list, u32 dstlist_size)
{
    int i, j;
    int ret;
    u32 u = 0;
    const char *temp_char = NULL;
    const __be32 *p = NULL;
    struct property *prop = NULL;

    for (i = 0; i < srclist_size; i++) {
        ret = bsp_dt_property_read_string_index(child, "dump_src_name", i, &temp_char);
        if (ret != 0 || temp_char == NULL) {
            dump_error("get src_name err\n");
            return DUMP_ERROR;
        }
        if (strncpy_s(log_strategy[i].data_head.filename, sizeof(log_strategy[i].data_head.filename), temp_char,
            strnlen(temp_char, DUMP_FILE_NAME_MAX_SIZE)) < 0) {
            dump_error("strncpy err\n");
            return DUMP_ERROR;
        }
        log_strategy[i].data_head.magic = DUMP_FILE_TRANS_MAGIC;
        log_strategy[i].data_head.links = DUMP_FILE_LINKS_MAGIC;
    }

    i = -1;
    j = -1;
    bsp_dt_property_for_each_u32(child, "dump_src_attr", prop, p, u)
    {
        i++;
        if (i % DUMP_LOG_STRATEGY_ATTR_SIZE == 0) {
            j++;
            log_strategy[j].is_compress = u;
        } else if (i % DUMP_LOG_STRATEGY_ATTR_SIZE == 1) {
            log_strategy[j].is_append = u;
        } else {
            if (log_strategy[j].is_append == 0) {
                continue;
            }
            if (u <= 0 || u > dstlist_size) {
                dump_error("u=%u is err\n", u);
                return DUMP_ERROR;
            }
            if (strncpy_s(log_strategy[j].data_head.dstfilename, sizeof(log_strategy[j].data_head.dstfilename),
                dstname_list[u - 1].filename, sizeof(dstname_list[u - 1].filename)) < 0) {
                return DUMP_ERROR;
            }
        }
    }

    if ((i + 1) != DUMP_LOG_STRATEGY_ATTR_SIZE * srclist_size || srclist_size != (j + 1)) {
        return DUMP_ERROR;
    }
    return DUMP_OK;
}

int dump_link_fill_list(device_node_s *child, struct dump_file_save_strategy *log_strategy, uintptr_t srclist_size)
{
    u32 dstlist_size = 0;
    int i;
    int ret = DUMP_ERROR;
    struct dump_dstname_list *dstname_list = NULL;
    const char *temp_char = NULL;
    if (bsp_dt_property_read_u32(child, "dstlistsize", &dstlist_size)) {
        dump_error("get size err\n");
        return DUMP_ERROR;
    }
    dstname_list = (struct dump_dstname_list *)kmalloc(dstlist_size * (sizeof(struct dump_dstname_list)), GFP_KERNEL);
    if (dstname_list == NULL) {
        dump_error("malloc err\n");
        return DUMP_ERROR;
    }
    if (memset_s(dstname_list, dstlist_size * (sizeof(struct dump_dstname_list)), 0,
        dstlist_size * (sizeof(struct dump_dstname_list))) != EOK) {
        dump_error("set err\n");
        goto out;
    }
    for (i = 0; i < dstlist_size; i++) {
        ret = bsp_dt_property_read_string_index(child, "dump_dst_name", i, &temp_char);
        if (ret != 0 || temp_char == NULL) {
            ret = DUMP_ERROR;
            dump_error("get dst_name err\n");
            goto out;
        }
        if (strncpy_s(dstname_list[i].filename, sizeof(dstname_list[i].filename), temp_char,
            strnlen(temp_char, DUMP_FILE_NAME_MAX_SIZE)) < 0) {
            dump_error("strncpy err\n");
            goto out;
        }
    }

    if (dump_link_probe_src_list(child, log_strategy, srclist_size, dstname_list, dstlist_size) != DUMP_OK) {
        dump_error("get src_attr err!\n");
        goto out;
    }
    ret = DUMP_OK;
out:
    if (dstname_list != NULL) {
        kfree(dstname_list);
        dstname_list = NULL;
    }
    return ret;
}

int dump_link_list_init(void)
{
    device_node_s *dev = NULL;
    u32 srclist_size = 0;
    int ret;
    struct dump_file_save_strategy *log_strategy = NULL;
    dev = bsp_dt_find_compatible_node(NULL, NULL, "driver,dpa_dump_linkup_list");
    if (dev == NULL) {
        dump_error("list dts no find\n");
        return DUMP_ERROR;
    }
    ret = bsp_dt_property_read_u32(dev, "srclistsize", &srclist_size);
    if (ret) {
        dump_error("get size err\n");
        return DUMP_ERROR;
    }
    log_strategy =
        (struct dump_file_save_strategy *)kmalloc(srclist_size * (sizeof(struct dump_file_save_strategy)), GFP_KERNEL);
    if (log_strategy == NULL) {
        dump_error("alloc err\n");
        return DUMP_ERROR;
    }
    g_dump_file_info.log_sum = (u32)srclist_size;
    if (memset_s(log_strategy, srclist_size * (sizeof(struct dump_file_save_strategy)), 0,
        srclist_size * (sizeof(struct dump_file_save_strategy))) != EOK) {
        dump_error("set err\n");
        kfree(log_strategy);
        return DUMP_ERROR;
    }
    ret = dump_link_fill_list(dev, log_strategy, srclist_size);
    if (ret) {
        kfree(log_strategy);
        return DUMP_ERROR;
    }

    g_dump_file_info.log_strategy = log_strategy;
    return DUMP_OK;
}

void dump_link_init(void)
{
    device_node_s *dev = NULL;
    u32 link_enable = 0;
    int ret;

    dev = bsp_dt_find_compatible_node(NULL, NULL, "driver,dpa_dump_log_strategy");
    if (dev == NULL) {
        dump_error("strategy dts no find\n");
        g_dump_file_info.link_enable = false;
        return;
    }

    ret = bsp_dt_property_read_u32(dev, "link_enable", &link_enable);
    if (ret || 0 == link_enable) {
        dump_error("link disable\n");
        g_dump_file_info.link_enable = false;
        return;
    }

    ret = dump_link_list_init();
    if (ret == DUMP_OK) {
        g_dump_file_info.link_enable = true;
    } else {
        g_dump_file_info.link_enable = false;
    }
}

bool dump_is_minidump(void)
{
    u32 attr = g_dump_file_info.current_attr;
    if ((attr & DUMP_ATTR_SAVE_MINIDUMP) == DUMP_ATTR_SAVE_MINIDUMP) {
        return true;
    }
    return false;
}

bool dump_is_fulldump(void)
{
    u32 attr = g_dump_file_info.current_attr;
    if ((attr & DUMP_ATTR_SAVE_FULLDUMP) == DUMP_ATTR_SAVE_FULLDUMP) {
        return true;
    }
    return false;
}

dump_product_type_e dump_get_product_type(void)
{
    u32 attr = g_dump_file_info.current_attr;
    if ((attr & DUMP_ATTR_SAVE_MBB) == DUMP_ATTR_SAVE_MBB) {
        return DUMP_MBB;
    } else if ((attr & DUMP_ATTR_SAVE_PHONE) == DUMP_ATTR_SAVE_PHONE) {
        return DUMP_PHONE;
    }
    return DUMP_PRODUCT_BUTT;
}

dump_file_attr_s *dump_get_file_attr(dump_save_file_id_e id)
{
    u32 i;
    for (i = 0; i < g_dump_file_info.file_num; i++) {
        if (id == g_dump_file_info.file_list[i].id) {
            return &g_dump_file_info.file_list[i];
        }
    }
    return NULL;
}

enum dump_subsys dump_get_file_subsys(dump_save_file_id_e id)
{
    u32 attr;
    dump_file_attr_s *fileinfo = dump_get_file_attr(id);
    if (fileinfo != NULL) {
        attr = fileinfo->attr >> DUMP_FILE_SYS_OFFSET;
        switch (attr) {
            case BIT(DUMP_SUBSYS_DPAHOST):
                return DUMP_SUBSYS_DPAHOST;
            case BIT(DUMP_SUBSYS_DPAFW):
                return DUMP_SUBSYS_DPAFW;
            case SUBSYS_COMM_ATTR:
                return DUMP_SUBSYS_COMM;
            default:
                return DUMP_SUBSYS_DPABUTT;
        }
    }
    return DUMP_SUBSYS_DPABUTT;
}

u32 dump_get_save_log_prio(dump_save_file_id_e id)
{
    const static u32 dump_log_prio_map[][2] = {
        {DUMP_SAVE_RESET_LOG, DUMP_WORK_PRIO_ASYNC_HOOK_COMMON_SAVE_RSTLOG_BIN},
        {DUMP_SAVE_DPA_DUMP, DUMP_WORK_PRIO_ASYNC_HOOK_COMMON_SAVE_DPADUMP_BIN},
        {DUMP_SAVE_DPA_DUMP_BACKUP, DUMP_WORK_PRIO_ASYNC_HOOK_COMMON_SAVE_DPADUMP_BACKUP_BIN},
    };
    int i;

    for (i = 0; i < ARRAY_SIZE(dump_log_prio_map); i++) {
        if (id == dump_log_prio_map[i][0]) {
            return dump_log_prio_map[i][1];
        }
    }
    return DUMP_WORK_PRIO_ASYNC_HOOK_COMMON_SAVE_OTHER_BIN;
}

static inline bool is_current_plat_match(u32 except_attr)
{
    u32 current_plat = DUMP_ATTR_DECODE_PLAT(g_dump_file_info.current_attr);
    u32 except_plat = DUMP_ATTR_DECODE_PLAT(except_attr);
    return DUMP_EXISTS_ATTRIBUTE(except_plat, current_plat);
}

static inline bool is_current_dump_level_match(u32 except_attr)
{
    u32 current_level = DUMP_ATTR_DECODE_DUMP_LEVEL(g_dump_file_info.current_attr);
    u32 except_level = DUMP_ATTR_DECODE_DUMP_LEVEL(except_attr);
    return DUMP_EXISTS_ATTRIBUTE(except_level, current_level);
}

static bool dump_is_file_need_save_core(dump_save_file_id_e id, u32 check_full_dump_later)
{
    dump_file_attr_s *file_info = dump_get_file_attr(id);
    if (file_info == NULL) {
        return false;
    }
    if (!file_info->save_flag) {
        return false;
    }
    if (!is_current_plat_match(file_info->attr)) {
        return false;
    }
    if ((!check_full_dump_later) && (!is_current_dump_level_match(file_info->attr))) {
        return false;
    }
    return true;
}

bool dump_is_file_need_save_without_check_fulldump(dump_save_file_id_e id)
{
    return dump_is_file_need_save_core(id ,1);
}

bool dump_is_file_need_save(dump_save_file_id_e id)
{
    return dump_is_file_need_save_core(id ,0);
}

// bbox_check_edition会读取设备节点，因此该接口必须在任务上下文调用
void dump_update_cur_fulldump_attr_if_beta_version(void)
{
    if (g_dump_file_info.current_attr & DUMP_ATTR_SAVE_FULLDUMP) {
        return;
    }

    // phone形态查询是否是beta版本，如果是，打开kernel驱动的fulldump
    if (bbox_check_edition() == EDITION_INTERNAL_BETA) {
        g_dump_file_info.current_attr |= DUMP_ATTR_SAVE_FULLDUMP;
    }
}

void dump_update_log_hook_to_file_info(u32 id, save_hook func)
{
    dump_file_attr_s *file_info = dump_get_file_attr(id);
    if (file_info != NULL) {
        file_info->save_func = func;
    }
}

dump_file_attr_s *dump_get_file_attr_by_save_func(save_hook func)
{
    u32 i;
    for (i = 0; i < g_dump_file_info.file_num; i++) {
        if (func == g_dump_file_info.file_list[i].save_func) {
            return &g_dump_file_info.file_list[i];
        }
    }
    return NULL;
}

void dump_cur_attr_init(void)
{
#ifdef CONFIG_DPA_FULL_DUMP
    g_dump_file_info.current_attr |= DUMP_ATTR_SAVE_FULLDUMP;
#else
    // phone形态查询是否是beta版本，如果是，打开kernel驱动的fulldump
    if (bbox_check_edition() == EDITION_INTERNAL_BETA) {
        g_dump_file_info.current_attr |= DUMP_ATTR_SAVE_FULLDUMP;
        dump_print("detect beta ver\n");
    }
#endif

    // mini dump 不支持定制关闭
    g_dump_file_info.current_attr |= DUMP_ATTR_SAVE_MINIDUMP;

#ifdef CONFIG_MODEM_EXTRA_RDR
    g_dump_file_info.current_attr |= DUMP_ATTR_SAVE_EXTRA_MDM;
#endif

    g_dump_file_info.current_attr |= DUMP_ATTR_SAVE_PHONE;
    dump_print("current_plat_attr=0x%x, num=%d!\n", g_dump_file_info.current_attr, g_dump_file_info.file_num);
}

dump_file_attr_s *dump_get_file_info_storage(dump_save_file_id_e id)
{
    u32 i;
    for (i = 0; i < g_dump_file_info.file_num; i++) {
        if (id == g_dump_file_info.file_list[i].id) {
            dump_error("file[%d] attr overlay\n", id);
            return &g_dump_file_info.file_list[i];
        }
    }
    if (i < g_dump_file_info.list_len) {
        return &g_dump_file_info.file_list[i];
    }
    return NULL;
}

int dump_file_attr_init(device_node_s *dev)
{
    const char *file_name = NULL;
    dump_file_attr_s *file_info = NULL;
    u32 ret, file_id;

    if (dev == NULL) {
        dump_error("para err!\n");
        return DUMP_ERROR;
    }
    file_id = 0xFFFFFFFF;
    ret = (u32)bsp_dt_property_read_u32(dev, "file_id", &file_id);
    if (ret != 0) {
        dump_error("get file_attr fail!\n");
        return (int)ret;
    }
    file_info = dump_get_file_info_storage(file_id);
    if (file_info == NULL) {
        dump_error("file list ovf\n");
        return DUMP_ERROR;
    }
    file_info->id = file_id;
    ret = (u32)bsp_dt_property_read_u32(dev, "save_flag", (u32 *)(uintptr_t)(&file_info->save_flag));
    ret |= (u32)bsp_dt_property_read_string(dev, "file_name", &file_name);
    if ((ret != 0) || (file_name == NULL)) {
        dump_error("get file_attr fail!\n");
        return (int)ret;
    }
    ret = (u32)strncpy_s(file_info->name, sizeof(file_info->name), file_name, strlen(file_name));
    if (ret != EOK) {
        dump_error("file_name strncpy filed!\n");
        return (int)ret;
    }

    if (bsp_dt_property_read_u32(dev, "attribute", &file_info->attr)) {
        dump_error("attribute not found!\n");
        return DUMP_ERROR;
    }
    g_dump_file_info.file_num++;
    return DUMP_OK;
}

void dump_file_cfg_init(void)
{
    device_node_s *dev = NULL;
    device_node_s *child = NULL;
    u32 num = 0;

    dev = bsp_dt_find_compatible_node(NULL, NULL, "driver,dpa_dump_file_cfg");
    if (dev == NULL) {
        dump_error("dump_file_cfg not found");
    }
    num = (u32)bsp_dt_get_child_count(dev);
    g_dump_file_info.file_list = kmalloc(num * sizeof(dump_file_attr_s), GFP_KERNEL);
    if (g_dump_file_info.file_list == NULL) {
        dump_error("file_list is null!");
        return;
    }
    g_dump_file_info.list_len = num;
    bsp_dt_for_each_child_of_node(dev, child)
    {
        (void)dump_file_attr_init(child);
    }
}

bool dump_get_log_strategy_init_state(void)
{
    return g_dump_file_info.inited;
}

int dump_log_strategy_init(void)
{
    if (g_dump_file_info.inited) {
        return DUMP_OK;
    }
    g_dump_file_info.inited = true;
    dump_cur_attr_init();
    dump_file_cfg_init();
    dump_link_init();
    return DUMP_OK;
}