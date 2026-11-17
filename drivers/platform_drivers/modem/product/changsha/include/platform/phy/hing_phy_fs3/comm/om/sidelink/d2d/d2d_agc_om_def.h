

#ifndef D2D_AGC_OM_DEF_H
#define D2D_AGC_OM_DEF_H

/*
 * 1 其他头文件包含
 */
#include  "neun_agc_om_def.h"
#include  "d2d_basedef_enum.h"
#include  "sll_agc_interface.h"
#include  "uphy_om_interface.h"
#include  "lphy_v2x_hal_feu_interface.h"
#include  "neun_hal_dl_feu_interface.h"
#include  "neun_hal_dl_agc_interface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(push, 4)

/*
 * 2 宏定义
 */
#define D2D_AGC_FIX_GAIN_CNT_COMP                          1
#define D2D_AGC_GAIN_SET_MAX_NUM                           1
#define D2D_AGC_FCFU_GAIN_SET_MAX_NUM                      (D2D_AGC_GAIN_SET_MAX_NUM + 1)
#define D2D_AGC_BBPDMA_CH_NODE_NUM                         (D2D_AGC_FCFU_GAIN_SET_MAX_NUM)
#define D2D_AGC_CC_MAX_CH_NUM                              (LPHY_CAPACITY_MAX_RECV_ANT_NUM >> 1)
#define D2D_AGC_MAX_RX_ANT_NUM                             2
#define D2D_AGC_PSB_SAVE_GAIN_NUM                          160
#define D2D_AGC_ONE_SFRMNUM                                10
#define D2D_AGC_INTRA_RSSI_BUF_NUM                         2
#define D2D_AGC_AAGC_STUB_GAIN                             672
#define D2D_AGC_COMP_LMT                                   144
#define D2D_AGC_CSU_GAIN_TYPE                              15 /* init cs 时，不进行快调，认为4bit都为1 */
#define D2D_AGC_CSU_GAIN_TYPE_SHIFT                        3 /* [3:0]对应post_cs, post_sm, post_df, pre */
#define D2D_AGC_DFU_GAIN_TYPE_SHIFT                        1 /* [3:0]对应post_cs, post_sm, post_df, pre */
#define D2D_AGC_WB_RSSI_SYM_START                          1
#define D2D_AGC_WB_RSSI_SYM_NUM                            7

/*
 * 3 枚举定义
 */
/*
 * 枚举说明: OM上报消息
 */
enum D2D_AGC_OmRptMsg {
    D2D_AGC_PWR_RPT = D2DPHY_OM_L1MSG_ID(D2DPHY_MODULE_ID_AGC, 0x00),
    D2D_AGC_RSSI_RPT,
    D2D_AGC_WBRSSI_RPT,
    D2D_AGC_TRACE_LOG_RPT,
    D2D_AGC_CS_RSSI_RPT,
    D2D_AGC_DFU_CC_TRACE_RPT,
    D2D_AGC_OM_RPT_BUTT
};
typedef uint8_t D2D_AGC_OmRptMsgUint08;

/*
 * 枚举说明: agc 工作模式
 */
enum D2D_AGC_WorkModeReq {
    /* MODE REQ */
    D2D_AGC_NULL_MODE = 0,             /* 无效mode，维持上一次mode */
    D2D_AGC_STOP_MODE,                 /* 停止工作请求 */
    D2D_AGC_INIT_CS_MODE,              /* 初搜模式 */
    D2D_AGC_CONN_MODE,                 /* 连接态模式 */
    D2D_AGC_PERIOD_CS_START_ACTION,    /* 周期搜 start 记录增益开始 */
    D2D_AGC_PERIOD_CS_END_ACTION,      /* 周期搜 end 记录增益结束 */
    D2D_AGC_MODE_BUTT
};
typedef uint8_t D2D_AGC_WorkModeReqUint08;

/*
 * 枚举说明: AGC周期
 */
enum D2D_AGC_Period {
    D2D_AGC_PERIOD_1MS     = 1,
    D2D_AGC_PERIOD_5MS     = 5,
    D2D_AGC_PERIOD_BUTT
};
typedef uint8_t D2D_AGC_PeriodUint08;

/*
 * 6 STRUCT定义
 */
typedef struct {
    NEUN_AGC_AntGain                antGain[D2D_AGC_MAX_RX_ANT_NUM];
    int16_t                         lastAagcGain[D2D_AGC_MAX_RX_ANT_NUM];
} D2D_AGC_GainInfo;

typedef struct {
    NEUN_AGC_AntPwr                     antPwr[D2D_AGC_MAX_RX_ANT_NUM];
    D2D_AGC_GainInfo               gainInfo;
} D2D_AGC_CcCalcInfo;

/* CC频点信息 */
typedef struct {
    uint32_t                             freq;
    uint16_t                             band;
    uint8_t                              rsv[UPHY_NUM2];
    uint32_t                             time;
} D2D_AGC_CcInfoBackup;

/*
 * 结构说明:  带宽变化
 */
