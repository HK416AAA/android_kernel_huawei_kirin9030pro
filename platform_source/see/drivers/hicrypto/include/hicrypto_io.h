/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: hardware crypto engine platform-independ io
 * Create: 2024/03/21
 */
#ifndef __HICRYPTO_IO_H__
#define __HICRYPTO_IO_H__
#include <linux/types.h>
#include <linux/timer.h>
#include <linux/delay.h>
#include <linux/errno.h>

#include "hicrypto_data_type.h"
#include "hicrypto_log.h"

#define pal_write_u32(data, addr) writel_relaxed(data, addr)
#define pal_read_u32(addr) readl_relaxed(addr)

#ifdef FEATURE_PAL_TRACE_ENABLE
#define pal_trace_addr_valid(addr) (PAL_TRUE)
#define pal_trace_addr(addr) (pal_get_trace() && pal_trace_addr_valid(addr))

/* write long */
static inline void __pal_write_u32(unsigned int data, uintptr_t addr, const char *func, unsigned int line)
{
	if (pal_trace_addr(addr))
		pal_error("   --TRACE_REG wl [" PAL_FMT_STR ":%u] " PAL_FMT_LLHEX " = " PAL_FMT_HEX " \n", func, line, (long long unsigned int)addr, data);
	writel_relaxed(data, addr);
}

#undef pal_write_u32
#define pal_write_u32(data, addr) __pal_write_u32((unsigned int)(data), integer(addr), __func__, __LINE__)

static inline unsigned int __pal_read_u32(uintptr_t addr, const char *func, unsigned int line)
{
	unsigned int data = readl_relaxed(addr);

	if (pal_trace_addr(addr)) {
		pal_error("   --TRACE_REG rl [" PAL_FMT_STR ":%u] " PAL_FMT_LLHEX " = " PAL_FMT_HEX " \n", func, line, (long long unsigned int)addr, data);
	}
	return data;
}

#undef pal_read_u32
#define pal_read_u32(addr) __pal_read_u32(integer(addr), __func__, __LINE__)

#endif /* end of FEATURE_PAL_TRACE_ENABLE */

/* flag is src type copy src to sysva */
int hicrypto_data_copy_from_user(void *dst, unsigned int dst_size, struct hi_base_data *src, unsigned int start,
				 unsigned int nbytes, int flag);
/* flag is dst type copy sys va to dst */
int hicrypto_data_copy_to_user(void *src, unsigned int src_size, struct hi_base_data *dst, unsigned int start,
			       unsigned int nbytes, int flag);

void  hicrypto_data_invalidate_dcache(unsigned long buffer, unsigned int size, unsigned int type);

void  hicrypto_data_flush_dcache(unsigned long buffer, unsigned int size, unsigned int type);

#endif