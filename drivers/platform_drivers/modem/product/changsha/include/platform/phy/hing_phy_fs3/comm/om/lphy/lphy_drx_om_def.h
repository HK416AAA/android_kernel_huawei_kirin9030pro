
#ifndef __LPHY_DRX_OM_DEF_H__
#define __LPHY_DRX_OM_DEF_H__

#include "uphy_om_interface.h"
#include "lphy_feature.h"
#include "lphy_comm_lpc_interface.h"
#include "neun_drx_interface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/* 2. Macro definitions */
/* 3. Enumerations declarations */
/* OM Request type from HIDS */
enum LPHY_CDRX_TmrOpType {
    LPHY_CDRX_TMR_DEL,
    LPHY_CDRX_TMR_ADD,
    LPHY_CDRX_TMR_BUTT
};
typedef uint32_t LPHY_CDRX_TmrOpTypeUint32;

/* DRX OM Report MSG ID */
enum LPHY_CDRX_OmL1MsgId {
    /* HL1C CDRX OM MSG ID */
    /* state Basic info */
    LPHY_OM_CDRX_INACTIVE_START_INFO_IND            = LPHY_OM_L1MSG_ID(LPHY_MODULE_ID_CDRX, 0x00),
    LPHY_OM_CDRX_ACTIVE_START_INFO_IND,

    /* HL1C timer info */
    LPHY_OM_CDRX_ONDU_TMR_ADD_IND,
    LPHY_OM_CDRX_ONDU_TMR_DEL_IND,

    /* LL1D timer info */
    LPHY_OM_CDRX_L1D_IA_TMR_ADD_IND,
    LPHY_OM_CDRX_L1D_IA_TMR_DEL_IND,
    LPHY_OM_CDRX_L1U_IA_TMR_ADD_IND,
    LPHY_OM_CDRX_L1U_IA_TMR_DEL_IND,

    LPHY_OM_CDRX_L1D_HARQRTT_TMR_ADD_IND,
    LPHY_OM_CDRX_L1D_HARQRTT_TMR_DEL_IND,
    LPHY_OM_CDRX_L1U_HARQRTT_TMR_ADD_IND,
    LPHY_OM_CDRX_L1U_HARQRTT_TMR_DEL_IND,

    LPHY_OM_CDRX_L1D_RETRANS_TMR_ADD_IND,
    LPHY_OM_CDRX_L1D_RETRANS_TMR_DEL_IND,
    LPHY_OM_CDRX_L1U_RETRANS_TMR_ADD_IND,
    LPHY_OM_CDRX_L1U_RETRANS_TMR_DEL_IND,

    LPHY_OM_CDRX_L1D_ACK_TMR_ADD_IND,
    LPHY_OM_CDRX_L1D_ACK_TMR_DEL_IND,
    LPHY_OM_CDRX_L1U_CQI_ONLY_TMR_ADD_IND,
    LPHY_OM_CDRX_L1U_CQI_ONLY_TMR_DEL_IND,
    LPHY_OM_CDRX_L1U_SR_TX_TMR_ADD_IND,
    LPHY_OM_CDRX_L1U_SR_TX_TMR_DEL_IND,

    LPHY_OM_CDRX_SPS_INFO_IND,
    LPHY_OM_CDRX_RRC_CFG_INFO_IND,
    LPHY_OM_CDRX_INACTIVE_START_IND,
    LPHY_OM_CDRX_ACTIVE_START_IND,

    LPHY_OM_CDRX_VOICE_SYNC_IND,
    LPHY_OM_DRX_BUTT
};
typedef uint32_t LPHY_CDRX_OmL1MsgID;

/* 5. 数据结构定义 */
/* CDRX OM: SPS info */
typedef struct {
    uint16_t curSubFramePos; /* (帧号*10 + 子帧号) */
    uint16_t subFrameToSps; /* curSubFramePos距离SPS唤醒位置的子帧间隔 */
    LPHY_CDRX_SpsWakeInfo spsWakeInfo; /* SPS唤醒参数 */
} LPHY_CDRX_OmSpsInfo;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* #ifndef __LPHY_DRX_OM_DEF_H__ */
