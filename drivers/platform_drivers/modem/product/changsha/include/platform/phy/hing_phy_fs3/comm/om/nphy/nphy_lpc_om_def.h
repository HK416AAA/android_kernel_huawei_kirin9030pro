


#ifndef __NPHY_LPC_OM_DEF_H__
#define __NPHY_LPC_OM_DEF_H__

/*
 * 1 Other header include
 */
#include "neun_lpc_om_def.h"


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */


/*
 * 3. Enumerations declarations
 */
enum NPHY_LPC_OmRptMsgIdType {
    NPHY_OM_LPC_MSGID_START             = NPHY_OM_L1MSG_ID(NPHY_MODULE_LPC, 0x0),
    NPHY_OM_LPC_L1CL1M_MSG              = NPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_L1CL1M_MSG,
    NPHY_OM_LPC_L1ML1C_MSG              = NPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_L1ML1C_MSG,
    NPHY_OM_LPC_L1CL1D_MSG              = NPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_L1CL1D_MSG,
    NPHY_OM_LPC_L1DL1C_MSG              = NPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_L1DL1C_MSG,
    NPHY_OM_LPC_L1CL1U_MSG              = NPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_L1CL1U_MSG,
    NPHY_OM_LPC_L1UL1C_MSG              = NPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_L1UL1C_MSG,
    NPHY_OM_LPC_L1CFESS_MSG             = NPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_L1CFESS_MSG,
    NPHY_OM_LPC_FESSL1C_MSG             = NPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_FESSL1C_MSG,
    NPHY_OM_LPC_HL1C_WAKE_INFO          = NPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_HL1C_WAKE_INFO,
    NPHY_OM_LPC_HL1C_SLEEP_INFO         = NPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_HL1C_SLEEP_INFO,
    NPHY_OM_LPC_HL1C_STATE_INFO         = NPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_HL1C_STATE_INFO,
    NPHY_OM_LPC_SYMBLPC_RX_INFO         = NPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_SYMBLPC_RX_INFO,
    NPHY_OM_LPC_DVTY_INFO               = NPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_DVTY_INFO,
    NPHY_OM_LPC_LOCAL_BWP_UPDATE_INFO   = NPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_LOCAL_BWP_UPDATE_INFO,
    NPHY_OM_LPC_DVFS_TSP_PROF_INFO      = NPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_DVFS_TSP_PROF_INFO,
    NPHY_OM_LPC_DVTY_CAL_INFO           = NPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_DVTY_CAL_INFO,
    NPHY_OM_LPC_DFX_INFO                = NPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_DFX_INFO,
    NPHY_OM_LPC_PRINT_RPT               = NPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_PRINT_RPT,
    NPHY_OM_LPC_PAGING_LISTEN_INFO      = NPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_PAGING_LISTEN_INFO,
    NPHY_OM_LPC_LOCAL_TX_INFO           = NPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_LOCAL_TX_INFO,
    NPHY_OM_LPC_PDCONLY_MC_RPT          = NPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_PDCONLY_MC_RPT,
};
typedef uint32_t NPHY_LPC_OmRptMsgId;

