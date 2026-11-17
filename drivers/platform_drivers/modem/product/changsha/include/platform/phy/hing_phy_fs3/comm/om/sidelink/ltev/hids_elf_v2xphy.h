

#ifndef __HIDS_ELF_V2XPHY_H__
#define __HIDS_ELF_V2XPHY_H__

/*
 * 头文件包含
 */
#include "vrrc_vphy_interface.h"
#include "vmac_phy_interface.h"
#include "vmac_phy_hl1c_interface.h"
#include "lphy_v2x_agc_om_def.h"
#include "lphy_v2x_basedef_struct.h"
#include "lphy_v2x_fec_comm_interface.h"
#include "lphy_v2x_hal_ul_interface.h"
#include "lphy_v2x_ul_fec_interface.h"
#include "lphy_v2x_ul_om_def.h"
#include "lphy_v2x_tfsync_om_def.h"
#include "lphy_v2x_tru_om_def.h"
#include "ul1m_v2x_tfsync_om.h"
#include "lphy_v2x_afc_om_def.h"
#include "neun_csu_om_def.h"
#include "lphy_v2x_dl_om_def.h"
#include "lphy_v2x_wmc_om_def.h"
#include "lphy_v2x_proc_om_def.h"
#include "ul1m_lphy_v2x_dem_om.h"
#include "ul1m_lphy_v2x_agc_om.h"
#include "ul1m_lphy_v2x_proc_om.h"
#include "lphy_v2x_ul_interface.h"
#include "mfg_phy_ct_interface.h"
#include "lphy_v2x_ul_interface.h"
#include "mfg_vphy_nbt_interface.h"
#include "lphy_v2x_hal_feu_interface.h"
#include "ul1m_vphy_interface.h"
#include "ul1m_rcm_tas_interface.h"
#include "ul1m_rcm_dsds1p0_interface.h"
#include "ul1m_rcm_dcxo_interface.h"
#include "ul1m_rcm_agent_interface.h"
#include "ul1m_rcm_crm_interface.h"
#include "ul1m_rcm_base_interface.h"
#include "uphy_blkddrmgr_interface.h"
#include "lphy_v2x_hal_dem_interface.h"
#ifdef __cplusplus
extern "C" {
#endif

/* v2x vrrcPhyInterface.h */
#define LTEVPHY_VRRCPHYINTERFACE_MAIN \
    enum VRRC_VPHY_HoResult           enVrrcVphyHoResult; \
    VRRC_VPHY_MsgTypeUint32           enVRRC_VPHY_MsgTypeUint32; \
    VRRC_VPHY_V2xWorkModeTypeUint16   enVRRC_VPHY_V2xWorkModeTypeUint16; \
    VRRC_VPHY_ResultUint16            enVRRC_VPHY_ResultUint16; \
    VRRC_VPHY_V2xSystemParaCnf        stVRRC_VPHY_V2xSystemParaCnf; \
    VRRC_VPHY_V2xResPoolConfigCnf     stVRRC_VPHY_V2xResPoolConfigCnf; \
    VRRC_VPHY_V2xSetWorkModeCnf       stVRRC_VPHY_V2xSetWorkModeCnf; \
    VRRC_VPHY_V2xInitSearchStartCnf   stVRRC_VPHY_V2xInitSearchStartCnf; \
    VRRC_VPHY_V2xInitSearchStopCnf    stVRRC_VPHY_V2xInitSearchStopCnf; \
    VRRC_VPHY_V2xRefUeInfo            stVRRC_VPHY_V2xRefUeInfo; \
    VRRC_VPHY_V2xRefFreqInfo          stVRRC_VPHY_V2xRefFreqInfo; \
    VRRC_VPHY_V2xSearchResultInfo     stVRRC_VPHY_V2xSearchResultInfo; \
    VRRC_VPHY_V2xSearchRsltInd        stVRRC_VPHY_V2xSearchRsltInd; \
    VRRC_VPHY_V2xPeriodSearchStartCnf stVRRC_VPHY_V2xPeriodSearchStartCnf; \
    VRRC_VPHY_V2xPeriodSearchStopCnf  stVRRC_VPHY_V2xPeriodSearchStopCnf; \
    VRRC_VPHY_V2xSyncSourceHoCnf      stVRRC_VPHY_V2xSyncSourceHoCnf; \
    VRRC_VPHY_V2xGnssStateCnf         stVRRC_VPHY_V2xGnssStateCnf; \
    VRRC_VPHY_V2x1ppsStatusInd        stVRRC_VPHY_V2x1ppsStatusInd; \
    VRRC_VPHY_V2xParaCheckCnf         stVRRC_VPHY_V2xParaCheckCnf; \
    VRRC_VPHY_V2xGnssSyncRsltInd      stVRRC_VPHY_V2xGnssSyncRsltInd;\
    VRRC_VPHY_V2xUtcResetCnf          stVRRC_VPHY_V2xUtcResetCnf
/* AGC */
#define LTEVPHY_AGC_MAIN \
    LPHY_V2X_AGC_PwrRttOm             agcPwrRttOm; \
    LPHY_V2X_AGC_ReqRptEn             agcReqRptEn; \
    LPHY_V2X_AGC_FixReqPara           agcFixReqPara; \
    LPHY_V2X_AGC_WbRssiOm             agcWbRssiOm; \
    SLL_AGC_HalTraceRpt               agcTraceLogom; \
    SLL_DEM_HalDfuBuf                 agcDfuTraceLogOm
/* ltevphy sched OM */
#define LTEVPHY_SCHED_OM_MAIN \
    enum VMAC_VPHY_MsgType            enVMAC_VPHY_MsgType; \
    VPHY_VMAC_RecMsg                  stLPHY_V2X_MAC_RecMsg; \
    VMAC_VPHY_PsschStartReqMsg        stVMAC_VPHY_PsschStartReqMsg; \
    VMAC_VPHY_PsschStopIndMsg         stVMAC_VPHY_PsschStopIndMsg
/* ltevphy proc OM */
#define LTEVPHY_PROC_OM_MAIN \
    LPHY_V2X_WMC_BInfo                lphyV2xWmcBInfo; \
    LPHY_V2X_WMC_OmRptB               lphyV2xWmcOMRptb; \
    LPHY_V2X_WMC_ErrorInfo            lphyV2xWmcErr; \
    LPHY_V2X_WMC_ProcOmRpt            lphyV2xWmcProc; \
    LPHY_V2X_WMC_AllProcStatusInfo    lphyV2xWmcAllProc; \
    LPHY_V2X_WMC_WorkMode             lphyV2xWmcWorkMode; \
    LPHY_V2X_WMC_BData                lphyV2xWmcBData; \
    LPHY_V2X_WMC_BReqInfo             lphyV2xWmcBReq; \
    LPHY_V2X_WMC_AgcWorkMode          lphyV2xWmcAgcWorkMode; \
    LPHY_V2X_WMC_AfcWorkMode          lphyV2xWmcAfcWorkMode; \
    LPHY_V2X_WMC_TruWorkMode          lphyV2xWmcTruWorkMode; \
    LPHY_V2X_WMC_FecWorkMode          lphyV2xWmcFecWorkMode; \
    LPHY_V2X_WMC_BComData             lphyV2xWmcComBData; \
    LPHY_V2X_WMC_BAgcData             lphyV2xWmcAgcBData; \
    LPHY_V2X_WMC_BTruData             lphyV2xWmcTruBData; \
    LPHY_V2X_WMC_BAfcData             lphyV2xWmcAfcBData; \
    LPHY_V2X_WMC_BFecData             lphyV2xWmcFecBData; \
    LPHY_V2X_AllCellInfo              lphyV2xAllCellInfo; \
    LPHY_V2X_WMC_TimeStamp            lphyV2xWmcTimestamp; \
    enum LPHY_V2X_WMC_ErrorType       enlphyV2xWmcErrType; \
    enum LPHY_V2X_AGC_WorkModeReq     enLphyV2xAgcWorkMode; \
    enum LPHY_V2X_AFC_WorkMode        enLphyV2xAfcWorkMode; \
    enum LPHY_V2X_TRU_WorkMode        enLphyV2xTruWorMode; \
    LPHY_V2X_PROC_BgsOmRptInfo        stLPHY_V2X_PROC_BgsOmRptInfo; \
    LPHY_V2X_PROC_ServeCellInfo       stLPHY_V2X_PROC_ServeCellInfo; \
    LPHY_V2X_PROC_SyncSourceListOmRpt stLPHY_V2X_PROC_SyncSourceListOmRpt; \
    LPHY_V2X_PROC_SyncSoExpOmInfo     stLPHY_V2X_PROC_SyncSoExpOmInfo; \
    LPHY_V2X_PROC_RrcRssiInfo         stLPHY_V2X_PROC_RrcRssiInfo; \
    LPHY_V2X_PROC_RrcSnrRsrpRpt       stLPHY_V2X_PROC_RrcSnrRsrpRpt; \
    LPHY_V2X_PROC_DtOmRpt             stLPHY_V2X_PROC_DtOmRpt; \
    PHY_NBT_LoadCcNvCnf               stPHY_NBT_LoadCcNvCnf;\
    PHY_NBT_TrxTestCnf                stPHY_NBT_TrxTestCnf;\
    PHY_MFG_CalMsgCnf                 stPHY_MFG_CalMsgCnf
/* FEC om */
#define LTEVPHY_FEC_OM_MAIN \
    enum LPHY_V2X_UL_PusChModType     enLPHY_V2X_UL_ChModTypeUint08; \
    LPHY_V2X_UL_FecSfrmCtrlInterface  fecSfrmCtrlInterface; \
    SLL_FEC_RfDrvEventInfo            v2xlRfDrvEvent; \
    enum NEUN_FEC_CcRxAction_         enRxAction; \
    enum NEUN_WMC_FecEffectTime       enEffTime; \
    enum NEUN_WMC_FecEffectPos        enEffPos
/* AFC */
#define LTEVPHY_AFC_MAIN \
    LPHY_V2X_AFC_PeirodOmPara      stLPHY_V2X_AFC_PeirodOmPara
/* ul om */
#define LTEVPHY_UL_OM_MAIN \
    SLL_UL_BbpOmRptInfo            v2xlUlOmBbpRptInfo; \
    LPHY_V2X_UL_OmReqInfo          ulOmReqInfo; \
    LPHY_V2X_UL_OmPwrStub          ulOmPwrStub
/* DL */
#define LTEVPHY_DL_MAIN \
    enum LPHY_V2X_TrigStopType     enLPHY_V2X_TrigStopType; \
    LPHY_V2X_DEC_TrigStopStub      lphyV2xDecTrigStopStub; \
    LPHY_V2X_DEC_DtRpt             decDtRpt; \
    LPHY_V2X_DEC_OmRptInfo         stLPHY_V2X_DEC_OmRptInfo; \
    LPHY_V2X_DEC_OmPsbRslRpt       stLPHY_V2X_DEC_OmPsbRslRpt; \
    LPHY_V2X_DEC_DfxBbpStub        v2xlDecDfxBbpStub
/* tfsync */
#define LTEVPHY_TFSYNC_MAIN \
    enum LPHY_V2X_GnssErrCode      enLPHY_V2X_GnssErrCode; \
    enum LPHY_V2X_GnssState        enLPHY_V2X_GnssState; \
    enum LPHY_V2X_RcvUtcPps        enLPHY_V2X_RcvUtcPps; \
    LPHY_V2X_TFSYNC_ReqReportEna   stLPHY_V2x_TFSYNC_Rpt; \
    LPHY_V2X_GNSS_Handle           stLPHY_V2X_TFSYNC_PpsPara; \
    LPHY_V2X_GNSS_Handle           stLPHY_V2X_TFSYNC_UtcPara; \
    LPHY_V2X_SyncModeInterface     stLPHY_V2X_TFSYNC_GnssCalc; \
    LPHY_V2X_SyncModeInterface     stLPHY_V2X_TFSYNC_TcCalc; \
    LPHY_V2X_TFSYNC_TcInfo         stLPHY_V2X_TFSYNC_TcPara; \
    LPHY_V2X_GnssErrorOmInfo       stLPHY_V2X_GnssErrorOmInfo; \
    LPHY_V2X_TRU_Om_LoopInfo       stLPHY_V2X_TRU_Om_LoopInfo
/* csu */
#define LTEVPHY_CSU_MAIN \
    NEUN_CSU_OmCtrl                v2xlCsuOmCtrl
/* LPM */
#define LTEVPHY_VPHYLPMINTERFACE_MAIN \
    UL1M_SLLPM_MsgHeader            stLPHY_V2X_UL1M_SLLPM_MsgHeader; \
    UL1M_VPHY_SetWorkModeCnf        stLPHY_V2X_VPHY_SetWorkModeCnf; \
    UPHY_BLKDDRMGR_MemAllocMsg      stV2X_UPHY_MemAllocMsg; \
    UPHY_BLKDDRMGR_MemFreeMsg       stV2X_UPHY_MemFreeMsg
/* RCM */
#define LTEVPHY_VPHYRCMINTERFACE_MAIN \
    PHY_RCM_RatmodeInd              stLPHY_V2X_PHY_RCM_RatmodeInd; \
    PHY_RCM_SuspendRfCnf            stLPHY_V2X_PHY_RCM_SuspendRfCnf; \
    PHY_RCM_CbtSwitchInd            stLPHY_V2X_PHY_RCM_CbtSwitchInd; \
    PHY_RCM_TxPowerRptCfgCnf        stLPHY_V2X_PHY_RCM_TxPowerRptCfgCnf; \
    PHY_RCM_TxPowerInd              stLPHY_V2X_PHY_RCM_TxPowerInd; \
    PHY_RCM_CarrierApplyReq         stLPHY_V2X_PHY_RCM_CarrierApplyReq; \
    PHY_RCM_CarrierReleaseInd       stLPHY_V2X_PHY_RCM_CarrierReleaseInd; \
    PHY_RCM_AwakeReq                stLPHY_V2X_PHY_RCM_AwakeReq; \
    PHY_RCM_SleepReq                stLPHY_V2X_PHY_RCM_SleepReq

#ifdef __cplusplus
}
#endif
#endif /* end of hids_elf_ltevphy.c */

