

/*
 * 1 Other Header File Including
 */
#ifndef __D2D_CSU_OM_DEF_H__
#define __D2D_CSU_OM_DEF_H__

#include "neun_afc_interface.h"
#include "uphy_om_interface.h"

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push, 4)

/*
 * Enum Description: OM Rpt MsgId
 */
enum D2DPHY_CSU_OmRptMsgId {
    D2DPHY_CSU_RPT_MSGID_START = D2DPHY_OM_L1MSG_ID(D2DPHY_MODULE_ID_CSU, 0x0),
    D2DPHY_CSU_STEP1_RSLT_RPT = D2DPHY_CSU_RPT_MSGID_START,
    D2DPHY_CSU_STEP2_RSLT_RPT,
    D2DPHY_CSU_RPT_MSGID_BUTT,
};
typedef uint8_t D2DPHY_CSU_OmRptMsgIdUint08;

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif /* end of __LPHY_CSU_OM_DEF_H__ */



