

#ifndef DPE_FRW_H
#define DPE_FRW_H

/* 其他头文件包含 */
#include "oal_ext_if.h"
#include "securec.h"
#include "dpe_frw_if.h"
/*
 * 事件表的最大个数
 * 一种类型的事件对应两个表项，所以事件表的大小为事件类型的2倍
 */
#define FRW_EVENT_TABLE_MAX_ITEMS (FRW_EVENT_TYPE_BUTT * 2)

extern frw_event_table_item_stru g_ast_event_table[FRW_EVENT_TABLE_MAX_ITEMS];

/* 申明事件转发表注册接口 */
uint32_t hmac_dev_rx_process_data(oal_netbuf_stru *netbuf);
uint32_t dpe_wlan_xmit_from_wlan(oal_netbuf_stru *netbuf);
#endif /* end of frw_event_main.h */
