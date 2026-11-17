
#ifndef HIDS_ELF_LPHY_H
#define HIDS_ELF_LPHY_H


/*
 * 1 其他头文件包含
 */
#include "lphy_feature.h"
#include "lphy_basedef_enum.h"
#include "lphy_basedef_struct.h"
#include "lrrc_phy_interface.h"
#include "mac_lphy_interface.h"
#include "lphy_hl1c_ll1d_interface.h"
#include "lphy_hl1c_ll1u_interface.h"
#include "lphy_sdr_emu_interface.h"
#include "lphy_proc_om_base_def.h"
#include "lphy_csi_om_def.h"
#include "lphy_tru_om_def.h"
#include "lphy_fec_comm_interface.h"
#include "lphy_comm_emu_interface.h"
#include "lphy_fec_om_def.h"
#include "lphy_dem_om_def.h"
#include "lphy_paramgt_om_base_def.h"
#include "lphy_che_om_def.h"
#include "ul1m_lphy_che_om.h"
#include "ul1m_lphy_est_om.h"
#include "lphy_est_om_base_def.h"
#include "lphy_ul_om_def.h"
#include "lphy_dec_om_def.h"
#include "lphy_chanctrl_om_def.h"
#include "lphy_lpc_om_def.h"
#include "lphy_lpc_interface.h"
#include "lphy_emu_om_def.h"
#include "neun_emu_bbp_config.h"
#include "lphy_tfpara_om_def.h"
#include "lphy_dsds_om_def.h"
#include "lphy_uldsds_om_def.h"
#include "lphy_agc_om_def.h"
#include "lphy_tfsync_om_def.h"
#include "ul1m_rcm_phy_interface.h"
#include "ul1m_prm_emu_winmanager.h"
#include "lphy_drx_om_def.h"
#include "neun_drx_om_def.h"
#include "lphy_comm_lpc_interface.h"
#include "neun_drx_interface.h"
#include "lphy_sched_om_def.h"
#include "lphy_feicic_interface.h"
#include "lphy_dl_tfsync_interface.h"
#include "ul1m_lphy_ul_om.h"
#include "ul1m_lphy_lpc_om.h"
#include "ul1m_lphy_drx_om.h"
#include "ul1m_lphy_sched_om.h"
#include "ul1m_lphy_csi_om.h"
#include "lphy_irat_om_def.h"
#include "ul1m_lphy_irat_om.h"
#include "ul1m_lphy_dem_om.h"
#include "ul1m_lphy_tfpara_om.h"
#include "ul1m_lphy_tfsync_om.h"
#include "ul1m_lphy_dec_om.h"
#include "ul1m_lphy_emu_om.h"
#include "lphy_proc_interface.h"
#include "lphy_meas_om_interface.h"
#include "ul1m_neun_tfpara_om.h"
#include "lphy_emu_interface.h"
#include "lphy_csu_om.h"
#include "lphy_ul_fec_interface.h"
#include "lphy_hal_emu_interface.h"
#include "lphy_dl_emu_interface.h"
#include "uphy_lpc_dfx_interface.h"
#include "lphy_fec_ul_comm_interface.h"
#include "lphy_dlserv_om_def.h"
#include "neun_ll1d_tfsync_win_interface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/* lphy_basedef_enum.h start */
#define LPHY_BASEDEF_ENUM_MAIN \
    enum LPHY_PROC_ReleaseMsgId                 enLPHY_PROC_ReleaseMsgId; \
    enum LPHY_PROC_InitCsuMsgId                 enLPHY_PROC_InitCsuMsgId; \
    enum LPHY_PROC_NcbdMsgId                    enLPHY_PROC_NcbdMsgId; \
    enum LPHY_PROC_ScbdMsgId                    enLPHY_PROC_ScbdMsgId; \
    enum LPHY_PROC_BgsMsgId                     enLPHY_PROC_BgsMsgId;
/* lphy_basedef_enum.h end */
/* lphy_basedef_struct.h start */
#define LPHY_BASEDEF_STRUCT_MAIN \
    LPHY_PROC_CommTimerContext                  stLPHY_PROC_CommTimerContext; \
    LPHY_PROC_EmbmsInfo                         stLPHY_PROC_EmbmsInfo;
