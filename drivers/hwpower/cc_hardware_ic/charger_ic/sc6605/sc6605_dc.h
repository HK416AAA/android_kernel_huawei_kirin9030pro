/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * sc6605_dc.h
 *
 * sc6605 dc driver header file
 *
 * Copyright (c) 2024-2025 Huawei Technologies Co., Ltd.
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

#ifndef _SC6605_DC_H_
#define _SC6605_DC_H_

#include "sc6605_manager.h"
#include "sc6605_charger.h"
#include <chipset_common/hwpower/direct_charge/direct_charge_ic.h>


#define SC6605_OTG_VOUT_5V1           5100
#define SC6605_OTG_VBAT_STEP          300    /* 300mV */

#define DC_REG_DUMP                   0x60
#define DC_REG_COUNT                  0x73

/* VBUS_OVP reg */
#define SC6605_VBATSNS_OVP_REG        0x60
#define SC6605_VBATSNS_OVP_VAL        0x92
#define SC6605_VBUS2OUT_OVP_REG       0x62
#define SC6605_VBUS2OUT_OVP_VAL       0x07   /* 800mV */
#define VBUS2OUT_UVP_MAX              0x07

#define IBUS_UCP_RISE_STAT_MASK       BIT(5)
#define IBUS_OCP_STAT_MASK            BIT(2)
#define VBAT_OVP_CP_STAT_MASK         BIT(1)

struct sc6605_dc_dev {
	struct i2c_adapter *adp;
	struct device *dev;
	struct regmap *rmap;
	struct dc_ic_ops sc_ops;
	struct dc_ic_ops lvc_ops;
	struct dc_batinfo_ops batinfo_ops;
	int device_id;
	int irq;
};

#endif /* _SC6605_DC_H_ */