/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 */
#include <linux/version.h>
#include <linux/device.h>
#include <linux/pm_wakeup.h>
#include <linux/dma-mapping.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/interrupt.h>
#include <linux/of_irq.h>
#ifdef CONFIG_LIBLINUX
#include <liblinux/pal.h>
#endif
#include "securec.h"
#include <bsp_dpa_ipc.h>
#include <bsp_dpa.h>
#include <bsp_sec_call.h>
#include "dpa_ipc_dump.h"

unsigned int g_dpa_ipc_res_lpm2acpu_ns[] = {
    DPA_IPC_ACPU_INT_SRC_M3_LPMCU_READY,
    DPA_IPC_ACPU_INT_SRC_MCU_DPA_DUMP,
};

unsigned int g_dpa_ipc_res_dpa2acpu_ns[] = {
    DPA_IPC_ACPU_INT_SRC_DPA_POWERDOWN,
    DPA_IPC_ACPU_INT_SRC_DPA_DUMP,
    DPA_IPC_ACPU_INT_SRC_DPA_BEFORE_MDM_RESETTING,
    DPA_IPC_ACPU_INT_SRC_DPA_AFTER_MDM_RESETTING,
    DPA_IPC_ACPU_INT_SRC_DPA_RESUME_COMPLE_ACK,
    DPA_IPC_ACPU_INT_SRC_DPA_RESET_HOST_IDLE,
    DPA_IPC_ACPU_INT_SRC_DPA_RESET_START_OK,
    DPA_IPC_ACPU_INT_SRC_DPA_FREQ_UP,
    DPA_IPC_ACPU_INT_SRC_DPA_FREQ_DOWN,
    DPA_IPC_ACPU_INT_SRC_DPA_FREQ_MIN,
    DPA_IPC_ACPU_INT_SRC_DPA_FREQ_LOAD_MAX,
};

unsigned int g_dpa_ipc_res_acpu2dpa_ns[] = {
    DPA_IPC_DPA_INT_SRC_ACPU_DUMP,
    DPA_IPC_DPA_INT_SRC_ACPU_BEFORE_MDM_RESETTING,
    DPA_IPC_DPA_INT_SRC_ACPU_AFTER_MDM_RESETTING,
    DPA_IPC_DPA_INT_SRC_ACPU_WAKE_UNLOCK,
    DPA_IPC_DPA_INT_SRC_ACPU_WAKE_LOCK,
    DPA_IPC_DPA_INT_SRC_ACPU_RFILE_NOTIFY,
    DPA_IPC_DPA_INT_SRC_ACPU_PM_DEBUG_REPORT,
    DPA_IPC_DPA_INT_SRC_ACPU_DPA_RESET,
};

struct dpa_ipc_recv_event_reg_info {
    dpa_ipc_cbk ipc_recv_handler;
    void *arg;
};
struct dpa_ipc_recv_event_reg_info g_dpa_ipc_event_reg_info[DPA_IPC_RECV_EVENT_MAX_NUM]; // 保存来自dpa的事件回调函数
struct dpa_ipc_recv_event_reg_info g_m3_ipc_event_reg_info[DPA_IPC_RECV_EVENT_MAX_NUM];  // 保存来自m3的事件回调函数

struct dpa_ipcmsg_device_t g_dpa_ipcmsg_device;
static spinlock_t g_dpa_ipc_reset_flag_lock;
u32 g_dpa_ipc_reset_flag = 0;
u32 g_dpa_ipc_init_flag = 0;

struct dpa_ipcmsg_device_t *dpa_ipcmsg_dev_get(void)
{
    return &g_dpa_ipcmsg_device;
}

void ipc_dpa_recv_int_clear(void)
{
    unsigned int reg_id;
    unsigned int reg_val;

    if (g_dpa_ipc_init_flag == 0) {
        return;
    }

    reg_val = g_dpa_ipcmsg_device.remote_id[0]; // 这只用处理来自dpa的
    writel(reg_val, (void *)(uintptr_t)((u8 *)g_dpa_ipcmsg_device.base_va +
        g_dpa_ipcmsg_device.send_mbx_id * DPA_IPCMSG_OFFSET + DPA_IPCMSG_ICLR_REG));
    for (reg_id = 0; reg_id < DPA_IPC_RECV_EVENT_MAX_NUM; reg_id++) {
        writel(0x0, (void *)(uintptr_t)((u8 *)g_dpa_ipcmsg_device.base_va +
            DPA_IPC_MBX_DATA_ADDR(g_dpa_ipcmsg_device.send_mbx_id, reg_id, DPA_IPCMSG_OFFSET)));
    }
}

