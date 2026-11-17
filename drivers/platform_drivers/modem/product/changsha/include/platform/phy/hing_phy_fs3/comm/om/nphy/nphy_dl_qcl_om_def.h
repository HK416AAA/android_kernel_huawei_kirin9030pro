


#ifndef __NPHY_DL_CHE_QCL_OM_DEF_H__
#define __NPHY_DL_CHE_QCL_OM_DEF_H__

/*
 * 1 其他头文件包含
 */
#include "uphy_typedef.h"
#include "uphy_om_interface.h"
#include "nrrc_nphy_interface.h"
#include "neun_che_interface.h"
#include "ul1m_nphy_dl_che_interface.h"
#include "nphy_dl_che_om_def.h"

#ifdef __cplusplus
#if __cplusplus
    extern "C"{
#endif
#endif /* __cplusplus */

typedef struct {
    uint16_t sysFIdx;
    uint16_t slotInSysF;
} NPHY_CHE_OmQclRptHeadStru;

typedef struct {
    uint8_t                    tciStateId;
    NPHY_CHE_RsTypeUint08      rsType;
    int16_t                    rsId;
    uint8_t                    tfCoefBuffIdx;            /* 计算相关系数的buf索引 0 1 2 */
    uint8_t                    rsv[3];
} NPHY_CHE_QclConfigBuff;

typedef struct {
    uint8_t                    tfCoefparaValidFlag : 1;        /* 实时计算的相关系数是否可用标志 */
    uint8_t                    tfCoefValidPingpangIdx : 1;     /* 计算好的相关系数的buf pingpang 索引 0 1 */
    uint8_t                    timeCoefValidPingpangIdx : 1;   /* 计算好的相关系数的buf pingpang 索引 0 1 */
    uint8_t                    timeCoefparaValidFlag : 1;      /* 实时计算的相关系数是否可用标志 */
    uint8_t                    fcoefUpdateFlag : 1;            /* 频域相关系数刷新指示 */
    uint8_t                    rsv1: 2;
    uint8_t                    psdValid : 1;                   /* psd系数有效指示 */
    uint8_t                    doppler;
    uint8_t                    trms;
    uint8_t                    rsv;
    int32_t                    timeOffset; /* 相关系数的定时偏差（主环路的定时调整值）,补偿在实时频域维纳滤波系数上 */
    int32_t                    freqOffset;                     /* 相关系数的频率偏差 */
} NPHY_CHE_QclCoefConfigBuff;

#define NPHY_CHE_OM_RPT_CODE_POINT_NUM    (2)
#define NPHY_CHE_OM_RPT_COEFBUF_NUM       (5)

/* tci 状态上报 */
typedef struct {
    NPHY_CHE_OmQclRptHeadStru  head;
    NPHY_CHE_QclConfigBuff     tciStateFreqOm[NPHY_CHE_OM_RPT_CODE_POINT_NUM]; /* 频域qcl 信息 */
    NPHY_CHE_QclConfigBuff     tciStateTimeOm[NPHY_CHE_OM_RPT_CODE_POINT_NUM]; /* 时域qcl 信息 */
    NPHY_CHE_QclCoefConfigBuff qclBufOm[NPHY_CHE_OM_RPT_COEFBUF_NUM];          /* 相关系数buf结果 */
    /* 5020新增 相关系数buf池化om */
    uint32_t                   tfCoefBuffMap;                            /* 过程分配的实时相关系数buf个数3个或者5个 */
}NPHY_CHE_TciStateRpt;
/* QCL config om rpt */

/* 4 bytes */
typedef struct {
    uint8_t                nzpResId;
    uint8_t                nzpCsiResSetId;
    uint8_t                tfSyncQclIdx;        /*基于外层的bitmap生成的时频内部的QclIdx的索引*/
    uint8_t                rsv;

    uint32_t               pdcPdsBitmap;       /* 6 bit according interface defination */
}NPHY_CHE_QclRsBufRpt;

typedef struct {
    NPHY_CHE_OmQclRptHeadStru head;
    NPHY_CHE_QclRsBufRpt   trsRpt[NPHY_DL_QCL_TRS_MAX_NUM];
    NPHY_CHE_QclRsBufRpt   csirsRpt[NPHY_DL_QCL_CSI_RS_MAX_NUM];
    uint8_t                mtrpCfgFlag;
    uint8_t                activeFlag;
    uint8_t                qclTrsBitmap;                        /*B5010, TRS最大0x3*/
    uint8_t                qclCsiBitmap;                        /*B5010, CSI最大0x3*/
}NPHY_CHE_QclBufRpt;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __NPHY_DL_CHE_QCL_OM_DEF_H__ */

