/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: hardware crypto engine platform-independ log
 * Create: 2023/03/07
 */
#ifndef __HICRYPTO_LOG_H__
#define __HICRYPTO_LOG_H__
#include <linux/printk.h>
#include <linux/iopoll.h>

#ifndef PAL_FMT_STR
#define PAL_FMT_STR "%s"
#endif /* PAL_FMT_STR */

#ifndef PAL_FMT_HEX
#define PAL_FMT_HEX "0x%x"
#endif /* PAL_FMT_HEX */

#ifndef PAL_FMT_LLHEX
#define PAL_FMT_LLHEX "0x%llx"
#endif /* PAL_FMT_LLHEX */

#ifndef PAL_FMT_PTR
#define PAL_FMT_PTR "%p"
#endif /* PAL_FMT_PTR */

#define PAL_FALSE 0
#define PAL_TRUE 1

#define pal_error(fmt, ...) pr_err("[error][%s:%u] " fmt, __func__, __LINE__, ##__VA_ARGS__)
#define pal_warn(fmt, ...) pr_warn("[warn][%s:%u] " fmt, __func__, __LINE__, ##__VA_ARGS__)
#define pal_info(fmt, ...) pr_info("[info][%s:%u] " fmt, __func__, __LINE__, ##__VA_ARGS__)
#define pal_debug(fmt, ...) pr_debug("[debug][%s:%u] " fmt, __func__, __LINE__, ##__VA_ARGS__)
#define pal_printf(fmt, ...) pr_info(fmt, ##__VA_ARGS__)

static inline unsigned int pal_check_log(unsigned int matched, const char *pfunc, unsigned int line)
{
	if (matched)
		pal_error("[%s:%u]\n", pfunc, line);
	return matched;
}

#define log_nothing() \
	do {          \
	} while (0)

#if !defined(CONFIG_CRYPTO_HICRYPTO_V2_DEBUG) || !CONFIG_CRYPTO_HICRYPTO_V2_DEBUG

#define pal_check(express) (express)
#define pal_get_trace() PAL_TRUE
#define pal_dump(desc, p, size, is_reg) log_nothing()
#else
/* unlikely(express) in perf test */
unsigned int pal_check_log(unsigned int matched, const char *pfunc, unsigned int line);
#define pal_check(express) (pal_check_log((express) ? PAL_TRUE : PAL_FALSE, __func__, __LINE__) != PAL_FALSE)

/**
 * @brief      : trace enable or not
 * @return     : ::unsigned int
 */
unsigned int pal_get_trace(void);

/**
 * @brief      : set trace control
 * @param[in]  : enable PAL_TRUE - disable or OTHER - enable
 * @return     : void
 */
void pal_set_trace(unsigned int enable);

void pal_dump_log(unsigned char *addr, unsigned int bytes, unsigned int is_reg);

#define pal_dump(desc, p, size, is_reg)                                                                             \
	do {                                                                                                        \
		pal_printf("[" PAL_FMT_STR ":%u]: " desc " > addr = " PAL_FMT_PTR ", len = %u", __func__, __LINE__, \
			   ptr(p), size);                                                                           \
		pal_dump_log((unsigned char *)(uintptr_t)(p), (unsigned int)(size), is_reg);                        \
		pal_printf("[" PAL_FMT_STR ":%u]: -------------end--------\n\n", __func__, __LINE__);               \
	} while (0)

#endif /* CONFIG_CRYPTO_HICRYPTO_V2_DEBUG */

/* data output by bytes */
#define pal_rawdata(desc, mem, memlen) pal_dump(desc, mem, memlen, PAL_FALSE)

/* data(register) output by words */
#define pal_regdump(desc, mem, memlen) pal_dump(desc, mem, memlen, PAL_TRUE)
#endif /* __HICRYPTO_LOG_H__ */
