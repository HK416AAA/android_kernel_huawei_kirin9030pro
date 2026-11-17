
#ifndef __NEUN_DRX_OM_DEF_H__
#define __NEUN_DRX_OM_DEF_H__

#include "uphy_om_interface.h"
#include "neun_basedef_enum.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/* 2. Macro definitions */
/* 3. Enumerations declarations */
typedef struct {
    uint16_t coreMask;
    uint16_t modemId;
} NEUN_CDRX_ReqCoreModemInd; /*lint !e959 */

typedef struct {
    NEUN_CDRX_ReqCoreModemInd      coreModem;
    uint8_t                        enaRpt;
    uint8_t                        rsvd[3];
} NEUN_CDRX_OmRptCtrl;

typedef struct {
    NEUN_CDRX_OmRptCtrl   staInfo;
    NEUN_CDRX_OmRptCtrl   tmrInfo;
} NEUN_CDRX_OmRptReq;

/* 5. SG 数据结构定义, 算法需要绘图的 */
/* CDRX OM  state basic info report */
typedef struct {
    uint8_t modemIdx;
    uint8_t cgIdx;
    uint8_t curCdrxType;
    uint8_t actCause;
    uint16_t sysFn;                   /* System frame Num */
    uint16_t subFn;                   /* subframe Num */
    uint16_t slotNum;                 /* Slot Num */
    uint16_t curCdrxCycle;            /* 当前CDRX周期，单位为ms */
} NEUN_CDRX_OmTimeInfo;

/* STRUCT declarations */
typedef struct {
    uint16_t onDurTmrLen;        /* slot num @240K SCS for NR, ms for LTE*/
    uint8_t onDurSlotOffsetTs;   /* 0~15 slot num @240K SCS for NR, 0 for LTE */
    uint8_t rsv;
    uint16_t inactTmrLen;        /* slot num @240K SCS for NR, ms for LTE */
    uint16_t longDrxCycle;       /* ms */
    uint16_t longDrxStartOffset; /* ms */
    uint16_t shortDrxCycle;      /* ms */
    uint16_t harqRttTmrDlLen;    /* slot num @各自scs */
    uint16_t reTransTmrDlLen;    /* slot num @各自scs */
    uint16_t harqRttTmrUlLen;    /* slot num @各自scs */
    uint16_t reTransTmrUlLen;    /* slot num @各自scs */
} NEUN_CDRX_RrcCfgInfo;

/* CDRX rrc cfg info */
typedef struct {
    uint8_t modemIdx;
    uint8_t cgIdx;
    uint8_t cdrxEnable;
    uint8_t shortDrxCycleTimer;       /* 0表示没有配置短周期；其他，为配置的短周期定时器长度 */
    uint8_t localCdrxEn;
    uint8_t rsv[3];
    NEUN_CDRX_RrcCfgInfo cdrxCfgInfo; /* cdrx config info */
} NEUN_CDRX_OmRrcCfgInfoRpt;

/* CDRX OM  Ondur timer info report */
typedef struct {
    uint8_t modemIdx;
    uint8_t cgIdx;
    uint8_t curCdrxType;
    uint8_t actCause;
    uint16_t sysFn;                   /* System frame Num */
    uint8_t  subFn;                   /* subframe Num */
    uint8_t  slotNum;                 /* Slot Num */
    uint8_t  abortSlotLen;            /* 尾部GAP/UL无发送/pdcSkip时隙提前终止定时器时隙数 */
    uint8_t  rsv[3];                  /* Slot Num */
} NEUN_CDRX_OmOnduTmrInfo;

/* CDRX OM  inactivity timer info report */
typedef struct {
    uint8_t modemIdx;
    uint8_t ccIdx;
    uint8_t subType;
    uint8_t tmrType;

    uint16_t curFmNum;
    uint8_t curSubFmNum;
    uint8_t curSlotNum;

    uint16_t rsv;
    uint16_t tmrLen;
    uint32_t startSlotPos;
    uint32_t endSlotPos;
} NEUN_CDRX_OmAddTmrInfo;

/* CDRX OM  Deleted timer info report */
typedef struct {
    uint8_t modemIdx;
    uint8_t ccIdx;
    uint8_t subType;
    uint8_t tmrType;

    uint8_t abortSlotLen;            /* 尾部GAP/UL无发送/pdcSkip时隙提前终止定时器时隙数 */
    uint8_t rsv[UPHY_NUM3];

    uint16_t curFmNum;
    uint8_t  curSubFmNum;
    uint8_t  curSlotNum;

    uint32_t nonActTmrBitMask;
    uint32_t actTmrBitMask;
} NEUN_CDRX_OmDelTmrInfo;

/* CDRX OM state detail info report */
typedef struct {
    uint8_t modemId;
    uint8_t cgId;
    uint16_t sysFn;
    uint16_t subFn;
    uint16_t slotNum;
    uint8_t cdrxTypeInd;
    uint8_t activeTimeInd;
    uint8_t rsv[2];
} NEUN_CDRX_OmDtStatus;

typedef struct {
    MDRV_MSG_HEAD
    uint16_t msgId;
    uint16_t resv0;
    uint32_t onDurationSlice; /* LPHY给出的LTE CDRX OnDuration起始时刻*/
    uint16_t sendOffset;      /* 以onDurationSlice为基点，VOICE发送语音包前量 */
    uint16_t resv1;
} NEUN_VOICE_OmSyncInd;

typedef struct {
    MDRV_MSG_HEAD
    uint16_t msgId;
    uint16_t resv;
} NEUN_VOICE_OmSyncEnableInd;
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* #ifndef __NEUN_DRX_OM_DEF_H__ */
