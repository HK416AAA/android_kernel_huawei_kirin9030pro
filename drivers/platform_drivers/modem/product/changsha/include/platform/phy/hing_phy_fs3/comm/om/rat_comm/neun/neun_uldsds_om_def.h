


/*
 * 1 其他头文件包含
 */
#ifndef __NEUN_ULDSDS_OM_DEF_H__
#define __NEUN_ULDSDS_OM_DEF_H__

#include "uphy_typedef.h"
#include "uphy_om_interface.h"
#include "neun_feature.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(push, 4)

/*
 * 2 宏定义
 */
/*
 * 3 枚举定义
 */

/*
 * 枚举说明: uldsds om上报Id列表，复用DSDS的模块Id，范围[0x20-0x30]
 */
enum NEUN_ULDSDS_OmRptMsgId {
    NEUN_ULDSDS_RPT_MSGID_START  = LPHY_OM_L1MSG_ID(LPHY_MODULE_ID_DSDS, 0x50), // value = 0x3039a050
    NEUN_ULDSDS_RPT_SCHED_PARA   = NEUN_ULDSDS_RPT_MSGID_START,
    NEUN_ULDSDS_RPT_EVENT_REQ,
    NEUN_ULDSDS_RPT_EVENT_REQ_PARA,
    NEUN_ULDSDS_RPT_L1U_SCHEDULE,
    NEUN_ULDSDS_L1CL1U_STATUS_NTF,
    NEUN_ULDSDS_NVLOAD_COMPLETE,
    NEUN_ULDSDS_VALID_RXANT_IND,
    NEUN_ULDSDS_TX_INTERUPT,
    NEUN_ULDSDS_RPT_MSGID_BUTT   = LPHY_OM_L1MSG_ID(LPHY_MODULE_ID_DSDS, 0x80)
};
typedef uint32_t NEUN_ULDSDS_OmRptMsgIdUint32;

/*
 * 4 消息头定义
 */
/*
 * 5 消息定义
 */
/*
 * 6 STRUCT定义
 */

typedef struct {
    uint8_t        rxHoldBitmap;
    uint8_t        rxConflictRslt;
    uint8_t        clearBufferFlag;
    uint8_t        rxHoldNoGapNrFlag;
    uint32_t       prevSlotNum;
    uint8_t        rxHoldAntMap[NEUN_CAPACITY_PROC_MAX_DL_CARRIER_NUM];
    uint8_t        rsv[UPHY_STRUCT_FILL_LEN(sizeof(uint8_t), sizeof(uint8_t) * NEUN_CAPACITY_PROC_MAX_DL_CARRIER_NUM)];
} NEUN_ULDSDS_OmTxInterrupt;

typedef struct {
    uint32_t     currSchedBmp;    // 当前slot调度之前的bitmap值
    uint32_t     afterSchedBmp;   // 当前slot调度之后的bitmap值
    uint32_t     currWaitExpBmp;
    uint32_t     afterWaitExpBmp;
} NEUN_ULDSDS_OmSchedPara;

/*
 * 7 UNION定义
 */
/*
 * 8 OTHERS定义
 */
/*
 * 9 全局变量声明
 */
/*
 * 10 函数声明
 */
#pragma pack(pop)

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif

