
#ifndef DIAG_ELF_LPHY_DEM_H
#define DIAG_ELF_LPHY_DEM_H


/*
 * 1 其他头文件包含
 */
#include "lphy_feature.h"
#include "lphy_csi_om_def.h"
#include "lphy_dem_om_def.h"
#include "lphy_paramgt_om_base_def.h"
#include "lphy_paramgt_dt_base_def.h"
#include "lphy_che_om_def.h"
#include "ul1m_lphy_che_om.h"
#include "ul1m_lphy_est_om.h"
#include "lphy_est_om_base_def.h"
#include "lphy_ul_om_def.h"
#include "lphy_dec_om_def.h"
#include "lphy_chanctrl_om_def.h"
#include "ul1m_lphy_ul_om.h"
#include "ul1m_lphy_csi_om.h"
#include "ul1m_lphy_dem_om.h"
#include "ul1m_lphy_dec_om.h"
#include "lphy_dlserv_om_def.h"
#include "lphy_sched_om_def.h"
#include "lphy_l1c_ll1d_channel.h"
#include "lphy_dl_sched_om_def.h"
#include "lphy_dec_interface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif
/* cqi */
#define LPHY_CQI_MAIN \
    enum LPHY_CQI_OmTraceType  enLPHY_CQI_OmTraceType; \
    enum LPHY_CQI_OmFileId     enLPHY_CQI_OmFileId; \
    enum LPHY_CQI_AcqiTriggerIndex enLPHY_CQI_AcqiTriggerIndex; \
    enum LPHY_CSI_LayerNumIndex enLPHY_CSI_LayerNumIndex; \
    LPHY_CSI_ReqCtrlSwitch     stLPHY_CSI_ReqCtrlSwitch; \
    LPHY_CSI_ReqCfg0           stLPHY_CSI_ReqCfg0; \
    LPHY_CSI_ReqCfg1           stLPHY_CSI_ReqCfg1; \
    LPHY_CSI_ReqCfgPiling      stLPHY_CSI_ReqCfgPiling; \
    LPHY_CSI_ReqRptBitPackPiling stLPHY_CSI_ReqRptBitPackPiling; \
    LPHY_CSI_ReqCfgInterface   stLPHY_CSI_ReqCfgInterface; \
    LPHY_CSI_OmCfgDl           stLPHY_CSI_OmCfgDl; \
    LPHY_CSI_OmCfgUl           stLPHY_CSI_OmCfgUl; \
    LPHY_CSI_OmPdeRpt          stLPHY_CSI_OmPdeRpt; \
    LPHY_CSI_OmPdeSlotCfg      stLPHY_CSI_OmPdeSlotCfg; \
    LPHY_CSI_OmPeriodRpt       stLPHY_CSI_OmPeriodRpt; \
    LPHY_CSI_OmAperiodRpt      stLPHY_CSI_OmAperiodRpt; \
    LPHY_RLM_OmCalcCfg         stLPHY_RLM_OmCalcCfg; \
    LPHY_RLM_OmEsnrRpt         stLPHY_RLM_OmEsnrRpt; \
    LPHY_CSI_OmCheCsirsRpt     stLPHY_CSI_OmCheCsirsRpt; \
    LPHY_CSI_DtCqiPeriodRpt    stLPHY_CSI_DtCqiPeriodRpt; \
    LPHY_CSI_DtCqiAperiodRpt   stLPHY_CSI_DtCqiAperiodRpt; \
    LPHY_CSI_OmRankAdpRpt      stLPHY_CSI_OmRankAdpRpt

