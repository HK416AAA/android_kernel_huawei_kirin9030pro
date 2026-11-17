/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 */
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/interrupt.h>
#include <linux/of_irq.h>
#include "dpa_fipc_plat.h"
#include "dpa_fipc_device.h"
#include "dpa_fipc_err_code.h"
#include "dpa_fipc_core.h"

#define DPA_FIPC_MAX_PIPES_NUM (32)

static int dpa_fipc_dev_irq_parse(struct device_node *p_irq_node, struct dpa_fipc_device_t *pdev)
{
    u32 cpu_id;
    struct dpa_fipc_irq_bundle *maps = NULL;
    if (of_property_read_u32_array(p_irq_node, "cpu_id", &cpu_id, 1)) {
        /* not a irq bundle ,may be other type; */
        return 0;
    }

    if (cpu_id >= DPA_FIPC_CPU_ID_MAX) {
        dpa_fipc_err("dts irq_bundle[%d] outrange error!\n", cpu_id);
        return -1;
    }
    maps = &pdev->maps[cpu_id];
    maps->cpu_id = cpu_id;

    maps->irq[0] = irq_of_parse_and_map(p_irq_node, 0);
    maps->irq[1] = irq_of_parse_and_map(p_irq_node, 1);
#ifdef CONFIG_LIBLINUX
    if (of_property_read_u32_array(p_irq_node, "hwirq_opipe", &maps->hwirq_opipe, 1)) {
        maps->hwirq_opipe = 0;
    }

    if (of_property_read_u32_array(p_irq_node, "hwirq_ipipe", &maps->hwirq_ipipe, 1)) {
        maps->hwirq_ipipe = 0;
    }
#endif
    maps->pdev = pdev;
    return 0;
}

static int dpa_fipc_dev_irq_probe(struct device_node *p_dev_node, struct dpa_fipc_device_t *pdev)
{
    u32 i;
    struct dpa_fipc_irq_bundle *pmap;
    struct device_node temp_node;
    struct device_node *p_child_node = &temp_node; /* for reduced dts version */

    (void)memset_s(p_child_node, sizeof(struct device_node), 0, sizeof(struct device_node));
    for (i = 0; i < DPA_FIPC_CPU_ID_MAX; i++) {
        pmap = &pdev->maps[i];
        (void)memset_s(pmap, sizeof(struct dpa_fipc_irq_bundle), 0, sizeof(struct dpa_fipc_irq_bundle));
    }
    for_each_child_of_node(p_dev_node, p_child_node)
    {
        if (dpa_fipc_dev_irq_parse(p_child_node, pdev)) {
            dpa_fipc_err("irq parse failed!\n");
            return DPA_FIPC_ERR_ENXIO;
        }
    }
    return 0;
}
static int dpa_fipc_phy_chns_parse(struct device_node *p_dev_node, struct dpa_fipc_channel *channel)
{
    int ret;

    if (channel == NULL || p_dev_node == NULL) {
        dpa_fipc_err("dpa_fipc_phy_chns_parse bad input!\n");
        return DPA_FIPC_ERR_EIO;
    }

    ret = of_property_read_u32_array(p_dev_node, "pipe_id", &channel->pipe_id, 1);
    ret |= of_property_read_u32_array(p_dev_node, "core_id", &channel->core_id, 1);
    ret |= of_property_read_u32_array(p_dev_node, "chn_type", &channel->type, 1);
    ret |= of_property_read_u32_array(p_dev_node, "depth", &channel->depth, 1);
    if (ret) {
        dpa_fipc_err("phy chnl parse failed!\n");
        return DPA_FIPC_ERR_EINVAL;
    }

    channel->state = DPA_FIPC_CHN_INIT;

    return 0;
}

static int dpa_fipc_phy_chns_probe(struct device_node *p_dev_node, struct dpa_fipc_device_t *pdev)
{
    u32 pipe_id;
    struct device_node temp_node;
    struct dpa_fipc_channel *p_phychnl = NULL;
    struct device_node *p_child_node = &temp_node; /* for reduced dts version */

    if (p_dev_node == NULL || pdev == NULL) {
        return DPA_FIPC_ERR_EIO;
    }

    (void)memset_s(p_child_node, sizeof(struct device_node), 0, sizeof(struct device_node));
    for_each_child_of_node(p_dev_node, p_child_node)
    {
        if (of_property_read_u32_array(p_child_node, "pipe_id", &pipe_id, 1)) {
            continue;
        }
        if (pipe_id >= pdev->pipepair_cnt) {
            return DPA_FIPC_ERR_OUT_OF_RANGE;
        }

        p_phychnl = (struct dpa_fipc_channel *)dpa_fipc_malloc(sizeof(struct dpa_fipc_channel));
        if (p_phychnl == NULL) {
            return DPA_FIPC_ERR_ENOMEM;
        }
        (void)memset_s(p_phychnl, sizeof(struct dpa_fipc_channel), 0, sizeof(struct dpa_fipc_channel));

        if (dpa_fipc_phy_chns_parse(p_child_node, p_phychnl)) {
            return DPA_FIPC_ERR_ENXIO;
        }
        pdev->p_phychnl[pipe_id] = p_phychnl;
    }
    return 0;
}