void bsp_ipc_dpa_reset(dpa_reset_stage_e stage)
{
    unsigned long lock_flag = 0;

    spin_lock_irqsave(&g_dpa_ipc_reset_flag_lock, lock_flag);
    if (stage == DPA_RESET_BEFORE) {
        g_dpa_ipc_reset_flag = 1;
        ipc_dpa_recv_int_clear();
        dpa_ipc_before_resetting_dump();
    }
    if (stage == DPA_RESET_AFTER) {
        g_dpa_ipc_reset_flag = 0;
        dpa_ipc_after_resetting_dump();
    }
    spin_unlock_irqrestore(&g_dpa_ipc_reset_flag_lock, lock_flag);
    return;
}

int dpa_ipcmsg_device_dts_parse(struct device_node *p_dev_node)
{
    int ret;
    u32 array[0x2] = {0};
    if (p_dev_node == NULL) {
        dpa_ipc_err("dpa ipcmsg dts input err!\n");
        return -1;
    }

    ret = of_property_read_u32_array(p_dev_node, "reg", array, sizeof(array) / sizeof(array[0]));
    ret |= of_property_read_u32_array(p_dev_node, "local_id", &g_dpa_ipcmsg_device.local_id, 1);
    ret |= of_property_read_u32_array(p_dev_node, "remote_id", g_dpa_ipcmsg_device.remote_id, 2);
    ret |= of_property_read_u32_array(p_dev_node, "send_mailbox", &g_dpa_ipcmsg_device.send_mbx_id, 1);
    ret |= of_property_read_u32_array(p_dev_node, "recv_mailbox", g_dpa_ipcmsg_device.recv_mbx_id, 2);
#ifdef CONFIG_LIBLINUX
    ret |= of_property_read_u32_array(p_dev_node, "hwirq", g_dpa_ipcmsg_device.hwirq, 2);
#endif
    if (ret) {
        dpa_ipc_err("dpa ipcmsg dts parse failed!\n");
        return -1;
    }

    g_dpa_ipcmsg_device.base_pa = array[0x0];
    g_dpa_ipcmsg_device.size = array[0x1];
    g_dpa_ipcmsg_device.base_va = ioremap(g_dpa_ipcmsg_device.base_pa, g_dpa_ipcmsg_device.size);
    if (g_dpa_ipcmsg_device.base_va == NULL) {
        dpa_ipc_err("dpa ipcmsg base addr ioremap failed!\n");
        return -1;
    }
    g_dpa_ipcmsg_device.irq[0x0] = irq_of_parse_and_map(p_dev_node, 0);
    g_dpa_ipcmsg_device.irq[0x1] = irq_of_parse_and_map(p_dev_node, 1);

    dpa_ipc_debug("dpa_ipcmsg_device_dts_parse done!\n");
    dpa_ipc_debug("reg[0x%x][0x%x] local_id[0x%x] \n remote_id[0x%x] send_mbx[0x%x] recv_mbx[0x%x] irq[%d]\n",
        g_dpa_ipcmsg_device.base_pa, (u32)g_dpa_ipcmsg_device.base_va,
        g_dpa_ipcmsg_device.local_id, g_dpa_ipcmsg_device.remote_id[0],
        g_dpa_ipcmsg_device.send_mbx_id, g_dpa_ipcmsg_device.recv_mbx_id[0],
        g_dpa_ipcmsg_device.irq[0]);
    dpa_ipc_debug("remote_id[0x%x] recv_mbx[0x%x] irq[%d]\n",
        g_dpa_ipcmsg_device.remote_id[1], g_dpa_ipcmsg_device.recv_mbx_id[1], g_dpa_ipcmsg_device.irq[1]);
    return 0;
}

