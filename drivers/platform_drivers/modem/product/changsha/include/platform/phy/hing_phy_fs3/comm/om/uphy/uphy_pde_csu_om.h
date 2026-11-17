

#ifndef __UPHY_PDE_CSU_OM_H__
#define __UPHY_PDE_CSU_OM_H__

#include "uphy_pde_common_om.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

typedef union {
    struct {
        unsigned int cmd_type_idx                                     :   8               ;    /* 7:0 */
        unsigned int task_rsc_num                                     :   8               ;    /* 15:8 */
        unsigned int task_proc_cnt                                    :   8               ;    /* 23:16 */
        unsigned int task_atom_cnt                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} CSU_SID_CSU_TOP_IN_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      pdma_id;
    CSU_SID_CSU_TOP_IN_SUB1                                           om_data1;
} CSU_SID_CSU_TOP_IN;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      pdma_id;
    CSU_SID_CSU_TOP_IN_SUB1                                           om_data1;
} CSU_SID_CSU_TOP_IN_BBP_MC;

typedef union {
    struct {
        unsigned int task_proc_cnt                                    :   8               ;    /* 7:0 */
        unsigned int task_atom_cnt                                    :   8               ;    /* 15:8 */
        unsigned int task_step1_suc                                   :   8               ;    /* 23:16 */
        unsigned int task_ic2_idx                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} CSU_SID_CSU_TOP_OUT_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      csu_add_task_flag;
    CSU_SID_CSU_TOP_OUT_SUB1                                          om_data1;
} CSU_SID_CSU_TOP_OUT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      csu_add_task_flag;
    CSU_SID_CSU_TOP_OUT_SUB1                                          om_data1;
} CSU_SID_CSU_TOP_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int cmd_type_idx                                     :   8               ;    /* 7:0 */
        unsigned int task_rsc_num                                     :   8               ;    /* 15:8 */
        unsigned int cmd_modem_idx                                    :   8               ;    /* 23:16 */
        unsigned int rsv_0                                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} CSU_SID_CSU_IC_TOP_IN_SUB0;

typedef union {
    struct {
        unsigned int task_proc_cnt                                    :   8               ;    /* 7:0 */
        unsigned int task_atom_cnt                                    :   8               ;    /* 15:8 */
        unsigned int task_step1_suc                                   :   8               ;    /* 23:16 */
        unsigned int task_ic2_idx                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} CSU_SID_CSU_IC_TOP_IN_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    CSU_SID_CSU_IC_TOP_IN_SUB0                                        om_data0;
    CSU_SID_CSU_IC_TOP_IN_SUB1                                        om_data1;
} CSU_SID_CSU_IC_TOP_IN;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    CSU_SID_CSU_IC_TOP_IN_SUB0                                        om_data0;
    CSU_SID_CSU_IC_TOP_IN_SUB1                                        om_data1;
} CSU_SID_CSU_IC_TOP_IN_BBP_MC;