typedef struct {
    NEUN_BAND_WidthUint08                   rfBw;
    uint8_t                                 rsv[UPHY_NUM3];
    NEUN_AGC_PostChInfo                     postChInfo[NEUN_FCFU_CH_BUTT];
} D2D_AGC_BwChange;

typedef struct {
    uint16_t                                cellId;
    uint8_t                                 modemIdx;
    uint8_t                                 rxAntNum;              /* 天线数 */
    uint32_t                                freq;                  /* 频点 */
    D2D_AGC_BwChange                   bwInfo;
    NEUN_CP_TypeUint08                      cpType;
    uint8_t                                 chNum;
    NEUN_LTE_TddUdCfgUint08                 udCfg;
    uint8_t                                 fastAdjMode;
    uint8_t                                 bbpCcIdx;
    uint8_t                                 rsv[UPHY_NUM3];
} D2D_AGC_CcInfo;

/*
 * 结构说明: DL CC控制信息
 */
typedef union {
    struct {
        uint32_t                            periodPsbTask                  : 1;
        uint32_t                            rssiTask                       : 1;

        uint32_t                            rsv                            : 30;
    } bits;
    uint32_t                                ctrlInfo;
} D2D_AGC_DlCtrlInfo;

/*
 * 结构说明: 同频控制参数
 */
typedef union {
    struct {
        uint32_t                            rssiReq                        : 1;
        uint32_t                            periodPsbReq                   : 1;
        uint32_t                            gainReq                        : 1;
        uint32_t                            rsv                            : 29;
    } bits;
    uint32_t                                reqInfo;
} D2D_AGC_DlReqCtrl;

/*
 * 结构说明: MBX H2L
 */
typedef struct {
    D2D_L1cL1dMsgTypeUint32            msgId;
    D2D_AGC_CcInfo                     ccInfo;
    D2D_AGC_DlCtrlInfo                 dlCtrl;
    D2D_AGC_DlReqCtrl                  reqCtrl;
    int16_t                            aagcGain[D2D_AGC_MAX_RX_ANT_NUM];
} D2D_AGC_Send2DlInfo;

/*
 * 结构说明: L->H CTRL
 */
typedef union {
    uint32_t                             rptInfo;
    struct {
        uint32_t                         pwrValid            : 1;
        uint32_t                         rssiBufAddrValid    : 1;
        uint32_t                         rsv                 : 30;
    } bits;
} D2D_AGC_DlRptInfo;

/*
 * 结构说明: rssi地址
 */
typedef struct {
    uint8_t                                 rxAntNum;
    uint8_t                                 rsv;
    uint16_t                                cellId;
    uint32_t                                freq;
} D2D_AGC_DlRptCcInfo;

/*
 * 结构说明: wb上报增益及子帧号信息
 */
typedef struct {
    NEUN_AGC_WbSlotGain                      slotGain;
    uint32_t                                 rptTime;
    uint8_t                                  sfrmPwrValid;
    uint8_t                                  resv[UPHY_NUM3];
} D2D_AGC_WbSfrmInfo;

/*
 * 结构说明: LL1C上报给HL1C的计算结果
 */
typedef struct {
    D2D_L1cL1dMsgTypeUint32                msgId;
    D2D_AGC_DlRptInfo                      rptInfo;
    int16_t                                demPostGain[D2D_AGC_MAX_RX_ANT_NUM];
    NEUN_AGC_AntPwr                        antPwr[D2D_AGC_MAX_RX_ANT_NUM];
    D2D_AGC_DlRptCcInfo                    rptCcInfo;
    SLL_FEU_CfgDaeAddrInfo                 rssiAddr;
    SLL_FEU_CfgDaeAddrInfo                 traceLogAddr;
    D2D_AGC_WbSfrmInfo                     rptWbSfrmInfo;
} D2D_AGC_DlRpt;

/*
 * 结构说明: 功率上报
 */
typedef struct {
    uint8_t                             antNum;
    uint8_t                             rsv[UPHY_NUM3];
    int16_t                             prePwr[D2D_AGC_MAX_RX_ANT_NUM];
    int16_t                             postPwr[D2D_AGC_MAX_RX_ANT_NUM];
} D2D_AGC_PwrRttOm;

/*
 * 结构说明: WB RSSI储存 按照FPU_符号_ANT 存放
 */
typedef struct {
    uint32_t                        rptTime;
    SLL_AGC_WbRssiBuf               wbRssiSym;
} D2D_AGC_WbRssiData;

/*
 * 结构说明: WB RSSI控制
 */
typedef struct {
    uint32_t                      dlRptTime;
    NEUN_AGC_WbSlotGain           slotGain;
    NEUN_AGC_WbRssiCalc           wbCalcInfo;
    D2D_AGC_WbRssiData       wbRssiData;
} D2D_AGC_WbRssiCtrl;

/*
 * 结构说明: WBRSSI上报
 */
typedef struct {
    D2D_AGC_WbRssiCtrl             wbRssiCtrl;
    uint8_t                             interfInd[D2D_AGC_MAX_RX_ANT_NUM];
    uint8_t                             rsv[UPHY_NUM2];
} D2D_AGC_WbRssiOm;

#pragma pack(pop)


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* end of lphy_v2x_agc_om_def.h */
