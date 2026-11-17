
#ifndef HIDS_ELF_NPHY_H
#define HIDS_ELF_NPHY_H


/*
 * 1 其他头文件包含
 */
#include "nphy_basedef_enum.h"
#include "nphy_basedef_struct.h"
#include "nrrc_nphy_interface.h"
#include "mac_nphy_interface.h"
#include "nphy_hl1c_ll1d_interface.h"
#include "nphy_hl1c_ll1u_interface.h"
#include "nphy_comm_meas_interface.h"
#include "nphy_ul_om_def.h"
#include "nphy_proc_om_base_def.h"
#include "nphy_fec_om_def.h"
#include "nphy_dl_chanctrl_om_def.h"
#include "ul1m_nphy_dl_chanctrl_interface.h"
#include "nphy_dl_csi_om_def.h"
#include "nphy_dl_dem_om_def.h"
#include "nphy_lpc_om_def.h"
#include "nphy_lpc_interface.h"
#include "nphy_tsn_interface.h"
#include "neun_afc_interface.h"
#include "nphy_dl_afc_interface.h"
#include "ul1m_ulpm_interface.h"
#include "ul1m_nphy_lpc_om.h"
#include "ul1m_nphy_drx_om.h"
#include "ul1m_nphy_sched_om.h"
#include "neun_hl1c_ll1d_interface.h"
#include "neun_hl1c_ll1u_msg_struct.h"
#include "neun_drx_interface.h"
#include "nphy_sfi_om_def.h"
#include "nphy_tru_om_def.h"
#include "nphy_dl_che_om_def.h"
#include "nphy_dl_che_dt_om_def.h"
#include "nphy_ul_csi_om.h"
#include "nphy_tfpara_om_def.h"
#include "nphy_tfsync_om_def.h"
#include "nphy_dsds_om_def.h"
#include "nphy_agc_om_def.h"
#include "nphy_sfas_om_base_def.h"
#include "ul1m_rcm_phy_interface.h"
#include "nphy_sched_om_def.h"
#include "nphy_drx_om_def.h"
#include "neun_drx_om_def.h"
#include "ul1m_nphy_dl_csi_om.h"
#include "ul1m_nphy_ul_csi_om.h"
#include "ul1m_nphy_tfpara_om.h"
#include "ul1m_nphy_tfsync_om.h"
#include "ul1m_nphy_sfi_om.h"
#include "ul1m_nphy_emu_om.h"
#include "ul1m_nphy_irat_om.h"
#include "ul1m_nphy_cycle_om.h"
#include "nphy_irat_om_def.h"
#include "nphy_sdrc_om_def.h"
#include "nphy_csu_interface.h" /* 使用NPHY_FOSCAN_ModeUint08 */
#include "nphy_sdra_om_def.h"
#include "nphy_proc_struct.h"
#include "hids_elf_nphy_base.h"
#include "uphy_lpc_dfx_interface.h"
#include "neun_ll1d_tfsync_win_interface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/* NR PROC START */
/* nphy_basedef_enum.h start */
#define NPHY_BASEDEF_ENUM_MAIN \
    enum NPHY_UL_CcState                        enNPHY_UL_CC_STATE_ENUM; \
    enum NPHY_PROC_InitSyncMsgId                enNPHY_PROC_InitSyncMsgId; \
    enum NPHY_PROC_NcbdMsgId                    enNPHY_PROC_NcbdMsgId; \
    enum NPHY_PROC_ReleaseMsgId                 enNPHY_PROC_ReleaseMsgId; \
    enum NPHY_PROC_BgsMsgId                     enNPHY_PROC_BgsMsgId; \
    enum NPHY_PROC_ScbdMsId                     enNPHY_PROC_ScbdMsId; \
    enum NPHY_PROC_LinkStatus                   enNPHY_PROC_LINK_STATUS_ENUM; \
    enum NPHY_PROC_RlmBfrTestType               enNPHY_PROC_RlmBfrTestType; \
    enum NPHY_PROC_RlmTruResType                enNPHY_PROC_RlmTruResType; \
    enum NPHY_PROC_RlmRxNum                     enNPHY_PROC_RlmRxNum; \
    enum NPHY_PROC_RlmScsType                   enNPHY_PROC_RlmScsType; \
    enum NPHY_PROC_RlmTruJudgeType              enNPHY_PROC_RlmTruJudgeType;
/* nphy_basedef_enum.h end */
/* nphy_basedef_struct.h start */
#define NPHY_BASEDEF_STRUCT_MAIN \
    NPHY_PROC_SpecificInfo                      stNPHY_PROC_SpecificInfo; \
    NPHY_BEAMARB_Context                        stNPHY_BEAMARB_Context;
/* nphy_basedef_struct.h end */
/* nphy_proc_comm_interface.h start */
#define NPHY_PROC_COMM_INTERFACE_MAIN \
    enum NPHY_CSI_RlmResUpdate                  enNPHY_CSI_RlmResUpdate; \
    enum NPHY_CSI_RlmQclValid                   enNPHY_CSI_RlmQclValid; \
    enum NPHY_PROC_RlmBfrCfgType                enNPHY_PROC_RlmBfrCfgType; \
    enum NPHY_PROC_RlmBfrResType                enNPHY_PROC_RlmBfrResType; \
    enum NPHY_UL_State                          enNPHY_UL_State; \
    NPHY_PROC_CsiRptCfgPerCc                    stNPHY_PROC_CsiRptCfgPerCc; \
    NPHY_COMM_DediRlCfgPerCcDlFusion            stNPHY_COMM_DediRlCfgPerCcDlFusion; \
    NPHY_COMM_SrsCfgPerUlCarrier                stNPHY_COMM_SrsCfgPerUlCarrier; \
    NPHY_COMM_NulCcCfg                          stNPHY_COMM_NulCcCfg; \
    NPHY_PROC_CntCycle                          stNPHY_PROC_CntCycle; \
    NPHY_COMM_SulCcCfg                          stNPHY_COMM_SulCcCfg;
/* nphy_proc_comm_interface.h end */
/* nphy_proc_interface.h start */
#define NPHY_PROC_INTERFACE_MAIN \
    enum NPHY_PROC_GapTrace                     enNPHY_PROC_GapTrace; \
    enum NPHY_PROC_GapSubprocType               enNPHY_PROC_GapSubprocType; \
    NPHY_PROC_GapInfo                           stNPHY_PROC_GapInfo;
