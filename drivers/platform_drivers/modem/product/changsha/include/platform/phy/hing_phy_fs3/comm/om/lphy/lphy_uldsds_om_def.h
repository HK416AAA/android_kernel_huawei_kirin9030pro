

/*
 * 1 其他头文件包含
 */
#ifndef LPHY_ULDSDS_OM_DEF_H
#define LPHY_ULDSDS_OM_DEF_H

#include "uphy_typedef.h"
#include "uphy_om_interface.h"
#include "uphy_prm_fess.h"
#include "lphy_feature.h"

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
 * 4 消息头定义
 */
/*
 * 5 消息定义
 */
/*
 * 6 STRUCT定义
 */
typedef struct {
    /* PRACH调度信息 */
    uint32_t                prachEn          : 1;       /* Prach发送指示，多子帧PRACH，只有首子帧该指示置位 */
    uint32_t                prachMulSbfnEn   : 1; /* 多子帧Prach发送指示，每个发送子帧都置位 */

    /* SRS调度信息 */
    uint32_t                srsTxNum         : 2;      /* 0->无SRS发送；若有SRS发送，用于指示SRS符号数 */

    /* PUSCH调度信息 */
    uint32_t                puschEn          : 1;
    uint32_t                onlyUciInfoFlg   : 1;
    uint32_t                pusUciEn         : 1;
    uint32_t                harqId           : 4;
    uint32_t                puschStartSymIdx : 4; /* PUSCH起始symidx */
    uint32_t                puschEndSymIdx   : 4; /* PUSCH结束symIdx */

    /* PUCCH调度信息 */
    uint32_t                pucchEn          : 1;
    uint32_t                pucchStartSymIdx : 4; /* PUCCH起始symidx */
    uint32_t                pucchEndSymIdx   : 4; /* PUCCH结束symidx */
    uint32_t                cqiEn            : 1;
    uint32_t                srEn             : 1;
    uint32_t                riEn             : 1;
    uint32_t                ackEn            : 1;

    /* SRS时域调度信息 */
    uint8_t                 srsSymIdx[UPHY_NUM2];

    /* PUSCH各个TB调度信息 */
    uint8_t                 newGrantInd[UPHY_NUM2];    /* 新传指示，1->新传；0->重传 */
    uint8_t                 tbValid[UPHY_NUM2];
    uint8_t                 ulGrantType; /* PUS发送类型, 此字段为0表示PUS上发送MSG3 */
    uint8_t                 rsv;
} LPHY_ULDSDS_UlCtrlOmRpt;

typedef struct {
    uint32_t                             sfStartMc;
    uint16_t                             sysFn;
    uint16_t                             subFrm     : 4;

    uint16_t                             volteState : 1;
    uint16_t                             channelId  : 1;
    uint16_t                             modemId    : 1;

    /* MSG2接收保护调度信息 */
    uint16_t                             preambleNum: 5;
    uint16_t                             sfNumPrtcPreamble: 4;  /* <= 1st 16bit */

    /* msg4接收保护计数器 */
    uint16_t                             sfNumPrtcMsg3  : 4;
    /* msg4 ACK发送保护计数器 */
    uint16_t                             ackNumAfterMsg3: 4;

    /* SR后UlGrant调度信息 */
    uint16_t                             srNum          : 8; /* <= 2nd 16bit */
    uint16_t                             sfNumPrtcSr    : 4;
    uint16_t                             srMacCfg       : 1;

    uint16_t                             srsCancel      : 1;
    uint16_t                             cqiCancel      : 1;
    uint16_t                             paddingCancel  : 1;
    uint16_t                             conCaFlag      : 1;
    uint16_t                             rsv0           : 7; /* <= 3rd 16bit */

    /* 系统配置参数 */
    uint8_t                              ulCpType[LPHY_CAPACITY_MAX_UL_CARRIER_NUM]; /* 0->Normal CP, 1->Extended CP */
    uint16_t                             pccUlDlCfg;
    uint16_t                             pccFrameType;
    uint16_t                             rsv1;
    /* TA ACK保护信息 */
    uint16_t                             ackTransSysFrm;
    uint8_t                              ackTransSubFn;
    uint8_t                              taAckTransFlag;

    /* 当前子帧调度的PCC/SCC上行调度信息，n+2子帧生效 */
    LPHY_ULDSDS_UlCtrlOmRpt              pccUlSchedInfo;
    LPHY_ULDSDS_UlCtrlOmRpt              sccUlSchedInfo;

    /* 上一子帧生效的仲裁信息回读 */
    FESS_TRXC_UldsdsUlArbPara            pccUlArbPara;
    FESS_TRXC_UldsdsUlArbPara            sccUlArbPara;
} LPHY_L1U_UldsdsOmReport;
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