/* ul */
#define LPHY_Ul_OM_MAIN \
    enum LPHY_UL_FakeType           enLPHY_UL_FakeTypeUint08; \
    enum LPHY_UL_OmMsgRptType       enLPHY_UL_OmMsgRptTypeUint08; \
    LPHY_Ul_OmPwrStub               stLPHY_UL_OmPwrStubReq; \
    LPHY_UL_OmReqPara               stLPHY_UL_OmUciReq; \
    LPHY_UL_OmUciRpt                stLPHY_UL_OmUciRpt; \
    LPHY_UL_OmPuschRpt              stLPHY_UL_OmPuschRpt; \
    LPHY_UL_OmPucchRpt              stLPHY_UL_OmPucchRpt; \
    LPHY_UL_OmRandomAccessRpt       stLPHY_UL_OmRandomAccessRpt; \
    LPHY_UL_OmSrsRpt                stLPHY_UL_OmSrsRpt; \
    LPHY_UL_OmCommInfoRpt           stLPHY_UL_OmCommInfoRpt; \
    LPHY_UL_OmReqBitmapPara         stLPHY_UL_OmCaptureReq; \
    LPHY_UL_OmCycleRpt              stLPHY_UL_OmCycleRpt; \
    LPHY_UL_OmReqPeriodPara         stLPHY_UL_OmHarqBlerReq; \
    LPHY_UL_OmHandCycleHeadRpt      stLPHY_UL_OmHandCycleHeadRpt; \
    LPHY_UL_OmHandCycleDataRpt      stLPHY_UL_OmHandCycleDataRpt; \
    LPHY_UL_OmHandCycleRpt          stLPHY_UL_OmHandCycleRpt; \
    LPHY_UL_SgHarqBler              stLPHY_UL_SgHarqBler; \
    LPHY_UL_OmPrintInfo             stLPHY_UL_OmPrintInfo; \
    LPHY_UL_OmCommonRptData         stLPHY_UL_OmCommonRptData; \
    LPHY_UL_OmCellConfigRpt         stLPHY_UL_OmCellConfigRpt; \
    LPHY_UL_OmBbpRptReqPara         stLPHY_UL_OmBbpRptReqPara;  \
    LPHY_UL_DtPowerInfoRpt          stLPHY_UL_DtPowerInfoRpt; \
    LPHY_UL_DtPuschInfoRpt          stLPHY_UL_DtPuschInfoRpt; \
    LPHY_UL_DtSchedTpInfoRpt        stLPHY_UL_DtSchedTpInfoRpt; \
    LPHY_UL_DtHarqInfoRpt           stLPHY_UL_DtHarqInfoRpt; \
    LPHY_UL_DtRandomAccessInfoRpt   stLPHY_UL_DtRandomAccessInfoRpt; \
    LPHY_UL_DtTaInfoRpt             stLPHY_UL_DtTaInfoRpt; \
    LPHY_UL_DtPuschHarqBlerInfoRpt  stLPHY_UL_DtPuschHarqBlerInfoRpt; \
    LPHY_UL_DtSchedInfoRpt          stLPHY_UL_DtSchedInfoRpt; \
    LPHY_UL_DtPhichBlerRpt          stLPHY_UL_DtPhichBlerRpt; \
    LPHY_OM_Ll1uKeyTimingRpt        stLPHY_OM_Ll1uKeyTimingRpt; \
    LPHY_UL_GrantFakeRpt            stLPHY_UL_GrantFakeRpt;\
    LPHY_UL_OmMsgRptInfo            stLPHY_UL_OmMsgRptInfo

