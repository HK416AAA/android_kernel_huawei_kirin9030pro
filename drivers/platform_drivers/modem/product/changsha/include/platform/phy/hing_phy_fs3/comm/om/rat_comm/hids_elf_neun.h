
#ifndef HIDS_ELF_NEUPHY_H
#define HIDS_ELF_NEUPHY_H


/*
 * 1 其他头文件包含
 */
#include "neun_basedef_macro.h"
#include "neun_basedef_enum.h"
#include "neun_basedef_struct.h"
#include "neun_proc_basedef_enum.h"
#include "lrrc_phy_interface.h"
#include "nrrc_nphy_interface.h"
#include "neun_hl1c_ll1d_interface.h"
#include "neun_hl1c_ll1u_msg_struct.h"
#include "nphy_lphy_interface.h"
#include "neun_top_interface.h"
#include "neun_proc_om_base_def.h"
#include "neun_wmc_om_def.h"
#include "neun_fec_om_def.h"
#include "neun_dl_afc_interface.h"
#include "neun_tru_interface.h"
#include "neun_tru_om_def.h"
#include "neun_agc_om_def.h"
#include "neun_afc_om_def.h"
#include "neun_afc_interface.h"
#include "neun_tfpara_om_def.h"
#include "neun_csu_om_def.h"
#include "neun_smp_om_def.h"
#include "neun_tfsync_om_def.h"
#include "neun_sdra_msg.h"
#include "ul1m_rcm_phy_interface.h"
#include "ul1m_prm_ul_share_interface.h"
#include "neun_dsds_om_def.h"
#include "neun_uldsds_om_def.h"
#include "neun_lpc_om_def.h"
#include "ul1m_neun_agc_om.h"
#include "ul1m_neun_tfsync_om.h"
#include "ul1m_neun_tfpara_om.h"
#include "ul1m_neun_dsds_om.h"
#include "ul1m_neun_afc_om.h"
#include "ul1m_neun_tru_om.h"
#include "ul1m_neun_wmc_om.h"
#include "neun_asu_om_def.h"
#include "neun_feu_auto_report_om_base_def.h"
#include "uphy_lpc_dfx_interface.h"
#include "neun_hl1c_ll1d_csu_interface.h"
#include "neun_proc_interface.h"
#include "neun_fec_dfu_interface.h"
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/* NEUN PROC START */
#define NEUN_PROC_MAIN \
    /* neun_proc_om_base_def.h start */ \
    enum NEUN_PROC_PrintType                    enNEUN_PROC_PrintType; \
    enum NEUN_PROC_OmSwitch                     enNEUN_PROC_OmSwitch; \
    enum NEUN_PROC_OmReqMsg                     enNEUN_PROC_OmReqMsg; \
    enum NEUN_PROC_OmRptReq                     enNEUN_PROC_OmRptReq; \
    enum NEUN_PROC_OmReport                     enNEUN_PROC_OmReport; \
    /* neun_proc_om_base_def.h end */ \
    /* neun_basedef_enum.h start */ \
    enum NEUN_PROC_Mode                         enNEUN_PROC_Mode; \
    enum NEUN_PARA_Valid                        enNEUN_ParaValid; \
    enum NEUN_UL_Type                           enNEUN_UlType; \
    enum NEUN_MODEM_Id                          enNEUN_ModemId; \
    enum NEUN_CaCellIdx                         enNEUN_CaCellIdx; \
    enum NEUN_SCS_Type                          enNEUN_ScsType; \
    enum NEUN_CP_Type                           enNEUN_CpType; \
    enum NEUN_CG_Idx                            enNEUN_CgIdx; \
    enum NEUN_FRAME_Type                        enNEUN_FrameType; \
    enum NEUN_LTE_TddUdCfg                      enNEUN_LTE_TddUdCfg; \
    enum NEUN_LTE_SpecSubFrmCfg                 enNEUN_LTE_SpecSubFrmCfg; \
    enum NEUN_MAILBOX_Idx                       enNEUN_MailboxIdx; \
    enum NEUN_WMC_ReqEffectTime                 enNEUN_WMC_ReqEffectTime; \
    enum NEUN_WMC_FecEffectTime                 enNEUN_WMC_FecEffectTime; \
    enum NEUN_WMC_FecEffectPos                  enNEUN_WMC_FecEffectPos; \
    enum NEUN_EffectScene                       enNEUN_EffectScene; \
    enum NEUN_WMC_EvtReqType                    enNEUN_WMC_EvtReqType; \
    enum NEUN_PROCESS_Id                        enNEUN_ProcessId; \
    enum NEUN_PROC_PresyncIdx                   enNEUN_PROC_PresyncIdx; \
    enum NEUN_WMC_AfcProcessIdx                 enNEUN_WMC_AfcProcessIdx; \
    enum NEUN_NR_ProcInterMeasType              enNEUN_NR_PROC_InterMeasType; \
    enum NEUN_CC_State                          enNEUN_CcState; \
    enum NEUN_CC_CfgState                       enNEUN_CcCfgState; \
    enum NEUN_UL_SarAntPort                     enNEUN_UL_SarAntPort; \
    enum NEUN_FCFU_ChanIdx                      enNEUN_FCFU_ChanIdx; \
    enum NEUN_BBA_ChanIdx                       enNEUN_BBA_ChanIdx; \
    enum NEUN_UE_RxAntNum                       enNEUN_UeRxAntNum; \
    enum NEUN_UE_TxAntNum                       enNEUN_UeTxAntNum; \
    enum NEUN_CellType                          enNEUN_CellType; \
    enum NEUN_EnodeBTxAntNum                    enNEUN_EnodeBTxAntNum; \
    enum NEUN_WMC_FastReqType                   enNEUN_WMC_FastReqType; \
    enum NEUN_BAND_Width                        enNEUN_BandWidth; \
    enum NEUN_NR_EmuSsbType                     enNEUN_NR_EmuSsbType; \
    enum NEUN_SampleSelType                     enNEUN_SampleSelType; \
    enum NEUN_AgcMbmpInfo                       enNEUN_AgcMbmpInfo; \
    enum NEUN_LTE_AgcBsStatus                   enNEUN_LTE_AgcBsStatus; \
    enum NEUN_FCFU_RxAntSelect                  enNEUN_FCFU_RxAntSelect; \
    enum NEUN_FCFU_CfuChType                    enNEUN_FCFU_CfuChType; \
    enum NEUN_CELL_SSB_CoresetPattern           enNEUN_CELL_SSB_CoresetPattern; \
    enum NEUN_AirCellIndex                      enNEUN_AirCellIndex; \
    enum NEUN_PROC_PwrCtrlMode                  enNEUN_PROC_PwrCtrlMode; \
    enum NEUN_SCS_TypeState                     enNEUN_ScsTypeState; \
    enum NEUN_PROC_RcmPaLevel                   enNEUN_PROC_RcmPaLevel; \
    enum NEUN_SCHED_Mode                        enNEUN_SCHED_Mode; \
    enum NEUN_DCI_Coreset                       enNEUN_DciCoreset; \
    enum NEUN_RNTI_Type                         enNEUN_RntiType; \
    enum NEUN_UL_CcState                        enNEUN_UlCcState; \
    enum NEUN_UL_BwpSwitch                      enNEUN_UlBwpSwitch; \
    enum NEUN_DCI_Format                        enNEUN_DCI_Format; \
    enum NEUN_SFI_Update                        enNEUN_SfiUpdate; \
    enum NEUN_SLOT_FormatPatten                 enNEUN_SlotFormatPatten; \
    enum NEUN_SFI_SlotType                      enNEUN_SfiSlotType; \
    enum NEUN_FFT_Idx                           enNEUN_FftIdx; \
    enum NEUN_IFFT_Idx                          enNEUN_IfftIdx; \
    enum NEUN_PRE_SyncRsType                    enNEUN_PreSyncRsType; \
    enum NEUN_EMU_TxResourceType                enNEUN_EmuTxResourceType; \
    enum NEUN_BAND_Ind                          enNEUN_BandInd; \
    enum LPHY_PROC_RxAntSwitchType              enLPHY_PROC_RxAntSwitchType; \
    /* neun_basedef_enum.h end */ \
    /* neun_proc_basedef_enum.h start */ \
    enum NEUN_PROC_ScellActState                enNEUN_PROC_ScellActState; \
    enum NEUN_PROC_ScellResyncCondition         enNEUN_PROC_ScellResyncCondition; \
    enum NEUN_RRC_State                         enNEUN_RRC_State; \
    enum NEUN_FOSCAN_Mode                       enNEUN_FoscanMode; \
    enum NEUN_SSB_CaseType                      enNEUN_SSB_CaseType; \
    enum NEUN_PROC_SrchEntryType                enNEUN_PROC_SrchEntryType; \
    enum NEUN_PROC_GrantState                   enNEUN_PROC_GrantState; \
    enum NEUN_PROC_InitSyncSubProc              enNEUN_PROC_InitSyncSubProc; \
    enum NEUN_PROC_BgsSubProc                   enNEUN_PROC_BgsSubProc; \
    enum NEUN_PROC_BgsRunState                  enNEUN_PROC_BgsRunState; \
    enum NEUN_PROC_BgsPriority                  enNEUN_PROC_BgsPriority; \
    enum NEUN_PROC_CampOnSubProc                enNEUN_PROC_CampOnSubProc; \
    enum NEUN_PROC_ReleaseSubProc               enNEUN_PROC_ReleaseSubProc; \
    enum NEUN_PROC_ReleaseMsgId                 enNEUN_PROC_ReleaseMsgId; \
    enum NEUN_PROC_ConnSubProc                  enNEUN_PROC_ConnSubProc; \
    enum NEUN_PROC_RachState                    enNEUN_PROC_RachState; \
    enum NEUN_PROC_ConnMsgId                    enNEUN_PROC_ConnMsgId; \
    enum NEUN_PROC_ConnCacheId                  enNEUN_PROC_ConnCacheId; \
    enum NEUN_PROC_ConnExtendCacheId            enNEUN_PROC_ConnExtendCacheId; \
    enum NEUN_PROC_ConnLphyCacheId              enNEUN_PROC_ConnLphyCacheId; \
    enum NEUN_PROC_State                        enNEUN_PROC_State; \
    enum NEUN_PROC_ExecuteState                 enNEUN_PROC_ExecuteState; \
    enum NEUN_PROC_PhaseState                   enNEUN_PROC_PhaseState; \
    enum NEUN_BAND_ScanType                     enNEUN_BandScanType; \
    enum NEUN_SDR_TaskType                      enNEUN_SDR_TaskType; \
    enum NEUN_BWP_Id                            enNEUN_BwpId; \
    enum NEUN_PROC_BwpState                     enNEUN_PROC_BwpState; \
    enum NEUN_FPU_ChanIdx                       enNEUN_FpuChanIdx; \
    enum NEUN_PROC_TimerType                    enNEUN_PROC_TimerType; \
    enum NEUN_PROC_TimerRefType                 enNEUN_PROC_TimerRefType; \
    enum NEUN_PROC_OmTrigSrc                    enNEUN_PROC_OmTrigSrc; \
    enum NEUN_ARB_ProcPriority                  enNEUN_ARB_ProcPriority; \
    enum NEUN_ARB_ProcFixPos                    enNEUN_ARB_ProcFixPos; \
    enum NEUN_ARB_ProcLatestPos                 enNEUN_ARB_ProcLatestPos; \
    enum NEUN_ARB_ProcPreactVal                 enNEUN_ARB_ProcPreactVal; \
    enum NEUN_ARB_ProcLimitLen                  enNEUN_ARB_ProcLimitLen; \
    enum NEUN_ARB_ProcRfOccupy                  enNEUN_ARB_ProcRfOccupy; \
    enum NEUN_PROC_NcbdSubproc                  enNEUN_PROC_NcbdSubproc; \
    enum NEUN_PROC_NcbdConfigState              enNEUN_NcbdConfigState; \
    enum NEUN_PROC_ScbdSubProc                  enNEUN_PROC_ScbdSubProc; \
    enum NEUN_PROC_ScbdConfigState              enNEUN_PROC_ScbdConfigState; \
    enum NEUN_PROC_HoSubProc                    enNEUN_PROC_HoSubProc; \
    enum NEUN_PROC_PbchType                     enNEUN_PROC_PbchType; \
    enum NEUN_PROC_BchType                      enNEUN_PROC_BchType; \
    enum NEUN_PROC_ForceStopType                enNEUN_PROC_ForceStopType; \
    enum NEUN_PROC_PubFlag                      enNEUN_PROC_PubFlag; \
    enum NEUN_PROC_SwitchModeState              enNEUN_PROC_SwitchModeState; \
    enum NEUN_RRC_IntraFreqType                 enNEUN_RRC_IntraFreqType; \
    enum NEUN_PROC_ServDpdtState                enNEUN_PROC_ServDpdtState; \
    enum NEUN_PCELL_ProcEndMsg                  enNEUN_PCELL_ProcEndMsg; \
    enum NEUN_PROC_AccessType                   enNEUN_PROC_AccessType; \
    enum NEUN_PROC_RlmBfrResCfgType             enNEUN_PROC_RlmBfrResCfgType; \
    enum NEUN_LTE_RlConfigType                  enNEUN_LTE_RlConfigType; \
    enum NEUN_NR_RlConfigType                   enNEUN_NR_RlConfigType; \
    enum NPHY_PROC_BgsBchState                  enNPHY_PROC_BgsBchState; \
    /* neun_proc_basedef_enum.h end */ \
    /* neun_top_interface.h start */ \
    enum NEUN_PBCH_Dec                          enNEUN_PbchDec; \
    enum NEUN_SSB_SmpChIdx                      enNEUN_SsbSmpChIdx; \
    /* neun_top_interface.h end */ \
    /* neun_hl1c_ll1d_interface.h start */ \
    enum NEUN_L1C_L1dMsgType                    enNEUN_L1C_L1dMsgType; \
    enum NEUN_BCH_Type                          enNEUN_BchType; \
    enum NEUN_EFFECT_Time                       enNEUN_EffectTime; \
    enum NEUN_SerachSpaceParaType               enNEUN_SerachSpaceParaType; \
    enum NEUN_SearchSpaceType                   enNEUN_SearchSpaceType; \
    enum NEUN_L1CL1D_StopType                   enNEUN_L1CL1D_StopType; \
    NEUN_L1C_L1dPbchSetUpInfo                   stNEUN_L1C_L1D_PbchSetUpInfo; \
    NEUN_L1C_L1dSsbShareInfo                    stNEUN_L1C_L1D_SsbShareInfo; \
    NEUN_L1D_L1cPbchResult                      stNEUN_L1D_L1C_PbchResult; \
    NEUN_L1C_L1dTimeInfo                        stNEUN_L1C_L1D_TimeInfo; \
    NEUN_L1C_L1dChnlActive                      stNEUN_L1C_L1D_ChnlActive; \
    NEUN_L1C_L1dChnlDeactive                    stNEUN_L1C_L1D_ChnlDeactive; \
    NEUN_L1C_L1dPdschBchRelease                 stNEUN_L1C_L1D_PdschBchRelease; \
    NEUN_L1C_L1dReleaseAll                      stNEUN_L1C_L1D_ReleaseAll; \
    NEUN_L1C_L1dRarConfigReq                    stNEUN_L1C_L1D_RarConfigReq; \
    NEUN_L1C_L1dRaAckNtf                        stNEUN_L1C_L1D_RaAckNtf; \
    NEUN_PROC_PrachSendInfo                     stNEUN_PROC_PrachSendInfo; \
    NEUN_L1C_L1dAccessNtf                       stNEUN_L1C_L1D_AccessNtf; \
    NEUN_L1C_L1dCrntiConfigReq                  stNEUN_L1C_L1D_CrntiConfigReq; \
    NEUN_L1C_L1dConn2Idle                       stNEUN_L1C_L1D_Conn2Idle; \
    NEUN_L1C_L1dScellActNtf                     stNEUN_L1C_L1D_ScellActNtf; \
    NEUN_L1C_L1dScellDeactiveNtf                stNEUN_L1C_L1D_ScellDeactiveNtf; \
    NEUN_L1C_L1dCdrxMacCeNtf                    stNEUN_L1C_L1D_CdrxMacCeNtf; \

    NEUN_L1C_L1dConnContentionRachSuccNtf       stNEUN_L1C_L1D_ConnContentionRachSuccNtf; \
    NEUN_L1D_L1cSearchSpacePara                 stNEUN_L1D_L1C_SearchSpacePara; \
    NEUN_L1D_L1cPchSiSsRpt                      stNEUN_L1D_L1C_PchSiSsRpt; \
    NEUN_HL1C_Ll1cSmpTaskStop                   stNEUN_Hl1cLl1cSmpTaskStop; \
    NEUN_LL1C_Hl1cEmuSmpFinish                  stNEUN_Ll1cHl1cEmuSmpFinish; \
    NEUN_Ll1cHl1cAbortSmpFinish                 stNEUN_Ll1cHl1cAbortSmpFinish; \
    NEUN_HL1C_Ll1cBandScanStop                  stNEUN_Hl1cLl1cBandScanStop; \
    NEUN_L1D_L1cSetWorkNodeCnf                  stNEUN_L1D_L1C_SetWorkNodeCnf; \
    NEUN_L1D_L1cActiveCnf                       stNEUN_L1D_L1C_ActiveCnf; \
    NEUN_L1C_L1dSetWorkModeReq                  stNEUN_L1C_L1D_SetWorkModeReq; \
    NEUN_L1C_L1dRlConfigReq                     stNEUN_L1C_L1D_RlConfigReq; \
    NEUN_L1CL1D_SyncNtf                         stNEUN_L1CL1D_SyncNtf; \
    NEUN_L1DL1C_SyncInd                         stNEUN_L1DL1C_SyncInd; \
    NEUN_L1CL1D_CampFinishNtf                   stNEUN_L1CL1D_CampFinishNtf; \
    NEUN_L1CL1D_HoFinishNtf                     stNEUN_L1CL1D_HoFinishNtf; \
    NEUN_L1CL1D_InterSlotNtf                    stNEUN_L1CL1D_InterSlotNtf; \
    NEUN_L1C_L1dLpcMsg                          stNEUN_L1C_L1D_LpcMsg; \
    NEUN_L1D_L1cLpcMsg                          stNEUN_L1D_L1C_LpcMsg; \
    NEUN_L1DL1C_RarTimeoutInd                   stNEUN_L1DL1C_RarTimeoutInd; \
    NEUN_L1D_L1cRelAllCnf                       stNEUN_L1D_L1cRelAllCnf; \
    NEUN_L1C_L1dMtchStopNtf                     stNEUN_L1C_L1dMtchStopNtf; \
    NEUN_L1C_L1dGapConfigNtf                    stNEUN_L1C_L1dGapConfigNtf; \
    NEUN_L1D_L1cPdcchOrderInd                   stNEUN_L1D_L1cPdcchOrderInd; \
    NEUN_L1D_L1cAccessCrntiInd                  stNEUN_L1D_L1cAccessCrntiInd; \
    NEUN_L1C_L1dCdrxMacCeNtf                    stNEUN_L1C_L1dCdrxMacCeNtf; \
    NEUN_L1D_L1cPagingInd                       stNEUN_L1D_L1cPagingInd; \
    NEUN_L1D_L1cShortMessageInd                 stNEUN_L1D_L1cShortMessageInd; \
    NEUN_Hl1cLl1cFreqScanSmpCfg                 stNEUN_Hl1cLl1cFreqScanSmpCfg; \
    NEUN_L1C_L1dBbpFinishNtf                    stNEUN_L1C_L1dBbpFinishNtf; \
    NEUN_L1C_L1dRxBlerReq                       stNEUN_L1C_L1dRxBlerReq; \
    NEUN_L1D_L1cRxBlerRpt                       stNEUN_L1D_L1cRxBlerRpt; \
    NEUN_L1C_L1D_CdrxCfgNtf                     stNEUN_L1C_L1D_CdrxCfgNtf; \
    NEUN_L1C_L1dCommMsg                         stNEUN_L1C_L1dCommMsg; \
    /* neun_hl1c_ll1d_interface.h end */ \
    /* nphy_lphy_interface.h start */ \
    enum LPHY_PROC_NrForceStop                  enLPHY_PROC_NR_FORCE_STOP_ENUM; \
    enum LPHY_FEC_UlChannelType                 enLPHY_FEC_UL_CHANNEL_TYPE_ENUM; \
    enum LPHY_FEC_UlAntType                     enLPHY_FEC_UL_ANT_TYPE_ENUM; \
    enum LPHY_FEC_UlScheduleType                enLPHY_FEC_UL_SCHEDULE_TYPE_ENUM; \
    enum LPHY_FEC_LphyToHl1CMsg                 enLPHY_FEC_LPHY_TO_HL1C_MSG_ENUM; \
    enum NPHY_NSA_UlType                        enNPHY_NSA_UL_TYPE_ENUM; \
    enum NPHY_LPHY_MsgType                      enNPHY_LPHY_MSG_TYPE_ENUM; \
    enum NPHY_SCS_Type                          enNPHY_SCS_TYPE_ENUM; \
    enum NPHY_ENDC_Band                         enNPHY_ENDC_BAND_ENUM; \
    enum NPHY_PROC_CcCfgState                   enNPHY_PROC_CC_CONFIG_STATE_ENUM; \
    NPHY_LPHY_SarAntInfo                        stNPHY_LPHY_SarAntInfo; \
    NPHY_LPHY_NphyVirPhrInfo                    stNPHY_LPHY_NphyVirPhrInfo; \
    NPHY_LPHY_EndcUlVirPhNtf                    stNPHY_LPHY_EndcUlVirPhNtf; \
    NPHY_LPHY_NphyUlTransInfo                   stNPHY_LPHY_NphyUlTransInfo; \
    NPHY_LPHY_NphyUlSchInfo                     stNPHY_LPHY_NphyUlSchInfo; \
    NPHY_LPHY_EndcUlSchNtf                      stNPHY_LPHY_EndcUlSchNtf; \
    NPHY_LPHY_NphyUlPhInfo                      stNPHY_LPHY_NphyUlPhInfo; \
    NPHY_LPHY_EndcUlPhNtf                       stNPHY_LPHY_EndcUlPhNtf; \
    NPHY_LPHY_EndcPwrSharePara                  stNPHY_LPHY_EndcPwrSharePara; \
    NPHY_LPHY_EndcUlCfgNtf                      stNPHY_LPHY_EndcUlCfgNtf; \
    NPHY_LPHY_EndcPhrCfg                        stNPHY_LPHY_EndcPhrCfg; \
    NPHY_LPHY_EndcUlPhrCfgNtf                   stNPHY_LPHY_EndcUlPhrCfgNtf; \
    NPHY_LPHY_EndcTimingReq                     stNPHY_LPHY_EndcTimingReq; \
    NPHY_PROC_NsaEndcCssf                       stNPHY_PROC_NsaEndcCssf; \
    NPHY_PROC_NsaGapIntTimeInd                  stNPHY_PROC_NsaGapIntTimeInd; \
    NPHY_PROC_DsdxNtf                           stNPHY_PROC_DsdxNtf; \
    NPHY_LPHY_WritePpmReq                       stNPHY_LPHY_WritePpmReq; \
    NPHY_PROC_SrsCcSwitch2Lphy                  stNPHY_PROC_SrsCcSwitch2Lphy; \
    LPHY_NPHY_UlSulPara                         stLPHY_NPHY_ULSUL_PARA_STRU; \
    LPHY_NPHY_UlSulInfo                         stLPHY_NPHY_UL_SUL_INFO_STRU; \
    LPHY_NPHY_RfcUlSulCfg                       stLPHY_NPHY_RfcUlSulCfg; \
    LPHY_NPHY_RfcUlSulFlag                      stLPHY_NPHY_RfcUlSulFlag; \
    LPHY_NPHY_EndcMaxPowInfo                    stLPHY_NPHY_EndcMaxPowInfo; \
    LPHY_NPHY_SendNrStartInfo                   stLPHY_NPHY_SendNrStartInfo; \
    UL1M_PRM_EndcIntraBandPara                  stUL1M_PRM_EndcIntraBandPara; \
    UL1M_PRM_EndcPowerShareInfo                 stUL1M_PRM_EndcPowerShareInfo; \
    UL1M_PRM_EndcPowerShare                     stUL1M_PRM_EndcPowerShare; \
    UL1M_PRM_EndcTimingInfo                     stUL1M_PRM_EndcTimingInfo; \
    UL1M_PRM_LphyPhInfo                         stUL1M_PRM_LphyPhInfo; \
    UL1M_PRM_LphyChnPwrInfo                     stUL1M_PRM_LphyChnPwrInfo; \
    UL1M_PRM_LphyUlPwrInfo                      stUL1M_PRM_LphyUlPwrInfo; \

    /* nphy_lphy_interface.h end */ \
    NEUN_PROC_OmCtrl                            stNEUN_PROC_OmCtrl; \
    NEUN_PROC_Base                              stNEUN_PROC_Base; \
    NEUN_PROC_PrintInfo                         stLPHY_PROC_PrintInfo; \
    NEUN_PROC_ConnContext                       stNEUN_PROC_ConnContext; \
    NEUN_PROC_CommContext                       stNEUN_PROC_CommContext; \
    NEUN_PROC_CommTimerContext                  stNEUN_PROC_CommTimerContext; \
    NEUN_ARB_ProcMgrContext                     stNEUN_ARB_ProcMgrContext; \
    NEUN_SERV_CellContext                       stNEUN_SERV_CellContext; \
    NEUN_SERV_ServCellInfo                      stNEUN_SERV_ServCellInfo; \
    NEUN_DL_InterCellLocalInfo                  stNEUN_DlInterCellLocalInfo; \
    NEUN_DL_CellLocalInfo                       stNEUN_DlCellLocalInfo; \
    NEUN_UL_CellLocalInfo                       stNEUN_UlCellLocalInfo; \
    NEUN_PROC_CcInfo                            stNEUN_PROC_CcInfo; \
    NEUN_PROC_ResyncCsuResult                   stNEUN_PROC_ResyncCsuResult; \
    NEUN_PROC_ResyncPbchResult                  stNEUN_PROC_ResyncPbchResult; \
    NEUN_PROC_PbchResult                        stNEUN_PROC_PbchResult; \
    NEUN_PROC_RelsContext                       stNEUN_PROC_RelsContext; \
    NEUN_PROC_InitSyncContext                   stNEUN_PROC_InitSyncContext; \
    NEUN_PROC_NcbdContext                       stNEUN_PROC_NcbdContext; \
    NEUN_PROC_CampOnContext                     stNEUN_PROC_CampOnContext; \
    NEUN_PROC_BgsContext                        stNEUN_PROC_BgsContext; \
    NEUN_PROC_ScbdContext                       stNEUN_PROC_ScbdContext; \
    NEUN_PROC_PagingContext                     stNEUN_PROC_PagingContext; \
    NEUN_PROC_HoContext                         stNEUN_PROC_HoContext; \
    NEUN_PROC_IntraContext                      stNEUN_PROC_IntraContext; \
    NEUN_PROC_ErrPrintOmTrigInfo                stNEUN_PROC_ErrPrintOmTrigInfo; \
    NEUN_PROC_AgentScgContext                   stNEUN_PROC_AgentScgContext; \
    NEUN_CCM_Context                            ccmContext; \
    NEUN_PROC_KeyOmContext                      stNEUN_PROC_KeyOmContext; \
    enum NEUN_LL1C_SDR_MSG_TYPE_                enNEUN_LL1C_SDR_MSG_TYPE_;
