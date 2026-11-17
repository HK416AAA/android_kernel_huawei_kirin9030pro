/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 */
#include <linux/version.h>
#include <linux/types.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/interrupt.h>
#include <linux/of_irq.h>
#include <linux/dma-mapping.h>
#include "dpa_msg_dts.h"
#include "bsp_dpa_fipc.h"
#include "dpa_msg_cmsg.h"
#include "dpa_msg_error_code.h"

static dpa_msg_cpugroup_dts_t g_dpa_msg_cpugroup_dts = {0};
dpa_msg_cpugroup_dts_t *dpa_msg_of_find_root_node(void)
{
    return &g_dpa_msg_cpugroup_dts;
}

static int dpa_msg_chns_parse(struct device_node *p_dev_node, dpa_msg_cpugroup_dts_t *pmsg_dts)
{
    u32 index;
    int ret;
    dpa_msg_phychn_dts_t *p_phychnl = NULL;
    struct device_node temp_node;
    struct device_node *p_child_node = &temp_node; /* for reduced dts version */

    if (p_dev_node == NULL || pmsg_dts == NULL) {
        return MSG_ERR_EIO;
    }
    if (pmsg_dts->phychn_cnt != 0) {
        // phychn_cnt不为0，说明已经初始化过了
        dpa_msg_err("msg dts alreay parsed!\n");
        return 0;
    }

    if (of_property_read_u32_array(p_dev_node, "chnl_num", &pmsg_dts->phychn_cnt, 1)) {
        dpa_msg_err("No chnl_num dts found!\n");
        return MSG_ERR_ENXIO;
    }

    pmsg_dts->msg_phychn_dts = (dpa_msg_phychn_dts_t *)kmalloc(sizeof(dpa_msg_phychn_dts_t) * pmsg_dts->phychn_cnt, GFP_KERNEL);

    (void)memset_s(p_child_node, sizeof(struct device_node), 0, sizeof(struct device_node));
    for_each_child_of_node(p_dev_node, p_child_node)
    {
        if (of_property_read_u32_array(p_child_node, "index", &index, 1)) {
            dpa_msg_err("No index dts found!\n");
            continue;
        }
        // 此处检查是为了及时发现配置中，phy_chnl_num与实际配置的通道不符的情况
        if (index >= pmsg_dts->phychn_cnt) {
            dpa_msg_err("bad index dts: %d!\n", index);
            return MSG_ERR_COMMON_OUT_OF_LIMIT;
        }
        p_phychnl = &pmsg_dts->msg_phychn_dts[index];
        p_phychnl->index = index;
        ret = of_property_read_u32_array(p_child_node, "dir", &p_phychnl->dir, 1);
        ret |= of_property_read_u32_array(p_child_node, "chnid", &p_phychnl->phychnid, 1);
        ret |= of_property_read_u32_array(p_child_node, "smsg_sz", &p_phychnl->smsg_sz, 1);
        ret |= of_property_read_u32_array(p_child_node, "buf_sz", &p_phychnl->buf_sz, 1);
        if (ret) {
            dpa_msg_err("bad msg chnl dts index[%d]!\n", index);
            return MSG_ERR_ENXIO;
        }
    }
    return 0;
}

int dpa_msg_dts_chns_probe(struct device_node *p_dev_node, dpa_msg_cpugroup_dts_t *pmsg_dts)
{
    struct device_node *p_child_node = NULL;
    if (p_dev_node == NULL || pmsg_dts == NULL) {
        dpa_msg_err("dpa_msg_dts_chns_probe bad input!\n");
        return MSG_ERR_EIO;
    }
    p_child_node = of_get_child_by_name(p_dev_node, "msg_cid_dpa");
    if (p_child_node == NULL) {
        dpa_msg_err("No dpa msg dts found!\n");
        return MSG_ERR_ENXIO;
    }
    return dpa_msg_chns_parse(p_child_node, pmsg_dts);
}

int dpa_msg_plat_probe(struct platform_device *pdev)
{
    int ret = 0;
    struct device_node *parent_node = NULL;
    const char *node_path = "modem,dpa_msg_device";

    parent_node = of_find_compatible_node(NULL, NULL, node_path);
    of_dma_configure(&pdev->dev, NULL, true);
    dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(64)); /* 64 bit */

    ret = dpa_msg_dts_chns_probe(parent_node, &g_dpa_msg_cpugroup_dts);
    return ret;
}