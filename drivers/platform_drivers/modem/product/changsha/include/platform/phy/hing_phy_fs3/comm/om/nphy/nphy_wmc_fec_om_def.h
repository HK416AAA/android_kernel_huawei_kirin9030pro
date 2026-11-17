

#ifndef __NPHY_WMC_FEC_OM_DEF_H__
#define __NPHY_WMC_FEC_OM_DEF_H__

/*
 * 1 其他头文件包含
 */
#include "uphy_typedef.h"
#include "neun_basedef_enum.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(push, 4)

/*
 * 3 枚举定义
 */
enum NPHY_FEC_WorkModeReq {
    NPHY_FEC_NULL_MODE          = 0,    /* 无效mode，维持上一次mode */
    NPHY_FEC_OFF_MODE           = 1,
    NPHY_FEC_HOLD_MODE          = 2,
    NPHY_FEC_INTRAON_MODE       = 3,
    NPHY_FEC_BANDSCAN_MODE      = 4,
    NPHY_FEC_CELLSRCH_MODE      = 5,
    NPHY_FEC_BCH_MODE           = 6,
    NPHY_FEC_NONBLINDHO_MODE    = 7,    /* 该模式表示最后一个同频工作模式，用来对mode进行分隔 */
    NPHY_FEC_INTERON_MODE       = 8,    /* 该模式表示最后一个异频工作模式，用来对mode进行分隔 */
    NPHY_FEC_IRATON_MODE        = 9,    /* 该模式表示最后一个异系统工作模式，用来对mode进行分隔 */
    NPHY_FEC_SLAVEMEAS_MODE     = 10,   /* 该模式表示最后一个从模测量工作模式，用来对mode进行分隔 */
    NPHY_FEC_SLAVEBANDSCAN_MODE = 11,
    NPHY_FEC_SLAVECELLSRCH_MODE = 12,
    NPHY_FEC_SLAVEPBCH_MODE     = 13,
    NPHY_FEC_SLAVESIB_MODE      = 14,
    NPHY_FEC_MODE_BUTT
};
typedef uint8_t NPHY_FEC_WorkModeReqUint08;

enum NPHY_FEC_ActionReq {
    NPHY_FEC_NULL_ACTION = 0, /* 无效ACTION */
    NPHY_FEC_SCELLCFG_ACTION,
    NPHY_FEC_SCELLDECFG_ACTION,
    NPHY_FEC_SSB_UPDATE_ACTION,
    NPHY_FEC_DEM_UPDATE_ACTION,
    NPHY_FEC_MEAS_UPDATE_ACTION,
    NPHY_FEC_ACTION_BUTT
};
typedef uint8_t NPHY_FEC_ActionReqUint08;

typedef enum {
    NPHY_FED_PUB_EFFECT_MODE_IMME = 0,
    NPHY_FED_PUB_EFFECT_MODE_ABS,
    NPHY_FED_PUB_EFFECT_MODE_BUTT
} NPHY_FED_PubEffectMode;
typedef uint8_t  NPHY_FED_PubEffectModeUint08;

typedef enum {
    NPHY_FED_CFU_EFFECT_MODE_IMME = 0,
    NPHY_FED_CFU_EFFECT_MODE_DEM_TIMING,
    NPHY_FED_CFU_EFFECT_MODE_MC_TIMING,
    NPHY_FED_CFU_EFFECT_MODE_ABS_TIMING,
    NPHY_FED_CFU_EFFECT_MODE_BUTT
} NPHY_FED_CfuEffectMode;
typedef uint8_t  NPHY_FED_CfuEffectModeUint08;

typedef enum {
    NPHY_FED_TIME_RXON = 0,             /* 正常场景的RXON, 本频开 */
    NPHY_FED_TIME_RXOFF,                /* 正常场景的RXON, 本频关 */

    NPHY_FED_TIME_GAP_INTER_RXON,        /* GAP场景进沟，异频开 */
    NPHY_FED_TIME_GAP_INTER_RXOFF,       /* GAP 场景出沟，异频关 */
    NPHY_FED_TIME_GAP_INTRA_RXON,        /* GAP场景出沟，本频开 */
    NPHY_FED_TIME_GAP_INTRA_RXOFF,       /* GAP场景进沟，本频关 */

    NPHY_FED_TIME_SMTC_INTER_RXON,       /* SMTC场景进沟，异频开 */
    NPHY_FED_TIME_SMTC_INTER_RXOFF,      /* SMTC场景出沟，异频关 */
    NPHY_FED_TIME_SMTC_INTRA_RXON,       /* SMTC场景出沟，本频开 */
    NPHY_FED_TIME_SMTC_INTRA_RXOFF,      /* SMTC场景进沟，本频关 */

    NPHY_FED_TIME_SLAVE_MEAS_RXON,       /* 从模进沟场景，打开从模 */
    NPHY_FED_TIME_SLAVE_MEAS_RXOFF,      /* 从模进沟场景，打开从模 */

    NPHY_FED_TIME_CALC_SCENARIO_BUTT
} NPHY_FED_TimeCalcScenario;
typedef uint8_t NPHY_FED_TimeCalcScenarioUint08;

/*
 * 6 STRUCT定义
 */
typedef struct {
    uint8_t                                  ucFpuRstFlag;           /* CC 的FPU复位切定时标志 */
    uint8_t                                  ucBlindTimeSwitchFlag;  /* bandscan或者小区初搜时盲切定时标志 */
    uint8_t                                  ucSsbSwitchFlag;  /* 根据SSB/DEM通路参数变化判断公共模块模式是否重新发送 */
    uint8_t                                  ucDemSwitchFlag;  /* 根据SSB/DEM通路参数变化判断公共模块模式是否重新发送 */

    uint8_t                                  ucMeasSwitchFlag;  /* 根据SSB/DEM通路参数变化判断公共模块模式是否重新发送 */
    uint8_t                                  ucRsv1[3];
} NPHY_TRU_Flag;

#pragma pack(pop)

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
