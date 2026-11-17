
#ifndef HIDS_ELF_NPHY_H
#define HIDS_ELF_NPHY_H


/*
 * 1 其他头文件包含
 */
#include "nphy_basedef_enum.h"
#include "nphy_basedef_struct.h"
#include "nrrc_nphy_interface.h"
#include "mac_nphy_interface.h"
#include "nphy_l1c_ll1d_interface.h"
#include "nphy_l1c_ll1u_interface.h"
#include "nphy_dl_chanctrl_om_def.h"
#include "ul1m_nphy_dl_chanctrl_interface.h"
#include "nphy_dl_dem_om_def.h"
#include "neun_l1c_ll1d_interface.h"
#include "nphy_dl_che_om_def.h"
#include "nphy_dl_qcl_om_def.h"
#include "nphy_dl_che_dt_om_def.h"
#include "nphy_hal_dl_dec_interface.h"
#include "nphy_dl_serv_om_base_def.h"
#include "nphy_dl_csi_om_def.h"
#include "ul1m_nphy_dl_csi_om.h"
#include "ul1m_nphy_dl_che_om.h"
#include "nphy_dl_dec_om_def.h"
#include "nphy_hal_dl_che_interface.h"
#include "nphy_dl_sched_om_def.h"
#include "nphy_dl_lpc_interface.h"
#include "nphy_dl_lpc_om_def.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


/* NR DL CHANCTRL */
#define NPHY_DL_CHANCTRL_MAIN \
    NPHY_DL_ChanCtrlOmReq                                       dlChanCtrlOmReq ; \
    NPHY_DL_ChanOmPrintTarceInfo                                dlChanOmPrintTarceInfo; \
    NPHY_DL_ChanWarnInterface                                   dlChanWarnInterrface; \
    enum NPHY_DL_ChanWarnType                                   dlChanWarnTypeUint32; \
    NPHY_DL_ChanRptInterface                                    dlChanRptInterface; \
    enum NPHY_DL_RptInterfaceType                               dlChanRptInterfaceTypeUint32; \
    NPHY_DL_ChanRptDbuf                                         dlChanDbuf; \
    NPHY_DL_ChanTag                                             dlChanTimetag; \
    NPHY_DLSERV_UlFixedMsgOmRpt                                 dlChanUlFixedMsgOmRpt; \
    CfgParaSlotRegsType                                         stCfgParaSlotRegsType; \
    NPHY_DL_ChnlRptSlotCfgBrief                                 stCfgParaSlotRegsTypeBrief
/* NR DL DEM */
#define NPHY_DL_DEM_MAIN \
    NPHY_DEM_OmSwitch                                           dlDemSwitch; \
    NPHY_DEM_OmCwModeStub                                       dlDemCwModeStub; \
    NPHY_DEM_OmSoftShiftStub                                    dlDemSoftShiftStub; \
    NPHY_DEM_OmDagcShiftValueStub                               dlDemDagcShiftStub; \
    NPHY_DEM_OmNoiseThStub                                      dlDemNoiseThStub; \
    NPHY_DEM_OmSignFlagStub                                     dlDemSignFlagStub; \
    NPHY_DEM_OmSymPscaleStub                                    dlDemSymPscalStub; \
    NPHY_DEM_OmRePscaleStub                                     dlDemRePscaleStub; \
    NPHY_DEM_OmTriggerStub                                      dlDemTriggerStub; \
    NPHY_DEM_FcrossParaStub                                     dlDemFcrossStub; \
    NPHY_DEM_OmChInfo                                           dlDemChanInfo; \
    NPHY_DEM_OmTriggerStop                                      dlDemTriggerStopInfo; \
    enum NPHY_DEM_TriggerCondition                              dlDemTriggerCondition; \
    NPHY_DEM_MuInfRpt                                           dlDemMuInfRpt; \
    NPHY_DEM_OmRateMatchBmpRptRegs                              dlDemRateMatchResRpt; \
    NPHY_DEM_OmPdsInfoDt                                        dlDemPdsInfoDtRpt
