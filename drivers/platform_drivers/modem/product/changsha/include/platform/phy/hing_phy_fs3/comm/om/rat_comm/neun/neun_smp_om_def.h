

/*
 * 1 Other Header File Including
 */
#ifndef NEUN_SMP_OM_DEF_H
#define NEUN_SMP_OM_DEF_H

#include  "uphy_typedef.h"
#include  "uphy_om_def.h"
#include  "uphy_om_interface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(push, 4)

/*
 * 2 Macro definition
 */
#define NEUN_SMP_OM_ON                  1
#define NEUN_SMP_OM_OFF                 0
#define NEUN_SMP_OM_SWITCH              NEUN_SMP_OM_ON
#define NEUN_SMP_OM_MAX_PSS_NUM         32
#define NEUN_SMP_OM_MAX_RX_NUM          4

/*
 * 3 枚举定义
 */
/*
 * Enum Description: OmReqMsgId
 */
enum NPHY_SMP_OmReqMsgId {
    NPHY_SMP_REQ_MSGID_START = NPHY_OM_REQ_ID(NPHY_MODULE_ID_SMP, 0x0),
    NPHY_SMP_REQ_MSGID_BUTT,
};
typedef uint8_t NPHY_SMP_OmReqMsgIdUint08;

enum LPHY_SMP_OmReqMsgId {
    LPHY_SMP_REQ_MSGID_START = LPHY_OM_REQ_ID(LPHY_MODULE_ID_SMP, 0x0),
    LPHY_SMP_REQ_MSGID_BUTT,
};
typedef uint8_t NPHY_SMP_OmReqMsgIdUint08;
/*
 * Enum Description: OM Rpt MsgId
 */
enum NPHY_SMP_OmRptMsgId {
    NPHY_SMP_RPT_MSGID_START = NPHY_OM_L1MSG_ID(NPHY_MODULE_ID_SMP, 0x0),
    NPHY_SMP_RPT_LL1D_MSG    = NPHY_SMP_RPT_MSGID_START,
    NPHY_SMP_RPT_STEP1_MSG,
    NPHY_SMP_RPT_CHNLSTATE_MSG,
    NPHY_SMP_FCFU_CFG_RPT_MSG,
    NPHY_SMP_COMP_NTF_RPT_MSG,
    NPHY_SMP_AGC_RSSI_RSLT_RPT,
    NPHY_SMP_RPT_MSGID_BUTT,
};
typedef uint8_t NPHY_SMP_OmRptMsgIdUint08;

enum LPHY_SMP_OmRptMsgId {
    LPHY_SMP_RPT_MSGID_START = LPHY_OM_L1MSG_ID(LPHY_MODULE_ID_SMP, 0x0),
    LPHY_SMP_RPT_LL1D_MSG    = LPHY_SMP_RPT_MSGID_START,
    LPHY_SMP_RPT_STEP1_MSG,
    LPHY_SMP_RPT_CHNLSTATE_MSG,
    LPHY_SMP_RPT_MSGID_BUTT,
};
typedef uint8_t LPHY_SMP_OmRptMsgIdUint08;

/*
 * 4 Struct definition
 */
typedef struct {
    uint32_t                            smpFreqInfo;

    uint8_t                             rxNum;
    uint8_t                             scsType;
    uint8_t                             frameType;
    uint8_t                             interFlag;

    uint8_t                             csuSmpEn;
    uint8_t                             emuSmpEn;
    uint8_t                             csuStep1En;
    uint8_t                             csuTailFlag;

    uint8_t                             smpStartMode;
    uint8_t                             csuPeriodCombFlag;
    uint8_t                             smpRbNumType;
    uint8_t                             dataMsLen;

    uint8_t                             fCfuCsuChnIdx;
    uint8_t                             smpDataDdrFlag;
    uint16_t                            res1;

    uint32_t                            smpStartAddRx01;
    uint32_t                            smpStartAddRx23;

    uint8_t                             foScanEn;
    uint8_t                             foScanNum;
    uint8_t                             foScanIdx;
    uint8_t                             foScanMode;
    /* 采数定时配置 */
    uint32_t                            smpTimingCfg[UPHY_NUM6];                /* 后续可细化结构，当前通用模式 */
} NEUN_SMP_OmRptLl1dCfgNtfMsg;


