/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2020. All rights reserved.
 */
#include <linux/of_device.h>
#include <linux/version.h>
#include <linux/types.h>
#include <linux/kthread.h>  /* struct task_struct */
#include <linux/spinlock.h> /* struct spinlock */
#include <linux/device.h>
#include <linux/pm_wakeup.h>
#include <uapi/linux/sched/types.h> /* struct sched_param */
#include <linux/dma-mapping.h>
#include <linux/slab.h>
#include "bsp_dpa_fipc.h"
#include "dpa_msg_plat.h"
#include "dpa_msg_cmsg.h"
#include "dpa_msg_dts.h"
#include "dpa_msg_core.h"
#include "dpa_fipc_ops.h"
#include "dpa_msg_error_code.h"

int dpa_send_lite_msg(const struct dpa_msg_addr *src_addr, const struct dpa_msg_addr *dst_addr, void *buf, unsigned int len)
{
    int ret;
    struct dpa_cmsg_hdr hdr;
    struct dpa_cmsg_lite_exthdr lite_exthdr;

    dpa_msg_blkx3_desc_t send_desc;

    hdr.type = DPA_CMSG_TYPE_LITE;
    hdr.rsv = 0;
    hdr.flags = 0;
    hdr.len = len;

    lite_exthdr.src = (src_addr->core << 0x10) | (src_addr->chnid);
    lite_exthdr.dst = (dst_addr->core << 0x10) | (dst_addr->chnid);

    send_desc.cnt = 0x3;
    send_desc.datablk[0].len = sizeof(hdr);
    send_desc.datablk[0].buf = &hdr;
    send_desc.datablk[1].len = sizeof(lite_exthdr);
    send_desc.datablk[1].buf = &lite_exthdr;
    send_desc.datablk[0x2].len = len;
    send_desc.datablk[0x2].buf = buf;

    ret = dpa_fipc_default_send(&send_desc);
    if (ret < 0) {
        return ret;
    }
    return MSG_OK;
}

int dpa_cmsg_phychn_init(dpa_msg_phychn_dts_t *phy_node, unsigned int cpuid)
{
    struct dpa_channel_ctrl_t *channel_ctrl = NULL;
    if (phy_node == NULL) {
        return MSG_ERR_COMMON_INPUT;
    }
    channel_ctrl = (struct dpa_channel_ctrl_t *)kmalloc(sizeof(struct dpa_channel_ctrl_t), GFP_KERNEL);

    if (channel_ctrl == NULL) {
        return MSG_ERR_ENOMEM;
    }
    (void)memset_s(channel_ctrl, sizeof(struct dpa_channel_ctrl_t), 0, sizeof(struct dpa_channel_ctrl_t));
    channel_ctrl->cid = cpuid;
    return dpa_fipc_phychn_init(channel_ctrl, phy_node);
}

int dpa_cmsg_cpugroup_init(dpa_msg_cpugroup_dts_t *cpu_node)
{
    int ret;
    unsigned int idx;
    unsigned int cpuid;
    dpa_msg_phychn_dts_t *phy_node = NULL;
    cpuid = cpu_node->cpuid;
    for (idx = 0; idx < cpu_node->phychn_cnt; ++idx) {
        phy_node = cpu_node->msg_phychn_dts + idx;
        ret = dpa_cmsg_phychn_init(phy_node, cpuid);
        if (ret) {
            dpa_msg_err("cmsg_phychn_init error!\n");
            return ret;
        }
    }
    return MSG_OK;
}

int dpa_msg_init(void)
{
    dpa_msg_cpugroup_dts_t *cpu_node = NULL;

    cpu_node = dpa_msg_of_find_root_node();
    if (unlikely(cpu_node == NULL)) {
        dpa_msg_err("msg dts not found!\n");
        return MSG_ERR_ENXIO;
    }
    return dpa_cmsg_cpugroup_init(cpu_node);
}


static struct platform_device g_dpa_cmsg_plat_device = {
    .name = "dpa_cmsg_plat",
};

static struct platform_driver g_dpa_cmsg_plat_driver = {
    .probe = dpa_msg_plat_probe,
    .driver =
        {
            .name = "dpa_cmsg_plat",
            .owner = THIS_MODULE,
            .probe_type = PROBE_FORCE_SYNCHRONOUS,
        },
};

void *dpa_msg_dma_buf_alloc(size_t size, dma_addr_t *dma_handle)
{
    void *mem_addr = NULL;
    mem_addr = dma_alloc_coherent(&g_dpa_cmsg_plat_device.dev, size, dma_handle, GFP_KERNEL);
    if (mem_addr == NULL) {
        return NULL;
    }
    return mem_addr;
}

void dpa_msg_dma_buf_free(size_t size, void *cpu_addr, dma_addr_t dma_handle)
{
    dma_free_coherent(&g_dpa_cmsg_plat_device.dev, size, cpu_addr, dma_handle);
    return;
}

int dpa_msg_crosscore_init(void)
{
    s32 ret;

    ret = platform_device_register(&g_dpa_cmsg_plat_device);
    if (ret) {
        return ret;
    }
    ret = platform_driver_register(&g_dpa_cmsg_plat_driver);
    if (ret) {
        platform_device_unregister(&g_dpa_cmsg_plat_device);
        return ret;
    }

    return 0;
}
