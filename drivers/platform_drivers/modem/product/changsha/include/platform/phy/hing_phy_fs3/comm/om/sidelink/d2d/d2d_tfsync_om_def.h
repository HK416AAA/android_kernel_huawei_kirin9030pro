

#ifndef __D2D_TFSYNC_OM_DEF_H__
#define __D2D_TFSYNC_OM_DEF_H__
/*
 * 1 其他头文件包含
 */
#include "vrrc_vphy_interface.h"
#include "hsync_hphy_hid2d_interface.h"
#include "neun_afc_interface.h"
#include "neun_tru_om_def.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/*
 * 枚举说明: 温补周期启动类型
 */
enum D2D_TcPeriodType {
    D2D_AFC_PERIOD_TYPE_COMP = 0,
    D2D_AFC_PERIOD_TYPE_SAMPLE,
    D2D_AFC_PERIOD_TYPE_BUTT
};
typedef uint8_t D2D_TcPeriodTypeUint08;

/* 温补周期相关记录 */
typedef struct {
    uint32_t periodCount; /* 计时器，每次符号2中断增加一次 */
    uint32_t periodThrd;  /* 定时器超时门限，GNSS为500ms，清除样本为50ms，SELF为500ms */
    uint32_t periodFlag;  /* 当前定时器是否启动 */
} D2D_TcPeriodInfo;

/*
 * 结构说明: temperature
 */
typedef struct {
    uint8_t               temperatureSw;
    uint8_t               rsv[3];

    NPHY_AFC_TempComp     backTempComp;
    D2D_TcPeriodInfo periodInfo[D2D_AFC_PERIOD_TYPE_BUTT];
} D2D_CompPara;

/*
 * 结构说明: 计算结果
 */
typedef struct {
    uint16_t gnssSfn;
    uint8_t  sysTimeSw;
    uint8_t  rsv;
    uint32_t gnssSyncPos;

    int32_t  pmm;               /* 量纲2^32 */
    int32_t  freqRatio;
    int32_t  phaseDelta;
    int32_t  deltaLoopFilter;
    int32_t  backFreqRatio;

    NEUN_TRU_TimeCfgTypeUint08 truCfgType;
    NEUN_AFC_TpaCfgTypeUint08  afcCfgType;
    uint8_t updataTru;
    uint8_t updataAfc;

    VRRC_VPHY_1ppsStatusTypeUint8 ppsStatusToRrc;
    uint8_t switchValid;
    uint8_t updataTcAfc;
    uint8_t reCfgSfn;
} D2D_TfSyncCalcPara;

/*
 * 结构说明: gnss 接口
 */
typedef struct {
    VRRC_VPHY_SyncSrcTypeUint8 syncSrcType;
    uint8_t                    gnss5sTimerStart;
    uint8_t                    ho12sTimerStart;
    uint8_t                    rsv1;
    uint16_t                   opId;
    uint16_t                   rsv2;
    D2D_TfSyncCalcPara    calcPara;
    D2D_TfSyncCalcPara    setPara;
} D2D_SyncModeInterface;

/*
 * 结构说明: om 接口
 */
typedef struct {
    D2D_SyncModeInterface gnssInfo;
} D2D_TFSYNC_GnssCalc;

typedef struct {
    D2D_CompPara tcInfo;
} D2D_TFSYNC_TcInfo;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
