


#ifndef __LPHY_LPC_OM_DEF_H__
#define __LPHY_LPC_OM_DEF_H__

/*
 * 1 Other header include
 */
#include "neun_lpc_om_def.h"
#include "neun_lpc_ext_interface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */


/*
 * 3. Enumerations declarations
 */
enum LPHY_LPC_OmMsgId {
    LPHY_OM_LPC_MSGID_START             = LPHY_OM_L1MSG_ID(LPHY_MODULE_ID_LPC, 0x0),
    LPHY_OM_LPC_L1CL1M_MSG              = LPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_L1CL1M_MSG,
    LPHY_OM_LPC_L1ML1C_MSG              = LPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_L1ML1C_MSG,
    LPHY_OM_LPC_L1CL1D_MSG              = LPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_L1CL1D_MSG,
    LPHY_OM_LPC_L1DL1C_MSG              = LPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_L1DL1C_MSG,
    LPHY_OM_LPC_L1CL1U_MSG              = LPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_L1CL1U_MSG,
    LPHY_OM_LPC_L1UL1C_MSG              = LPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_L1UL1C_MSG,
    LPHY_OM_LPC_L1CFESS_MSG             = LPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_L1CFESS_MSG,
    LPHY_OM_LPC_FESSL1C_MSG             = LPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_FESSL1C_MSG,
    LPHY_OM_LPC_HL1C_WAKE_INFO          = LPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_HL1C_WAKE_INFO,
    LPHY_OM_LPC_HL1C_SLEEP_INFO         = LPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_HL1C_SLEEP_INFO,
    LPHY_OM_LPC_HL1C_STATE_INFO         = LPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_HL1C_STATE_INFO,
    LPHY_OM_LPC_SYMBLPC_RX_INFO         = LPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_SYMBLPC_RX_INFO,
    LPHY_OM_LPC_DVTY_INFO               = LPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_DVTY_INFO,
    LPHY_OM_LPC_DVFS_TSP_PROF_INFO      = LPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_DVFS_TSP_PROF_INFO,
    LPHY_OM_LPC_DVTY_CAL_INFO           = LPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_DVTY_CAL_INFO,
    LPHY_OM_LPC_DFX_INFO                = LPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_DFX_INFO,
    LPHY_OM_LPC_PRINT_RPT               = LPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_PRINT_RPT,
    LPHY_OM_LPC_LOCAL_TX_INFO           = LPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_LOCAL_TX_INFO,
    LPHY_OM_LPC_PDCONLY_MC_RPT          = LPHY_OM_LPC_MSGID_START + NEUN_OM_LPC_PDCONLY_MC_RPT,
};
typedef uint32_t LPHY_LPC_OmMsgIdUint32;

typedef struct {
    uint32_t                              msgId;

    uint8_t                               bbpPdfReqProfile;    /* 记录PDF申请档位 */
    uint8_t                               bbpPdtReqProfile;    /* 记录PDF申请档位 */
    uint8_t                               bbpUlReqProfile;     /* 记录PDF申请档位 */

    uint8_t                               bbpPdfLastProfile;    /* 记录PDF上次的实际档位 */
    uint8_t                               bbpPdtLastProfile;    /* 记录PDF上次的实际档位 */
    uint8_t                               bbpUlLastProfile;     /* 记录PDF上次的实际档位 */

    uint8_t                               bbpPdfProfile;       /* 记录PDF实际档位 */
    uint8_t                               bbpPdtProfile;       /* 记录PDT实际档位 */
    uint8_t                               bbpUlProfile;        /* 记录UL实际档位 */

    uint8_t                               bbpPdfMaxProfile;       /* 记录PDF支持的最大档位 */
    uint8_t                               bbpPdtMaxProfile;       /* 记录PDT支持的最大档位 */
    uint8_t                               bbpUlMaxProfile;        /* 记录UL支持的最大档位 */

    uint32_t                              dvfsBbpReqCnt;       /* 记录BBP调频申请次数 */
    uint32_t                              dvfsBbpReqSlice;     /* 记录BBP调频申请时间戳 */
    uint32_t                              dvfsBbpCnfCnt;       /* 记录BBP调频完成次数 */
    uint32_t                              dvfsBbpCnfSlice;     /* 记录BBP调频完成时间戳 */
} LPHY_LPC_OmDvfsBbpInfo;

typedef struct {
    uint16_t                             sysFrmNum;
    uint8_t                              subFrmNum;
    uint8_t                              symbLpcEn;
    uint8_t                              dlUpdateFlag;
    uint8_t                              ccIndex;
    uint16_t                             rxSymbBit[UPHY_NUM3];
    uint16_t                             hl1cVoteRxBit[UPHY_NUM3];
    uint16_t                             dlVoteSymb[UPHY_NUM2];
    uint8_t                              voteFlag;
    uint8_t                              microSleep20Flag;
    uint8_t                              sensorStateFlag;
    uint8_t                              tfsyncOptFlag;
    uint8_t                              highMcsFlag;
    uint8_t                              lowMcsCycleCnt;
    uint8_t                              fastModeForbidEvtBitMap; /* PCC阻止进入快调模式的事件集合 */
    NEUN_LPC_SymbLpcWorkModeUint08       pccWorkMode; /* PCC符号级低功耗工作模式 */
} LPHY_LPC_OmSymbRxBitInfo;

typedef struct {
    NEUN_LPC_DvtyImmedEvtUint08 immedFlag;           /* 需要立即切换 */
    uint8_t lpcAntNum;
    uint8_t servAntNum;
    uint8_t nvAntNum;
    uint8_t ueCapAntNum;
    uint8_t otaAntNum;
    uint8_t rsv[2];
} LPHY_LPC_OmDvtyInfo;


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* #ifndef __LPHY_LPC_OM_DEF_H__ */

