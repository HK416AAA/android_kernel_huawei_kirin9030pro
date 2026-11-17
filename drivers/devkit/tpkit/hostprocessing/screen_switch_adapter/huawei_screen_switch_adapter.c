/*
 * Huawei Touchscreen Driver
 *
 * Copyright (c) 2024-2024 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#include "huawei_screen_switch_adapter.h"
#include <linux/slab.h>
#include "huawei_thp.h"

#if ((defined CONFIG_LCD_KIT_DRIVER) || (defined CONFIG_HW_EDP_DRIVER))

static struct screen_switch_adapter *g_screen_switch_adapter;

struct screen_switch_adapter *get_screen_switch_adapter(void)
{
    if(!g_screen_switch_adapter)
        return NULL;
    return g_screen_switch_adapter;
}

/* Only Used for THP_TSKIT dual screen architecture */
int lcd_spec_adapter(enum lcd_spec_seq lcd_spec_seq)
{
    thp_log_info("%s:called\n", __func__);
    switch (lcd_spec_seq) {
    case LCD_SEQ0:
        g_screen_switch_adapter->lcd_spec_ops->fold = thp_tskit_fold_for_lcd_spec_seq0;
        g_screen_switch_adapter->lcd_spec_ops->unfold = thp_tskit_unfold_for_lcd_spec_seq0;
        return NO_ERR;
    case LCD_SEQ1:
        g_screen_switch_adapter->lcd_spec_ops->fold = thp_tskit_fold_for_lcd_spec_seq1;
        g_screen_switch_adapter->lcd_spec_ops->unfold = thp_tskit_unfold_for_lcd_spec_seq1;
        return NO_ERR;
    default:
        thp_log_err("%s:invalid value, please check dts config\n", __func__);
        return -EINVAL;
    }
}

int screen_switch_arch_adapter(enum thp_dual_screen_switch_arch dual_screen_switch_arch)
{
    struct thp_core_data *cd = thp_get_core_data(MAIN_TOUCH_PANEL);

    thp_log_info("%s:called\n", __func__);
    switch (dual_screen_switch_arch) {
    case DUAL_THP:
        g_screen_switch_adapter->ops->fold = screen_switch_to_fold_for_dual_thp;
        g_screen_switch_adapter->ops->unfold = screen_switch_to_unfold_for_dual_thp;
        return NO_ERR;
    case THP_TSKIT:
        g_screen_switch_adapter->ops->fold = screen_switch_to_fold_for_thp_tskit;
        g_screen_switch_adapter->ops->unfold = screen_switch_to_unfold_for_thp_tskit;
        /* TP Screen Switch Adapt LCD Screen Switch arch */
        lcd_spec_adapter(cd->thp_tskit_fold_scheme);
        return NO_ERR;
    default:
		thp_log_err("%s:invalid value, please check dts config\n", __func__);
        return -EINVAL;
    }
}

int screenon_spec_adapter(enum thp_screen_switch_spec_seq screenon_spec_seq)
{
    thp_log_info("%s:called\n", __func__);
    switch (screenon_spec_seq) {
    case SEQ0:
        g_screen_switch_adapter->spec_ops->screenon_fold = thp_multi_screenon_fold_seq0;
        g_screen_switch_adapter->spec_ops->screenon_unfold = thp_multi_screenon_unfold_seq0;
        return NO_ERR;
    case SEQ1:
        g_screen_switch_adapter->spec_ops->screenon_fold = thp_multi_screenon_fold_seq1;
        g_screen_switch_adapter->spec_ops->screenon_unfold = thp_multi_screenon_unfold_seq1;
        return NO_ERR;
    case SEQ2:
        g_screen_switch_adapter->spec_ops->screenon_fold = thp_multi_screenon_fold_seq2;
        g_screen_switch_adapter->spec_ops->screenon_unfold = thp_multi_screenon_unfold_seq2;
        return NO_ERR;
    default:
		thp_log_err("%s:invalid value, please check dts config\n", __func__);
        return -EINVAL;
    }
}

