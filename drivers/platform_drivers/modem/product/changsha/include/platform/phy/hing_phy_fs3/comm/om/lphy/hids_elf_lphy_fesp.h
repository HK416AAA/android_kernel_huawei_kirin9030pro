
#ifndef HIDS_ELF_LPHY_FESP_H
#define HIDS_ELF_LPHY_FESP_H


/*
 * 1 其他头文件包含
 */
#include "lphy_feature.h"
#include "lphy_basedef_enum.h"
#include "lphy_basedef_struct.h"
#include "lphy_dl_tfcomm_interface.h"
#include "ul1m_lphy_tfsync_om.h"
#include "ul1m_neun_tfpara_om.h"
#include "lphy_dl_tfsync_interface.h"
#include "lphy_dl_tru_interface.h"
#include "neun_hal_dl_feu_interface.h"
#include "lphy_tru_om_def.h"
#include "lphy_fec_comm_interface.h"
#include "lphy_fec_om_def.h"
#include "lphy_tfpara_om_def.h"
#include "lphy_agc_om_def.h"
#include "lphy_tfsync_om_def.h"
#include "lphy_hal_dl_agc_interface.h"
#include "ul1m_lphy_cycle_om.h"
#include "neun_ll1d_tfsync_win_interface.h"
#include "lphy_fed_tx_om_interface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/* TFSYNC */
#define LPHY_TFSYNC_MAIN \
    enum LPHY_TFSYNC_IcWorkMode      lphyTfsyncicWorkModeUint08; \
    enum LPHY_TFSYNC_WorkState       lphyTfsyncWorkStateUint8; \
    enum LPHY_TFSYNC_BusyState       lphyTfsyncBusyStaeUint8; \
    enum NEUN_TFSYNC_StableLevel     lphyTfsyncStableLevelUint8; \
    LPHY_TFSYNC_ReqRptEn             lphyTfsyncReqRptEn; \
    LPHY_TFSYNC_IcOmRpt              lphyTfsyncIcOmRpt; \
    LPHY_TFSYNC_CtrlRptInfo          lphyTfsyncCtrlInfo;\
    LPHY_TFSYNC_DataValid            dataValid; \
    LPHY_TFSYNC_SubFrmInfo           subFrmStateInfo; \
    LPHY_TRU_SssPara                 lphyTruSssPara;
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
    LPHY_AGC_BsBackupBuf         agcBsBackup; \
    LPHY_AGC_IntraBackupBuf      agcIntraBackup; \
    LPHY_AGC_InterBackupBuf      agcInterBackup;

/* FEC om */
#define LPHY_FEC_MAIN \
    LPHY_FEC_OmCcReqInfo         ccReqInfo; \
    LPHY_UL_FecSfrmCtrlInterface FecSfrmCtrlInterface;\
    LPHY_FEC_TxOmInfo            TxOmInfo;

/* lphy cycle begin */
#define LPHY_CYCLE_MAIN_BASE \
    LPHY_OM_Ml1cCycleRpt          cycleMl1cRpt
/* lphy cycle end */


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* end of hids_elf_lphy.c */