/* NR DL CHE */
#define NPHY_DL_CHE_MAIN \
    NPHY_CHE_OmSwitch                                           dlCheSwitch; \
    NPHY_CHE_PdsIrcStub                                         dlCheIrcCfgStub; \
    NPHY_CHE_OmDmrsSnrStub                                      dlCheDmrsSnrStub; \
    NPHY_CHE_OmTimeParacalcStub                                 dlCheTimeParacalcStub; \
    NPHY_CHE_OmFreqParacalcStub                                 dlCheFreqParacalcStub; \
    NPHY_CHE_PdsStub                                            dlChePdsStub; \
    NPHY_CHE_PdcAlgStub                                         dlChePdcAlgStub; \
    NPHY_CHE_HstStub                                            dlCheHstStub; \
    NPHY_CHE_OmCommStub                                         dlCheCommRegStub; \
    NPHY_CHE_OmRptPdcChanInfo                                   dlChePdcChanInfo; \
    NPHY_CHE_PdcIrcInfo                                         dlChePdcIrcInfo; \
    NPHY_CHE_DmrsSnrRptUsual                                    dlCheDmrsSnrRptUsual; \
    NPHY_CHE_PrtTrace                                           dlChePrtTrace; \
    NPHY_CHE_PrtErr                                             dlChePrtErr; \
    NPHY_CHE_PrtWarn                                            dlChePrtWarn; \
    NPHY_CHE_TrsRpt                                             dlCheTrsRpt; \
    NPHY_CHE_TrsWienerCorrFiltRpt                               dlCheTrsWienerCorrFiltRpt; \
    NPHY_CHE_CsirsRpt                                           dlCheCsirsRpt; \
    NPHY_CHE_SsbRpt                                             dlCheSsbRpt; \
    NPHY_CHE_DmrsRptRcross                                      dlCheDmrsRptRcross; \
    NPHY_CHE_PdsDftRpt                                          dlCheDftRpt; \
    NPHY_CHE_OmRptPdcStaticInfo                                 dlCheStaticInfo; \
    NPHY_CHE_HstRpt                                             dlCheHstRpt; \
    NPHY_CHE_QclBufRpt                                          dlCheQclBufRpt; \
    NPHY_CHE_DmrsDopplerRpt                                     dlCheDmrsDopplerRpt; \
    NPHY_CHE_TciStateRpt                                        dlCheTciStateRpt;\
    NPHY_CHE_PdsChnlCfg                                         dlChePdsChnlCfg;\
    FpdsNrChCfcRegsType                                         dlCheFpdsCfg;\
    DcicpQclCfgRegsType                                         dlCheHalQclCfg;\
    NPHY_CHE_PdsDediChnlRpt                                     dlChePdeRpt;\
    NPHY_CHE_PsdJudgeRslt                                       dlChePsdJudgeRslt;\
    NPHY_CHE_PdcTripleReduceWarn                                dlChePdcTrippleReduceWarnRpt; \
    NPHY_CHE_DtPdsSnrRpt                                        dlChePdsSnrDtRpt; \
    enum NPHY_CHE_Enable                                        dlCheEnable; \
    enum NPHY_CHE_RuuMode                                       dlCheRuuMode; \
    enum NPHY_CHE_RuuSel                                        dlCheRuuSel; \
    enum NPHY_CHE_ZpFlag                                        dlCheZpFlag; \
    enum NPHY_CHE_LongTerm                                      dlCheLongTerm; \
    enum NPHY_DEM_CommChanType_                                 dlCheCommChanType_; \
    enum NPHY_CHE_SnrRsrpSel                                    dlCheSnrRsrpSel; \
    enum NPHY_CHE_StubFlag                                      dlCheStubFlag; \
    enum NPHY_CHE_NoiseEstType                                  dlCheNoiseEstType; \
    enum NPHY_CHE_WnNoiseEstCoefSel                             dlCheWnNoiseEstCoefSel; \
    enum NPHY_CHE_WienerSnrType                                 dlCheWienerSnrType; \
    enum NPHY_CHE_BbpCfgSel                                     dlCheBbpCfgSel; \
    enum NPHY_CHE_PwrOutputSel                                  dlChePwrOutputSel; \
    enum NPHY_CHE_PwrRecvantAdj                                 dlChePwrRecvantAdj; \
    enum NPHY_CHE_OmPrintError                                  dlCheOmPrintError; \
    enum NPHY_CHE_OmPrintWarn                                   dlCheOmPrintWarn; \
    enum NPHY_CHE_OmPrintTrace                                  dlCheOmPrintTrace; \
    enum NPHY_CHE_OmModuleId                                    dlCheOmModuleId
