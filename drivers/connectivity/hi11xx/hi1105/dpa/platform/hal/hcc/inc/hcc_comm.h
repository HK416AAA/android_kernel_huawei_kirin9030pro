/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Header file of hcc comm
 * Author: dpa drivers
 */

#ifndef HCC_COMM_H
#define HCC_COMM_H

#include <stdint.h>

#define HCC_LONG_PACKAGE_SIZE 1560
#define FRW_EVENT_HCC_BURST_COUNT 128

/* hcc tx transfer flow control */
#define HCC_FC_NONE 0x0 /* 对调用者不进行流控，netbuf一直缓冲在hcc队列中,这种类型的数据包不宜过多 */
#define HCC_FC_WAIT 0x1 /* 阻塞等待，如果是在中断上下文调用，该标记被自动清除,非中断上下文生效 */
#define HCC_FC_NET  0x2 /* 对于网络层的流控 */
#define HCC_FC_DROP 0x4 /* 流控采用丢包方式,流控时返回成功 */
#define HCC_FC_ALL  (HCC_FC_WAIT | HCC_FC_NET | HCC_FC_DROP)

typedef enum _hcc_action_type__ {
    HCC_ACTION_TYPE_WIFI = 0,      /* data from wifi */
    HCC_ACTION_TYPE_OAM = 1,       /* data from oam,sdt etc. */
    HCC_ACTION_TYPE_TEST = 2,      /* used for hcc transfer test */
    HCC_ACTION_TYPE_CHR = 3,       /* used for device chr exception */
    HCC_ACTION_TYPE_CUSTOMIZE = 4, /* used for device customization data transmit */
    HCC_ACTION_TYPE_BUS = 5,       /* used for hcc bus */

    HCC_ACTION_TYPE_BUTT
} hcc_action_type;

/*
 * hcc protocol header
 * |-------hcc total(64B)-----|-----------package mem--------------|
 * |hcc hdr|pad hdr|hcc extend|pad_payload|--------payload---------|
 */
#pragma pack(push, 1)
/* 6bytes */
typedef struct hcc_header {
#define HCC_SUB_TYPE_BUTT 16   /* 4 bits bound [0~15] */
    uint8_t sub_type : 4;    /* sub type to hcc type,refer to hcc_action_type */
    uint8_t main_type : 4;   /* main type to hcc type,refer to hcc_action_type */

    uint8_t seq;              /* seq num for debug */
    uint8_t pad_hdr;          /* pad_hdr only need 6 bits, the 2bits reserved,
                                       pad_hdr used to algin hcc tcm hdr(64B) */
    uint16_t more : 1;        /* for hcc aggregation */
    uint16_t option : 1;      /* reserved */
    uint16_t pad_payload : 2; /* the pad to algin the payload addr */
    uint16_t pay_len : 12;    /* the payload length,
                                        did't contain the extend hcc hdr area */
} hcc_header_t;
#pragma pack(pop)
#define HCC_HDR_TOTAL_LEN        64
#define HCC_HDR_LEN              sizeof(hcc_header_t)
#define HCC_HDR_RESERVED_MAX_LEN (HCC_HDR_TOTAL_LEN - HCC_HDR_LEN)

#endif