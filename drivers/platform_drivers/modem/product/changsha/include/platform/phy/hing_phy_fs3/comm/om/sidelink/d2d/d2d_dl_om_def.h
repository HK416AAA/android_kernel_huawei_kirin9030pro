
#ifndef __D2D_DL_OM_DEF_H___
#define __D2D_DL_OM_DEF_H___

/*
 * 1 头文件包含
 */
#include "ltevphy_feature.h"
#include "uphy_om_interface.h"
#include "hid2d_l2_phy_interface.h"
#include "d2d_basedef_struct.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

enum D2D_DEM_OmRptMsg {
    D2D_DEM_INFO_RPT = D2DPHY_OM_L1MSG_ID(D2DPHY_MODULE_ID_DEM, 0x00),
    D2D_PSBCH_RSL_INFO,
};

typedef struct {
    uint32_t  priority : 3;
    uint32_t  resResv : 4;
    uint32_t  subChnLen : 4;
    uint32_t  timeGap : 4;
    uint32_t  mcs : 5;
    uint32_t  reTxIdx     : 1;
    uint32_t  transFormat : 1;
    uint32_t  castType : 2;
    uint32_t  layer2Id : 8;

    uint8_t   valid : 1;
    uint8_t   psschRbNum : 7; /* DA RB数36.213 14.1.1.4c */
    uint8_t   psschRbStart; /* DA 起始位置 RRC res pool指示 */
    uint8_t   fakeVal;
    uint8_t   harqMergeFlag;
    uint32_t  sciVal;
    uint16_t  freqInd;
    int16_t   freqOfst;
    uint16_t  timeInd;
    int16_t   timeOfst;
    int16_t   tfeRx0Snr;
    int16_t   tfeRx1Snr;
    int8_t    rsrpVal;
    uint8_t   rsvd[3];
} D2D_PSCCH_OM_INFO;


typedef struct {
    uint8_t   valid: 1;
    uint8_t   crcFlag: 1;
    uint8_t   shifitVal: 6;
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
    uint32_t  capDataLenRpt: 16;
    uint32_t  rptCbCompInd: 16;
    uint32_t  cbCrcRpt: 16;
    uint32_t  rptCbWrDiscInd: 16;
} D2D_PSSCH_OM_INFO;

typedef struct {
    D2D_PSCCH_OM_INFO   pscchOmInfo;
    D2D_PSSCH_OM_INFO   psschOmInfo;
} D2D_DEC_OM_INFO;

typedef struct {
    uint8_t     sbfn;
    uint8_t     rsvd;
    uint16_t    sfn;
    D2D_DEC_OM_INFO decInfo[V2XPHY_REC_MAX_USER_NUM];
} D2D_DEC_OmRptInfo;

/*
 * 结构说明: MAC上报所需sciRsrp, snrRsrp结构体
 */
typedef struct {
    uint32_t                nonLocalUserSciNum;   /* MAC需要的sciRsrp信息中，非本用户的sci个数  */
    HPHY_HL2_SciRsrpRptInfo sciRsrpInfo;   /* MAC需要的sciRsrp信息  */
    D2D_FtfeSnrRsrpRpt      snrRsrpInfo;   /* AT需要的snr,rsrp信息  */
} D2D_DEC_SnrRsrpInfo;


typedef union {
    /* Define the struct bits */
    struct {
        uint32_t  manageUeNamePart1 : 4;
        uint32_t  withSyncSourceId : 1;   /* 0：不携带同步源ID，携带管理UE名称，1：携带了同步源ID*/
        uint32_t  broadcastSrv     : 1;
        uint32_t  indicator1       : 8;
        uint32_t  subFrameNum      : 4;   /* 解psb获取的子帧号 */
        uint32_t  frameNum         : 10;  /* 解psb获取的帧号 */
        uint32_t  hiD2dVersion     : 3;
        uint32_t  msgType          : 1;

        uint32_t  srv1              : 16;
        uint32_t  manageUeNamePart2 : 16;
    } withNameBits1;
    struct {
        uint32_t  manageUeNamePart2 : 32;

        uint32_t  srv               : 16;
        uint32_t  crc               : 4;
        uint32_t  manageUeNamePart3 : 12;
    } withNameBits2;
    struct {
        uint32_t commDomainId1   : 14;
        uint32_t subFrameNum       : 4;
        uint32_t frameNum          : 10;
        uint32_t hiD2dVersion      : 4;

        uint32_t rsv               : 31;
        uint32_t commDomainId2   : 1;
    } d2dProcMibInfo;
    /* psb结果直接赋值给u32即可，按照上边比特位读取即可获得内部内容 */
    uint32_t    u32[2];
} D2D_PROC_PsbOmInfoUnion;

/*
 * 结构说明: PSBCH译码结果信息
 */
typedef struct {
    uint8_t  psbType;
    int8_t   psbsSnr;
    uint8_t  crcFlag;
    uint8_t  psbDmrsValidNum;
    uint8_t  psbInvalidSymIdx;
    uint8_t  zeroSymNum;
    uint8_t  invalidSmIdx[2];

    uint16_t slId;       /* 小区ID */
    uint16_t  rsv;  /* 预留1字节 */
    D2D_PROC_PsbOmInfoUnion    psbInfo;

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
} D2D_DEC_OmPsbRslRpt;
/*
 * 结构说明: PSSCH误码率统计
 */
typedef struct {
    uint16_t primaryErrorNum;
    uint16_t primaryTotalNum;
    uint16_t retransErrorNum;
    uint16_t retransTotalNum;
    uint16_t errorNum;
    uint16_t totalNum;
} D2D_DEC_BlerCount;

/*
 * 结构说明: PSSCH误码率统计上报
 */
typedef struct {
    D2D_DEC_BlerCount       singleBlerInfo;
    D2D_DEC_BlerCount       accuBlerInfo;
    LPHY_V2X_PssPscStatInfo singlePssPscStatInfo;
    LPHY_V2X_PssPscStatInfo accuPssPscStatInfo;
} D2D_DEC_BlerInfoRpt;

/*
 * 结构说明: 1s上报计数器
 */
typedef struct {
    uint32_t record32Clock;
} D2D_DEC_PerSecondRpt;

/*
 * 3 函数实现
 */
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* end of LPHY_UL_OM_DEF_H_ */
