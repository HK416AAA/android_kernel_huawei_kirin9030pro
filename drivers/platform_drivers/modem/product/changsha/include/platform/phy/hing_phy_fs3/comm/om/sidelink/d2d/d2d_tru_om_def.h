

/*
 * 1 其他头文件包含
 */
#ifndef __D2D_TRU_OM_DEF_H__
#define __D2D_TRU_OM_DEF_H__

#include  "d2d_basedef_struct.h"
#include "uphy_om_interface.h"


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(push, 4)

/*
 * 3 枚举定义
 */
enum D2D_TRU_WorkMode {
    D2D_TRU_NULL_MODE                      = 0, /* 无效mode，维持上一次mode */
    D2D_TRU_STOP_MODE                      = 1, /* 停止，进连接态 */
    D2D_TRU_SWITCH_MODE                    = 2, /* 切换，启动周期测量 */
    D2D_TRU_RUN_MODE                       = 3, /* 启动，停止周期测量 */
    D2D_TRU_MODE_BUTT,
};
typedef uint8_t D2D_TRU_WorkModeReqUint08;

/*
 * 枚举说明: OM REQ ID
 */
enum D2D_TRU_REQ_MSG {
    D2D_TRU_REQ_MSG_INFO = D2DPHY_OM_REQ_ID(D2DPHY_MODULE_ID_TRU, 0x01),
};
typedef uint32_t D2D_TRU_OmReqIdUint32;

/*
 * 枚举说明: OM 上报 ID
 */
enum D2D_TRU_IND_MSG {
    D2D_TRU_SWITCH_INFO = D2DPHY_OM_L1MSG_ID(D2DPHY_MODULE_ID_TRU, 0x01),
    D2D_TRU_LOOP_INFO,
};
typedef uint32_t D2D_TRU_OmInfoIdUint32;

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
} D2D_TRU_SwitchInfo;

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
} D2D_TRU_Om_LoopInfo;

#pragma pack(pop)


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
