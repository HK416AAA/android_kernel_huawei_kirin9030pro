
#ifndef __NEUN_LPC_OM_DEF_H__
#define __NEUN_LPC_OM_DEF_H__

#include "uphy_om_interface.h"


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

#pragma pack(push, 4)


enum NEUN_LPC_OmRptMsgId_ {
    NEUN_OM_LPC_L1CL1M_MSG = 0x0,
    NEUN_OM_LPC_L1ML1C_MSG,
    NEUN_OM_LPC_L1CL1D_MSG,
    NEUN_OM_LPC_L1DL1C_MSG,
    NEUN_OM_LPC_L1CL1U_MSG,
    NEUN_OM_LPC_L1UL1C_MSG,
    NEUN_OM_LPC_L1CFESS_MSG,
    NEUN_OM_LPC_FESSL1C_MSG,
    NEUN_OM_LPC_HL1C_WAKE_INFO,
    NEUN_OM_LPC_HL1C_SLEEP_INFO,
    NEUN_OM_LPC_HL1C_STATE_INFO,
    NEUN_OM_LPC_SYMBLPC_RX_INFO,
    NEUN_OM_LPC_DVTY_INFO,
    NEUN_OM_LPC_LOCAL_BWP_UPDATE_INFO,
    NEUN_OM_LPC_DVFS_TSP_PROF_INFO,
    NEUN_OM_LPC_DVTY_CAL_INFO,
    NEUN_OM_LPC_DFX_INFO,
    NEUN_OM_LPC_PRINT_RPT,
    NEUN_OM_LPC_PAGING_LISTEN_INFO,
    NEUN_OM_LPC_LOCAL_TX_INFO,
    NEUN_OM_LPC_PDCONLY_MC_RPT,
    NEUN_OM_LPC_MSGID_BUTT
};
typedef uint32_t NEUN_LPC_OmRptMsgIdxUint32;

// CHR 需求：NEUN_LPC_DVTY_IMMED_MBS之前的枚举值相对C版本不能辩护，枚举范围也不能扩充，否则会CHR影响码流对齐
enum NEUN_LPC_DvtyImmedEvt {
    NEUN_LPC_DVTY_IMMED_NON = 0,       /* 不需要立即切换 */
    NEUN_LPC_DVTY_IMMED_FORBIT_VOTE,   /* 保护任务需要立即切换 */
    NEUN_LPC_DVTY_IMMED_HST,           /* 高铁场景不支持关分集 */
    NEUN_LPC_DVTY_IMMED_SPS,           /* SPS场景不支持关分集 */
    NEUN_LPC_DVTY_IMMED_CONCA,         /* 连续CA不支持关分集 */
    NEUN_LPC_DVTY_IMMED_LOW_LATENCY,   /* 下行Minislot/dmrsCfgTypeB/pdc case 1-2，不支持关分集 */
    NEUN_LPC_DVTY_IMMED_TX_2T,         /* TX天线数2T不支持关分集 */
    NEUN_LPC_DVTY_IMMED_RRC_MAX,       /* Tx天线数或性能模式OTA天线数和Tx天线数取大, 已经是UeCap时 直接开分集 */
    NEUN_LPC_DVTY_IMMED_RACH,          /* 随机接入不支持关分集 */
    NEUN_LPC_DVTY_IMMED_CRCERROR,      /* CRC错需要立即切换 */
    NEUN_LPC_DVTY_IMMED_PDSRATE,       /* PDS调度率或误码率超出门限 */
    NEUN_LPC_DVTY_IMMED_MIN_MAX,       /* 被允许最小天线数已最大 */
    NEUN_LPC_DVTY_IMMED_CCCFG,         /* ccCfg更新天线数 */
    NEUN_LPC_DVTY_IMMED_MIN_PROTECT,   /* 评估窗内需要开到被允许最小天线数时 */
    NEUN_LPC_DVTY_IMMED_PROTECT,       /* 保护任务需要立即切换 */
    NEUN_LPC_DVTY_IMMED_VOICE,         /* 语音不支持关分集的场景需要立即切换 */
    NEUN_LPC_DVTY_IMMED_DSDX,          /* 双卡，副卡进入连接态后不支持关分集 */
    NEUN_LPC_DVTY_IMMED_PAGING,        /* 解到寻呼DCI后4个寻呼周期不切locla bwp, For NR only */
    NEUN_LPC_DVTY_IMMED_CSI,           /* 非周期CSI上报不切local bwp, For NR only */
    NEUN_LPC_DVTY_IMMED_NOMEAS,        /* 无测量值时保持最大收 */
    NEUN_LPC_DVTY_IMMED_MBS,           /* MBS不支持关分集 */
    NEUN_LPC_DVTY_IMMED_JUDGE,         /* 依据最新评估结果刷新 */
    NEUN_LPC_DVTY_IMMED_HOLD,          /* 特殊任务不能切天线 */
    NEUN_LPC_DVTY_IMMED_RSV0,          /* 保留 */
    NEUN_LPC_DVTY_IMMED_RSV1,          /* 保留 */
    NEUN_LPC_DVTY_IMMED_RSV2,          /* 保留 */
    NEUN_LPC_DVTY_IMMED_EVENT_ID_BUTT
};
typedef uint8_t NEUN_LPC_DvtyImmedEvtUint08;