/* lphy_basedef_struct.h end */
/* lrrc_phy_interface.h start */
#define LRRC_PHY_INTERFACE_MAIN \
    enum LRRC_LPHY_MsgId                        enLRRC_LPHY_MsgId; \
    enum LRRC_LPHY_CellSearchType               enLRRC_LPHY_CellSearchType; \
    enum LRRC_LPHY_AntannaPort                  enLRRC_LPHY_AntannaPort; \
    enum LRRC_LPHY_CsiAntannaPort               enLRRC_LPHY_CsiAntannaPort; \
    enum LRRC_LPHY_SrsAntannaPort               enLRRC_LPHY_SrsAntannaPort; \
    enum LRRC_LPHY_BandWidth                    enLRRC_LPHY_BandWidth; \
    enum LRRC_LPHY_SubframeAssignment           enLRRC_LPHY_SubframeAssignment; \
    enum LRRC_LPHY_SpecialSubframePattern       enLRRC_LPHY_SpecialSubframePattern; \
    enum LRRC_LPHY_Result                       enLRRC_LPHY_Result; \
    enum LRRC_LPHY_MbsfnSfCfgType               enLRRC_LPHY_MbsfnSfCfgType; \
    enum LRRC_LPHY_ChannelType                  enLRRC_LPHY_ChannelType; \
    enum LRRC_LPHY_PdschSetupFlag               enLRRC_LPHY_PdschSetupFlag; \
    enum LRRC_LPHY_PdschTmMode                  enLRRC_LPHY_PdschTmMode; \
    enum LRRC_LPHY_CodeBookType                 enLRRC_LPHY_CodeBookType; \
    enum LRRC_LPHY_AntennaSelect                enLRRC_LPHY_AntennaSelect; \
    enum LRRC_LPHY_PdschPa                      enLRRC_LPHY_PdschPa; \
    enum LRRC_LPHY_PdschPb                      enLRRC_LPHY_PdschPb; \
    enum LRRC_LPHY_ParaValidFlag                enLRRC_LPHY_ParaValidFlag; \
    enum LRRC_LPHY_DeltaPucchShitf              enLRRC_LPHY_DeltaPucchShitf; \
    enum LRRC_LPHY_RepetitionFactor             enLRRC_LPHY_RepetitionFactor; \
    enum LRRC_LPHY_TddFeedbackMode              enLRRC_LPHY_TddFeedbackMode; \
    enum LRRC_LPHY_DsrTransMax                  enLRRC_LPHY_DsrTransMax; \
    enum LRRC_LPHY_PuschHoppingMode             enLRRC_LPHY_PuschHoppingMode; \
    enum LRRC_LPHY_PuschNSb                     enLRRC_LPHY_PuschNSb; \
    enum LRRC_LPHY_UlCyclicPrefixLen            enLRRC_LPHY_UlCyclicPrefixLen; \
    enum LRRC_LPHY_ParaEnable                   enLRRC_LPHY_ParaEnable; \
    enum LRRC_LPHY_MaxHarqTx                    enLRRC_LPHY_MaxHarqTx; \
    enum LRRC_LPHY_PwrCtrlAlpha                 enLRRC_LPHY_PwrCtrlAlpha; \
    enum LRRC_LPHY_DeltafFormat                 enLRRC_LPHY_DeltafFormat; \
    enum LRRC_LPHY_FilterCoeff                  enLRRC_LPHY_FilterCoeff; \
    enum LRRC_LPHY_IndexFormatType              enLRRC_LPHY_IndexFormatType; \
    enum LRRC_LPHY_PersistSchedInterval         enLRRC_LPHY_PersistSchedInterval; \
    enum LRRC_LPHY_ImplicitRelAfter             enLRRC_LPHY_ImplicitRelAfter; \
    enum LRRC_LPHY_PhichDuration                enLRRC_LPHY_PhichDuration; \
    enum LRRC_LPHY_PhichResource                enLRRC_LPHY_PhichResource; \
    enum LRRC_LPHY_DrxPageT                     enLRRC_LPHY_DrxPageT; \
    enum LRRC_LPHY_DrxPageType                  enLRRC_LPHY_DrxPageType; \
    enum LRRC_LPHY_MeasCommand                  enLRRC_LPHY_MeasCommand; \
    enum LRRC_LPHY_IdleMeasReportType           enLRRC_LPHY_IdleMeasReportType; \
    enum LRRC_LPHY_ConnMeasType                 enLRRC_LPHY_ConnMeasType; \
    enum LRRC_LPHY_ConnMeasReportType           enLRRC_LPHY_ConnMeasReportType; \
    enum LRRC_LPHY_MeasGapType                  enLRRC_LPHY_MeasGapType; \
    enum LRRC_LPHY_CqiModeaPeriodic             enLRRC_LPHY_CqiModeaPeriodic; \
    enum LRRC_LPHY_CqiFormateIndType            enLRRC_LPHY_CqiFormateIndType; \
    enum LRRC_LPHY_SrsBandwidthType             enLRRC_LPHY_SrsBandwidthType; \
    enum LRRC_LPHY_SrsSubframeType              enLRRC_LPHY_SrsSubframeType; \
    enum LRRC_LPHY_SrsHoppingBandwidth          enLRRC_LPHY_SrsHoppingBandwidth; \
    enum LRRC_LPHY_CyclicShift                  enLRRC_LPHY_CyclicShift; \
    enum LRRC_LPHY_DurationTimer                enLRRC_LPHY_DurationTimer; \
    enum LRRC_LPHY_InactiveTimer                enLRRC_LPHY_InactiveTimer; \
    enum LRRC_LPHY_RetransTimer                 enLRRC_LPHY_RetransTimer; \
    enum LRRC_LPHY_LongDrxOffset                enLRRC_LPHY_LongDrxOffset; \
    enum LRRC_LPHY_ShortDrxCycle                enLRRC_LPHY_ShortDrxCycle; \
    enum LRRC_LPHY_EdrxOffset                   enLRRC_LPHY_EdrxOffset; \
    enum LRRC_LPHY_DrxIndicator                 enLRRC_LPHY_DrxIndicator; \
    enum LRRC_LPHY_GateclockIndicator           enLRRC_LPHY_GateclockIndicator; \
    enum LRRC_LPHY_SiWindow                     enLRRC_LPHY_SiWindow; \
    enum LRRC_LPHY_SiPeriod                     enLRRC_LPHY_SiPeriod; \
    enum LRRC_LPHY_MbsfnAllocationPeriod        enLRRC_LPHY_MbsfnAllocationPeriod; \
    enum LRRC_LPHY_MbsfnAllocationType          enLRRC_LPHY_MbsfnAllocationType; \
    enum LRRC_LPHY_CgiAcquisitionMethod         enLRRC_LPHY_CgiAcquisitionMethod; \
    enum LRRC_LPHY_BandScanType                 enLRRC_LPHY_BandScanType; \
    enum LRRC_LPHY_HoFlag                       enLRRC_LPHY_HoFlag; \
    enum LRRC_LPHY_CfgEndFlag                   enLRRC_LPHY_CfgEndFlag; \
    enum LRRC_LPHY_WorkModeType                 enLRRC_LPHY_WorkModeType; \
    enum LRRC_LPHY_SetWorkModeReason            enLRRC_LPHY_SetWorkModeReason; \
    enum LRRC_LPHY_RatType                      enLRRC_LPHY_RatType; \
    enum LRRC_LPHY_GeranBandInd                 enLRRC_LPHY_GeranBandInd; \
    enum LRRC_LPHY_LteModeType                  enLRRC_LPHY_LteModeType; \
    enum LRRC_LPHY_WcdmaState                   enLRRC_LPHY_WcdmaState; \
    enum LRRC_LPHY_BandInd                      enLRRC_LPHY_BandInd; \
    enum LRRC_LPHY_ErrType                      enLRRC_LPHY_ErrType; \
    enum LRRC_LPHY_McchRepetPeriodR9            enLRRC_LPHY_McchRepetPeriodR9; \
    enum LRRC_LPHY_McchOffset                   enLRRC_LPHY_McchOffset; \
    enum LRRC_LPHY_McchModifyPeriod             enLRRC_LPHY_McchModifyPeriod; \
    enum LRRC_LPHY_SigMcsR9                     enLRRC_LPHY_SigMcsR9; \
    enum LRRC_LPHY_NonMbsfNregionLen            enLRRC_LPHY_NonMbsfNregionLen; \
    enum LRRC_LPHY_ConigValidFlg                enLRRC_LPHY_ConigValidFlg; \
    enum LRRC_LPHY_NotificationOffset           enLRRC_LPHY_NotificationOffset; \
    enum LRRC_LPHY_NotificationRepetCoeffR9     enLRRC_LPHY_NotificationRepetCoeffR9; \
    enum LRRC_LPHY_NotificationSfIndex          enLRRC_LPHY_NotificationSfIndex; \
    enum LRRC_LPHY_MchSchdlPeriodR9             enLRRC_LPHY_MchSchdlPeriodR9; \
    enum LRRC_LPHY_CommSfAllocPeriodR9          enLRRC_LPHY_CommSfAllocPeriodR9; \
    enum LRRC_LPHY_MchDataMcsType               enLRRC_LPHY_MchDataMcsType; \
    enum LRRC_LPHY_OtdoaRprtType                enLRRC_LPHY_OtdoaRprtType; \
    enum LRRC_LPHY_OtdoaEnableSignal            enLRRC_LPHY_OtdoaEnableSignal; \
    enum LRRC_LPHY_PositionOtdoaMeasReq         enLRRC_LPHY_PositionOtdoaMeasReq; \
    enum LRRC_LPHY_OtdoaTargetDeviceErrorCauses enLRRC_LPHY_OtdoaTargetDeviceErrorCauses; \
    enum LRRC_LPHY_EcidTargetDeviceErrorCauses  enLRRC_LPHY_EcidTargetDeviceErrorCauses; \
    enum LRRC_LPHY_LteCpType                    enLRRC_LPHY_LteCpType; \
    enum LRRC_LPHY_OtdoaAntPortCfg              enLRRC_LPHY_OtdoaAntPortCfg; \
    enum LRRC_LPHY_OtdoaPrsCrsType              enLRRC_LPHY_OtdoaPrsCrsType; \
    enum LRRC_LPHY_OtdoaDlSubframeNum           enLRRC_LPHY_OtdoaDlSubframeNum; \
    enum LRRC_LPHY_LteBandWidth                 enLRRC_LPHY_LteBandWidth; \
    enum LRRC_LPHY_OtdoaRprtInterval            enLRRC_LPHY_OtdoaRprtInterval; \
    enum LRRC_LPHY_DeltafPucchFormat3           enLRRC_LPHY_DeltafPucchFormat3; \
    enum LRRC_LPHY_DeltafPucchFormat1bcs        enLRRC_LPHY_DeltafPucchFormat1bcs; \
    enum LRRC_LPHY_DeltafPucchFormat4           enLRRC_LPHY_DeltafPucchFormat4; \
    enum LRRC_LPHY_DeltafPucchFormat5           enLRRC_LPHY_DeltafPucchFormat5; \
    enum LRRC_LPHY_DeltatxdOffsetPucch          enLRRC_LPHY_DeltatxdOffsetPucch; \
    enum LRRC_LPHY_PucchFormatType              enLRRC_LPHY_PucchFormatType; \
    enum LRRC_LPHY_SubframePatternType          enLRRC_LPHY_SubframePatternType; \
    enum LRRC_LPHY_PeriodicFactor               enLRRC_LPHY_PeriodicFactor; \
    enum LRRC_LPHY_CqiReportMode                enLRRC_LPHY_CqiReportMode; \
    enum LRRC_LPHY_TransmissionMode             enLRRC_LPHY_TransmissionMode; \
    enum LRRC_LPHY_PathlossRefLink              enLRRC_LPHY_PathlossRefLink; \
    enum LRRC_LPHY_SchedulCellType              enLRRC_LPHY_SchedulCellType; \
    enum LRRC_LPHY_MeasCycleScell               enLRRC_LPHY_MeasCycleScell; \
    enum LRRC_LPHY_DsdsRfshared                 enLRRC_LPHY_DsdsRfshared; \
    enum LRRC_LPHY_SensorState                  enLRRC_LPHY_SensorState; \
    enum LRRC_LPHY_NotchState                   enLRRC_LPHY_NotchState; \
    enum LRRC_LPHY_DpdtCmd                      enLRRC_LPHY_DpdtCmd; \
    enum LRRC_LPHY_QclOperation                 enLRRC_LPHY_QclOperation; \
    enum LRRC_LPHY_CrsPortsCount                enLRRC_LPHY_CrsPortsCount; \
    enum LRRC_LPHY_PdschStart                   enLRRC_LPHY_PdschStart; \
    enum LRRC_LPHY_TransmissionType             enLRRC_LPHY_TransmissionType; \
    enum LRRC_LPHY_NumberprbPairs               enLRRC_LPHY_NumberprbPairs; \
    enum LRRC_LPHY_BgscfgType                   enLRRC_LPHY_BgscfgType; \
    enum LRRC_LPHY_BgSearchPriority             enLRRC_LPHY_BgSearchPriority; \
    enum LRRC_LPHY_DsdsNorfType                 enLRRC_LPHY_DsdsNorfType; \
    enum LRRC_LPHY_AntennaMaxLayersMimo         enLRRC_LPHY_AntennaMaxLayersMimo; \
    enum LRRC_LPHY_TbsIndexAlt                  enLRRC_LPHY_TbsIndexAlt; \
    enum LRRC_LPHY_EimtaHarqRefConfig           enLRRC_LPHY_EimtaHarqRefConfig; \
    enum LRRC_LPHY_CellType                     enLRRC_LPHY_CellType; \
    enum LRRC_LPHY_Cg                           enLRRC_LPHY_Cg; \
    enum LRRC_LPHY_AltCqiTable                  enLRRC_LPHY_AltCqiTable; \
    enum LRRC_LPHY_TrigSubframeSetInd           enLRRC_LPHY_TrigSubframeSetInd; \
    enum LRRC_LPHY_MeasScalFacType              enLRRC_LPHY_MeasScalFacType; \
    enum LRRC_LPHY_EimtaCmdPeriodR12            enLRRC_LPHY_EimtaCmdPeriodR12; \
    enum LRRC_LPHY_MbsfnLogInterval             enLRRC_LPHY_MbsfnLogInterval; \
    enum LRRC_LPHY_DmtcPeriod                   enLRRC_LPHY_DmtcPeriod; \
    enum LRRC_LPHY_CdmType                      enLRRC_LPHY_CdmType; \
    enum LRRC_LPHY_CsiRsEmimoType               enLRRC_LPHY_CsiRsEmimoType; \
    enum LRRC_LPHY_CbsrType                     enLRRC_LPHY_CbsrType; \
    enum LRRC_LPHY_MpdcchSfCssRa                enLRRC_LPHY_MpdcchSfCssRa; \
    enum LRRC_LPHY_MpdcchSfUess                 enLRRC_LPHY_MpdcchSfUess; \
    enum LRRC_LPHY_PdschMaxNumRpttnCeModeb      enLRRC_LPHY_PdschMaxNumRpttnCeModeb; \
    enum LRRC_LPHY_PuschMaxNumRpttn             enLRRC_LPHY_PuschMaxNumRpttn; \
    enum LRRC_LPHY_MpdcchNumRpttnRa             enLRRC_LPHY_MpdcchNumRpttnRa; \
    enum LRRC_LPHY_PucchRpttnCeMsg4Lvl          enLRRC_LPHY_PucchRpttnCeMsg4Lvl; \
    enum LRRC_LPHY_PucchRpttnCeFrmt             enLRRC_LPHY_PucchRpttnCeFrmt; \
    enum LRRC_LPHY_CodeBookSizeDetermin         enLRRC_LPHY_CodeBookSizeDetermin; \
    enum LRRC_LPHY_CeMode                       enLRRC_LPHY_CeMode; \
    enum LRRC_LPHY_PhrModeOtherCg               enLRRC_LPHY_PhrModeOtherCg; \
    enum LRRC_LPHY_ModemStartStateType          enLRRC_LPHY_ModemStartStateType; \
    enum LRRC_LPHY_ModemDsdsStateType           enLRRC_LPHY_ModemDsdsStateType; \
    enum PsBand                                 enPsBand; \
    enum LRRC_LPHY_SwitchIndType                enLRRC_LPHY_SwitchIndType; \
    enum LRRC_LPHY_EutranModeType               enLRRC_LPHY_EutranModeType; \
    enum LRRC_LPHY_MeasType                     enLRRC_LPHY_MeasType; \
    enum LRRC_LPHY_HighspeedFlag                enLRRC_LPHY_HighspeedFlag; \
    enum LRRC_LPHY_EccEnable                    enLRRC_LPHY_EccEnable; \
    enum LRRC_LPHY_JamDetRsltType               enLRRC_LPHY_JamDetRsltType; \
    enum LRRC_LPHY_ActiveLteModemNum            enLRRC_LPHY_ActiveLteModemNum; \
    enum LRRC_LPHY_DdrMsgId                     enLRRC_LPHY_DdrMsgId; \
    enum LRRC_LPHY_TpcSubframeSetCfgType        enLRRC_LPHY_TpcSubframeSetCfgType; \
    enum LRRC_LPHY_PuschUpPtsSym                enLRRC_LPHY_PuschUpPtsSym; \
    enum LRRC_LPHY_SfType                       enLRRC_LPHY_SfType; \
    enum LRRC_LPHY_SubcarrierSpacSsbR15         enLRRC_LPHY_SubcarrierSpacSsbR15; \
    enum LRRC_LPHY_GapFlag                      enLRRC_LPHY_GapFlag; \
    enum LRRC_LPHY_GapSharing                   enLRRC_LPHY_GapSharing; \
    enum LRRC_LPHY_CcType                       enLRRC_LPHY_CcType; \
    enum LRRC_LPHY_MeasSourceType               enLRRC_LPHY_MeasSourceType; \
    enum LRRC_LPHY_MeasFreqChangeType           enLRRC_LPHY_MeasFreqChangeType; \
    enum PS_ScsType                  enPS_ScsType; \
    enum PS_SsbPeriod                    enPS_SsbPeriod; \
    enum PS_SsbDuration                     enLRRC_LPHY_Duration; \
    enum LRRC_LPHY_NetDeployType                enLRRC_LPHY_NetDeployType; \
    enum LRRC_LPHY_SpcellFlag                   enLRRC_LPHY_SpcellFlag; \
    LRRC_LPHY_RxAntInfo                         stLRRC_LPHY_RxAntInfo; \
    LRRC_LPHY_CqiInfo                           stLRRC_LPHY_CqiInfo; \
    LRRC_LPHY_SiConfigItem                      stLRRC_LPHY_SiConfigItem; \
    LRRC_LPHY_SiConfigReq                       stLRRC_LPHY_SiConfigReq; \
    LRRC_LPHY_SiConfigCnf                       stLRRC_LPHY_SiConfigCnf; \
    LRRC_LPHY_ConfigDrxGateclockInd             stLRRC_LPHY_ConfigDrxGateclockInd; \
    LRRC_LPHY_UeCapSuppEutraBand                stLRRC_LPHY_UeCapSuppEutraBand; \
    LRRC_LPHY_EccCfgCnf                         stLRRC_LPHY_EccCfgCnf; \
    LRRC_LPHY_EccStatusInd                      stLRRC_LPHY_EccStatusInd; \
    LRRC_LPHY_SibTimeInfoNotify                 stLRRC_LPHY_SibTimeInfoNotify; \
    LRRC_LPHY_SibLeapTimeGetCnf                 stLRRC_LPHY_SibLeapTimeGetCnf; \
    LRRC_LPHY_LostcoverageStatusNotify          stLRRC_LPHY_LostcoverageStatusNotify; \
    LRRC_LPHY_Smtc1                             stLRRC_LPHY_Smtc1; \
    LRRC_LPHY_PagingData                        stLRRC_LPHY_PagingData; \
    LRRC_LPHY_PagingInd                         stLRRC_LPHY_PagingInd; \
    LRRC_LPHY_MibDataInd                        stLRRC_LPHY_MibDataInd; \
    LRRC_LPHY_NotchReq                          stLRRC_LPHY_NotchReq; \
    LRRC_LPHY_SensorStateReq                    stLRRC_LPHY_SensorStateReq; \
    LRRC_LPHY_CandidateCellInfoList             stLRRC_LPHY_CandidateCellInfoList; \
    LRRC_LPHY_FreqBandInfo                      stLRRC_LPHY_FreqBandInfo; \
    LRRC_LPHY_CellSearchingReq                  stLRRC_LPHY_CellSearchingReq; \
    LRRC_LPHY_CellSearchingInd                  stLRRC_LPHY_CellSearchingInd; \
    LRRC_LPHY_BandScanResultList                stLRRC_LPHY_BandScanResultList; \
    LRRC_LPHY_JamDetectInfo                     stLRRC_LPHY_JamDetectInfo; \
    LRRC_LPHY_BandScanReq                       stLRRC_LPHY_BandScanReq; \
    LRRC_LPHY_JamDetRslt                        stLRRC_LPHY_JamDetRslt; \
    LRRC_LPHY_BandScanInd                       stLRRC_LPHY_BandScanInd; \
    LRRC_LPHY_FreqRssiMeasInfo                  stLRRC_LPHY_FreqRssiMeasInfo; \
    LRRC_LPHY_FreqRssiScanReq                   stLRRC_LPHY_FreqRssiScanReq; \
    LRRC_LPHY_TddConfigInfo                     stLRRC_LPHY_TddConfigInfo; \
    LRRC_LPHY_CampedMaincellReq                 stLRRC_LPHY_CampedMaincellReq; \
    LRRC_LPHY_CampedMaincellCnf                 stLRRC_LPHY_CampedMaincellCnf; \
    LRRC_LPHY_AntennaDedicatedInfo              stLRRC_LPHY_AntennaDedicatedInfo; \
    LRRC_LPHY_MbsfnSubframeCfgInfo              stLRRC_LPHY_MbsfnSubframeCfgInfo; \
    LRRC_LPHY_MbsfnSubframeCfgList              stLRRC_LPHY_MbsfnSubframeCfgList; \
    LRRC_LPHY_DmrsConfig                        stLRRC_LPHY_DmrsConfig; \
    LRRC_LPHY_OptionalSetOfFields               stLRRC_LPHY_OptionalSetOfFields; \
    LRRC_LPHY_ReMapQclConfig                    stLRRC_LPHY_ReMapQclConfig; \
    LRRC_LPHY_ReMapQclConfigList                stLRRC_LPHY_ReMapQclConfigList; \
    LRRC_LPHY_PdschDedicatedInfo                stLRRC_LPHY_PdschDedicatedInfo; \
    LRRC_LPHY_QclCrsInfo                        stLRRC_LPHY_QclCrsInfo; \
    LRRC_LPHY_CsiRsConfigNzpInfo                stLRRC_LPHY_CsiRsConfigNzpInfo; \
    LRRC_LPHY_CsiRsConfigNzpInfoList            stLRRC_LPHY_CsiRsConfigNzpInfoList; \
    LRRC_LPHY_CsiRsConfigZpInfo                 stLRRC_LPHY_CsiRsConfigZpInfo; \
    LRRC_LPHY_CsiRsConfigZpInfoList             stLRRC_LPHY_CsiRsConfigZpInfoList; \
    LRRC_LPHY_IdleDrxInfo                       stLRRC_LPHY_IdleDrxInfo; \
    LRRC_LPHY_N1PucchAnPersistentList           stLRRC_LPHY_N1PucchAnPersistentList; \
    LRRC_LPHY_SpsConfigDl                       stLRRC_LPHY_SpsConfigDl; \
    LRRC_LPHY_MeasSubframePattern               stLRRC_LPHY_MeasSubframePattern; \
    LRRC_LPHY_CsiRs                             stLRRC_LPHY_CsiRs; \
    LRRC_LPHY_ZeroTxPowerCsiRs                  stLRRC_LPHY_ZeroTxPowerCsiRs; \
    LRRC_LPHY_DsZtpCsiRsConfig                  stLRRC_LPHY_DsZtpCsiRsConfig; \
    LRRC_LPHY_CqiRprtAprdcProcTrigBit           stLRRC_LPHY_CqiRprtAprdcProcTrigBit; \
    LRRC_LPHY_CsiImIdList                       stLRRC_LPHY_CsiImIdList; \
    LRRC_LPHY_NzpRsCfgList                      stLRRC_LPHY_NzpRsCfgList; \
    LRRC_LPHY_CsiRsCfgNzpEmimo                  stLRRC_LPHY_CsiRsCfgNzpEmimo; \
    LRRC_LPHY_CbsrNonPrcde                      stLRRC_LPHY_CbsrNonPrcde; \
    LRRC_LPHY_CbsrBmFrmK1a                      stLRRC_LPHY_CbsrBmFrmK1a; \
    LRRC_LPHY_CbsrBmFrmKn                       stLRRC_LPHY_CbsrBmFrmKn; \
    LRRC_LPHY_PCAndCbsrR13                      stLRRC_LPHY_PCAndCbsrR13; \
    LRRC_LPHY_CsiCfgNzpIdList                   stLRRC_LPHY_CsiCfgNzpIdList; \
    LRRC_LPHY_PCAndCbsrListR13                  stLRRC_LPHY_PCAndCbsrListR13; \
    LRRC_LPHY_CsiRsBmFrm                        stLRRC_LPHY_CsiRsBmFrm; \
    LRRC_LPHY_CsiRsNonPrcde                     stLRRC_LPHY_CsiRsNonPrcde; \
    LRRC_LPHY_CsiRsEmimo                        stLRRC_LPHY_CsiRsEmimo; \
    LRRC_LPHY_CsiRsConfig                       stLRRC_LPHY_CsiRsConfig; \
    LRRC_LPHY_CrsAssistInfo                     stLRRC_LPHY_CrsAssistInfo; \
    LRRC_LPHY_CrsAssistInfoList                 stLRRC_LPHY_CrsAssistInfoList; \
    LRRC_LPHY_ResourceblockAssignment           stLRRC_LPHY_ResourceblockAssignment; \
    LRRC_LPHY_MpdcchCfg                         stLRRC_LPHY_MpdcchCfg; \
    LRRC_LPHY_EpdcchSetCfg                      stLRRC_LPHY_EpdcchSetCfg; \
    LRRC_LPHY_DeltatxdOffsetlistPucchR11        stLRRC_LPHY_DeltatxdOffsetlistPucchR11; \
    LRRC_LPHY_NPucchParam                       stLRRC_LPHY_NPucchParam; \
    LRRC_LPHY_PuschDmrs                         stLRRC_LPHY_PuschDmrs; \
    LRRC_LPHY_EimtaMainConfig                   stLRRC_LPHY_EimtaMainConfig; \
    LRRC_LPHY_EimtaMainConfigServCell           stLRRC_LPHY_EimtaMainConfigServCell; \
    LRRC_LPHY_NeighCellInfo                     stLRRC_LPHY_NeighCellInfo; \
    LRRC_LPHY_NaicsAssistInfo                   stLRRC_LPHY_NaicsAssistInfo; \
    LRRC_LPHY_PdcchCandReduct                   stLRRC_LPHY_PdcchCandReduct; \
    LRRC_LPHY_FreqHopPara                       stLRRC_LPHY_FreqHopPara; \
    LRRC_LPHY_N1PucchAnInfoList                 stLRRC_LPHY_N1PucchAnInfoList; \
    LRRC_LPHY_PucchCommCeInfo                   stLRRC_LPHY_PucchCommCeInfo; \
    LRRC_LPHY_PucchCommInfo                     stLRRC_LPHY_PucchCommInfo; \
    LRRC_LPHY_AckNackRepet                      stLRRC_LPHY_AckNackRepet; \
    LRRC_LPHY_PucchFormat3                      stLRRC_LPHY_PucchFormat3; \
    LRRC_LPHY_N1PucchAnCs                       stLRRC_LPHY_N1PucchAnCs; \
    LRRC_LPHY_PucchChannelSel                   stLRRC_LPHY_PucchChannelSel; \
    LRRC_LPHY_PucchFormat4Resource              stLRRC_LPHY_PucchFormat4Resource; \
    LRRC_LPHY_PucchFormat5Resource              stLRRC_LPHY_PucchFormat5Resource; \
    LRRC_LPHY_PucchFormat4                      stLRRC_LPHY_PucchFormat4; \
    LRRC_LPHY_PucchFormat5                      stLRRC_LPHY_PucchFormat5; \
    LRRC_LPHY_PucchNumRepetitionCeModeA         stLRRC_LPHY_PucchNumRepetitionCeModeA; \
    LRRC_LPHY_PucchNumRepetitionCeModeB         stLRRC_LPHY_PucchNumRepetitionCeModeB; \
    LRRC_LPHY_PucchNumRepetitionCe              stLRRC_LPHY_PucchNumRepetitionCe; \
    LRRC_LPHY_PucchDedicatedInfo                stLRRC_LPHY_PucchDedicatedInfo; \
    LRRC_LPHY_SrConfigInfo                      stLRRC_LPHY_SrConfigInfo; \
    LRRC_LPHY_PuschBasicConfig                  stLRRC_LPHY_PuschBasicConfig; \
    LRRC_LPHY_PuschUlRefSignal                  stLRRC_LPHY_PuschUlRefSignal; \
    LRRC_LPHY_PuschBetaOffsetMc                 stLRRC_LPHY_PuschBetaOffsetMc; \
    LRRC_LPHY_PuschBetaOffsetMcSfmSet           stLRRC_LPHY_PuschBetaOffsetMcSfmSet; \
    LRRC_LPHY_PuschTpcSfmSet                    stLRRC_LPHY_PuschTpcSfmSet; \
    LRRC_LPHY_TpcSubframeSetCfg                 stLRRC_LPHY_TpcSubframeSetCfg; \
    LRRC_LPHY_TpcSubframeSetNotCfg              stLRRC_LPHY_TpcSubframeSetNotCfg; \
    LRRC_LPHY_TddPuschUppts                     stLRRC_LPHY_TddPuschUppts; \
    LRRC_LPHY_PuschDedicatedInfo                stLRRC_LPHY_PuschDedicatedInfo; \
    LRRC_LPHY_PucchDeltafList                   stLRRC_LPHY_PucchDeltafList; \
    LRRC_LPHY_DeltatxdOffsetlistPucch           stLRRC_LPHY_DeltatxdOffsetlistPucch; \
    LRRC_LPHY_PowerCtrlCommInfo                 stLRRC_LPHY_PowerCtrlCommInfo; \
    LRRC_LPHY_DcPhr                             stLRRC_LPHY_DcPhr; \
    LRRC_LPHY_McgPowerCoordin                   stLRRC_LPHY_McgPowerCoordin; \
    LRRC_LPHY_PowerCtrlDedicatedInfo            stLRRC_LPHY_PowerCtrlDedicatedInfo; \
    LRRC_LPHY_TpcPdcchConfig                    stLRRC_LPHY_TpcPdcchConfig; \
    LRRC_LPHY_P0Persistent                      stLRRC_LPHY_P0Persistent; \
    LRRC_LPHY_P0PersistSubFrameSet2             stLRRC_LPHY_P0PersistSubFrameSet2; \
    LRRC_LPHY_SpsConfigUl                       stLRRC_LPHY_SpsConfigUl; \
    LRRC_LPHY_AntennaInfoUl                     stLRRC_LPHY_AntennaInfoUl; \
    LRRC_LPHY_TdmPattern                        stLRRC_LPHY_TdmPattern; \
    LRRC_LPHY_RsrpThresInfoList                 stLRRC_LPHY_RsrpThresInfoList; \
    LRRC_LPHY_PrachConfig                       stLRRC_LPHY_PrachConfig; \
    LRRC_LPHY_PrachConfigHighSpeed              stLRRC_LPHY_PrachConfigHighSpeed; \
    LRRC_LPHY_SyncReq                           stLRRC_LPHY_SyncReq; \
    LRRC_LPHY_SyncCnf                           stLRRC_LPHY_SyncCnf; \
    LRRC_LPHY_SyncInd                           stLRRC_LPHY_SyncInd; \
    LRRC_LPHY_MeasSfPatternCfgNeigh             stLRRC_LPHY_MeasSfPatternCfgNeigh; \
    LRRC_LPHY_LaaMeasRssiCfg                    stLRRC_LPHY_LaaMeasRssiCfg; \
    LRRC_LPHY_ScellInfo                         stLRRC_LPHY_ScellInfo; \
    LRRC_LPHY_SingleFreqCellInfo                stLRRC_LPHY_SingleFreqCellInfo; \
    LRRC_LPHY_SecondSingleFreqInfo              stLRRC_LPHY_SecondSingleFreqInfo; \
    LRRC_LPHY_InterFreqCellInfo                 stLRRC_LPHY_InterFreqCellInfo; \
    LRRC_LPHY_UtranCarrierMeasParam             stLRRC_LPHY_UtranCarrierMeasParam; \
    LRRC_LPHY_PeriodAndOffsetR15                stLRRC_LPHY_PeriodAndOffsetR15; \
    LRRC_LPHY_MtcSsbNrR15                       stLRRC_LPHY_MtcSsbNrR15; \
    LRRC_LPHY_RsConfigSsbNrR15                  stLRRC_LPHY_RsConfigSsbNrR15; \
    LRRC_LPHY_NrFreqAndRsSsbInfo                stLRRC_LPHY_NrFreqAndRsSsbInfo; \
    LRRC_LPHY_IratFreqInfo                      stLRRC_LPHY_IratFreqInfo; \
    LRRC_LPHY_SecondFreqInfo                    stLRRC_LPHY_SecondFreqInfo; \
    LRRC_LPHY_MeasDsOccaDurat                   stLRRC_LPHY_MeasDsOccaDurat; \
    LRRC_LPHY_MeasCsiRsCfg                      stLRRC_LPHY_MeasCsiRsCfg; \
    LRRC_LPHY_MeasDmtcPeriodOffset              stLRRC_LPHY_MeasDmtcPeriodOffset; \
    LRRC_LPHY_MeasDsSingleFreq                  stLRRC_LPHY_MeasDsSingleFreq; \
    LRRC_LPHY_MeasDsCellResult                  stLRRC_LPHY_MeasDsCellResult; \
    LRRC_LPHY_MeasDsSingleFreqResult            stLRRC_LPHY_MeasDsSingleFreqResult; \
    LRRC_LPHY_MeasRssiResult                    stLRRC_LPHY_MeasRssiResult; \
    LRRC_LPHY_IratIdleFreqInfo                  stLRRC_LPHY_IratIdleFreqInfo; \
    LRRC_LPHY_MeasInIdleReq                     stLRRC_LPHY_MeasInIdleReq; \
    LRRC_LPHY_MeasInIdleCnf                     stLRRC_LPHY_MeasInIdleCnf; \
    LRRC_LPHY_CellMeasResult                    stLRRC_LPHY_CellMeasResult; \
    LRRC_LPHY_IdleServCellMeasResult            stLRRC_LPHY_IdleServCellMeasResult; \
    LRRC_LPHY_LaaSingleFreqRssiRslt             stLRRC_LPHY_LaaSingleFreqRssiRslt; \
    LRRC_LPHY_LaaRssiRslt                       stLRRC_LPHY_LaaRssiRslt; \
    LRRC_LPHY_SstdRslt                          stLRRC_LPHY_SstdRslt; \
    LRRC_LPHY_SingleFreqMeasResult              stLRRC_LPHY_SingleFreqMeasResult; \
    LRRC_LPHY_InterFreqMeasResult               stLRRC_LPHY_InterFreqMeasResult; \
    LRRC_LPHY_InactiveInterFreqMeasResult       stLRRC_LPHY_InactiveInterFreqMeasResult; \
    LRRC_LPHY_SecondFreqMeasResult              stLRRC_LPHY_SecondFreqMeasResult; \
    LRRC_LPHY_MeasInIdleInd                     stLRRC_LPHY_MeasInIdleInd; \
    LRRC_LPHY_InactiveMeasInIdleInd             stLRRC_LPHY_InactiveMeasInIdleInd; \
    LRRC_LPHY_MeasInConnectedReq                stLRRC_LPHY_MeasInConnectedReq; \
    LRRC_LPHY_MeasInConnectedCnf                stLRRC_LPHY_MeasInConnectedCnf; \
    LRRC_LPHY_MeasInConnectedInd                stLRRC_LPHY_MeasInConnectedInd; \
    LRRC_LPHY_InactiveMeasInConnectedInd        stLRRC_LPHY_InactiveMeasInConnectedInd; \
    LRRC_LPHY_TxPwrInfo                         stLRRC_LPHY_TxPwrInfo; \
    LRRC_LPHY_McsInfo                           stLRRC_LPHY_McsInfo; \
    LRRC_LPHY_BlerInfo                          stLRRC_LPHY_BlerInfo; \
    LRRC_LPHY_MeasInfoInd                       stLRRC_LPHY_MeasInfoInd; \
    LRRC_LPHY_GapSharingConfig                  stLRRC_LPHY_GapSharingConfig; \
    LRRC_LPHY_MeasGapNrConfig                   stLRRC_LPHY_MeasGapNrConfig; \
    LRRC_LPHY_MeasGapConfigReq                  stLRRC_LPHY_MeasGapConfigReq; \
    LRRC_LPHY_MeasScalFactor                    stLRRC_LPHY_MeasScalFactor; \
    LRRC_LPHY_CommMeasConfigReq                 stLRRC_LPHY_CommMeasConfigReq; \
    LRRC_LPHY_MeasGapConfigCnf                  stLRRC_LPHY_MeasGapConfigCnf; \
    LRRC_LPHY_RelallReq                         stLRRC_LPHY_RelallReq; \
    LRRC_LPHY_RelallCnf                         stLRRC_LPHY_RelallCnf; \
    LRRC_LPHY_CsiConfigIndex                    stLRRC_LPHY_CsiConfigIndex; \
    LRRC_LPHY_CqiSubband                        stLRRC_LPHY_CqiSubband; \
    LRRC_LPHY_CriRprtCfgIndex                   stLRRC_LPHY_CriRprtCfgIndex; \
    LRRC_LPHY_CqiReportPeriodicProcExt          stLRRC_LPHY_CqiReportPeriodicProcExt; \
    LRRC_LPHY_CqiReportPeriodicProcExtList      stLRRC_LPHY_CqiReportPeriodicProcExtList; \
    LRRC_LPHY_CsiImConfig                       stLRRC_LPHY_CsiImConfig; \
    LRRC_LPHY_CsiImConfigList                   stLRRC_LPHY_CsiImConfigList; \
    LRRC_LPHY_PCAndCbsr                         stLRRC_LPHY_PCAndCbsr; \
    LRRC_LPHY_PCAndCbsrList                     stLRRC_LPHY_PCAndCbsrList; \
    LRRC_LPHY_CqiReportBothProc                 stLRRC_LPHY_CqiReportBothProc; \
    LRRC_LPHY_CqiReportAperiodicProcR11         stLRRC_LPHY_CqiReportAperiodicProcR11; \
    LRRC_LPHY_CsiProcess                        stLRRC_LPHY_CsiProcess; \
    LRRC_LPHY_CsiProcessList                    stLRRC_LPHY_CsiProcessList; \
    LRRC_LPHY_CqiReportBoth                     stLRRC_LPHY_CqiReportBoth; \
    LRRC_LPHY_CqiReportPeriodicInfo             stLRRC_LPHY_CqiReportPeriodicInfo; \
    LRRC_LPHY_CqiRprtAprdcSfmSetInd             stLRRC_LPHY_CqiRprtAprdcSfmSetInd; \
    LRRC_LPHY_CqiReportAperiodic                stLRRC_LPHY_CqiReportAperiodic; \
    LRRC_LPHY_CqiRprtAprdcCsiTrig               stLRRC_LPHY_CqiRprtAprdcCsiTrig; \
    LRRC_LPHY_CqiRprtAprdcCsiTrig2              stLRRC_LPHY_CqiRprtAprdcCsiTrig2; \
    LRRC_LPHY_CqiRprtAprdcR13                   stLRRC_LPHY_CqiRprtAprdcR13; \
    LRRC_LPHY_CqiConfigReq                      stLRRC_LPHY_CqiConfigReq; \
    LRRC_LPHY_SrsCommInfo                       stLRRC_LPHY_SrsCommInfo; \
    LRRC_LPHY_SrsDedicatedInfo                  stLRRC_LPHY_SrsDedicatedInfo; \
    LRRC_LPHY_SrsConfigAp                       stLRRC_LPHY_SrsConfigAp; \
    LRRC_LPHY_SrsDediAperiodInfo                stLRRC_LPHY_SrsDediAperiodInfo; \
    LRRC_LPHY_SrsConfigReq                      stLRRC_LPHY_SrsConfigReq; \
    LRRC_LPHY_ConnectedDrxInfo                  stLRRC_LPHY_ConnectedDrxInfo; \
    LRRC_LPHY_SetWorkModeReq                    stLRRC_LPHY_SetWorkModeReq; \
    LRRC_LPHY_SetWorkModeCnf                    stLRRC_LPHY_SetWorkModeCnf; \
    LRRC_LPHY_BsicInfo                          stLRRC_LPHY_BsicInfo; \
    LRRC_LPHY_BsicVerifyReq                     stLRRC_LPHY_BsicVerifyReq; \
    LRRC_LPHY_BsicVerifyCnf                     stLRRC_LPHY_BsicVerifyCnf; \
    LRRC_LPHY_ErrorInd                          stLRRC_LPHY_ErrorInd; \
    LRRC_LPHY_OtdoaInterFreqInfo                stLRRC_LPHY_OtdoaInterFreqInfo; \
    LRRC_LPHY_LcsGapReq                         stLRRC_LPHY_LcsGapReq; \
    LRRC_LPHY_OtdoaPrsMutingInfo                stLRRC_LPHY_OtdoaPrsMutingInfo; \
    LRRC_LPHY_OtdoaPrsInfo                      stLRRC_LPHY_OtdoaPrsInfo; \
    LRRC_LPHY_OtdoaRefCellInfo                  stLRRC_LPHY_OtdoaRefCellInfo; \
    LRRC_LPHY_OtdoaNeighbourCellInfoList        stLRRC_LPHY_OtdoaNeighbourCellInfoList; \
    LRRC_LPHY_OtdoaNeighbourCellInfo            stLRRC_LPHY_OtdoaNeighbourCellInfo; \
    LRRC_LPHY_OtdoaNeighbourCellLayersInfo      stLRRC_LPHY_OtdoaNeighbourCellLayersInfo; \
    LRRC_LPHY_OtdoaAssistanceData               stLRRC_LPHY_OtdoaAssistanceData; \
    LRRC_LPHY_LcsMbx                            stLRRC_LPHY_LcsMbx; \
    LRRC_LPHY_OtdoaReq                          stLRRC_LPHY_OtdoaReq; \
    LRRC_LPHY_OtdoaCnf                          stLRRC_LPHY_OtdoaCnf; \
    LRRC_LPHY_OtdoaMeasQuality                  stLRRC_LPHY_OtdoaMeasQuality; \
    LRRC_LPHY_OtdoaNeighbourMeasList            stLRRC_LPHY_OtdoaNeighbourMeasList; \
    LRRC_LPHY_OtdoaNeighbourMeas                stLRRC_LPHY_OtdoaNeighbourMeas; \
    LRRC_LPHY_OtdoaSignalMeasInfo               stLRRC_LPHY_OtdoaSignalMeasInfo; \
    LRRC_LPHY_OtdoaProvideLocationInfo          stLRRC_LPHY_OtdoaProvideLocationInfo; \
    LRRC_LPHY_OtdoaInd                          stLRRC_LPHY_OtdoaInd; \
    LRRC_LPHY_MSG_DATA                          stLRRC_LPHY_MSG_DATA; \
    LRRC_LPHY_McchConfigR9                      stLRRC_LPHY_McchConfigR9; \
    LRRC_LPHY_MbsfnAreaInfoR9                   stLRRC_LPHY_MbsfnAreaInfoR9; \
    LRRC_LPHY_MbsfnAreaInfoListR9               stLRRC_LPHY_MbsfnAreaInfoListR9; \
    LRRC_LPHY_MbsfnMcchCfgReq                   stLRRC_LPHY_MbsfnMcchCfgReq; \
    LRRC_LPHY_MbsfnMcchCfgCnf                   stLRRC_LPHY_MbsfnMcchCfgCnf; \
    LRRC_LPHY_McchNotificationCfg               stLRRC_LPHY_McchNotificationCfg; \
    LRRC_LPHY_MbsfnNotifyCfgReq                 stLRRC_LPHY_MbsfnNotifyCfgReq; \
    LRRC_LPHY_MbsfnNotifyCfgCnf                 stLRRC_LPHY_MbsfnNotifyCfgCnf; \
    LRRC_LPHY_PmchConfigR9                      stLRRC_LPHY_PmchConfigR9; \
    LRRC_LPHY_PmchInfoListR9                    stLRRC_LPHY_PmchInfoListR9; \
    LRRC_LPHY_MbsfnAreaCfgInfo                  stLRRC_LPHY_MbsfnAreaCfgInfo; \
    LRRC_LPHY_MbsfnPmchCfgReq                   stLRRC_LPHY_MbsfnPmchCfgReq; \
    LRRC_LPHY_MbsfnPmchCfgCnf                   stLRRC_LPHY_MbsfnPmchCfgCnf; \
    LRRC_LPHY_MbsfnNotifyInd                    stLRRC_LPHY_MbsfnNotifyInd; \
    LRRC_LPHY_MbsfnSubframeCfg                  stLRRC_LPHY_MbsfnSubframeCfg; \
    LRRC_LPHY_MbsfnSubframeCfgReq               stLRRC_LPHY_MbsfnSubframeCfgReq; \
    LRRC_LPHY_MbsfnSubframeCfgCnf               stLRRC_LPHY_MbsfnSubframeCfgCnf; \
    LRRC_LPHY_SwitchInd                         stLRRC_LPHY_SwitchInd; \
    LRRC_LPHY_BgSearchStartReq                  stLRRC_LPHY_BgSearchStartReq; \
    LRRC_LPHY_BgSearchStartCnf                  stLRRC_LPHY_BgSearchStartCnf; \
    LRRC_LPHY_BgSearchStopReq                   stLRRC_LPHY_BgSearchStopReq; \
    LRRC_LPHY_BgSearchStopCnf                   stLRRC_LPHY_BgSearchStopCnf; \
    LRRC_LPHY_BgSearchSuspendReq                stLRRC_LPHY_BgSearchSuspendReq; \
    LRRC_LPHY_BgSearchSuspendCnf                stLRRC_LPHY_BgSearchSuspendCnf; \
    LRRC_LPHY_BgSearchResumeReq                 stLRRC_LPHY_BgSearchResumeReq; \
    LRRC_LPHY_BgSearchResumeCnf                 stLRRC_LPHY_BgSearchResumeCnf; \
    LRRC_LPHY_AnrStartReq                       stLRRC_LPHY_AnrStartReq; \
    LRRC_LPHY_AnrStartCnf                       stLRRC_LPHY_AnrStartCnf; \
    LRRC_LPHY_AnrStopReq                        stLRRC_LPHY_AnrStopReq; \
    LRRC_LPHY_AnrStopCnf                        stLRRC_LPHY_AnrStopCnf; \
    LRRC_LPHY_CrossCarrSchedulCfg               stLRRC_LPHY_CrossCarrSchedulCfg; \
    LRRC_LPHY_LaaScell                          stLRRC_LPHY_LaaScell; \
    LRRC_LPHY_DpdtCmdReq                        stLRRC_LPHY_DpdtCmdReq; \
    LRRC_LPHY_DpdtCmdInd                        stLRRC_LPHY_DpdtCmdInd; \
    LRRC_LPHY_NORF_INFO_IND                     stLRRC_LPHY_NORF_INFO_IND; \
    LRRC_LPHY_MbmsEnableReq                     stLRRC_LPHY_MbmsEnableReq; \
    LRRC_LPHY_MbmsEnableCnf                     stLRRC_LPHY_MbmsEnableCnf; \
    LRRC_LPHY_MbmsDisableReq                    stLRRC_LPHY_MbmsDisableReq; \
    LRRC_LPHY_MbmsDisableCnf                    stLRRC_LPHY_MbmsDisableCnf; \
    LRRC_LPHY_MbmsPmchActiveCfgInfo             stLRRC_LPHY_MbmsPmchActiveCfgInfo; \
    LRRC_LPHY_MbmsPmchActiveReq                 stLRRC_LPHY_MbmsPmchActiveReq; \
    LRRC_LPHY_MbmsPmchActiveCnf                 stLRRC_LPHY_MbmsPmchActiveCnf; \
    LRRC_LPHY_MbmsAllPmchInactiveReq            stLRRC_LPHY_MbmsAllPmchInactiveReq; \
    LRRC_LPHY_MbmsAllPmchInactiveCnf            stLRRC_LPHY_MbmsAllPmchInactiveCnf; \
    LRRC_LPHY_MbmsMrsMeasInd                    stLRRC_LPHY_MbmsMrsMeasInd; \
    LRRC_LPHY_MbmsRcvAllMcchInd                 stLRRC_LPHY_MbmsRcvAllMcchInd; \
    LRRC_LPHY_ConnectedToIdleReq                stLRRC_LPHY_ConnectedToIdleReq; \
    LRRC_LPHY_ConnectedToIdleCnf                stLRRC_LPHY_ConnectedToIdleCnf; \
    LRRC_LPHY_HifiSyncSwitchInd                 stLRRC_LPHY_HifiSyncSwitchInd; \
    LRRC_LPHY_RlfPara                           stLRRC_LPHY_RlfPara; \
    LRRC_LPHY_ScgRlfPara                        stLRRC_LPHY_ScgRlfPara; \
    LRRC_LPHY_RlfInfo                           stLRRC_LPHY_RlfInfo; \
    LRRC_LPHY_UeCapRfPara                       stLRRC_LPHY_UeCapRfPara; \
    LRRC_LPHY_ChrSrvingCellInfo                 stLRRC_LPHY_ChrSrvingCellInfo; \
    LRRC_LPHY_FreqRssiScanStopReq               stLRRC_LPHY_FreqRssiScanStopReq; \
    LRRC_LPHY_SuspendReq                        stLRRC_LPHY_SuspendReq; \
    LRRC_LPHY_ResumeReq                         stLRRC_LPHY_ResumeReq; \
    LRRC_LPHY_DsMeasIntraReq                    stLRRC_LPHY_DsMeasIntraReq; \
    LRRC_LPHY_DsMeasInterReq                    stLRRC_LPHY_DsMeasInterReq; \
    LRRC_LPHY_DsMeasSecondFreqReq               stLRRC_LPHY_DsMeasSecondFreqReq; \
    LRRC_LPHY_DsMeasIntraCnf                    stLRRC_LPHY_DsMeasIntraCnf; \
    LRRC_LPHY_DsMeasMcgPcellInd                 stLRRC_LPHY_DsMeasMcgPcellInd; \
    LRRC_LPHY_DsMeasIntraInd                    stLRRC_LPHY_DsMeasIntraInd; \
    LRRC_LPHY_DsMeasInterInd                    stLRRC_LPHY_DsMeasInterInd; \
    LRRC_LPHY_DsMeasSecondFreqInd               stLRRC_LPHY_DsMeasSecondFreqInd; \
    LRRC_LPHY_MbsfnTargetAreaInfo               stLRRC_LPHY_MbsfnTargetAreaInfo; \
    LRRC_LPHY_MbsfnArea                         stLRRC_LPHY_MbsfnArea; \
    LRRC_LPHY_MbsfnLogReq                       stLRRC_LPHY_MbsfnLogReq; \
    LRRC_LPHY_MbsfnLogCnf                       stLRRC_LPHY_MbsfnLogCnf; \
    LRRC_LPHY_MbsfnBlerRslt                     stLRRC_LPHY_MbsfnBlerRslt; \
    LRRC_LPHY_MbsfnDataBlerMchRslt              stLRRC_LPHY_MbsfnDataBlerMchRslt; \
    LRRC_LPHY_MbsfnLogEnergyAreaRslt            stLRRC_LPHY_MbsfnLogEnergyAreaRslt; \
    LRRC_LPHY_MbsfnLogBlerAreaRslt              stLRRC_LPHY_MbsfnLogBlerAreaRslt; \
    LRRC_LPHY_MbsfnLogEnergyInd                 stLRRC_LPHY_MbsfnLogEnergyInd; \
    LRRC_LPHY_MbsfnLogBlerInd                   stLRRC_LPHY_MbsfnLogBlerInd; \
    LRRC_LPHY_MeasLaaRssiInd                    stLRRC_LPHY_MeasLaaRssiInd; \
    LRRC_LPHY_MeasSstdInd                       stLRRC_LPHY_MeasSstdInd; \
    LRRC_LPHY_ModemStartStateInfoReq            stLRRC_LPHY_ModemStartStateInfoReq; \
    LRRC_LPHY_ModemStartStateInfoCnf            stLRRC_LPHY_ModemStartStateInfoCnf; \
    LRRC_LPHY_CapParaNotify                     stLRRC_LPHY_CapParaNotify; \
    LRRC_LPHY_EtwsCmasBeginNtf                  stLRRC_LPHY_EtwsCmasBeginNtf; \
    LRRC_LPHY_EtwsCmasEndNtf                    stLRRC_LPHY_EtwsCmasEndNtf; \
    LRRC_LPHY_SiBitmapNtf                       stLRRC_LPHY_SiBitmapNtf; \
    LRRC_LPHY_EccCfgReq                         stLRRC_LPHY_EccCfgReq; \
    LRRC_LPHY_SibLeapTimeGetReq                 stLRRC_LPHY_SibLeapTimeGetReq; \
    LRRC_LPHY_LppLeapTimeGetReq                 stLRRC_LPHY_LppLeapTimeGetReq; \
    LRRC_LPHY_LppLeapTimeGetCnf                 stLRRC_LPHY_LppLeapTimeGetCnf; \
    LRRC_LPHY_ModemCapLoadReq                   stLRRC_LPHY_ModemCapLoadReq; \
    LRRC_LPHY_ModemCapLoadCnf                   stLRRC_LPHY_ModemCapLoadCnf; \
    LRRC_LPHY_AntInfoReq                        stLRRC_LPHY_AntInfoReq; \
    LRRC_LPHY_AntInfoCnf                        stLRRC_LPHY_AntInfoCnf; \
    LRRC_LPHY_Smtc2                             stLRRC_LPHY_Smtc2; \
    LRRC_LPHY_SmtcConfig                        stLRRC_LPHY_SmtcConfig; \
    LRRC_LPHY_MeasNrSsbConfig               stLRRC_LPHY_MeasNrSsbConfig; \
    LRRC_LPHY_FreqAndRsssb                      stLRRC_LPHY_FreqAndRsssb; \
    LRRC_LPHY_NrMeasReq                         stLRRC_LPHY_NrMeasReq; \
    LRRC_LPHY_CcDlDediInfo                      stLRRC_LPHY_CcDlDediInfo; \
    LRRC_LPHY_CcUlDediInfo                      stLRRC_LPHY_CcUlDediInfo; \
    LRRC_LPHY_CcCommInfo                        stLRRC_LPHY_CcCommInfo; \
    LRRC_LPHY_CellInfo                          stLRRC_LPHY_CellInfo; \
    LRRC_LPHY_CcStatus                          stLRRC_LPHY_CcStatus; \
    LRRC_LPHY_CcConfigInfo                      stLRRC_LPHY_CcConfigInfo; \
    LRRC_LPHY_CgCdrxInfo                        stLRRC_LPHY_CgCdrxInfo; \
    LRRC_LPHY_DdrConfigMsgCcAddr                stLRRC_LPHY_DdrConfigMsgCcAddr; \
    LRRC_LPHY_DdrConfigMsgCgAddr                stLRRC_LPHY_DdrConfigMsgCgAddr; \
    LRRC_LPHY_DdrConfigMsgReq                   stLRRC_LPHY_DdrConfigMsgReq; \
    LRRC_LPHY_DdrConfigMsgCnf                   stLRRC_LPHY_DdrConfigMsgCnf; \
    LRRC_LPHY_ChangeToConnectedNtf              stLRRC_LPHY_ChangeToConnectedNtf; \
    LRRC_LPHY_PbchSetupReq                      stLRRC_LPHY_PbchSetupReq; \
    LRRC_LPHY_PbchSetupCnf                      stLRRC_LPHY_PbchSetupCnf; \
    LRRC_LPHY_PbchReleaseReq                    stLRRC_LPHY_PbchReleaseReq; \
    LRRC_LPHY_PbchReleaseCnf                    stLRRC_LPHY_PbchReleaseCnf; \
    LRRC_LPHY_PdschBchSetupReq                  stLRRC_LPHY_PdschBchSetupReq; \
    LRRC_LPHY_PdschBchSetupCnf                  stLRRC_LPHY_PdschBchSetupCnf; \
    LRRC_LPHY_TddConfigNtf                      stLRRC_LPHY_TddConfigNtf; \
    LRRC_LPHY_PdschBchReleaseReq                stLRRC_LPHY_PdschBchReleaseReq; \
    LRRC_LPHY_PdschBchReleaseCnf                stLRRC_LPHY_PdschBchReleaseCnf; \
    LRRC_LPHY_DlCommInfo                        stLRRC_LPHY_DlCommInfo; \
    LRRC_LPHY_PrachCommInfo                     stLRRC_LPHY_PrachCommInfo; \
    LRRC_LPHY_PuschCommInfo                     stLRRC_LPHY_PuschCommInfo; \
    LRRC_LPHY_PwrCtrlCommInfo                   stLRRC_LPHY_PwrCtrlCommInfo; \
    LRRC_LPHY_UlCommInfo                        stLRRC_LPHY_UlCommInfo; \
    LRRC_LPHY_CommRlSetupReq                    stLRRC_LPHY_CommRlSetupReq; \
    LRRC_LPHY_SpsConfig                         stLRRC_LPHY_SpsConfig; \
    LRRC_LPHY_LaaScellInfo                      stLRRC_LPHY_LaaScellInfo; \
    LRRC_LPHY_DlDediInfo                        stLRRC_LPHY_DlDediInfo; \
    LRRC_LPHY_PuschDediPara                     stLRRC_LPHY_PuschDediPara; \
    LRRC_LPHY_PucchDediPara                     stLRRC_LPHY_PucchDediPara; \
    LRRC_LPHY_PwrCtrlDediPara                   stLRRC_LPHY_PwrCtrlDediPara; \
    LRRC_LPHY_UlDediInfo                        stLRRC_LPHY_UlDediInfo; \
    LRRC_LPHY_DediRlSetupReq                    stLRRC_LPHY_DediRlSetupReq; \
    LRRC_LPHY_SuspendCnf                        stLRRC_LPHY_SuspendCnf; \
    LRRC_LPHY_ResumeCnf                         stLRRC_LPHY_ResumeCnf; \
    LRRC_LPHY_ConflictNrBandNtf                 stLRRC_LPHY_ConflictNrBandNtf;
