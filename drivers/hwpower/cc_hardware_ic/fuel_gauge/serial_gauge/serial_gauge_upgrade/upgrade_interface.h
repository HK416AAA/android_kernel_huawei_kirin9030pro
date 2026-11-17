/* SPDX-License-Identifier: GPL-2.0 */
/*
 * upgrade_interface.h
 *
 * serial gauge upgrade function interface
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

#ifndef _SERIAL_GAUGE_UPGRADE_INTERFACE_H_
#define _SERIAL_GAUGE_UPGRADE_INTERFACE_H_

#define SERIAL_GAUGE_FILE_PATH_LEN 100
#define SERIAL_GAUGE_MAX_LOW_SOC 20

/* firmware upgrade */
void serial_gauge_start_upgrade(void);
void serial_gauge_upgrade_free(void);

#endif /* _SERIAL_GAUGE_UPGRADE_INTERFACE_H_ */