/* NEUN PROC END */
/* WMC */
#define NEUN_WMC_MAIN \
    NEUN_FEC_ProcCcaQueryPara              fecProcCcaQueryPara; \
    NEUN_FEC_CcaQueryPara                  fecCcaQueryPara; \
    NEUN_FEC_CcaQueryResult                fecCcaQueryResult; \
    NEUN_WMC_ReqRptEna                     wmcRptEn; \
    NEUN_WMC_OmRptB                        wmcBInfoRpt; \
    NEUN_WMC_FastBRpt                      wmcFastBRpt; \
    NEUN_WMC_OmRptBCtrl                    wmcBCtrlRpt; \
    NEUN_WMC_ProcOmInfo                    wmcProcRpt; \
    NEUN_WMC_CInfo                         wmcCInfoRpt; \
    NEUN_WMC_ErrorInfo                     wmcErrRpt; \
    NEUN_WMC_ActInfoRpt                    wmcactRpt; \
    /* WMC 枚举定义 */ \
    enum NEUN_WMC_AfcProcessIdx            afcProcessType; \
    enum NEUN_NR_ProcInterMeasType         nrInterType; \
    enum NEUN_TRU_WorkModeReq              truMode; \
    enum NEUN_FEC_WorkModeReq              fecMode; \
    enum NEUN_WMC_ProcActFlag              procActFlg; \
    enum NEUN_AFC_WorkMode                 afcMode;
