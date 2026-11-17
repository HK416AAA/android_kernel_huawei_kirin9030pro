

/*
 * 1 其他头文件包含
 */
#ifndef __NEUN_DSDS_OM_DEF_H__
#define __NEUN_DSDS_OM_DEF_H__

#include "uphy_typedef.h"
#include "uphy_om_interface.h"
#include "neun_basedef_enum.h"
#include "neun_basedef_struct.h"
#include "neun_dsds_interface.h"

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
enum NEUN_DSDS_OmReq {
    NEUN_DSDS_OM_REQ_START = NPHY_OM_REQ_ID(NPHY_MODULE_ID_DSDS, 0x00),
    NEUN_DSDS_OM_REQ = NEUN_DSDS_OM_REQ_START, // 0x3602B000
    NEUN_ULDSDS_OM_EN, // 0x3602B001
    NEUN_DSDS_OM_REQ_BUTT,
};
typedef uint32_t NEUN_DSDS_OmReqUint32;

enum NEUN_DSDS_OmTrigSrc {
    NEUN_DSDS_OM_TRIG_SRC_NONE          = 0x00,
    NEUN_DSDS_OM_TRIG_SRC_APPLY_REQ     = 0x01,
    NEUN_DSDS_OM_TRIG_SRC_ASSIGN_IND    = 0x02,
    NEUN_DSDS_OM_TRIG_SRC_PREEMPT_IND   = 0x04,
    NEUN_DSDS_OM_TRIG_SRC_RESUME_IND    = 0x08,
    NEUN_DSDS_OM_TRIG_SRC_APPLY_FAIL    = 0x10,
    NEUN_DSDS_OM_TRIG_SRC_TASK_REL      = 0x20,
    NEUN_DSDS_OM_TRIG_SRC_TIMER_EXPIRY  = 0x40,
    NEUN_DSDS_OM_TRIG_SRC_PREEMPT_ACK   = 0x80,
    NEUN_DSDS_OM_TRIG_SRC_SCHED_STATE   = 0x100,
    NEUN_DSDS_OM_TRIG_SRC_RF_STATE      = 0x200,
    NEUN_DSDS_OM_TRIG_SRC_ASSIGN_FAIL   = 0x400,
    NEUN_DSDS_OM_TRIG_SRC_RECYCLE       = 0x800,
    NEUN_DSDS_OM_TRIG_SRC_GRANT_STATE   = 0x1000,
    NEUN_DSDS_OM_TRIG_SRC_RRC_SUSPEND   = 0x2000,
    NEUN_DSDS_OM_TRIG_SRC_RRC_RESUME    = 0x4000,
    NEUN_DSDS_OM_TRIG_SRC_BUTT          = 0x8000,
};
typedef uint16_t NEUN_DSDS_OmTrigSrcUint16;

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
    NEUN_DSDS_OmTrigSrcUint16       omTrigSrc;
    NEUN_DSDS_SchedStateUint08      lastDsdsState;
    NEUN_DSDS_RfStateUint08         lastRfState;

    NEUN_CHANNEL_TypeUint08         lastChannelId;
    NEUN_DSDS_BoolUint08            lastNeedLogin;
    NEUN_DSDS_BoolUint08            lastNeedLogOut;
    NEUN_PROC_GrantStateUint08      grantState;
} NEUN_DSDS_OmRecordInfo;

typedef struct {
    NEUN_PROC_ModeUint08             mode;
    NEUN_MODEM_IdUint08              modemIndex;
    DSDS_RCM_NeunTaskIdUint08        currTaskId;
    NEUN_CHANNEL_TypeUint08          channelId;
    NEUN_DSDS_PreemptAckStateUint08  preemptAckState;
    NEUN_DSDS_BoolUint08             isNeedLogin;
    NEUN_DSDS_BoolUint08             isNeedLogOut;
    uint8_t                          rsv;
    DSDS_NEUN_Time                   omNeunTime;

    uint32_t                         loginBlackBall;
    uint32_t                         measExistVote;
    uint32_t                         connExistVote;
    NEUN_DSDS_SuspendInfo            suspendInfo;
    NEUN_DSDS_32KTimeBase            baseTime;

    uint32_t                         curr32kTime;
    uint32_t                         taskRelBitmap;
    uint32_t                         taskValBitmap;
    uint32_t                         rfOnBitmap;
} NEUN_DSDS_OmReportComm;

typedef struct {
    NEUN_DSDS_OmReportComm           commInfo;
    NEUN_DSDS_OmRecordInfo           specInfo;
    NEUN_DSDS_TaskContext            taskInfo;
} NEUN_DSDS_OmRptTaskStatus;

typedef struct {
#if (NEUN_FEATURE_DSDS_SRS_SWITCH == UPHY_ON)
    NEUN_DSDS_SrsContext             dsdsSrsInfo;
#endif
    uint8_t                          srsSub3gSub6gFlag;
    uint8_t                          intraBand;
    uint16_t                         rsv;
} NEUN_DSDS_OmRptSrsInfo;

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

