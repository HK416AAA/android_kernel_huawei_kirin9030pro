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

/*lint --e{528,537,715} */
#include <bsp_dump.h>
#include <bsp_print.h>
#include <securec.h>
#include "sysboot.h"

#define THIS_MODU mod_sysboot
#define SYSBOOT_DUMP_SIZE 0x400
#define SAVE_DUMP_NUM 10
#define MOUDLE_SIZE sizeof(struct modem_module_init_dump_node)

struct sysboot_dump_info {
    unsigned char *addr;
    unsigned int size;
};

static struct sysboot_dump_info g_sysboot_dump_info;
void sysboot_module_dump_callback(void);

void *moudle_result_save(struct modem_module_init_dump_node *init_nodes, unsigned int *idx, void *addr)
{
    int ret;
    int result = init_nodes->init_result;
    struct modem_module_init_dump_node *dump_node = NULL;
    if (result != 0 && result != MODEM_INIT_RET_STUB_MAGIC &&
        result != MODEM_INIT_RET_MAGIC && *idx < SAVE_DUMP_NUM) {
        dump_node = (struct modem_module_init_dump_node *)addr;
        *dump_node = *init_nodes;
        (*idx)++;
        addr += MOUDLE_SIZE;
    }
    return addr;
}

void print_module_dump_info(struct modem_module_init_dump_node *init_nodes)
{
    bsp_err("module_id:%u.\n", init_nodes->module_id);
    bsp_err("module_name:%s.\n", init_nodes->module_name);
    bsp_err("init_result:%d.\n", init_nodes->init_result);
    bsp_err("init_start_slice:%u.\n", init_nodes->init_start_slice);
    bsp_err("init_end_slice:%u.\n", init_nodes->init_end_slice);
}

void sysboot_all_module_dump_show(void)
{
    int i = 0;
    struct modem_module_init_dump_info *init_dump_info = sysboot_get_modem_module_dump_info();

    bsp_err("early_init_magic_start:0x%x.\n", init_dump_info->early_init_magic_start);
    for (i = 0; i < MODEM_MODULE_INIT_END; i++) {
        print_module_dump_info(&init_dump_info->early_init_nodes[i]);
    }
    bsp_err("early_init_magic_end:0x%x.\n", init_dump_info->early_init_magic_end);

    bsp_err("ps_init_magic_start:0x%x.\n", init_dump_info->ps_init_magic_start);
    print_module_dump_info(&init_dump_info->ps_init_nodes);
    bsp_err("ps_init_magic_end:0x%x.\n", init_dump_info->ps_init_magic_start);

    bsp_err("late_init_magic_start:0x%x.\n", init_dump_info->late_init_magic_start);
    for (i = 0; i < MODEM_MODULE_LATE_INIT_END; i++) {
        print_module_dump_info(&init_dump_info->late_init_nodes[i]);
    }
    bsp_err("late_init_magic_end:0x%x.\n", init_dump_info->late_init_magic_end);
}

void sysboot_error_module_dump_show(void)
{
    int i = 0;
    uint32_t *mod_idx = 0;
    uint32_t *magic = NULL;
    unsigned char *dump_addr = g_sysboot_dump_info.addr;
    struct modem_module_init_dump_node *dump_info_print = NULL;

    sysboot_module_dump_callback();

    if (dump_addr == NULL) {
        bsp_err("sysboot dump info addr is NULL.\n");
        return;
    }

    magic = (uint32_t *)dump_addr;
    dump_addr += sizeof(uint32_t);
    bsp_err("dump_init_magic_start:0x%x.\n", *magic);

    mod_idx = (uint32_t *)dump_addr;
    dump_addr += sizeof(uint32_t);
    if (*mod_idx > SAVE_DUMP_NUM) {
        bsp_err("dump module idx error, idx = %u.\n", *mod_idx);
        return;
    }

    for (i = 0; i < *mod_idx; i++) {
        dump_info_print = (struct modem_module_init_dump_node *)dump_addr;
        print_module_dump_info(dump_info_print);
        dump_addr += MOUDLE_SIZE;
    }

    magic = (uint32_t *)dump_addr;
    dump_addr += sizeof(uint32_t);
    bsp_err("dump_init_magic_end:0x%x.\n", *magic);

    bsp_err("print sysboot error module dump info success.\n");
}

void sysboot_module_dump_callback(void)
{
    int ret = 0;
    int i = 0;
    uint32_t *magic = NULL;
    uint32_t *mod_idx = NULL;
    unsigned char *dumpbuf = g_sysboot_dump_info.addr;
    struct modem_module_init_dump_info *init_dump_info = sysboot_get_modem_module_dump_info();

    if (g_sysboot_dump_info.addr == NULL) {
        bsp_err("g_sysboot_dump_info.addr is NULL.\n");
        return;
    }

    magic = (uint32_t *)dumpbuf;
    *magic = init_dump_info->early_init_magic_start;
    dumpbuf += sizeof(uint32_t);

    mod_idx = (uint32_t *)dumpbuf;
    *mod_idx = 0;
    dumpbuf += sizeof(uint32_t);

    for (i = 0; i < MODEM_MODULE_INIT_END; i++) {
        dumpbuf = moudle_result_save(&init_dump_info->early_init_nodes[i], mod_idx, dumpbuf);
    }

    dumpbuf = moudle_result_save(&init_dump_info->ps_init_nodes, mod_idx, dumpbuf);

    for (i = 0; i < MODEM_MODULE_LATE_INIT_END; i++) {
        dumpbuf = moudle_result_save(&init_dump_info->late_init_nodes[i], mod_idx, dumpbuf);
    }

    magic = (uint32_t *)dumpbuf;
    *magic = init_dump_info->late_init_magic_end;
    dumpbuf += sizeof(uint32_t);

    bsp_err("memcpy_s sysboot error module dump info success.\n");
}

int bsp_sysboot_dump_init(void)
{
    g_sysboot_dump_info.addr =
        (unsigned char *)bsp_dump_register_field(DUMP_MODEMAP_SYSBOOT, "SYSBOOT", SYSBOOT_DUMP_SIZE, 0);
    if (g_sysboot_dump_info.addr == NULL) {
        bsp_err("register sysboot dump filed failed.\n");
        return -1;
    }
    g_sysboot_dump_info.size = SYSBOOT_DUMP_SIZE;
    (void)memset_s(g_sysboot_dump_info.addr, SYSBOOT_DUMP_SIZE, 0, SYSBOOT_DUMP_SIZE);

    if (bsp_dump_register_hook("SYSBOOT", sysboot_module_dump_callback) == -1) {
        bsp_err("register sysboot dump hook failed.\n");
        return -1;
    }

    return 0;
}