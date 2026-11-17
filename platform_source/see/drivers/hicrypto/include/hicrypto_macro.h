/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: hardware crypto engine general small tools
 * Create: 2023/03/07
 */
#ifndef __HICRYPTO_MACRO_H__
#define __HICRYPTO_MACRO_H__
#include <linux/types.h>

#ifndef PAGE_SIZE
#define PAGE_SIZE 4096
#endif

#ifndef one_object
#define one_object(obj) obj
#endif /* one_object */

#ifndef concatenate
#define concatenate(a, b) a##b
#endif

#ifndef PRIVATE
#define PRIVATE static
#endif /* PRIVATE */

#ifndef STUB_FUNC
#define STUB_FUNC __attribute__((weak)) /* declare for stub func */
#endif /* STUB_FUNC */

#ifndef STATIC_INLINE
#define STATIC_INLINE one_object(static __attribute__((always_inline)) inline)
#endif /* STATIC_INLINE */

#ifndef ALIGN_U32
#define ALIGN_U32 __attribute__((aligned(sizeof(unsigned int))))
#endif /* ALIGN_U32 */

#ifndef unused
#define unused(x) ((void)(x))
#endif /* unused */

/* do nothing */
#ifndef do_nothing
#define do_nothing() \
	do {         \
	} while (0)
#endif /* do_nothing */

/* array size */
#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#endif /* ARRAY_SIZE */

#define INVALID_HICRYPTO_PADDR 0xFFFFFFFFFFFFFFFFUL

/* convert to pointer type  */
#ifndef ptr
#define ptr(p) ((void *)((uintptr_t)(p)))
#endif /* ptr */
#ifndef ptr_to_type
#define ptr_to_type(ptr, type) ((type)(uintptr_t)(ptr))
#endif

#ifndef ptr_to_void
#define ptr_to_void(ptr) 		((void *)(uintptr_t)(ptr))
#endif

#ifndef ptr_add
#define ptr_add(b, o) ({				\
	uintptr_t ____b = (uintptr_t)(b);			\
	uintptr_t ____p = (uintptr_t)&(((uint8_t *)(____b))[o]);\
							\
	BUG_ON(____b > ____p);				\
	ptr_to_void(____p);					\
})
#endif

#ifndef ptr_to_ulong
#define ptr_to_ulong(ptr) ptr_to_type(ptr, unsigned long)
#endif

#ifndef PAGE_SHIFT
#define PAGE_SHIFT 12
#endif

#ifndef PAGE_MASK
#define PAGE_MASK (~((1U << PAGE_SHIFT) - 1))
#endif

#ifndef integer
#define integer(p) ((uintptr_t)(p))
#endif /* integer */

#ifndef addr_is_cross
#define addr_is_cross(pa, alen, pb, blen)                                                 \
	((((integer(pa)) > (integer(pb))) && ((integer(pa)) - (integer(pb)) < (blen))) || \
	 (((integer(pb)) > (integer(pa))) && ((integer(pb)) - (integer(pa)) < (alen))))
#endif /* addr_is_cross */

/* register attribute */
#ifndef reg_att
#define reg_att(p, type, member) (((type *)(p))->reg.member)
#endif /* reg_att */

/******************* bit operation **************************/
#ifndef BITS_PER_BYTE
#define BITS_PER_BYTE 8 /* 8 bits per bytes */
#endif /* BITS_PER_BYTE */

#ifndef bit_val
#define bit_val(x) (1U << (x))
#endif /* bit_val */

#ifndef bit_mask
#define bit_mask(x) (bit_val(x) - 1U)
#endif /* bit_mask */

/* bit set to 1 */
#ifndef bit_set_op
#define bit_set_op(pflag, bit)                   \
	do {                                     \
		uintptr_t __flag = bit_val(bit); \
		*(pflag) |= __flag;              \
	} while (0)
#endif /* bit_set_op */

