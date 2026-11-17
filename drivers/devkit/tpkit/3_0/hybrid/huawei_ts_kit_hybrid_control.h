/* SPDX-License-Identifier: GPL-2.0 */
/*
 * huawei_ts_kit_hybrid_control.h
 *
 * head file for hybrid ts control
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
#ifndef __TS_KIT_HYBRID_CONTROL_H_
#define __TS_KIT_HYBRID_CONTROL_H_

int ts_hybrid_suspend(struct ts_hybrid_ctrl *ts_ctrl);
int ts_hybrid_resume(struct ts_hybrid_ctrl *ts_ctrl);
int ts_hybrid_idle(struct ts_hybrid_ctrl *ts_ctrl);

int ts_hybrid_normal2mcu(struct ts_hybrid_ctrl *ts_ctrl);
int ts_hybrid_idle2mcu(struct ts_hybrid_ctrl *ts_ctrl);
int ts_hybrid_sleep2mcu(struct ts_hybrid_ctrl *ts_ctrl);

int ts_hybrid_normal2ap(struct ts_hybrid_ctrl *ts_ctrl);
int ts_hybrid_idle2ap(struct ts_hybrid_ctrl *ts_ctrl);
int ts_hybrid_sleep2ap(struct ts_hybrid_ctrl *ts_ctrl);

int ts_hybrid_quickon(struct ts_hybrid_ctrl *ts_ctrl);

int ts_hybrid_input_reset(struct ts_hybrid_ctrl *ts_ctrl);

#endif
