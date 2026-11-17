

#ifndef ELF_NPHY_FESP_H
#define ELF_NPHY_FESP_H


/*
 * 1 其他头文件包含
 */
#include "nphy_basedef_enum.h"
#include "nphy_fec_om_def.h"
#include "nphy_fec_om_base_def.h"
#include "neun_afc_interface.h"
#include "nphy_dl_afc_interface.h"
#include "nphy_tsn_interface.h"
#include "nphy_sfi_om_def.h"
#include "ul1m_nphy_sfi_om.h"
#include "nphy_sfi_om_base_def.h"
#include "nphy_sfas_om_base_def.h"
#include "nphy_tru_om_def.h"
#include "nphy_tfpara_om_def.h"
#include "nphy_tfsync_om_def.h"
#include "nphy_agc_ssb_om_base_def.h"
#include "nphy_agc_dem_om_base_def.h"
#include "ul1m_nphy_cycle_om.h"
#include "nphy_dl_tfsync_interface.h"
#include "nphy_dl_tfpara_interface.h"
#include "neun_ll1d_tfsync_win_interface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/* FEC om */
#define NPHY_FEC_OM_MAIN \
    NPHY_FEC_OmCcReqInfo                                        ccReqInfo;

#define NPHY_SFI_OM_MAIN \
    enum NPHY_SFI_OmSwitch                                      nphySfiOmSwitch; \
    enum NPHY_SFI_OmRptMsg                                      nphySfiOmRpt; \
    NPHY_SFI_OmCtrl                                             nphySfiOmCtrl; \
    NPHY_SFI_WindowRptInfo                                      nphySfiWindowInfo; \
    NPHY_SFI_EventRptInfo                                       nphySfiCcInfo;  \
    NPHY_SFAS_EventRptInfo                                      nphySfasCcInfo

/* AFC */
#define NPHY_AFC_MAIN \
    NPHY_AFC_DmrsBplPara                                        nphyDmrsBplPara; \
    NEUN_AFC_PredictTempComp                                    predictTempComp;
/* TRU */
#define NPHY_TRU_MAIN \
    enum NPHY_TRU_LoopType                                      nphyTruloopTypeUint08; \
    NPHY_FEU_HalTsnIrigbTimeInfo                                tsnIrigbTimeInfo; \
    NPHY_TSN_Sib9TimeInfo                                       tsnSib9TimeInfo; \
    NPHY_TSN_CtrlInfo                                           tsnCtrlInfo; \
    NPHY_TSN_RptInfo                                            tsnRptInfo;
/* TFSYNC */
#define NPHY_TFSYNC_MAIN \
    enum NPHY_TFSYNC_OmSwitch                                   nphyTfsyncOmSwitchUint08; \
    enum NPHY_TFSYNC_CtrlState                                  nphyTfsyncCtrlStateUint08; \
    enum NPHY_TFSYNC_SauCcState                                 nphyTfsyncSauCcStateUint08; \
    enum NPHY_TFSYNC_RsTaskState                                nphyTfsyncRsTaskStateUint08; \
    enum NRRC_NPHY_CsiRsCdmType                                 nphyTfsyncCsiRsCdmTypeUint8; \
    enum NPHY_TFSYNC_SsbType                                    nphyTfsyncSsbTypeUint08; \
    enum NEUN_TFSYNC_SinrState                                  nphyTfsyncSinrStateUint08; \
    enum NPHY_TFSYNC_OmRptType                                  nphyTfsyncOmRptTypeUint08; \
    NPHY_TFSYNC_SauSampOmInfo                                   nphyTfsyncSauSampOmInfo; \
    NPHY_TFSYNC_SauSampOmPara                                   nphyTfsyncSauSampOmPara; \
    NPHY_TFSYNC_SauSamp                                         nphyTfsyncSauSamp; \
    NPHY_TFSYNC_TaskCtrl                                        nphyTfsyncTaskCtrl; \
    NPHY_TFSYNC_CcSampCtrl                                      nphyTfsyncCcSampCtrl; \
    NPHY_TFSYNC_FtfeRptCtrl                                     nphyTfsyncFtfeRptCtrl; \
    NPHY_TFSYNC_RsSampCtrl                                      nphyTfsyncRsSampCtrl; \
    NEUN_TFSYNC_TimeStamp                                       nphyTfsyncTimeStamp; \
    NPHY_TFSYNC_RsSampInfo                                      nphyTfsyncRsSampInfo; \
    NPHY_TFSYNC_SsbCtrl                                         nphyTfsyncSsbCtrl; \
    NPHY_TFSYNC_SsbInfo                                         nphyTfsyncSsbInfo; \
    NPHY_TFSYNC_ReqReportEna                                    nphyTfsyncReqReportEna; \
    NEUN_TFSYNC_RecvWinInfo                                     nphyTfsyncWinPara; \
    enum NEUN_TFSYNC_RecWinMode                                 nphyTfsyncRecWinModeUint08; \
    NEUN_TFSYNC_WinParaStub                                     nphyTfsyncParaStub; \
    NPHY_TFSYNC_TrsDdrSamp                                      nphyTfsyncTrsDdrSamp; \
    NEUN_TFSYNC_PccQualityInfo                                  nphyTfsyncPccQuality; \
    NPHY_TFSYNC_SibTrsOm                                        nphyTfsyncSibTrsOm; \
    NPHY_TFSYNC_RecPbOmParas                                    nphyTfsyncRecPbOm;
