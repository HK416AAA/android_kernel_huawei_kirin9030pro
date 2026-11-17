
/*
 * 1 其他头文件包含
 */
#ifndef __NPHY_DL_BEAM_OM_DEF_H__
#define __NPHY_DL_BEAM_OM_DEF_H__

#include "neun_basedef_struct.h"/*lint !e537*/
#include "uphy_mbx_alloc_interface.h"/*lint !e537*/

#include "nphy_hl1c_ll1d_interface.h"/*lint !e537*/
#include "neun_basedef_enum.h"/*lint !e537*/
#include "nphy_ll1d_sdr_tfsync_interface.h"
#include "nphy_emu_comm_interface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(push, 4)

/*
 * 2 宏定义
 */
/*
 * 3 枚举定义
 */
typedef enum {
    NPHY_DL_BEAM_OM_REQ_DISABLE = 0,
    NPHY_DL_BEAM_OM_REQ_ENABLE
}NPHY_DlBeamOmReqEnableEnum;

typedef uint8_t NPHY_DlBeamOmReqEnableEnumUint08;

typedef enum {
    NPHY_DL_BEAM_OM_REQ_MODEM0 = NPHY_OM_REQ_ID(NPHY_MODULE_BEAM, 0x00),
    NPHY_DL_BEAM_OM_REQ_MODEM1 = NPHY_OM_REQ_ID(NPHY_MODULE_BEAM, 0x01),

    NPHY_DL_BEAM_OM_REQ_BUTT,
}NPHY_DlBeamOmReqEnum;

typedef uint8_t NPHY_DlBeamOmReqEnumUint08;

typedef enum {
    NPHY_DL_BEAM_SAMP_CFG_IND = NPHY_OM_L1MSG_ID(NPHY_MODULE_BEAM, 0x00),
    NPHY_DL_BEAM_SDR_CFG_IND,

    NPHY_DL_BEAM_OM_ENUM_BUFF
}NPHY_DlBeamOmEnum;

typedef uint8_t NPHY_DlBeamOmEnumUint08;

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
    UPHY_OM_ReqCoreModemInd     core;

    NPHY_DlBeamOmReqEnableEnumUint08    sampCfgEn; /* 采数配置信息上报使能 */
    NPHY_DlBeamOmReqEnableEnumUint08    sdrCfgEn;  /* sdr配置信息上报使能 */
    uint8_t                                  rsv[2];
}NPHY_DlBeamOmCtrlStru;

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
#pragma pack(pop)

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif

