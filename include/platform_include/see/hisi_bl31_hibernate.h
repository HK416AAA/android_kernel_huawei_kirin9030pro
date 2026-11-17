/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: bl31_hibernate header file
 * Create : 2020/03/06
 */

#ifndef __HISI_BL31_HIBERNATE_H__
#define __HISI_BL31_HIBERNATE_H__

#define MAX_HIBERNATE_BLOCK         128
/* 32bytes encrypted key & 16bytes tag & 12bytes encrypted iv */
#define HIBERNATE_CTX_INFO_SIZE     60
#define PM_EVENT_FREEZE             0x0001
#define PM_EVENT_QUIESCE            0x0008
#define PM_EVENT_THAW               0x0020
#define PM_EVENT_RESTORE            0x0040
#define PM_EVENT_RECOVER            0x0080

struct hibernate_meminfo_t {
	/* pyhs addr of kernel and bl31 shamre memory */
	phys_addr_t paddr;
	/* addr size of kernel and bl31 shamre memory */
	u64 addr_size;
	/* virt addr of kernel and bl31 shamre memory */
	void *smem_vaddr;
	/* virt addr of kernel memory for kernel management */
	void *kmem_vaddr;
};

struct hibernate_meminfo_v2 {
	/* virt addr of kernel and bl31 shamre memory */
	void *smem_vaddr;
	/* number of blocks */
	int blocks_num;
	/* size of each block */
	u64 blocks_size[MAX_HIBERNATE_BLOCK];
	/* virt addr of kernel memory for kernel management */
	void *kmem_vaddrs[MAX_HIBERNATE_BLOCK];
	void *hib_ctx_info;
	u32 hib_ctx_info_magic;
};

#ifdef CONFIG_BL31_HIBERNATE_V2
int bl31_hibernate_freeze_v2(int event);
int bl31_hibernate_restore_v2(int event);
#else
static inline int bl31_hibernate_freeze_v2(void) { return 0; }
static inline int bl31_hibernate_restore_v2(void) { return 0; }
#endif

#ifdef CONFIG_HISI_BL31_HIBERNATE
int bl31_hibernate_freeze(void);
int bl31_hibernate_restore(void);
struct hibernate_meminfo_t get_bl31_hibernate_mem_info(void);
int bl31_hibernate_store_k(void);
int bl31_hibernate_clean_k(void);
int bl31_hibernate_get_k(void);
#else
static inline int bl31_hibernate_freeze(void) { return 0; }
static inline int bl31_hibernate_restore(void) { return 0; }
static inline struct hibernate_meminfo_t get_bl31_hibernate_mem_info(void) {
	struct hibernate_meminfo_t s = {0, 0, NULL, NULL};
	return s;
}
static inline int bl31_hibernate_store_k(void) { return 0; }
static inline int bl31_hibernate_clean_k(void) { return 0; }
static inline int bl31_hibernate_get_k(void) { return 0; }
#endif

#endif /* __HISI_BL31_HIBERNATE_H__ */