int screenoff_spec_adapter(enum thp_screen_switch_spec_seq screenoff_spec_seq)
{
    thp_log_info("%s:called\n", __func__);
    switch (screenoff_spec_seq) {
    case SEQ0:
        g_screen_switch_adapter->spec_ops->screenoff_fold = thp_multi_screenoff_fold_seq0;
        g_screen_switch_adapter->spec_ops->screenoff_unfold = thp_multi_screenoff_unfold_seq0;
        return NO_ERR;
    case SEQ1:
        g_screen_switch_adapter->spec_ops->screenoff_fold = thp_multi_screenoff_fold_seq1;
        g_screen_switch_adapter->spec_ops->screenoff_unfold = thp_multi_screenoff_unfold_seq1;
        return NO_ERR;
    case SEQ2:
        g_screen_switch_adapter->spec_ops->screenoff_fold = thp_multi_screenoff_fold_seq2;
        g_screen_switch_adapter->spec_ops->screenoff_unfold = thp_multi_screenoff_unfold_seq2;
        return NO_ERR;
    default:
		thp_log_err("%s:invalid value, please check dts config\n", __func__);
        return -EINVAL;
    }
}

int screen_switch_spec_adapter(enum thp_screen_switch_spec_seq screenon_spec_seq,
    enum thp_screen_switch_spec_seq screenoff_spec_seq)
{
    int ret;

    thp_log_info("%s:called\n", __func__);
    ret = screenon_spec_adapter(screenon_spec_seq);
    if (ret)
        goto out;
    ret = screenoff_spec_adapter(screenoff_spec_seq);
    if (ret)
        goto out;
out:
    return ret;
}

void screen_switch_adapter_release(struct screen_switch_adapter* screen_switch_adapter)
{
    struct thp_core_data *cd = thp_get_core_data(MAIN_TOUCH_PANEL);

    thp_log_info("%s:called\n", __func__);
    kfree(screen_switch_adapter->spec_ops);
    screen_switch_adapter->spec_ops = NULL;
    if (cd->screen_switch_config.dual_screen_arch) {
        kfree(screen_switch_adapter->lcd_spec_ops);
        screen_switch_adapter->lcd_spec_ops = NULL; 
    }
    kfree(screen_switch_adapter->ops);
    screen_switch_adapter->ops = NULL;  
    kfree(screen_switch_adapter);
    screen_switch_adapter = NULL;
}
EXPORT_SYMBOL(screen_switch_adapter_release);

int thp_screen_switch_adapter_memory_alloc(void)
{
    g_screen_switch_adapter = kzalloc(sizeof(struct screen_switch_adapter), GFP_KERNEL);
    if (!g_screen_switch_adapter)
        return NO_ERR;
    g_screen_switch_adapter->ops = kzalloc(sizeof(struct arch_adapt_ops), GFP_KERNEL);
    if (!g_screen_switch_adapter->ops) {
        thp_log_err("failed to kzalloc g_screen_switch_adapter->ops\n");
        goto error;
    }

    g_screen_switch_adapter->lcd_spec_ops = kzalloc(sizeof(struct lcd_spec_adapt_ops), GFP_KERNEL);
    if (!g_screen_switch_adapter->lcd_spec_ops) {
        thp_log_err("failed to kzalloc g_screen_switch_adapter->lcd_ops\n");
        goto error;
    }

    g_screen_switch_adapter->spec_ops = kzalloc(sizeof(struct screen_switch_spec_adapt_ops), GFP_KERNEL);
    if (!g_screen_switch_adapter->spec_ops) {
        thp_log_err("failed to kzalloc g_screen_switch_adapter->spec_ops\n");
        goto error;
    }
    return NO_ERR;
error:
    screen_switch_adapter_release(g_screen_switch_adapter);
    return -ENOMEM;
}

struct screen_switch_adapter *thp_screen_switch_adapt(enum thp_dual_screen_switch_arch dual_screen_switch_arch,
    enum thp_screen_switch_spec_seq screenon_spec_seq, enum thp_screen_switch_spec_seq screenoff_spec_seq)
{
    int ret;

    thp_log_info("%s:called\n", __func__);

    ret = thp_screen_switch_adapter_memory_alloc();
    if (ret)
        return NULL;

    /* TP Screen Switch Architecture Adapt */
    ret = screen_switch_arch_adapter(dual_screen_switch_arch);
    if (ret)
        goto error;

    /* adapt different fold or unfold process */
    ret = screen_switch_spec_adapter(screenon_spec_seq, screenoff_spec_seq);
    if (ret)
        goto error;

    return g_screen_switch_adapter;
error:
    thp_log_info("%s:thp_screen_switch_adapt error\n", __func__);
    screen_switch_adapter_release(g_screen_switch_adapter);
    return NO_ERR;
}
#endif