typedef union {
    struct {
        unsigned int cmd_type_idx                                     :   8               ;    /* 7:0 */
        unsigned int task_rsc_num                                     :   8               ;    /* 15:8 */
        unsigned int cmd_modem_idx                                    :   8               ;    /* 23:16 */
        unsigned int rsv_0                                            :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} CSU_SID_CSU_RSSI_TOP_IN_SUB0;

typedef union {
    struct {
        unsigned int task_proc_cnt                                    :   8               ;    /* 7:0 */
        unsigned int task_atom_cnt                                    :   8               ;    /* 15:8 */
        unsigned int task_step1_suc                                   :   8               ;    /* 23:16 */
        unsigned int task_ic2_idx                                     :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} CSU_SID_CSU_RSSI_TOP_IN_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    CSU_SID_CSU_RSSI_TOP_IN_SUB0                                      om_data0;
    CSU_SID_CSU_RSSI_TOP_IN_SUB1                                      om_data1;
} CSU_SID_CSU_RSSI_TOP_IN;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    CSU_SID_CSU_RSSI_TOP_IN_SUB0                                      om_data0;
    CSU_SID_CSU_RSSI_TOP_IN_SUB1                                      om_data1;
} CSU_SID_CSU_RSSI_TOP_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      task_cnt;
    unsigned int                                                      cmd_type_idx;
} CSU_SID_CSU_NR_STEP2_IN;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      task_cnt;
    unsigned int                                                      cmd_type_idx;
} CSU_SID_CSU_NR_STEP2_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      task_cnt;
    unsigned int                                                      cmd_type_idx;
} CSU_SID_CSU_LTE_STEP2_IN;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      task_cnt;
    unsigned int                                                      cmd_type_idx;
} CSU_SID_CSU_LTE_STEP2_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      task_cnt;
    unsigned int                                                      task_atom_cnt;
} CSU_SID_CSU_LTEV_STEP2_IN;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      task_cnt;
    unsigned int                                                      task_atom_cnt;
} CSU_SID_CSU_LTEV_STEP2_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      rsv_0;
    unsigned int                                                      task_cnt;
} CSU_SID_CSU_NR_IC_CANCEL_IN;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      rsv_0;
    unsigned int                                                      task_cnt;
} CSU_SID_CSU_NR_IC_CANCEL_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      ic_cell_num;
    unsigned int                                                      cmd_type_idx;
} CSU_SID_CSU_LTE_IC_CANCEL_IN;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ic_cell_num;
    unsigned int                                                      cmd_type_idx;
} CSU_SID_CSU_LTE_IC_CANCEL_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      ic_step1_cell_num;
    unsigned int                                                      rsv_0;
} CSU_SID_CSU_IC_STEP1_OUT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ic_step1_cell_num;
    unsigned int                                                      rsv_0;
} CSU_SID_CSU_IC_STEP1_OUT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      base_addr_rx0;
    unsigned int                                                      ssb_pos;
} CSU_SID_CSU_DIF_IN;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      base_addr_rx0;
    unsigned int                                                      ssb_pos;
} CSU_SID_CSU_DIF_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
} CSU_SID_CSU_DBG0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
} CSU_SID_CSU_DBG0_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
} CSU_SID_CSU_DBG1;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
} CSU_SID_CSU_DBG1_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
} CSU_SID_CSU_DBG2;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
} CSU_SID_CSU_DBG2_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
} CSU_SID_CSU_DBG3;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
} CSU_SID_CSU_DBG3_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
} CSU_SID_CSU_DBG4;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
} CSU_SID_CSU_DBG4_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
} CSU_SID_CSU_DBG5;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
} CSU_SID_CSU_DBG5_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} CSU_SID_CSU_ALG_RPT0;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      data0;
    unsigned int                                                      data1;
    unsigned int                                                      data2;
    unsigned int                                                      data3;
    unsigned int                                                      data4;
    unsigned int                                                      data5;
    unsigned int                                                      data6;
    unsigned int                                                      data7;
    unsigned int                                                      data8;
    unsigned int                                                      data9;
    unsigned int                                                      data10;
    unsigned int                                                      data11;
    unsigned int                                                      data12;
    unsigned int                                                      data13;
    unsigned int                                                      data14;
    unsigned int                                                      data15;
    unsigned int                                                      data16;
    unsigned int                                                      data17;
    unsigned int                                                      data18;
    unsigned int                                                      data19;
    unsigned int                                                      data20;
    unsigned int                                                      data21;
    unsigned int                                                      data22;
    unsigned int                                                      data23;
    unsigned int                                                      data24;
    unsigned int                                                      data25;
    unsigned int                                                      data26;
    unsigned int                                                      data27;
    unsigned int                                                      data28;
    unsigned int                                                      data29;
    unsigned int                                                      data30;
    unsigned int                                                      data31;
    unsigned int                                                      data32;
    unsigned int                                                      data33;
    unsigned int                                                      data34;
    unsigned int                                                      data35;
    unsigned int                                                      data36;
    unsigned int                                                      data37;
    unsigned int                                                      data38;
    unsigned int                                                      data39;
    unsigned int                                                      data40;
    unsigned int                                                      data41;
    unsigned int                                                      data42;
    unsigned int                                                      data43;
    unsigned int                                                      data44;
    unsigned int                                                      data45;
    unsigned int                                                      data46;
    unsigned int                                                      data47;
    unsigned int                                                      data48;
    unsigned int                                                      data49;
    unsigned int                                                      data50;
    unsigned int                                                      data51;
    unsigned int                                                      data52;
    unsigned int                                                      data53;
    unsigned int                                                      data54;
    unsigned int                                                      data55;
    unsigned int                                                      data56;
    unsigned int                                                      data57;
    unsigned int                                                      data58;
    unsigned int                                                      data59;
    unsigned int                                                      data60;
    unsigned int                                                      data61;
    unsigned int                                                      data62;
    unsigned int                                                      data63;
    unsigned int                                                      data64;
    unsigned int                                                      data65;
    unsigned int                                                      data66;
    unsigned int                                                      data67;
    unsigned int                                                      data68;
    unsigned int                                                      data69;
    unsigned int                                                      data70;
    unsigned int                                                      data71;
    unsigned int                                                      data72;
    unsigned int                                                      data73;
    unsigned int                                                      data74;
    unsigned int                                                      data75;
    unsigned int                                                      data76;
    unsigned int                                                      data77;
    unsigned int                                                      data78;
    unsigned int                                                      data79;
    unsigned int                                                      data80;
    unsigned int                                                      data81;
    unsigned int                                                      data82;
    unsigned int                                                      data83;
    unsigned int                                                      data84;
    unsigned int                                                      data85;
    unsigned int                                                      data86;
    unsigned int                                                      data87;
    unsigned int                                                      data88;
    unsigned int                                                      data89;
    unsigned int                                                      data90;
    unsigned int                                                      data91;
    unsigned int                                                      data92;
    unsigned int                                                      data93;
    unsigned int                                                      data94;
    unsigned int                                                      data95;
    unsigned int                                                      data96;
    unsigned int                                                      data97;
    unsigned int                                                      data98;
    unsigned int                                                      data99;
    unsigned int                                                      data100;
    unsigned int                                                      data101;
    unsigned int                                                      data102;
    unsigned int                                                      data103;
    unsigned int                                                      data104;
    unsigned int                                                      data105;
    unsigned int                                                      data106;
    unsigned int                                                      data107;
    unsigned int                                                      data108;
    unsigned int                                                      data109;
    unsigned int                                                      data110;
    unsigned int                                                      data111;
    unsigned int                                                      data112;
    unsigned int                                                      data113;
    unsigned int                                                      data114;
    unsigned int                                                      data115;
    unsigned int                                                      data116;
    unsigned int                                                      data117;
    unsigned int                                                      data118;
    unsigned int                                                      data119;
    unsigned int                                                      data120;
    unsigned int                                                      data121;
    unsigned int                                                      data122;
    unsigned int                                                      data123;
    unsigned int                                                      data124;
    unsigned int                                                      data125;
    unsigned int                                                      data126;
    unsigned int                                                      data127;
} CSU_SID_CSU_ALG_RPT0_BBP_MC;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
