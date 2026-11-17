/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
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
#include <linux/io.h>
#include <linux/kernel.h>
#include <linux/interrupt.h>
#include <linux/slab.h>
#include <securec.h>
#include <bsp_print.h>
#include <bsp_dump.h>
#include <bsp_slice.h>
#include <bsp_dt.h>
#include <bsp_dpa.h>
#include "buserr_probe.h"
#include "buserr_base.h"
#include "buserr_qic_em.h"
#include "buserr_qicprobe.h"

#ifdef __cplusplus
extern "C" {
#endif

qic_errprobe_s  g_qic_errprobe;

qic_errprobe_s *qic_errprobe_get_ctrl_info(void)
{
    return &g_qic_errprobe;
}
EXPORT_SYMBOL(qic_errprobe_get_ctrl_info);

int qic_errprobe_set_parser_flag(int opt)
{
    u32 raw_err_bit, i;
    int valid_cnt = 0;
    qic_errprobe_s *qic_errprobe = qic_errprobe_get_ctrl_info();

    /* 清除标识位 */
    if (opt == QIC_STATE_INVALID) {
        (void)memset_s(qic_errprobe->em_flag, QIC_PARSER_EM_MAX, 0 , qic_errprobe->em_cnt);
        return 0;
    }

    for (i = 0; i < qic_errprobe->em_cnt; i++) {
        raw_err_bit = readl(qic_errprobe->em[i].irq_reg);
        if (raw_err_bit & (1U << qic_errprobe->em[i].irq_bit)) {
            qic_errprobe->em_flag[i] = QIC_STATE_VALID;
            valid_cnt++;
            qic_printf("%s is vaild\n", qic_errprobe->em[i].name);
        }
    }
    qic_printf("%d em record qic err\n", valid_cnt);
    return valid_cnt;
}

void *qic_errprobe_em_addr(u32 em_index)
{
    qic_errprobe_s *qic_errprobe = qic_errprobe_get_ctrl_info();
    return qic_errprobe->em[em_index].base;
}

void qic_errprobe_show_dump(qic_dump_head_s *dump_addr)
{
    qic_printf("reg dump: \n");
    qic_printf("  %08x %08x %08x %08x \n",
        dump_addr->err_reg[0], dump_addr->err_reg[1], dump_addr->err_reg[0x2], dump_addr->err_reg[0x3]);
    qic_printf("  %08x %08x %08x %08x %08x \n",
        dump_addr->err_reg[0x4], dump_addr->err_reg[0x5], dump_addr->err_reg[0x6],
        dump_addr->err_reg[0x7], dump_addr->err_reg[0x8]);
}

/* 针对地址空洞，需要补充读IB的寄存器空间,并将真实地址替换 */
void qic_errprobe_decerr(qic_em_s *em, qic_dump_head_s *dump_addr)
{
    unsigned int err_status, ib_idx;
    void *qic_ibq_base = NULL;

    if (em->ibq_cnt == 0 || em->ibq_addr == NULL) {
        return;
    }

    err_status = (dump_addr->err_reg[0x0] >> QIC_EMP_CMD_STATUS_BIT) & QIC_EMP_CMD_STATUS_MASK;
    if (err_status != QIC_EM_STATUS_DECERR) {
        return;
    }

    ib_idx = (dump_addr->err_reg[0x1] >> QIC_EMP_CMD_IBID_BIT) & QIC_EMP_CMD_IBID_MASK;
    if (ib_idx >= em->ibq_cnt) {
        return;
    }

    qic_ibq_base = (void *)em->ibq_addr[ib_idx];
    if (qic_ibq_base == NULL) {
        return;
    }

    /* 更新真实访问地址 */
    dump_addr->err_reg[0x3] = readl(qic_ibq_base + QIC_IBQ_DECERR_ADDR0);
    dump_addr->err_reg[0x4] = readl(qic_ibq_base + QIC_IBQ_DECERR_ADDR1);
    dump_addr->err_reg[0x8] = readl(qic_ibq_base + QIC_IBQ_DECERR_STATUS);

    writel(1, qic_ibq_base + QIC_IBQ_DECERR_CLR);

    qic_printf("DCCERR update reg show:\n");
    qic_errprobe_show_dump(dump_addr);
}

void qic_errprobe_save_dump(void *qic_em_base, qic_dump_head_s *dump_addr, int i)
{
    qic_errprobe_s *qic_errprobe = qic_errprobe_get_ctrl_info();

    if (qic_em_base == NULL || dump_addr == NULL) {
        qic_printf("addr is null\n");
        return;
    }
    if (dump_addr->dump_idx > 0) { /* 已经存了1份最初dump，未清中断不在继续覆盖，避免丢失首次日志 */
        qic_printf("history dump save done, current ignore\n");
        return;
    }

    dump_addr->magic_num    = QIC_STATE_REG_MAGIC;
    dump_addr->chip_version = qic_errprobe->chip_version;
    dump_addr->base_addr    = qic_errprobe->em[i].phy_base;
    dump_addr->slice        = bsp_get_slice_value();
    dump_addr->valid_state  = QIC_STATE_VALID;
    dump_addr->err_reg[0x0] = readl(qic_em_base + QIC_EM_ERR_LOG0);
    dump_addr->err_reg[0x1] = readl(qic_em_base + QIC_EM_ERR_LOG1);
    dump_addr->err_reg[0x2] = readl(qic_em_base + QIC_EM_ERR_LOG2);
    dump_addr->err_reg[0x3] = readl(qic_em_base + QIC_EM_ERR_LOG3);
    dump_addr->err_reg[0x4] = readl(qic_em_base + QIC_EM_ERR_LOG4);
    dump_addr->err_reg[0x5] = readl(qic_em_base + QIC_EM_ERR_LOG5);
    dump_addr->err_reg[0x6] = readl(qic_em_base + QIC_EM_ERR_LOG6);
    dump_addr->err_reg[0x7] = readl(qic_em_base + QIC_EM_ERR_LOG7);
    dump_addr->dump_idx++;

    qic_errprobe->dump_times++;
    qic_printf("save dump done\n");
    qic_errprobe_show_dump(dump_addr);

    qic_errprobe_decerr(&qic_errprobe->em[i], dump_addr);
}

unsigned int qic_errprobe_get_mid(int i)
{
    qic_errprobe_s *qic_errprobe = qic_errprobe_get_ctrl_info();
    qic_dump_head_s *dump_addr = qic_errprobe->dump_addr + i;
    if ((i >= 0) && (i < qic_errprobe->em_cnt) && (dump_addr != NULL)) {
        return dump_addr->err_reg[0x5] & 0xff;
    } else {
        return 0;
    }
}

s32 qic_errprobe_dump_init(void)
{
    qic_errprobe_s *qic_errprobe = qic_errprobe_get_ctrl_info();
    qic_dump_head_s *dump_addr = NULL;
    u32 qic_dump_size = 0x2 * qic_errprobe->em_cnt * sizeof(qic_dump_head_s);

    dump_addr = (qic_dump_head_s *)bsp_dpa_dump_register_field(OM_DPAHOST_DPA_QIC, "QIC", qic_dump_size, QIC_DUMP_VID);
    if (dump_addr == NULL) {
        qic_printf("get qic dump field fail!\n");
        return -1;
    }

    (void)memset_s(dump_addr, qic_dump_size, 0, qic_dump_size);
    qic_errprobe->dump_addr = dump_addr;
    qic_errprobe->dump_record = dump_addr + qic_errprobe->em_cnt;

    return 0;
}
void qic_errpobe_irq_clr(void)
{
    int i, retry_num;
    void *qic_em_base = NULL;
    qic_errprobe_s *qic_errprobe = qic_errprobe_get_ctrl_info();

    for (i = 0; i < qic_errprobe->em_cnt; i++) {
        if (qic_errprobe->em_flag[i] == 0) {
            continue;
        }
        qic_em_base = qic_errprobe_em_addr(i);
        retry_num = 0x4;
        while (retry_num >= 0) {
            writel(1, qic_em_base + QIC_EM_INT_CLR);
            retry_num--;
        }
    }
}

irqreturn_t qic_errprobe_fault_irq_handler(void)
{
    int i;
    void *qic_em_base = NULL;
    qic_errprobe_s *qic_errprobe = qic_errprobe_get_ctrl_info();

    qic_printf("[0x%x]irq in\n", bsp_get_slice_value());
    qic_errprobe->irq_count++;

    if (qic_errprobe_set_parser_flag(QIC_STATE_VALID) == 0) {
        return IRQ_HANDLED;
    }

    for (i = 0; i < qic_errprobe->em_cnt; i++) {
        if (qic_errprobe->em_flag[i] == 0) {
            continue;
        }
        qic_em_base = qic_errprobe_em_addr(i);
        qic_errprobe_save_dump(qic_em_base, qic_errprobe->dump_addr + i, i);
    }

    if (i >= qic_errprobe->em_cnt) {
        i = 0;
    }

    if (bsp_buserr_ctrl()->cfg.qic_rst == true) {
        qic_printf("enter system_error\n");
        dpa_system_error(DRV_ERRNO_MDMPERI_QIC, qic_errprobe_get_mid(i), 0, NULL, 0);
        return IRQ_HANDLED;
    }

    qic_errpobe_irq_clr();
    (void)qic_errprobe_set_parser_flag(QIC_STATE_INVALID);
    qic_printf("[0x%x]irq out\n", bsp_get_slice_value());

    return IRQ_HANDLED;
}

s32 qic_errprobe_irq_handler_init(void)
{
    s32 ret = bsp_buserr_register_hook("qic_handler", qic_errprobe_fault_irq_handler, BUS_ERROR_QIC);
    if (ret) {
        qic_printf("register irq handler fail\n");
        return -1;
    }
    return 0;
}

/* system error callback */
void qic_errprobe_fault_dump_handler(void)
{
    int i;
    void *qic_em_base = NULL;
    qic_errprobe_s *qic_errprobe = qic_errprobe_get_ctrl_info();

    if (qic_errprobe_set_parser_flag(QIC_STATE_VALID) == 0) {
        return;
    }

    for (i = 0; i < qic_errprobe->em_cnt; i++) {
        if (qic_errprobe->em_flag[i] == 0) {
            continue;
        }
        qic_em_base = qic_errprobe_em_addr(i);
        qic_errprobe_save_dump(qic_em_base, qic_errprobe->dump_record + i, i);
    }

    qic_printf("[0x%x]dump save done\n", bsp_get_slice_value());
}

s32 qic_errprobe_dump_handler_init(void)
{
    s32 ret;

    ret = bsp_dpa_dump_register_hook("qic_fault", qic_errprobe_fault_dump_handler);
    if (ret == -1) {
        qic_printf("register dump handler fail\n");
    }
    return 0;
}

void qic_errprobe_ibq_init(qic_em_s *em, const device_node_s *dev)
{
    int ret;
    u32 i = 0;
    u32 u = 0;
    const __be32 *p = NULL;
    struct property *prop = NULL;

    /* 有些平台不支持，不支持的默认跳过，不需要返回错误 */
    ret = bsp_dt_property_read_u32(dev, "qic_ibq_cnt", &em->ibq_cnt);
    if (ret || em->ibq_cnt == 0 || em->ibq_cnt > QIC_IBQ_MAX) {
        em->ibq_cnt = 0;
        qic_printf("skip ibq get\n");
        return;
    }

    em->ibq_addr = (void *)kmalloc(sizeof(void *) * em->ibq_cnt, GFP_KERNEL);
    if (em->ibq_addr == NULL) {
        em->ibq_cnt = 0;
        return;
    }

    bsp_dt_property_for_each_u32(dev, "qic_ibq_base", prop, p, u) {
        if (i >= em->ibq_cnt) {
            em->ibq_cnt = 0;
            kfree(em->ibq_addr);
            em->ibq_addr = NULL;
            qic_printf("i %d exceed!\n", i);
            return;
        }
        em->ibq_addr[i++] = (void *)ioremap(u, 0x1000);
        if (em->ibq_addr[i++] == NULL) {
            qic_printf("addr is null!\n");
        }
    }
}

void qic_errprobe_em_dts_init(device_node_s *child, u32 index)
{
    u32 reg[0x2];
    const char *em_name = NULL;
    qic_errprobe_s *qic_errprobe = qic_errprobe_get_ctrl_info();
    qic_em_s *em = &qic_errprobe->em[index];

    if (bsp_dt_property_read_string(child, "qic_name", &em_name)) {
        qic_printf("rd name fail\n");
        return;
    }
    if (strncpy_s(em->name, sizeof(em->name), em_name, strlen(em_name))) {
        return;
    }

    if (bsp_dt_property_read_u32_array(child, "irq_reg", reg, 0x2)) {
        qic_printf("rd irq reg fail\n");
        return;
    }
    em->irq_reg = (void *)ioremap(reg[0], 0x1000) + reg[1];
    if (em->irq_reg == NULL) {
        qic_printf("irq_reg is NULL\n");
        return;
    }

    if (bsp_dt_property_read_u32(child, "irq_bit", &em->irq_bit)) {
        qic_printf("rd irq_bit fail\n");
        return;
    }

    if (bsp_dt_property_read_u32_array(child, "base", reg, 0x2)) {
        qic_printf("rd em base fail\n");
        return;
    }
    em->phy_base = reg[0];
    em->base = (void *)ioremap(reg[0], reg[1]);
    if (em->base == NULL) {
        qic_printf("em->base is null\n");
    }
    qic_errprobe_ibq_init(em, child);
}


s32 qic_errprobe_dts_init(void)
{
    u32 ret, i, em_cnt;
    device_node_s *dev = NULL, *child = NULL;
    qic_errprobe_s *qic_errprobe = qic_errprobe_get_ctrl_info();

    dev = bsp_dt_find_compatible_node(NULL, NULL, "mdmperi_qic");
    if (dev == NULL) {
        qic_printf("rd dev fail\n");
        return QIC_NULL_POINTER;
    }

    ret = bsp_dt_property_read_u32(dev, "chipid", &qic_errprobe->chip_version);
    if (ret) {
        qic_printf("get chipid fail, %d\n", ret);
        qic_errprobe->chip_version = 0;
    }

    ret = bsp_dt_property_read_u32(dev, "em_cnt", &em_cnt);
    if (ret || em_cnt == 0 || em_cnt > QIC_PARSER_EM_MAX) {
        qic_printf("get em_cnt fail, %d\n", em_cnt);
        return QIC_PARA_ERROR;
    }

    qic_errprobe->em_cnt = em_cnt;
    qic_errprobe->em = (qic_em_s *)kmalloc(sizeof(qic_em_s) * em_cnt, GFP_KERNEL);
    if (qic_errprobe->em == NULL) {
        qic_printf("malloc fail\n");
        return QIC_NULL_POINTER;
    }
    i = 0;
    bsp_dt_for_each_child_of_node(dev, child) {
        if (i >= em_cnt) {
            qic_printf("child size err\n");
            return QIC_EXC_BRANCH;
        }
        qic_errprobe_em_dts_init(child, i);
        i++;
    }

    return 0;
}

s32 bsp_buserr_probe_init(void)
{
    s32 ret;

    qic_printf("[init] start\n");

    ret = qic_errprobe_dts_init();
    if (ret) {
        return -1;
    }

    ret = qic_errprobe_dump_init();
    if (ret) {
        return -1;
    }

    ret = qic_errprobe_dump_handler_init();
    if (ret) {
        return -1;
    }

    ret = qic_errprobe_irq_handler_init();
    if (ret) {
        return -1;
    }
    qic_printf("[init] ok\n");
    return 0;
}

#ifdef __cplusplus
}
#endif
