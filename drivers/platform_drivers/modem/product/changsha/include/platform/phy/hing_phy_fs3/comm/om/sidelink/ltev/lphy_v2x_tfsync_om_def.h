

#ifndef __LPHY_V2X_TFSYNC_OM_DEF_H__
#define __LPHY_V2X_TFSYNC_OM_DEF_H__
/*
 * 1 其他头文件包含
 */
#include "vrrc_vphy_interface.h"
#include "neun_afc_interface.h"
#include "neun_tru_om_def.h"
#include "uphy_las_gnss_interface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/*
 * 枚举说明: 温补周期启动类型
 */
enum LPHY_V2X_TcPeriodType {
    V2XPHY_AFC_PERIOD_TYPE_COMP = 0,
    V2XPHY_AFC_PERIOD_TYPE_SAMPLE,
    V2XPHY_AFC_PERIOD_TYPE_BUTT
};
typedef uint8_t LPHY_V2X_TcPeriodTypeUint08;

/*
 * 枚举说明: abs/utc 时间信息队列索引
 */
enum LPHY_V2X_GnssTimeQueue {
    TIME_QUEUE_CURRENT = 0,
    TIME_QUEUE_LAST,
    TIME_QUEUE_BUTT
};
typedef uint8_t LPHY_V2X_GnssTimeQueueUint08;

/*
 * 枚举说明: GNSS信号接收状态
 */
enum LPHY_V2X_RcvUtcPps {
    GNSS_RECEIVE_READY = 0,
    GNSS_RECEIVE_SUCC,
    GNSS_RECEIVE_BUTT
};
typedef uint32_t LPHY_V2X_RcvUtcPpsUint32;


/* 枚举说明: GNSS状态 */
enum LPHY_V2X_GnssState {
    GNSS_INIT_SYS_STATE0 = 0,
    GNSS_INIT_SYS_STATE1,
    GNSS_TRACE_STATE,
    GNSS_STATE_INVALID_WORD
};
typedef uint32_t LPHY_V2X_GnssStateUint32;

/*
 * 枚举说明: GNSS错误码
 */
enum  LPHY_V2X_GnssErrCode {
    LPHY_V2X_GNSS_VALID = 0,
    LPHY_V2X_PPS_UTC_FLAG_INVALID,
    LPHY_V2X_UTC_PERIOD_INVALID,
    LPHY_V2X_ABS_TIME_INVALID,
    LPHY_V2X_SNR_INVALID,
    LPHY_V2X_LOST_UTC,
    LPHY_V2X_LOST_PPS,
    LPHY_V2X_UTC_MORETHAN_500MS,
    LPHY_V2X_STEP1_FAIL,
    LPHY_V2X_CURRENT_PPS_INVALID,
    LPHY_V2X_BUTT
};
typedef uint32_t LPHY_V2X_GnssErrCodeUint32;

/*
 * 4 STRUCT定义
 */
/*
 * 结构说明: abs
 */
typedef struct {
    uint32_t sysFrmNum;
    uint32_t subFrmNum;
    uint32_t tsNum;

    uint32_t absTimeTs;
    uint32_t validFlg;
} LPHY_V2X_GnssAbsTime;

typedef struct {
    uint8_t                  tgap;
    uint8_t                  rcvPpsFlag;
    uint16_t                 bbpSfn;
    LPHY_V2X_RcvUtcPpsUint32 gnssPpsRcvState;
    LPHY_V2X_GnssAbsTime     absTime[TIME_QUEUE_BUTT];
} LPHY_V2X_GnssPpsPara;

/*
 * 结构说明: utc
 */
typedef struct {
    uint32_t validFlg;
    uint32_t utcCalendarTime;
} LPHY_V2X_GnssCalendarTime;

typedef struct {
    int32_t                    period2Utc;
    LPHY_V2X_RcvUtcPpsUint32   utcRevState;
    LPHY_V2X_GnssCalendarTime  utcTime[TIME_QUEUE_BUTT];
} LPHY_V2X_GnssUtcPara;

typedef struct {
    uint64_t        timestamp_32k;
    uint64_t        timeStamp;
    uint32_t        numOfSatellites;  /* 可视卫星数量 */
    int32_t         leapSecond;
    GnssSysInfo     sysInfo[VRRC_VPHY_MAX_SATNUM]; /* GNSS系统类型及对应信噪比 */
} LPHY_V2X_SystemPara;

/*
 * 结构说明: timer
 */
typedef struct {
    uint32_t gnss500msTimer;
    uint32_t gnss1sTimer;
    uint32_t gnss5sTimer;
    uint32_t gnss1ppsIntTimer;
    uint32_t gnss12sTimer;
} LPHY_V2X_GnssTimerPara;

/*
 * 结构说明: om
 */
typedef struct {
    LPHY_V2X_GnssStateUint32   state;
    LPHY_V2X_GnssErrCodeUint32 errCode;
} LPHY_V2X_GnssErrorOmInfo;

typedef struct {
    LPHY_V2X_GnssStateUint32     gnssState;
    LPHY_V2X_SystemPara    systemPara;
    LPHY_V2X_GnssPpsPara   ppsPara;
    LPHY_V2X_GnssUtcPara   utcPara;
    LPHY_V2X_GnssTimerPara timerPara;
    int32_t deltaN;
} LPHY_V2X_GNSS_Handle;

/* 温补周期相关记录 */
typedef struct {
    uint32_t periodCount; /* 计时器，每次符号2中断增加一次 */
    uint32_t periodThrd;  /* 定时器超时门限，GNSS为500ms，清除样本为50ms，SELF为500ms */
    uint32_t periodFlag;  /* 当前定时器是否启动 */
} LPHY_V2X_TcPeriodInfo;

/*
 * 结构说明: temperature
 */
typedef struct {
    uint8_t               temperatureSw;
    uint8_t               rsv[3];

    NPHY_AFC_TempComp     backTempComp;
    LPHY_V2X_TcPeriodInfo periodInfo[V2XPHY_AFC_PERIOD_TYPE_BUTT];
} LPHY_V2X_CompPara;

/*
 * 结构说明: 计算结果
 */
typedef struct {
    uint16_t gnssSfn;
    uint8_t  sysTimeSw;
    uint8_t  waitSwitch;
    uint32_t gnssSyncPos;

    int32_t  curPpm;
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
} LPHY_V2X_TfSyncCalcPara;

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
    LPHY_V2X_TfSyncCalcPara    calcPara;
    LPHY_V2X_TfSyncCalcPara    setPara;
} LPHY_V2X_SyncModeInterface;

/*
 * 结构说明: om 接口
 */
typedef struct {
    LPHY_V2X_SyncModeInterface gnssInfo;
} LPHY_V2X_TFSYNC_GnssCalc;

typedef struct {
    LPHY_V2X_CompPara tcInfo;
} LPHY_V2X_TFSYNC_TcInfo;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