/* fec om */
#define NEUN_FEC_MAIN \
    enum NEUN_FEC_OmHandleType              omHandleType; \
    enum NEUN_FEC_AutoReportMsgId           autoReportMsgId; \
    NEUN_FEC_DbgComRptInfo                  dbgComRptInfo; \
    NEUN_FEC_DbgReqRptEn                    dbgReqRptEn; \
    NEUN_FEC_RfDrvEventInfo                 rfDrvEventReqRptInfo; \
    NEUN_FEC_OmReportEn                     rfDrvEventReqRptEn; \
    NEUN_FEC_RfDrvEvent                     rfDrvEvent; \
    NEUN_FEC_ReadRegEn                      readRegEn; \
    NEUN_FEC_ReadRegValue                   readRegValue; \
    NEUN_FEC_ReadRegInfo                    readRegInfo; \
    NEUN_FEC_ReportData                     reportData; \
    NEUN_FEC_AutoReportPara                 autoReportPara;
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
    NEUN_AFC_TpaReadOm                                          afcTpaReadOm;
/* TRU */
#define NEUN_TRU_MAIN \
    enum NEUN_TRU_SysTimEffectType                              truSysTimEffctTypeUint08; \
    enum NEUN_TRU_TimeCfgType                                   truTimeCfgTypeUint08; \
    enum NEUN_TRU_LockType                                      truLockTypeUint08; \
    enum NEUN_TRU_FftType                                       truFftTypeUint08; \
    enum NEUN_BAND_Width                                        truBandWidthUint08; \
    NEUN_TRU_DLToHl1cMsg                                        truDlToHl1cMsg; \
    NEUN_TRU_CcBase                                             truCcBase; \
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
    NEUN_AGC_ShareLnaInfoRpt                                    agcLnaInfo;
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
/* CSU */
#define NEUN_CSU_MAIN \
    NEUN_CSU_OmCtrl                                             omCsuCtrl; \
    NEUN_CSU_OmInitEmuCtrl                                      omCsuInitEmuCtrl; \
    NEUN_CSU_OmStep1RsltRptInfo                                 omCsuStep1RsltRpt; \
    NEUN_CSU_OmStep2RsltRptInfo                                 omCsuStep2RsltRpt; \
    NEUN_CSU_OmStep1RegRptInfo                                  omCsuStep1RegRpt; \
    NEUN_SDR_TspFuncOmCtrl                                      omSdrTspFuncCtrl; \
    NEUN_SDR_TspfuncTrsDopplerRpt                               omSdrTrsDopRpt; \
    NEUN_SDR_TspfuncSsbDopplerRpt                               omSdrSsbDopRpt; \
    NEUN_SDR_TspfuncTrmsDopplerRpt                              omSdrTrmsDopRpt; \
    NEUN_SDR_TspfuncDmrsDopplerRpt                              omSdrDmrsDopRpt; \
    NEUN_SDR_BeamOmCtrl                                         omSdrBeamCtrl; \
    NEUN_CSU_OmCycleInfo                                        omcycleRpt; \
    NEUN_CSU_OmSmpRsltInfo                                      omSmpRsltInfo; \
    NEUN_SDR_OmTaskLoadInfo                                     omTaskLoadInfo;