/* lrrc_phy_interface.h end */
/* mac_lphy_interface.h start */
#define MAC_LPHY_INTERFACE_MAIN \
    enum LMAC_LPHY_MsgType           enLMAC_LPHY_MsgType; \
    enum LTE_ACCESS_Cause            enLTE_ACCESS_Cause; \
    enum LTE_ACCESS_Type             enLTE_ACCESS_Type; \
    enum LTE_RNTI_Type               enLTE_RNTI_Type; \
    enum LTE_CRC_Type                enLTE_CRC_Type; \
    enum LTE_DATAERR_Type            enLTE_DATAERR_Type; \
    enum L1L2_RSLT_Code              enL1L2_RSLT_Code; \
    enum LMAC_LPHY_VoiceStatus       enLMAC_LPHY_VoiceStatus; \
    enum LMAC_LPHY_PblPowerCause     enLMAC_LPHY_PblPowerCause; \
    enum LMAC_LPHY_CgId              enLMAC_LPHY_CgId; \
    enum LMAC_LPHY_ModemId           enLMAC_LPHY_ModemId; \
    enum LMAC_LPHY_DsdsRf            enLMAC_LPHY_DsdsRf; \
    enum LMAC_LPHY_UlDsdsTransPri    enLMAC_LPHY_DsdsTransPri; \
    enum LMAC_LPHY_ScellDeactType    enLMAC_LPHY_ScellDeactType; \
    enum LMAC_LPHY_SrSendResultType  enLMAC_LPHY_SrSendResultType; \
    LMAC_LPHY_AccessReq              stLMAC_LPHY_AccessReq;              /* ID_LMAC_LPHY_ACCESS_REQ */ \
    LMAC_LPHY_SrDataReq              stLMAC_LPHY_SrDataReq;              /* ID_LMAC_LPHY_SR_DATA_REQ */ \
    LMAC_LPHY_RaAckNtf               stLMAC_LPHY_RaAckNtf;               /* ID_LMAC_LPHY_RA_ACK_NTF */ \
    LMAC_LPHY_SpsReleaseNtf          stLMAC_LPHY_SpsReleaseNtf;          /* ID_LMAC_LPHY_SPS_RELEASE_NTF */ \
    LMAC_LPHY_RarConfigReq           stLMAC_LPHY_RarConfigReq;           /* ID_LMAC_LPHY_RAR_CONFIG_REQ */ \
    LMAC_LPHY_CrntiConfigNtf         stLMAC_LPHY_CrntiConfigNtf;         /* ID_LMAC_LPHY_CRNTI_CONFIG_NTF */ \
    LMAC_LPHY_TaTimerNtf             stLMAC_LPHY_TaTimerNtf;             /* ID_LMAC_LPHY_TA_TIMER_NTF */ \
    LMAC_LPHY_TaNtf                  stLMAC_LPHY_TaNtf;                  /* ID_LMAC_LPHY_TA_NTF */ \
    LMAC_LPHY_ConnectedDrxNtf        stLMAC_LPHY_ConnectedDrxNtf;        /* ID_LMAC_LPHY_CONNECTED_DRX_NTF */ \
    LMAC_LPHY_MtchStopNtf            stLMAC_LPHY_MtchStopNtf;            /* ID_LMAC_LPHY_MTCH_STOP_NTF */ \
    LMAC_LPHY_ScellActNtf            stLMAC_LPHY_ScellActNtf;            /* ID_LMAC_LPHY_SCELL_ACT_NTF */ \
    LMAC_LPHY_VoiceStatusNtf         stLMAC_LPHY_VoiceStatusNtf;         /* ID_LMAC_LPHY_VOICE_STATUS_NTF */ \
    LMAC_LPHY_GapConfigNtf           stLMAC_LPHY_GapConfigNtf;           /* ID_LMAC_LPHY_GAP_CONFIG_NTF */ \
    LMAC_LPHY_ForceActiveNtf         stLMAC_LPHY_ForceActiveNtf;         /* ID_LMAC_LPHY_FORCE_ACTIVE_NTF */ \
    LMAC_LPHY_HoCqiSrsActiveNtf      stLMAC_LPHY_HoCqiSrsActiveNtf;      /* ID_LMAC_LPHY_HO_CQI_SRS_ACTIVE_NTF */ \
    LMAC_LPHY_PduTransPri            stLMAC_LPHY_PduTransPri;            /* ID_LMAC_LPHY_PDU_TRANS_PRI_REQ */ \
    LMAC_LPHY_UlDynSkip              stLMAC_LPHY_UlDynSkip;              /* ID_LMAC_LPHY_SKIP_UL_TX_DYN_NTF */ \
    LMAC_LPHY_AccessCnf              stLMAC_LPHY_AccessCnf;              /* ID_LMAC_LPHY_ACCESS_CNF */ \
    LMAC_LPHY_SrDataCnf              stLMAC_LPHY_SrDataCnf;              /* ID_LMAC_LPHY_SR_DATA_CNF */ \
    LMAC_LPHY_UlGrantHarqInd         stLMAC_LPHY_UlGrantHarqInd;         /* ID_LMAC_LPHY_UL_GRANT_HARQ_IND */ \
    LMAC_LPHY_DlAssignmentInd        stLMAC_LPHY_DlAssignmentInd;        /* ID_LMAC_LPHY_DL_ASSIGNMENT_IND */ \
    LMAC_LPHY_PdcchOrderInd          stLMAC_LPHY_PdcchOrderInd;          /* ID_LMAC_LPHY_PDCCH_ORDER_IND */ \
    LMAC_LPHY_PdcchOrderSuccInd      stLMAC_LPHY_PdcchOrderSuccInd;      /* ID_LMAC_LPHY_PDCCH_ORDER_SUCC_IND */ \
    LMAC_LPHY_RarTimeoutInd          stLMAC_LPHY_RarTimeoutInd;          /* ID_LMAC_LPHY_RAR_TIMEOUT_IND */ \
    LMAC_LPHY_RarConfigCnf           stLMAC_LPHY_RarConfigCnf;           /* ID_LMAC_LPHY_RAR_CONFIG_CNF */ \
    LMAC_LPHY_PdcchReleaseUlspsInd   stLMAC_LPHY_PdcchReleaseUlspsInd;   /* ID_LMAC_LPHY_PDCCH_RELEASE_ULSPS_IND */ \
    LMAC_LPHY_ConnHstUnlockInd       stLMAC_LPHY_ConnHstUnlockInd;       /* ID_LMAC_LPHY_CONN_HST_UNLOCK_IND */ \
    LMAC_LPHY_Dsds3TaFailInd         stLMAC_LPHY_Dsds3TaFailInd;         /* ID_LMAC_LPHY_DSDS3_TA_FAIL_IND */ \
    LMAC_LPHY_DsdsRfUsedInd          stLMAC_LPHY_DsdsRfUsedInd;          /* ID_LMAC_LPHY_DSDS_RF_USED_IND */ \
    LMAC_LPHY_Msg3HarqInd            stLMAC_LPHY_Msg3HarqInd;            /* ID_LMAC_LPHY_MSG3_HARQ_IND */ \
    LMAC_LPHY_PlInd                  stLMAC_LPHY_PlInd;                  /* ID_LMAC_LPHY_PL_IND */ \
    LMAC_LPHY_PbInd                  stLMAC_LPHY_PbInd;                  /* ID_LMAC_LPHY_PB_IND */ \
    LMAC_LPHY_UlTransTimingDiffInd   stLMAC_LPHY_UlTransTimingDiffInd;   /* ID_LMAC_LPHY_UL_TRANS_TIMING_DIFF_IND */ \
    LMAC_LPHY_PowerRampSuspensionInd stLMAC_LPHY_PowerRampSuspensionInd; /* ID_LMAC_LPHY_PWR_RAMP_SUSPENSION_IND */ \
    LMAC_LPHY_RefPhInd               stLMAC_LPHY_RefPhInd;               /* ID_LMAC_LPHY_REF_PH_IND */ \
    LMAC_LPHY_RealPhInd              stLMAC_LPHY_RealPhInd;              /* ID_LMAC_LPHY_REAL_PH_IND */ \
    LMAC_LPHY_UlHarqMaxTxNumInd      stLMAC_LPHY_UlHarqMaxTxNumInd;      /* ID_LMAC_LPHY_UL_HARQ_MAX_TX_NUM_IND */ \
    LMAC_LPHY_PreambleTransFailInd   stLMAC_LPHY_PreambleTransFailInd;   /* ID_LMAC_LPHY_PREAMBLE_TRANS_FAIL_IND */ \
    LMAC_LPHY_SrTransFailInd         stLMAC_LPHY_SrTransFailInd;         /* ID_LMAC_LPHY_SR_TRANS_FAIL_IND */ \
    LMAC_LPHY_PucchAndRsrpInfo       stLMAC_LPHY_PucchAndRsrpInfo;       /* ID_LMAC_LPHY_PUCCH_RSRP_INFO_IND */ \
    LPHY_LMAC_CcMappingInd           stLPHY_LMAC_CcMappingInd;           /* ID_LMAC_LPHY_CC_MAPPING_IND */