static int dpa_fipc_clk_parse(struct device_node *p_dev_node, struct dpa_fipc_device_t *pdev)
{
    int ret;
    u32 array[0x2] = {0};

    if (pdev == NULL || p_dev_node == NULL) {
        return DPA_FIPC_ERR_EIO;
    }

    ret = of_property_read_u32_array(p_dev_node, "dpa_fipc_crg_base", array, sizeof(array) / sizeof(array[0]));
    ret |= of_property_read_u32_array(p_dev_node, "dpa_fipc_clk_en", &pdev->clock.dev_crg_clk_en_offset, 1);
    ret |= of_property_read_u32_array(p_dev_node, "dpa_fipc_clk_dis", &pdev->clock.dev_crg_clk_dis_offset, 1);
    ret |= of_property_read_u32_array(p_dev_node, "dpa_fipc_clk_mask", &pdev->clock.dev_crg_clk_mask, 1);
    if (ret) {
        dpa_fipc_err("clk parse failed!\n");
        return DPA_FIPC_ERR_EINVAL;
    }
    pdev->clock.dev_crg_base = array[0];
    pdev->clock.dev_crg_size = array[1];
    pdev->clock.dev_crg_base_va = ioremap(pdev->clock.dev_crg_base, pdev->clock.dev_crg_size);
    if (pdev->clock.dev_crg_base_va == NULL) {
        dpa_fipc_err("dpa fipc clk addr ioremap failed!\n");
        return DPA_FIPC_ERR_MEM_OP_FAILED;
    }
    return 0;
}

static int dpa_fipc_clk_probe(struct device_node *p_dev_node, struct dpa_fipc_device_t *pdev)
{
    struct device_node *p_child_node = NULL;
    if (p_dev_node == NULL || pdev == NULL) {
        return DPA_FIPC_ERR_EIO;
    }
    p_child_node = of_get_child_by_name(p_dev_node, "dpa_fipc_clk");
    if (p_child_node == NULL) {
        dpa_fipc_err("No clk dts found!\n");
        return DPA_FIPC_ERR_ENXIO;
    }
    return dpa_fipc_clk_parse(p_child_node, pdev);
}

static int dpa_fipc_base_probe(struct device_node *p_dev_node, struct dpa_fipc_device_t *pdev)
{
    int ret;
    u32 array[0x2] = {0};
    if (pdev == NULL || p_dev_node == NULL) {
        dpa_fipc_err("dpa_msg_device_dts_parse error!\n");
        return DPA_FIPC_ERR_EIO;
    }

    ret = of_property_read_u32_array(p_dev_node, "version", &pdev->version, 1);
    ret |= of_property_read_u32_array(p_dev_node, "reg", array, sizeof(array) / sizeof(array[0]));
    ret |= of_property_read_u32_array(p_dev_node, "pipepair_cnt", &pdev->pipepair_cnt, 1);
    if (ret) {
        dpa_fipc_err("base info dts node error!\n");
        return DPA_FIPC_ERR_ENXIO;
    }
    if (pdev->pipepair_cnt > DPA_FIPC_MAX_PIPES_NUM) {
        dpa_fipc_err("big pipepair_cnt %d!\n", pdev->pipepair_cnt);
        return DPA_FIPC_ERR_ENXIO;
    }
    pdev->base_pa = array[0x0];
    pdev->base_va = ioremap(pdev->base_pa, array[0x1]);
    if (pdev->base_va == NULL) {
        dpa_fipc_err("dpa fipc base addr ioremap failed!\n");
        return DPA_FIPC_ERR_MEM_OP_FAILED;
    }
    return 0;
}

int dpa_fipc_device_dts_parse(struct device_node *p_dev_node)
{
    int ret;
    struct dpa_fipc_device_t *pdev = dpa_get_fipc_device();
    if (pdev == NULL) {
        return DPA_FIPC_ERR_ENXIO;
    }

    ret = dpa_fipc_base_probe(p_dev_node, pdev);
    if (ret) {
        dpa_fipc_err("base info parsed failed:%d", ret);
        return ret;
    }

    ret = dpa_fipc_dev_irq_probe(p_dev_node, pdev);
    if (ret) {
        dpa_fipc_err("irq parsed failed:%d", ret);
        return ret;
    }

    ret = dpa_fipc_phy_chns_probe(p_dev_node, pdev);
    if (ret) {
        dpa_fipc_err("phy channels parsed failed:%d", ret);
        return ret;
    }

    ret = dpa_fipc_clk_probe(p_dev_node, pdev);
    if (ret) {
        dpa_fipc_err("clk parsed failed:%d", ret);
        return ret;
    }
    return 0;
}