/* SMP */
#define NEUN_SMP_MAIN \
    NEUN_SMP_OmCsuStep1RptInfo                                  omSmpStep1Ctrl;
/* DSDS START */
#define NEUN_DSDS_MAIN \
    enum RCM_PHY_MsgId              rcmPhyMsgId; \
    enum NEUN_DSDS_RfState          neunDdsdsRfState; \
    enum NEUN_DSDS_SchedState       neunDdsdsSchedState; \
    enum NEUN_DSDS_TaskTimerType    neunDdsdsTaskTimerType; \
    enum NEUN_DSDS_TimeroutTrigType neunDdsdsTimeOutTrigType; \
    enum NEUN_DSDS_FixStartPos     neunDdsdsFixStartPos; \
    enum NEUN_DSDS_TaskFiniteType   neunDdsdsTaskFiniteType; \
    enum NEUN_DSDS_PreemptState     neunDdsdsPreemptState; \
    enum NEUN_DSDS_PreemptAckState  neunDdsdsPreemptAckState; \
    enum NEUN_CHANNEL_Type          neunChannelType; \
    enum NEUN_DSDS_OmReq            neunDsdsOmReq; \
    enum NEUN_ULDSDS_OmRptMsgId     neunUldsdsOmRptMsgId; \
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
    PHY_RCM_TaskRelReq              phyRcmTaskRelReq; \
    PHY_RCM_TaskRelallReq           phyRcmTaskRelallReq; \
    PHY_RCM_AssignAck               phyRcmAssignAck; \
    PHY_RCM_TaskResumeAck           phyRcmTaskResumeAck; \
    PHY_RCM_TaskPreemptAck          phyRcmTaskPreemptAck; \
    PHY_RCM_InterfereBusinessInd    phyRcmBusinessInd; \
    NEUN_DSDS_OmCtrl                neunDsdsOmCtrl; \
    NEUN_ULDSDS_OmCtrlReq           neunUldsdsOmCtrlReq; \
    NEUN_ULDSDS_OmSchedPara         neunUldsdsOmSchedPara; \
    NEUN_SSM_DSDS_VoteReqPara         neunUldsdsVoteReqPara; \
    NEUN_SSM_DSDS_ProtectPara         neunUldsdsProtectPara; \
    NEUN_L1CL1U_UldsdsSatusNtf      neunUldsdsStatusNtf; \
    NEUN_ULDSDS_OmTxInterrupt       neunUldsdsOmTxInterrupt; \
    NEUN_DSDS_SrsContext            neunDsdsSrsInfo; \
    NEUN_DSDS_OmRptSrsInfo          neunDsdsOmRptSrsInfo; \
    NEUN_DSDS_ArbProcMgrContext     neunDsdsArbProcMgrContest; \
    NEUN_DSDS_ArbProcShareContext   neunDsdsArbProcShareContext;
