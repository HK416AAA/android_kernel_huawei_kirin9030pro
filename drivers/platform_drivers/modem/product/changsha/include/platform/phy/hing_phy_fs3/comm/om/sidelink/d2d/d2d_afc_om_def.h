

#ifndef __D2D_AFC_OM_DEF_H__
#define __D2D_AFC_OM_DEF_H__
/*
 * 1 其他头文件包含
 */
#include "neun_afc_interface.h"
#include  "uphy_om_interface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/*
 * 2 宏定义
 */
typedef struct {
    UPHY_UINT16 cellId;      /* 小区ID */
    UPHY_UINT16 rsv1;
    UPHY_UINT32 freqInfo;
    UPHY_SINT32 initFo;      /* 温补和扫档频偏，hz */
    UPHY_SINT32 pbchInitFo;  /* 小区搜和解pb频偏的和，hz  */
    UPHY_SINT32 csuInitFfo;  /* 小区搜频偏，归一化 */
    UPHY_SINT32 foDmrs;      /* 初始PBCH频偏，归一化  */

    UPHY_SINT16 foEst;
    UPHY_UINT08 inFoValid;   /* 频偏估计值的可靠性判决 */
    UPHY_UINT08 rsv2;

    UPHY_SINT16 filterInFoEst;
    UPHY_UINT16 counterKp;
    UPHY_SINT32 curFoAdj;
    UPHY_SINT32 curFoAdjAdd;
    UPHY_SINT32 accFo;
    UPHY_SINT32 outLoopFilterHz;
    UPHY_SINT32 freqRatio;          /* 下行频点对应PPM值,2^32 */
    UPHY_SINT32 phaseDeltaStandard; /* 30.72采样率对应的下行频偏折算到相位的值 */
} D2D_AFC_PeirodOmPara;

/*
 * 枚举说明: OM 上报 ID
 */
enum D2D_AFC_OmRptId {
    D2D_AFC_TPA_CFG_INFO_H = D2DPHY_OM_L1MSG_ID(D2DPHY_MODULE_ID_AFC, 0x00),
    D2D_AFC_END_INFO_H,
    D2D_AFC_PERIOD_RPT_INFO,
    D2D_AFC_MSGID_BUTT
};
typedef UPHY_UINT32 D2D_AFC_OmRptIdUint32;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
