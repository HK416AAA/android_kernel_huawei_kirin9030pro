

#ifndef __HIDS_ELF_D2DPHY_H__
#define __HIDS_ELF_D2DPHY_H__

/*
 * 头文件包含
 */
#include "hrrc_hphy_hid2d_interface.h"
#include "hsync_hphy_hid2d_interface.h"
#include "hid2d_l2_phy_interface.h"
#include "d2d_agc_om_def.h"
#include "d2d_hl1c_basedef_struct.h"
#include "d2d_fec_comm_interface.h"
#include "d2d_ul_fec_interface.h"
#include "d2d_ul_om_def.h"
#include "d2d_tfsync_om_def.h"
#include "d2d_tru_om_def.h"
#include "d2d_afc_om_def.h"
#include "neun_csu_om_def.h"
#include "d2d_dl_om_def.h"
#include "d2d_wmc_om_def.h"
#include "d2d_proc_om_def.h"
#include "ul1m_d2d_tfsync_om.h"
#include "ul1m_d2d_dem_om.h"
#include "ul1m_d2d_agc_om.h"
#include "ul1m_d2d_proc_om.h"
#include "lphy_v2x_hal_feu_interface.h"
#include "ul1m_vphy_interface.h"
#include "ul1m_rcm_tas_interface.h"
#include "ul1m_rcm_dsds1p0_interface.h"
#include "ul1m_rcm_dcxo_interface.h"
#include "ul1m_rcm_agent_interface.h"
#include "ul1m_rcm_crm_interface.h"
#include "ul1m_rcm_base_interface.h"
#include "d2d_basedef_struct.h"
#include "d2d_lpc_interface.h"
#include "uphy_blkddrmgr_interface.h"
#include "lphy_v2x_hal_dem_interface.h"
#ifdef __cplusplus
extern "C" {
#endif

#define D2DPHY_HRRCPHYINTERFACE_MAIN \
    HRRC_HPHY_MsgTypeUint32           enHRRC_HPHY_MsgTypeUint32; \
    HRRC_HPHY_WorkModeTypeUint16      enHRRC_HPHY_WorkModeTypeUint16; \
    PS_D2D_RsltTypeUint32             enPS_D2D_RsltTypeUint32; \
    HSYNC_HPHY_MsgTypeUint32          enHSYNC_HPHY_MsgTypeUint32;\
    HRRC_HPHY_SyncSrcTypeUint16       enHRRC_HPHY_SyncSrcTypeUint16;\
    HPHY_HRRC_SystemParaConfigCnf     stHPHY_HRRC_SystemParaConfigCnf; \
    HPHY_HRRC_HbcchDataCnf            stHPHY_HRRC_HbcchDataCnf; \
    HRRC_HPHY_HbcchDataStopNtf        stHRRC_HPHY_HbcchDataStopNtf; \
    HPHY_HRRC_SetWorkModeCnf          stHPHY_HRRC_SetWorkModeCnf; \
    HPHY_HRRC_DlOutOfSyncInd          stHPHY_HRRC_DlOutOfSyncInd;\
    HPHY_HRRC_SyncSrcConfigCnf        stHPHY_HRRC_SyncSrcConfigCnf;\
    HPHY_HRRC_InitSearchCnf           stHPHY_HRRC_InitSearchCnf; \
    HPHY_HRRC_SearchRsltInd           stHPHY_HRRC_SearchRsltInd;\
    HPHY_HRRC_SearchResultInfo        stHPHY_HRRC_SearchResultInfo;\
    HPHY_HRRC_RefUeInfo               stHPHY_HRRC_RefUeInfo;\
    HPHY_HRRC_LpcSearchCnf            stHPHY_HRRC_LpcSearchCnf;\
    HPHY_HRRC_LpcSearchStopCnf        stHPHY_HRRC_LpcSearchStopCnf;\
    HPHY_HRRC_PeriodSearchStopCnf     stHPHY_HRRC_PeriodSearchStopCnf;\
    HPHY_HRRC_RaInd                   stHPHY_HRRC_RaInd;\
    HPHY_HRRC_RefUeSignalQualityInd   stHPHY_HRRC_RefUeSignalQualityInd

/* AGC */
#define D2DPHY_AGC_MAIN \
    D2D_AGC_PwrRttOm             d2dAgcPwrRttOm; \
    D2D_AGC_ReqRptEn             d2dAgcReqRptEn; \
    D2D_AGC_FixReqPara           d2dAgcFixReqPara; \
    D2D_AGC_WbRssiOm             d2dAgcWbRssiOm; \
    SLL_AGC_HalTraceRpt          d2dAgcTraceLogom; \
    SLL_DEM_HalDfuBuf            d2dAgcDfuTraceLogOm
/* d2dphy sched OM */
#define D2DPHY_SCHED_OM_MAIN \
    enum HL2_HPHY_MsgType          enHL2_HPHY_MsgType; \
    HPHY_HL2_PsschMeasMsg          stHPHY_HL2_PsschMeasMsg; \
    HL2_HPHY_TaConfigMsg           stHL2_HPHY_TaConfigMsg; \
    HL2_HPHY_PscchSendIndMsg       stHL2_HPHY_PscchSendIndMsg;\
    HPHY_HL2_PsbchTaRptMsg         stHPHY_HL2_PsbchTaRptMsg
/* d2dphy proc OM */
#define D2DPHY_PROC_OM_MAIN \
    D2D_WMC_BInfo                D2DWmcBInfo; \
    D2D_WMC_OmRptB               D2DWmcOMRptb; \
    D2D_WMC_ErrorInfo            D2DWmcErr; \
    D2D_WMC_ProcOmRpt            D2DWmcProc; \
    D2D_WMC_AllProcStatusInfo    D2DWmcAllProc; \
    D2D_WMC_WorkMode             D2DWmcWorkMode; \
    D2D_WMC_BData                D2DWmcBData; \
    D2D_WMC_BReqInfo             D2DWmcBReq; \
    D2D_WMC_AgcWorkMode          D2DWmcAgcWorkMode; \
    D2D_WMC_AfcWorkMode          D2DWmcAfcWorkMode; \
    D2D_WMC_TruWorkMode          D2DWmcTruWorkMode; \
    D2D_WMC_FecWorkMode          D2DWmcFecWorkMode; \
    D2D_WMC_BComData             D2DWmcComBData; \
    D2D_WMC_BAgcData             D2DWmcAgcBData; \
    D2D_WMC_BTruData             D2DWmcTruBData; \
    D2D_WMC_BAfcData             D2DWmcAfcBData; \
    D2D_WMC_BFecData             D2DWmcFecBData; \
    D2D_AllCellInfo              D2DAllCellInfo; \
    D2D_WMC_TimeStamp            D2DWmcTimestamp; \
    enum D2D_WMC_ErrorType       enD2DWmcErrType; \
    enum D2D_AGC_WorkModeReq     enD2DAgcWorkMode; \
    enum D2D_AFC_WorkMode        enD2DAfcWorkMode; \
    enum D2D_TRU_WorkMode        enD2DTruWorMode; \
    D2D_PROC_BgsOmRptInfo        stD2D_PROC_BgsOmRptInfo; \
    D2D_PROC_ServeCellInfo       stD2D_PROC_ServeCellInfo; \
    D2D_PROC_SyncSourceListOmRpt stD2D_PROC_SyncSourceListOmRpt; \
    D2D_PROC_SyncSoExpOmInfo     stD2D_PROC_SyncSoExpOmInfo; \
    D2D_PROC_RrcRssiInfo         stD2D_PROC_RrcRssiInfo; \
    D2D_PROC_RrcSnrRsrpRpt       stD2D_PROC_RrcSnrRsrpRpt; \
    D2D_PROC_DtOmRpt             stD2D_PROC_DtOmRpt;\
    D2D_PROC_OmRpt               stD2D_PROC_OmRpt;\
    D2D_PROC_CsuArbOmRptInfo     stD2D_PROC_CsuArbOmRptInfo
/* FEC om */
#define D2DPHY_FEC_OM_MAIN \
    enum D2D_UL_PusChModType    enD2D_UL_ChModTypeUint08; \
    D2D_UL_FecSfrmCtrlInterface d2dFecSfrmCtrlInterface; \
    D2D_FEC_CommBandCcInfo      d2dCommBandCcInfo; \
    V2XL_FEC_DbgComRptInfo      dbgComRptInfo; \
    SLL_FEC_RfDrvEventInfo      d2dlRfDrvEvent; \
    enum NEUN_FEC_CcRxAction_   d2dlEnRxAction; \
    enum NEUN_WMC_FecEffectTime d2dlEnEffTime; \
    enum NEUN_WMC_FecEffectPos  d2dlEnEffPos
/* AFC */
#define D2DPHY_AFC_MAIN \
    D2D_AFC_PeirodOmPara      stD2D_AFC_PeirodOmPara
/* ul om */
#define D2DPHY_UL_OM_MAIN \
    SLL_UL_BbpOmRptInfo       d2dUlOmBbpRptInfo; \
    D2D_UL_OmReqInfo          d2dUlOmReqInfo; \
    D2D_UL_OmPwrStub          d2dulOmPwrStub
/* DL */
#define D2DPHY_DL_MAIN \
    enum D2D_TrigStopType     enD2D_TrigStopType; \
    D2D_DEC_TrigStopStub      d2dDecTrigStopStub; \
    D2D_DEC_DtRpt             d2dDecDtRpt; \
    D2D_DEC_OmRptInfo         stD2D_DEC_OmRptInfo; \
    D2D_DEC_OmPsbRslRpt       stD2D_DEC_OmPsbRslRpt;\
    D2D_DEC_BlerInfoRpt       stD2D_DEC_BlerInfoRpt;\
    D2D_PSCCH_OM_INFO         stD2D_PSCCH_OmInfo
/* tfsync */
#define D2DPHY_TFSYNC_MAIN \
    D2D_TFSYNC_ReqReportEna   stD2D_TFSYNC_Rpt; \
    D2D_SyncModeInterface     stD2D_TFSYNC_TcCalc; \
    D2D_TFSYNC_TcInfo         stD2D_TFSYNC_TcPara; \
    D2D_TRU_Om_LoopInfo       stD2D_TRU_Om_LoopInfo
/* csu */
#define D2DPHY_CSU_MAIN \
    NEUN_CSU_OmCtrl           d2dCsuOmCtrl
/* LPM */
#define D2DPHY_VPHYLPMINTERFACE_MAIN \
    UL1M_SLLPM_MsgHeader        stD2D_UL1M_SLLPM_MsgHeader; \
    UL1M_VPHY_SetWorkModeCnf    stD2D_UL1M_VPHY_SetWorkModeCnf; \
    UPHY_BLKDDRMGR_MemAllocMsg  stD2D_UPHY_MemAllocMsg; \
    UPHY_BLKDDRMGR_MemFreeMsg   stD2D_UPHY_MemFreeMsg
/* RCM */
#define D2DPHY_VPHYRCMINTERFACE_MAIN \
    PHY_RCM_RatmodeInd        stD2D_PHY_RCM_RatmodeInd; \
    PHY_RCM_SuspendRfCnf      stD2D_PHY_RCM_SuspendRfCnf; \
    PHY_RCM_CbtSwitchInd      stD2D_PHY_RCM_CbtSwitchInd; \
    PHY_RCM_TxPowerRptCfgCnf  stD2D_PHY_RCM_TxPowerRptCfgCnf; \
    PHY_RCM_TxPowerInd        stD2D_PHY_RCM_TxPowerInd; \
    PHY_RCM_CarrierApplyReq   stD2D_PHY_RCM_CarrierApplyReq; \
    PHY_RCM_CarrierReleaseInd stD2D_PHY_RCM_CarrierReleaseInd; \
    PHY_RCM_AwakeReq          stD2D_PHY_RCM_AwakeReq; \
    PHY_RCM_SleepReq          stD2D_PHY_RCM_SleepReq
/*LPC*/
#define D2DPHY_LPC_MIAN \
    UL1M_SLLPM_Hl1cSleepCompleteInfo STUL1M_SLLPM_Hl1cSleepCompleteInfo; \
    D2D_L1C_L1D_LpcReq        stD2D_L1C_L1D_LpcReq; \
    D2D_L1D_L1C_LpcCnf        stD2D_L1D_L1C_LpcCnf; \
    D2D_LPC_Hl1cWakeOmInfo    stD2D_LPC_Hl1cWakeOmInfo; \
    D2D_LPC_Hl1cSleepOmInfo   stD2D_LPC_Hl1cSleepOmInfo

#ifdef __cplusplus
}
#endif
#endif /* end of hids_elf_ltevphy.c */