/* nphy_proc_interface.h end */
/* nrrc_nphy_interface.h start */
#define NRRC_NPHY_INTERFACE_MAIN \
    enum NRRC_NPHY_PifMsgType                   enNRRC_NPHY_PifMsgType; \
    enum NRRC_NPHY_DpdtCmd                      enNRRC_NPHY_DpdtCmd; \
    enum NRRC_NPHY_DrxCount                     enNRRC_NPHY_DrxCount; \
    enum NRRC_NPHY_GapShareScheme               enNRRC_NPHY_GapShareScheme; \
    enum NRRC_NPHY_PagingCycle                  enNRRC_NPHY_PagingCycle; \
    enum NRRC_NPHY_CsiResTypeForCh              enNRRC_NPHY_CsiResTypeForCh; \
    enum NRRC_NPHY_CsiRptNgN1N2Type             enNRRC_NPHY_CsiRptNgN1N2Type; \
    enum NRRC_NPHY_CsiRptType2N1N2Type          enNRRC_NPHY_CsiRptType2N1N2Type; \
    enum NRRC_NPHY_DmaMemIdx                    enNRRC_NPHY_DmaMemIdx; \
    enum NRRC_NPHY_GapAdvanceTime               enNRRC_NPHY_GapAdvanceTime; \
    enum NRRC_NPHY_GapLength                    enNRRC_NPHY_GapLength; \
    enum NRRC_NPHY_GapRepPeriod                 enNRRC_NPHY_GapRepPeriod; \
    enum NRRC_NPHY_BandWidth                    enNRRC_NPHY_BandWidth; \
    enum NRRC_NPHY_BeamFailDetectNum            enNRRC_NPHY_BeamFailDetectNum; \
    enum NRRC_NPHY_BeamFailDetectTimer          enNRRC_NPHY_BeamFailDetectTimer; \
    enum PS_CgId                         enPS_CgId; \
    enum NRRC_NPHY_CsiRptAntPortsType           enNRRC_NPHY_CsiRptAntPortsType; \
    enum NRRC_NPHY_CsiRptType1N1N2Type          enNRRC_NPHY_CsiRptType1N1N2Type; \
    enum NRRC_NPHY_CsiRptPortIdxType            enNRRC_NPHY_CsiRptPortIdxType; \
    enum NRRC_NPHY_CsiRptSubband                enNRRC_NPHY_CsiRptSubband; \
    enum NRRC_NPHY_MimoLayer                    enNRRC_NPHY_MimoLayer; \
    enum NRRC_NPHY_PdschBundleType              enNRRC_NPHY_PdschBundleType; \
    enum NRRC_NPHY_PwrCtrlCloseLoopIdx          enNRRC_NPHY_PwrCtrlCloseLoopIdx; \
    enum NRRC_NPHY_RlMonitorRsPurpose           enNRRC_NPHY_RlMonitorRsPurpose; \
    enum NRRC_NPHY_SrsResSetType                enNRRC_NPHY_SrsResSetType; \
    enum NRRC_NPHY_CsiImScLoc                   enNRRC_NPHY_CsiImScLoc; \
    enum NRRC_NPHY_BeamFailDetectResType        enNRRC_NPHY_BeamFailDetectResType; \
    enum NRRC_NPHY_CoresetPrecoderGranu         enNRRC_NPHY_CoresetPrecoderGranu; \
    enum NRRC_NPHY_CsiRptBlerTarget             enNRRC_NPHY_CsiRptBlerTarget; \
    enum NRRC_NPHY_CsiRptTimeRestrict           enNRRC_NPHY_CsiRptTimeRestrict; \
    enum NRRC_NPHY_DrxOnDurationType            enNRRC_NPHY_DrxOnDurationType; \
    enum NRRC_NPHY_HarqProcNum                  enNRRC_NPHY_HarqProcNum; \
    enum NRRC_NPHY_PtrsReOff                    enNRRC_NPHY_PtrsReOff; \
    enum NRRC_NPHY_PucchGroupHoppingType        enNRRC_NPHY_PucchGroupHoppingType; \
    enum NRRC_NPHY_PuschTransPrecoder           enNRRC_NPHY_PuschTransPrecoder; \
    enum NRRC_NPHY_PuschWithUciScale            enNRRC_NPHY_PuschWithUciScale; \
    enum NRRC_NPHY_SearchSpaceUeSpecFmt         enNRRC_NPHY_SearchSpaceUeSpecFmt; \
    enum PS_RachSsbNumPerRo                  enPS_RachSsbNumPerRo; \
    enum PS_BfrRsType                 enPS_BfrRsType; \
    enum NRRC_NPHY_UlConfigredGrantType         enNRRC_NPHY_UlConfigredGrantType; \
    enum NRRC_NPHY_XOverhead                    enNRRC_NPHY_XOverhead; \
    enum NRRC_NPHY_BandScanType                 enNRRC_NPHY_BandScanType; \
    enum PS_UlType                       enPS_UlType; \
    enum NRRC_NPHY_UlPuschType                  enNRRC_NPHY_UlPuschType; \
    enum NRRC_NPHY_AggregationFactor            enNRRC_NPHY_AggregationFactor; \
    enum NRRC_NPHY_AggregationLevel             enNRRC_NPHY_AggregationLevel; \
    enum PS_Alpha                        enPS_Alpha; \
    enum NRRC_NPHY_CoresetCceRegMappingType     enNRRC_NPHY_CoresetCceRegMappingType; \
    enum NRRC_NPHY_CoresetInterleaverRows       enNRRC_NPHY_CoresetInterleaverRows; \
    enum NRRC_NPHY_CqiFormat                    enNRRC_NPHY_CqiFormat; \
    enum NRRC_NPHY_CsiCodebookType1Subtype      enNRRC_NPHY_CsiCodebookType1Subtype; \
    enum NRRC_NPHY_CsiCodebookType2AlphaSize    enNRRC_NPHY_CsiCodebookType2AlphaSize; \
    enum NRRC_NPHY_CsiCodebookType2BeamsNum     enNRRC_NPHY_CsiCodebookType2BeamsNum; \
    enum NRRC_NPHY_CsiCodebookType2SamplSize    enNRRC_NPHY_CsiCodebookType2SamplSize; \
    enum NRRC_NPHY_CsiCodebookType2Subtype      enNRRC_NPHY_CsiCodebookType2Subtype; \
    enum NRRC_NPHY_CsiImPattern                 enNRRC_NPHY_CsiImPattern; \
    enum NRRC_NPHY_CsiPdschBundleSize           enNRRC_NPHY_CsiPdschBundleSize; \
    enum NRRC_NPHY_SelCsiResCfg                 enNRRC_NPHY_SelCsiResCfg; \
    enum NRRC_NPHY_CsiResType                   enNRRC_NPHY_CsiResType; \
    enum NRRC_NPHY_CsiRptCqiTable               enNRRC_NPHY_CsiRptCqiTable; \
    enum NRRC_NPHY_CsiRptPeriod                 enNRRC_NPHY_CsiRptPeriod; \
    enum NRRC_NPHY_CsiRptQuantityType           enNRRC_NPHY_CsiRptQuantityType; \
    enum NRRC_NPHY_CsiRptSemiPuschSlotConfig    enNRRC_NPHY_CsiRptSemiPuschSlotConfig; \
    enum NRRC_NPHY_CsiRptSubbandSize            enNRRC_NPHY_CsiRptSubbandSize; \
    enum NRRC_NPHY_CsiRsCdmType                 enNRRC_NPHY_CsiRsCdmType; \
    enum NRRC_NPHY_CsiRsDensityDot5PrbAlloc     enNRRC_NPHY_CsiRsDensityDot5PrbAlloc; \
    enum NRRC_NPHY_CsiRsFreqAlloc               enNRRC_NPHY_CsiRsFreqAlloc; \
    enum NRRC_NPHY_CsiRsPeriod                  enNRRC_NPHY_CsiRsPeriod; \
    enum NRRC_NPHY_CsiRsPortNum                 enNRRC_NPHY_CsiRsPortNum; \
    enum NRRC_NPHY_CwNumScheByDci               enNRRC_NPHY_CwNumScheByDci; \
    enum NRRC_NPHY_DlPreemptTimeFreqSet         enNRRC_NPHY_DlPreemptTimeFreqSet; \
    enum NRRC_NPHY_DlSpsPeriod                  enNRRC_NPHY_DlSpsPeriod; \
    enum PS_DmrsAddiPos                  enPS_DmrsAddiPos; \
    enum PS_DmrsMaxLen                   enPS_DmrsMaxLen; \
    enum PS_DmrsTypeAPos                 enPS_DmrsTypeAPos; \
    enum NRRC_NPHY_DrxInactivityTimer           enNRRC_NPHY_DrxInactivityTimer; \
    enum NRRC_NPHY_DrxLongDrxPeriod             enNRRC_NPHY_DrxLongDrxPeriod; \
    enum NRRC_NPHY_DrxOnDuraTimerMs             enNRRC_NPHY_DrxOnDuraTimerMs; \
    enum NRRC_NPHY_DrxRetransTimerDl            enNRRC_NPHY_DrxRetransTimerDl; \
    enum NRRC_NPHY_DrxRetransTimerUl            enNRRC_NPHY_DrxRetransTimerUl; \
    enum NRRC_NPHY_DrxShortDrxPeriod            enNRRC_NPHY_DrxShortDrxPeriod; \
    enum NRRC_NPHY_HarqAckCodebook              enNRRC_NPHY_HarqAckCodebook; \
    enum NRRC_NPHY_LteCarrBw                    enNRRC_NPHY_LteCarrBw; \
    enum NRRC_NPHY_LteCrsPortsNum               enNRRC_NPHY_LteCrsPortsNum; \
    enum NRRC_NPHY_LteCrsVShift                 enNRRC_NPHY_LteCrsVShift; \
    enum NRRC_NPHY_LteMbsfnAllocPeriod          enNRRC_NPHY_LteMbsfnAllocPeriod; \
    enum NRRC_NPHY_LteMbsfnAllocSubframeType    enNRRC_NPHY_LteMbsfnAllocSubframeType; \
    enum NRRC_NPHY_MaxCbgNumPerTb               enNRRC_NPHY_MaxCbgNumPerTb; \
    enum NRRC_NPHY_McsTable                     enNRRC_NPHY_McsTable; \
    enum NRRC_NPHY_NzpCsiResPwrCtrlOffsetSs     enNRRC_NPHY_NzpCsiResPwrCtrlOffsetSs; \
    enum NRRC_NPHY_PassLossRefLink              enNRRC_NPHY_PassLossRefLink; \
    enum NRRC_NPHY_PdschBundleSize              enNRRC_NPHY_PdschBundleSize; \
    enum PS_PxschMappingType             enPS_PxschMappingType; \
    enum NRRC_NPHY_PlRefRsType                  enNRRC_NPHY_PlRefRsType; \
    enum NRRC_NPHY_PmiFormat                    enNRRC_NPHY_PmiFormat; \
    enum PS_RachPrachRootSeqIndex              enPS_RachPrachRootSeqIndex; \
    enum PS_RachPrachRestrictSetType           enPS_RachPrachRestrictSetType; \
    enum NRRC_NPHY_PucchMaxCodeRate             enNRRC_NPHY_PucchMaxCodeRate; \
    enum NRRC_NPHY_PucchOccIdx                  enNRRC_NPHY_PucchOccIdx; \
    enum NRRC_NPHY_PucchOccLen                  enNRRC_NPHY_PucchOccLen; \
    enum NRRC_NPHY_PucchSlotNum                 enNRRC_NPHY_PucchSlotNum; \
    enum NRRC_NPHY_PuschRateMatchMode           enNRRC_NPHY_PuschRateMatchMode; \
    enum NRRC_NPHY_PuschUciType                 enNRRC_NPHY_PuschUciType; \
    enum NRRC_NPHY_QclRsType                    enNRRC_NPHY_QclRsType; \
    enum NRRC_NPHY_QclType                      enNRRC_NPHY_QclType; \
    enum NRRC_NPHY_RateMatchPatternPeriod       enNRRC_NPHY_RateMatchPatternPeriod; \
    enum NRRC_NPHY_RateMatchPatternSlotNum      enNRRC_NPHY_RateMatchPatternSlotNum; \
    enum NRRC_NPHY_RateMatchPatternType         enNRRC_NPHY_RateMatchPatternType; \
    enum NRRC_NPHY_RbgSize                      enNRRC_NPHY_RbgSize; \
    enum NRRC_NPHY_ResAllocType                 enNRRC_NPHY_ResAllocType; \
    enum NRRC_NPHY_ScheType                     enNRRC_NPHY_ScheType; \
    enum NRRC_NPHY_SearchSpaceCandiPdcNum       enNRRC_NPHY_SearchSpaceCandiPdcNum; \
    enum NRRC_NPHY_SearchSpacePeriod            enNRRC_NPHY_SearchSpacePeriod; \
    enum NRRC_NPHY_SearchSpaceType              enNRRC_NPHY_SearchSpaceType; \
    enum NRRC_NPHY_SptlRelationType             enNRRC_NPHY_SptlRelationType; \
    enum NRRC_NPHY_PuschCodebookSubset          enNRRC_NPHY_PuschCodebookSubset; \
    enum NRRC_NPHY_SrsHoppingType               enNRRC_NPHY_SrsHoppingType; \
    enum NRRC_NPHY_SrsMonitorPeriod             enNRRC_NPHY_SrsMonitorPeriod; \
    enum NRRC_NPHY_SrsPeriod                    enNRRC_NPHY_SrsPeriod; \
    enum NRRC_NPHY_SrsPortsNum                  enNRRC_NPHY_SrsPortsNum; \
    enum NRRC_NPHY_SrsPowerCtrlAdjStates        enNRRC_NPHY_SrsPowerCtrlAdjStates; \
    enum NRRC_NPHY_SrsResRepFactor              enNRRC_NPHY_SrsResRepFactor; \
    enum NRRC_NPHY_SrsResSymbolsNum             enNRRC_NPHY_SrsResSymbolsNum; \
    enum NRRC_NPHY_SrsTpcPdcchGroupType         enNRRC_NPHY_SrsTpcPdcchGroupType; \
    enum NRRC_NPHY_SrsTransComb                 enNRRC_NPHY_SrsTransComb; \
    enum NRRC_NPHY_UlTxConfig                   enNRRC_NPHY_UlTxConfig; \
    enum NRRC_NPHY_SrsUsage                     enNRRC_NPHY_SrsUsage; \
    enum PS_SrPeriod                     enNRRC_NPHY_SrPeriod; \
    enum PS_SsbPeriod                    enPS_SsbPeriod; \
    enum NRRC_NPHY_SsbPosInBurst                enNRRC_NPHY_SsbPosInBurst; \
    enum NRRC_NPHY_TddUlDlTransPeriod           enNRRC_NPHY_TddUlDlTransPeriod; \
    enum NRRC_NPHY_UlPtrsDtfTimeDensity         enNRRC_NPHY_UlPtrsDtfTimeDensity; \
    enum NRRC_NPHY_UlPtrsPower                  enNRRC_NPHY_UlPtrsPower; \
    enum NRRC_NPHY_UlCfgGrantPeriod             enNRRC_NPHY_UlCfgGrantPeriod; \
    enum NRRC_NPHY_UlCfgGrantRepK               enNRRC_NPHY_UlCfgGrantRepK; \
    enum NRRC_NPHY_UlCfgGrantRepRv              enNRRC_NPHY_UlCfgGrantRepRv; \
    enum NRRC_NPHY_VrbToPrbInterleaver          enNRRC_NPHY_VrbToPrbInterleaver; \
    enum NRRC_NPHY_BgSrchPrio                   enNRRC_NPHY_BgSrchPrio; \
    enum NRRC_NPHY_MeasSlotPeriod               enNRRC_NPHY_MeasSlotPeriod; \
    enum NRRC_NPHY_BgscfgType                   enNRRC_NPHY_BgscfgType; \
    enum NRRC_NPHY_CsiMeasurePrbSize            enNRRC_NPHY_CsiMeasurePrbSize; \
    enum NRRC_NPHY_NetDeployMode                enNRRC_NPHY_NetDeployMode; \
    enum NRRC_NPHY_ParaIndicate                 enNRRC_NPHY_ParaIndicate; \
    enum NRRC_NPHY_BmpType                      enNRRC_NPHY_BmpType; \
    enum PS_SsbDuration                         enPS_SsbDuration; \
    enum NRRC_NPHY_CsiMeasureDensity            enNRRC_NPHY_CsiMeasureDensity; \
    enum NRRC_NPHY_Bool                         enNRRC_NPHY_Bool; \
    enum NRRC_NPHY_ParaEnable                   enNRRC_NPHY_ParaEnable; \
    enum NRRC_NPHY_Result                       enNRRC_NPHY_Result; \
    enum NRRC_NPHY_BeamType                     enNRRC_NPHY_BeamType; \
    enum NRRC_NPHY_MeasFreqChangeType           enNRRC_NPHY_MeasFreqChangeType; \
    enum NRRC_NPHY_RatType                      enNRRC_NPHY_RatType; \
    enum PS_ModeType                            enPS_ModeType; \
    enum NRRC_NPHY_CellSearchType               enNRRC_NPHY_CellSearchType; \
    enum NRRC_NPHY_SearchCellResult             enNRRC_NPHY_SearchCellResult; \
    enum NRRC_NPHY_PdschBchSetupFlag            enNRRC_NPHY_PdschBchSetupFlag; \
    enum NRRC_NPHY_SiWindow                     enNRRC_NPHY_SiWindow; \
    enum NRRC_NPHY_SiPeriod                     enNRRC_NPHY_SiPeriod; \
    enum NRRC_NPHY_PuschHoppingMode             enNRRC_NPHY_PuschHoppingMode; \
    enum NRRC_NPHY_AntannaPort                  enNRRC_NPHY_AntannaPort; \
    enum NRRC_NPHY_ParaValid                    enNRRC_NPHY_ParaValid; \
    enum NRRC_NPHY_WorkModeType                 enNRRC_NPHY_WorkModeType; \
    enum NRRC_NPHY_SetWorkModeReason            enNRRC_NPHY_SetWorkModeReason; \
    enum PS_ScsType                             enPS_ScsType; \
    enum PS_CpType                              enPS_CpType; \
    enum PS_CellType                            enPS_CellType; \
    enum NRRC_NPHY_UeSpecChType                 enNRRC_NPHY_UeSpecChType; \
    enum NRRC_NPHY_CoresetRegBundleSize         enNRRC_NPHY_CoresetRegBundleSize; \
    enum NRRC_NPHY_DmrsType                     enNRRC_NPHY_DmrsType; \
    enum NRRC_NPHY_CsiRsDensity                 enNRRC_NPHY_CsiRsDensity; \
    enum NRRC_NPHY_CsiRptType                   enNRRC_NPHY_CsiRptType; \
    enum NRRC_NPHY_CsiCodebookType              enNRRC_NPHY_CsiCodebookType; \
    enum NRRC_NPHY_PucchFormat                  enNRRC_NPHY_PucchFormat; \
    enum NRRC_NPHY_SrsResType                   enNRRC_NPHY_SrsResType; \
    enum NRRC_NPHY_ErrType                      enNRRC_NPHY_ErrType; \
    enum NRRC_NPHY_SyncType                     enNRRC_NPHY_SyncType; \
    enum NRRC_NPHY_TargetState                  enNRRC_NPHY_TargetState; \
    enum NRRC_NPHY_DpdtSwitch                   enNRRC_NPHY_DpdtSwitch; \
    enum NRRC_NPHY_DsdsRfshared                 enNRRC_NPHY_DsdsRfshared; \
    enum NRRC_NPHY_MeasCycleScell               enNRRC_NPHY_MeasCycleScell; \
    enum NRRC_NPHY_MonitorOccasionType          enNRRC_NPHY_MonitorOccasionType; \
    enum NRRC_NPHY_MeasSourceType               enNRRC_NPHY_MeasSourceType; \
    enum NRRC_NPHY_MeasCellType                 enNRRC_NPHY_MeasCellType; \
    enum NRRC_NPHY_ScgCfgPscellScene            enNRRC_NPHY_ScgCfgPscellScene; \
    enum NRRC_NPHY_SmtcTimingRefer              enNRRC_NPHY_SmtcTimingRefer; \
    enum NRRC_NPHY_XscaleType                   enNRRC_NPHY_XscaleType; \
    enum NPHY_NRRC_MrDcSyncType                 enNPHY_NRRC_MrDcSyncType; \
    enum NRRC_NPHY_SwitchIndType                enNRRC_NPHY_SwitchIndType; \
    enum NRRC_NPHY_TrxTasCmd                    enNRRC_NPHY_TrxTasCmd; \
    enum NRRC_NPHY_DbrDrxCycleLen               enNRRC_NPHY_DbrDrxCycleLen; \
    enum NRRC_NPHY_CgiAcquisitionMethod         enNRRC_NPHY_CgiAcquisitionMethod; \
    enum NRRC_NPHY_PhrModeOtherCg               enNRRC_NPHY_PhrModeOtherCg; \
    enum NRRC_NPHY_SensorStatSupport            enNRRC_NPHY_SensorStatSupport; \
    enum NRRC_NPHY_RefServCellInd               enNRRC_NPHY_RefServCellInd; \
    enum NRRC_NPHY_BeamLockTestType             enNRRC_NPHY_BeamLockTestType; \
    enum NRRC_NPHY_BeamLockTestRange            enNRRC_NPHY_BeamLockTestRange; \
    enum NRRC_NPHY_ScgRelType                   enNRRC_NPHY_ScgRelType; \
    NRRC_NPHY_PhrCfg                            stNRRC_NPHY_PhrCfg; \
    NRRC_NPHY_CgParaCfg                         stNRRC_NPHY_CgParaCfg; \
    NRRC_NPHY_CcAddr                            stNRRC_NPHY_CcAddr; \
    NRRC_NPHY_CgAddr                            stNRRC_NPHY_CgAddr; \
    NRRC_NPHY_BfrCbdRsInfo                      stNRRC_NPHY_BfrCbdRsInfo; \
    NRRC_NPHY_ScanSsbFreqInfo                   stNRRC_NPHY_ScanSsbFreqInfo; \
    NRRC_NPHY_SfiDciPerCc                       stNRRC_NPHY_SfiDciPerCc; \
    NRRC_NPHY_TpcSrsCfg                         stNRRC_NPHY_TpcSrsCfg; \
    NRRC_NPHY_DrxOnDurationTimerSubms           stNRRC_NPHY_DrxOnDurationTimerSubms; \
    NRRC_NPHY_CsiRptPucchResCfg                 stNRRC_NPHY_CsiRptPucchResCfg; \
    NRRC_NPHY_DefaultParaCfg                    stNRRC_NPHY_DefaultParaCfg; \
    NRRC_NPHY_DlPreemptIntPos                   stNRRC_NPHY_DlPreemptIntPos; \
    NRRC_NPHY_PucchResourceFormat0              stNRRC_NPHY_PucchResourceFormat0; \
    NRRC_NPHY_PucchResourceFormat1              stNRRC_NPHY_PucchResourceFormat1; \
    NRRC_NPHY_PucchResourceFormat2              stNRRC_NPHY_PucchResourceFormat2; \
    NRRC_NPHY_PucchResourceFormat3              stNRRC_NPHY_PucchResourceFormat3; \
    NRRC_NPHY_ScheTypeOtherCfg                  stNRRC_NPHY_ScheTypeOtherCfg; \
    NRRC_NPHY_SlotSpecCfg                       stNRRC_NPHY_SlotSpecCfg; \
    NRRC_NPHY_SrsFreqHoppingCfg                 stNRRC_NPHY_SrsFreqHoppingCfg; \
    NRRC_NPHY_SrsTpcCcSetIndex                  stNRRC_NPHY_SrsTpcCcSetIndex; \
    NRRC_NPHY_UciBetaOffsetCfg                  stNRRC_NPHY_UciBetaOffsetCfg; \
    NRRC_NPHY_MeasSfPatternCfgNeigh             stNRRC_NPHY_MeasSfPatternCfgNeigh; \
    NRRC_NPHY_IdleIratInfo                      stNRRC_NPHY_IdleIratInfo; \
    NRRC_NPHY_ConnIratInfo                      stNRRC_NPHY_ConnIratInfo; \
    NRRC_NPHY_MeasScalFactor                    stNRRC_NPHY_MeasScalFactor; \
    NRRC_NPHY_FreqBandInfo                      stNRRC_NPHY_FreqBandInfo; \
    NRRC_NPHY_CandidateCellList                 stNRRC_NPHY_CandidateCellList; \
    NRRC_NPHY_ScanSsbFreqInfoList               stNRRC_NPHY_ScanSsbFreqInfoList; \
    NRRC_NPHY_GapSharing                        stNRRC_NPHY_GapSharing; \
    NRRC_NPHY_MeasSlotCfg                       stNRRC_NPHY_MeasSlotCfg; \
    NRRC_NPHY_FirstMonitorOccasionPerPo         stNRRC_NPHY_FirstMonitorOccasionPerPo; \
    NRRC_NPHY_PcchCfgInfo                       stNRRC_NPHY_PcchCfgInfo; \
    NRRC_NPHY_SfiDciCfg                         stNRRC_NPHY_SfiDciCfg; \
    NRRC_NPHY_TddUlDlCfgCommPattern             stNRRC_NPHY_TddUlDlCfgCommPattern; \
    NRRC_NPHY_CsiCbType1MulPanCbRstrct          stNRRC_NPHY_CsiCbType1MulPanCbRstrct; \
    NRRC_NPHY_CsiCbType1SinPanCbRstrct          stNRRC_NPHY_CsiCbType1SinPanCbRstrct; \
    NRRC_NPHY_CsiCbType2NoPortSelCbRstrct       stNRRC_NPHY_CsiCbType2NoPortSelCbRstrct; \
    NRRC_NPHY_DlPtrsEprePort2                   stNRRC_NPHY_DlPtrsEprePort2; \
    NRRC_NPHY_GapCfg                            stNRRC_NPHY_GapCfg; \
    NRRC_NPHY_PucchResSetXCfg                   stNRRC_NPHY_PucchResSetXCfg; \
    NRRC_NPHY_RateMatchPatternPatternCfg        stNRRC_NPHY_RateMatchPatternPatternCfg; \
    NRRC_NPHY_BeamFailRecoveryCfg               stNRRC_NPHY_BeamFailRecoveryCfg; \
    NRRC_NPHY_CsiApAssociatRptCfg               stNRRC_NPHY_CsiApAssociatRptCfg; \
    NRRC_NPHY_CsiCbType2PortSelCfg              stNRRC_NPHY_CsiCbType2PortSelCfg; \
    NRRC_NPHY_CsiRptPortIdx2Cfg                 stNRRC_NPHY_CsiRptPortIdx2Cfg; \
    NRRC_NPHY_CsiRptPortIdx4Cfg                 stNRRC_NPHY_CsiRptPortIdx4Cfg; \
    NRRC_NPHY_CsiRsResSetZpCfg                  stNRRC_NPHY_CsiRsResSetZpCfg; \
    NRRC_NPHY_CsiRsResTimePeriodCfg             stNRRC_NPHY_CsiRsResTimePeriodCfg; \
    NRRC_NPHY_DciFmt23Cfg                       stNRRC_NPHY_DciFmt23Cfg; \
    NRRC_NPHY_ImResSetLst                       stNRRC_NPHY_ImResSetLst; \
    NRRC_NPHY_NzpSsbResSetLst                   stNRRC_NPHY_NzpSsbResSetLst; \
    NRRC_NPHY_PdschBundleDynamicCfg             stNRRC_NPHY_PdschBundleDynamicCfg; \
    NRRC_NPHY_PdschBundleStaticCfg              stNRRC_NPHY_PdschBundleStaticCfg; \
    NRRC_NPHY_PdschCfgPerCc                     stNRRC_NPHY_PdschCfgPerCc; \
    NRRC_NPHY_PuschCfgPerCc                     stNRRC_NPHY_PuschCfgPerCc; \
    NRRC_NPHY_RateMatchGrp                      stNRRC_NPHY_RateMatchGrp; \
    NRRC_NPHY_SearchSpaceCandiNumCfg            stNRRC_NPHY_SearchSpaceCandiNumCfg; \
    NRRC_NPHY_SriPuschMappingCfg                stNRRC_NPHY_SriPuschMappingCfg; \
    NRRC_NPHY_SrsAssociatApCfg                  stNRRC_NPHY_SrsAssociatApCfg; \
    NRRC_NPHY_SrsAssociatSpPCfg                 stNRRC_NPHY_SrsAssociatSpPCfg; \
    NRRC_NPHY_SrsSptlRelationInfo               stNRRC_NPHY_SrsSptlRelationInfo; \
    NRRC_NPHY_TpcPuschCfg                       stNRRC_NPHY_TpcPuschCfg; \
    NRRC_NPHY_TpcPucchCfg                       stNRRC_NPHY_TpcPucchCfg; \
    NRRC_NPHY_DrxOnDurationTimerMs              stNRRC_NPHY_DrxOnDurationTimerMs; \
    NRRC_NPHY_RlMonitorRes                      stNRRC_NPHY_RlMonitorRes; \
    NRRC_NPHY_CoresetInterleave                 stNRRC_NPHY_CoresetInterleave; \
    NRRC_NPHY_PdschScheTiming                   stNRRC_NPHY_PdschScheTiming; \
    NRRC_NPHY_PuschScheTiming                   stNRRC_NPHY_PuschScheTiming; \
    NRRC_NPHY_CgCfg                             stNRRC_NPHY_CgCfg; \
    NRRC_NPHY_CsiRptAperiodTimingCfg            stNRRC_NPHY_CsiRptAperiodTimingCfg; \
    NRRC_NPHY_CsiRptFreqCfg                     stNRRC_NPHY_CsiRptFreqCfg; \
    NRRC_NPHY_CsiRptPeriodTimingCfg             stNRRC_NPHY_CsiRptPeriodTimingCfg; \
    NRRC_NPHY_CsiRptQuantityTypeCriRiI1Cqi      stNRRC_NPHY_CsiRptQuantityTypeCriRiI1Cqi; \
    NRRC_NPHY_CsiRptSemiperPucchTimingCfg       stNRRC_NPHY_CsiRptSemiperPucchTimingCfg; \
    NRRC_NPHY_CsiRptSemiperPuschTimingCfg       stNRRC_NPHY_CsiRptSemiperPuschTimingCfg; \
    NRRC_NPHY_CsiRptTriggerSpCfg                stNRRC_NPHY_CsiRptTriggerSpCfg; \
    NRRC_NPHY_CsiRsResMappingCfg                stNRRC_NPHY_CsiRsResMappingCfg; \
    NRRC_NPHY_CsiSsbResSetCfg                   stNRRC_NPHY_CsiSsbResSetCfg; \
    NRRC_NPHY_DlPreemptIndCfg                   stNRRC_NPHY_DlPreemptIndCfg; \
    NRRC_NPHY_DlPtrsCfg                         stNRRC_NPHY_DlPtrsCfg; \
    NRRC_NPHY_CsiImResSetCfg                    stNRRC_NPHY_CsiImResSetCfg; \
    NRRC_NPHY_LteMbsfnSubframeInfo              stNRRC_NPHY_LteMbsfnSubframeInfo; \
    NRRC_NPHY_NzpCsiResSetCfg                   stNRRC_NPHY_NzpCsiResSetCfg; \
    NRRC_NPHY_PdcchTciState                     stNRRC_NPHY_PdcchTciState; \
    NRRC_NPHY_PlRefRsInfo                       stNRRC_NPHY_PlRefRsInfo; \
    NRRC_NPHY_PucchFormat1Cfg                   stNRRC_NPHY_PucchFormat1Cfg; \
    NRRC_NPHY_PucchFormat2Cfg                   stNRRC_NPHY_PucchFormat2Cfg; \
    NRRC_NPHY_PucchFormat34Cfg                  stNRRC_NPHY_PucchFormat34Cfg; \
    NRRC_NPHY_PucchP0Cfg                        stNRRC_NPHY_PucchP0Cfg; \
    NRRC_NPHY_PucchResourceFormat4              stNRRC_NPHY_PucchResourceFormat4; \
    NRRC_NPHY_PucchResSet0Cfg                   stNRRC_NPHY_PucchResSet0Cfg; \
    NRRC_NPHY_PuschDmrsCpOfdm                   stNRRC_NPHY_PuschDmrsCpOfdm; \
    NRRC_NPHY_PuschDmrsDftSOfdm                 stNRRC_NPHY_PuschDmrsDftSOfdm; \
    NRRC_NPHY_PuschHoppingOffsetLst             stNRRC_NPHY_PuschHoppingOffsetLst; \
    NRRC_NPHY_PuschP0AlphaSet                   stNRRC_NPHY_PuschP0AlphaSet; \
    NRRC_NPHY_QclTypeCfg                        stNRRC_NPHY_QclTypeCfg; \
    NRRC_NPHY_RachCfgComm                       stNRRC_NPHY_RachCfgComm; \
    NRRC_NPHY_ScheTypeOwnCfg                    stNRRC_NPHY_ScheTypeOwnCfg; \
    NRRC_NPHY_ScsSpecCarrCfg                    stNRRC_NPHY_ScsSpecCarrCfg; \
    NRRC_NPHY_SearchSpaceUeTypeCfg              stNRRC_NPHY_SearchSpaceUeTypeCfg; \
    NRRC_NPHY_SlotFormatCombineCfg              stNRRC_NPHY_SlotFormatCombineCfg; \
    NRRC_NPHY_SptlRelationInfo                  stNRRC_NPHY_SptlRelationInfo; \
    NRRC_NPHY_SrsResMappingCfg                  stNRRC_NPHY_SrsResMappingCfg; \
    NRRC_NPHY_SrsTpcPdcchCfg                    stNRRC_NPHY_SrsTpcPdcchCfg; \
    NRRC_NPHY_SrResourceCfg                     stNRRC_NPHY_SrResourceCfg; \
    NRRC_NPHY_SsbCfgComm                        stNRRC_NPHY_SsbCfgComm; \
    NRRC_NPHY_TddUlDlCfgDedi                    stNRRC_NPHY_TddUlDlCfgDedi; \
    NRRC_NPHY_TimingDlDataToUlAck               stNRRC_NPHY_TimingDlDataToUlAck; \
    NRRC_NPHY_UciOnPusch                        stNRRC_NPHY_UciOnPusch; \
    NRRC_NPHY_UlPtrsCfgCpOfdm                   stNRRC_NPHY_UlPtrsCfgCpOfdm; \
    NRRC_NPHY_UlPtrsCfgDftSOfdm                 stNRRC_NPHY_UlPtrsCfgDftSOfdm; \
    NRRC_NPHY_UlConfigredGrantType1Cfg          stNRRC_NPHY_UlConfigredGrantType1Cfg; \
    NRRC_NPHY_Type0aSearchSpacePara             stNRRC_NPHY_Type0aSearchSpacePara; \
    NRRC_NPHY_SingleFreqInfo                    stNRRC_NPHY_SingleFreqInfo; \
    NRRC_NPHY_SsbMeasured                       stNRRC_NPHY_SsbMeasured; \
    NRRC_NPHY_Smtc1                             stNRRC_NPHY_Smtc1; \
    NRRC_NPHY_ScellInfo                         stNRRC_NPHY_ScellInfo; \
    NRRC_NPHY_Smtc2                             stNRRC_NPHY_Smtc2; \
    NRRC_NPHY_CsiMeasureBandWidth               stNRRC_NPHY_CsiMeasureBandWidth; \
    NRRC_NPHY_CsiMeasSlotConfig                 stNRRC_NPHY_CsiMeasSlotConfig; \
    NRRC_NPHY_UtranCarrierMeasParam             stNRRC_NPHY_UtranCarrierMeasParam; \
    NRRC_NPHY_ConnCommMeasInfo                  stNRRC_NPHY_ConnCommMeasInfo; \
    NRRC_NPHY_FreqRssiMeasInfo                  stNRRC_NPHY_FreqRssiMeasInfo; \
    NRRC_NPHY_SiConfigItem                      stNRRC_NPHY_SiConfigItem; \
    NRRC_NPHY_CommPucchPara                     stNRRC_NPHY_CommPucchPara; \
    NRRC_NPHY_RlfParaInfo                       stNRRC_NPHY_RlfParaInfo; \
    NRRC_NPHY_BasicCellInfo                     stNRRC_NPHY_BasicCellInfo; \
    NRRC_NPHY_CcCommInfo                        stNRRC_NPHY_CcCommInfo; \
    NRRC_NPHY_SrsPwrDediPara                    stNRRC_NPHY_SrsPwrDediPara; \
    NRRC_NPHY_SyncPara                          stNRRC_NPHY_SyncPara; \
    NRRC_NPHY_BwpInfoComm                       stNRRC_NPHY_BwpInfoComm; \
    NRRC_NPHY_PdschDlSpsPara                    stNRRC_NPHY_PdschDlSpsPara; \
    NRRC_NPHY_BandScanSsbFreqInfoRslt           stNRRC_NPHY_BandScanSsbFreqInfoRslt; \
    NRRC_NPHY_PdcchCfgForUl                     stNRRC_NPHY_PdcchCfgForUl; \
    NRRC_NPHY_CcDlSibInfo                       stNRRC_NPHY_CcDlSibInfo; \
    NRRC_NPHY_CsiResCfgType                     stNRRC_NPHY_CsiResCfgType; \
    NRRC_NPHY_CsiRptPortIdxCfg                  stNRRC_NPHY_CsiRptPortIdxCfg; \
    NRRC_NPHY_CsiRptTypeCfg                     stNRRC_NPHY_CsiRptTypeCfg; \
    NRRC_NPHY_DrxOnDurationTimer                stNRRC_NPHY_DrxOnDurationTimer; \
    NRRC_NPHY_PdschBundleTypeCfg                stNRRC_NPHY_PdschBundleTypeCfg; \
    NRRC_NPHY_PucchFormatTypeCfg                stNRRC_NPHY_PucchFormatTypeCfg; \
    NRRC_NPHY_ScheTypeCfg                       stNRRC_NPHY_ScheTypeCfg; \
    NRRC_NPHY_SrsResSetTypeCfg                  stNRRC_NPHY_SrsResSetTypeCfg; \
    NRRC_NPHY_SsRssiMeasCfg                     stNRRC_NPHY_SsRssiMeasCfg; \
    NRRC_NPHY_BeamFailRecoveryCfgPerUl          stNRRC_NPHY_BeamFailRecoveryCfgPerUl; \
    NRRC_NPHY_CsiApTrigStateCfg                 stNRRC_NPHY_CsiApTrigStateCfg; \
    NRRC_NPHY_CsiCbType1MulPanelCfg             stNRRC_NPHY_CsiCbType1MulPanelCfg; \
    NRRC_NPHY_CsiCbType2NoPortSelCfg            stNRRC_NPHY_CsiCbType2NoPortSelCfg; \
    NRRC_NPHY_CsiRptCbType1MoreAntCfg           stNRRC_NPHY_CsiRptCbType1MoreAntCfg; \
    NRRC_NPHY_DciFmt20Cfg                       stNRRC_NPHY_DciFmt20Cfg; \
    NRRC_NPHY_SriPuschPwrCtrlCfg                stNRRC_NPHY_SriPuschPwrCtrlCfg; \
    NRRC_NPHY_RlMonitorCfg                      stNRRC_NPHY_RlMonitorCfg; \
    NRRC_NPHY_CellToSfiCfg                      stNRRC_NPHY_CellToSfiCfg; \
    NRRC_NPHY_CsiImResCfg                       stNRRC_NPHY_CsiImResCfg; \
    NRRC_NPHY_CsiRptQuantityCfg                 stNRRC_NPHY_CsiRptQuantityCfg; \
    NRRC_NPHY_NzpCsiRsResCfg                    stNRRC_NPHY_NzpCsiRsResCfg; \
    NRRC_NPHY_CsiRsResZpCfg                     stNRRC_NPHY_CsiRsResZpCfg; \
    NRRC_NPHY_CtrlResSetCfg                     stNRRC_NPHY_CtrlResSetCfg; \
    NRRC_NPHY_LteMbsfnSubframeCfg               stNRRC_NPHY_LteMbsfnSubframeCfg; \
    NRRC_NPHY_PdschDmrsCfg                      stNRRC_NPHY_PdschDmrsCfg; \
    NRRC_NPHY_PlRefRsCfg                        stNRRC_NPHY_PlRefRsCfg; \
    NRRC_NPHY_PucchSptlRelationCfg              stNRRC_NPHY_PucchSptlRelationCfg; \
    NRRC_NPHY_PuschP0AlphaCfg                   stNRRC_NPHY_PuschP0AlphaCfg; \
    NRRC_NPHY_RateMatchPatternBitmap            stNRRC_NPHY_RateMatchPatternBitmap; \
    NRRC_NPHY_SrsResCfg                         stNRRC_NPHY_SrsResCfg; \
    NRRC_NPHY_SrsTpcPdcchGroupCfg               stNRRC_NPHY_SrsTpcPdcchGroupCfg; \
    NRRC_NPHY_TciRsSetCfg                       stNRRC_NPHY_TciRsSetCfg; \
    NRRC_NPHY_TddUlDlCfgComm                    stNRRC_NPHY_TddUlDlCfgComm; \
    NRRC_NPHY_PdschTimeDomainResAlloc           stNRRC_NPHY_PdschTimeDomainResAlloc; \
    NRRC_NPHY_PuschTimeDomainResAlloc           stNRRC_NPHY_PuschTimeDomainResAlloc; \
    NRRC_NPHY_SmtcConfig                        stNRRC_NPHY_SmtcConfig; \
    NRRC_NPHY_ConnMeasGapInfo                   stNRRC_NPHY_ConnMeasGapInfo; \
    NRRC_NPHY_CandidateCellInfoList             stNRRC_NPHY_CandidateCellInfoList; \
    NRRC_NPHY_CcDlInfo                          stNRRC_NPHY_CcDlInfo; \
    NRRC_NPHY_CcUlInfo                          stNRRC_NPHY_CcUlInfo; \
    NRRC_NPHY_IratRsSsbCfg                      stNRRC_NPHY_IratRsSsbCfg; \
    NRRC_NPHY_CsiCodebookType2SubTypeCfg        stNRRC_NPHY_CsiCodebookType2SubTypeCfg; \
    NRRC_NPHY_CsiRptCbType1AntPortCfg           stNRRC_NPHY_CsiRptCbType1AntPortCfg; \
    NRRC_NPHY_PdschCfgForUl                     stNRRC_NPHY_PdschCfgForUl; \
    NRRC_NPHY_RateMatchPatternTypeCfg           stNRRC_NPHY_RateMatchPatternTypeCfg; \
    NRRC_NPHY_CommPdschPara                     stNRRC_NPHY_CommPdschPara; \
    NRRC_NPHY_CsiRptPortCfg                     stNRRC_NPHY_CsiRptPortCfg; \
    NRRC_NPHY_PdschBundleCfg                    stNRRC_NPHY_PdschBundleCfg; \
    NRRC_NPHY_RlMonitorCfgPerDl                 stNRRC_NPHY_RlMonitorCfgPerDl; \
    NRRC_NPHY_SrsAssociatCfg                    stNRRC_NPHY_SrsAssociatCfg; \
    NRRC_NPHY_CommRlCfgPerCcComm                stNRRC_NPHY_CommRlCfgPerCcComm; \
    NRRC_NPHY_CrossCarrierSche                  stNRRC_NPHY_CrossCarrierSche; \
    NRRC_NPHY_CsiResCfg                         stNRRC_NPHY_CsiResCfg; \
    NRRC_NPHY_CsiRptTriggerApCfg                stNRRC_NPHY_CsiRptTriggerApCfg; \
    NRRC_NPHY_CsiRsResZpCfgLst                  stNRRC_NPHY_CsiRsResZpCfgLst; \
    NRRC_NPHY_PucchResourceCfg                  stNRRC_NPHY_PucchResourceCfg; \
    NRRC_NPHY_RateMatchLteCrsMatch              stNRRC_NPHY_RateMatchLteCrsMatch; \
    NRRC_NPHY_SearchSpaceCommTypeCfg            stNRRC_NPHY_SearchSpaceCommTypeCfg; \
    NRRC_NPHY_SlotFormatIndCfg                  stNRRC_NPHY_SlotFormatIndCfg; \
    NRRC_NPHY_PdcchCfgPerCc                     stNRRC_NPHY_PdcchCfgPerCc; \
    NRRC_NPHY_SrsCarrSwitchCfg                  stNRRC_NPHY_SrsCarrSwitchCfg; \
    NRRC_NPHY_TciStatesCfg                      stNRRC_NPHY_TciStatesCfg; \
    NRRC_NPHY_UlPtrsCfg                         stNRRC_NPHY_UlPtrsCfg; \
    NRRC_NPHY_ConnMeasSsbConfig                 stNRRC_NPHY_ConnMeasSsbConfig; \
    NRRC_NPHY_CommPuschPara                     stNRRC_NPHY_CommPuschPara; \
    NRRC_NPHY_CdrxInfo                          stNRRC_NPHY_CdrxInfo; \
    NRRC_NPHY_PucchPwrDediPara                  stNRRC_NPHY_PucchPwrDediPara; \
    NRRC_NPHY_PuschPwrDediPara                  stNRRC_NPHY_PuschPwrDediPara; \
    NRRC_NPHY_CcStatus                          stNRRC_NPHY_CcStatus; \
    NRRC_NPHY_CcCfg                             stNRRC_NPHY_CcCfg; \
    NRRC_NPHY_CellInfo                          stNRRC_NPHY_CellInfo; \
    NRRC_NPHY_DlInfoForUlPerBwpCfg              stNRRC_NPHY_DlInfoForUlPerBwpCfg; \
    NRRC_NPHY_SearchSpaceTypeCfg                stNRRC_NPHY_SearchSpaceTypeCfg; \
    NRRC_NPHY_BeamFailCfgPerCc                  stNRRC_NPHY_BeamFailCfgPerCc; \
    NRRC_NPHY_BeamFailCfgPerCcFusion            stNRRC_NPHY_BeamFailCfgPerCcFusion; \
    NRRC_NPHY_CsiCbType1SinglePanelCfg          stNRRC_NPHY_CsiCbType1SinglePanelCfg; \
    NRRC_NPHY_CsiRptPortCfgLst                  stNRRC_NPHY_CsiRptPortCfgLst; \
    NRRC_NPHY_CommRlCfgPerCcUl                  stNRRC_NPHY_CommRlCfgPerCcUl; \
    NRRC_NPHY_CsiCodebookType2Cfg               stNRRC_NPHY_CsiCodebookType2Cfg; \
    NRRC_NPHY_CsiResCfgPerCc                    stNRRC_NPHY_CsiResCfgPerCc; \
    NRRC_NPHY_CsiRptTriggerCfg                  stNRRC_NPHY_CsiRptTriggerCfg; \
    NRRC_NPHY_DediRlCfgPerCcComm                stNRRC_NPHY_DediRlCfgPerCcComm; \
    NRRC_NPHY_PuschDmrsCfg                      stNRRC_NPHY_PuschDmrsCfg; \
    NRRC_NPHY_RateMatchPattern                  stNRRC_NPHY_RateMatchPattern; \
    NRRC_NPHY_SrsResSetCfg                      stNRRC_NPHY_SrsResSetCfg; \
    NRRC_NPHY_SftdMeasInfo                      stNRRC_NPHY_SftdMeasInfo; \
    NRRC_NPHY_ConnSingleFreqCellInfo            stNRRC_NPHY_ConnSingleFreqCellInfo; \
    NRRC_NPHY_ConnPcellInfo                     stNRRC_NPHY_ConnPcellInfo; \
    NRRC_NPHY_ConnPscellInfo                    stNRRC_NPHY_ConnPscellInfo; \
    NRRC_NPHY_CgCdrxInfo                        stNRRC_NPHY_CgCdrxInfo; \
    NRRC_NPHY_PucchDediPara                     stNRRC_NPHY_PucchDediPara; \
    NRRC_NPHY_CsiCodebookType1SubtypeCfg        stNRRC_NPHY_CsiCodebookType1SubtypeCfg; \
    NRRC_NPHY_DediDlInfoForUl                   stNRRC_NPHY_DediDlInfoForUl; \
    NPHY_COMM_SrsBwpCfg                         stNPHY_COMM_SrsBwpCfg; \
    NRRC_NPHY_RateMatchResPdsch                 stNRRC_NPHY_RateMatchResPdsch; \
    NRRC_NPHY_SearchSpaceTypeSpecCfg            stNRRC_NPHY_SearchSpaceTypeSpecCfg; \
    NRRC_NPHY_IdleSingleFreqCellInfo            stNRRC_NPHY_IdleSingleFreqCellInfo; \
    NRRC_NPHY_IdlePcellInfo                     stNRRC_NPHY_IdlePcellInfo; \
    NRRC_NPHY_ConnInterFreqCellInfo             stNRRC_NPHY_ConnInterFreqCellInfo; \
    NRRC_NPHY_ConnSecondSingleFreqInfo          stNRRC_NPHY_ConnSecondSingleFreqInfo; \
    NRRC_NPHY_PuschConfigedGrant                stNRRC_NPHY_PuschConfigedGrant; \
    NRRC_NPHY_PuschDediPara                     stNRRC_NPHY_PuschDediPara; \
    NRRC_NPHY_UeSpecPucchPara                   stNRRC_NPHY_UeSpecPucchPara; \
    NRRC_NPHY_DediUlForUlPerUlBwp               stNRRC_NPHY_DediUlForUlPerUlBwp; \
    NRRC_NPHY_DediUlInfoForUlPerUl              stNRRC_NPHY_DediUlInfoForUlPerUl; \
    NRRC_NPHY_DediCgPerCcInfoForUl              stNRRC_NPHY_DediCgPerCcInfoForUl; \
    NRRC_NPHY_DediCgInfoForUl                   stNRRC_NPHY_DediCgInfoForUl; \
    NRRC_NPHY_CsiCodebookType1Cfg               stNRRC_NPHY_CsiCodebookType1Cfg; \
    NRRC_NPHY_SearchSpaceCfg                    stNRRC_NPHY_SearchSpaceCfg; \
    NRRC_NPHY_SrsCfgPerUl                       stNRRC_NPHY_SrsCfgPerUl; \
    NRRC_NPHY_IdleInterFreqCellInfo             stNRRC_NPHY_IdleInterFreqCellInfo; \
    NRRC_NPHY_ConnSecondFreqInfo                stNRRC_NPHY_ConnSecondFreqInfo; \
    NRRC_NPHY_PdschDediPara                     stNRRC_NPHY_PdschDediPara; \
    NRRC_NPHY_UeSpecPuschPara                   stNRRC_NPHY_UeSpecPuschPara; \
    NRRC_NPHY_CsiCodebookTypeCfg                stNRRC_NPHY_CsiCodebookTypeCfg; \
    NRRC_NPHY_UlBwpDediCfg                      stNRRC_NPHY_UlBwpDediCfg; \
    NRRC_NPHY_UlBwpCfg                          stNRRC_NPHY_UlBwpCfg; \
    NRRC_NPHY_SrsCfgPerCc                       stNRRC_NPHY_SrsCfgPerCc; \
    NRRC_NPHY_CommPdcchPara                     stNRRC_NPHY_CommPdcchPara; \
    NRRC_NPHY_UeSpecPdcchPara                   stNRRC_NPHY_UeSpecPdcchPara; \
    NRRC_NPHY_UeSpecPdschPara                   stNRRC_NPHY_UeSpecPdschPara; \
    NRRC_NPHY_DlBwpDediCfg                      stNRRC_NPHY_DlBwpDediCfg; \
    NRRC_NPHY_DlBwpCfg                          stNRRC_NPHY_DlBwpCfg; \
    NRRC_NPHY_CommRlCfgPerCcDl                  stNRRC_NPHY_CommRlCfgPerCcDl; \
    NRRC_NPHY_CsiRptCodebookCfg                 stNRRC_NPHY_CsiRptCodebookCfg; \
    NRRC_NPHY_DediRlCfgPerCcUl                  stNRRC_NPHY_DediRlCfgPerCcUl; \
    NRRC_NPHY_CsiRptCfg                         stNRRC_NPHY_CsiRptCfg; \
    NRRC_NPHY_DediRlCfgPerCcDl                  stNRRC_NPHY_DediRlCfgPerCcDl; \
    NRRC_NPHY_DediRlCfgPerCcDlFusion            stNRRC_NPHY_DediRlCfgPerCcDlFusion; \
    NRRC_NPHY_RadioResourceCommInfo             stNRRC_NPHY_RadioResourceCommInfo; \
    NRRC_NPHY_CsiRptCfgPerCc                    stNRRC_NPHY_CsiRptCfgPerCc; \
    NRRC_NPHY_DediRlCfgPerCc                    stNRRC_NPHY_DediRlCfgPerCc; \
    NRRC_NPHY_DediRlCfgPerCcFusion              stNRRC_NPHY_DediRlCfgPerCcFusion; \
    NRRC_NPHY_CcRadioResourceCommInfo           stNRRC_NPHY_CcRadioResourceCommInfo; \
    NRRC_NPHY_IdleMeasPcellSetupReq             stNRRC_NPHY_IdleMeasPcellSetupReq; \
    NRRC_NPHY_IdleMeasPcellIntraSetupReq        stNRRC_NPHY_IdleMeasPcellIntraSetupReq; \
    NRRC_NPHY_IdleMeasInterSetupReq             stNRRC_NPHY_IdleMeasInterSetupReq; \
    NRRC_NPHY_IdleMeasIratSetupReq              stNRRC_NPHY_IdleMeasIratSetupReq; \
    NRRC_NPHY_IdleMeasRelReq                    stNRRC_NPHY_IdleMeasRelReq; \
    NRRC_NPHY_ConnCommMeasConfigReq             stNRRC_NPHY_ConnCommMeasConfigReq; \
    NRRC_NPHY_ConnMeasGapConfigReq              stNRRC_NPHY_ConnMeasGapConfigReq; \
    NRRC_NPHY_ConnMeasIratSetupReq              stNRRC_NPHY_ConnMeasIratSetupReq; \
    NRRC_NPHY_ConnMeasPcellSetupReq             stNRRC_NPHY_ConnMeasPcellSetupReq; \
    NRRC_NPHY_ConnMeasPcellIntraSetupReq        stNRRC_NPHY_ConnMeasPcellIntraSetupReq; \
    NRRC_NPHY_ConnMeasInterSetupReq             stNRRC_NPHY_ConnMeasInterSetupReq; \
    NRRC_NPHY_ConnMeasPscellSetupReq            stNRRC_NPHY_ConnMeasPscellSetupReq; \
    NRRC_NPHY_ConnMeasPscellIntraSetupReq       stNRRC_NPHY_ConnMeasPscellIntraSetupReq; \
    NRRC_NPHY_ConnMeasSecondFreqSetupReq        stNRRC_NPHY_ConnMeasSecondFreqSetupReq; \
    NRRC_NPHY_ConnMeasRelReq                    stNRRC_NPHY_ConnMeasRelReq; \
    NRRC_NPHY_ConnMeasAnrStartReq               stNRRC_NPHY_ConnMeasAnrStartReq; \
    NRRC_NPHY_ConnMeasAnrStopReq                stNRRC_NPHY_ConnMeasAnrStopReq; \
    NRRC_NPHY_ConnMeasIratAnrStartReq           stNRRC_NPHY_ConnMeasIratAnrStartReq; \
    NRRC_NPHY_ConnMeasIratAnrStopReq            stNRRC_NPHY_ConnMeasIratAnrStopReq; \
    NRRC_NPHY_CellSearchingReq                  stNRRC_NPHY_CellSearchingReq; \
    NRRC_NPHY_PbchSetupReq                      stNRRC_NPHY_PbchSetupReq; \
    NRRC_NPHY_PdschBchSetupReq                  stNRRC_NPHY_PdschBchSetupReq; \
    NRRC_NPHY_FreqRssiScanReq                   stNRRC_NPHY_FreqRssiScanReq; \
    NRRC_NPHY_FreqRssiScanStopReq               stNRRC_NPHY_FreqRssiScanStopReq; \
    NRRC_NPHY_CampedMaincellReq                 stNRRC_NPHY_CampedMaincellReq; \
    NRRC_NPHY_PbchReleaseReq                    stNRRC_NPHY_PbchReleaseReq; \
    NRRC_NPHY_PdschBchReleaseReq                stNRRC_NPHY_PdschBchReleaseReq; \
    NRRC_NPHY_BgSearchStartReq                  stNRRC_NPHY_BgSearchStartReq; \
    NRRC_NPHY_BgSearchStopReq                   stNRRC_NPHY_BgSearchStopReq; \
    NRRC_NPHY_BgSearchSuspendReq                stNRRC_NPHY_BgSearchSuspendReq; \
    NRRC_NPHY_BgSearchResumeReq                 stNRRC_NPHY_BgSearchResumeReq; \
    NRRC_NPHY_SiConfigReq                       stNRRC_NPHY_SiConfigReq; \
    NRRC_NPHY_SiBitmapNtf                       stNRRC_NPHY_SiBitmapNtf; \
    NRRC_NPHY_PreResourceConfigReq              stNRRC_NPHY_PreResourceConfigReq; \
    NRRC_NPHY_SetWorkModeReq                    stNRRC_NPHY_SetWorkModeReq; \
    NRRC_NPHY_DrxConfigInConnectedReq           stNRRC_NPHY_DrxConfigInConnectedReq; \
    NRRC_NPHY_RelAllReq                         stNRRC_NPHY_RelAllReq; \
    NRRC_NPHY_ConnectedToIdleReq                stNRRC_NPHY_ConnectedToIdleReq; \
    NRRC_NPHY_ChangeToConnectedNtf              stNRRC_NPHY_ChangeToConnectedNtf; \
    NRRC_NPHY_SyncReq                           stNRRC_NPHY_SyncReq; \
    NRRC_NPHY_BandScanReq                       stNRRC_NPHY_BandScanReq; \
    NRRC_NPHY_DpdtCmdReq                        stNRRC_NPHY_DpdtCmdReq; \
    NRRC_NPHY_UlTxDirectCurBwpRptInfo           stNRRC_NPHY_UlTxDirectCurBwpRptInfo; \
    NRRC_NPHY_UlTxDirectCurCellRptInfo          stNRRC_NPHY_UlTxDirectCurCellRptInfo; \
    NRRC_NPHY_EndMsg                            stNRRC_NPHY_EndMsg; \
    NRRC_NPHY_WakeNtf                           stNRRC_NPHY_WakeNtf; \
    NRRC_NPHY_DsdsSuspendReq                    stNRRC_NPHY_DsdsSuspendReq; \
    NRRC_NPHY_DsdsResumeReq                     stNRRC_NPHY_DsdsResumeReq; \
    NRRC_NPHY_HifiSyncSwitchInd                 stNRRC_NPHY_HifiSyncSwitchInd; \
    NRRC_NPHY_PagingIdentityNtf                 stNRRC_NPHY_PagingIdentityNtf; \
    NRRC_NPHY_AntInfoReq                        stNRRC_NPHY_AntInfoReq; \
    NRRC_NPHY_SibTimeInfoNotify                 stNRRC_NPHY_SibTimeInfoNotify; \
    NRRC_NPHY_SibLeapTimeGetReq                 stNRRC_NPHY_SibLeapTimeGetReq; \
    NRRC_NPHY_DemandRachGeneric                 stNRRC_NPHY_DemandRachGeneric; \
    NRRC_NPHY_RachOccasionSi                    stNRRC_NPHY_RachOccasionSi; \
    NRRC_NPHY_SiReqReseource                    stNRRC_NPHY_SiReqReseource; \
    NRRC_NPHY_SiReqCfg                          stNRRC_NPHY_SiReqCfg; \
    NRRC_NPHY_DemandSiStartReq                  stNRRC_NPHY_DemandSiStartReq; \
    NRRC_NPHY_DemandSiStopReq                   stNRRC_NPHY_DemandSiStopReq; \
    NRRC_NPHY_SwitchInd                         stNRRC_NPHY_SwitchInd; \
    NRRC_NPHY_TrxTasCmdReq                      stNRRC_NPHY_TrxTasCmdReq; \
    NRRC_NPHY_DbrReportInd                      stNRRC_NPHY_DbrReportInd; \
    NRRC_NPHY_DrxCycleNtf                       stNRRC_NPHY_DrxCycleNtf; \
    NRRC_NPHY_DdrCfgReq                         stNRRC_NPHY_DdrCfgReq; \
    NRRC_NPHY_ArSensorStateNtf                  stNRRC_NPHY_ArSensorStateNtf; \
    NRRC_NPHY_ConcurrenceSearchBeginNtf         stNRRC_NPHY_ConcurrenceSearchBeginNtf; \
    NRRC_NPHY_ConcurrenceSearchEndNtf           stNRRC_NPHY_ConcurrenceSearchEndNtf; \
    NRRC_NPHY_BeamLockTestReq                   stNRRC_NPHY_BeamLockTestReq; \
    NRRC_NPHY_OsiParaConfigReq                  stNRRC_NPHY_OsiParaConfigReq; \
    NPHY_NRRC_BeamResult                        stNPHY_NRRC_BeamResult; \
    NPHY_NRRC_CellSearchInfo                    stNPHY_NRRC_CellSearchInfo; \
    NPHY_NRRC_BandScanResultList                stNPHY_NRRC_BandScanResultList; \
    NPHY_NRRC_CellIdleMeasResult                stNPHY_NRRC_CellIdleMeasResult; \
    NPHY_NRRC_CellConnMeasResult                stNPHY_NRRC_CellConnMeasResult; \
    NPHY_NRRC_SingleFreqIdleMeasResult          stNPHY_NRRC_SingleFreqIdleMeasResult; \
    NPHY_NRRC_SingleFreqConnMeasResult          stNPHY_NRRC_SingleFreqConnMeasResult; \
    NPHY_NRRC_MeasRsltInfo                      stNPHY_NRRC_MeasRsltInfo; \
    NPHY_NRRC_SftdMeasCellRslt                  stNPHY_NRRC_SftdMeasCellRslt; \
    NPHY_NRRC_SftdMeasRslt                      stNPHY_NRRC_SftdMeasRslt; \
    NPHY_NRRC_ConnSftdMeasInd                   stNPHY_NRRC_ConnSftdMeasInd; \
    NPHY_NRRC_MrDcSyncNtf                       stNPHY_NRRC_MrDcSyncNtf; \
    NPHY_NRRC_IdleMeasPcellIntraSetupCnf        stNPHY_NRRC_IdleMeasPcellIntraSetupCnf; \
    NPHY_NRRC_IdleMeasPcellSetupCnf             stNPHY_NRRC_IdleMeasPcellSetupCnf; \
    NPHY_NRRC_IdleMeasPcellInd                  stNPHY_NRRC_IdleMeasPcellInd; \
    NPHY_NRRC_IdleMeasPcellIntraInd             stNPHY_NRRC_IdleMeasPcellIntraInd; \
    NPHY_NRRC_IdleMeasInterSetupCnf             stNPHY_NRRC_IdleMeasInterSetupCnf; \
    NPHY_NRRC_IdleMeasInterInd                  stNPHY_NRRC_IdleMeasInterInd; \
    NPHY_NRRC_IdleMeasIratSetupCnf              stNPHY_NRRC_IdleMeasIratSetupCnf; \
    NPHY_NRRC_IdleMeasRelCnf                    stNPHY_NRRC_IdleMeasRelCnf; \
    NPHY_NRRC_ConnCommMeasConfigCnf             stNPHY_NRRC_ConnCommMeasConfigCnf; \
    NPHY_NRRC_ConnMeasGapConfigCnf              stNPHY_NRRC_ConnMeasGapConfigCnf; \
    NPHY_NRRC_ConnMeasIratSetupCnf              stNPHY_NRRC_ConnMeasIratSetupCnf; \
    NPHY_NRRC_ConnMeasPcellSetupCnf             stNPHY_NRRC_ConnMeasPcellSetupCnf; \
    NPHY_NRRC_ConnMeasPcellInd                  stNPHY_NRRC_ConnMeasPcellInd; \
    NPHY_NRRC_ConnMeasPcellIntraSetupCnf        stNPHY_NRRC_ConnMeasPcellIntraSetupCnf; \
    NPHY_NRRC_ConnMeasPcellIntraInd             stNPHY_NRRC_ConnMeasPcellIntraInd; \
    NPHY_NRRC_ConnMeasInterInd                  stNPHY_NRRC_ConnMeasInterInd; \
    NPHY_NRRC_ConnMeasInterSetupCnf             stNPHY_NRRC_ConnMeasInterSetupCnf; \
    NPHY_NRRC_ConnMeasPscellSetupCnf            stNPHY_NRRC_ConnMeasPscellSetupCnf; \
    NPHY_NRRC_ConnMeasPscellInd                 stNPHY_NRRC_ConnMeasPscellInd; \
    NPHY_NRRC_ConnMeasPscellIntraSetupCnf       stNPHY_NRRC_ConnMeasPscellIntraSetupCnf; \
    NPHY_NRRC_ConnMeasPscellIntraInd            stNPHY_NRRC_ConnMeasPscellIntraInd; \
    NPHY_NRRC_ConnMeasSecondFreqSetupCnf        stNPHY_NRRC_ConnMeasSecondFreqSetupCnf; \
    NPHY_NRRC_ConnMeasSecondFreqInd             stNPHY_NRRC_ConnMeasSecondFreqInd; \
    NPHY_NRRC_ConnMeasRelCnf                    stNPHY_NRRC_ConnMeasRelCnf; \
    NPHY_NRRC_ConnMeasAnrStartCnf               stNPHY_NRRC_ConnMeasAnrStartCnf; \
    NPHY_NRRC_ConnMeasAnrStopCnf                stNPHY_NRRC_ConnMeasAnrStopCnf; \
    NPHY_NRRC_ConnMeasIratAnrStartCnf           stNPHY_NRRC_ConnMeasIratAnrStartCnf; \
    NPHY_NRRC_ConnMeasIratAnrStopCnf            stNPHY_NRRC_ConnMeasIratAnrStopCnf; \
    NPHY_NRRC_CellSearchingInd                  stNPHY_NRRC_CellSearchingInd; \
    NPHY_NRRC_PbchSetupCnf                      stNPHY_NRRC_PbchSetupCnf; \
    NPHY_NRRC_PbchDataInd                       stNPHY_NRRC_PbchDataInd; \
    NPHY_NRRC_FreqRssiScanInd                   stNPHY_NRRC_FreqRssiScanInd; \
    NPHY_NRRC_PdschBchSetupCnf                  stNPHY_NRRC_PdschBchSetupCnf; \
    NPHY_NRRC_CampedMaincellCnf                 stNPHY_NRRC_CampedMaincellCnf; \
    NPHY_NRRC_PbchReleaseCnf                    stNPHY_NRRC_PbchReleaseCnf; \
    NPHY_NRRC_PdschBchReleaseCnf                stNPHY_NRRC_PdschBchReleaseCnf; \
    NPHY_NRRC_ReadPbchFailInd                   stNPHY_NRRC_ReadPbchFailInd; \
    NPHY_NRRC_BgSearchStartCnf                  stNPHY_NRRC_BgSearchStartCnf; \
    NPHY_NRRC_BgSearchStopCnf                   stNPHY_NRRC_BgSearchStopCnf; \
    NPHY_NRRC_BgSearchSuspendCnf                stNPHY_NRRC_BgSearchSuspendCnf; \
    NPHY_NRRC_BgSearchResumeCnf                 stNPHY_NRRC_BgSearchResumeCnf; \
    NPHY_NRRC_SiConfigCnf                       stNPHY_NRRC_SiConfigCnf; \
    NPHY_NRRC_PreResourceConfigCnf              stNPHY_NRRC_PreResourceConfigCnf; \
    NPHY_NRRC_PchDataInd                        stNPHY_NRRC_PchDataInd; \
    NPHY_NRRC_ShortMessageInd                   stNPHY_NRRC_ShortMessageInd; \
    NPHY_NRRC_SetWorkModeCnf                    stNPHY_NRRC_SetWorkModeCnf; \
    NPHY_NRRC_RelAllCnf                         stNPHY_NRRC_RelAllCnf; \
    NPHY_NRRC_ConnectedToIdleCnf                stNPHY_NRRC_ConnectedToIdleCnf; \
    NPHY_NRRC_SyncCnf                           stNPHY_NRRC_SyncCnf; \
    NPHY_NRRC_SyncInd                           stNPHY_NRRC_SyncInd; \
    NPHY_NRRC_OutOfSyncInd                      stNPHY_NRRC_OutOfSyncInd; \
    NPHY_NRRC_ErrorInd                          stNPHY_NRRC_ErrorInd; \
    NPHY_NRRC_BandScanInd                       stNPHY_NRRC_BandScanInd; \
    NPHY_NRRC_DpdtCmdInd                        stNPHY_NRRC_DpdtCmdInd; \
    NPHY_NRRC_AntInfoCnf                        stNPHY_NRRC_AntInfoCnf; \
    NPHY_NRRC_DsdsSuspendCnf                    stNPHY_NRRC_DsdsSuspendCnf; \
    NPHY_NRRC_DsdsResumeCnf                     stNPHY_NRRC_DsdsResumeCnf; \
    NPHY_NRRC_SibLeapTimeGetCnf                 stNPHY_NRRC_SibLeapTimeGetCnf; \
    NPHY_NRRC_DemandSiStartCnf                  stNPHY_NRRC_DemandSiStartCnf; \
    NPHY_NRRC_DemandSiStopCnf                   stNPHY_NRRC_DemandSiStopCnf; \
    NPHY_NRRC_QryTrxTasCnf                      stNPHY_NRRC_QryTrxTasCnf; \
    NPHY_NRRC_DdrCfgCnf                         stNPHY_NRRC_DdrCfgCnf; \
    NPHY_NRRC_MeasPbchDataInd                   stNPHY_NRRC_MeasPbchDataInd; \
    NPHY_NRRC_BeamLockTestCnf                   stNPHY_NRRC_BeamLockTestCnf; \
    NPHY_NRRC_PlatformCapInd                    stNPHY_NRRC_PlatformCapInd; \
    NPHY_NRRC_OsiParaConfigCnf                  stNPHY_NRRC_OsiParaConfigCnf;
