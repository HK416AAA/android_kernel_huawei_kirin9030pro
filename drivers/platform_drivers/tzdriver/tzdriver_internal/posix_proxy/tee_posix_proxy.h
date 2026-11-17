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
#ifndef TEE_POSIX_PROXY_H
#define TEE_POSIX_PROXY_H

int tee_posix_proxy_register_tasklet(void __user *arg, unsigned int nsid);
int tee_posix_proxy_unregister_all_tasklet(void);

void tee_posix_proxy_init(void);

#endif

