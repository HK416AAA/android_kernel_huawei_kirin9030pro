

/*
 * 1 Other Header File Including
 */
#ifndef __LPHY_V2X_CSU_OM_DEF_H__
#define __LPHY_V2X_CSU_OM_DEF_H__

#include "neun_afc_interface.h"
#include  "uphy_om_interface.h"

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push, 4)


/*
 * Enum Description: OM Rpt MsgId
 */
enum LVPHY_CSU_OmRptMsgId {
    LVPHY_CSU_RPT_MSGID_START = LVPHY_OM_L1MSG_ID(LVPHY_MODULE_ID_CSU, 0x0),
    LVPHY_CSU_STEP1_RSLT_RPT = LVPHY_CSU_RPT_MSGID_START,
    LVPHY_CSU_STEP2_RSLT_RPT,
    LVPHY_CSU_RPT_MSGID_BUTT,
};
typedef uint8_t LVPHY_CSU_OmRptMsgIdUint08;


#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif /* end of __LPHY_CSU_OM_DEF_H__ */