/* mac_lphy_interface.h end */
/* lphy_hl1c_ll1d_interface.h start */
#define LPHY_HL1C_LL1D_INTERFACE_MAIN \
    enum LPHY_CSU_EmuFsReq           enLPHY_CSU_EmuFsReq; \
    LPHY_HL1C_L1cCsuSmpCfg           stLPHY_Hl1cL1cCsuSmpCfg; \
    LPHY_HL1C_L1cEmuFsCfg            stLPHY_Hl1cL1cEmuFsCfg; \
    LPHY_HL1C_Ll1cCellCfgInfo        stLPHY_Hl1cLl1cEmuCellInfo; \
    LPHY_HL1C_Ll1cEmuSmpCfg          stLPHY_Hl1cLl1cEmuSmpCfg; \
    LPHY_Hl1C_Ll1dEmuStopSmp         stLPHY_Hl1C_Ll1dEmuStopSmp; \
    LPHY_L1C_L1dBchConfig            stLPHY_L1C_L1D_BchConfig; \
    LPHY_L1C_L1DSiCfgMsg             stLPHY_L1C_L1DSiCfgMsg; \
    LPHY_L1C_L1DMbsfnCfgMsg          stLPHY_L1C_L1DMbsfnCfgMsg; \
    LPHY_Ll1cHl1cCsuReport           stLPHY_Ll1cHl1cCsuReport; \
    LPHY_Ll1cHl1cFreqScanRpt         stLPHY_Ll1cHl1cFreqScanRpt; \
    LPHY_Hl1cLl1cBandScanSmpCfg      stLPHY_Hl1cLl1cBandScanSmpCfg; \
    LPHY_Hl1cLl1cPssScanSmpCfg       stLPHY_Hl1cLl1cPssScanSmpCfg; \
    LPHY_Ll1cHl1cPssScanInfo         stLPHY_Ll1cHl1cPssScanInfo; \
    LPHY_Hl1cLl1cBandScanRpt         stLPHY_Hl1cLl1cBandScanRpt; \
    LPHY_Hl1cLl1cPssScanRpt          stLPHY_Hl1cLl1cPssScanRpt; \
    LPHY_PROC_CntCycle               stLPHY_PROC_CntCycle; \
    LPHY_CSU_OmCellRsltRpt           stLPHY_CSU_OmCellRsltRpt;
