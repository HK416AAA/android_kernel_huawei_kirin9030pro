

/*
 * 1 Other header include
 */
#ifndef __UPHY_OM_DEF_H__
#define __UPHY_OM_DEF_H__

#include "uphy_typedef.h"
#include "uphy_om_base_def.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

typedef struct {
    union {
        uint32_t CfgUint32;
        struct {
            uint32_t                    pdeOamCfg   :  4;
            uint32_t                    rsv         : 28;
        } cfgEnBit;
    } cfgEnUn;
    union {
        uint32_t logEnUint32;
        struct {
            uint32_t                  pdeTopLogEn    : 1;
            uint32_t                  pdeBclLogEn    : 1;
            uint32_t                  pdeCheLogEn    : 1;
            uint32_t                  pdePdsLogEn    : 1;
            uint32_t                  pdeCsiLogEn    : 1;
            uint32_t                  pdeTfeLogEn    : 1;
            uint32_t                  pdeCsuLogEn    : 1;
            uint32_t                  pdeSmuLogEn    : 1;
            uint32_t                  pdeUmtsLogEn   : 1;
            uint32_t                  pdeGsmLogEn    : 1;
            uint32_t                  pdeLcsLogEn    : 1;
            uint32_t                  pdeDcicpLogEn  : 1;
            uint32_t                  pdeLtevLogEn   : 1;
            uint32_t                  pdeTtsLogEn    : 1;
            uint32_t                  pdeAimdmLogEn  : 1;
            uint32_t                  pdeXwlsLogEn   : 1;
            uint32_t                  pdeAipdtLogEn  : 1;
            uint32_t                  rsv1           : 8;
            uint32_t                  pdeOmTrceEn    : 1;
            uint32_t                  pdeOmErrorEn   : 1;
            uint32_t                  pdeOmWarnEn    : 1;
            uint32_t                  pdeOmInfoEn    : 1;
            uint32_t                  pdeOmDebugEn   : 1;
            uint32_t                  pdeOmAlgEn     : 1;
            uint32_t                  pdeOmAssertEn  : 1;
        } logEnBit;
    } logEnUn;
    union {
        uint32_t gateEnUint32;
        struct {
            uint32_t                  fdbufDbgEn       : 1;
            uint32_t                  cmdCfgComm       : 1;
            uint32_t                  cmdCfgSdr        : 1;
            uint32_t                  cmdRptLow        : 1;
            uint32_t                  xwlsDbgCtrl      : 1;
            uint32_t                  dcicpCfgInfo     : 1;
            uint32_t                  dcicpDbgCtrl     : 1;
            uint32_t                  ltevDbgCtrl      : 1;
            uint32_t                  bclDbgCtrl       : 1;
            uint32_t                  bclAlgRpt        : 1;
            uint32_t                  cheDbgCtrl       : 1;
            uint32_t                  cheAlgNr         : 1;
            uint32_t                  cheAlgLte        : 1;
            uint32_t                  cheNrPDot        : 1;
            uint32_t                  cheLteDmrPDot    : 1;
            uint32_t                  ttsDbgCtrl       : 1;
            uint32_t                  pdsDbgCtrl       : 1;
            uint32_t                  pdsHbufLlrCfgRpt : 1;
            uint32_t                  csiDbgCtrl0      : 1;
            uint32_t                  csiDbgCtrl1      : 1;
            uint32_t                  gsmCDbgCtrl      : 4;
            uint32_t                  gsmADbgCtrl      : 1;
            uint32_t                  umtsDbgCtrl      : 7;
        } gateEnBit;
    } gateEnUn;
    union {
        uint32_t tfeRptUint32;
        struct {
            uint32_t                  tfeTaskType      : 4;
            uint32_t                  tfeRscIdx        : 4;
            uint32_t                  tfeLsSmpLen      : 5;
            uint32_t                  tfeLsSmpMode     : 1;
            uint32_t                  tfeLsSmpEn       : 1;
            uint32_t                  tfePdpSmpSel     : 1;
            uint32_t                  tfePdpSmpEn      : 1;
            uint32_t                  tfeCirSftBitSmpE : 1;
            uint32_t                  tfePktHeadSmpEn  : 1;
            uint32_t                  tfeAfcSmpEn      : 1;
            uint32_t                  tfeEstOfdmWin    : 1;
            uint32_t                  tfeEstTcorr      : 1;
            uint32_t                  tfeEstTcorrKEn   : 1;
            uint32_t                  tfeEstFcorr      : 1;
            uint32_t                  sumDifCtrl       : 1;
            uint32_t                  smuCtrlEn        : 3;
            uint32_t                  csuInfoEn        : 1;
            uint32_t                  csuAlgEn         : 1;
            uint32_t                  lcsPdpEn         : 1;
            uint32_t                  lcsAlgEn         : 1;
        } tfeRptBit;
    } tfeRptUn;
} UPHY_OM_ReqPdeLogEn;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif


#endif

