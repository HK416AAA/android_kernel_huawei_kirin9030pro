

/*
 * 1 Other Header File Including
 */
#ifndef NEUN_CSU_OM_DEF_H
#define NEUN_CSU_OM_DEF_H

#include  "uphy_typedef.h"
#include  "uphy_om_def.h"
#include  "uphy_om_interface.h"
#include  "uphy_trace_interface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(push, 4)

/*
 * 2 Macro definition
 */
#define NEUN_CSU_OM_ON        1
#define NEUN_CSU_OM_OFF       0
#define NEUN_CSU_OM_SWITCH    NEUN_CSU_OM_ON
#define NEUN_CSU_OM_MAX_CELL_NUM 16
#define NEUN_CSU_OM_MAX_PSS_NUM  32
#define NEUN_CSU_OM_MAX_RX_NUM   4

#define NEUN_SDR_FUNC_OM_SWITCH NEUN_CSU_OM_ON
#define NEUN_SDR_TRS_LLF_NUM    7
#define NEUN_SDR_SSB_MSE_NUM    3
#define NEUN_SDR_TRMS_LLF_NUM   6
#define NEUN_SDR_DMRS_RX_NUM    2
#define NEUN_SDR_DMRS_MSE_NUM   7
#define NEUN_SDR_DMRS_CROSS_NUM 10

#define NEUN_SDR_TX_RPT_NUM     8
#define NEUN_SDR_RX_RPT_NUM     4
#define NEUN_SDR_RX_COL_NUM     2
#define NEUN_SDR_TRX_MASK       0x03
#define NEUN_SDR_TRX_SHIFT      2

/* 任务时刻点负载跟踪开关，采用多任务共享buffer的方式，适用于单卡场景，跟踪pcc负载，建议单次仅配置一个任务，避免数据因优先级串扰 */
#define NEUN_SDR_TASK_LOAD_SWITCH       NEUN_CSU_OM_OFF     /* 任务负载跟踪开关接口开关 */
#define NEUN_SDR_PARA_DMRS_LOAD_SWITCH  NEUN_CSU_OM_OFF     /* DMRS参数估计任务的时刻点维测 */
#define NEUN_SDR_OM_TASKLOAD_LEN        16                  /* 任务时间点计数时间点的数目 */

#define NEUN_BGT_CSU_MAX_CELL_NUM       32
/*
 * 3 枚举定义
 */
/*
 * Enum Description: OmReqMsgId
 */
enum NPHY_CSU_OmReqMsgId {
    NPHY_CSU_REQ_MSGID_START  = NPHY_OM_REQ_ID(NPHY_MODULE_ID_CSU, 0x0),
    NPHY_CSU_RSLT_OM_REQ      = NPHY_CSU_REQ_MSGID_START,
    NEUN_SDR_TSPFUNC_OM_REQ,                                            /* SDR参数估计OM REQ */
    NEUN_SDR_HF_BEAM_OM_REQ,                                            /* SDR高频BEAM后处理OM REQ */
    NPHY_CSU_REQ_MSGID_BUTT,
};
typedef uint8_t NPHY_CSU_OmReqMsgIdUint08;

/*
 * Enum Description: OM Rpt MsgId
 */