/* bit clear to 0 */
#ifndef bit_cls
#define bit_cls(pflag, bit)                         \
	do {                                        \
		uintptr_t __flag = ~(bit_val(bit)); \
		*(pflag) &= __flag;                 \
	} while (0)
#endif /* bit_cls */

/* bit check */
#ifndef bit_chk
#define bit_chk(flag, bit) ((flag)&bit_val(bit))
#endif /* bit_chk */

/* align to 2~bit */
#ifndef bit_align
#define bit_align(n, bit) (((n) + bit_mask(bit)) & (~(bit_mask(bit))))
#endif /* bit_align */

/* modulo by 2~bit */
#ifndef bit_mod
#define bit_mod(n, bit) ((n) & (bit_mask(bit)))
#endif /* bit_mod */

/* modulo by 4 */
#ifndef word_mod
#define word_mod(n) bit_mod(n, 2)
#endif /* word_mod */

/* bits to bytes */
#ifndef bit2byte
#define bit2byte(bits) ((bits) >> 3)
#endif /* bit2byte */

/* bits to bytes, algin to a byte */
#ifndef bit2byte_align
#define bit2byte_align(bits) bit2byte(bit_align(bits, 3))
#endif /* bit2byte_align */

/* bits to words */
#ifndef bit2word
#define bit2word(bits) ((bits) >> (3 + 2))
#endif /* bit2word */

/* bytes to bita */
#ifndef byte2bit
#define byte2bit(bytes) ((bytes) << 3)
#endif /* byte2bit */

/* bytes to words */
#ifndef byte2word
#define byte2word(bytes) ((bytes) >> 2)
#endif /* byte2word */

/* bytes to words */
#ifndef byte2u64
#define byte2u64(bytes) ((bytes) >> 3)
#endif /* byte2word */

/* bytes to words, algin to a word */
#ifndef byte2word_align
#define byte2word_align(bytes) byte2word(bit_align(bytes, 2))
#endif /* byte2word_align */

/* bytes to words */
#ifndef word2byte
#define word2byte(words) ((words) << 2)
#endif /* word2byte */

/* set word in bytes to avoid CPU alignment */
#ifndef word_set
#define word_set(pdst, psrc)                                                            \
	do {                                                                            \
		if (bit_mod(integer(pdst), 2) == 0 && bit_mod(integer(psrc), 2) == 0) { \
			((unsigned int *)(pdst))[0] = ((unsigned int *)(psrc))[0];                        \
		} else {                                                                \
			((unsigned char *)(pdst))[0] = ((unsigned char *)(psrc))[0];                          \
			((unsigned char *)(pdst))[1] = ((unsigned char *)(psrc))[1];                          \
			((unsigned char *)(pdst))[2] = ((unsigned char *)(psrc))[2];                          \
			((unsigned char *)(pdst))[3] = ((unsigned char *)(psrc))[3];                          \
		}                                                                       \
	} while (0)
#endif /* word_set */

/* inverted word copy in bytes to avoid CPU alignment */
#ifndef word_set_inv
#define word_set_inv(pdst, psrc)                                                            \
	do {                                                                                \
		if (integer(pdst) % sizeof(unsigned int) == 0 && integer(psrc) % sizeof(unsigned int) == 0) { \
			((unsigned int *)(pdst))[0] = u32_inv(((unsigned int *)(psrc))[0]);                   \
		} else {                                                                    \
			((unsigned char *)(pdst))[0] = ((unsigned char *)(psrc))[3];                              \
			((unsigned char *)(pdst))[1] = ((unsigned char *)(psrc))[2];                              \
			((unsigned char *)(pdst))[2] = ((unsigned char *)(psrc))[1];                              \
			((unsigned char *)(pdst))[3] = ((unsigned char *)(psrc))[0];                              \
		}                                                                           \
	} while (0)
#endif /* word_set_inv */