int dpa_ipcmsg_probe(void)
{
    int ret;
    struct device_node *ptr_device_node = NULL;
    const char *node_path = "modem,dpa_ipc_device";
    ptr_device_node = of_find_compatible_node(NULL, NULL, node_path);
    if (ptr_device_node == NULL) {
        dpa_ipc_err("dpa ipcmsg dts not found!\n");
        return -1;
    }
    ret = memset_s(&g_dpa_ipcmsg_device, sizeof(g_dpa_ipcmsg_device), 0, sizeof(g_dpa_ipcmsg_device));
    if (ret) {
        return -1;
    }
    ret = dpa_ipcmsg_device_dts_parse(ptr_device_node);
    if (ret) {
        dpa_ipc_err("dpa ipcmsg dts parse failed!\n");
    }
    return ret;
}

int dpa_ipcmsg_recv_reg_get(dpa_ipc_res_id_e res_id, int *recv_index)
{
    int res_index;
    int res_num = sizeof(g_dpa_ipc_res_dpa2acpu_ns) / sizeof(unsigned int);
    for (res_index = 0; res_index < res_num; res_index++) {
        if (g_dpa_ipc_res_dpa2acpu_ns[res_index] == res_id) {
            *recv_index = 0;
            return res_index;
        }
    }
    res_num = sizeof(g_dpa_ipc_res_lpm2acpu_ns) / sizeof(unsigned int);
    for (res_index = 0; res_index < res_num; res_index++) {
        if (g_dpa_ipc_res_lpm2acpu_ns[res_index] == res_id) {
            *recv_index = 1;
            return res_index;
        }
    }

    return -1;
}

int bsp_dpa_ipc_connect(dpa_ipc_res_id_e res_id, dpa_ipc_cbk handler, void *parameter)
{
    struct dpa_ipc_recv_event_reg_info *recv_event = NULL;
    int reg_idx;
    int mbx_idx = -1;

    reg_idx = dpa_ipcmsg_recv_reg_get(res_id, &mbx_idx);

    if (handler == NULL || reg_idx >= DPA_IPC_RECV_EVENT_MAX_NUM || reg_idx == -1){
        return -1;
    }
    if (mbx_idx == 0) {
        // 来自dpa的事件
        recv_event = g_dpa_ipc_event_reg_info;
    } else {
        // 来自m3的事件
        recv_event = g_m3_ipc_event_reg_info;
    }

    if (recv_event[reg_idx].ipc_recv_handler != NULL){
        return -1;
    }

    recv_event[reg_idx].arg = parameter;
    recv_event[reg_idx].ipc_recv_handler = handler;
    return 0;
}

irqreturn_t dpa_ipc_recv_m3_handler(int irq_no, void *arg)
{
    unsigned int reg_id;
    unsigned int reg_val;
    int ret;

    reg_val = g_dpa_ipcmsg_device.local_id;
    writel(reg_val, (void *)(uintptr_t)((u8 *)g_dpa_ipcmsg_device.base_va +
        g_dpa_ipcmsg_device.recv_mbx_id[1] * DPA_IPCMSG_OFFSET + DPA_IPCMSG_ICLR_REG));

    for (reg_id = 0; reg_id < sizeof(g_dpa_ipc_res_lpm2acpu_ns) / sizeof(unsigned int); reg_id++) {
        reg_val = readl((void *)(uintptr_t)((u8 *)g_dpa_ipcmsg_device.base_va +
            DPA_IPC_MBX_DATA_ADDR(g_dpa_ipcmsg_device.recv_mbx_id[1], reg_id, DPA_IPCMSG_OFFSET)));
        if (reg_val == 0) {
            continue;
        }

        dpa_ipc_event_recv_dump(reg_id, g_dpa_ipc_res_lpm2acpu_ns[reg_id], DPA_IPC_RECV_BEFORE, 0x1);
        writel(0x0, (void *)(uintptr_t)((u8 *)g_dpa_ipcmsg_device.base_va +
            DPA_IPC_MBX_DATA_ADDR(g_dpa_ipcmsg_device.recv_mbx_id[1], reg_id, DPA_IPCMSG_OFFSET)));
        if (g_m3_ipc_event_reg_info[reg_id].ipc_recv_handler == NULL) {
            dpa_ipc_err("dpa ipc event %d not registered", reg_id);
            dpa_ipc_event_recv_dump(reg_id, g_dpa_ipc_res_lpm2acpu_ns[reg_id], DPA_IPC_ERR_NO_CBK, 0x1);
            continue;
        }

        ret = g_m3_ipc_event_reg_info[reg_id].ipc_recv_handler(g_m3_ipc_event_reg_info[reg_id].arg);
        if (ret) {
            dpa_ipc_err("dpa ipc event %d failed: %d", reg_id, ret);
        }

        dpa_ipc_event_recv_dump(reg_id, g_dpa_ipc_res_lpm2acpu_ns[reg_id], ret, 0x1);
    }

    return IRQ_HANDLED;
}

