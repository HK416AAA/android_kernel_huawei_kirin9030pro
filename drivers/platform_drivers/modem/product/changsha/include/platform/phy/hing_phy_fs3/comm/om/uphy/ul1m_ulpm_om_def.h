

/*
 * 1 Other Header File Including
 */
#ifndef __UL1M_ULPM_OM_DEF_H__
#define __UL1M_ULPM_OM_DEF_H__

#include "uphy_typedef.h"
#include "uphy_feature.h"
#include "lphy_feature.h"
#include "nphy_feature.h"
#include "uphy_om_interface.h"
#include "uphy_basedef_const.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(push, 4)

/*
 * Enum Description: OM Req MsgId
 */
enum UL1M_ULPM_OmReqMsgId {
    UL1M_ULPM_OM_REQ_START  = UPHY_OM_REQ_ID(UPHY_MODULE_ID_LPM, 0x0),
    UL1M_ULPM_OM_REQ        = UL1M_ULPM_OM_REQ_START,
    UL1M_ULPM_OM_REQ_BUTT,
};
typedef uint32_t UL1M_ULPM_OmReqMsgIdUint32;

/*
 * Enum Description: OM Rpt MsgId
 */
enum UL1M_ULPM_OmRptMsgId {
    UL1M_ULPM_OM_DVFS_BBP_VOTE_INFO = UPHY_OM_L1MSG_ID(UPHY_MODULE_ID_LPM, 0x0),
    UL1M_ULPM_OM_DVFS_BBP_PROF_INFO,
    UL1M_ULPM_OM_DVFS_TSP_PROF_INFO,
    UL1M_ULPM_OM_PHY_RCM_AWAKE_REQ,
    UL1M_ULPM_OM_PHY_RCM_SLEEP_REQ,
    UL1M_ULPM_OM_PHY_VOICE_STATUS_INFO,
    UL1M_ULPM_OM_PHY_VOICE_STATUS_NTF,
    UL1M_ULPM_OM_TEMP_PROTECT_INFO,
    UL1M_ULPM_OM_UL1M_SLEEP_INFO,
    UL1M_ULPM_OM_DVFS_RPT_MSGID_BUTT,
};
typedef uint32_t UL1M_ULPM_OmRptMsgIdUint32;

/* 枚举说明：PDF投票源枚举 */
enum {
    UL1M_DVFS_PDF_VT_MODULE_DVFS,
    UL1M_DVFS_PDF_VT_MODULE_MUMIMO,
    UL1M_DVFS_PDF_VT_MODULE_FEICIC,
    UL1M_DVFS_PDF_VT_MODULE_BUTT
};
typedef uint8_t UL1M_DVFS_PdfVtModuleUint08;

/* 枚举说明：PDT投票源枚举 */
enum {
    UL1M_DVFS_PDT_VT_MODULE_DVFS,
    UL1M_DVFS_PDT_VT_MODULE_CSU,
    UL1M_DVFS_PDT_VT_MODULE_SMU,
    UL1M_DVFS_PDT_VT_MODULE_UL,
    UL1M_DVFS_PDT_VT_MODULE_CFU,
    UL1M_DVFS_PDT_VT_MODULE_BUTT
};
typedef uint8_t UL1M_DVFS_PdtVtModuleUint08;

/* 枚举说明  : 语音呼叫状态 */
enum UL1M_OmVoiceCallStatus{
    UL1M_OM_VOICE_CALL_STATUS_INIT,
    UL1M_OM_VOICE_CALL_STATUS_START,
    UL1M_OM_VOICE_CALL_STATUS_ACTIVE,
    UL1M_OM_VOICE_CALL_STATUS_END,
    UL1M_OM_VOICE_CALL_STATUS_BUTT,
};
typedef uint8_t UL1M_OmVoiceCallStatusUint8;

/*
 * 4 Struct definition
 */
/*
 * Struct Description: pde om ctrl
 */
typedef struct {
    uint8_t     ulpmInfoLevelEna;
    uint8_t     ulpmTraceLevelEna;
    uint8_t     rttHpaCtrl;
    uint8_t     rsv;
} UL1M_ULPM_OmCtrl;

/* 小区搜索相关PDT投票信息 */
typedef struct {
    uint8_t lteTotalRecvNum;
    uint8_t nrSub6gTotalRecvNum;
    uint8_t nrHfTotalRecvNum;
    uint8_t rsv;
} UL1M_DVFS_CsuPdtVoteInfo;

