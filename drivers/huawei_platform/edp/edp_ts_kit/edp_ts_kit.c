/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include <linux/module.h>
#include <linux/of.h>
#include "edp_ts_kit.h"
#include "edp_log.h"

#define HW_EDP_PANEL_DEVICE_NODE "huawei,edp_panel"
#define NO_ERR 0

/* edp ts kit ops */
struct edp_ts_kit_ops *g_edp_ts_kit_ops;

/* edp ts kit ops register function */
int edp_ts_kit_ops_register(struct edp_ts_kit_ops *ops)
{
	struct device_node *np = NULL;

	np = of_find_compatible_node(NULL, NULL, HW_EDP_PANEL_DEVICE_NODE);
	if (!np) {
		edp_info("edp node is null\n");
		return -EINVAL;
	}

	if (!g_edp_ts_kit_ops) {
		g_edp_ts_kit_ops = ops;
		edp_info("edp ts kit ops register suc!\n");
		return NO_ERR;
	}

	edp_err("edp ts kit ops have been registered!\n");
	return -EINVAL;
}

/* edp ts kit ops unregister function */
int edp_ts_kit_ops_unregister(struct edp_ts_kit_ops *ops)
{
	struct device_node *np = NULL;

	np = of_find_compatible_node(NULL, NULL, HW_EDP_PANEL_DEVICE_NODE);
	if (!np) {
		edp_info("edp node is null\n");
		return -EINVAL;
	}

	if (g_edp_ts_kit_ops == ops) {
		g_edp_ts_kit_ops = NULL;
		edp_info("edp ts kit ops unregister suc!\n");
		return NO_ERR;
	}

	edp_err("edp ts kit ops unregister fail!\n");
	return -EINVAL;
}

/* get edp ts kit ops function */
struct edp_ts_kit_ops *edp_ts_kit_get_ops(void)
{
	return g_edp_ts_kit_ops;
}

/* edp lcd kit ops */
struct edp_tp_safe_rate_ops *g_edp_tp_safe_rate_ops = NULL;
/*edp_tp_safe_rate_ops register function */
int edp_tp_safe_rate_ops_register(struct edp_tp_safe_rate_ops *ops)
{
    if(ops == NULL) {
        edp_err("ops is NULL\n");
        return -EINVAL;
    }
    
	if (!g_edp_tp_safe_rate_ops) {
		g_edp_tp_safe_rate_ops = ops;
		edp_info("edp_tp_safe_rate_ops register suc!\n", __func__);
		return NO_ERR;
	}
	edp_err("edp_tp_safe_rate_ops have been registered!\n", __func__);
	return -EINVAL;
}

/* edp_tp_safe_rate_ops unregister function */
int edp_tp_safe_rate_ops_unregister(struct edp_tp_safe_rate_ops *ops)
{
    if(ops == NULL) {
        edp_err("ops is NULL\n");
        return -EINVAL;
    }

	if (g_edp_tp_safe_rate_ops == ops) {
		g_edp_tp_safe_rate_ops = NULL;
		edp_info("edp_tp_safe_rate_ops unregister suc!\n", __func__);
		return NO_ERR;
	}
	edp_err("edp_tp_safe_rate_ops unregister fail!\n", __func__);
	return -EINVAL;
}

/* get edp_tp_safe_rate_ops ops function */
struct edp_tp_safe_rate_ops *edp_tp_safe_rate_get_ops(void)
{
	return g_edp_tp_safe_rate_ops;
}