/* nrrc_nphy_interface.h end */
/* mac_nphy_interface.h start */
#define MAC_NPHY_INTERFACE_MAIN \
    enum NMAC_NPHY_MsgType                      enNMAC_NPHY_MsgType; \
    enum NMAC_NPHY_SchedMode                    enNMAC_NPHY_SchedMode; \
    enum NMAC_NPHY_RntiType                     enNMAC_NPHY_RntiType; \
    enum NMAC_NPHY_Crc                          enNMAC_NPHY_Crc; \
    enum NMAC_NPHY_DataErr                      enNMAC_NPHY_DataErr; \
    enum NMAC_NPHY_BeamIndexType                enNMAC_NPHY_BeamIndexType; \
    enum NMAC_NPHY_RaBwpSwitchType              enNMAC_NPHY_RaBwpSwitchType; \
    enum NR_ACCESS_Cause                        enNR_ACCESS_Cause; \
    enum NR_ACCESS_Type                         enNR_ACCESS_Type; \
    enum NMAC_NPHY_PreambleScsindex             enNMAC_NPHY_PreambleScsindex; \
    enum NMAC_NPHY_CrntiValid                   enNMAC_NPHY_CrntiValid; \
    enum NMAC_NPHY_UlGrantType                  enNMAC_NPHY_UlGrantType; \
    enum NMAC_NPHY_PwrRampSuspend               enNMAC_NPHY_PwrRampSuspend; \
    enum NMAC_NPHY_CdrxType                     enNMAC_NPHY_CdrxType; \
    enum NMAC_NPHY_UlSkip                       enNMAC_NPHY_UlSkip; \
    enum NMAC_NPHY_UlDataType                   enNMAC_NPHY_UlDataType; \
    enum NR_ACCESS_SsbOccasionMask              enNR_ACCESS_SsbOccasionMask; \
    enum NMAC_NPHY_Msg1ScsValid                 enNMAC_NPHY_Msg1ScsValid; \
    enum NMAC_NPHY_RaPeriodValid                enNMAC_NPHY_RaPeriodValid; \
    enum NMAC_NPHY_Msg3TransPrecode             enNMAC_NPHY_Msg3TransPrecode; \
    enum NMAC_NPHY_PhType                       enNMAC_NPHY_PhType; \
    enum NMAC_NPHY_MacCe                        enNMAC_NPHY_MacCe; \
    enum NMAC_NPHY_DsdsRf                       enNMAC_NPHY_DsdsRf; \
    enum NMAC_NPHY_UlBbpPadFillMod              enNMAC_NPHY_UlBbpPadFillMod; \
    enum NMAC_NPHY_ScellDeactType               enNMAC_NPHY_ScellDeactType; \
    enum NMAC_NPHY_UlBwpSwitch                  enNMAC_NPHY_UlBwpSwitch; \
    enum NPHY_NMAC_CsirsQclSsbIndexValid        enNPHY_NMAC_CsirsQclSsbIndexValid; \
    enum NPHY_NMAC_SrSendResultType             enNPHY_NMAC_SrSendResultType; \
    NMAC_NPHY_AccessReq                         stNMAC_NPHY_AccessReq;                  /* ID_NMAC_NPHY_ACCESS_REQ */ \
    NMAC_NPHY_RarConfigReq                      stNMAC_NPHY_RarConfigReq;               /* ID_NMAC_NPHY_RAR_CONFIG_REQ */ \
    NMAC_NPHY_SrDataReq                         stNMAC_NPHY_SrDataReq;                  /* ID_NMAC_NPHY_SR_DATA_REQ */ \
    NMAC_NPHY_RaAckNtf                          stNMAC_NPHY_RaAckNtf;                   /* ID_NMAC_NPHY_RA_ACK_NTF */ \
    NMAC_NPHY_HoCqiSrsActiveNtf                 stNMAC_NPHY_HoCqiSrsActiveNtf;          /* ID_NMAC_NPHY_HO_CQI_SRS_ACT_NTF */ \
    NMAC_NPHY_GapConfigNtf                      stNMAC_NPHY_GapConfigNtf;               /* ID_NMAC_NPHY_GAP_CONFIG_NTF */ \
    NMAC_NPHY_ForceActiveNtf                    stNMAC_NPHY_ForceActiveNtf;             /* ID_NMAC_NPHY_FORCE_ACT_NTF */ \
    NMAC_NPHY_TaTimerNtf                        stNMAC_NPHY_TaTimerNtf;                 /* ID_NMAC_NPHY_TA_TIMER_NTF */ \
    NMAC_NPHY_TaNtf                             stNMAC_NPHY_TaNtf;                      /* ID_NMAC_NPHY_TA_NTF */ \
    NMAC_NPHY_ConnectedDrxNtf                   stNMAC_NPHY_ConnectedDrxNtf;            /* ID_NMAC_NPHY_CDRX_NTF */ \
    NMAC_NPHY_ScellActNtf                       stNMAC_NPHY_ScellActNtf;                /* ID_NMAC_NPHY_SCELL_ACT_NTF */ \
    NMAC_NPHY_BwpInactTimerNtf                  stNMAC_NPHY_BwpInactTimerNtf;           /* ID_NMAC_NPHY_BWP_INACT_TIMER_NTF */ \
    NMAC_NPHY_MacCeNtf                          stNMAC_NPHY_MacCeNtf;                   /* ID_NMAC_NPHY_MAC_CE_NTF */ \
    NMAC_NPHY_RaBwpSwitchNtf                    stNMAC_NPHY_RaBwpSwitchNtf;             /* ID_NMAC_NPHY_RA_BWP_SWITCH_NTF */ \
    NMAC_NPHY_RaStopNtf                         stNMAC_NPHY_RaStopNtf;                  /* ID_NMAC_NPHY_RA_STOP_NTF */ \
    NMAC_NPHY_UlConfigGrantTrigNtf              stNMAC_NPHY_UlConfigGrantTrigNtf;       /* ID_NMAC_NPHY_UL_CONFIG_GRANT_TRIG_NTF */ \
    NMAC_NPHY_UlConfigGrantStopNtf              stNMAC_NPHY_UlConfigGrantStopNtf;       /* ID_NMAC_NPHY_UL_CONFIG_GRANT_STOP_NTF */ \
    NMAC_NPHY_ResetNtf                          stNMAC_NPHY_ResetNtf;                   /* ID_NMAC_NPHY_RESET_NTF */ \
    NMAC_NPHY_UlConfigGrantDeactCnfNtf          stNMAC_NPHY_UlConfigGrantDeactCnfNtf;   /* ID_NMAC_NPHY_UL_CONFIG_GRANT_DEACT_CNF_NTF */ \
    NPHY_NMAC_AccessCnf                         stNPHY_NMAC_AccessCnf;                  /* ID_NPHY_NMAC_ACCESS_CNF */ \
    NPHY_NMAC_RarConfigCnf                      stNPHY_NMAC_RarConfigCnf;               /* ID_NPHY_NMAC_RAR_CONFIG_CNF */ \
    NPHY_NMAC_SrDataCnf                         stNPHY_NMAC_SrDataCnf;                  /* ID_NPHY_NMAC_SR_DATA_CNF */ \
    NPHY_NMAC_PdcchOrderInd                     stNPHY_NMAC_PdcchOrderInd;              /* ID_NPHY_NMAC_PDCCH_ORDER_IND */ \
    NPHY_NMAC_PdcchOrderSuccInd                 stNPHY_NMAC_PdcchOrderSuccInd;          /* ID_NPHY_NMAC_PDCCH_ORDER_SUCC_IND */ \
    NPHY_NMAC_BeamFailureRecoveryInd            stNPHY_NMAC_BeamFailureRecoveryInd;     /* ID_NPHY_NMAC_BEAM_FAILURE_RECOVERY_IND */ \
    NPHY_NMAC_BeamFailureRecoverySuccInd        stNPHY_NMAC_BeamFailureRecoverySuccInd; /* ID_NPHY_NMAC_BEAM_FAILURE_RECOVERY_SUCC_IND */ \
    NPHY_NMAC_RarResponseTimeoutInd             stNPHY_NMAC_RarResponseTimeoutInd;      /* ID_NPHY_NMAC_RAR_RESPONSE_TIMEOUT_IND */ \
    NPHY_NMAC_BfrResponseTimeoutInd             stNPHY_NMAC_BfrResponseTimeoutInd;      /* ID_NPHY_NMAC_BFR_RESPONSE_TIMEOUT_IND */ \
    NPHY_NMAC_DlBwpSwitchInd                    stNPHY_NMAC_DlBwpSwitchInd;             /* ID_NPHY_NMAC_DL_BWP_SWITCH_IND */ \
    NPHY_NMAC_UlGrantInd                        stNPHY_NMAC_UlGrantInd;                 /* ID_NPHY_NMAC_UL_GRANT_IND */ \
    NPHY_NMAC_DlAssignmentInd                   stNPHY_NMAC_DlAssignmentInd;            /* ID_NPHY_NMAC_DL_ASSIGNMENT_IND */ \
    NPHY_NMAC_PhInd                             stNPHY_NMAC_PhInd;                      /* ID_NPHY_NMAC_PH_IND */ \
    NPHY_NMAC_PwrRampSuspensionInd              stNPHY_NMAC_PwrRampSuspensionInd;       /* ID_NPHY_NMAC_PWR_RAMP_SUSPENSION_IND */ \
    NPHY_NMAC_UlTransTimingDiffInd              stNPHY_NMAC_UlTransTimingDiffInd;       /* ID_NPHY_NMAC_UL_TRANS_TIMING_DIFF_IND */ \
    NPHY_NMAC_SsbCsirsIndexInd                  stNPHY_NMAC_SsbCsirsIndexInd;           /* ID_NPHY_NMAC_SSB_CSIRS_INDEX_IND */ \
    NPHY_NMAC_BeamClearInd                      stNPHY_NMAC_BeamClearInd;               /* ID_NPHY_NMAC_BEAM_CLEAR_IND */ \
    NPHY_NMAC_DsdsRfUsedInd                     stNPHY_NMAC_DsdsRfUsedInd;              /* ID_NPHY_NMAC_DSDS_RF_USED_IND */ \
    NPHY_NMAC_UlConfigGrantActInd               stNPHY_NMAC_UlConfigGrantActInd;        /* ID_NPHY_NMAC_UL_CONFIG_GRANT_ACT_IND */ \
    NPHY_NMAC_UlConfigGrantDeactInd             stNPHY_NMAC_UlConfigGrantDeactInd;      /* ID_NPHY_NMAC_UL_CONFIG_GRANT_DEACT_IND */ \
    NPHY_NMAC_CcMappingInd                      stNPHY_NMAC_CcMappingInd;               /* ID_NPHY_NMAC_CC_MAPPING_IND */
