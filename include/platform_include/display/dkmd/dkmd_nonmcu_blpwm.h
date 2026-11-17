/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef DPU_NONMCU_BLPWM_H
#define DPU_NONMCU_BLPWM_H

#define BLPWM_FREQUENCY_DEFAULT 0xFF
#define BLPWM_CYCLE_DEFAULT 0x0FFF0FFF

#define BLPWM_ADDR_SIZE 0x1000U
#define IOREMAP_LIST_SIZE 5
#define BLPWM_SET_INDEX 0
#define BLPWM_GET_INDEX 1

#define BLPWM_BUTT (-1)
#define BLPWM0 0
#define BLPWM1 1
#define BLPWM2 2
#define BLPWM3 3
#define BLPWM_READ 0
#define BLPWM_WRITE 1
#define PWM0_FREQUENCY_VAL 0xD0
#define PWM0_CYCLE_VAL 1000

typedef struct blpwm_reg_val {
	int operation;
	unsigned int base_addr;
	unsigned int offset_addr;
	unsigned int data;
} blpwm_reg_val_t;

typedef struct blpwm_ioremap {
	unsigned int base_addr;
	char __iomem *base_io_addr;
} blpwm_ioremap_t;

typedef struct blpwm_ioremap_info {
	unsigned int current_size;
	unsigned int next_index;
	blpwm_ioremap_t *ioremap_list;
} blpwm_ioremap_info_t;

typedef struct blpwm_operate_config {
	int blpwm_type;
	blpwm_reg_val_t *blpwm_init_config;
	unsigned long blpwm_init_config_size;
	blpwm_reg_val_t *blpwm_enable_config;
	unsigned long blpwm_enable_config_size;
	blpwm_reg_val_t *blpwm_disable_config;
	unsigned long blpwm_disable_config_size;
	blpwm_reg_val_t *blpwm_frequency_config;
	unsigned long blpwm_frequency_config_size;
	blpwm_reg_val_t *blpwm_cycle_config;
	unsigned long blpwm_cycle_config_size;
} blpwm_operate_config_t;

blpwm_operate_config_t* dkmd_get_blpwm_config(int blpwm_type);
int dkmd_blpwm_init(blpwm_operate_config_t* blpwm_operate_config);
int dkmd_blpwm_enable(blpwm_operate_config_t* blpwm_operate_config);
int dkmd_blpwm_disable(blpwm_operate_config_t* blpwm_operate_config);
int dkmd_blpwm_set_frequency(blpwm_operate_config_t* blpwm_operate_config, unsigned int reg_data);
int dkmd_blpwm_get_frequency(blpwm_operate_config_t* blpwm_operate_config, unsigned int *reg_data);
int dkmd_blpwm_set_cycle(blpwm_operate_config_t* blpwm_operate_config, unsigned int reg_data);
int dkmd_blpwm_get_cycle(blpwm_operate_config_t* blpwm_operate_config, unsigned int *reg_data);
int dkmd_display_blpwm_custom_settings(int pwm_type, bool pwm_gen, unsigned int frequency_val, unsigned int cycle_val);

static blpwm_reg_val_t blpwm0_init_config[] = {
	{BLPWM_WRITE,  0xEC929000U, 0x084U, 0x01U}, // Configuring the multiplexing relationship
	{BLPWM_WRITE,  0xEC928000U, 0x084U, 0x01U}, // Configuring the multiplexing relationship
};

static blpwm_reg_val_t blpwm0_enable_config[] = {
	{BLPWM_WRITE,  0xEC875000U, 0x100U, 0x01U}, // enable
	{BLPWM_READ,   0xEC875000U, 0x100U, 0x0U},
};

static blpwm_reg_val_t blpwm0_disable_config[] = {
	{BLPWM_WRITE,  0xEC875000U, 0x100U, 0x0U}, // disable
	{BLPWM_READ,   0xEC875000U, 0x100U, 0x0U},
};

static blpwm_reg_val_t blpwm0_frequency_config[] = {
	{BLPWM_WRITE,  0xEC875000U, 0x104U, 0x0U}, // The maximum frequency is 255
	{BLPWM_READ,   0xEC875000U, 0x104U, 0x0U},
};

static blpwm_reg_val_t blpwm0_cycle_config[] = {
	{BLPWM_WRITE,  0xEC875000U, 0x108U, 0x0U}, // duty cycle
	{BLPWM_READ,   0xEC875000U, 0x108U, 0x0U},
};