/* NR DL DEC PDS */
#define NPHY_DL_DEC_PDS_MAIN \
    enum NPHY_DEC_PdsPrintType                                  nphyPdsPrintType; \
    enum NPHY_DEC_CommChnlType                                  nphyChnlType; \
    enum NMAC_NPHY_RntiType                                     nphyRntiType; \
    NPHY_DEC_PdschDlschDecodeResult                             schDecodeResultOm; \
    NPHY_DEC_SchOmCalcPara                                      schOmCalcPara; \
    NPHY_DEC_BpchDecodeResult                                   bpchDecodeResult; \
    NPHY_DEC_BpchOmCalcPara                                     bpchOmCalcPara; \
    NPHY_DL_DecPdsParaStub                                      decPdsParaStub; \
    NPHY_DL_DecPdsOmReq                                         nphyDecPdsOmReq; \
    NPHY_DEC_BlerOm                                             nphyDecBlerOm; \
    NPHY_DEC_ThroughputOm                                       nphyDecThroughputOm; \
    NPHY_DEC_HarqBlerCalc                                       nphyDecHarqBlerCalc; \
    NPHY_DEC_DecCbDetail                                        nphyDecCbDetail; \
    NPHY_DEC_OmCrcOkRetran                                      nphyDecCrcOkRetran; \
    NPHY_DEC_PdsOmPrintPara                                     nphyDecPdsOmPrintPara; \
    NPHY_DEC_SchBbpRpt                                          nphyDecSchBbpRpt;\
    NPHY_DEC_PdsRptBpchReg                                      nphyDecBpchRegRpt;\
    NPHY_DEC_Rm                                                 nphyDecRmDtRpt; \
    NPHY_DEC_DtDLThroughputOm                                   nphyDecDlThroughputDtRpt;\
    NPHY_DEC_DtLayerRpt                                         nphyDtLayerRpt;\
    NPHY_CHR_CovCapMsg                                          nphyCovCapMsg;\
    NPHY_CHR_MaxPeakMsg                                         nphyMaxPeakInfoMsg;\
    DcicpRrcCfgRegsType                                         dcicpRrcCfgRegs
/* NR DL DEC PDC */
#define NPHY_DL_DEC_PDC_MAIN \
    enum NPHY_DEC_OmPdcTrace                                    nphyDecRptInfo; \
    enum NEUN_L1DL1C_PeiFinishType                              neunL1dL1cPeiFinishType; \
    NPHY_DL_DecPdcOmReq                                         nphyDecPdcOmReq; \
    NPHY_DEC_OmDci10SirntiDomain                                nphyDecOmDci10SirntiDomain; \
    NPHY_DEC_OmDci10RarntiDomain                                nphyDecOmDci10RarntiDomain; \
    NPHY_DEC_OmDci10CrntiDomain                                 nphyDecOmDci10CrntiDomai; \
    NPHY_DEC_OmDci11Domain                                      nphyDecOmDci11Domain; \
    NPHY_DEC_OmDci10PrntiDomain                                 nphyDecOmDci10PrntiDomain; \
    NPHY_DEC_OmRntiValueRpt                                     nphyDecOmRntiValueRpt; \
    NPHY_DEC_OmPdcchDtRpt                                       nphyDecOmPdcchDtRpt; \
    NPHY_DEC_OmBdCfgPara                                        nphyDecOmBdCfgPara; \
    NPHY_DEC_OmBdSpace                                          nphyDecOmBdSpace; \
    NPHY_DEC_OmCombbpDciLen                                     nphyDecOmCombbpDciLen; \
    NPHY_DEC_OmPdcchDtSecRpt                                    nphyDecOmPdcchDtSecRpt; \
    NPHY_DL_DciVariaDomain                                      nphyDlDciVariaDomain; \
    NPHY_DEC_OmFakeSecRpt                                       nphyDecOmFakeSecRpt; \
    NPHY_DEC_OmConctrlSwitch                                    nphyDecOmConctrlSwitch; \
    NPHY_DEC_OmPdcPrintStru                                     nphyDecOmPdcPrint; \
    NPHY_DEC_OmDci26Domain                                      nphyDecOmDci26Domain; \
    NPHY_DEC_OmFakeDci                                          nphyDecOmFakeDci; \
    NPHY_DEC_OmPdcchDtSecRpt                                    nphyDecomPdcchDtSecRpt; \
    NPHY_DEC_OmSpsActDeactInfo                                  nphyDecOmSpsActDeAct; \
    NPHY_Ll1cHl1cPeiReport                                      nphyLl1dHl1cPeiRpt; \
    NPHY_DEC_SemiStaticConfigImage                              nphyDecSemiStaticConfigImage; \
    NPHY_DEC_DynamicConfigImage                                 nphyDecDynamicConfigImage; \
    NPHY_DEC_OmPdeFalseAlarm                                    nphyDecOmPdeFalseAlarm; \
    NPHY_DEC_OmPreFake                                          nphyDecOmPreFake; \
    NPHY_DEC_OmParseFake                                        nphyDecOmParseFake

