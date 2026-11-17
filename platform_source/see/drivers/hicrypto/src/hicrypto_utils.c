/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: Hisilicon hardware crypto engine debug code.
 * Create : 2023/08/31
 */
#include <linux/uaccess.h>
#include <asm/cacheflush.h>
#include <asm/barrier.h>
#include <asm/memory.h>
#include <securec.h>

#include "hicrypto_data_type.h"
#include "hicrypto_errno.h"
#include "hicrypto_log.h"
#include "hicrypto_utils.h"
#include "hicrypto_alg_def.h"
#include "hicrypto_io.h"
#include "hicrypto_macro.h"

#define BSP_THIS_MODULE BSP_MODULE_SCE

#if defined(CONFIG_CRYPTO_HICRYPTO_V2_DEBUG) && CONFIG_CRYPTO_HICRYPTO_V2_DEBUG
unsigned int g_pal_log_trace = 1;

/**
 * @brief      : set trace control
 * @param[in]  : enable PAL_PAL_TRUE - disable or OTHER - enable
 */
void pal_set_trace(unsigned int enable)
{
	g_pal_log_trace = enable;
}

/**
 * @brief      : trace enable or not
 */
unsigned int pal_get_trace(void)
{
	return g_pal_log_trace;
}
/**
 * @brief      : dump register or memory data
 * @param[in]  : addr   mem/reg address
 * @param[in]  : bytes  data length
 * @param[in]  : is_reg PAL_TRUE -- register format, PAL_FALSE -- memory format
 */
void pal_dump_log(unsigned char *addr, unsigned int bytes, unsigned int is_reg)
{
	unsigned int value = 0;
	unsigned int len = 0;
	unsigned char *data = addr;
	char tmp_buf[] = { ' ', '\0', '\0', '\0' };

	while (bytes > len) {
		if ((len & 0xF) == 0) {
			if (is_reg == PAL_TRUE)
				pal_printf("\n\t[" PAL_FMT_PTR "]:", addr);
			else
				pal_printf("\n\t[%d]:", len);
		}
		if (addr == data && ((bytes - len) >= sizeof(unsigned int))) {
			data = (unsigned char *)&value;
			if (is_reg != PAL_TRUE) {
				word_set(data, addr);
			} else {
				value = pal_read_u32(integer(addr));
				value = u32_inv(value);
				pal_printf(KERN_CONT "0x");
			}
		}
		tmp_buf[2] = u8_lsb(*data);	 /* 2 is low 4bit  */
		tmp_buf[2] = tohexu(tmp_buf[2]); /* 2 is low 4bit */
		tmp_buf[1] = u8_msb(*data);	 /* unsigned char high 4bit */
		tmp_buf[1] = tohexu(tmp_buf[1]); /* unsigned char high 4bit */

		if (is_reg != PAL_TRUE) /* 4bytes a group */
			pal_printf(KERN_CONT PAL_FMT_STR, tmp_buf);
		else
			pal_printf(KERN_CONT PAL_FMT_STR, tmp_buf + 1);
		data++;
		addr++;
		len++;
		if ((unsigned char *)(&value + 1) == data) {
			data = addr;
			pal_printf(KERN_CONT " ");
		}
	}
	pal_printf("\n");
}

#endif /* FEATURE_DFT_ENABLE */

unsigned int hicrypto_data_get_page_size(void)
{
	return 4096;
}

/* copy small data to buf */
int hicrypto_data_copy_from_user(void *dst, unsigned int dst_size, struct hi_base_data *src, unsigned int start,
				 unsigned int nbytes, int flag)
{
	unsigned char *data = NULL;
	int ret;
	errno_t libc_ret;

	if (pal_check(dst == NULL || src == NULL || nbytes == 0 || src->buffer == NULL))
		return err_api(ERRCODE_NULL);

	if (pal_check((start > src->size) || ((src->size - start) < nbytes) || dst_size < nbytes)) {
		return err_api(ERRCODE_PARAMS);
	}

	if (flag == ADDR_TYPE_KERNEL_VA) {
		/* sysva  to sysva */
		libc_ret = memcpy_s(dst, dst_size, ptr_add(ptr_to_ulong(src->buffer), start), nbytes);
		if (pal_check(libc_ret != EOK))
			return err_api(ERRCODE_MEMORY);
		return BSP_RET_OK;
	}

	if (flag == ADDR_TYPE_USER_VA) {
		/* appva  to sysva */
		ret = copy_from_user(dst, ptr_add(ptr_to_ulong(src->buffer), start), nbytes);
		if (pal_check(ret != 0)) {
			pal_error("copy_from_user failed, ret=%d\n", ret);
			return err_api(ERRCODE_MEMORY);
		}
		return BSP_RET_OK;
	}

	return err_api(ERRCODE_PARAMS);
}

int hicrypto_data_copy_to_user(void *src, unsigned int src_size, struct hi_base_data *dst, unsigned int start,
			       unsigned int nbytes, int flag)
{
	int ret;
	errno_t libc_ret;

	if (pal_check(dst == NULL || src == NULL || nbytes == 0 || dst->buffer == NULL))
		return err_api(ERRCODE_NULL);
	if (pal_check((start > src_size) || ((src_size - start) < nbytes) || nbytes > dst->size))
		return err_api(ERRCODE_PARAMS);

	if (flag == ADDR_TYPE_KERNEL_VA) {
		/* sysva  to sysva */
		libc_ret = memcpy_s(dst->buffer, dst->size, ptr_add(ptr_to_ulong(src), start), nbytes);
		if (pal_check(libc_ret != EOK))
			return err_api(ERRCODE_MEMORY);
		return BSP_RET_OK;
	}

	if (flag == ADDR_TYPE_USER_VA) {
		/* copy_to_user sysva to va */
		ret = copy_to_user(dst->buffer, ptr_add(ptr_to_ulong(src), start), nbytes);
		if (pal_check(ret != 0)) {
			pal_error("copy_to_user failed, ret=%d\n", ret);
			return err_api(ERRCODE_PARAMS);
		}
		return BSP_RET_OK;
	}
	return err_api(ERRCODE_PARAMS);
}

void hicrypto_data_flush_dcache(unsigned long buffer, unsigned int size, unsigned int type)
{
#ifndef CONFIG_CRYPTO_HICRYPTO_V2_SYS_CACHE
	unused(type);
	if (type == ADDR_TYPE_KERNEL_VA)
		__flush_dcache_area(buffer, size);
	if (type == ADDR_TYPE_USER_VA)
		__flush_cache_user_range(buffer, ptr_add(buffer, size));
#else
	unused(buffer);
	unused(size);
	unused(type);
#endif
}

void hicrypto_data_invalidate_dcache(unsigned long buffer, unsigned int size, unsigned int type)
{
#ifndef CONFIG_CRYPTO_HICRYPTO_V2_SYS_CACHE
	if (type == ADDR_TYPE_KERNEL_VA)
		__inval_dcache_area(buffer, size);
	if (type == ADDR_TYPE_USER_VA)
		__flush_cache_user_range(buffer, ptr_add(buffer, size));
	if (type == ADDR_TYPE_PA)
		__flush_cache_range_by_pa(buffer, ptr_add(buffer, size), __DCACHE_INVAL_RANGE);
#else
	unused(buffer);
	unused(size);
	unused(type);
#endif
}