/* mac_nphy_interface.h end */
/* NR PROC END */


/* NR DSDS START */
#define NPHY_DSDS_MAIN \
    enum NPHY_DSDS_OmMsgType        nphyDsdsOmReport; \
    enum RCM_PHY_MsgId              rcmPhyMsgId; \
    enum RCM_MODE_Id                rcmModeId; \
    enum RCM_MODEM_Id               rcmModemId; \
    enum RCM_PHY_ConcurrenceState   phyRcmConcSt; \
    enum RCM_RF_Id                  rcmRfId; \
    enum NEUN_DSDS_RfState          neunDdsdsRfState; \
    enum NEUN_DSDS_SchedState       neunDdsdsSchedState; \
    enum NEUN_DSDS_TaskTimerType   neunDdsdsTaskTimerType; \
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
/* NR DSDS END */


/* NR DL CHANCTRL */
#define NPHY_DL_CHANCTRL_MAIN \
    NPHY_DL_ChanCtrlOmReq                                       dlChanCtrlOmReq ; \
    NPHY_DL_ChanOmPrintTarceInfo                                dlChanOmPrintTarceInfo; \
    NPHY_DL_ChanRptInterface                                    dlChanRptInterface; \
    enum NPHY_DL_RptInterfaceType                               dlChanRptInterfaceTypeUint32; \
    NPHY_DL_ChanRptDbuf                                         dlChanDbuf; \
    NPHY_DL_ChanTag                                             dlChanTimetag; \
    NPHY_DLSERV_UlFixedMsgOmRpt                                 dlChanUlFixedMsgOmRpt;
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
    enum NPHY_DLRLM_OmWarn                                      dlRlmOmWarnTpye;
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
    NPHY_DEM_OmPdsInfoDt                                        dlDemPdsInfoDtRpt;
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
    NPHY_CHE_PdsChnlCfg                                         dlChePdsChnlCfg;\
    FpdsNrChCfcRegsType                                         dlCheFpdsCfg;\
    DcicpQclCfgRegsType                                         dlCheHalQclCfg;\
    NPHY_CHE_PdsDediChnlRpt                                     dlChePdeRpt;\
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
    enum NPHY_CHE_OmPrintTrace                                  dlCheOmPrintTrace;
