

/*
 * 1 Other Header File Including
 */
#ifndef __UL1M_ULRM_OM_DEF_H__
#define __UL1M_ULRM_OM_DEF_H__

#include "uphy_typedef.h"
#include "uphy_om_def.h"
#include "uphy_om_interface.h"
#include "ul1m_lrm_comm_interface.h"
#include "neun_feature.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(push, 4)

/*
 * 2 Macro definition
 */
/*
 * 3 Enum definition
 */
/*
 * Enum Description: OM Req MsgId
 */
enum UL1M_PRM_LrmOmReqMsgId {
    UL1M_PRM_LRM_REQ_MSGID_START = UPHY_OM_REQ_ID(UPHY_MODULE_ID_PRM_LRM, 0x0), // value = 0x3f003000
    UL1M_PRM_LRM_REQ_OM_EN       = UL1M_PRM_LRM_REQ_MSGID_START,
    UL1M_PRM_LRM_REQ_MSGID_BUTT,
};
typedef uint32_t UL1M_PRM_LrmOmReqMsgIdUint32;

/*
 * Enum Description: Ul1M OM report to hidis msgId define here, please add inorder,id must less than 127
 */
enum UL1M_PRM_LrmOmRptMsgId {
    UL1M_PRM_LRM_RPT_START = UPHY_OM_L1MSG_ID(UPHY_MODULE_ID_PRM_LRM, 0x0), // value = 0x3f383000
    UL1M_PRM_LRM_RPT_RES_INFO = UL1M_PRM_LRM_RPT_START,
    UL1M_PRM_LRM_RPT_MSGID_BUTT,
};
typedef uint32_t UL1M_PRM_LrmOmRptMsgIdUint32;

/*
 * 4 Struct definition
 */
/*
 * Struct Description:om ctrl
 */
typedef struct {
    UPHY_OM_ReqEnableUint08 isOmEnable; // om request switch
    uint8_t                 res[3];
} UL1M_PRM_LrmOmCtrlReq;

/* Struct Description: om report struct */
typedef struct {
    UL1M_PRM_LrmDlResInfo        dlResInfo[UL1M_PRM_LRM_DL_BBP_RES_MAX_NUM];
    UL1M_PRM_LrmUlResInfo        ulResInfo[UL1M_PRM_LRM_UL_BBP_RES_MAX_NUM];
    uint32_t                  dlResUsedBitMap;
#if (NEUN_FEATURE_DC_SWITCH == UPHY_ON)
    uint32_t                  dlPdeCfgResUsedBitMap;
#endif
    uint32_t                  ulResUsedBitMap;
    uint32_t                  dlSystimUsedBitMap;
    uint32_t                  dlBbaUsedBitMap;
    uint32_t                  ulModUsedBitMap;
    uint32_t                  ulTduUsedBitMap;
    uint32_t                  ulSystimUsedBitMap;
    uint8_t                   ltevSystimChIdx;
    uint8_t                   icModeFlag;
    uint8_t                   pdeChangeFlag;
    uint8_t                   rsv;
} UL1M_PRM_LrmOmResInfo;

/*
 * Struct Description: cfg rpt size = 532 bytes
 */
typedef struct {
    UL1M_PRM_LrmBbpResApplyInfo resReq;  // resource request info report
    UL1M_PRM_LrmOmResInfo       resRslt; // resource request result info report
#if (NEUN_FEATURE_BBP_PDE_CLEAR_SWITCH == UPHY_ON)
    UL1M_PRM_LrmPdeClearContext pdeClearInfo;
#endif
} UL1M_PRM_LrmOmRpt;

#pragma pack(pop)


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* end of __UL1M_ULRM_OM_DEF_H__ */