irqreturn_t dpa_ipc_recv_fw_handler(int irq_no, void *arg)
{
    unsigned int reg_id;
    unsigned int reg_val;
    int ret;

    reg_val = g_dpa_ipcmsg_device.local_id;
    writel(reg_val, (void *)(uintptr_t)((u8 *)g_dpa_ipcmsg_device.base_va +
        g_dpa_ipcmsg_device.recv_mbx_id[0] * DPA_IPCMSG_OFFSET + DPA_IPCMSG_ICLR_REG));

    for (reg_id = 0; reg_id < sizeof(g_dpa_ipc_res_dpa2acpu_ns) / sizeof(unsigned int); reg_id++) {
        reg_val = readl((void *)(uintptr_t)((u8 *)g_dpa_ipcmsg_device.base_va +
            DPA_IPC_MBX_DATA_ADDR(g_dpa_ipcmsg_device.recv_mbx_id[0], reg_id, DPA_IPCMSG_OFFSET)));
        if (reg_val == 0) {
            continue;
        }

        dpa_ipc_event_recv_dump(reg_id, g_dpa_ipc_res_dpa2acpu_ns[reg_id], DPA_IPC_RECV_BEFORE, 0x0);
        writel(0x0, (void *)(uintptr_t)((u8 *)g_dpa_ipcmsg_device.base_va +
            DPA_IPC_MBX_DATA_ADDR(g_dpa_ipcmsg_device.recv_mbx_id[0], reg_id, DPA_IPCMSG_OFFSET)));
        if (g_dpa_ipc_event_reg_info[reg_id].ipc_recv_handler == NULL) {
            dpa_ipc_err("dpa ipc event %d not registered", reg_id);
            dpa_ipc_event_recv_dump(reg_id, g_dpa_ipc_res_dpa2acpu_ns[reg_id], DPA_IPC_ERR_NO_CBK, 0x0);
            continue;
        }

        ret = g_dpa_ipc_event_reg_info[reg_id].ipc_recv_handler(g_dpa_ipc_event_reg_info[reg_id].arg);
        if (ret) {
            dpa_ipc_err("dpa ipc event %d failed: %d", reg_id, ret);
        }

        dpa_ipc_event_recv_dump(reg_id, g_dpa_ipc_res_dpa2acpu_ns[reg_id], ret, 0x0);
    }

    return IRQ_HANDLED;
}

int dpa_ipcmsg_recv_init(void)
{
    unsigned int ret = 0;

    (void)memset_s(g_dpa_ipc_event_reg_info, sizeof(g_dpa_ipc_event_reg_info), 0, sizeof(g_dpa_ipc_event_reg_info));
    (void)memset_s(g_m3_ipc_event_reg_info, sizeof(g_m3_ipc_event_reg_info), 0, sizeof(g_m3_ipc_event_reg_info));

    ret = request_irq(g_dpa_ipcmsg_device.irq[0], dpa_ipc_recv_fw_handler, 0, "dpa_ipcmsg_recv_dpa", NULL);
    if (ret) {
        dpa_ipc_err("dpa ipcmsg_recv_init failed: %d", ret);
        return ret;
    }
    ret = request_irq(g_dpa_ipcmsg_device.irq[1], dpa_ipc_recv_m3_handler, 0, "dpa_ipcmsg_recv_m3", NULL);
    if (ret) {
        dpa_ipc_err("m3 ipcmsg_recv_init failed: %d", ret);
        return ret;
    }
#ifdef CONFIG_LIBLINUX
    liblinux_pal_local_irq_setfast(g_dpa_ipcmsg_device.hwirq[0], 1);
    liblinux_pal_local_irq_setfast(g_dpa_ipcmsg_device.hwirq[1], 1);
#endif
    return 0;
}