/* lphy_hl1c_ll1d_interface.h end */
/* lphy_hl1c_ll1u_interface.h start */
#define LPHY_HL1C_LL1U_INTERFACE_MAIN \
    LPHY_L1UL1C_UlHarqMaxTxNumInd    stLPHY_L1UL1C_UlHarqMaxTxNumInd;
/* lphy_hl1c_ll1u_interface.h end */
#define LPHY_PROC_MAIN \
    LPHY_EMU_SdrRptInfo              stLPHY_EMU_SdrRptInfo; \
    LPHY_SDR_Hl1cCsuReport           stLPHY_SDR_Hl1cCsuReport;
/* LTE PROC END */

/* TFSYNC */
#define LPHY_TFSYNC_MAIN \
    enum LPHY_TFSYNC_IcWorkMode      lphyTfsyncicWorkModeUint08; \
    LPHY_TFSYNC_ReqRptEn             lphyTfsyncReqRptEn; \
    LPHY_TFSYNC_IcOmRpt              lphyTfsyncIcOmRpt;
/* Tfpara */
#define NEUN_TFPARA_MAIN \
    enum NEUN_TFPARA_OmSwitch        lphyTfparaOmSwitchUint08; \
    NEUN_TFPARA_ReqReportEna         lphyTfparaReqReportEna; \
    NEUN_TFPARA_Om                   lphyTfparaOm; \
    LPHY_TFPE_OutPara                lphyTfparaOutPara; \
    NEUN_TFPE_SnrInfo                lphyTfparaSnrInfo; \
    NEUN_TFPE_RsrpNoiseSnr           lphyTfparaRsrpNoise; \
    NEUN_TFPE_LinearData             lphyTfparaLinearData; \
    LPHY_TFPE_OmRpt                  lphyTfparaOmRpt; \
    LPHY_TFPE_SfnFlag                lphyTfparaSfnFlag; \
    LPHY_TFPE_RptPara                lphyTfparaRptPara; \
    NEUN_TFSYNC_RecvWinInfo          lphyTfsyncWinPara; \
    enum NEUN_TFSYNC_RecWinMode      lphyTfsyncRecWinModeUint08; \
    NEUN_TFSYNC_WinParaStub          lphyTfsyncParaStub; \
    NEUN_TFPE_OutAlpha               lphyTfparanosieAlpha;
