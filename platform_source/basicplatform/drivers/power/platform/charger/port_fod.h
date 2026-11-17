/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * port_fod.h
 *
 * port fod header.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef __PORT_FOD_H__
#define __PORT_FOD_H__

#ifndef unused
#define unused(x) ((void)(x))
#endif

enum current_source_chsel {
    SBU1_CHL = 0,
    SBU2_CHL,
	DP_CHL,
	DM_CHL,
};

struct port_fod_ops {
	void (*ldo33_enable)(unsigned int enable);
	int (*open_current_source_det)(enum current_source_chsel source_chsel);
	int (*close_current_source_det)(enum current_source_chsel source_chsel);
	int (*get_adc_value)(int *val, enum current_source_chsel source_chsel);
	void (*app_det_en)(unsigned int enable);
};

#ifdef CONFIG_SCHARGER_PORT_FOD
int port_fod_ops_register(struct port_fod_ops* ops);
#else
static inline int port_fod_ops_register(struct port_fod_ops* ops) {
	unused(ops);
	return 0;
}
#endif
#endif /* __PORT_FOD_H__ */