int dpa_ipcmsg_send_reg_get(dpa_ipc_res_id_e res_id)
{
    int res_index;
    int res_num = sizeof(g_dpa_ipc_res_acpu2dpa_ns) / sizeof(unsigned int);
    for (res_index = 0; res_index < res_num; res_index++) {
        if (g_dpa_ipc_res_acpu2dpa_ns[res_index] == res_id) {
            return res_index;
        }
    }
    return -1;
}

int bsp_dpa_ipc_send(dpa_ipc_res_id_e res_id)
{
    int ret;
    int reg_idx = 0;
    unsigned long lock_flag = 0;

    // 先判断发送的ipc是否是需要经teeos转发给m3的
    if (res_id >= DPA_IPC_VERIFY_START && res_id < DPA_IPC_VERIFY_END) {
        ret = bsp_sec_call(FUNC_MDRV_TEEOS_FORWARD_IPC, res_id);
        if (ret) {
            dpa_ipc_err("dpa ipc seccall failed, ret=%d\n", ret);
            return ret;
        }
        return 0;
    }

    reg_idx = dpa_ipcmsg_send_reg_get(res_id);
    if (reg_idx < 0) {
        return -1;
    }

    if (g_dpa_ipc_init_flag == 0) {
        dpa_ipc_err("dpa ipcmsg not init!\n");
        return DPA_IPC_ERR;
    }
    spin_lock_irqsave(&g_dpa_ipc_reset_flag_lock, lock_flag);
    if (g_dpa_ipc_reset_flag) {
        dpa_ipc_event_send_dump(reg_idx, res_id, DPA_IPC_ERR_RESET);
        spin_unlock_irqrestore(&g_dpa_ipc_reset_flag_lock, lock_flag);
        return DPA_IPC_ERR_RESET;
    }

    writel(DPA_IPCMSG_FAST_IPC, (void *)(uintptr_t)((u8 *)g_dpa_ipcmsg_device.base_va +
        DPA_IPC_MBX_DATA_ADDR(g_dpa_ipcmsg_device.send_mbx_id, (unsigned int)reg_idx, DPA_IPCMSG_OFFSET)));
    writel(g_dpa_ipcmsg_device.local_id, (void *)(uintptr_t)((u8 *)g_dpa_ipcmsg_device.base_va +
        g_dpa_ipcmsg_device.send_mbx_id * DPA_IPCMSG_OFFSET + DPA_IPCMSG_ICLR_REG));
    writel(g_dpa_ipcmsg_device.local_id, (void *)(uintptr_t)((u8 *)g_dpa_ipcmsg_device.base_va +
        g_dpa_ipcmsg_device.send_mbx_id * DPA_IPCMSG_OFFSET + DPA_IPCMSG_SEND_REG));
    dpa_ipc_event_send_dump(reg_idx, res_id, 0);
    spin_unlock_irqrestore(&g_dpa_ipc_reset_flag_lock, lock_flag);
    return 0;
}

// 只给dpa fw发直接ipc，所以hw_init只初始化到remote_id[0]的邮箱
void dpa_ipcmsg_hw_init(void)
{
    unsigned int mask, reg_val;

    reg_val = readl((void *)(uintptr_t)((u8 *)g_dpa_ipcmsg_device.base_va +
        g_dpa_ipcmsg_device.send_mbx_id * DPA_IPCMSG_OFFSET + DPA_IPCMSG_SRC_REG));
    if (reg_val == g_dpa_ipcmsg_device.local_id) {
        return;
    }

    writel(g_dpa_ipcmsg_device.local_id, (void *)(uintptr_t)((u8 *)g_dpa_ipcmsg_device.base_va +
        g_dpa_ipcmsg_device.send_mbx_id * DPA_IPCMSG_OFFSET + DPA_IPCMSG_SRC_REG));
    writel(g_dpa_ipcmsg_device.remote_id[0], (void *)(uintptr_t)((u8 *)g_dpa_ipcmsg_device.base_va +
        g_dpa_ipcmsg_device.send_mbx_id * DPA_IPCMSG_OFFSET + DPA_IPCMSG_DST_REG));
    writel(DPA_IPC_MODE, (void *)(uintptr_t)((u8 *)g_dpa_ipcmsg_device.base_va +
        g_dpa_ipcmsg_device.send_mbx_id * DPA_IPCMSG_OFFSET + DPA_IPCMSG_MODE_REG));

    mask = DPA_IPCMSG_IMASK_ALL & (~(g_dpa_ipcmsg_device.remote_id[0]));
    writel(mask, (void *)(uintptr_t)((u8 *)g_dpa_ipcmsg_device.base_va +
        g_dpa_ipcmsg_device.send_mbx_id * DPA_IPCMSG_OFFSET + DPA_IPCMSG_IMASK_REG));
}

