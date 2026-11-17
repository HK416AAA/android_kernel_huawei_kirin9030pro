

#ifndef ELF_NEUN_FESP_H
#define ELF_NEUN_FESP_H

/*
 * 1 其他头文件包含
 */
#include "neun_basedef_macro.h"
#include "neun_basedef_enum.h"
#include "neun_fec_om_typedef_interface.h"
#include "neun_wmc_om_def.h"
#include "neun_fec_om_def.h"
#include "neun_dl_afc_interface.h"
#include "neun_tru_interface.h"
#include "neun_tru_om_def.h"
#include "neun_agc_om_def.h"
#include "neun_afc_om_def.h"
#include "neun_afc_interface.h"
#include "neun_tfpara_om_def.h"
#include "neun_tfsync_om_def.h"
#include "ul1m_neun_agc_om.h"
#include "ul1m_neun_tfsync_om.h"
#include "ul1m_neun_tfpara_om.h"
#include "ul1m_neun_afc_om.h"
#include "ul1m_neun_tru_om.h"
#include "ul1m_neun_wmc_om.h"
#include "ul1m_neun_chscen_om.h"
#include "neun_feu_auto_report_om_base_def.h"
#include "neun_fec_calc_freq_interface.h"
#include "neun_fec_dfu_interface.h"
#include "neun_hal_dl_agc_interface.h"
#include "neun_chscen_interface.h"
#include "neun_fed_rfin_interface.h"
#include "neun_wmc_interface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/* WMC */
#define NEUN_WMC_MAIN \
    NEUN_FEC_CcaQueryResult                fecCcaQueryResult; \
    NEUN_WMC_ReqRptEna                     wmcRptEn; \
    NEUN_WMC_OmRptB                        wmcBInfoRpt; \
    NEUN_WMC_TraceEvtReqOmRpt              wmcEvtReqRpt; \
    NEUN_WMC_FastBRpt                      wmcFastBRpt; \
    NEUN_WMC_OmRptBCtrl                    wmcBCtrlRpt; \
    NEUN_WMC_ProcOmInfo                    wmcProcRpt; \
    NEUN_WMC_CInfo                         wmcCInfoRpt; \
    NEUN_WMC_ErrorInfo                     wmcErrRpt; \
    NEUN_WMC_ActInfoRpt                    wmcactRpt; \
    /* WMC 枚举定义 */ \
    enum NEUN_WMC_AfcProcessIdx            afcProcessType; \
    enum NEUN_TRU_WorkModeReq              truMode; \
    enum NEUN_FEC_WorkModeReq              fecMode; \
    enum NEUN_WMC_ProcActFlag              procActFlg; \
    enum NEUN_AFC_WorkMode                 afcMode; \
    enum NEUN_WMC_EvtReqRptSelChoice        evtReqRptSelChoice; \
    enum NEUN_WMC_EvtReqType               reqType; \
    enum NEUN_PROCESS_Id                   procId;
/* fec om */
#define NEUN_FEC_MAIN \
    enum NEUN_FEC_DlEventType               dlEventType; \
    enum NEUN_FEC_OmHandleType              omHandleType; \
    enum NEUN_FEC_AutoReportMsgId           autoReportMsgId; \
    enum NEUN_FEC_EventId                   eventId; \
    enum NEUN_FEC_ReportDataType            reportDataType; \
    enum NEUN_FEC_BbaRptSelChoice           bbaRptSelChoice; \
    NEUN_FEC_DbgComRptInfo                  dbgComRptInfo; \
    NEUN_FEC_DbgReqRptEn                    dbgReqRptEn; \
    NEUN_FEC_DfuFilterSwEn                  filterEn; \
    NEUN_FEC_RfDrvEventInfo                 rfDrvEventReqRptInfo; \
    NEUN_FEC_OmReportEn                     rfDrvEventReqRptEn; \
    NEUN_FEC_RfDrvEvent                     rfDrvEvent; \
    NEUN_FEC_ReadRegEn                      readRegEn; \
    NEUN_FEC_ReadRegValue                   readRegValue; \
    NEUN_FEC_ReadRegInfo                    readRegInfo; \
    NEUN_FEC_ReportData                     reportData; \
    NEUN_FEC_AutoReportPara                 autoReportPara; \
    NEUN_FEC_DfuFilterInfo                  dfuFilterRpt; \
    NEUN_FEC_TraceLogDecodeRpt              tracelog; \
    NEUN_FEC_DfuFilterSwEn                  filterByPassEn; \
    NEUN_FEC_DfuFilterInfo                  filterByPassPara;
