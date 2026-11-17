
#ifndef __NPHY_DRX_OM_DEF_H__
#define __NPHY_DRX_OM_DEF_H__

#include "uphy_om_interface.h"
#include "nphy_feature.h"
#include "neun_drx_interface.h"
#include "nphy_comm_lpc_interface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/* 2. Macro definitions */
/* 3. Enumerations declarations */
/* OM Request type from HIDS */
enum NPHY_CDRX_TmrOpType {
    NPHY_CDRX_TMR_DEL,
    NPHY_CDRX_TMR_ADD,
    NPHY_CDRX_TMR_BUTT
};
typedef uint32_t NPHY_CDRX_TmrOpTypeUint32;

/* DRX OM Report MSG ID */
enum NPHY_CDRX_OmL1MsgId {
    /* HL1C CDRX OM MSG ID */
    /* state Basic info */
    NPHY_OM_CDRX_INACTIVE_START_INFO_IND = NPHY_OM_L1MSG_ID(NPHY_MODULE_CDRX, 0x00),
    NPHY_OM_CDRX_ACTIVE_START_INFO_IND,

    /* HL1C timer info */
    NPHY_OM_CDRX_ONDU_TMR_ADD_IND,
    NPHY_OM_CDRX_ONDU_TMR_DEL_IND,

    /* LL1D timer info */
    NPHY_OM_CDRX_L1D_IA_TMR_ADD_IND,
    NPHY_OM_CDRX_L1D_IA_TMR_DEL_IND,
    NPHY_OM_CDRX_L1U_IA_TMR_ADD_IND,
    NPHY_OM_CDRX_L1U_IA_TMR_DEL_IND,

    NPHY_OM_CDRX_L1D_HARQRTT_TMR_ADD_IND,
    NPHY_OM_CDRX_L1D_HARQRTT_TMR_DEL_IND,
    NPHY_OM_CDRX_L1U_HARQRTT_TMR_ADD_IND,
    NPHY_OM_CDRX_L1U_HARQRTT_TMR_DEL_IND,

    NPHY_OM_CDRX_L1D_RETRANS_TMR_ADD_IND,
    NPHY_OM_CDRX_L1D_RETRANS_TMR_DEL_IND,
    NPHY_OM_CDRX_L1U_RETRANS_TMR_ADD_IND,
    NPHY_OM_CDRX_L1U_RETRANS_TMR_DEL_IND,

    NPHY_OM_CDRX_L1D_ACK_ADD_IND,
    NPHY_OM_CDRX_L1D_ACK_DEL_IND,
    NPHY_OM_CDRX_L1U_CQI_ONLY_TMR_ADD_IND,
    NPHY_OM_CDRX_L1U_CQI_ONLY_TMR_DEL_IND,
    NPHY_OM_CDRX_L1U_SR_TX_TMR_ADD_IND,
    NPHY_OM_CDRX_L1U_SR_TX_TMR_DEL_IND,

    NPHY_OM_CDRX_SPS_INFO_IND,
    NPHY_OM_CDRX_RRC_CFG_INFO_IND,
    NPHY_OM_CDRX_INACTIVE_START_IND,
    NPHY_OM_CDRX_ACTIVE_START_IND,

    NPHY_OM_CDRX_VOICE_SYNC_IND,
    NPHY_OM_CDRX_VOICE_SyncEnableInd,
    NPHY_OM_CDRX_DCP_CAL_INFO_IND,
    NPHY_OM_CDRX_DCP_RES_INFO_IND,

    NPHY_OM_DRX_BUTT
};
typedef uint32_t NPHY_CDRX_OmL1MsgID;

/* 5. 数据结构定义 */
/* CDRX OM: SPS info */
typedef struct {
    uint32_t curSlotPos; /* (帧号*10 + 子帧号)*slotNumPerSubframe + slotNum */
    uint32_t slotLenToSps; /* curSlotPos距离SPS唤醒位置的slot间隔 */
    NPHY_CDRX_SpsWakeInfo spsWakeInfo; /* SPS唤醒参数 */
} NPHY_CDRX_OmSpsInfo;

/* STRUCT declarations */
typedef struct {
    uint16_t firstCdrxOffset;   /*  slot数 */
    uint16_t secondCdrxOffset;
    uint16_t slotDuration;
    uint16_t spacePeriod;

    uint8_t minSlotFlag;
    uint8_t minTimeGap;
    uint8_t psOffset;
    uint8_t durOffsetInSpace;
    uint8_t psOffsetInSpace;
    uint8_t psToDuraGap;
    uint8_t dcpDurDisToOndu;
    uint8_t dcpDurEndDisToOndu;
} NPHY_CDRX_DcpCalcInfo;

/* R16_POWER_SAVING  对齐协议栈结构：NRRC_NPHY_DcpConfigR16 */
typedef struct {
    uint16_t psOffset;               /* INTEGER (1..120) 单位 1/8ms */
    uint8_t  sizeDci26;
    uint8_t  positionDci2_6;
    uint8_t  psWakeUp;
    uint8_t  psTransmitPeriodicL1Rsrp;
    uint8_t  psTransmitPeriodicCsi;
} NPHY_CDRX_DcpConfigR16;

typedef struct {
    uint16_t slotPertiod;   /* SearchSpace周期，slot为单位，高层参数已转化为slotNum */
    uint16_t offset;
    uint16_t slotDuration;
    uint16_t resv;
} NPHY_CDRX_DcpSearchSpace;

typedef struct {
    uint8_t                  dcpConfigR16Valid;
    uint8_t                  disableOndu;
    uint8_t                  dcpDurDisToOndu;     /* 时隙数 第一个可监听dci26  距离ondu的时隙数 */
    uint8_t                  dcpDurEndDisToOndu;
    uint8_t                  hl1cDcpDecodeOk;     /* Hl1c获取到结果后不再重复读取接口 增加此标志 */
    uint8_t                  csiRptTmrOn;         /* 不启动ondu 但需要上报周期CSI时 */
    uint8_t                  minTimeGap;          /* 协议配置最小GAP */
    uint8_t                  psRntiActFlag;       /* true 时连接态过程激活psRnti */
    uint32_t                 csiTmrSlotLen;       /* timer length in slot number(for 240k SCS) */
    uint32_t                 csiTmrStartPos;      /* 定时器起始位置，折算为240kscs对应的slot位置。 */
    uint32_t                 csiTmrEndPos;
    NPHY_CDRX_DcpConfigR16   dcpCfg;
    NPHY_CDRX_DcpSearchSpace dcpSpace;
    NEUN_L1D_DcpDecodeInfo   dcpDecodeInfo;
} NPHY_CDRX_DcpInfo;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* #ifndef __NPHY_DRX_OM_DEF_H__ */
