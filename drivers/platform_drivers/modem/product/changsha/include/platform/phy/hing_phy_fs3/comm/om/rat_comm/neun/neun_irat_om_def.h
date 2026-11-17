

/*
 * 1 其他头文件包含
 */
#ifndef __NEUN_IRAT_OM_DEF_H__
#define __NEUN_IRAT_OM_DEF_H__

#include "uphy_typedef.h"
#include "uphy_om_interface.h"
#include "neun_basedef_enum.h"
#include "ul1m_irat_interface.h"

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
 * 枚举说明: IRAT INT消息序号
 */
enum NEUN_IRAT_IntMsgNum {
    NEUN_IRAT_MSG_INT0, // 预调度请求 N/L主模 -> 从模
    NEUN_IRAT_MSG_INT1, // 从模进沟   N/L从模 -> 从模
    NEUN_IRAT_MSG_INT2, // 正常出沟   N/L从模 -> 从模
    NEUN_IRAT_MSG_INT3, // 频点测量完成 L从模 -> 主模
    NEUN_IRAT_MSG_INT4, // 主模强停从模 N/L主模 -> 从模
    NEUN_IRAT_MSG_INT5, // 通知从模测量上报 N/L主模 -> 从模
    NEUN_IRAT_MSG_INT6, // 频点测量完成 N从模 -> L主模
    NEUN_IRAT_MSG_INT4_CNF, // 从模强停完成 N/L从模 -> 主模
    NEUN_IRAT_MSG_INT_BUTT
};
typedef uint8_t NEUN_IRAT_IntMsgNumUint8;

/*
 * 4 消息头定义
 */
/*
 * 5 消息定义
 */
/*
 * 6 STRUCT定义
 */
/*
 * 结构说明: 从模测量完成上报
 */
typedef struct {
    NEUN_MODEM_IdUint08       modemId;
    uint8_t                   rsv;
    UL1M_IRAT_MsgTypeIdUint16 msgId;
} NEUN_IRAT_FreqMeasCompleteInfo;


/*
 * 结构说明: 从模定时折算信息上报
 */
typedef struct {
    NEUN_MODEM_IdUint08       modemId;
    uint8_t                   rsv[3];
    UL1M_IRAT_LockTiming      currentTiming;
    uint32_t                  masterDiff;
    uint32_t                  slaveDiff;
    uint32_t                  oldRxDelay;
    uint32_t                  newRxDelay;
    uint32_t                  deltaTs;
    uint32_t                  tsOffset;
    uint32_t                  sfnOffset;
    uint32_t                  oldAheadTime;
    uint32_t                  newAheadTime;
} NEUN_IRAT_TimDiffInfo;

/*
 * 结构说明: INT消息OM上报
 */
typedef struct {
    NEUN_MODEM_IdUint08       modemId;
    NEUN_IRAT_IntMsgNumUint8  intNum;
    UL1M_IRAT_RatTypeIdUint8  senderMode;
    UL1M_IRAT_RatTypeIdUint8  recverMode;
    UL1M_IRAT_ReqTypeUint8    reqType;
    uint8_t                   rev[UPHY_NUM3];
} NEUN_IRAT_IntMsgInfo;

/*
 * 结构说明: 主模发送预调度消息OM上报
 */
typedef struct {
    NEUN_IRAT_IntMsgInfo       intMsgInfo;
    UL1M_IRAT_PreSchedInfoStru preSchedInfo;
} NEUN_IRAT_OmPreSchedMsg;

/*
 * 结构说明: 主模发送仲裁预调度消息OM上报
 */
typedef struct {
    NEUN_IRAT_IntMsgInfo       intMsgInfo;
    UL1M_IRAT_ArbPreSchedMsg   arbPreSchedInfo;
} NEUN_IRAT_OmArbPreSchedMsg;
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