/* DEM OM */
#define LPHY_DEM_OM_MAIN \
    enum LPHY_DEM_OmRptErrType       enLPHY_DEM_OmRptErrTypeUint08; \
    enum LPHY_DEM_PdsTranScheme      enLPHY_DEM_PdsTranScheme; \
    enum LPHY_DEM_DlDciType          enLPHY_DEM_DlDciTypeUint8; \
    enum LPHY_DEM_RntiType           enLPHY_DEM_RntiTypeUint8; \
    enum LPHY_DEM_DciFakeType        enLPHY_DEM_DciFakeTypeUint8; \
    LPHY_DEM_OmRptInfo               stLPHY_DEM_OmRptInfo; \
    LPHY_DEM_OmErrRptMsgInfo         stLPHY_DEM_OmErrRptMsgInfo; \
    LPHY_DEM_OmPdcRptInfo            stLPHY_DEM_OmPdcRptInfo; \
    LPHY_DEM_OmPdsRpt                stLPHY_DEM_OmPdsRpt; \
    LPHY_DEM_OmIrcRpt                stLPHY_DEM_OmIrcRpt; \
    LPHY_DEM_OmIcIrcRpt              stLPHY_DEM_OmIcIrcRpt; \
    LPHY_DEC_OmCrcOkRpt              stLPHY_DEC_OmCrcOkRpt; \
    LPHY_DEM_OmRptEn                 stLPHY_DEM_OmRptEn; \
    LPHY_DEM_OmPdcStub               stLPHY_DEM_OmPdcStub; \
    LPHY_DEM_OmPdsStub               stLPHY_DEM_OmPdsStub; \
    LPHY_DEM_OmIrcStub               stLPHY_DEM_OmIrcStub; \
    LPHY_DEM_OmIcIrcStub             stLPHY_DEM_OmIcIrcStub; \
    LPHY_DEM_OmPbBbpRegs             stLPHY_DEM_OmPbBbpRegs; \
    LPHY_PARAMGT_DtCfiRpt            stLPHY_PARAMGT_DtCfiRpt;\
    LPHY_PARAMGT_DtPdcchGrantStatRpt stLPHY_PARAMGT_DtPdcchGrantStatRpt;\
    LPHY_PARAMGT_DtPdcchDlGrantRpt   stLPHY_PARAMGT_DtPdcchDlGrantRpt;\
    LPHY_PARAMGT_DtPdschMcsRbStatRpt stLPHY_PARAMGT_DtPdschMcsRbStatRpt;\
    LPHY_PARAMGT_DtDlschBlerRpt      stLPHY_PARAMGT_DtDlschBlerRpt;\
    LPHY_PARAMGT_DtPdcchBlerRpt      stLPHY_PARAMGT_DtPdcchBlerRpt;\
    LPHY_PARAMGT_DtDlThroughputRpt   stLPHY_PARAMGT_DtDlThroughputRpt;\
    NlBpchRptRegsType                stNlBpchRptRegsType; \
    NlBpchCfgRegsType                stNlBpchCfgRegsType; \
    LPHY_DEC_OmSchCfgRegs            stLphyDecOmSchCfgRegs;\
    LPHY_DEC_OmSchRptRegs            stLPHY_DEC_OmSchRptRegs; \
    LPHY_DEC_SchHarqInfo             stLphyDecSchHarqInfo; \
    NEUN_DEC_HarqBorrow              stNeunDecHarqBorrow; \
    LPHY_DEC_OmRptMsgInfo            stLphyDecOmRptMsgInfo
/* CHE OM */
#define LPHY_CHE_OM_MAIN \
    enum LPHY_CHE_OmModuleId         enLPHY_CHE_OmModuleIdUint08; \
    LPHY_CHE_OmCommStub              stLPHY_CHE_OmCommStub; \
    LPHY_CHE_OmRptEn                 stLPHY_CHE_OmRptEn; \
    LPHY_CHE_OmCfgCfcCrs             stLPHY_CHE_OmCfgCfcCrs; \
    LPHY_CHE_OmCfgCfcDrs             stLPHY_CHE_OmCfgCfcDrs; \
    LPHY_CHE_OmCfgDft                stLPHY_CHE_OmCfgDft; \
    LPHY_CHE_OmPbCfgInfo             stLPHY_CHE_OmPbCfgInfo; \
    LPHY_CHE_OmCrsCfgInfo            stLPHY_CHE_OmCrsCfgInfo; \
    LPHY_CHE_OmCrsPdeRpt             stLPHY_CHE_OmCrsPdeRpt; \
    LPHY_CHE_OmDrsCfgInfo            stLPHY_CHE_OmDrsCfgInfo; \
    LPHY_CHE_OmDrsPdeRpt             stLPHY_CHE_OmDrsPdeRpt; \
    LPHY_CHE_OmIcRptInfo             stLPHY_CHE_OmIcRptInfo; \
    LPHY_CHE_OmIcPde1stRptInfo       stLPHY_CHE_OmIcPde1stRptInfo; \
    LPHY_CHE_OmIcPde2ndRptInfo       stLPHY_CHE_OmIcPde2ndRptInfo; \
    LPHY_CHE_OmFpdsCfcRpt            stLPHY_CHE_OmFpdsCfcRpt
