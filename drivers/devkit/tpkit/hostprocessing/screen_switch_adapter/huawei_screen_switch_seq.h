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

#ifndef __SCREEN_SWITCH_SEQ__
#define __SCREEN_SWITCH_SEQ__
enum thp_screen_switch_spec_seq {
    SEQ0 = 0,
    SEQ1, 
    SEQ2, 
    SEQMAX = 255,
};
#if ((defined CONFIG_LCD_KIT_DRIVER) || (defined CONFIG_HW_EDP_DRIVER))
int thp_multi_screenon_fold_seq0(void);
int thp_multi_screenon_unfold_seq0(void);
int thp_multi_screenoff_fold_seq0(void);
int thp_multi_screenoff_unfold_seq0(void);
int thp_multi_screenon_fold_seq1(void);
int thp_multi_screenon_unfold_seq1(void);
int thp_multi_screenoff_fold_seq1(void);
int thp_multi_screenoff_unfold_seq1(void);
int thp_multi_screenon_fold_seq2(void);
int thp_multi_screenon_unfold_seq2(void);
int thp_multi_screenoff_fold_seq2(void);
int thp_multi_screenoff_unfold_seq2(void);
#endif
#endif