#ifndef word_set_less
#define word_set_less(pdst, psrc, len)                                 \
	do {                                                           \
		((unsigned char *)(pdst))[0] = ((unsigned char *)(psrc))[0];                 \
		if ((len) > 1) {                                       \
			((unsigned char *)(pdst))[1] = ((unsigned char *)(psrc))[1];         \
			if ((len) > 2)                                 \
				((unsigned char *)(pdst))[2] = ((unsigned char *)(psrc))[2]; \
		}                                                      \
	} while (0)
#endif /* word_set_less */

/* data interchange (bit algorithm to reduce stack ) */
#ifndef num_switch
#define num_switch(a, b)         \
	do {                     \
		(a) = (a) ^ (b); \
		(b) = (a) ^ (b); \
		(a) = (a) ^ (b); \
	} while (0)
#endif /* num_switch */

/* least significant bit of unsigned char */
#ifndef u8_lsb
#define u8_lsb(b) ((b)&0x0F)
#endif /* u8_lsb */
/* most significant bit of unsigned char */
#ifndef u8_msb
#define u8_msb(b) (((unsigned char)(b)) >> (BITS_PER_BYTE >> 1))
#endif /* u8_msb */

/* least significant bit of u16 */
#ifndef u16_lsb
#define u16_lsb(s) ((unsigned char)(u16)(s))
#endif /* u16_lsb */
/* most significant bit of u16 */
#ifndef u16_msb
#define u16_msb(s) ((unsigned char)((u16)(s) >> BITS_PER_BYTE))
#endif /* u16_msb */

#ifndef U32_MAX
#define U32_MAX 0xFFFFFFFF
#endif /* U32_MAX */

/* least significant bit of unsigned int */
#ifndef u32_lsb
#define u32_lsb(n) ((u16)(unsigned int)(n))
#endif /* u32_lsb */
/* ost significant bit of unsigned int */
#ifndef u32_msb
#define u32_msb(n) ((u16)((unsigned int)(n) >> (BITS_PER_BYTE << 1)))
#endif /* u32_msb */

#ifndef u64_lsb
#define u64_lsb(n) ((unsigned int)(n))
#endif

#ifndef u64_msb
#define u64_msb(n) ((unsigned int)((n) >> 32))
#endif

/* make 2 unsigned char to a u16 */
#ifndef tou16
#define tou16(h_u8, l_u8) (u16)(((unsigned char)(h_u8) << BITS_PER_BYTE) | (unsigned char)(l_u8))
#endif /* tou16 */
/* make 2 u16 to a unsigned int */
#ifndef tou32
#define tou32(h_u16, l_u16) (unsigned int)(((u16)(h_u16) << 16) | (u16)(l_u16))
#endif /* tou32 */

#ifndef tou64
#define tou64(h_u32, l_u32) (unsigned long long)(((unsigned long long)(h_u32) << 32) | (unsigned int)(l_u32))
#endif /* tou64 */

/* invert u16 by byte */
#ifndef u16_inv
#define u16_inv(v) tou16(u16_lsb(v), u16_msb(v))
#endif /* u16_inv */

/* invert unsigned int by byte */
#ifndef u32_inv
#define u32_inv(v) (((v) == 0) ? 0 : (((unsigned int)u16_inv(u32_lsb(v)) << 16) | u16_inv(u32_msb(v))))
#endif /* u32_inv */

#ifndef u64_inv
#define u64_inv(v) (((v) == 0) ? 0 : (((unsigned long long)u32_inv(u64_lsb(v)) << 32) | u32_inv(u64_msb(v))))
#endif /* u64_inv */

#ifndef round_up
#define round_up(num, base) (((base) == 0) ? (num) : ((((num) + (base)-1) / (base)) * (base)))
#endif /* round_up */

/******************* character operation **************************/
#define BASE10 10
#define BASE16 16

/* check if it is digit */
#ifndef is_digit
#define is_digit(c) (('0' <= (c)) && ((c) <= '9'))
#endif /* is_digit */

