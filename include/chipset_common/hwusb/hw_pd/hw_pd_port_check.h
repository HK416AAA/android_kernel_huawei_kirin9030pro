/*
 * hw_pd_port_check.h
 *
 * Header file of port cehck operation interface of huawei PD driver
 *
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * Author: HUAWEI, Inc.
 *
 * This package is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
 
#ifndef _HW_PD_PORTCHECK_H_
#define _HW_PD_PORTCHECK_H_

struct fod_ops {
	bool (*is_fod_state)(void);
};

/* port check by user-space application */
void hw_pd_port_check_vbus(void);
int fod_ops_register(struct fod_ops *ops);

#endif /* _HW_PD_PORTCHECK_H_ */