/* AGC */
#define LPHY_AGC_MAIN \
    LPHY_AGC_PwrRttOm            agcPwrRttOm; \
    LPHY_AGC_H2lMsg              agcH2lMsg; \
    LPHY_AGC_L2hMsg              agcl2HMsg; \
    LPHY_AGC_CcInfo              agcCcInfo; \
    LPHY_AGC_CcCalcInfo          agcCcCalcInfo; \
    LPHY_AGC_BBPRssiGainRpt      agcBbpRssiGain; \
    NEUN_AGC_CfuRptSlotPkg       cfuRpt; \
    NEUN_AGC_InbandSlotPkg       inbandRssi; \
    LPHY_AGC_CrsSlotPkg          crsRssi; \
    LPHY_AGC_BaseCellCtrl        lphyAgcBaseCell; \
    LPHY_AGC_EndPwrRptInfo       endPwrRpt; \
    LPHY_AGC_CcInfoBackup        agcInterCcInfo; \
    LPHY_AGC_InterAagcBackup     agcInterAagc; \
    enum NEUN_AGC_TaskType       agcTaskType; \
    LPHY_AGC_ParaOmInfo          agcParaOmInfo; \
    LPHY_AGC_WbRssiCtrl          agcWbRssiCtrl; \
    LPHY_AGC_WbRssiOmInfo        agcWbRssiOmInfo; \
    LPHY_AGC_AllTaskRpt          agcAllTask; \
    LPHY_AGC_AllCctrlRpt         agcAllCctrl; \
    NEUN_AGC_ShareLnaInfoRpt     agcLnaInfo;