/* NR DL CSI */
#define NPHY_DL_CSI_MAIN \
    NPHY_DL_CsiCtrlOmReq                                        dlCsiCtrlOmReq; \
    NPHY_DL_CsiAlgParaStub                                      dlCsiAlgParaStub; \
    NPHY_DL_CsiOmAddrStub                                       dlCsiAddrStub; \
    NPHY_DL_RlmAlgPara                                          dlRlmAlgParaStub; \
    NPHY_DL_CsiOmTraceInfo                                      dlCsiOmTraceInfo; \
    NPHY_DL_CsiOmWarnInfo                                       dlCsiOmWarnInfo; \
    NPHY_DL_CsiOmErrInfo                                        dlCsiOmErrInfo; \
    NPHY_DL_CsiOmReportInfo                                     csiOmReportInfo; \
    NPHY_DL_CsiOmSlotInfo                                       csiOmSlotInfo; \
    NPHY_DL_CsiOmFltSnrInfo                                     csiOmFltSnrInfo; \
    NPHY_DLCSI_OmRptAPeriodicRslt                               csiOmApRptInfo; \
    NPHY_DLCSI_OmRptAPeriodicRsltDebug                          csiOmApRptInfoDebug; \
    NPHY_DL_CsiOmPdeCheRptInfo                                  csiOmPdeCheRptInfo; \
    NPHY_DL_CsiOmDtPdeCheRptInfo                                csiOmDtPdeCheRptInfo; \
    NPHY_DL_RlmOmPdeCheRptInfo                                  rlmOmPdeCheRptInfo; \
    NPHY_DL_CsiOmCalcRptParaInfo                                csiRptParaInfo; \
    NPHY_DL_CsiOmRptResSched                                    csiRptResSched; \
    NPHY_DL_RlmOmTraceInfo                                      dlRlmOmTraceInfo; \
    NPHY_DL_RlmOmWarnInfo                                       dlRlmOmWarnInfo; \
    NPHY_DL_CsiOmCmrResult                                      dlCsiOmCmrResult; \
    NPHY_DLCSI_OmExistInfo                                      dlCsiOmExistInfo; \
    NPHY_DLCSI_OmRankAdpPara                                    dlCsiOmRankAdp; \
    NPHY_CSI_PdeRptSlotRegs                                     dlCsiOmPdeRptSlotRegs; \
    NPHY_CSI_PdeNzpResRegs                                      dlCsiOmPdeNzpResRegs; \
    NPHY_CSI_PdeImResRegs                                       dlCsiOmPdeImResRegs; \
    NPHY_CSI_PdeReportSettingRegs                               dlCsiOmPdeRptSettingRegs; \
    NPHY_CSI_PdeRlmSlotRegs                                     dlRlmOmPdeSlotRegs; \
    NPHY_CSI_PdeRlmRscRegs                                      dlRlmOmPdeResRegs; \
    NPHY_DLCSI_OmAdaptCbPara                                    dlCsiOmAdaptCbPara; \
    enum NPHY_DLCSI_OmTrace                                     dlCsiOmTraceTpye; \
    enum NPHY_DLCSI_OmWarn                                      dlCsiOmWarnTpye; \
    enum NPHY_DLCSI_OmErr                                       dlCsiOmErrTpye; \
    enum NRRC_NPHY_SelCsiResCfg                                 csiResCfgTpye; \
    enum NRRC_NPHY_CsiRsCdmType                                 csiCdmType; \
    enum NRRC_NPHY_CsiRptType                                   csiRptType; \
    enum NRRC_NPHY_CsiResType                                   csiResType; \
    enum NPHY_DLRLM_OmTrace                                     dlRlmOmTraceTpye; \
    enum NPHY_DLRLM_OmWarn                                      dlRlmOmWarnTpye

/* NR DL LPC */
#define NPHY_DL_LPC_MAIN \
    NPHY_L1D_L1C_LpmSymbLpcNtf                                  nphyL1dL1cLpmSymbLpcNtf; \
    NPHY_L1D_L1C_LpmSymbParaNtf                                 nphyL1dL1cLpmSymbParaNtf; \
    NPHY_DLLPC_SymCtrl                                          nphyDllpcSymCtrl; \
    NPHY_DLLPC_SymbPSOmInfo                                     nphyDllpcSymbpsOmInfo

/* NR DL SCHED OM */
#define NPHY_DL_SCHED_OM_MAIN \
    NPHY_SCHED_MailCounter                                      msgCycleRpt

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* end of hids_elf_nphy.c */