enum NPHY_CSU_OmRptMsgId {
    NPHY_CSU_RPT_MSGID_START = NPHY_OM_L1MSG_ID(NPHY_MODULE_ID_CSU, 0x0),
    NPHY_CSU_STEP1_RSLT_RPT = NPHY_CSU_RPT_MSGID_START,
    NPHY_CSU_STEP2_RSLT_RPT,
    NPHY_CSU_BBP_ITA_REG_RPT,
    NPHY_CSU_BBP_ITR_REG_RPT,
    NEUN_SDR_TRS_DOPPLER_RPT,                                            /* SDR参数估计OM RPT */
    NEUN_SDR_SSB_DOPPLER_RPT,
    NEUN_SDR_TRMS_DOPPLER_RPT,
    NEUN_SDR_DMRS_DOPPLER_RPT,
    NPHY_SDR_HF_SSB_BEAM_RPT,                                            /* SDR高频BEAM后处理结果上报 */
    NPHY_SDR_HF_CSI_BEAM_RPT,
    NPHY_SDR_INIT_EMU_RPT,
    NPHY_SDR_EMU_PB_CFG_RPT,
    NPHY_CSU_SMP_ISR_CYCLE_RPT,
    NPHY_CSU_HF_SMP_CYCLE_RPT,
    NPHY_CSU_CSIRS_BEAM_CYCLE_RPT,
    NPHY_SDR_HF_BM_SSB_INS_RPT,                                          /* SDR高频SSB BEAM PDE瞬时值结果上报 */
    NPHY_CSU_SMP_RSLT_RPT,
    NEUN_SDR_TASK_LOAD_RPT,
    NPHY_SDR_MERGE_INIT_EMU_RPT,
    NPHY_CSU_IC_RSLT_RPT,
    NPHY_CSU_RPT_MSGID_BUTT,
};
typedef uint8_t NPHY_CSU_OmRptMsgIdUint08;
/*
 * Enum Description: OmReqMsgId
 */
enum LPHY_CSU_OmReqMsgId {
    LPHY_CSU_REQ_MSGID_START = LPHY_OM_REQ_ID(LPHY_MODULE_ID_CSU, 0x0),
    LPHY_CSU_RSLT_OM_REQ = LPHY_CSU_REQ_MSGID_START,
    LPHY_CSU_INITEMU_OM_REQ,
    LPHY_CSU_STOP_SMP_REQ,
    LPHY_CSU_REQ_MSGID_BUTT,
};
typedef uint8_t LPHY_CSU_OmReqMsgIdUint08;

/*
 * Enum Description: OM Rpt MsgId
 */
enum LPHY_CSU_OmRptMsgId {
    LPHY_CSU_RPT_MSGID_START = LPHY_OM_L1MSG_ID(LPHY_MODULE_ID_CSU, 0x0),
    LPHY_CSU_STEP1_RSLT_RPT = LPHY_CSU_RPT_MSGID_START,
    LPHY_CSU_STEP2_RSLT_RPT,
    LPHY_CSU_BBP_ITA_REG_RPT,
    LPHY_CSU_BBP_ITR_REG_RPT,
    LPHY_CSU_CELL_LIST_RPT,
    LPHY_CSU_IC_RSLT_RPT,
    LPHY_CSU_RPT_MSGID_BUTT,
};
typedef uint8_t LPHY_CSU_OmRptMsgIdUint08;

/*
 * 4 Struct definition
 */
/*
 * Struct Description:om ctrl
 */
typedef struct {
    UPHY_OM_ReqEnableUint08 csuStep1Ena;
    UPHY_OM_ReqEnableUint08 csuStep2Ena;
    UPHY_OM_ReqEnableUint08 csuStep1RegEna;
    UPHY_OM_ReqEnableUint08 bandScanEn;
    UPHY_OM_ReqEnableUint08 csuStep2NumEna;
    UPHY_OM_ReqEnableUint08 agcRssiEn;
    UPHY_OM_ReqEnableUint08 sdrcOmEn;
    uint8_t                 resv;
} NEUN_CSU_OmCtrl;

/*
 * Struct Description: om init emu ctrl
 */
typedef struct {
    UPHY_OM_ReqEnableUint08 initEmuEna;
    UPHY_OM_ReqEnableUint08 initCsuEna;
    uint8_t                 resv[2];
    int16_t                 rsrp;
    int16_t                 rsrq;
}NEUN_CSU_OmInitEmuCtrl;

/*
 * Struct Description: OM Req struct
 */
typedef struct {
    uint32_t reqAddr;
    uint32_t reqSize;
} NEUN_CSU_OmReqInfo;