enum NPHY_CHE_OmModuleId                                    dlCheOmModuleId;
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
    NPHY_DEC_Rm                                                 nphyDecRmDtRpt; \
    NPHY_DEC_DtDLThroughputOm                                   nphyDecDlThroughputDtRpt; \
    NPHY_DEC_DtLayerRpt                                         nphyDtLayerRpt;
/* NR DL DEC PDC */
#define NPHY_DL_DEC_PDC_MAIN \
    enum NPHY_DEC_OmPdcTrace                                    nphyDecRptInfo; \
    NPHY_DL_DecPdcOmReq                                         nphyDecPdcOmReq; \
    NPHY_DEC_OmDci10SirntiDomain                                nphyDecOmDci10SirntiDomain; \
    NPHY_DEC_OmDci10RarntiDomain                                nphyDecOmDci10RarntiDomain; \
    NPHY_DEC_OmDci10CrntiDomain                                 nphyDecOmDci10CrntiDomai; \
    NPHY_DEC_OmDci11Domain                                      nphyDecOmDci11Domain; \
    NPHY_DEC_OmDci10PrntiDomain                                 nphyDecOmDci10PrntiDomain; \
    NPHY_DEC_OmCurrCoreset                                      nphyDecOmCurrCoreset; \
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
    NPHY_DEC_OmFakeDci                                          nphyDecOmFakeDci;