/* 结构说明: CSU step1结果 */
typedef struct {
    uint32_t                            nid2            : 2;
    uint32_t                            step1Pos        : 21;
    uint32_t                            corr            : 9;
} NEUN_SMP_OmCsuPssInfo;

/*
 * Struct Description: NEUN SMP configuration OM Info
 */
typedef struct {
    uint32_t                            addrR01;
    uint32_t                            addrR23;
} NEUN_SMP_OmCfgInfo;

/*
 * Struct Description: NEUN SMP report step1 OM Info
 */
typedef struct {
    uint8_t                             csuState;                               /* 合并csuRsltState和csuSdcOverflow */
    uint8_t                             ccModeRpt;
    uint8_t                             rsltStartTs;
    uint8_t                             rsv0;
    uint16_t                            rsltPrdCnt;
    uint16_t                            rsv1;
    uint32_t                            sti;
    uint32_t                            smpCnt;
    int16_t                             agcGain[NEUN_SMP_OM_MAX_RX_NUM];
} NEUN_SMP_OmRptInfo;

/*
 * Struct Description: NEUN CSU report step1 OM Info
 */
typedef struct {
    uint32_t                            freqInfo;
    uint8_t                             foScanMode;
    uint8_t                             rxNum;
    uint8_t                             chIdx;
    uint8_t                             pssDetNum;
    NEUN_SMP_OmCfgInfo                  smpCfgInfo;
    NEUN_SMP_OmRptInfo                  smpRptInfo;
    NEUN_SMP_OmCsuPssInfo               pssInfo[NEUN_SMP_OM_MAX_PSS_NUM];
} NEUN_SMP_OmCsuStep1RptInfo;

typedef union {
    /* Define the struct bits */
    struct {
        /*
         * 调试用。
         * [5]: 保留
         * [4]: 数采s2b buf满告警
         * [3]：结果上报s2b buf满告警
         * [2]：排序fifo写满告警
         * [1]：时域相关buf写满告
         * [0]：入口sfifo写满告警
         */
        unsigned int sfifo                    : 1;
        unsigned int res                      : 1;
        unsigned int sortFifo                 : 1;
        unsigned int s2bBuffRpt               : 1;
        unsigned int s2bBuffSmp               : 1;
        unsigned int res2                     : 27;
    } bits;

    /* Define an unsigned member */
    unsigned int u32;
} NEUN_SMP_OmChnDebugAlm0;


