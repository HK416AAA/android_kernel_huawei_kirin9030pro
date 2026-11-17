/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: hardware crypto engine alg common def
 * Create: 2023/03/07
 */
#ifndef __HICRYPTO_DATA_TYPE_H__
#define __HICRYPTO_DATA_TYPE_H__

#define hi_gen_ptr_base(base, addr, num, flag) do {        \
	(base)->buffer = (unsigned char *)(uintptr_t)(addr);                            \
	(base)->size = (num);                               \
	(base)->type = (flag);                              \
} while (0)

#define hi_gen_base(base, addr, num, flag) do {           \
	(base).buffer =  (unsigned char *)(uintptr_t)(addr);                            \
	(base).size = (num);                               \
	(base).type = (flag);                              \
} while (0)

#define hi_gen_ptr_data(base, buf, num, flag) do {        \
	(base)->addr.cpu_addr = (unsigned char *)(uintptr_t)(buf);                            \
	(base)->len = (num);                               \
	(base)->type = (flag);                              \
} while (0)

#define hi_gen_data(base, buf, num, flag) do {           \
	(base).addr.cpu_addr = (unsigned char *)(uintptr_t)(buf);                              \
	(base).len = (num);                               \
	(base).type = (flag);                              \
} while (0)

struct hi_base_data {
	unsigned int type; /* addr_type */
	unsigned int size;
	unsigned char *buffer;
};

typedef union _pal_addr_u {
	unsigned char *cpu_addr;
	unsigned long long master_addr;
} pal_addr_t;

enum addr_type {
	ADDR_TYPE_KERNEL_VA = 0,
	ADDR_TYPE_USER_VA = 1,
	ADDR_TYPE_PA = 2,
};

struct hi_data_addr {
	unsigned int type;
	unsigned int len;
	pal_addr_t addr;
};

struct hi_aead_data {
	struct hi_base_data *payload;
	unsigned int payload_num;
	struct hi_base_data *aad;
	struct hi_base_data *tag;
};

#define HISI_BASE_DATA_SIZE 2
 
struct hi_data_addrs {
	struct hi_data_addr data[HISI_BASE_DATA_SIZE];
	unsigned int data_num;
	unsigned int data_len;
};

#define hi_gen_aead_data(base, pl, pl_num, paad, ptag) do {           \
	(base).payload = (struct hi_base_data *)(uintptr_t)(pl);      \
	(base).payload_num = (pl_num);                                  \
	(base).aad = (struct hi_base_data *)(uintptr_t)(paad);         \
	(base).tag = (struct hi_base_data *)(uintptr_t)(ptag);         \
} while (0)

#endif