/* EST OM */
#define LPHY_EST_OM_MAIN \
    enum LPHY_EST_OmModuleId         enLPHY_EST_OmModuleIdUint08; \
    LPHY_EST_OmRptEn                 stLPHY_EST_OmRptEn; \
    LPHY_EST_OmPdeCfgStub            stLPHY_EST_OmPdeCfgStub; \
    LPHY_EST_OmCalcParaStub          stLPHY_EST_OmCalcParaStub; \
    LPHY_EST_OmResultStub            stLPHY_EST_OmResultStub; \
    LPHY_EST_OmEstPdeRpt             stLPHY_EST_OmEstPdeRpt; \
    LPHY_EST_OmTcorrInfoRpt          stLPHY_EST_OmTcorrInfoRpt;  \
    LPHY_EST_OmMLDopplerRpt          stLPHY_EST_OmMLDopplerRpt;  \
    LPHY_EST_OmPsdInfoRpt            stLPHY_EST_OmPsdInfoRpt;  \
    LPHY_EST_OmFinalDopplerRpt       stLPHY_EST_OmFinalDopplerRpt;  \
    LPHY_EST_OmHstInfoRpt            stLPHY_EST_OmHstInfoRpt;  \
    LPHY_EST_OmTrmsInfoRpt           stLPHY_EST_OmTrmsInfoRpt;  \
    LPHY_EST_OmAwgnInfoRpt           stLPHY_EST_OmAwgnInfoRpt;  \
    LPHY_EST_OmRiseInfoRpt           stLPHY_EST_OmRiseInfoRpt;  \
    LPHY_EST_OmEstTimeCfgRpt         stLPHY_EST_OmEstTimeCfgRpt;  \
    LPHY_EST_OmEstFreqCfgRpt         stLPHY_EST_OmEstFreqCfgRpt
/* DEC OM */
#define LPHY_DEC_OM_MAIN \
    enum LPHY_DEC_TrigStopType       trigStopType; \
    LPHY_DL_DecPdsOmReq              stLphyDecPdsOmReq; \
    LPHY_DEC_BlerOm                  stLPHY_DEC_BlerOm; \
    LPHY_DEC_ThroughputOm            stLPHY_DEC_ThroughputOm; \
    LPHY_DEC_HarqBlerClac            stLphyDecHarqBlerCalc; \
    LPHY_DEC_OmTrigStopReq           stLphyDecOmTrigStopReq; \
    LPHY_DEC_OmDciFieldLen           stLphyDecOmDciFieldLen; \
    LPHY_DEC_OmDlDciFieldLen         stLphyDecOmDlDciFieldLen; \
    LPHY_DEC_OmDci1CLen              stLphyDecOmDci1CLen; \
    LPHY_DEC_OmCommDciFieldLen       stLphyDecOmCommDciFieldLen; \
    LPHY_DEC_OmDciLenRpt             stLphyDecOmDciLenRpt; \
    LPHY_DEC_OmDlDciFieldLenRpt      stLphyDecOmDlDciFieldLenRpt; \
    LPHY_DEC_OmCommDciFieldLenRpt    stLphyDecOmCommDciFieldLenRpt
/* CHANCTRL OM */
#define LPHY_CHANCTRL_OM_MAIN \
    enum LPHY_CHANCTRL_OmRptMsgType  enLPHY_CHANCTRL_OmRptMsgTypeUint08; \
    LPHY_CHANCTRL_OmRptMsgInfo       stLPHY_CHANCTRL_OmRptMsgInfo; \
    LPHY_CHANCTRL_OmCfiPredMsgInfo   stLPHY_CHANCTRL_OmCfiPredMsgInfo
/* DLSERV OM */
#define LPHY_DLSERV_OM_MAIN \
    LPHY_DLSERV_CcCommCfgInfo        stLPHY_DLSERV_CcCommCfgInfo; \
    LPHY_DLSERV_omDbufInfo           stLPHY_DLSERV_omDbufInfo; \
    LPHY_L1D_L1C_LpmSymbLpcNtf       stLphyL1dL1cLpmSymbLpcNtf
/* LL1D SCHED OM */
#define LPHY_L1D_SEHED_OM_MAIN \
    LPHY_OM_Ll1dCycleRpt              l1dCycleRpt;\
    LPHY_SCHED_MailCounter            msgCycleRpt;\
    LPHY_OM_Ll1dKeyTimingRpt          l1dKeyTimingRpt
/* lphy dem degin */
#define LPHY_DEM_MAIN_BASE \
    LPHY_DEM_OmDtReqPara            demOmDtReqPara
/* lphy dem end */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* end of diag_elf_lphy.c */

