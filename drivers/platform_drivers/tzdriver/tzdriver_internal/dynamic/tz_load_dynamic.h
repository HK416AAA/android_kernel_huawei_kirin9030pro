/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2023. All rights reserved.
 * Description: Enable to load dynamic driver and server
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#ifndef TZ_LOAD_DYNAMIC_H
#define TZ_LOAD_DYNAMIC_H

#if defined(DYNAMIC_DRV_DIR) || defined(DYNAMIC_CRYPTO_DRV_DIR) || defined(DYNAMIC_SRV_DIR)
#if defined(DYNAMIC_DIR_CONFIGURABLE)
void tz_load_dynamic_dir(const char *dyn_drv_dir_add, const char *dyn_srv_dir_add, const char *dyn_crypto_dir_add);
#else
void tz_load_dynamic_dir(void);
#endif /* DYNAMIC_DIR_CONFIGURABLE */
#endif

#endif