

/*
 * 1 其他头文件包含
 */
#ifndef __LPHY_V2X_TRU_OM_DEF_H__
#define __LPHY_V2X_TRU_OM_DEF_H__

#include  "lphy_v2x_basedef_struct.h"
#include  "uphy_om_interface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(push, 4)

/*
 * 3 枚举定义
 */
enum LPHY_V2X_TRU_WorkMode {
    LPHY_V2X_TRU_NULL_MODE                      = 0, /* 无效mode，维持上一次mode */
    LPHY_V2X_TRU_STOP_MODE                      = 1, /* 停止，进连接态 */
    LPHY_V2X_TRU_SWITCH_MODE                    = 2, /* 切换，启动周期测量 */
    LPHY_V2X_TRU_RUN_MODE                       = 3, /* 启动，停止周期测量 */
    LPHY_V2X_TRU_MODE_BUTT,
};

typedef uint8_t LPHY_V2X_TRU_WorkModeReqUint08;

/*
 * 枚举说明: OM REQ ID
 */
enum LPHY_V2X_TRU_REQ_MSG {
    LPHY_V2X_TRU_REQ_MSG_INFO = LVPHY_OM_REQ_ID(LVPHY_MODULE_ID_TRU, 0x01),
};
typedef uint32_t LPHY_V2X_TRU_OmReqIdUint32;

/*
 * 枚举说明: OM 上报 ID
 */
enum LPHY_V2X_TRU_IND_MSG {
    LPHY_V2X_TRU_SWITCH_INFO = LVPHY_OM_L1MSG_ID(LVPHY_MODULE_ID_TRU, 0x01),
    LPHY_V2X_TRU_LOOP_INFO,
};
typedef uint32_t LPHY_V2X_TRU_OmInfoIdUint32;

/*
 * 4 STRUCT定义
 */

/*
 * 结构说明: tru switch info
 */
typedef struct {
    uint32_t syncpos;      /* 帧头 */
    uint32_t insfn;        /* psbch解到的帧号 */
    uint32_t cfgsfn;       /* 折算出的当前帧号 */
    uint32_t psbchAbsPos;  /* 解到psbch的子帧的绝对时标位置 */
} LPHY_V2X_TRU_SwitchInfo;

/*
 * 结构说明: tru loop info
 */
typedef struct {
    uint8_t  kiIndex;              /* 1-64 */
    uint8_t  holdFlg;
    int16_t  crcFlg;
    int16_t  syncDeltaErrTimes;    /* 搜索和解调定时偏差过大的次数 */
    uint16_t rsv;
    int32_t  toEst;
    int32_t  adjVal;
    uint32_t csSyncPos;
    uint32_t curDemodTime;
    uint32_t outDemodTime;
} LPHY_V2X_TRU_Om_LoopInfo;

#pragma pack(pop)


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
