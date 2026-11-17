
#ifndef __LPHY_V2X_DL_OM_DEF_H___
#define __LPHY_V2X_DL_OM_DEF_H___

/*
 * 1 头文件包含
 */
#include "ltevphy_feature.h"
#include "uphy_om_interface.h"
#include "vmac_phy_interface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

enum LPHY_V2X_DEM_OmRptMsg {
    LPHY_V2X_DEM_INFO_RPT = LVPHY_OM_L1MSG_ID(LVPHY_MODULE_ID_DEM, 0x00),
    LPHY_V2X_PSBCH_RSL_INFO,
};

typedef struct {
    uint8_t  valid     : 1;
    uint8_t  priority  : 3;
    uint8_t  resResv   : 4;

    uint8_t  resIndVal;
    uint8_t  psschRbNum;          /* DA RB数36.213 14.1.1.4c */
    uint8_t  psschRbStart;        /* DA 起始位置 RRC res pool指示 */
    uint8_t  transFormat : 1;
    uint8_t  rsvd1 : 7;
    uint8_t  harqMergeFlag;

    uint16_t  timeGap   : 4;
    uint16_t  mcs       : 5;
    uint16_t  reTxIdx   : 1;
    uint16_t  fakeVal   : 6;

    uint32_t  sciVal;
    uint16_t  freqInd;
    int16_t   freqOfst;
    uint16_t  timeInd;
    int16_t   timeOfst;
    int16_t   tfeRx0Snr;
    int16_t   tfeRx1Snr;
    int8_t    rsrpVal;
    uint8_t   rsvd[3];
} PSCCH_OM_INFO;


typedef struct {
    uint8_t   valid:1;
    uint8_t   crcFlag:1;
    uint8_t   shifitVal:6;
    int8_t    pssSnr;
    uint16_t  crcVal;
    uint32_t  tbsize;
    uint32_t  scramInit;
    uint16_t  freqInd;
    int16_t   freqOfst;
    uint16_t  timeInd;
    int16_t   timeOfst;
    int16_t   tfeRx0Snr;
    int16_t   tfeRx1Snr;
    uint32_t  ltevCapDataLenRpt:16;
    uint32_t  rptLtevCbCompInd:16;
    uint32_t  ltevCbCrcRpt: 16;
    uint32_t  rptLtevCbWrDiscInd:16;
} PSSCH_OM_INFO;

typedef struct {
    PSCCH_OM_INFO   pscchOmInfo;
    PSSCH_OM_INFO   psschOmInfo;
} DEC_OM_INFO;

typedef struct {
    uint8_t     sbfn;
    uint8_t     rsvd;
    uint16_t    sfn;
    DEC_OM_INFO decInfo[V2XPHY_REC_MAX_USER_NUM];
} LPHY_V2X_DEC_OmRptInfo;

/*
 * 结构说明: MAC上报所需sciRsrp, snrRsrp结构体
 */
typedef struct {
    VPHY_VMAC_SciRsrpRptInfo        sciRsrpInfo;   /* MAC需要的sciRsrp信息  */
    LPHY_V2X_FtfeSnrRsrpRpt   snrRsrpInfo;   /* AT需要的snr,rsrp信息  */
} LPHY_V2X_DEC_SnrRsrpInfo;

/*
 * 结构说明: PSBCH译码结果信息
 */
typedef struct {
    uint8_t  psbType;
    int8_t   psbsSnr;
    uint8_t  crcFlag;
    uint8_t  psbSymValid;
    uint8_t  psbInvalidSymIdx;
    uint8_t  zeroSymNum;
    uint8_t  invalidSmIdx[2];
    uint16_t slssId;
    uint16_t rsv;

    uint32_t psbRsv0     : 11;  /* 第一个32bits的保留位 */
    uint32_t incovInd    : 1;   /* 解psb获取的同步源是否在E-UTRAN 1->true or 0->false */
    uint32_t subFrameNum : 4;   /* 解psb获取的子帧号 */
    uint32_t frameNum    : 10;  /* 解psb获取的帧号 */
    uint32_t tddCfg      : 3;   /* 解psb获取的tdd配置信息 */
    uint32_t bandWidth   : 3;   /* 解psb获取的带宽信息 (高位位置) */
    uint32_t  psbRsv1    : 32;  /* 第二个32bits的保留位 */

    int16_t freqOfst;
    uint16_t freqInd;
    int16_t timOfst;
    uint16_t timInd;

    int16_t rsrpLineR0;
    int16_t rsrpLineR1;
    int16_t rsrpShiftR0;
    int16_t rsrpShiftR1;
    int16_t totalGain[2]; /* 2个天线 */
    int16_t psbFftShfMaxRx0;
    int16_t psbFftShfMaxRx1;
    int32_t rsrp0dBm;
    int32_t rsrp1dBm;
    int16_t tfeRx0Snr;
    int16_t tfeRx1Snr;
} LPHY_V2X_DEC_OmPsbRslRpt;

/*
 * 3 函数实现
 */
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* end of LPHY_UL_OM_DEF_H_ */
