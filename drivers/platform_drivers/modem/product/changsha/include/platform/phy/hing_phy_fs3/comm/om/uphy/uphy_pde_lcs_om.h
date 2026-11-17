

#ifndef __UPHY_PDE_LCS_OM_H__
#define __UPHY_PDE_LCS_OM_H__

#include "uphy_pde_common_om.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

typedef union {
    struct {
        unsigned int task_mode                                        :   8               ;    /* 7:0 */
        unsigned int task_rsc_cnt                                     :   8               ;    /* 15:8 */
        unsigned int task_rep_cnt                                     :   8               ;    /* 23:16 */
        unsigned int task_atom_cnt                                    :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} LCS_SID_LCS_TOP_IN_SUB0;

typedef union {
    struct {
        unsigned int lcs_gdc_idx                                      :   8               ;    /* 7:0 */
        unsigned int m_factor                                         :   8               ;    /* 15:8 */
        unsigned int ifft_factor                                      :   8               ;    /* 23:16 */
        unsigned int comb_type                                        :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} LCS_SID_LCS_TOP_IN_SUB1;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    LCS_SID_LCS_TOP_IN_SUB0                                           om_data0;
    LCS_SID_LCS_TOP_IN_SUB1                                           om_data1;
} LCS_SID_LCS_TOP_IN;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LCS_SID_LCS_TOP_IN_SUB0                                           om_data0;
    LCS_SID_LCS_TOP_IN_SUB1                                           om_data1;
} LCS_SID_LCS_TOP_IN_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      lcs_add_task_flag;
    unsigned int                                                      rsv_0;
} LCS_SID_LCS_TOP_OUT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      lcs_add_task_flag;
    unsigned int                                                      rsv_0;
} LCS_SID_LCS_TOP_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int next_task_mode                                   :   8               ;    /* 7:0 */
        unsigned int next_task_rsc_cnt                                :   8               ;    /* 15:8 */
        unsigned int next_task_rep_cnt                                :   8               ;    /* 23:16 */
        unsigned int next_task_atom_cnt                               :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} LCS_SID_LCS_ACCU_OUT_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    LCS_SID_LCS_ACCU_OUT_SUB0                                         om_data0;
    unsigned int                                                      rsv_0;
} LCS_SID_LCS_ACCU_OUT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LCS_SID_LCS_ACCU_OUT_SUB0                                         om_data0;
    unsigned int                                                      rsv_0;
} LCS_SID_LCS_ACCU_OUT_BBP_MC;

typedef union {
    struct {
        unsigned int next_task_mode                                   :   8               ;    /* 7:0 */
        unsigned int next_task_rsc_cnt                                :   8               ;    /* 15:8 */
        unsigned int next_task_rep_cnt                                :   8               ;    /* 23:16 */
        unsigned int next_task_atom_cnt                               :   8               ;    /* 31:24 */
    } bits;
    unsigned int u32;
} LCS_SID_LCS_RUF_OUT_SUB0;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    LCS_SID_LCS_RUF_OUT_SUB0                                          om_data0;
    unsigned int                                                      rsv_0;
} LCS_SID_LCS_RUF_OUT;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    LCS_SID_LCS_RUF_OUT_SUB0                                          om_data0;
    unsigned int                                                      rsv_0;
} LCS_SID_LCS_RUF_OUT_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      noise_mean_r0;
    unsigned int                                                      noise_mean_r1;
} LCS_SID_LCS_ACCU_NOISE;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      noise_mean_r0;
    unsigned int                                                      noise_mean_r1;
} LCS_SID_LCS_ACCU_NOISE_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      noise_mean_r0;
    unsigned int                                                      noise_mean_r1;
} LCS_SID_LCS_RUF_NOISE;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      noise_mean_r0;
    unsigned int                                                      noise_mean_r1;
} LCS_SID_LCS_RUF_NOISE_BBP_MC;


typedef struct {
    U_BBP_SST_NL                                                      pde_sst;
    unsigned int                                                      ruf_base_addr;
    unsigned int                                                      accu_base_addr;
} LCS_SID_LCS_DIF;


typedef struct {
    unsigned int                                                      bbp_mc_cnt;
    unsigned int                                                      ruf_base_addr;
    unsigned int                                                      accu_base_addr;
} LCS_SID_LCS_DIF_BBP_MC;


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
} LCS_SID_LCS_DDR_DATA;


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
} LCS_SID_LCS_DDR_DATA_BBP_MC;


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
} LCS_SID_LCS_RUF_MRC_DATA;


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
} LCS_SID_LCS_RUF_MRC_DATA_BBP_MC;


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
} LCS_SID_LCS_RX0_CIR_DATA;


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
} LCS_SID_LCS_RX0_CIR_DATA_BBP_MC;


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
} LCS_SID_LCS_RX1_CIR_DATA;


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
} LCS_SID_LCS_RX1_CIR_DATA_BBP_MC;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