/* LTE DSDS START */
#define LPHY_DSDS_MAIN \
    enum LPHY_DSDS_OmMsgType        lphyDsdsOmReport; \
    enum RCM_PHY_MsgId              rcmPhyMsgId; \
    enum RCM_MODE_Id                rcmModeId; \
    enum RCM_MODEM_Id               rcmModemId; \
    enum RCM_PHY_ConcurrenceState   phyRcmConcSt; \
    enum RCM_RF_Id                  rcmRfId; \
    enum NEUN_DSDS_RfState          neunDdsdsRfState; \
    enum NEUN_DSDS_SchedState       neunDdsdsSchedState; \
    enum NEUN_DSDS_TaskTimerType    neunDdsdsTaskTimerType; \
    enum NEUN_DSDS_TimeroutTrigType neunDdsdsTimeOutTrigType; \
    enum NEUN_DSDS_FixStartPos      neunDdsdsFixStartPos; \
    enum NEUN_DSDS_TaskFiniteType   neunDdsdsTaskFiniteType; \
    enum NEUN_DSDS_PreemptState     neunDdsdsPreemptState; \
    enum NEUN_DSDS_PreemptAckState  neunDdsdsPreemptAckState; \
    enum NEUN_DRX_32KType           neunDrx32KType; \
    enum NEUN_CHANNEL_Type          neunChannelType; \
    NEUN_DSDS_TaskAttribute         neunDdsdsTaskAttribute; \
    NEUN_PROC_RfSuspendInfo         neunDdsdsRcmSuspendInfo; \
    NEUN_DSDS_ConfigInfo            neunDdsdsConfigInfo; \
    DSDS_32K_Timer                  neunDdsds32K_Timer; \
    NEUN_DSDS_ApplyInfo             neunDdsdsApplyInfo; \
    NEUN_DSDS_PreemptInfo           neunDdsdsPreemptInfo; \
    NEUN_DSDS_TaskContext           neunDdsdsTaskContext; \
    NEUN_DSDS_SuspendInfo           neunDdsdsSuspendInfo; \
    DSDS_NEUN_Time                  neunDdsdsime; \
    NEUN_DSDS_TaskApplyRequest      neunDdsdsTaskApplyRequest; \
    NEUN_DSDS_OmRptTaskStatus       neunDdsdsOmRptTaskStatus; \
    LPHY_L1U_UldsdsOmReport         lphyL1uUldsdsOmReport; \
    PHY_RCM_TaskReqPara             phyRcmTaskReqPara; \
    PHY_RCM_TaskApplyReq            phyRcmTaskApplyReq; \
    PHY_RCM_TaskRelReq              phyRcmTaskRelReq; \
    PHY_RCM_TaskRelallReq           phyRcmTaskRelallReq; \
    PHY_RCM_AssignAck               phyRcmAssignAck; \
    PHY_RCM_TaskResumeAck           phyRcmTaskResumeAck; \
    PHY_RCM_TaskPreemptAck          phyRcmTaskPreemptAck; \
    PHY_RCM_ConcurrenceStateInd     phyRcmConcurrenceStateInd; \
    PHY_RCM_SuspendRfCnf            phyRcmSuspendRfCnf; \
    PHY_RCM_UlDsdsFallbackInd       phyRcmUlDsdsFallbackInd; \
    PHY_RCM_BackupAntCtrlCnf        phyRcmBackupAntCtrlCnf; \
    PHY_RCM_CarrierApplyReq         phyRcmCarrierApplyReq; \
    PHY_RCM_CarrierReleaseInd       phyRcmCarrierReleaseInd; \
    PHY_RCM_CarrierSuspendAck       phyRcmCarrierSuspendAck; \
    PHY_RCM_MimoFallbackAck         phyRcmMimoFallbackAck; \
    PHY_RCM_MimoReconfigReq         phyRcmMimoReconfigReq;
    /* LTE DSDS END */
    /* FEC om */
