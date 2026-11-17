/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: implement the platform interface for boot fail
 * Author: qidechun
 * Create: 2019-03-05
 */

#ifndef ADAPTER_HONGHU_H
#define ADAPTER_HONGHU_H

/* ---- includes ---- */
#include <linux/io.h>
#include <hwbootfail/core/adapter.h>

/* ---- c++ support ---- */
#ifdef __cplusplus
extern "C" {
#endif

/* ---- export macroes ---- */
/* ---- export prototypes ---- */
/*---- export function prototypes ----*/
int honghu_adapter_init(struct adapter *adp);
void *bf_map(phys_addr_t addr, size_t size);
void bf_unmap(const void *addr);

/* ---- c++ support ---- */
#ifdef __cplusplus
}
#endif
#endif