/* AFC */
#define NEUN_AFC_MAIN \
    enum NEUN_AFC_OmSwitch                                      afcOmSwitchUint08; \
    enum NEUN_TFSYNC_RsType                                     tfsyncRsTypeUint08; \
    enum NEUN_AFC_IlState                                       afcIlStateUint08; \
    enum NEUN_AFC_PdPeriod                                      afcPdPeriodUint08; \
    enum NEUN_AFC_PdDone                                        afcPdDoneUint08; \
    enum NEUN_TFSYNC_PdpLen                                     tfsyncPdpLenUint08; \
    enum NEUN_AFC_FilterMode                                    afcFilterModeUint08; \
    enum NEUN_AFC_BlindDrms                                     afcBlindDrmsUint08; \
    enum NEUN_AFC_H2LMsgType                                    afcH2LMsgTypeUint08; \
    enum NEUN_AFC_WorkMode                                      afcWorkModeUint08; \
    enum NEUN_AFC_UpdateCause                                   afcUpdateCauseUint08; \
    enum NEUN_AFC_CrcState                                      afcCrcStateUint08; \
    enum NEUN_AFC_TempRegion                                    afcTempRegionUint08; \
    enum NEUN_AFC_SampleOmRptType                               afcSampleOmRptTypeUint08; \
    NEUN_AFC_ReqReportEna                                       afcReqReportEna; \
    NEUN_AFC_ReqFoStubEna                                       afcReqFoStubEna; \
    NEUN_AFC_ReqTcPpmStubEna                                    afcReqTcPpmStubEna; \
    NEUN_AFC_ReqFoStayEna                                       afcReqFoStayEna; \
    NEUN_AFC_ReqDtRptEna                                        afcDtRptEna; \
    NEUN_AFC_OmCommRpt                                          afcOmCommRpt; \
    NEUN_AFC_LoopFilter                                         afcLoopFilter; \
    NEUN_AFC_PdResult                                           afcPdResult; \
    NEUN_AFC_OmBplRpt                                           afcOmBplRpt; \
    NEUN_AFC_OmRpt                                              afcOmRpt; \
    NEUN_AFC_PbchCcPara                                         afcPbchCcPara; \
    NEUN_AFC_CcCfg                                              afcCcCfg; \
    NEUN_AFC_OmRptInfo                                          afcOmRptInfo; \
    NEUN_AFC_ParaUpdate                                         afcParaUpdate; \
    NEUN_AFC_SampleCtrl                                         afcSampleCtrl; \
    NEUN_AFC_HstCtrl                                            afcHstCtrl; \
    NEUN_AFC_TpaReadOm                                          afcTpaReadOm; \
    NEUN_AFC_DtReport                                           afcDtRptInfo;
/* TRU */
#define NEUN_TRU_MAIN \
    enum NEUN_TRU_SysTimEffectType                              truSysTimEffctTypeUint08; \
    enum NEUN_TRU_TimeCfgType                                   truTimeCfgTypeUint08; \
    enum NEUN_TRU_LockType                                      truLockTypeUint08; \
    enum NEUN_TRU_FftType                                       truFftTypeUint08; \
    enum NEUN_BAND_Width                                        truBandWidthUint08; \
    NEUN_TRU_CcBase                                             truCcBase; \
    NEUN_TRU_OmRptCtrl                                          truRptCtrl; \
    NEUN_TRU_OmRptInfo                                          truOmRptInfo; \
    NEUN_TRU_FilterMiniRpt                                      truFilterMiniRpt; \
    NEUN_TRU_ReqRptEn                                           truReqRptEn; \
    NEUN_TRU_ReqStub                                            truReqStub; \
    NEUN_TRU_ReqStubEn                                          truReqStubEn; \
    NEUN_TRU_RptInfo                                            truRptInfo; \
    NEUN_TRU_FilterPara                                         truFilterPara;
/* AGC */
#define NEUN_AGC_MAIN \
    enum NEUN_AGC_V2xGainType                                   agcV2xGainType; \
    enum NEUN_AGC_OmSwitch                                      agcOmSwitch; \
    NEUN_AGC_ReqRptEn                                           agcReqRptEn; \
    NEUN_AGC_ReqFixGain                                         agcReqFixGain; \
    NEUN_AGC_ReqFixGainEn                                       agcReqFixGainEn; \
    NEUN_AGC_TaskList                                           agcTaskList; \
    NEUN_AGC_CcInfo                                             agcCcInfo; \
    NEUN_AGC_CfuRptSlotPkg                                      agcRssiRpt; \
    NEUN_AGC_ReqFixPara                                         agcReqFixPara; \
    NEUN_AGC_CcBandList                                         agcBandList; \
    NEUN_AGC_ReqMsg                                             agcReqMsg; \
    NEUN_AGC_GainRptInfo                                        agcGainRptInfo; \
    NEUN_AGC_HalTraceRpt                                        agcTraceRpt; \
    NEUN_FEC_LnaCtrlInfo                                        agcLnaInfo; \
    NEUN_NR_AgcMeasPara                                         agcSsbAction;
/* TFPARA */
#define NEUN_TFPARA_MAIN \
    enum NEUN_TFPARA_OmSwitch                                nphyTfparaOmSwitchUint08; \
    enum NEUN_TFSYNC_PccQualityState                         neunTfsyncPccQualityState; \
    NEUN_TFPARA_ReqReportEna                                 lphyTfparaReqReportEna; \
    NEUN_TFPARA_Om                                           lphyTfparaOm; \
    NEUN_TFPE_SnrInfo                                        lphyTfparaSnrInfo; \
    NEUN_TFPE_RsrpNoiseSnr                                   lphyTfparaRsrpNoise; \
    NEUN_TFPE_LinearData                                     lphyTfparaLinearData; \
    NEUN_FEC_DfuCommonPara                                   dfuOmRptInfo; \
    NEUN_TFPE_OmStopSmp                                      tfpeSmpStop;
/* CHSCEN START */
#define NEUN_CHSCEN_MAIN \
    enum NEUN_CHSCEN_ModeType       neunChscenModeType; \
    enum NEUN_CHSCEN_MseType        neunChscenMseType; \
    enum NEUN_CHSCEN_SpeedType      neunChscenSpeedType; \
    enum NEUN_CHSCEN_HstType        neunChscenHstType; \
    enum NEUN_CHSCEN_WorkMode       neunChscenWorkMode; \
    enum NEUN_CHSCEN_SensorType     neunChscenSensorType; \
    enum NEUN_CHSCEN_OmSwitch       neunChscenOmSwitch; \
    enum NEUN_CHSCEN_SpeedStubType  neunChscenSpeedStubType; \
    enum NEUN_CHSCEN_HstStubType    neunChscenHstStubType; \
    NEUN_CHSCEN_OmInfo              chscenInfo; \
    NEUN_CHSCEN_ClassifyResStub     chscenResStub;
/* CHSCEN END */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* end of hids_elf_neuphy.c */