#define LPHY_FEC_MAIN \
    LPHY_FEC_OmCcReqInfo         ccReqInfo; \
    LPHY_UL_FecSfrmCtrlInterface FecSfrmCtrlInterface;\
    LPHY_FEC_TxOmInfo            TxOmInfo;\

/* LPC */
#define LPHY_LPC_MAIN \
    LPHY_LPC_CtrlInfo                stLPHY_LPC_CtrlInfo; \
    NEUN_LPC_OmSwitch                lpcOmSwtich; \
    LPHY_LPC_OmStubReq               lpcOmStubReq; \
    LPHY_DVFS_TspProfileInfo         dvfsTspProfInfo; \
    LPHY_LPC_OmDvtyInfo              lphyLpcOmDvtyInfo; \
    LPHY_LPC_DvtyDemoduInfo          lphyDvtyDemoduInfo; \
    LPHY_LPC_OmSymbRxBitInfo         lphyOmSymbRxBitInfo; \
    enum NEUN_LPC_PrintEvt           lpcPrintEvt; \
    enum UPHY_OM_ReportLevel         printLevel; \
    enum NEUN_LPC_SymbLpcWorkMode    pccWorkMode; \
    NEUN_LPC_PrintRptInfo            lphyLpcPrintInfo; \
    UPHY_LPC_PdcOnlyRecord           lphyLpcPdcOnlyInfo;
/* DRX */
#define LPHY_CDRX_OM_MAIN \
    enum LPHY_CDRX_OmL1MsgId     lphyCdrxOmL1MsgID; \
    NEUN_CDRX_OmRptCtrl          lphyCdrxOmRptCtrl; \
    NEUN_CDRX_OmTimeInfo         lphyCdrxOmTimeInfo; \
    NEUN_CDRX_OmOnduTmrInfo      lphyCdrxOmOnduTmrInfo; \
    NEUN_CDRX_OmAddTmrInfo       lphyCdrxOmAddTmrInfo; \
    NEUN_CDRX_OmDelTmrInfo       lphyCdrxOmDelTmrInfo; \
    NEUN_CDRX_OmRrcCfgInfoRpt    lphyCdrxOmRrcCfgInfoRpt; \
    LPHY_CDRX_SpsWakeInfo        lphyCdrxOmSpsWakeInfo; \
    LPHY_CDRX_OmSpsInfo          lphyCdrxOmSpsInfo;
/* SCHED */
#define LPHY_SCHED_OM_MAIN \
    LPHY_SCHED_OmSymbCycleRptReq     SymbCycleRptReq;
/* LTE HL1C SCHED OM */
#define LPHY_HL1C_SEHED_OM_MAIN \
    LPHY_OM_Hl1cCycleRpt             hl1cCycleRpt;
/* LTE LL1D SCHED OM */
#define LPHY_LL1D_SEHED_OM_MAIN \
    LPHY_OM_Ll1dCycleRpt             ll1dCycleRpt;
#define LPHY_PROC_OM_MAIN \
    enum NEUN_PROC_State             omMeasState; \
    enum NEUN_PROC_ExecuteState      omMeasExecState; \
    enum NEUN_DC_GapCfgType          omDcGapCfgType; \
    LPHY_PROC_IntraMeasState         omIntraMeasState; \
    LPHY_PROC_IntraCounter           omIntraCnt; \
    NEUN_PROC_MeasState              omInterMeasState; \
    LPHY_PROC_EndcGapOmInfo          omEndcGapInfo; \
    LPHY_PROC_InterIratWaitSchedNum  omInterWaitSchedNum; \
    LPHY_PROC_IratMeasAllocGapInfo   omIratMeasIntoGap; \
    LPHY_PROC_IratMeasOutGapInfo     omIratMeasOutGap;\
    LPHY_PROC_IratNrNogapCapOmInfo   omIratNrNogapCap;\
    LPHY_PROC_NrNogapDescellOmInfo   omNrDescellNogap;\
    LPHY_PROC_IratNrInfo             omIratnrinfo;
/* emu om */
#define LPHY_EMU_OM_MAIN \
    enum LPHY_EMU_ReqEnable   omEmuEnable; \
    enum LPHY_EMU_OmEmuStopSmpType omEmuStopType; \
    LPHY_EMU_OmEmuReqCtrl          omEmuReqCtrl; \
    LPHY_EMU_OmEmuStopSmp          omEmuStopSmp; \
    NEUN_EMU_HalBbpCfgReg              omEmuCfgReg; \
    LPHY_EMU_IndAllFreqSg           omEmuAll; \
    LPHY_EMU_IndServeSg             omServSg; \
    LPHY_EMU_MeasCfg                omMeasCfg; \
    UL1M_PRM_EMU_ResInfo            omEmuResInfo; \
    UL1M_PRM_EMU_ModeCcInfoCtx      omLrEmuModeCcInfo; \
    NEUN_EMU_CellSchedStateUint08       cellSchedState; \
    NEUN_PROCESS_IdUint08               processId; \
    LPHY_COMMEMU_OmSmpCfg           omSmpCfg;
    NEUN_EMU_RptLineMeasInfo        omRptLineMeasInfo; \
    LPHY_EMU_HalOmReadRegInfo       omReadRegInfo;
/* FEICIC start */
#define LPHY_FEICIC_MAIN \
    enum LPHY_FEICIC_SfrmType                   lphyFeicicSfrmType; \
    enum LPHY_FEICIC_CellTypeNgb                lphyFeicicCellTypeNgb; \
    enum LPHY_FEICIC_SevCellIcMode              lphyFeicicSevCellIcMode; \
    enum LPHY_FEICIC_NgbCellNum                 lphyFeicicNgbCellNum; \
    enum LPHY_FEICIC_CrsIcCellChange            lphyFeicicCrsIcCellChange; \
    enum LPHY_FEICIC_SubframeSize               lphyFeicicSubframeSize; \
    enum LPHY_FEICIC_AntSel                     lphyFeicicAntSel; \
    enum LPHY_FEICIC_IcNgbCell                  lphyFeicicIcNgbCell; \
    enum LPHY_FEICIC_IcChannel                  lphyFeicicIcChannel; \
    enum LPHY_FEICIC_NgbMbsfn                   lphyFeicicNgbMbsfn; \
    enum LPHY_FEICIC_IcOrder                    lphyFeicicIcOrder; \
    enum LPHY_FEICIC_IcCell                     lphyFeicicIcCell; \
    enum LPHY_FEICIC_CellType                   lphyFeicicCellType; \
    enum LPHY_FEICIC_MemberAction               lphyFeicicMemberAction; \
    enum LPHY_FEICIC_State                      lphyFeicicState; \
    enum LPHY_FEICIC_CrsIcMode                  lphyFeicicCrsIcMode; \
    enum LPHY_FEICIC_PbDecState                 lphyFeicicPbDecState; \
    enum LPHY_FEICIC_CrsIcState                 lphyFeicicCrsIcState; \
    LPHY_FEICIC_OmCtrl                          lphyFeicicOmCtrl; \
    LPHY_FEICIC_OmStubCtrl                      lphyFeicicOmStubCtrl; \
    LPHY_FEICIC_MeasInfoReport                  lphyFeicicMeasInfoReport; \
    LPHY_FEICIC_CrsIcInfoReport                 lphyFeicicCrsIcInfoReport; \
    LPHY_FEICIC_CrsIcOrder                      lphyFeicicCrsIcOrder; \
    LPHY_FEICIC_WorkStatus                      lphyFeicicWorkStatus; \
    LPHY_FEICIC_RrcConfig                       lphyFeicicRrcConfig; \
    LPHY_FEICIC_MibPbchDecCellInfoReport        lphyFeicicMibPbchDecCellInfoReport; \
    LPHY_FEICIC_PbIcCellInfoBuff                lphyFeicicPbIcCellInfoBuff; \
    LPHY_FEICIC_WorkCommStatus                  lphyFeicicCommWorkStatus; \
    LPHY_FEICIC_WorkStatusInfoReport            lphyFeicicWorkStatusInfoReport;
/* FEICIC end */
/* IRAT start */
#define LPHY_IRAT_MAIN \
    enum UL1M_IRAT_MsgTypeId_                   lphyIratFreqMeasTypeId; \
    enum LPHY_IRAT_OmSwitch                     lphyIratOmSwitch; \
    enum NEUN_IRAT_IntMsgNum                    lphyIratIntMsgNum; \
    enum UL1M_IRAT_RatTypeId                    lphyIratRatTypeId; \
    LPHY_IRAT_OmCtrlReq                         lphyIratOmCtrlReq; \
    NEUN_IRAT_FreqMeasCompleteInfo              lphyIratFreqMeasCompleteInfo; \
    NEUN_IRAT_IntMsgInfo                        lphyIratIntMsgInfo; \
    UL1M_IRAT_PreSchedInfoStru                  lphyIratPreSchedInfo; \
    NEUN_IRAT_OmPreSchedMsg                     lphyIratOmPreSchedMsg; \
    NEUN_IRAT_OmArbPreSchedMsg                  lphyIratOmArbPreSchedMsg; \
    NEUN_IRAT_TimDiffInfo                       lphyIratTimDiffInfo;
    /* IRAT end */
/* TAS begin */
#define LPHY_RCM_ASU_MAIN \
    PHY_RCM_StartTasCnf                         omPhyRcmStartTasCnf; \
    PHY_RCM_StopTasCnf                          omPhyRcmStopTasCnf; \
    PHY_RCM_SetDpdtCnf                          omPhyRcmSetDpdtCnf; \
    PHY_RCM_TxBlankingInd                       omPhyRcmTxBlankingInd; \
    PHY_RCM_RatmodeInd                          omPhyRcmRatmodeInd; \
    PHY_RCM_AccessStateInd                      omPhyRcmAccessStateInd; \
    PHY_RCM_SearchingStateInd                   omPhyRcmSearchingStateInd; \
    PHY_RCM_SignalStateInd                      omPhyRcmSignalStateInd; \
    PHY_RCM_IdleHappyInd                        omPhyRcmIdleHappyInd; \
    PHY_RCM_OnlyStartMasCnf                     omPhyRcmOnlyStartMasCnf; \
    PHY_RCM_OnlyStopMasCnf                      omPhyRcmOnlyStopMasCnf;\
    PHY_RCM_TasStateInd                         omPhyRcmTasStateInd;\
/* TAS end */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* end of hids_elf_lphy.c */