#ifndef digit2dec
#define digit2dec(c) ((c) - '0')
#endif /* digit2dec */

/* check if it is lower case */
#ifndef is_lower
#define is_lower(c) (('a' <= (c)) && ((c) <= 'z'))
#endif /* is_lower */

/* check if it is upper case  */
#ifndef is_upper
#define is_upper(c) (((c) >= 'A') && ((c) <= 'Z'))
#endif /* is_upper */

/* covert to lower case */
#ifndef to_lower
#define to_lower(c) (char)(is_upper(c) ? (((c) - 'A') + 'a') : (c))
#endif /* to_lower */

/* covert to upper case */
#ifndef to_upper
#define to_upper(c) (char)(is_lower(c) ? (((c) - 'a') + 'A') : (c))
#endif /* to_upper */

/* covert to lower hexadecimal character */
#ifndef tohexl
#define tohexl(c) (char)(((c) < BASE10) ? ((c) + '0') : (((c)-BASE10) + 'a'))
#endif /* tohexl */

/* covert to upper hexadecimal character */
#ifndef tohexu
#define tohexu(c) (char)(((c) < BASE10) ? ((c) + '0') : (((c)-BASE10) + 'A'))
#endif /* tohexu */

/* check if character is valid */
#ifndef is_valid_char
#define is_valid_char(c) (((c) >= 0x20) && ((c) <= 0x7E))
#endif /* is_valid_char */

/* check if is hexadecimal character */
#ifndef ishex
#define ishex(c) (is_digit(c) || ((((c) >= 'A') && ((c) <= 'F')) || (('a' <= (c)) && ((c) <= 'f'))))
#endif /* ishex */

/* covert hexadecimal character to decimal integer */
#ifndef hex2byte
#define hex2byte(c) (is_digit(c) ? digit2dec(c) : (10 + (is_lower(c) ? ((c) - 'a') : ((c) - 'A'))))
#endif /* hex2byte */

#ifndef align_kerel_mask
#define align_kerel_mask(x, mask) (((x) + (mask)) & ~(mask))
#endif
#ifndef align_kerel
#define align_kerel(x, a) align_kerel_mask(x, (typeof(x))(a)-1)
#endif

#ifndef ALIGN_UP
#define ALIGN_UP(x, align) (((x) + ((align)-1)) & ~((align)-1))
#endif
#ifndef ALIGN_DOWN
#define ALIGN_DOWN(x, align) ((x) & ~((align)-1))
#endif

#ifndef PAGE_SHIFT
#define PAGE_SHIFT              12
#endif

#ifndef PAGE_SIZE
#define PAGE_SIZE               (1 << PAGE_SHIFT)
#endif

#ifndef PAGE_MASK
#define PAGE_MASK               (~(PAGE_SIZE-1)) /* 0xFFFFF000 */
#endif

#ifndef PAGE_MASK_64BIT
#define PAGE_MASK_64BIT         0xFFFFFFF000
#endif

#ifndef PAGE_OFFSET_MASK
#define PAGE_OFFSET_MASK        (PAGE_SIZE-1) /* 0xFFF */
#endif

#ifndef PAGE_ALIGN_UP
#define PAGE_ALIGN_UP(x)        ALIGN_UP(x, PAGE_SIZE)
#endif

#ifndef PAGE_ALIGN_DOWN
#define PAGE_ALIGN_DOWN(x)      ALIGN_DOWN(x, PAGE_SIZE)
#endif

#ifndef IS_PAGE_ALIGNED
#define IS_PAGE_ALIGNED(addr)   (((addr) & PAGE_OFFSET_MASK) == 0)
#endif

#ifndef htobe32
#define htobe32(value)  ((((value) & 0x000000FF) << 24) |\
			(((value)  & 0x0000FF00) << 8)  |\
			(((value)  & 0x00FF0000) >> 8)  |\
			(((value)  & 0xFF000000) >> 24))
#endif
#endif /* end of __HICRYPTO_MACRO_H__ */