static blpwm_reg_val_t blpwm1_init_config[] = {
	{BLPWM_WRITE,  0xe0385000U, 0x034U, 0x01U}, // Configuring the multiplexing relationship
	{BLPWM_WRITE,  0xe0386000U, 0x034U, 0x01U}, // Configuring the multiplexing relationship
	{BLPWM_READ,   0xffb85000U, 0x028U, 0x0U},
	{BLPWM_WRITE,  0xffb85000U, 0x020U, 0x01U}, // open the clock
	{BLPWM_READ,   0xffb85000U, 0x028U, 0x0U},
	{BLPWM_WRITE,  0xffb85000U, 0x078U, 0x10U}, // soft reset
	{BLPWM_WRITE,  0xffb85000U, 0x07cU, 0x10U}, // soft reset
	{BLPWM_READ,   0xffb85000U, 0x080U, 0x0U},
};

static blpwm_reg_val_t blpwm1_enable_config[] = {
	{BLPWM_WRITE,  0xE0320000U, 0x100U, 0x01U},
	{BLPWM_READ,   0xE0320000U, 0x100U, 0x0U},
};

static blpwm_reg_val_t blpwm1_disable_config[] = {
	{BLPWM_WRITE,  0xE0320000U, 0x100U, 0x0U},
	{BLPWM_READ,   0xE0320000U, 0x100U, 0x0U},
};

static blpwm_reg_val_t blpwm1_frequency_config[] = {
	{BLPWM_WRITE,  0xE0320000U, 0x104U, 0x0U},
	{BLPWM_READ,   0xE0320000U, 0x104U, 0x0U},
};

static blpwm_reg_val_t blpwm1_cycle_config[] = {
	{BLPWM_WRITE,  0xE0320000U, 0x108U, 0x0U},
	{BLPWM_READ,   0xE0320000U, 0x108U, 0x0U},
};

static blpwm_reg_val_t blpwm2_init_config[] = {
	{BLPWM_WRITE,  0xec929000U, 0x088U, 0x01U},
	{BLPWM_WRITE,  0xec928000U, 0x088U, 0x01U},
	{BLPWM_WRITE,  0xEC94D000U, 0x164U, 0x40004000U},
	{BLPWM_WRITE,  0xEC94D000U, 0x000U, 0x10000U},
	{BLPWM_READ,   0xEC94D000U, 0x008U, 0x0U},
	{BLPWM_WRITE,  0xEC94D000U, 0x100U, 0x10U},
	{BLPWM_WRITE,  0xEC94D000U, 0x104U, 0x10U},
	{BLPWM_READ,   0xEC94D000U, 0x108U, 0x0U},
};

static blpwm_reg_val_t blpwm2_enable_config[] = {
	{BLPWM_WRITE,  0xEC94C000U, 0x100U, 0x01U},
	{BLPWM_READ,   0xEC94C000U, 0x100U, 0x0U},
};

static blpwm_reg_val_t blpwm2_disable_config[] = {
	{BLPWM_WRITE,  0xEC94C000U, 0x100U, 0x0U},
	{BLPWM_READ,   0xEC94C000U, 0x100U, 0x0U},
};

static blpwm_reg_val_t blpwm2_frequency_config[] = {
	{BLPWM_WRITE,  0xEC94C000U, 0x104U, 0x0U},
	{BLPWM_READ,   0xEC94C000U, 0x104U, 0x0U},
};

static blpwm_reg_val_t blpwm2_cycle_config[] = {
	{BLPWM_WRITE,  0xEC94C000U, 0x108U, 0x0U},
	{BLPWM_READ,   0xEC94C000U, 0x108U, 0x0U},
};

static blpwm_reg_val_t blpwm3_init_config[] = {
	{BLPWM_WRITE,  0xe0381000U, 0x0a4U, 0x01U},
	{BLPWM_WRITE,  0xe0380000U, 0x0a4U, 0x01U},
	{BLPWM_READ,   0xffb85000U, 0x038U, 0x0U},
	{BLPWM_WRITE,  0xffb85000U, 0x030U, 0x08U},
	{BLPWM_READ,   0xffb85000U, 0x038U, 0x0U},
	{BLPWM_WRITE,  0xffb85000U, 0x084U, 0x08U},
	{BLPWM_WRITE,  0xffb85000U, 0x088U, 0x08U},
	{BLPWM_READ,   0xffb85000U, 0x08CU, 0x0U},
};

static blpwm_reg_val_t blpwm3_enable_config[] = {
	{BLPWM_WRITE,  0xE0323000U, 0x100U, 0x01U},
	{BLPWM_READ,   0xE0323000U, 0x100U, 0x0U},
};

