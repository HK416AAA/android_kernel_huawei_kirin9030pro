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

#ifndef __SCREEN_SWITCH_ADAPTER__
#define __SCREEN_SWITCH_ADAPTER__
#include "huawei_screen_switch_seq.h"

#if ((defined CONFIG_LCD_KIT_DRIVER) || (defined CONFIG_HW_EDP_DRIVER))

struct screen_switch_adapter;

enum thp_dual_screen_switch_arch {
    DUAL_THP = 0,
    THP_TSKIT,
    DUAL_SCREEN_SWITCH_ARCH_MAX = 255,
};

/* Only used for thp_tskit TP Software architecture */
enum lcd_spec_seq {
    LCD_SEQ0 = 0,
    LCD_SEQ1,
    LCD_SEQ_MAX = 255,
};

struct arch_adapt_ops {
    int (*fold)(void);
    int (*unfold)(void);
};

struct screen_switch_spec_adapt_ops {
    int (*screenon_fold)(void);
    int (*screenon_unfold)(void);
    int (*screenoff_fold)(void);
    int (*screenoff_unfold)(void);
};

struct lcd_spec_adapt_ops {
    int (*fold)(void);
    int (*unfold)(void);
};

struct screen_switch_adapter {
    struct arch_adapt_ops *ops;
    struct screen_switch_spec_adapt_ops *spec_ops;
    struct lcd_spec_adapt_ops *lcd_spec_ops;
};

struct screen_switch_adapter *get_screen_switch_adapter(void);
void screen_switch_adapter_release(struct screen_switch_adapter* screen_switch_adapter);
struct screen_switch_adapter *thp_screen_switch_adapt(enum thp_dual_screen_switch_arch dual_screen_switch_arch,
    enum thp_screen_switch_spec_seq screenon_spec_seq, enum thp_screen_switch_spec_seq screenoff_spec_seq);
int screen_switch_to_fold_for_dual_thp(void);
int screen_switch_to_unfold_for_dual_thp(void);
int screen_switch_to_fold_for_thp_tskit(void);
int screen_switch_to_unfold_for_thp_tskit(void);

/* Used For different LCD screen switch scheme */
int thp_tskit_fold_for_lcd_spec_seq0(void);
int thp_tskit_unfold_for_lcd_spec_seq0(void);
int thp_tskit_fold_for_lcd_spec_seq1(void);
int thp_tskit_unfold_for_lcd_spec_seq1(void);
#endif
#endif