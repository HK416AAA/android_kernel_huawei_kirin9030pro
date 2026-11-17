/*
 * Copyright (c) 2023-2024 Huawei Device Co., Ltd.
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2024. All rights reserved.
 *
 */

#ifndef LITEHIDE_SYMBOLS_H
#define LITEHIDE_SYMBOLS_H

#ifdef CONFIG_HUAWEI_HIDESYMS
extern bool is_hide_symbols(const char *symbol);
#else
static inline bool is_hide_symbols(const char *symbol)
{
	return false;
}
#endif
#endif