/* TFPARA */
#define NPHY_TFPARA_MAIN \
    enum NEUN_TFPARA_OmSwitch                                nphyTfparaOmSwitchUint08; \
    NEUN_TFPARA_ReqReportEna                                 nphyTfparaReqReportEna; \
    NPHY_TFPARA_OutPara                                      nphyTfparaOutPara; \
    NPHY_TFPARA_CcInfo                                       nphyTfparaCcInfo; \
    NEUN_TFPE_SnrInfo                                        nphyTfparaSnrInfo; \
    NEUN_TFPE_LinearData                                     nphyTfparaLinearData; \
    NEUN_TFPE_RsrpNoiseSnr                                   nphyTfparaRsrpNoise; \
    NPHY_TFPARA_OmRpt                                        nphyTfparaOmRpt;

/* nphy agc begin */
#define NPHY_AGC_MAIN_BASE \
    enum NPHY_AGC_BbpOmType                     NPHY_AGC_BbpOmTypeUint32; \
    enum NPHY_AGC_WorkModeReq                   agcWorkMode; \
    NPHY_AGC_SsbPwrOmInfo                       agcSsbPwrOmInfo; \
    NPHY_AGC_CcCalcInfo                         agcCcCalcInfo; \
    NPHY_AGC_DemH2lMsg                          agcDemH2lMsg; \
    NPHY_AGC_DemL2hMsg                          agcDemL2hMsg; \
    NPHY_AGC_ParaOmInfo                         agcParaOmInfo; \
    NPHY_AGC_WbRssiCtrl                         agcWbRssiCtrl; \
    NPHY_AGC_BbpInfoRpt                         agcBbpInfoRpt; \
    NPHY_AGC_WbRssiOmInfo                       agcWbRssiOmInfo; \
    NPHY_AGC_SsbWbSlotBuf                       agcSsbWbRssiOmInfo; \
    NPHY_AGC_WbSsbPwr                           agcWbSsbPwrRpt;  \
    NPHY_AGC_WbSsbCalcBuf                       agcWbSsbCalcBuf; \
    NPHY_AGC_SsbPosRptInfo                      agcSsbPosRpt; \
    NPHY_AGC_PdsDmrsInfo                        agcDmrsOmInfo; \
    NPHY_AGC_SsbWbRssiBuf                       agcPickedRssiRpt; \
    NPHY_AGC_SsbH2lMsg                          agcSsbH2lMsg; \
    NPHY_AGC_SsbL2hMsg                          agcSsbL2hMsg;

/* nphy agc end */

/* nphy cycle begin */
#define NPHY_CYCLE_MAIN_BASE \
    NPHY_OM_Ml1cCycleRpt                        cycleMl1cRpt; \
    NPHY_OM_Ml1cKeyTimingRpt                    keyTimingMl1cRpt; \
    NPHY_OM_Ll1dCycleRpt                        cycleL1DRpt; \
    NPHY_OM_Ll1dKeyTimingRpt                    keyTimingLl1dRpt

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* end of hids_elf_nphy.c */