/* FEC om */
#define NPHY_FEC_OM_MAIN \
    NPHY_FEC_OmCcReqInfo                                        ccReqInfo;
/* sfi om */
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
    NEUN_AFC_PredictTempComp                                    predictTempComp;\
    NPHY_TFSYNC_DemTimeHstInfo                                  demTimeHstInfo;
/* TRU */
#define NPHY_TRU_MAIN \
    enum NPHY_TRU_LoopType                                      nphyTruloopTypeUint08; \
    NPHY_FEU_HalTsnIrigbTimeInfo                               tsnIrigbTimeInfo; \
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
    NPHY_TFSYNC_TrsDdrSamp                                      nphyTfsyncTrsDdrSamp; \
    NEUN_TFSYNC_RecvWinInfo                                     nphyTfsyncWinPara; \
    enum NEUN_TFSYNC_RecWinMode                                 nphyTfsyncRecWinModeUint08; \
    NEUN_TFSYNC_WinParaStub                                     nphyTfsyncParaStub;
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
/* NR HL1C OM */
#define NPHY_HL1C_OM_MAIN \
    NEUN_LPC_OmHl1cWakeInfo                                     hl1cWakeInfo; \
    NEUN_LPC_OmHl1cSleepInfo                                    hl1cSleepInfo; \
    NPHY_LPC_CtrlInfo                                           hl1cLpcCtrlInfo; \
    UL1M_ULPM_H2UMsg                                            h2uLpcMsg; \
    NEUN_L1D_L1cLpcMsg                                         ll1d2Hl1cLpcMsg; \
    NEUN_L1C_L1dLpcMsg                                         hl1c2Ll1dLpcMsg; \
    NEUN_L1CL1U_LpcMsg                                          hl1c2Ll1uLpcMsg; \
    NEUN_LPC_OmSwitch                                           lpcOmSwitch; \
    NPHY_LPC_OmStubReq                                          lpcOmStubReq; \
    enum UL1M_ULPM_H2UMsgId_                                    h2uLpcMsgType; \
    enum NEUN_L1C_L1dMsgType                                    hl1cLl1dMsgType; \
    NEUN_L1UL1C_CnfCommPara                                     lpcL1uL1cCnfMsg; \
    enum NEUN_L1CL1U_ExtPifMsgType                              lpcL1cL1uLpcMsgEnum; \
    enum NPHY_LPC_LocalBwpSwitchEvt                             lpcLocalBwpSwitchEvt; \
    enum NPHY_LPC_BwpSwitchType                                 lpcBwpSwitchType; \
    enum NPHY_LPC_MicroSleepForBidType                          mcroSleepForBidType; \
    NPHY_LPC_OmSymbRxBitInfo                                    nphyLpcOmSymbRxBitInfo; \
    NPHY_LPC_OmDvtyInfo                                         nphyLpcOmDvtyInfo; \
    NPHY_LPC_OmLocalBwpInfo                                     nphyLpcOmLocalBwpInfo; \
    NPHY_DVFS_TspProfileInfo                                    dvfsTspProfInfo; \
    NPHY_LPC_OmDvtyCalInfo                                      nphyLpcOmDvtyCalInfo; \
    enum NEUN_LPC_PrintEvt                                      lpcPrintEvt; \
    enum UPHY_OM_ReportLevel                                    printLevel; \
    enum NEUN_LPC_SymbLpcWorkMode                               pccWorkMode; \
    NEUN_LPC_PrintRptInfo                                       nphyLpcPrintInfo; \
    enum NPHY_LPC_LocationType                                  nphyLpcLocationType; \
    enum NEUN_LPC_PagingListenType                              nphyLpcPagingListenType; \
    NPHY_LPC_LocationPara                                       nphyLpcLocationPara; \
    NPHY_LPC_SsbSnr                                             nphyLpcSsbSnr; \
    NPHY_LPC_PeiStateInfo                                       nphyLpcPeiStateInfo; \
    NEUN_LPC_LocalTxInfo                                        nphyLpcLocalTxInfo; \
    UPHY_LPC_PdcOnlyRecord                                      nphyLpcPdcOnlyInfo;