static blpwm_reg_val_t blpwm3_disable_config[] = {
	{BLPWM_WRITE,  0xE0323000U, 0x100U, 0x0U},
	{BLPWM_READ,   0xE0323000U, 0x100U, 0x0U},
};

static blpwm_reg_val_t blpwm3_frequency_config[] = {
	{BLPWM_WRITE,  0xE0323000U, 0x104U, 0x0U},
	{BLPWM_READ,   0xE0323000U, 0x104U, 0x0U},
};

static blpwm_reg_val_t blpwm3_cycle_config[] = {
	{BLPWM_WRITE,  0xE0323000U, 0x108U, 0x0U},
	{BLPWM_READ,   0xE0323000U, 0x108U, 0x0U},
};

static blpwm_operate_config_t blpwm_operate_config_list[] = {
	{
		.blpwm_type = BLPWM0,
		.blpwm_init_config = blpwm0_init_config,
		.blpwm_init_config_size = ARRAY_SIZE(blpwm0_init_config),
		.blpwm_enable_config = blpwm0_enable_config,
		.blpwm_enable_config_size = ARRAY_SIZE(blpwm0_enable_config),
		.blpwm_disable_config = blpwm0_disable_config,
		.blpwm_disable_config_size = ARRAY_SIZE(blpwm0_disable_config),
		.blpwm_frequency_config = blpwm0_frequency_config,
		.blpwm_frequency_config_size = ARRAY_SIZE(blpwm0_frequency_config),
		.blpwm_cycle_config = blpwm0_cycle_config,
		.blpwm_cycle_config_size = ARRAY_SIZE(blpwm0_cycle_config),
	},
	{
		.blpwm_type = BLPWM1,
		.blpwm_init_config = blpwm1_init_config,
		.blpwm_init_config_size = ARRAY_SIZE(blpwm1_init_config),
		.blpwm_enable_config = blpwm1_enable_config,
		.blpwm_enable_config_size = ARRAY_SIZE(blpwm1_enable_config),
		.blpwm_disable_config = blpwm1_disable_config,
		.blpwm_disable_config_size = ARRAY_SIZE(blpwm1_disable_config),
		.blpwm_frequency_config = blpwm1_frequency_config,
		.blpwm_frequency_config_size = ARRAY_SIZE(blpwm1_frequency_config),
		.blpwm_cycle_config = blpwm1_cycle_config,
		.blpwm_cycle_config_size = ARRAY_SIZE(blpwm1_cycle_config),
	},
	{
		.blpwm_type = BLPWM2,
		.blpwm_init_config = blpwm2_init_config,
		.blpwm_init_config_size = ARRAY_SIZE(blpwm2_init_config),
		.blpwm_enable_config = blpwm2_enable_config,
		.blpwm_enable_config_size = ARRAY_SIZE(blpwm2_enable_config),
		.blpwm_disable_config = blpwm2_disable_config,
		.blpwm_disable_config_size = ARRAY_SIZE(blpwm2_disable_config),
		.blpwm_frequency_config = blpwm2_frequency_config,
		.blpwm_frequency_config_size = ARRAY_SIZE(blpwm2_frequency_config),
		.blpwm_cycle_config = blpwm2_cycle_config,
		.blpwm_cycle_config_size = ARRAY_SIZE(blpwm2_cycle_config),
	},
	{
		.blpwm_type = BLPWM3,
		.blpwm_init_config = blpwm3_init_config,
		.blpwm_init_config_size = ARRAY_SIZE(blpwm3_init_config),
		.blpwm_enable_config = blpwm3_enable_config,
		.blpwm_enable_config_size = ARRAY_SIZE(blpwm3_enable_config),
		.blpwm_disable_config = blpwm3_disable_config,
		.blpwm_disable_config_size = ARRAY_SIZE(blpwm3_disable_config),
		.blpwm_frequency_config = blpwm3_frequency_config,
		.blpwm_frequency_config_size = ARRAY_SIZE(blpwm3_frequency_config),
		.blpwm_cycle_config = blpwm3_cycle_config,
		.blpwm_cycle_config_size = ARRAY_SIZE(blpwm3_cycle_config),
	},
};

static blpwm_ioremap_t blpwm_ioremap_list[IOREMAP_LIST_SIZE] = {};

static blpwm_ioremap_info_t blpwm_ioremap_info = {
	.current_size = 0,
	.next_index = 0,
	.ioremap_list = blpwm_ioremap_list,
};

#endif