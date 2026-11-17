

#ifndef __LPHY_V2X_FEC_OM_DEF_H__
#define __LPHY_V2X_FEC_OM_DEF_H__

/*
 * 1 其他头文件包含
 */
#include "neun_fec_om_def.h"
#include "lphy_v2x_basedef_struct.h"
#include "uphy_om_interface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(push, 4)

#define LPHY_V2X_FEC_MODE_NUM 6

/*
 * 3 枚举定义
 */
/*
 * 枚举说明: OM 上报 ID
 */
enum LPHY_V2X_FEC_OmRptId {
    LPHY_V2X_FEC_RF_DRV_EVENT_INFO = LVPHY_OM_L1MSG_ID(LVPHY_MODULE_ID_FEC, 0x00),
    LPHY_V2X_FEC_RF_DRV_TX_EVENT_INFO,
    LPHY_V2X_FEC_TX_CTRL_REQ_INFO,
    LPHY_V2X_FEC_READ_REG_INFO,
    LPHY_V2X_FEC_DATA_RPT_INFO,
    LPHY_V2X_FEC_TX_BAND_CTRL_INFO,
    LPHY_V2X_FEC_FCFU_DBG_INFO,
    LPHY_V2X_FEC_OM_RPT_ID_BUTT
};
typedef uint32_t LPHY_V2X_FEC_OmRptIdUint32;


#pragma pack(pop)


#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif

#endif    /* end of nenu_fec_om_def.h */

