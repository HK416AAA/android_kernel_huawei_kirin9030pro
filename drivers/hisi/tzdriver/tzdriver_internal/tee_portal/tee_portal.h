/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: function declaration interface for tee portal.
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
#ifndef TEE_PORTAL
#define TEE_PORTAL

int tee_portal_register(void *owner, void __user *arg);
int tee_portal_unregister(const void *owner);
int tee_portal_work(const void *owner);
void tee_portal_init(void);

#endif