enum NPHY_LPC_LocalBwpSwitchEvt {
    NPHY_LPC_BWP_NON = 0,                          /* 不需要切换 */
    NPHY_LPC_BWP_RRCCFG = 1,                       /* RRC配置变化 */
    NPHY_LPC_BWP_DCI = 2,                          /* 解到DCI切换 */
    NPHY_LPC_BWP_CSI = 3,                          /* 非周期CSI上报不切local bwp */
    NPHY_LPC_BWP_PAGING = 4,                       /* 解到寻呼DCI后4个寻呼周期不切locla bwp */
    NPHY_LPC_BWP_NOTSUPPORT = 5,                   /* 不支持localBWP的场景 */
    NPHY_LPC_BWP_DSDX = 6,                         /* 双卡，DSDX状态变化 */
    NPHY_LPC_BWP_PROTECT = 7,                      /* 保护任务不切locla bwp */
    NPHY_LPC_BWP_RBCHANGE = 8,                     /* RB变化触发切换 */
    NPHY_LPC_BWP_TIMEOUT = 9,                      /* 时间保护满足触发切换 */
    NPHY_LPC_BWP_MEAS_ACTIVE = 16,                 /* 测量业务激活触发切换 */
    NPHY_LPC_BWP_MEAS_DEACTIVE = 17,               /* 测量业务去激活触发切换 */
    NPHY_LPC_BWP_NONMEAS_ACTIVE = 18,              /* 非测量业务激活触发切换 */
    NPHY_LPC_BWP_DLSPS_ACTIVE = 19,                /* NR DL SPS激活触发切换 */
    NPHY_LPC_BWP_WUS_ACTIVE = 20,                  /* WUS触发切换 */
    NPHY_LPC_BWP_EVENT_BUTT
};
typedef uint8_t NPHY_LPC_LocalBwpSwitchEvtUint08;

/*
 * 枚举说明: BWP切换的原因
 */
enum NPHY_LPC_BwpSwitchType {
    NPHY_LPC_BWP_NO_SWITCH = 0,   /* 不切换 */
    NPHY_LPC_BWP_RRC_CONFIG,      /* 切换到新的基站配置BWP */
    NPHY_LPC_BWP_LOCAL,           /* 切换到Local BWP */
    NPHY_LPC_BWP_BACK_RRC_CONFIG, /* 回退到原来基站配置的激活BWP */
    NPHY_LPC_BWP_SSB_TRS,         /* 切换到SSB/TRS/SSBandTRS BWP带宽 */
    NPHY_LPC_BWP_WUS,             /* 切换到WUS BWP带宽 */
    NPHY_LPC_BWP_WUS_SSB,         /* 切换到WUS+SSB BWP带宽 */
    NPHY_LPC_BWP_BUTT
};
typedef uint8_t NPHY_LPC_BwpSwitchTypeUint08;

/* microsleep2.0 BWP切换的原因不能进入的原因 */
enum NPHY_LPC_MicroSleepForBidType {
    NPHY_LPC_MICROSLEEP_ENABLE = 0,      /* 当前场景可以进入microsleep2.0 */
    NPHY_LPC_MICROSLEEP_CLOSE,           /* NV或AT命令关闭功能 */
    NPHY_LPC_MICROSLEEP_PROC_FORBID,     /* 非连接态，或release过程存在时，阻止进入 */
    NPHY_LPC_MICROSLEEP_SYMBLPC_DISABLE, /* 无损符号级低功耗未生效 */
    NPHY_LPC_MICROSLEEP_PROTECT_TASK,    /* 保护任务正在执行 */
    NPHY_LPC_MICROSLEEP_DCI_WIN,         /* 不满足DCI禁止窗长 */
    NPHY_LPC_MICROSLEEP_CSI_FORBID,      /* CSI阻止进入 */
    NPHY_LPC_MICROSLEEP_CA_FORBID,       /* CA阻止进入 */
    NPHY_LPC_MICROSLEEP_DLSPS_FORBID,    /* DL SPS激活阻止进入 */
    NPHY_LPC_MICROSLEEP_SNR_FORBID,      /* 有损加SNR条件,低于5db时不进有损 */
    NPHY_LPC_MICROSLEEP_BUTT
};
typedef uint8_t NPHY_LPC_MicroSleepForBidTypeUint08;

typedef struct {
    uint32_t        bbpDvfsReqSlice;
    uint32_t        bbpDvfsCnfSlice;
    uint16_t        bbpDvfsReqCnt;
    uint16_t        bbpDvfsCnfCnt;

    uint32_t        currPdfWeight;
    uint32_t        currPdtWeight;
    uint32_t        currUlWeight;
    uint32_t        lastPdfWeight;
    uint32_t        lastPdtWeight;
    uint32_t        lastUlWeight;
    uint8_t         actualPdfProfile;
    uint8_t         actualPdtProfile;
    uint8_t         actualUlProfile;
    uint8_t         rsv;
} NPHY_LPC_OmDvfsBbpInfo;


