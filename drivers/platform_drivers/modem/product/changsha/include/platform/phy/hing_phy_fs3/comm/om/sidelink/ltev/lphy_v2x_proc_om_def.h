
#ifndef __LPHY_V2X_PROC_OM_DEF_H__
#define __LPHY_V2X_PROC_OM_DEF_H__


/*
 * 1 其他头文件包含
 */
#include "uphy_typedef.h"
#include "uphy_om_interface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
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
enum LPHY_V2X_PROC_PhyRrcOmRpt {
    VRRC_VPHY_ACTIVE_IND = LVPHY_OM_L1MSG_ID(LVPHY_MODULE_ID_PROC, 0x00), /* wait */
    VPHY_VRRC_SYSTEM_PARA_CNF,                     /* VRRC_VPHY_V2xSystemParaCnf */
    VPHY_VRRC_RES_POOL_CONFIG_CNF,                 /* VRRC_VPHY_V2xResPoolConfigCnf */
    VPHY_VRRC_KICKOFF_CNF,                         /* VRRC_VPHY_V2xSetWorkModeCnf */
    VPHY_VRRC_SET_WORK_MODE_CNF,                   /* wait */
    VPHY_VRRC_GNSS_STATE_CNF,                      /* wait */
    VPHY_VRRC_V2X_STATISTICS_CNF,
    VPHY_VRRC_V2X_STATISTICS_CLEAR_CNF,
    VPHY_VRRC_V2X_SNRRSRP_CNF,
    VPHY_VRRC_V2X_PC5SYN_CNF,
    VPHY_VRRC_V2X_LOG_IND,
    VPHY_VRRC_V2X_RSSI_CNF,
    VPHY_VRRC_V2X_INIT_SEARCH_START_CNF,           /* VRRC_VPHY_V2xInitSearchStartCnf */
    VPHY_VRRC_V2X_INIT_SEARCH_STOP_CNF,            /* VRRC_VPHY_V2xInitSearchStopCnf */
    VPHY_VRRC_V2X_INIT_SEARCH_RSLT_IND,            /* VRRC_VPHY_V2xInitSearchRsltInd */
    VPHY_VRRC_V2X_PERIOD_SEARCH_START_CNF,         /* VRRC_VPHY_V2xPeriodSearchStartCnf */
    VPHY_VRRC_V2X_PERIOD_SEARCH_STOP_CNF,          /* VRRC_VPHY_V2xPeriodSearchStopCnf */
    VPHY_VRRC_V2X_PERIOD_SEARCH_RSLT_IND,          /* VRRC_VPHY_V2xPeriodSearchRsltInd */
    VPHY_VRRC_V2X_SYNC_SOURCE_HO_CNF,              /* VRRC_VPHY_V2xSyncSourceHoCnf */
    VPHY_VRRC_V2X_PC5SYN_IND,                      /* wait */
    VPHY_VRRC_UTC_RESET_CNF,                       /* wait */
    VPHY_VMAC_V2X_REC_RPT,                         /* LPHY_V2X_MAC_RecMsg 0x37385015 */
    VPHY_V2X_PROC_INIT_SETUP_REQ,                  /* wait 0x37385016 */
    VPHY_VRRC_SET_TX_POWER_CNF,                    /* wait 0x37385017 */
    VPHY_VRRC_V2X_1PPS_STATUS_IND,                 /* VRRC_VPHY_V2x1ppsStatusInd 0x37385018 */
    VPHY_VMAC_V2X_PSSCH_START_REQ,                 /* VPHY_VMAC_PsschStartReq 0x37385019 */
    VPHY_VMAC_V2X_PSSCH_STOP_REQ,                  /* VPHY_VMAC_PsschStopReq 0x3738501A */
    VPHY_VRRC_V2X_GNSS_SYNC_RSLT_IND,              /* VRRC_VPHY_V2xGnssSyncRsltInd */
    LPHY_V2X_BGS_PROCESS_INFO,                     /* LPHY_V2X_PROC_BgsOmRptInfo 0x3738501C */
    LPHY_V2X_SYNC_SOURCE_EXP_INFO,                 /* LPHY_V2X_PROC_SyncSoExpOmInfo 0x3738501F */
    VRRC_VPHY_OM_RPT_BUTT = LVPHY_OM_L1MSG_ID(LVPHY_MODULE_ID_PROC, 0x80)
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
    uint32_t startSmpSysFn :10;
    uint32_t startSmpSubFn :4;
    uint32_t searchMode    :2;
    uint32_t randPeriod    :4;
    uint32_t isLogPeriod   :1;
    uint32_t currentFoId   :5;
    uint32_t stopFlag      :1;
    uint32_t rsvd          :5;
} LPHY_V2X_PROC_BgsOmRptInfo;

typedef struct {
    uint32_t phySubFrmNum;
    int32_t pssOffset;
} LPHY_V2X_PROC_SinglePssOmInfo;

typedef struct {
    uint32_t currSti;
    uint32_t lastSti;
    uint32_t pssNum;
    LPHY_V2X_PROC_SinglePssOmInfo singlePssInfo[2];  /* 最多2个 */
} LPHY_V2X_PROC_OneSyncSoExpInfo;

typedef struct {
    LPHY_V2X_PROC_OneSyncSoExpInfo  syncSoExpInfo[16];  /* 最多16个同步源 */
} LPHY_V2X_PROC_SyncSoExpOmInfo;

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

#endif /* __LPHY_V2X_PROC_OM_DEF_H__ */