/* DRX */
#define NPHY_DRX_MAIN \
    enum NPHY_CDRX_OmL1MsgId     nphyCdrxOmL1MsgID; \
    NEUN_CDRX_OmRptReq           nphyHl1cCdrxOmRptEn; \
    NEUN_CDRX_OmRptCtrl          nphyCdrxOmRptCtrl; \
    NEUN_CDRX_OmTimeInfo         nphyCdrxOmTimeInfo; \
    NEUN_CDRX_OmOnduTmrInfo      nphyCdrxOmOnduTmrInfo; \
    NEUN_CDRX_OmAddTmrInfo       nphyCdrxOmAddTmrInfo; \
    NEUN_CDRX_OmDelTmrInfo       nphyCdrxOmDelTmrInfo; \
    NEUN_CDRX_OmRrcCfgInfoRpt    nphyCdrxOmRrcCfgInfoRpt; \
    NPHY_CDRX_SpsWakeInfo        nphyCdrxOmSpsWakeInfo; \
    NPHY_CDRX_OmSpsInfo          nphyCdrxOmSpsInfo;
/* SCHED */
#define NPHY_SCHED_MAIN \
    NPHY_SCHED_OmSymbCycleRptReq                                SymbCycleRptReq;
/* NR HL1C SCHED OM */
#define NPHY_HL1C_SCHED_OM_MAIN \
    NPHY_OM_Hl1cCycleRpt                                        hl1cCycleRpt;