/* 结构说明: CSU step1结果 */
typedef struct {
    uint8_t                          nid2;                                 /* Nid2 */
    uint8_t                          foScanIdx;                            /* 频偏扫档档位索引 */
    uint16_t                          corr;                                 /* 相关峰 */
    int32_t                          ffo;                                  /* step1频偏 */
    uint32_t                          pos;                                  /* step1上报的PSS位置 */
} NEUN_CSU_OmPssInfo;

/* 结构说明: 小区信息 */
typedef struct {
    uint32_t                          outPssSync;                           /* PSS同步位置对应的绝对时标 单位8Ts */
    uint32_t                          pos;                                  /* PSS同步信息,样点 */
    int32_t                          ffo;                                  /* 频偏扫档+step1频偏得到的归一化总频偏 */

    uint16_t                          cellId;                               /* 小区ID */
    uint16_t                          step1Ratio;                           /* S1R */
    uint16_t                          step2Ratio;                           /* S2R */
    uint16_t                          sssRatio;                             /* SSR */

    int16_t                          syncPowRssi;                          /* 时域功率，dB */
    uint8_t                          halfSfnInd;                           /* 前后半帧指示 */
    uint8_t                          foScanIdx;                            /* 频偏档位索引 */
} NEUN_CSU_OmCellInfo;

/*
 * Struct Description: NEUN CSU report step1 OM Info
 */
typedef struct {
    uint8_t                              modemIdx;
    uint8_t                              ccIdx;
    uint8_t                              fcfuChIdx;
    uint8_t                              resv1;
    uint8_t                              workState[UPHY_NUM2];
    uint16_t                             resv2;
    uint32_t                             freqAlm;
    uint32_t                             tsInSubFrm: 16;
    uint32_t                             suFrameNum: 4;
    uint32_t                             frameNum: 10;
    uint32_t                             reserve: 2;
    uint32_t                             sti;
    uint32_t                             ddrDataRxAddr[UPHY_NUM2];
    uint32_t                             nrDdrBitMap;
    uint32_t                             lteDdrBitMap;
    uint32_t                             fcfuDdrBitmap;
    uint32_t                             ccStep1Cnt;
    int16_t                              agcGain[NEUN_CSU_OM_MAX_RX_NUM];
} NEUN_CSU_OmSmpRsltInfo;

/*
 * Struct Description: NEUN CSU report step1 OM Info
 */
typedef struct {
    NEUN_CSU_OmSmpRsltInfo               smpRsltInfo;
    uint8_t                              foScanMode;
    uint8_t                              ratMode;
    uint8_t                              maxChIdx;
    uint8_t                              pssDetNum;
    uint32_t                             freqInfo;
    NEUN_CSU_OmPssInfo                   pssInfo[NEUN_CSU_OM_MAX_PSS_NUM];
} NEUN_CSU_OmStep1RsltRptInfo;

/*
 * Struct Description: NEUNCSU report step2 OM Info
 */
typedef struct {
    uint8_t           modemIdx;
    uint8_t           ccIdx;
    uint8_t           fcfuChIdx;
    uint8_t           detCellNum;
    uint8_t           saturationFlag;
    uint8_t           resv[3];
    uint32_t          freqInfo;
    NEUN_CSU_OmCellInfo cellInfo[NEUN_CSU_OM_MAX_CELL_NUM];
} NEUN_CSU_OmStep2RsltRptInfo;

/*
 * Struct Description: NEUN_CSU_OmStep1BbpRptInfo
 */
typedef struct {
    uint8_t            modemIdx;
    uint8_t            fcfuChIdx;
    uint8_t            resv[2];
    uint32_t           ccStep1Cnt;
    uint32_t           ccStep1State;
    uint32_t           ccIntCnt;
    uint32_t           ccDebugAlm;
    uint32_t           comLineCtrl;
    uint16_t           tsInSubFrm;
    uint16_t           suFrameNum;
} NEUN_CSU_OmStep1RegRptInfo;

/*
 * Struct Description:om ctrl
 */
typedef struct {
    UPHY_OM_ReqEnableUint08 trsDopEna;
    UPHY_OM_ReqEnableUint08 ssbDopEna;
    UPHY_OM_ReqEnableUint08 trmsDopEna;
    UPHY_OM_ReqEnableUint08 dmrsDopEna;
} NEUN_SDR_TspFuncOmCtrl;