typedef union {
    /* Define the struct bits */
    struct {
        uint32_t csuStartState             : 1;      /* [0]:csu_start启动状态 */
        uint32_t resApplyState             : 1;      /* [1]:资源申请状态 */
        uint32_t bookingTimeRpt            : 16;     /* [17:2]:预约启动时刻定时上报 */
        uint32_t step1State                : 2;      /* [19:18]:step1状态机状态 */
        uint32_t stopIndState              : 3;      /* [22:20]:stop_ind状态 */
        uint32_t smpBusyState              : 1;      /* [23]:数采busy状态 */
        uint32_t sortBusyState             : 1;      /* [24]:二级排序busy状态 */
        uint32_t step1CalcState            : 1;      /* [25]:step1计算状态 */
        uint32_t corrCalcState             : 1;      /* [26]:相关计算状态 */
        uint32_t srchIsrWaitState          : 1;      /* [27]:srch中断等待延时状态 */
        uint32_t measIsrWaitState          : 1;      /* [28]:meas中断等待延时状态 */
        uint32_t corrCalcWaitState         : 1;      /* [29]:相关计算延时状态 */
        uint32_t reserved                  : 2;      /* [31:30]:保留 */
    } bits;

    /* Define an unsigned member */
    uint32_t u32;
} NEUN_SMP_OmCcDebugRpt0;
/* Define the union CcDebugRpt1 */
typedef union {
    /* Define the struct bits */
    struct {
        uint32_t startCnt                 : 5;      /* [4:0]:软件配置start计数 */
        uint32_t stopCnt                  : 5;      /* [9:5]:软件配置stop计数 */
        uint32_t srchEndState             : 2;      /* [11:10]:搜索结束状态：0正常、1abn、2stop */
        uint32_t measEndState             : 2;      /* [13:12]:测量结束状态：0正常、1abn */
        uint32_t srchAbnCnt               : 4;      /* [17:14]:搜索abn计数 */
        uint32_t srchStopCnt              : 4;      /* [21:18]:搜索stop计数 */
        uint32_t srchIsrCnt               : 4;      /* [25:22]:搜索中断计数 */
        uint32_t measIsrCnt               : 4;      /* [29:26]:测量中断计数 */
        uint32_t reserved                 : 2;      /* [31:30]:保留 */
    } bits;

    /* Define an unsigned member */
    uint32_t u32;
} NEUN_SMP_OmCcDebugRpt1;
/* Define the union CcDebugRpt2 */
typedef union {
    /* Define the struct bits */
    struct {
        /*
         * 小区搜索工作状态指示：
         * 1'b1，小区搜索处于工作状态
         * 1'b0，小区搜索处于空闲态
         * 注：当csu_work_state=0时才可启动下一次搜索
         */
        uint32_t csuWorkState            : 1;       /* [0] */
        uint32_t reserved                : 31;      /* [31:1] */
    } bits;

    /* Define an unsigned member */
    uint32_t u32;
} NEUN_SMP_OmCcDebugRpt2;

typedef union {
    /* Define the struct bits */
    struct {
        uint32_t step1CalcResOverFlow    : 1;       /* [0]：step1运算资源申请超限告警 */
        uint32_t dataSmpResOverFlow      : 1;       /* [1]：数据采集资源申请超限告警 */
        uint32_t firFilterResOverFlow    : 1;       /* [2]：FIR滤波资源申请超限告警警 */
        uint32_t res                     : 1;       /* [3]：保留 */
        uint32_t lastCalcNotFinished     : 1;       /* [4]：启动时前一次运算未完成（工作状态配置start） */
        uint32_t bookingTimeNoDataInput  : 1;       /* [5]：预约启动位置未进数告警（数据通路未打开） */
        uint32_t bookingTimePassby       : 1;       /* [6]：搜索预约时间配置已过前时刻告警 */
        uint32_t reserved                : 25;      /* [31:7]：保留 */
    } bits;

    /* Define an unsigned member */
    uint32_t u32;
} NEUN_SMP_OmCcDebugAlm;

typedef struct {
    uint8_t                             runState;
    uint8_t                             chIdx;
    uint8_t                             interFlag;
    uint8_t                             res;

    NEUN_SMP_OmCcDebugRpt0              bbpDbgRpt0;
    NEUN_SMP_OmCcDebugRpt1              bbpDbgRpt1;
    NEUN_SMP_OmCcDebugRpt2              bbpDbgRpt2;
    NEUN_SMP_OmCcDebugAlm               bbpDbgAlm;

    uint32_t                            bbpDbgSmpCnt;
    uint32_t                            bbpDbgBaseAddr;
    uint32_t                            bbpFdaeInt;
    uint32_t                            bbpFdaeEn;

    NEUN_SMP_OmChnDebugAlm0             fifoAlm;
} NEUN_SMP_OmChnStateReadInfo;

#pragma pack(pop)

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* end of .h */