typedef struct {
    uint32_t  rsv;
} NPHY_LPC_OmDvfsTspInfo;

typedef struct {
    uint16_t                                sysFrmNum;
    uint8_t                                 subFrmNum;
    uint8_t                                 symbLpcEn;
    uint8_t                                 dlUpdateFlag;
    uint8_t                                 ccIndex;
    uint16_t                                rxSymbBit[UPHY_NUM3];
    uint8_t                                 slotNum;
    uint8_t                                 slotNumInSysFN;
    uint8_t                                 microSleep20State;
    uint8_t                                 voteFlag;
    uint16_t                                hl1cVoteRxBit[UPHY_NUM3];
    uint16_t                                dlVoteSymb[UPHY_NUM3];
    uint8_t                                 sfiConflictFlg;
    NPHY_LPC_MicroSleepForBidTypeUint08     forbidReason;
    uint8_t                                 fastModeForbidEvtBitMap; /* PCC阻止进入快调模式的事件集合 */
    NEUN_LPC_SymbLpcWorkModeUint08          pccWorkMode; /* PCC符号级低功耗工作模式 */
} NPHY_LPC_OmSymbRxBitInfo;

typedef struct {
    uint16_t                         sysFrm;              /* sysFrame */
    uint16_t                         slotNum;             /* slot number */
    int16_t                          dciRbStart;          /* DCI基于PointA的起始RB */
    int16_t                          dciRbEnd;            /* DCI基于PointA的结束RB */
    int16_t                          ssbMeasRbStart;      /* SSB测量基于PointA的起始RB */
    int16_t                          ssbMeasRbEnd;        /* SSB测量基于PointA的结束RB */
    uint16_t                         trsMeasRbStart;      /* TRS测量基于PointA的起始RB */
    uint16_t                         trsMeasRbEnd;        /* TRS测量基于PointA的结束RB */
    int16_t                          csiRbStart;          /* 周期CSI上报基于PointA的起始RB */
    int16_t                          csiRbEnd;            /* 周期CSI上报基于PointA的结束RB */
    int16_t                          trsRbStart;          /* TRS基于PointA的起始RB */
    int16_t                          trsRbEnd;            /* TRS基于PointA的结束RB */
    int16_t                          curRbStart;          /* 目前实际生效的起始RB */
    int16_t                          curRbEnd;            /* 目前实际生效的结束RB */
    int16_t                          wusMinRbStart;       /* wus最小起始RB */
    int16_t                          wusMaxRbEnd;         /* wus最大结束RB */

    uint16_t                         csiCycle;            /* 激活BWP的周期CSI的上报周期 */
    uint8_t                          dlRbUpdateFlag;      /* DCI/TRS/CSI RB是否有刷新标志 */
    uint8_t                          ssbMeasRbUpdateFlag; /* SSB测量的RB是否有刷新 */
    uint8_t                          ssbOverBwpFlag;      /* SSB测量不在激活带宽内标志 */
    uint8_t                          csiAperiodicFlag;    /* 非周期CSI生效标志 */
    uint8_t                          localBwpState;       /* 记录当前CC工作的bwp类型 */
    NPHY_LPC_BwpSwitchTypeUint08     bwpSwitchType;       /* 记录当前CCBWP切换的类型 */
    NPHY_LPC_LocalBwpSwitchEvtUint08 switchReason;        /* 记录切换原因 */
    uint8_t                          ccIdx;
    uint16_t                         resyncInSsbOnlyCcMap;
    NEUN_PROC_MeasBwpTypeUint08      measBwpType;         /* 切换到 NPHY_LPC_BWP_SSB 场景需要进一步根据该枚举计算rbNum */
    uint8_t                          rsv[UPHY_NUM3];
} NPHY_LPC_OmLocalBwpInfo;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* #ifndef __NPHY_LPC_OM_DEF_H__ */