/* NR LL1D SCHED OM */
#define NPHY_LL1D_SCHED_OM_MAIN \
    NPHY_OM_Ll1dCycleRpt                                        ll1dCycleRpt;
/* NR UL CSI */
#define NPHY_UL_CSI_MAIN \
    NPHY_ULCSI_CtrlOmReq                                        ulCsiCtrlOmReq; \
    NPHY_CSI_OmRptStub                                          ulCsiRptStubInfo; \
    NPHY_CSI_OmDtRptTimerStub                                   ulCsiDtRptTimerStub; \
    NPHY_CSI_ReportPayLoad                                      ulCsiPdRptPayload; \
    NPHY_CSI_PeriodicRptInfoLocal                               ulCsiPdRptLenInfo; \
    NPHY_CSI_ApRptInfoLocal                                     ulCsiApRptLenInfo; \
    NPHY_CSI_ReportSeqs                                         ulCsiRptPacket; \
    NRRC_NPHY_CsiApTrigStateCfg                                 ulCsiRptTrigInfo; \
    NPHY_CSI_OmTrigRslt                                         ulCsiRptTrigRslt; \
    NPHY_CSI_OmTimeInfo                                         ulCsiRptTimeInfo; \
    NPHY_CSI_OmCycleStat                                        ulCsiRptCycleInfo; \
    NPHY_CSI_OmTraceMsg                                         ulCsiRptTraceInfo; \
    NPHY_CSI_OmWarnMsg                                          ulCsiRptWarnInfo; \
    NPHY_ULCSI_OmDtGenl                                         ulCsiOmDtGenl; \
    NPHY_ULCSI_OmDtRankPerSec                                   ulCsiOmDtRankPerSec; \
    NPHY_ULCSI_OmDtCqiPerSec                                    ulCsiOmDtCqiPerSec; \
    enum NPHY_ULCSI_OmTraceCode                                ulCsiOmTraceType; \
    enum NPHY_ULCSI_OmWarnCode                                 ulCsiOmWarnType; \
    enum NPHY_ULCSI_OmMsgState                                 ulCsiOmMsgState; \
    enum NPHY_ULCSI_CbkPmi                                     ulCsiCbkPmi; \
    enum NPHY_ULCSI_RptLenType                                 ulCsiRptLenType; \
    NPHY_ULCSI_OmRptPeriodicRslt                                ulPdCsiRptRslt; \
    NPHY_ULCSI_OmRptAperiodicRslt                               ulApCsiRslt;
/* nphy meas start */
#define NPHY_MEAS_MAIN \
    NPHY_NRRC_MeasPbchDataInd                   measMeasPbchDataInd; \
    NPHY_NRRC_BeamLockTestCnf                   measBeamLockTestCnf; \
    NPHY_NRRC_IdleMeasPcellIntraSetupCnf        measIdleMeasPcellIntraSetupCnf; \
    NPHY_NRRC_IdleMeasPcellSetupCnf             measIdleMeasPcellSetupCnf; \
    NPHY_NRRC_IdleMeasPcellInd                  measIdleMeasPcellInd; \
    NPHY_NRRC_IdleMeasPcellIntraInd             measIdleMeasPcellIntraInd; \
    NPHY_NRRC_IdleMeasInterSetupCnf             measIdleMeasInterSetupCnf; \
    NPHY_NRRC_IdleMeasInterInd                  measIdleMeasInterInd; \
    NPHY_NRRC_IdleMeasIratSetupCnf              measIdleMeasIratSetupCnf; \
    NPHY_NRRC_IdleMeasRelCnf                    measIdleMeasRelCnf; \
    NPHY_NRRC_ConnCommMeasConfigCnf             measConnCommMeasConfigCnf; \
    NPHY_NRRC_ConnMeasGapConfigCnf              measConnMeasGapConfigCnf; \
    NPHY_NRRC_ConnMeasIratSetupCnf              measConnMeasIratSetupCnf; \
    NPHY_NRRC_ConnMeasPcellSetupCnf             measConnMeasPcellSetupCnf; \
    NPHY_NRRC_ConnMeasPcellInd                  measConnMeasPcellInd; \
    NPHY_NRRC_ConnMeasPcellIntraSetupCnf        measConnMeasPcellIntraSetupCnf; \
    NPHY_NRRC_ConnMeasPcellIntraInd             measConnMeasPcellIntraInd; \
    NPHY_NRRC_ConnMeasInterInd                  measConnMeasInterInd; \
    NPHY_NRRC_ConnMeasInterSetupCnf             measConnMeasInterSetupCnf; \
    NPHY_NRRC_ConnMeasPscellSetupCnf            measConnMeasPscellSetupCnf; \
    NPHY_NRRC_ConnMeasPscellInd                 measConnMeasPscellInd; \
    NPHY_NRRC_ConnMeasPscellIntraSetupCnf       measConnMeasPscellIntraSetupCnf; \
    NPHY_NRRC_ConnMeasPscellIntraInd            measConnMeasPscellIntraInd; \
    NPHY_NRRC_ConnMeasSecondFreqSetupCnf        measConnMeasSecondFreqSetupCnf; \
    NPHY_NRRC_ConnMeasSecondFreqInd             measConnMeasSecondFreqInd; \
    NPHY_NRRC_ConnMeasRelCnf                    measConnMeasRelCnf; \
    NPHY_NRRC_ConnMeasAnrStartCnf               measConnMeasAnrStartCnf; \
    NPHY_NRRC_ConnMeasAnrStopCnf                measConnMeasAnrStopCnf; \
    NPHY_NRRC_ConnMeasIratAnrStartCnf           measConnMeasIratAnrStartCnf; \
    NPHY_NRRC_ConnMeasIratAnrStopCnf            measConnMeasIratAnrStopCnf; \
    NPHY_SDR_Hl1cPbchMeasReport                 emuHl1cPbchMeasReport;
/* nphy meas stop */

/* nphy csu start */
#define NPHY_CSU_MAIN \
    NPHY_SDR_OmBeamRptResultIndex               omSdrBeamRpt; \
    NPHY_L1DL1C_EmuSsbRssiResultInd             omSsbRssiRpt; \
    NPHY_CSU_QueueInitEmuInfo                   omSdrInitEmuRpt; \
    NPHY_Hl1cLl1cSsbComPbchCfg                  omSdrEmuPbCfgRpt; \
    NPHY_DLBM_OmSsbBplInstantRslt               omSdrBmSsbBplRpt; \
    NPHY_CSU_QueueInitEmuInfo                   omSdrMergeInitEmuRpt;
/* nphy csu stop */
/* TAS begin */
#define NPHY_RCM_ASU_MAIN \
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
    PHY_RCM_TasStateInd                         omPhyRcmTasStateInd;
/* TAS end */
#define NPHY_HL1C_LL1D_INTERFACE_MAIN \
    NPHY_HL1C_Ll1cCsiRsTaskStop                 stNPHY_HL1C_LL1C_CsiRsTaskStop; \
    NPHY_HL1C_Ll1cEMU                           stNPHY_HL1C_LL1C_EMU_CsiRsSmpCfg;
#define NPHY_TOP_INTERFACE_MAIN \
    enum NPHY_CsiRsSmpChnState                  enNPHY_CsiRsSmpChnState;
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* end of hids_elf_nphy.c */
