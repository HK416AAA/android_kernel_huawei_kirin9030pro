

/*****************************************************************************
  1 Other header include
*****************************************************************************/
#ifndef __UPHY_DMU_OM_DEF_H__
#define __UPHY_DMU_OM_DEF_H__

#include  "uphy_dvfs_interface.h"
#include  "uphy_inst_id_interface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/*****************************************************************************
  3. Enumerations declarations
*****************************************************************************/

typedef struct {
    uint16_t instFreqReq[UPHY_DVFS_SOC_TYPE_BUTT][UPHY_INST_ID_DEFS_BUTT];
} UPHY_OM_DmuSocFreqVote;


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* #ifndef __UPHY_LPC_OM_DEF_H__ */