/* DSDS END */
/* LPC */
#define NEUN_LPC_MAIN \
    enum NEUN_LPC_DvtyImmedEvt      neunLpcDvtyImmedEvt; \
    enum NEUN_LPC_DvtyMode          neunLpcDvtyMode; \
    UPHY_LPC_DfxRptInfo             neunLpcDfxRptInfo;
/* ASU START */
#define NEUN_ASU_MAIN \
    NEUN_ASU_OmReportAsuStatus      neunAsuOmReportAsuStatus; \
    NEUN_ASU_CsReport               neunAsuCsReport; \
    NEUN_ASU_CallbackComm           neunAsuCallbackComm; \
    NEUN_ASU_Context                neunAsuContext; \
    NEUN_ASU_ReportSarInfo          neunAsuReportSarInfo; \
    NEUN_ASU_OmReportConnComm       neunAsuOmReportConnComm; \
    NEUN_ASU_TxTasComm              neunAsuTxTasComm; \
    NEUN_ASU_OmTxLimitState         neunAsuOmTxLimitState; \
    NEUN_ASU_OmRptTxStatis          neunAsuOmRptTxStatis; \
    NEUN_ASU_TxSelDlAnt             neunAsuTxSelDlAnt; \
    NEUN_ASU_RxTasProbe             neunAsuRxTasProbe; \
    NEUN_ASU_CommConfig             neunAsuCommConfig; \
    NEUN_ASU_EmuReport              neunAsuEmuReport; \
    NEUN_ASU_OmRptRsrpFilter        neunAsuOmRptRsrpFilter; \
    NEUN_ASU_FreeProcInfo           neunAsuFreeProcInfo; \
    NEUN_ASU_IdleProcInfo           neunAsuIdleProcInfo; \
    NEUN_ASU_RachProcInfo           neunAsuRachProcInfo; \
    NEUN_ASU_ConnProcInfo           neunAsuConnProcInfo; \
    NEUN_ASU_ToolRpt                neunAsuToolRpt; \
    NEUN_ASU_BlankingInfo           neunAsuBlankingInfo; \
    NEUN_ASU_ToolRptCtrl            neunAsuToolRptCtrl; \
    NEUN_ASU_OmCtrl                 neunAsuOmCtrl; \
    NEUN_ASU_OmCfgTxPower           neunAsuOmCfgTxPower; \
    NEUN_ASU_OmCfgTxStatis          neunAsuOmCfgTxStatis;
/* ASU END */
#define NEUN_CCM_MAIN \
    enum NEUN_CcmProcIdEnum         enNEUN_CcmProcIdEnum; \
    enum NEUN_ProcChanType          enNEUN_ProcChanType; \
    enum NEUN_ProcChanReq           enNEUN_ProcChanReq; \
    enum NEUN_ProcChanEffectTime    enNEUN_ProcChanEffectTime; \
    enum NEUN_ProcEvent             enNEUN_ProcEvent;

#ifdef __cplusplus
#if __cplusplus
        }
#endif
#endif

#endif /* end of hids_elf_neuphy.c */