enum NEUN_HLPC_DvtyPreventCause  {
    NEUN_HLPC_DVTY_PREVENT_NONE = 0,
    NEUN_HLPC_DVTY_PREVENT_PROTECT_TASK,    /* PAG和PSYNC不关分集 */
    NEUN_HLPC_DVTY_PREVENT_TFSYNC_IND,      /* 时频不稳定不关分集 */
    NEUN_HLPC_DVTY_PREVENT_SIGNEL_LEV,      /* 信号格数恶化不关分集 */
    NEUN_HLPC_DVTY_PREVENT_DCI_WIN,         /* 40msDCI窗内不关分集 */
    NEUN_HLPC_DVTY_PREVENT_SNR_WIN,         /* 1s低信噪比窗内不关分集 */
    NEUN_HLPC_DVTY_PREVENT_BUTT,
};
typedef uint8_t NEUN_HLPC_DvtyPreventCauseUint8;

enum NEUN_LPC_DVTY_CloseLimitCause {
    NEUN_LPC_DVTY_CLSOE_LIMIT_NONE = 0,   /* 默认最小1R */
    NEUN_LPC_DVTY_CLSOE_LIMIT_OTA,        /* 性能优先时OTA是天线数下限 */
    NEUN_LPC_DVTY_CLSOE_LIMIT_DCI,        /* 功耗优化时DCI窗内OTA是下限 */
    NEUN_LPC_DVTY_CLSOE_LIMIT_CRC,        /* 误码时不小于pdsPort数和当前天线数 */
    NEUN_LPC_DVTY_CLSOE_LIMIT_BUTT,
};
typedef uint8_t NEUN_LPC_DVTY_CloseLimitCauseUint8;

enum NEUN_LPC_DvtyMode {
    NEUN_LPC_DVTY_KEEP,
    NEUN_LPC_DVTY_CLOSE,
    NEUN_LPC_DVTY_OPEN,
    NEUN_LPC_DVTY_BUTT
};
typedef uint8_t NEUN_LPC_DvtyModeUint08;

enum NEUN_LPC_PrintEvt {
    NEUN_LPC_PRINT_ACT_UL_FAIL = 0,
    NEUN_LPC_PRINT_NPHY_SYMB_EVT_ERROR = 1,
    NEUN_LPC_PRINT_NPHY_LOWTASK_FAIL = 2,
    NEUN_LPC_PRINT_NPHY_SCHED_SCS_ERROR = 3,
    NEUN_LPC_PRINT_NPHY_LL1D_REV_IRAT_MSG = 4,
    NEUN_LPC_PRINT_NPHY_LL1D_SCHED_FDMA_LOGIN_FAIL = 5,
    NEUN_LPC_PRINT_NPHY_LL1D_SCHED_MAILCNT_OVERFLOW = 6,
    NEUN_LPC_PRINT_NPHY_DLLPC_TSK_BUSY = 7,
    NEUN_LPC_PRINT_NPHY_LL1D_ACT = 8,
    NEUN_LPC_PRINT_DVFS_TIMER_ERR = 9,
    NEUN_LPC_PRINT_LL1D_REV_HL1C_MID_MSG = 10,
    NEUN_LPC_PRINT_LTE_MEAS_STOPING = 11,
    NEUN_LPC_PRINT_CDRX_TIMER_CFG_ERR = 12,
    NEUN_LPC_PRINT_UECAP_OTA_RXANTNUM_ERR = 13,
    NEUN_LPC_PRINT_SSB_BWP_SAVE = 14,
    NEUN_LPC_PRINT_SERV_BWP_SAVE = 15,
    NEUN_LPC_PRINT_EVT_BUTT
};
typedef uint32_t NEUN_LPC_PrintEvtUint32;

/*
 * 结构说明: 低功耗OM请求信息
 */
typedef struct {
    uint32_t l1cL1mMsg    : 1;
    uint32_t l1mL1cMsg    : 1;
    uint32_t l1cL1dMsg    : 1;
    uint32_t l1dL1cMsg    : 1;
    uint32_t l1cL1uMsg    : 1;
    uint32_t l1uL1cMsg    : 1;
    uint32_t l1cFessMsg   : 1;
    uint32_t fessL1cMsg   : 1;
    uint32_t hl1cWakeInf  : 1;
    uint32_t hl1cSleepInf : 1;
    uint32_t hl1cStateInf : 1;
    uint32_t symbLpcRxInf : 1;
    uint32_t dvtyInf      : 1;
    uint32_t loaclBwp     : 1;
    uint32_t tspDvfsProf  : 1;
    uint32_t dvtyCalInf   : 1;
    uint32_t dfxInfo      : 1;
    uint32_t printSwitch  : 1;
    uint32_t pagingListen : 1;
    uint32_t localTx      : 1;
    uint32_t pdcOnlyMcRpt : 1;
    uint32_t rsv          : 11;
} NEUN_LPC_OmSwitch;


typedef struct {
    uint32_t    wakeReqSlice;       /* 记录发送唤醒请求时间戳 */
    uint32_t    wakeCnfSlice;       /* 记录收到唤醒回复时间戳 */
    uint32_t    sleepReqSlice;      /* 记录发送唤醒请求时间戳 */
} NEUN_LPC_OmRfInfo;

typedef struct {
    void*    addr;
    uint32_t size;
} NEUN_LPC_OmReqInf;

/*
 * 结构说明: 低功耗print信息
 */
typedef struct {
    UPHY_OM_ReportLevelUint32 level;
    NEUN_LPC_PrintEvtUint32 evtId;
    uint32_t para1;
    uint32_t para2;
} NEUN_LPC_PrintRptInfo;

#pragma pack(pop)

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* #ifndef __NEUN_LPC_OM_DEF_H__ */