/*
 * Struct Description: TRS 的SDR计算任务OM上报结构体
 */
typedef struct {
    uint16_t ccIdx;
    uint16_t resv;
    int32_t  llfCom[NEUN_SDR_TRS_LLF_NUM];    /* 收合并LLF值 */
} NEUN_SDR_TspfuncTrsDopplerRpt;

/*
 * Struct Description: SSB 的SDR计算任务OM上报结构体
 */
typedef struct {
    uint16_t ccIdx;
    uint16_t resv;
    int32_t  mseCom[NEUN_SDR_SSB_MSE_NUM];    /* 收合并MSE值 */
} NEUN_SDR_TspfuncSsbDopplerRpt;

/*
 * Struct Description: TRS 的SDR计算任务OM上报结构体
 */
typedef struct {
    uint16_t ccIdx;
    uint16_t resv;
    int32_t  llf[NEUN_SDR_TRMS_LLF_NUM];    /* LLF值 */
} NEUN_SDR_TspfuncTrmsDopplerRpt;

/*
 * Struct Description: cross result
 */
typedef struct {
    int32_t re;
    int32_t im;
} NEUN_DMRS_CrossD;

/*
 * Struct Description: TRS 的SDR计算任务OM上报结构体
 */
typedef struct {
    uint16_t         ccIdx;
    uint16_t         resv;
    uint8_t          snr[NEUN_SDR_DMRS_RX_NUM];
    uint8_t          shift[NEUN_SDR_DMRS_RX_NUM];
    NEUN_DMRS_CrossD cross[NEUN_SDR_DMRS_RX_NUM][NEUN_SDR_DMRS_CROSS_NUM];
    uint32_t         mse[NEUN_SDR_DMRS_MSE_NUM];
} NEUN_SDR_TspfuncDmrsDopplerRpt;

/*
 * Struct Description:om ctrl
 */
typedef struct {
    UPHY_OM_ReqEnableUint08 ssbBeamEna;
    UPHY_OM_ReqEnableUint08 csiBeamEna;
    UPHY_OM_ReqEnableUint08 ssbInstantEna;
    uint8_t                 rsv;
} NEUN_SDR_BeamOmCtrl;

/*
 * Struct Description:om cycle
 */
typedef struct {
    UPHY_TRACE_Header   header;
    UPHY_TRACE_TaskData data;
}NEUN_CSU_OmCycleInfo;

/*
 * Struct Description:Task load OM Rpt
 */
typedef struct {
    uint8_t             type;
    uint8_t             res[UPHY_NUM3];
    uint32_t            timer[NEUN_SDR_OM_TASKLOAD_LEN]; /* 记录任务各个时刻位置的时间，最大16长度 */
} NEUN_SDR_OmTaskLoadInfo;


typedef struct {
    uint16_t                            cellId;
    uint8_t                             cellSucFlag;
    uint8_t                             cellCpHalfFrame;
    uint8_t                             foscanIdx;
    uint8_t                             res[UPHY_NUM3];

    uint32_t                            pos;
    uint16_t                            step2Ratio;
    uint16_t                            sssRatio;

    int16_t                             step1RsltFfoRpt;
    uint16_t                            step1RsltCorrRpt;

    uint32_t                            ssRx0PowRpt;
    uint32_t                            ssRx1PowRpt;
} NEUN_BGT_CSU_OmStep2CellInfo;


typedef struct {
    uint32_t                            freqInfo;

    uint8_t                             modemIdx;
    uint8_t                             res;
    uint8_t                             schCellNum;
    uint8_t                             detCellNum;

    NEUN_BGT_CSU_OmStep2CellInfo        cellInfo[NEUN_BGT_CSU_MAX_CELL_NUM];
} NEUN_BGT_CSU_OmStep2RptInfo;


#pragma pack(pop)

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* end of __NEUN_CSU_OM_DEF_H__ */