/* 测量相关PDT投票信息 */
typedef struct {
    /* NR LTE合并后结果 */
    uint8_t lteTotalRecvNum;
    uint8_t nrTotalRecvNum[UPHY_NUM2];                  /* 0: sub6g, 1: hf */
    uint8_t nrCcNum;

    /* NR LTE投票结果 */
    uint16_t nrHfCcMask[UPHY_NUM3];
    uint8_t lteModemVoteInfo[UPHY_NUM3][LPHY_CAPACITY_MAX_DL_CARRIER_NUM + 1];
    uint8_t nrModemVoteInfo[UPHY_NUM3][NPHY_CAPACITY_MAX_DL_CARRIER_NUM + 1];
    uint8_t rsv[UPHY_STRUCT_FILL_LEN(sizeof(uint8_t),
                                    ((NPHY_CAPACITY_MAX_DL_CARRIER_NUM + LPHY_CAPACITY_MAX_DL_CARRIER_NUM + UPHY_NUM2) *
                                    UPHY_NUM3 + UPHY_NUM2) * sizeof(uint8_t))];
} UL1M_DVFS_SmuPdtVoteInfo;

/* HL1C BBP投票信息结构体 */
typedef struct {
    /* 公共信息 */
    uint8_t     sweepFlag;              /* 小区搜扫档标志 */
    uint8_t     dlCcNum;                /* 下行载波数 */
    uint8_t     dlCcScsType;            /* 下行载波最大scs类型 */
    uint8_t     pdtPdfVoteFlag;         /* pdt/pdf投票标志 */
    uint8_t     recvAntNum;             /* 最大接收天线数 */
    uint8_t     hfUlVoteFlag;           /* GUL线程是否有高频UL */
    uint16_t    totalWeight;            /* 所有载波总权重 */

    uint8_t     hfFlag;                 /* 是否存在高频载波 */
    uint8_t     hfCcNum;                /* 高频载波数 */
    uint16_t    maxHfCcWeight;          /* 高频载波最大权重 */
    uint16_t    maxHfBw;                /* 高频载波最大带宽 */
    uint16_t    maxConCaBw;             /* 连续CA带宽和 */
    uint16_t    maxCcWeight;            /* 单个CC的权重最大值（连续CA算一个载波） */
    uint16_t    scs60KCcWeight;         /* 60K scsType的载波的权重和 */

    /* PDF相关信息 */
    uint16_t    pdfCcNum[UPHY_CAPACITY_MAX_PDE_NUM];     /* 每套PDF的载波数 */
    uint16_t    pdfWeight[UPHY_CAPACITY_MAX_PDE_NUM];    /* 每个PDF所对应的载波的权重和 */
    uint16_t    pdfHfCcNum[UPHY_CAPACITY_MAX_PDE_NUM];   /* 每套PDF的高频载波数 */
    uint16_t    pdfHfBw[UPHY_CAPACITY_MAX_PDE_NUM];      /* 每套PDF的高频载波带宽和 */
} UL1M_ULPM_DvfsBbpVoteInfo;

/* HL1C BBP投票信息上报结构体 */
typedef struct {
    uint8_t modeType;
    uint8_t isInProtect;
    uint16_t rsv;
    uint8_t curLocProfile[UPHY_NUM2];
    uint8_t actLocProfile[UPHY_NUM2];
    uint8_t pdfModuleProfile[UL1M_DVFS_PDF_VT_MODULE_BUTT];     /* 各模块PDF投票档位 */
    uint8_t pdtModuleProfile[UL1M_DVFS_PDT_VT_MODULE_BUTT];     /* 各模块PDT投票档位 */

    UL1M_ULPM_DvfsBbpVoteInfo    lteVoteInfo;
    UL1M_ULPM_DvfsBbpVoteInfo    nrVoteInfo;
    UL1M_DVFS_SmuPdtVoteInfo smuPdtVtInf;
    UL1M_DVFS_CsuPdtVoteInfo csuPdtVtInf;
} UL1M_ULPM_DvfsBbpVoteInfoRpt;

/* 语音状态上报 */
typedef struct {
    UL1M_OmVoiceCallStatusUint8 callStatus[UPHY_NUM4]; /* 每张SIM卡维护一个语音状态 */
} UL1M_NELPM_VoiceStatusInfo;

/* 语音状态通知 */
typedef struct {
    uint32_t msgId;
} UL1M_ULPM_VoiceStatusNtf;

/* 温度保护结构 */
typedef struct {
    int8_t tempProLevel;          /* 温保级别 TEM_PRO_LOW = -1,
                                              TEM_PRO_NORMAL = 0,
                                              TEM_PRO_HIGH = 1,*/
    uint8_t enterFlag;            /* 是否进入温保状态标志 */
    uint8_t rsv[2];
} UL1M_ULPM_TempProtectInfo;

#pragma pack(pop)
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* end of __UL1M_ULPM_OM_DEF_H__ */

