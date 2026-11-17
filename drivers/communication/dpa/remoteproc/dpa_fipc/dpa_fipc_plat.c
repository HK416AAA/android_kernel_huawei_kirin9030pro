/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 */
#include <linux/of_device.h>

#include "bsp_dpa.h"
#include "dpa_fipc_plat.h"
#include "dpa_fipc_err_code.h"
#include "dpa_fipc_device.h"

#define DPA_MSG_MEM_ALIGN_DEFAULT (4)

static struct platform_device g_dpa_fipc_plat_device = {
    .name = "dpa_fipc_plat",
};

void *dpa_fipc_alloc_coherent(u32 size, dpafipcsoc_ptr_t *pa, u32 align)
{
    void *mem_addr = NULL;
    u32 align_sz;

    if (align < DPA_MSG_MEM_ALIGN_DEFAULT) {
        align = DPA_MSG_MEM_ALIGN_DEFAULT;
    }
    align_sz = dpa_fipc_roundup(size, align);
    mem_addr = dma_alloc_coherent(&g_dpa_fipc_plat_device.dev, align_sz, pa, GFP_KERNEL);
    if (mem_addr == NULL) {
        dpa_fipc_err("fipc_dma_alloc failed\n");
        return NULL;
    }
    return mem_addr;
}

void dpa_fipc_free_coherent(u32 size, void *va, dpafipcsoc_ptr_t pa)
{
    dma_free_coherent(&g_dpa_fipc_plat_device.dev, size, va, pa);
}

int dpa_fipc_device_init(void)
{
    int ret = dpa_fipc_device_probe();
    dpa_fipc_always("dpa_msg_device init: %d\n", ret);
    return ret;
}

static int dpa_fipc_plat_probe(struct platform_device *pdev)
{
    int ret = 0;
    struct device_node *parent_node = NULL;
    const char *node_path = "modem,dpa_fipc_device";

    parent_node = of_find_compatible_node(NULL, NULL, node_path);
    of_dma_configure(&pdev->dev, NULL, true);
    dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(64)); /* 64 bit */

    ret = dpa_fipc_device_dts_parse(parent_node);
    dpa_fipc_always("dpa_fipc_device_dts_parse: %d\n", ret);
    return ret;
}

static int dpa_fipc_suspend_wrapper(struct device *dev)
{
    return bsp_dpa_fipc_suspend();
}

static int dpa_fipc_resume_wrapper(struct device *dev)
{
    return bsp_dpa_fipc_resume();
}

static const struct dev_pm_ops g_dpa_fipc_pmops = {
    .suspend_noirq = dpa_fipc_suspend_wrapper,
    .resume_noirq = dpa_fipc_resume_wrapper,
    .prepare = NULL,
    .complete = NULL,
};

static struct platform_driver g_dpa_fipc_plat_driver = {
    .probe = dpa_fipc_plat_probe,
    .driver =
        {
            .name = "dpa_fipc_plat",
            .owner = THIS_MODULE,
            .probe_type = PROBE_FORCE_SYNCHRONOUS,
            .pm = &g_dpa_fipc_pmops,
        },
};

/* FIPC虽然有多个设备，但鉴于其关联特性，以及低功耗时间优化， 因此创建一个虚拟设备来统一处理所有fipc事务 */
int bsp_dpa_fipc_init(void)
{
    int ret = 0;

    static int inited = 0;
    if (inited) {
        return 0;
    }

    ret = platform_device_register(&g_dpa_fipc_plat_device);
    if (ret) {
        return ret;
    }
    ret = platform_driver_register(&g_dpa_fipc_plat_driver);
    if (ret) {
        platform_device_unregister(&g_dpa_fipc_plat_device);
        return ret;
    }
    inited = 1;
    dpa_fipc_always("dpa fipc init ok\n");
    return ret;
}

MODULE_DESCRIPTION("DPA MSG Driver");
MODULE_LICENSE("GPL");
