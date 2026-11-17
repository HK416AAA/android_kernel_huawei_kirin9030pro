/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2018-2019. All rights reserved.
 */


#ifndef COMPILE_CONFIG_H
#define COMPILE_CONFIG_H

#if defined(DPA_MODE) && defined(BUILD_STACK)
#include "bsp_memory.h"
#endif

#ifndef NSTACK_STATIC
#ifndef NSTACK_STATIC_CHECK
#define NSTACK_STATIC static
#else
#define NSTACK_STATIC
#endif
#endif

/* indicate high frequency text section */
#ifndef HF_TEXT_SEC
#if defined(DPA_MODE) && defined(BUILD_STACK)
#define HF_TEXT_SEC __sys_pl1_text
#else
#define HF_TEXT_SEC
#endif
#endif

/* indicate high frequency data section */
#ifndef HF_DATA_SEC
#if defined(DPA_MODE) && defined(BUILD_STACK)
#define HF_DATA_SEC __sys_pl1_data
#else
#define HF_DATA_SEC
#endif
#endif

/* indicate high frequency bss section, will initialize to 0 */
#ifndef HF_BSS_SEC
#if defined(DPA_MODE) && defined(BUILD_STACK)
#define HF_BSS_SEC __sys_pl1_bss
#else
#define HF_BSS_SEC
#endif
#endif

/* indicate low frequency text section */
#ifndef LF_TEXT_SEC
#if defined(DPA_MODE) && defined(BUILD_STACK)
#define LF_TEXT_SEC
#else
#define LF_TEXT_SEC
#endif
#endif

/* indicate low frequency data section */
#ifndef LF_DATA_SEC
#if defined(DPA_MODE) && defined(BUILD_STACK)
#define LF_DATA_SEC
#else
#define LF_DATA_SEC
#endif
#endif

/* indicate low frequency bss section, will initialize to 0 */
#ifndef LF_BSS_SEC
#if defined(DPA_MODE) && defined(BUILD_STACK)
#define LF_BSS_SEC
#else
#define LF_BSS_SEC
#endif
#endif

#endif /* compile_config.h */
