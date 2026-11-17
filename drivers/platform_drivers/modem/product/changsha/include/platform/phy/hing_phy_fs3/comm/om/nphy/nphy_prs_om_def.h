

/*
 * 1 其他头文件包含
 */
#ifndef __NPHY_PRS_OM_DEF_H__
#define __NPHY_PRS_OM_DEF_H__

#include "nphy_smpc_prs.h"
#include "nphy_hl1c_ml1c_bgt.h"
#include "ul1m_sdrm_nphy_msg.h"
#include "ul1m_sdrm_prs_manager.h"
#include "nphy_l1c_ll1d_interface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(push, 4)

/* smpc prs */
#define NPHY_SMPC_MAIN \
    NPHY_SMPC_PrsSmpBbpCfg                  prsSmpBbpCfg; \
    NPHY_ML1C_HL1C_SmpPrsInfoNtf            prsSmpInfoNtf;
/* bgt prs */
#define NPHY_BGT_MAIN \
    UL1M_SDRM_PrsPdeCfgData     sdrmPrsdeCfg; \
    SDRM_NPHY_PrsReq            sdrmPrsCfg; \
    SDRM_NPHY_PrsInd            sdrmPrsInd;

#pragma pack(pop)


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* end of __NPHY_CSU_OM_DEF_H__ */

