/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: MP12 ssi host entry function declaration.
 * Author: platform drivers
 */

#ifndef SSI_MP12_H
#define SSI_MP12_H

#ifdef _PRE_CONFIG_GPIO_TO_SSI_DEBUG
int mp12_ssi_config(unsigned long long module_set);
int mp12_ssi_check_subsys_is_work(void);
void mp12_ssi_dump_gpio(void);
void mp12_ssi_dump_cpu_trace(void);
#endif /* #ifdef __PRE_CONFIG_GPIO_TO_SSI_DEBUG */
#endif /* #ifndef SSI_MP12_H */