void dpa_ipcmsg_recognize_wakesrc_event(void)
{
    unsigned int i;
    unsigned int reg_val;

    // 只识别来自dpa的唤醒源是哪一个业务触发的
    for (i = 0; i < sizeof(g_dpa_ipc_res_dpa2acpu_ns) / sizeof(unsigned int); ++i) {
        reg_val = readl((void *)(uintptr_t)((u8 *)g_dpa_ipcmsg_device.base_va +
            DPA_IPC_MBX_DATA_ADDR(g_dpa_ipcmsg_device.recv_mbx_id[0], i, DPA_IPCMSG_OFFSET)));
        if (reg_val) {
            dpa_ipc_err("dpa ipc resume wakesrc event %d\n", i);
        }
    }
    return;
}

static int dpa_ipcmsg_dpm_resume(struct device *dev)
{
    dpa_ipcmsg_hw_init();
    dpa_ipcmsg_recognize_wakesrc_event();
    return 0;
}

static int dpa_ipcmsg_pre_probe(struct platform_device *pdev)
{
    int ret;

    ret = dpa_ipc_dump_init();
    if (ret) {
        dpa_ipc_err("dpa_ipc_dump_init failed!\n");
    }

    spin_lock_init(&g_dpa_ipc_reset_flag_lock);
    ret = dpa_ipcmsg_probe();
    if (ret) {
        dpa_ipc_err("dpa ipcmsg dts failed!\n");
        return ret;
    }
    dpa_ipc_debug("dpa_ipcmsg_probe done!\n");

    ret = dpa_ipcmsg_recv_init();
    if (ret) {
        dpa_ipc_debug("dpa_ipcmsg_recv_init: %d\n", ret);
        return ret;
    }
    dpa_ipcmsg_hw_init();
    dpa_ipc_debug("dpa_ipcmsg_hw_init done!\n");

    g_dpa_ipc_init_flag = 1;
    dpa_ipc_always("bsp_dpa_ipc_int done\n");
    return 0;
}

static struct platform_device g_dpa_ipcmsg_platform_device = {
    .name = "Dpa Host IPCMSG",
};

static const struct dev_pm_ops g_dpa_ipcmsg_pm_ops = {
    .resume_noirq = dpa_ipcmsg_dpm_resume,
};

static struct platform_driver g_dpa_ipcmsg_platform_driver = {
    .probe = dpa_ipcmsg_pre_probe,
    .driver = {
        .name = "Dpa Host IPCMSG",
        .owner = THIS_MODULE,
        .pm = &g_dpa_ipcmsg_pm_ops,
    },
};

int bsp_dpa_ipc_int(void)
{
    int ret;
    ret = platform_device_register(&g_dpa_ipcmsg_platform_device);
    if (ret) {
        dpa_ipc_err("dpa ipcmsg platform device register failed!\n");
        return ret;
    }
    ret = platform_driver_register(&g_dpa_ipcmsg_platform_driver);
    if (ret) {
        platform_device_unregister(&g_dpa_ipcmsg_platform_device);
        dpa_ipc_err("dpa ipcmsg platform driver register failed!\n");
        return ret;
    }
    dpa_ipc_err("dpa ipcmsg init ok\n");
    return ret;
}

MODULE_DESCRIPTION("DPA HOST IPCMSG Driver");
MODULE_LICENSE("GPL");
