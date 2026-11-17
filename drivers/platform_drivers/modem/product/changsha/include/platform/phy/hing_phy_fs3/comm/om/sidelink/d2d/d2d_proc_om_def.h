
#ifndef __D2D_PROC_OM_DEF_H__
#define __D2D_PROC_OM_DEF_H__


/*
 * 1 其他头文件包含
 */
#include "uphy_typedef.h"
#include "uphy_om_interface.h"
#include "d2d_proc_om_def.h"
#include "d2d_basedef_enum.h"
#include "d2d_hl1c_basedef_struct.h"
#include "hid2d_l2_phy_interface.h"
// 增加d2d头文件包含

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

/*
 * 2 宏定义
 */
/*
 * 3 枚举定义
 */
/*
 * 枚举说明: 上报所需要的MsgID，可以直接使用，不需要转换
 * DSP->HDIS
 */
enum D2D_PROC_PhyRrcOmRpt {
    HRRC_HPHY_ACTIVE_IND = D2DPHY_OM_L1MSG_ID(D2DPHY_MODULE_ID_PROC, 0x00),    /* wait */
    HPHY_HRRC_SYSTEM_PARA_CONFIG_CNF,                                          /* HPHY_HRRC_SystemParaConfigCnf */
    HPHY_HRRC_HBCCH_DATA_CNF,                                                  /* HPHY_HRRC_HbcchDataCnf */
    HPHY_HRRC_HBCCH_DATA_IND,                                                  /* HPHY_HRRC_HbcchDataInd */
    HPHY_HRRC_SET_WORK_MODE_CNF,                                               /* HPHY_HRRC_SetWorkModeCnf */
    HPHY_HRRC_D2D_DL_OUT_OF_SYNC_IND,                                          /* HPHY_HRRC_DlOutOfSyncInd */
    HPHY_HRRC_D2D_SYNC_SRC_CONFIG_CNF,                                         /* HPHY_HRRC_SyncSrcConfigCnf */
    HPHY_HRRC_D2D_INIT_SEARCH_CNF,                                             /* HPHY_HRRC_InitSearchCnf */
    HPHY_HRRC_D2D_INIT_SEARCH_IND,                                             /* HPHY_HRRC_InitSearchInd */
    HPHY_HRRC_D2D_LPC_SEARCH_CNF,                                              /* HPHY_HRRC_LpcSearchCnf */
    HPHY_HRRC_D2D_LPC_SEARCH_IND,                                              /* HPHY_HRRC_LpcSearchInd */
    HPHY_HRRC_D2D_LPC_SEARCH_STOP_CNF,                                         /* HPHY_HRRC_LpcSearchStopCnf */
    HPHY_HRRC_D2D_PERIOD_SEARCH_CNF,                                           /* HPHY_HRRC_PeriodSearchCnf */
    HPHY_HRRC_D2D_PERIOD_SEARCH_IND,                                           /* HPHY_HRRC_PeriodSearchInd */
    HPHY_HRRC_D2D_PERIOD_SEARCH_STOP_CNF,                                      /* HPHY_HRRC_PeriodSearchStopCnf */
    HPHY_HRRC_D2D_RA_IND,                                                      /* HPHY_HRRC_RaInd */
    HPHY_HRRC_D2D_REF_UE_SIGNAL_QUALITY_IND,                                   /* HPHY_HRRC_RefUeSignalQualityInd */
    HPHY_HL2_D2D_CC_ID_SET,                                                    /* HPHY_HL2_CoreIdSetIndMsg */
    HPHY_HL2_D2D_PSSCH_MEAS_IND,                                               /* HPHY_HL2_PsschMeasMsg */
    HPHY_HRRC_SET_TX_POWER_CNF,                                                /* wait 0x37385017 */
    D2D_SYNC_SOURCE_EXP_INFO,                                                  /* D2D_PROC_SyncSoExpOmInfo 0x3738501F */
    HRRC_HPHY_OM_RPT_BUTT = D2DPHY_OM_L1MSG_ID(D2DPHY_MODULE_ID_PROC, 0x80)
};

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
    uint8_t                        searchMode     : 2; /* 搜索模式 */
    uint8_t                        scanIdx        : 5;
    uint8_t                        rsv            : 1;

    uint8_t                        rsv1;

    uint16_t                       nextStartPos;        /* BGS采数开始位置 */
    uint16_t                       slssIdInd;
    uint16_t                       startTxPos;          /* 本轮周期搜恢复发送的时间 */
    uint16_t                       lPeriodLen;          /* 一个长周期的长度：ms */
    uint8_t                        smpLen;              /* 本轮周期搜的完整采数子帧，160ms/pms */
    uint8_t                        lDurStart;           /* L-Duration开始位置 */
    uint8_t                        mod1RandPeriod;      /* MOD1 随机值*/
    uint8_t                        rsv2[3];
} D2D_PROC_BgsOmRptInfo;
/* D2D背景搜索OM上报信息 */
typedef struct {
    uint8_t                            valBitmap;     /* arbiter中的有效bitmap，task apply时对应task的bit位置1，logout置0 */
    uint8_t                            reqBitmap;     /* arbiter中的请求bitmap，task apply时对应task的bit位置1，下子帧激活时置0 */
    uint8_t                            actBitmap;     /* arbiter中的激活bitmap，task apply时对应task的bit位置1，去激活时置0 */
    uint8_t                            waitActBitmap; /* arbiter中的等待激活bitmap，task apply时对应task的bit位置1，去激活时置0 */
    uint16_t                           actSfnPos;
    D2D_PROC_CsuTaskUint08             csuTaskId;
    uint8_t                            rsv;
} D2D_PROC_CsuArbOmRptInfo;
/* 新增OM消息结构体，上报CSU ARB信息 */

typedef struct {
    uint32_t phySubFrmNum;
    int32_t pssOffset;
} D2D_PROC_SinglePssOmInfo;

typedef struct {
    uint32_t currSti;
    uint32_t lastSti;
    uint32_t pssNum;
    D2D_PROC_SinglePssOmInfo singlePssInfo[2];  /* 最多2个 */
} D2D_PROC_OneSyncSoExpInfo;

typedef struct {
    D2D_PROC_OneSyncSoExpInfo  syncSoExpInfo[16];  /* 最多16个同步源 */
} D2D_PROC_SyncSoExpOmInfo;

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
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __D2D_PROC_OM_DEF_H__ */

