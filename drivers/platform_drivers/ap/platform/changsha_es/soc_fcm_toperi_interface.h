#ifndef __SOC_FCM_TOPERI_INTERFACE_H__
#define __SOC_FCM_TOPERI_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_FCM_TOPERI_FCM_BASE_CFG1_ADDR(base) ((base) + (0x800UL))
#define SOC_FCM_TOPERI_FCM_CSSYS_MEM_CTL_ADDR(base) ((base) + (0x804UL))
#define SOC_FCM_TOPERI_FCM_CLUSTER_PCHANNEL_CFG_ADDR(base) ((base) + (0x81CUL))
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_MEM_CTRL_LP_ADDR(base) ((base) + (0x820UL))
#define SOC_FCM_TOPERI_FCM_CORE0_PCHANNEL_CFG_ADDR(base) ((base) + (0x824UL))
#define SOC_FCM_TOPERI_FCM_CORE1_PCHANNEL_CFG_ADDR(base) ((base) + (0x828UL))
#define SOC_FCM_TOPERI_FCM_CORE2_PCHANNEL_CFG_ADDR(base) ((base) + (0x82CUL))
#define SOC_FCM_TOPERI_FCM_CORE3_PCHANNEL_CFG_ADDR(base) ((base) + (0x830UL))
#define SOC_FCM_TOPERI_FCM_CORE4_PCHANNEL_CFG_ADDR(base) ((base) + (0x834UL))
#define SOC_FCM_TOPERI_FCM_CORE5_PCHANNEL_CFG_ADDR(base) ((base) + (0x838UL))
#define SOC_FCM_TOPERI_FCM_CORE6_PCHANNEL_CFG_ADDR(base) ((base) + (0x83CUL))
#define SOC_FCM_TOPERI_FCM_CORE7_PCHANNEL_CFG_ADDR(base) ((base) + (0x840UL))
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_DATARAM_WAY_0_15_MEM_TEST_ADDR(base) ((base) + (0x844UL))
#define SOC_FCM_TOPERI_CORE_MEM_LP_CTL_ADDR(base) ((base) + (0x850UL))
#define SOC_FCM_TOPERI_CLUSTER_MEM_LP_CTL_ADDR(base) ((base) + (0x854UL))
#define SOC_FCM_TOPERI_FCM_PCHANNEL_CFG_REG_ADDR(base) ((base) + (0x870UL))
#define SOC_FCM_TOPERI_FCM_CORE01_PCHANNEL_CFG_REG_ADDR(base) ((base) + (0x874UL))
#define SOC_FCM_TOPERI_FCM_CORE23_PCHANNEL_CFG_REG_ADDR(base) ((base) + (0x878UL))
#define SOC_FCM_TOPERI_FCM_CORE45_PCHANNEL_CFG_REG_ADDR(base) ((base) + (0x87CUL))
#define SOC_FCM_TOPERI_FCM_CORE67_PCHANNEL_CFG_REG_ADDR(base) ((base) + (0x880UL))
#define SOC_FCM_TOPERI_LPM3_FORCE_FLUSH_CACHE_CFG_REG_ADDR(base) ((base) + (0x888UL))
#define SOC_FCM_TOPERI_LPM3_FORCE_OFF_TO_ON_CFG_REG_ADDR(base) ((base) + (0x88CUL))
#define SOC_FCM_TOPERI_FCM_P_CHANNEL_DISABLE_OFF_CFG_REG_ADDR(base) ((base) + (0x890UL))
#define SOC_FCM_TOPERI_CORE_HCTP_MEM_ADJUST_REG_ADDR(base) ((base) + (0x8C4UL))
#define SOC_FCM_TOPERI_CORE_HDTP_MEM_ADJUST_REG_ADDR(base) ((base) + (0x8C8UL))
#define SOC_FCM_TOPERI_FCM_NOC_NSAID_MID_ADDR(base) ((base) + (0x8E4UL))
#define SOC_FCM_TOPERI_KARMA_PCR_SD_CTRL_ADDR(base) ((base) + (0x8F0UL))
#define SOC_FCM_TOPERI_KARMA_PCR_FVT_MEM_CTRL_ADDR(base) ((base) + (0x8F4UL))
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT0_ADDR(base) ((base) + (0xC00UL))
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT2_ADDR(base) ((base) + (0xC08UL))
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT3_ADDR(base) ((base) + (0xC0CUL))
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT4_ADDR(base) ((base) + (0xC10UL))
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT5_ADDR(base) ((base) + (0xC14UL))
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT6_ADDR(base) ((base) + (0xC18UL))
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT7_ADDR(base) ((base) + (0xC1CUL))
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT8_ADDR(base) ((base) + (0xC20UL))
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT9_ADDR(base) ((base) + (0xC24UL))
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT10_ADDR(base) ((base) + (0xC28UL))
#define SOC_FCM_TOPERI_FCM_PCHANNEL_STAT_ADDR(base) ((base) + (0xC30UL))
#define SOC_FCM_TOPERI_FCM_CORE0_PCHANNEL_STAT_ADDR(base) ((base) + (0xC34UL))
#define SOC_FCM_TOPERI_FCM_CORE1_PCHANNEL_STAT_ADDR(base) ((base) + (0xC38UL))
#define SOC_FCM_TOPERI_FCM_CORE2_PCHANNEL_STAT_ADDR(base) ((base) + (0xC3CUL))
#define SOC_FCM_TOPERI_FCM_CORE3_PCHANNEL_STAT_ADDR(base) ((base) + (0xC40UL))
#define SOC_FCM_TOPERI_FCM_CORE4_PCHANNEL_STAT_ADDR(base) ((base) + (0xC44UL))
#define SOC_FCM_TOPERI_FCM_CORE5_PCHANNEL_STAT_ADDR(base) ((base) + (0xC48UL))
#define SOC_FCM_TOPERI_FCM_CORE6_PCHANNEL_STAT_ADDR(base) ((base) + (0xC4CUL))
#define SOC_FCM_TOPERI_FCM_CORE7_PCHANNEL_STAT_ADDR(base) ((base) + (0xC50UL))
#define SOC_FCM_TOPERI_FCM_CORE01_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + (0xC6CUL))
#define SOC_FCM_TOPERI_FCM_CORE23_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + (0xC70UL))
#define SOC_FCM_TOPERI_FCM_CORE45_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + (0xC74UL))
#define SOC_FCM_TOPERI_FCM_CORE67_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + (0xC78UL))
#define SOC_FCM_TOPERI_FCM_FCM_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + (0xC7CUL))
#else
#define SOC_FCM_TOPERI_FCM_BASE_CFG1_ADDR(base) ((base) + (0x800))
#define SOC_FCM_TOPERI_FCM_CSSYS_MEM_CTL_ADDR(base) ((base) + (0x804))
#define SOC_FCM_TOPERI_FCM_CLUSTER_PCHANNEL_CFG_ADDR(base) ((base) + (0x81C))
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_MEM_CTRL_LP_ADDR(base) ((base) + (0x820))
#define SOC_FCM_TOPERI_FCM_CORE0_PCHANNEL_CFG_ADDR(base) ((base) + (0x824))
#define SOC_FCM_TOPERI_FCM_CORE1_PCHANNEL_CFG_ADDR(base) ((base) + (0x828))
#define SOC_FCM_TOPERI_FCM_CORE2_PCHANNEL_CFG_ADDR(base) ((base) + (0x82C))
#define SOC_FCM_TOPERI_FCM_CORE3_PCHANNEL_CFG_ADDR(base) ((base) + (0x830))
#define SOC_FCM_TOPERI_FCM_CORE4_PCHANNEL_CFG_ADDR(base) ((base) + (0x834))
#define SOC_FCM_TOPERI_FCM_CORE5_PCHANNEL_CFG_ADDR(base) ((base) + (0x838))
#define SOC_FCM_TOPERI_FCM_CORE6_PCHANNEL_CFG_ADDR(base) ((base) + (0x83C))
#define SOC_FCM_TOPERI_FCM_CORE7_PCHANNEL_CFG_ADDR(base) ((base) + (0x840))
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_DATARAM_WAY_0_15_MEM_TEST_ADDR(base) ((base) + (0x844))
#define SOC_FCM_TOPERI_CORE_MEM_LP_CTL_ADDR(base) ((base) + (0x850))
#define SOC_FCM_TOPERI_CLUSTER_MEM_LP_CTL_ADDR(base) ((base) + (0x854))
#define SOC_FCM_TOPERI_FCM_PCHANNEL_CFG_REG_ADDR(base) ((base) + (0x870))
#define SOC_FCM_TOPERI_FCM_CORE01_PCHANNEL_CFG_REG_ADDR(base) ((base) + (0x874))
#define SOC_FCM_TOPERI_FCM_CORE23_PCHANNEL_CFG_REG_ADDR(base) ((base) + (0x878))
#define SOC_FCM_TOPERI_FCM_CORE45_PCHANNEL_CFG_REG_ADDR(base) ((base) + (0x87C))
#define SOC_FCM_TOPERI_FCM_CORE67_PCHANNEL_CFG_REG_ADDR(base) ((base) + (0x880))
#define SOC_FCM_TOPERI_LPM3_FORCE_FLUSH_CACHE_CFG_REG_ADDR(base) ((base) + (0x888))
#define SOC_FCM_TOPERI_LPM3_FORCE_OFF_TO_ON_CFG_REG_ADDR(base) ((base) + (0x88C))
#define SOC_FCM_TOPERI_FCM_P_CHANNEL_DISABLE_OFF_CFG_REG_ADDR(base) ((base) + (0x890))
#define SOC_FCM_TOPERI_CORE_HCTP_MEM_ADJUST_REG_ADDR(base) ((base) + (0x8C4))
#define SOC_FCM_TOPERI_CORE_HDTP_MEM_ADJUST_REG_ADDR(base) ((base) + (0x8C8))
#define SOC_FCM_TOPERI_FCM_NOC_NSAID_MID_ADDR(base) ((base) + (0x8E4))
#define SOC_FCM_TOPERI_KARMA_PCR_SD_CTRL_ADDR(base) ((base) + (0x8F0))
#define SOC_FCM_TOPERI_KARMA_PCR_FVT_MEM_CTRL_ADDR(base) ((base) + (0x8F4))
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT0_ADDR(base) ((base) + (0xC00))
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT2_ADDR(base) ((base) + (0xC08))
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT3_ADDR(base) ((base) + (0xC0C))
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT4_ADDR(base) ((base) + (0xC10))
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT5_ADDR(base) ((base) + (0xC14))
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT6_ADDR(base) ((base) + (0xC18))
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT7_ADDR(base) ((base) + (0xC1C))
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT8_ADDR(base) ((base) + (0xC20))
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT9_ADDR(base) ((base) + (0xC24))
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT10_ADDR(base) ((base) + (0xC28))
#define SOC_FCM_TOPERI_FCM_PCHANNEL_STAT_ADDR(base) ((base) + (0xC30))
#define SOC_FCM_TOPERI_FCM_CORE0_PCHANNEL_STAT_ADDR(base) ((base) + (0xC34))
#define SOC_FCM_TOPERI_FCM_CORE1_PCHANNEL_STAT_ADDR(base) ((base) + (0xC38))
#define SOC_FCM_TOPERI_FCM_CORE2_PCHANNEL_STAT_ADDR(base) ((base) + (0xC3C))
#define SOC_FCM_TOPERI_FCM_CORE3_PCHANNEL_STAT_ADDR(base) ((base) + (0xC40))
#define SOC_FCM_TOPERI_FCM_CORE4_PCHANNEL_STAT_ADDR(base) ((base) + (0xC44))
#define SOC_FCM_TOPERI_FCM_CORE5_PCHANNEL_STAT_ADDR(base) ((base) + (0xC48))
#define SOC_FCM_TOPERI_FCM_CORE6_PCHANNEL_STAT_ADDR(base) ((base) + (0xC4C))
#define SOC_FCM_TOPERI_FCM_CORE7_PCHANNEL_STAT_ADDR(base) ((base) + (0xC50))
#define SOC_FCM_TOPERI_FCM_CORE01_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + (0xC6C))
#define SOC_FCM_TOPERI_FCM_CORE23_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + (0xC70))
#define SOC_FCM_TOPERI_FCM_CORE45_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + (0xC74))
#define SOC_FCM_TOPERI_FCM_CORE67_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + (0xC78))
#define SOC_FCM_TOPERI_FCM_FCM_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + (0xC7C))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 8;
        unsigned int mtcmos_sd_bypass : 1;
        unsigned int reserved_1 : 2;
        unsigned int core_idle_isolate_bypass : 1;
        unsigned int reserved_2 : 20;
    } reg;
} SOC_FCM_TOPERI_FCM_BASE_CFG1_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_BASE_CFG1_mtcmos_sd_bypass_START (8)
#define SOC_FCM_TOPERI_FCM_BASE_CFG1_mtcmos_sd_bypass_END (8)
#define SOC_FCM_TOPERI_FCM_BASE_CFG1_core_idle_isolate_bypass_START (11)
#define SOC_FCM_TOPERI_FCM_BASE_CFG1_core_idle_isolate_bypass_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coresight_memory_ls : 1;
        unsigned int coresight_memory_ds : 1;
        unsigned int coresight_memory_sd : 1;
        unsigned int reserved_0 : 5;
        unsigned int coresight_mem_test : 3;
        unsigned int coresight_mem_tsel_r : 3;
        unsigned int coresight_mem_tsel_w : 2;
        unsigned int coresight_mem_tra : 2;
        unsigned int reserved_1 : 14;
    } reg;
} SOC_FCM_TOPERI_FCM_CSSYS_MEM_CTL_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_CSSYS_MEM_CTL_coresight_memory_ls_START (0)
#define SOC_FCM_TOPERI_FCM_CSSYS_MEM_CTL_coresight_memory_ls_END (0)
#define SOC_FCM_TOPERI_FCM_CSSYS_MEM_CTL_coresight_memory_ds_START (1)
#define SOC_FCM_TOPERI_FCM_CSSYS_MEM_CTL_coresight_memory_ds_END (1)
#define SOC_FCM_TOPERI_FCM_CSSYS_MEM_CTL_coresight_memory_sd_START (2)
#define SOC_FCM_TOPERI_FCM_CSSYS_MEM_CTL_coresight_memory_sd_END (2)
#define SOC_FCM_TOPERI_FCM_CSSYS_MEM_CTL_coresight_mem_test_START (8)
#define SOC_FCM_TOPERI_FCM_CSSYS_MEM_CTL_coresight_mem_test_END (10)
#define SOC_FCM_TOPERI_FCM_CSSYS_MEM_CTL_coresight_mem_tsel_r_START (11)
#define SOC_FCM_TOPERI_FCM_CSSYS_MEM_CTL_coresight_mem_tsel_r_END (13)
#define SOC_FCM_TOPERI_FCM_CSSYS_MEM_CTL_coresight_mem_tsel_w_START (14)
#define SOC_FCM_TOPERI_FCM_CSSYS_MEM_CTL_coresight_mem_tsel_w_END (15)
#define SOC_FCM_TOPERI_FCM_CSSYS_MEM_CTL_coresight_mem_tra_START (16)
#define SOC_FCM_TOPERI_FCM_CSSYS_MEM_CTL_coresight_mem_tra_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_p_channel_init_pstate : 7;
        unsigned int reserved_0 : 1;
        unsigned int force_on_to_sfonly_on_enable : 1;
        unsigned int reserved_1 : 3;
        unsigned int force_on_to_sfonly_on : 1;
        unsigned int reserved_2 : 2;
        unsigned int cluster_preq_from_sys : 1;
        unsigned int cluster_pstate_from_sys : 7;
        unsigned int reserved_3 : 1;
        unsigned int cluster_pactive_sel : 2;
        unsigned int reserved_4 : 5;
        unsigned int fcm_p_channel_enable : 1;
    } reg;
} SOC_FCM_TOPERI_FCM_CLUSTER_PCHANNEL_CFG_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_CLUSTER_PCHANNEL_CFG_fcm_p_channel_init_pstate_START (0)
#define SOC_FCM_TOPERI_FCM_CLUSTER_PCHANNEL_CFG_fcm_p_channel_init_pstate_END (6)
#define SOC_FCM_TOPERI_FCM_CLUSTER_PCHANNEL_CFG_force_on_to_sfonly_on_enable_START (8)
#define SOC_FCM_TOPERI_FCM_CLUSTER_PCHANNEL_CFG_force_on_to_sfonly_on_enable_END (8)
#define SOC_FCM_TOPERI_FCM_CLUSTER_PCHANNEL_CFG_force_on_to_sfonly_on_START (12)
#define SOC_FCM_TOPERI_FCM_CLUSTER_PCHANNEL_CFG_force_on_to_sfonly_on_END (12)
#define SOC_FCM_TOPERI_FCM_CLUSTER_PCHANNEL_CFG_cluster_preq_from_sys_START (15)
#define SOC_FCM_TOPERI_FCM_CLUSTER_PCHANNEL_CFG_cluster_preq_from_sys_END (15)
#define SOC_FCM_TOPERI_FCM_CLUSTER_PCHANNEL_CFG_cluster_pstate_from_sys_START (16)
#define SOC_FCM_TOPERI_FCM_CLUSTER_PCHANNEL_CFG_cluster_pstate_from_sys_END (22)
#define SOC_FCM_TOPERI_FCM_CLUSTER_PCHANNEL_CFG_cluster_pactive_sel_START (24)
#define SOC_FCM_TOPERI_FCM_CLUSTER_PCHANNEL_CFG_cluster_pactive_sel_END (25)
#define SOC_FCM_TOPERI_FCM_CLUSTER_PCHANNEL_CFG_fcm_p_channel_enable_START (31)
#define SOC_FCM_TOPERI_FCM_CLUSTER_PCHANNEL_CFG_fcm_p_channel_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l3_data_way15_way12_mem_ctrl_sys : 3;
        unsigned int l3_data_way11_way8_mem_ctrl_sys : 3;
        unsigned int l3_data_way7_way4_mem_ctrl_sys : 3;
        unsigned int l3_data_way3_way0_mem_ctrl_sys : 3;
        unsigned int l3_sf_mem_ctrl_sys : 3;
        unsigned int l3_other_mem_ctrl_sys : 3;
        unsigned int reserved : 2;
        unsigned int l3_tag_way15_way12_mem_ctrl_sys : 3;
        unsigned int l3_tag_way11_way8_mem_ctrl_sys : 3;
        unsigned int l3_tag_way7_way4_mem_ctrl_sys : 3;
        unsigned int l3_tag_way3_way0_mem_ctrl_sys : 3;
    } reg;
} SOC_FCM_TOPERI_FCM_CLUSTER_L3_MEM_CTRL_LP_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_data_way15_way12_mem_ctrl_sys_START (0)
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_data_way15_way12_mem_ctrl_sys_END (2)
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_data_way11_way8_mem_ctrl_sys_START (3)
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_data_way11_way8_mem_ctrl_sys_END (5)
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_data_way7_way4_mem_ctrl_sys_START (6)
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_data_way7_way4_mem_ctrl_sys_END (8)
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_data_way3_way0_mem_ctrl_sys_START (9)
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_data_way3_way0_mem_ctrl_sys_END (11)
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_sf_mem_ctrl_sys_START (12)
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_sf_mem_ctrl_sys_END (14)
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_other_mem_ctrl_sys_START (15)
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_other_mem_ctrl_sys_END (17)
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_tag_way15_way12_mem_ctrl_sys_START (20)
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_tag_way15_way12_mem_ctrl_sys_END (22)
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_tag_way11_way8_mem_ctrl_sys_START (23)
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_tag_way11_way8_mem_ctrl_sys_END (25)
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_tag_way7_way4_mem_ctrl_sys_START (26)
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_tag_way7_way4_mem_ctrl_sys_END (28)
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_tag_way3_way0_mem_ctrl_sys_START (29)
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_tag_way3_way0_mem_ctrl_sys_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core0_p_channel_init_pstate : 6;
        unsigned int reserved_0 : 10;
        unsigned int core0_pstate_from_sys : 6;
        unsigned int reserved_1 : 2;
        unsigned int core0_preq_from_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core0_mem_ctrl_from_sys : 3;
        unsigned int core0_p_channel_enable : 1;
    } reg;
} SOC_FCM_TOPERI_FCM_CORE0_PCHANNEL_CFG_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_CORE0_PCHANNEL_CFG_core0_p_channel_init_pstate_START (0)
#define SOC_FCM_TOPERI_FCM_CORE0_PCHANNEL_CFG_core0_p_channel_init_pstate_END (5)
#define SOC_FCM_TOPERI_FCM_CORE0_PCHANNEL_CFG_core0_pstate_from_sys_START (16)
#define SOC_FCM_TOPERI_FCM_CORE0_PCHANNEL_CFG_core0_pstate_from_sys_END (21)
#define SOC_FCM_TOPERI_FCM_CORE0_PCHANNEL_CFG_core0_preq_from_sys_START (24)
#define SOC_FCM_TOPERI_FCM_CORE0_PCHANNEL_CFG_core0_preq_from_sys_END (24)
#define SOC_FCM_TOPERI_FCM_CORE0_PCHANNEL_CFG_core0_mem_ctrl_from_sys_START (28)
#define SOC_FCM_TOPERI_FCM_CORE0_PCHANNEL_CFG_core0_mem_ctrl_from_sys_END (30)
#define SOC_FCM_TOPERI_FCM_CORE0_PCHANNEL_CFG_core0_p_channel_enable_START (31)
#define SOC_FCM_TOPERI_FCM_CORE0_PCHANNEL_CFG_core0_p_channel_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core1_p_channel_init_pstate : 6;
        unsigned int reserved_0 : 10;
        unsigned int core1_pstate_from_sys : 6;
        unsigned int reserved_1 : 2;
        unsigned int core1_preq_from_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core1_mem_ctrl_from_sys : 3;
        unsigned int core1_p_channel_enable : 1;
    } reg;
} SOC_FCM_TOPERI_FCM_CORE1_PCHANNEL_CFG_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_CORE1_PCHANNEL_CFG_core1_p_channel_init_pstate_START (0)
#define SOC_FCM_TOPERI_FCM_CORE1_PCHANNEL_CFG_core1_p_channel_init_pstate_END (5)
#define SOC_FCM_TOPERI_FCM_CORE1_PCHANNEL_CFG_core1_pstate_from_sys_START (16)
#define SOC_FCM_TOPERI_FCM_CORE1_PCHANNEL_CFG_core1_pstate_from_sys_END (21)
#define SOC_FCM_TOPERI_FCM_CORE1_PCHANNEL_CFG_core1_preq_from_sys_START (24)
#define SOC_FCM_TOPERI_FCM_CORE1_PCHANNEL_CFG_core1_preq_from_sys_END (24)
#define SOC_FCM_TOPERI_FCM_CORE1_PCHANNEL_CFG_core1_mem_ctrl_from_sys_START (28)
#define SOC_FCM_TOPERI_FCM_CORE1_PCHANNEL_CFG_core1_mem_ctrl_from_sys_END (30)
#define SOC_FCM_TOPERI_FCM_CORE1_PCHANNEL_CFG_core1_p_channel_enable_START (31)
#define SOC_FCM_TOPERI_FCM_CORE1_PCHANNEL_CFG_core1_p_channel_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core2_p_channel_init_pstate : 6;
        unsigned int reserved_0 : 10;
        unsigned int core2_pstate_from_sys : 6;
        unsigned int reserved_1 : 2;
        unsigned int core2_preq_from_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core2_mem_ctrl_from_sys : 3;
        unsigned int core2_p_channel_enable : 1;
    } reg;
} SOC_FCM_TOPERI_FCM_CORE2_PCHANNEL_CFG_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_CORE2_PCHANNEL_CFG_core2_p_channel_init_pstate_START (0)
#define SOC_FCM_TOPERI_FCM_CORE2_PCHANNEL_CFG_core2_p_channel_init_pstate_END (5)
#define SOC_FCM_TOPERI_FCM_CORE2_PCHANNEL_CFG_core2_pstate_from_sys_START (16)
#define SOC_FCM_TOPERI_FCM_CORE2_PCHANNEL_CFG_core2_pstate_from_sys_END (21)
#define SOC_FCM_TOPERI_FCM_CORE2_PCHANNEL_CFG_core2_preq_from_sys_START (24)
#define SOC_FCM_TOPERI_FCM_CORE2_PCHANNEL_CFG_core2_preq_from_sys_END (24)
#define SOC_FCM_TOPERI_FCM_CORE2_PCHANNEL_CFG_core2_mem_ctrl_from_sys_START (28)
#define SOC_FCM_TOPERI_FCM_CORE2_PCHANNEL_CFG_core2_mem_ctrl_from_sys_END (30)
#define SOC_FCM_TOPERI_FCM_CORE2_PCHANNEL_CFG_core2_p_channel_enable_START (31)
#define SOC_FCM_TOPERI_FCM_CORE2_PCHANNEL_CFG_core2_p_channel_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core3_p_channel_init_pstate : 6;
        unsigned int reserved_0 : 10;
        unsigned int core3_pstate_from_sys : 6;
        unsigned int reserved_1 : 2;
        unsigned int core3_preq_from_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core3_mem_ctrl_from_sys : 3;
        unsigned int core3_p_channel_enable : 1;
    } reg;
} SOC_FCM_TOPERI_FCM_CORE3_PCHANNEL_CFG_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_CORE3_PCHANNEL_CFG_core3_p_channel_init_pstate_START (0)
#define SOC_FCM_TOPERI_FCM_CORE3_PCHANNEL_CFG_core3_p_channel_init_pstate_END (5)
#define SOC_FCM_TOPERI_FCM_CORE3_PCHANNEL_CFG_core3_pstate_from_sys_START (16)
#define SOC_FCM_TOPERI_FCM_CORE3_PCHANNEL_CFG_core3_pstate_from_sys_END (21)
#define SOC_FCM_TOPERI_FCM_CORE3_PCHANNEL_CFG_core3_preq_from_sys_START (24)
#define SOC_FCM_TOPERI_FCM_CORE3_PCHANNEL_CFG_core3_preq_from_sys_END (24)
#define SOC_FCM_TOPERI_FCM_CORE3_PCHANNEL_CFG_core3_mem_ctrl_from_sys_START (28)
#define SOC_FCM_TOPERI_FCM_CORE3_PCHANNEL_CFG_core3_mem_ctrl_from_sys_END (30)
#define SOC_FCM_TOPERI_FCM_CORE3_PCHANNEL_CFG_core3_p_channel_enable_START (31)
#define SOC_FCM_TOPERI_FCM_CORE3_PCHANNEL_CFG_core3_p_channel_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core4_p_channel_init_pstate : 6;
        unsigned int reserved_0 : 10;
        unsigned int core4_pstate_from_sys : 6;
        unsigned int reserved_1 : 2;
        unsigned int core4_preq_from_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core4_mem_ctrl_from_sys : 3;
        unsigned int core4_p_channel_enable : 1;
    } reg;
} SOC_FCM_TOPERI_FCM_CORE4_PCHANNEL_CFG_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_CORE4_PCHANNEL_CFG_core4_p_channel_init_pstate_START (0)
#define SOC_FCM_TOPERI_FCM_CORE4_PCHANNEL_CFG_core4_p_channel_init_pstate_END (5)
#define SOC_FCM_TOPERI_FCM_CORE4_PCHANNEL_CFG_core4_pstate_from_sys_START (16)
#define SOC_FCM_TOPERI_FCM_CORE4_PCHANNEL_CFG_core4_pstate_from_sys_END (21)
#define SOC_FCM_TOPERI_FCM_CORE4_PCHANNEL_CFG_core4_preq_from_sys_START (24)
#define SOC_FCM_TOPERI_FCM_CORE4_PCHANNEL_CFG_core4_preq_from_sys_END (24)
#define SOC_FCM_TOPERI_FCM_CORE4_PCHANNEL_CFG_core4_mem_ctrl_from_sys_START (28)
#define SOC_FCM_TOPERI_FCM_CORE4_PCHANNEL_CFG_core4_mem_ctrl_from_sys_END (30)
#define SOC_FCM_TOPERI_FCM_CORE4_PCHANNEL_CFG_core4_p_channel_enable_START (31)
#define SOC_FCM_TOPERI_FCM_CORE4_PCHANNEL_CFG_core4_p_channel_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core5_p_channel_init_pstate : 6;
        unsigned int reserved_0 : 10;
        unsigned int core5_pstate_from_sys : 6;
        unsigned int reserved_1 : 2;
        unsigned int core5_preq_from_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core5_mem_ctrl_from_sys : 3;
        unsigned int core5_p_channel_enable : 1;
    } reg;
} SOC_FCM_TOPERI_FCM_CORE5_PCHANNEL_CFG_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_CORE5_PCHANNEL_CFG_core5_p_channel_init_pstate_START (0)
#define SOC_FCM_TOPERI_FCM_CORE5_PCHANNEL_CFG_core5_p_channel_init_pstate_END (5)
#define SOC_FCM_TOPERI_FCM_CORE5_PCHANNEL_CFG_core5_pstate_from_sys_START (16)
#define SOC_FCM_TOPERI_FCM_CORE5_PCHANNEL_CFG_core5_pstate_from_sys_END (21)
#define SOC_FCM_TOPERI_FCM_CORE5_PCHANNEL_CFG_core5_preq_from_sys_START (24)
#define SOC_FCM_TOPERI_FCM_CORE5_PCHANNEL_CFG_core5_preq_from_sys_END (24)
#define SOC_FCM_TOPERI_FCM_CORE5_PCHANNEL_CFG_core5_mem_ctrl_from_sys_START (28)
#define SOC_FCM_TOPERI_FCM_CORE5_PCHANNEL_CFG_core5_mem_ctrl_from_sys_END (30)
#define SOC_FCM_TOPERI_FCM_CORE5_PCHANNEL_CFG_core5_p_channel_enable_START (31)
#define SOC_FCM_TOPERI_FCM_CORE5_PCHANNEL_CFG_core5_p_channel_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core6_p_channel_init_pstate : 6;
        unsigned int reserved_0 : 10;
        unsigned int core6_pstate_from_sys : 6;
        unsigned int reserved_1 : 2;
        unsigned int core6_preq_from_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core6_mem_ctrl_from_sys : 3;
        unsigned int core6_p_channel_enable : 1;
    } reg;
} SOC_FCM_TOPERI_FCM_CORE6_PCHANNEL_CFG_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_CORE6_PCHANNEL_CFG_core6_p_channel_init_pstate_START (0)
#define SOC_FCM_TOPERI_FCM_CORE6_PCHANNEL_CFG_core6_p_channel_init_pstate_END (5)
#define SOC_FCM_TOPERI_FCM_CORE6_PCHANNEL_CFG_core6_pstate_from_sys_START (16)
#define SOC_FCM_TOPERI_FCM_CORE6_PCHANNEL_CFG_core6_pstate_from_sys_END (21)
#define SOC_FCM_TOPERI_FCM_CORE6_PCHANNEL_CFG_core6_preq_from_sys_START (24)
#define SOC_FCM_TOPERI_FCM_CORE6_PCHANNEL_CFG_core6_preq_from_sys_END (24)
#define SOC_FCM_TOPERI_FCM_CORE6_PCHANNEL_CFG_core6_mem_ctrl_from_sys_START (28)
#define SOC_FCM_TOPERI_FCM_CORE6_PCHANNEL_CFG_core6_mem_ctrl_from_sys_END (30)
#define SOC_FCM_TOPERI_FCM_CORE6_PCHANNEL_CFG_core6_p_channel_enable_START (31)
#define SOC_FCM_TOPERI_FCM_CORE6_PCHANNEL_CFG_core6_p_channel_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core7_p_channel_init_pstate : 6;
        unsigned int reserved_0 : 10;
        unsigned int core7_pstate_from_sys : 6;
        unsigned int reserved_1 : 2;
        unsigned int core7_preq_from_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core7_mem_ctrl_from_sys : 3;
        unsigned int core7_p_channel_enable : 1;
    } reg;
} SOC_FCM_TOPERI_FCM_CORE7_PCHANNEL_CFG_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_CORE7_PCHANNEL_CFG_core7_p_channel_init_pstate_START (0)
#define SOC_FCM_TOPERI_FCM_CORE7_PCHANNEL_CFG_core7_p_channel_init_pstate_END (5)
#define SOC_FCM_TOPERI_FCM_CORE7_PCHANNEL_CFG_core7_pstate_from_sys_START (16)
#define SOC_FCM_TOPERI_FCM_CORE7_PCHANNEL_CFG_core7_pstate_from_sys_END (21)
#define SOC_FCM_TOPERI_FCM_CORE7_PCHANNEL_CFG_core7_preq_from_sys_START (24)
#define SOC_FCM_TOPERI_FCM_CORE7_PCHANNEL_CFG_core7_preq_from_sys_END (24)
#define SOC_FCM_TOPERI_FCM_CORE7_PCHANNEL_CFG_core7_mem_ctrl_from_sys_START (28)
#define SOC_FCM_TOPERI_FCM_CORE7_PCHANNEL_CFG_core7_mem_ctrl_from_sys_END (30)
#define SOC_FCM_TOPERI_FCM_CORE7_PCHANNEL_CFG_core7_p_channel_enable_START (31)
#define SOC_FCM_TOPERI_FCM_CORE7_PCHANNEL_CFG_core7_p_channel_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l3_data_way15_0_hisi_mem_test : 3;
        unsigned int reserved_0 : 2;
        unsigned int l3_data_way15_0_hisi_mem_tselw : 2;
        unsigned int l3_data_way15_0_hisi_mem_tra : 2;
        unsigned int l3_data_way15_0_hisi_mem_tselr : 3;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_FCM_TOPERI_FCM_CLUSTER_L3_DATARAM_WAY_0_15_MEM_TEST_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_DATARAM_WAY_0_15_MEM_TEST_l3_data_way15_0_hisi_mem_test_START (0)
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_DATARAM_WAY_0_15_MEM_TEST_l3_data_way15_0_hisi_mem_test_END (2)
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_DATARAM_WAY_0_15_MEM_TEST_l3_data_way15_0_hisi_mem_tselw_START (5)
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_DATARAM_WAY_0_15_MEM_TEST_l3_data_way15_0_hisi_mem_tselw_END (6)
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_DATARAM_WAY_0_15_MEM_TEST_l3_data_way15_0_hisi_mem_tra_START (7)
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_DATARAM_WAY_0_15_MEM_TEST_l3_data_way15_0_hisi_mem_tra_END (8)
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_DATARAM_WAY_0_15_MEM_TEST_l3_data_way15_0_hisi_mem_tselr_START (9)
#define SOC_FCM_TOPERI_FCM_CLUSTER_L3_DATARAM_WAY_0_15_MEM_TEST_l3_data_way15_0_hisi_mem_tselr_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ananke_core_mem_ctl_normal : 3;
        unsigned int reserved_0 : 1;
        unsigned int ananke_core_mem_ctl_sd : 3;
        unsigned int reserved_1 : 1;
        unsigned int ananke_core_mem_ctl_dslp : 3;
        unsigned int reserved_2 : 1;
        unsigned int ananke_core_mem_ctl_slp : 3;
        unsigned int reserved_3 : 1;
        unsigned int enyo_big_core_mem_ctl_normal : 3;
        unsigned int reserved_4 : 1;
        unsigned int enyo_big_core_mem_ctl_sd : 3;
        unsigned int reserved_5 : 1;
        unsigned int enyo_big_core_mem_ctl_dslp : 3;
        unsigned int reserved_6 : 1;
        unsigned int enyo_big_core_mem_ctl_slp : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_FCM_TOPERI_CORE_MEM_LP_CTL_UNION;
#endif
#define SOC_FCM_TOPERI_CORE_MEM_LP_CTL_ananke_core_mem_ctl_normal_START (0)
#define SOC_FCM_TOPERI_CORE_MEM_LP_CTL_ananke_core_mem_ctl_normal_END (2)
#define SOC_FCM_TOPERI_CORE_MEM_LP_CTL_ananke_core_mem_ctl_sd_START (4)
#define SOC_FCM_TOPERI_CORE_MEM_LP_CTL_ananke_core_mem_ctl_sd_END (6)
#define SOC_FCM_TOPERI_CORE_MEM_LP_CTL_ananke_core_mem_ctl_dslp_START (8)
#define SOC_FCM_TOPERI_CORE_MEM_LP_CTL_ananke_core_mem_ctl_dslp_END (10)
#define SOC_FCM_TOPERI_CORE_MEM_LP_CTL_ananke_core_mem_ctl_slp_START (12)
#define SOC_FCM_TOPERI_CORE_MEM_LP_CTL_ananke_core_mem_ctl_slp_END (14)
#define SOC_FCM_TOPERI_CORE_MEM_LP_CTL_enyo_big_core_mem_ctl_normal_START (16)
#define SOC_FCM_TOPERI_CORE_MEM_LP_CTL_enyo_big_core_mem_ctl_normal_END (18)
#define SOC_FCM_TOPERI_CORE_MEM_LP_CTL_enyo_big_core_mem_ctl_sd_START (20)
#define SOC_FCM_TOPERI_CORE_MEM_LP_CTL_enyo_big_core_mem_ctl_sd_END (22)
#define SOC_FCM_TOPERI_CORE_MEM_LP_CTL_enyo_big_core_mem_ctl_dslp_START (24)
#define SOC_FCM_TOPERI_CORE_MEM_LP_CTL_enyo_big_core_mem_ctl_dslp_END (26)
#define SOC_FCM_TOPERI_CORE_MEM_LP_CTL_enyo_big_core_mem_ctl_slp_START (28)
#define SOC_FCM_TOPERI_CORE_MEM_LP_CTL_enyo_big_core_mem_ctl_slp_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_cluster_mem_ctl_normal : 3;
        unsigned int reserved_0 : 1;
        unsigned int fcm_cluster_mem_ctl_sd : 3;
        unsigned int reserved_1 : 1;
        unsigned int fcm_cluster_mem_ctl_dslp : 3;
        unsigned int reserved_2 : 1;
        unsigned int fcm_cluster_core_mem_ctl_slp : 3;
        unsigned int reserved_3 : 1;
        unsigned int enyo_mid_core_mem_ctl_normal : 3;
        unsigned int reserved_4 : 1;
        unsigned int enyo_mid_core_mem_ctl_sd : 3;
        unsigned int reserved_5 : 1;
        unsigned int enyo_mid_core_mem_ctl_dslp : 3;
        unsigned int reserved_6 : 1;
        unsigned int enyo_mid_core_mem_ctl_slp : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_FCM_TOPERI_CLUSTER_MEM_LP_CTL_UNION;
#endif
#define SOC_FCM_TOPERI_CLUSTER_MEM_LP_CTL_fcm_cluster_mem_ctl_normal_START (0)
#define SOC_FCM_TOPERI_CLUSTER_MEM_LP_CTL_fcm_cluster_mem_ctl_normal_END (2)
#define SOC_FCM_TOPERI_CLUSTER_MEM_LP_CTL_fcm_cluster_mem_ctl_sd_START (4)
#define SOC_FCM_TOPERI_CLUSTER_MEM_LP_CTL_fcm_cluster_mem_ctl_sd_END (6)
#define SOC_FCM_TOPERI_CLUSTER_MEM_LP_CTL_fcm_cluster_mem_ctl_dslp_START (8)
#define SOC_FCM_TOPERI_CLUSTER_MEM_LP_CTL_fcm_cluster_mem_ctl_dslp_END (10)
#define SOC_FCM_TOPERI_CLUSTER_MEM_LP_CTL_fcm_cluster_core_mem_ctl_slp_START (12)
#define SOC_FCM_TOPERI_CLUSTER_MEM_LP_CTL_fcm_cluster_core_mem_ctl_slp_END (14)
#define SOC_FCM_TOPERI_CLUSTER_MEM_LP_CTL_enyo_mid_core_mem_ctl_normal_START (16)
#define SOC_FCM_TOPERI_CLUSTER_MEM_LP_CTL_enyo_mid_core_mem_ctl_normal_END (18)
#define SOC_FCM_TOPERI_CLUSTER_MEM_LP_CTL_enyo_mid_core_mem_ctl_sd_START (20)
#define SOC_FCM_TOPERI_CLUSTER_MEM_LP_CTL_enyo_mid_core_mem_ctl_sd_END (22)
#define SOC_FCM_TOPERI_CLUSTER_MEM_LP_CTL_enyo_mid_core_mem_ctl_dslp_START (24)
#define SOC_FCM_TOPERI_CLUSTER_MEM_LP_CTL_enyo_mid_core_mem_ctl_dslp_END (26)
#define SOC_FCM_TOPERI_CLUSTER_MEM_LP_CTL_enyo_mid_core_mem_ctl_slp_START (28)
#define SOC_FCM_TOPERI_CLUSTER_MEM_LP_CTL_enyo_mid_core_mem_ctl_slp_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_pchannel_wait_cycle_dslp : 16;
        unsigned int fcm_pchannel_wait_cycle_sd : 16;
    } reg;
} SOC_FCM_TOPERI_FCM_PCHANNEL_CFG_REG_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_PCHANNEL_CFG_REG_fcm_pchannel_wait_cycle_dslp_START (0)
#define SOC_FCM_TOPERI_FCM_PCHANNEL_CFG_REG_fcm_pchannel_wait_cycle_dslp_END (15)
#define SOC_FCM_TOPERI_FCM_PCHANNEL_CFG_REG_fcm_pchannel_wait_cycle_sd_START (16)
#define SOC_FCM_TOPERI_FCM_PCHANNEL_CFG_REG_fcm_pchannel_wait_cycle_sd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_core0_pchannel_wait_cycle_dslp : 16;
        unsigned int fcm_core1_pchannel_wait_cycle_dslp : 16;
    } reg;
} SOC_FCM_TOPERI_FCM_CORE01_PCHANNEL_CFG_REG_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_CORE01_PCHANNEL_CFG_REG_fcm_core0_pchannel_wait_cycle_dslp_START (0)
#define SOC_FCM_TOPERI_FCM_CORE01_PCHANNEL_CFG_REG_fcm_core0_pchannel_wait_cycle_dslp_END (15)
#define SOC_FCM_TOPERI_FCM_CORE01_PCHANNEL_CFG_REG_fcm_core1_pchannel_wait_cycle_dslp_START (16)
#define SOC_FCM_TOPERI_FCM_CORE01_PCHANNEL_CFG_REG_fcm_core1_pchannel_wait_cycle_dslp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_core2_pchannel_wait_cycle_dslp : 16;
        unsigned int fcm_core3_pchannel_wait_cycle_dslp : 16;
    } reg;
} SOC_FCM_TOPERI_FCM_CORE23_PCHANNEL_CFG_REG_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_CORE23_PCHANNEL_CFG_REG_fcm_core2_pchannel_wait_cycle_dslp_START (0)
#define SOC_FCM_TOPERI_FCM_CORE23_PCHANNEL_CFG_REG_fcm_core2_pchannel_wait_cycle_dslp_END (15)
#define SOC_FCM_TOPERI_FCM_CORE23_PCHANNEL_CFG_REG_fcm_core3_pchannel_wait_cycle_dslp_START (16)
#define SOC_FCM_TOPERI_FCM_CORE23_PCHANNEL_CFG_REG_fcm_core3_pchannel_wait_cycle_dslp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_core4_pchannel_wait_cycle_dslp : 16;
        unsigned int fcm_core5_pchannel_wait_cycle_dslp : 16;
    } reg;
} SOC_FCM_TOPERI_FCM_CORE45_PCHANNEL_CFG_REG_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_CORE45_PCHANNEL_CFG_REG_fcm_core4_pchannel_wait_cycle_dslp_START (0)
#define SOC_FCM_TOPERI_FCM_CORE45_PCHANNEL_CFG_REG_fcm_core4_pchannel_wait_cycle_dslp_END (15)
#define SOC_FCM_TOPERI_FCM_CORE45_PCHANNEL_CFG_REG_fcm_core5_pchannel_wait_cycle_dslp_START (16)
#define SOC_FCM_TOPERI_FCM_CORE45_PCHANNEL_CFG_REG_fcm_core5_pchannel_wait_cycle_dslp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_core6_pchannel_wait_cycle_dslp : 16;
        unsigned int fcm_core7_pchannel_wait_cycle_dslp : 16;
    } reg;
} SOC_FCM_TOPERI_FCM_CORE67_PCHANNEL_CFG_REG_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_CORE67_PCHANNEL_CFG_REG_fcm_core6_pchannel_wait_cycle_dslp_START (0)
#define SOC_FCM_TOPERI_FCM_CORE67_PCHANNEL_CFG_REG_fcm_core6_pchannel_wait_cycle_dslp_END (15)
#define SOC_FCM_TOPERI_FCM_CORE67_PCHANNEL_CFG_REG_fcm_core7_pchannel_wait_cycle_dslp_START (16)
#define SOC_FCM_TOPERI_FCM_CORE67_PCHANNEL_CFG_REG_fcm_core7_pchannel_wait_cycle_dslp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int force_flush_cache : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_TOPERI_LPM3_FORCE_FLUSH_CACHE_CFG_REG_UNION;
#endif
#define SOC_FCM_TOPERI_LPM3_FORCE_FLUSH_CACHE_CFG_REG_force_flush_cache_START (0)
#define SOC_FCM_TOPERI_LPM3_FORCE_FLUSH_CACHE_CFG_REG_force_flush_cache_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int force_off_to_on : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_TOPERI_LPM3_FORCE_OFF_TO_ON_CFG_REG_UNION;
#endif
#define SOC_FCM_TOPERI_LPM3_FORCE_OFF_TO_ON_CFG_REG_force_off_to_on_START (0)
#define SOC_FCM_TOPERI_LPM3_FORCE_OFF_TO_ON_CFG_REG_force_off_to_on_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int force_disable_off : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_TOPERI_FCM_P_CHANNEL_DISABLE_OFF_CFG_REG_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_P_CHANNEL_DISABLE_OFF_CFG_REG_force_disable_off_START (0)
#define SOC_FCM_TOPERI_FCM_P_CHANNEL_DISABLE_OFF_CFG_REG_force_disable_off_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_tp_test : 3;
        unsigned int core_tp_tselr_tp : 2;
        unsigned int core_tp_tselw : 2;
        unsigned int core_tp_tra : 2;
        unsigned int core_tp_tselr_hchd : 3;
        unsigned int core_hc_test : 3;
        unsigned int core_hc_tselr_tp : 2;
        unsigned int core_hc_tselw : 2;
        unsigned int core_hc_tra : 2;
        unsigned int core_hc_tselr_hchd : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_FCM_TOPERI_CORE_HCTP_MEM_ADJUST_REG_UNION;
#endif
#define SOC_FCM_TOPERI_CORE_HCTP_MEM_ADJUST_REG_core_tp_test_START (0)
#define SOC_FCM_TOPERI_CORE_HCTP_MEM_ADJUST_REG_core_tp_test_END (2)
#define SOC_FCM_TOPERI_CORE_HCTP_MEM_ADJUST_REG_core_tp_tselr_tp_START (3)
#define SOC_FCM_TOPERI_CORE_HCTP_MEM_ADJUST_REG_core_tp_tselr_tp_END (4)
#define SOC_FCM_TOPERI_CORE_HCTP_MEM_ADJUST_REG_core_tp_tselw_START (5)
#define SOC_FCM_TOPERI_CORE_HCTP_MEM_ADJUST_REG_core_tp_tselw_END (6)
#define SOC_FCM_TOPERI_CORE_HCTP_MEM_ADJUST_REG_core_tp_tra_START (7)
#define SOC_FCM_TOPERI_CORE_HCTP_MEM_ADJUST_REG_core_tp_tra_END (8)
#define SOC_FCM_TOPERI_CORE_HCTP_MEM_ADJUST_REG_core_tp_tselr_hchd_START (9)
#define SOC_FCM_TOPERI_CORE_HCTP_MEM_ADJUST_REG_core_tp_tselr_hchd_END (11)
#define SOC_FCM_TOPERI_CORE_HCTP_MEM_ADJUST_REG_core_hc_test_START (12)
#define SOC_FCM_TOPERI_CORE_HCTP_MEM_ADJUST_REG_core_hc_test_END (14)
#define SOC_FCM_TOPERI_CORE_HCTP_MEM_ADJUST_REG_core_hc_tselr_tp_START (15)
#define SOC_FCM_TOPERI_CORE_HCTP_MEM_ADJUST_REG_core_hc_tselr_tp_END (16)
#define SOC_FCM_TOPERI_CORE_HCTP_MEM_ADJUST_REG_core_hc_tselw_START (17)
#define SOC_FCM_TOPERI_CORE_HCTP_MEM_ADJUST_REG_core_hc_tselw_END (18)
#define SOC_FCM_TOPERI_CORE_HCTP_MEM_ADJUST_REG_core_hc_tra_START (19)
#define SOC_FCM_TOPERI_CORE_HCTP_MEM_ADJUST_REG_core_hc_tra_END (20)
#define SOC_FCM_TOPERI_CORE_HCTP_MEM_ADJUST_REG_core_hc_tselr_hchd_START (21)
#define SOC_FCM_TOPERI_CORE_HCTP_MEM_ADJUST_REG_core_hc_tselr_hchd_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_hd_test : 3;
        unsigned int core_hd_tselr_tp : 2;
        unsigned int core_hd_tselw : 2;
        unsigned int core_hd_tra : 2;
        unsigned int core_hd_tselr_hchd : 3;
        unsigned int core_tp_test : 3;
        unsigned int core_tp_tselr_tp : 2;
        unsigned int core_tp_tselw : 2;
        unsigned int core_tp_tra : 2;
        unsigned int core_tp_tselr_hchd : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_FCM_TOPERI_CORE_HDTP_MEM_ADJUST_REG_UNION;
#endif
#define SOC_FCM_TOPERI_CORE_HDTP_MEM_ADJUST_REG_core_hd_test_START (0)
#define SOC_FCM_TOPERI_CORE_HDTP_MEM_ADJUST_REG_core_hd_test_END (2)
#define SOC_FCM_TOPERI_CORE_HDTP_MEM_ADJUST_REG_core_hd_tselr_tp_START (3)
#define SOC_FCM_TOPERI_CORE_HDTP_MEM_ADJUST_REG_core_hd_tselr_tp_END (4)
#define SOC_FCM_TOPERI_CORE_HDTP_MEM_ADJUST_REG_core_hd_tselw_START (5)
#define SOC_FCM_TOPERI_CORE_HDTP_MEM_ADJUST_REG_core_hd_tselw_END (6)
#define SOC_FCM_TOPERI_CORE_HDTP_MEM_ADJUST_REG_core_hd_tra_START (7)
#define SOC_FCM_TOPERI_CORE_HDTP_MEM_ADJUST_REG_core_hd_tra_END (8)
#define SOC_FCM_TOPERI_CORE_HDTP_MEM_ADJUST_REG_core_hd_tselr_hchd_START (9)
#define SOC_FCM_TOPERI_CORE_HDTP_MEM_ADJUST_REG_core_hd_tselr_hchd_END (11)
#define SOC_FCM_TOPERI_CORE_HDTP_MEM_ADJUST_REG_core_tp_test_START (12)
#define SOC_FCM_TOPERI_CORE_HDTP_MEM_ADJUST_REG_core_tp_test_END (14)
#define SOC_FCM_TOPERI_CORE_HDTP_MEM_ADJUST_REG_core_tp_tselr_tp_START (15)
#define SOC_FCM_TOPERI_CORE_HDTP_MEM_ADJUST_REG_core_tp_tselr_tp_END (16)
#define SOC_FCM_TOPERI_CORE_HDTP_MEM_ADJUST_REG_core_tp_tselw_START (17)
#define SOC_FCM_TOPERI_CORE_HDTP_MEM_ADJUST_REG_core_tp_tselw_END (18)
#define SOC_FCM_TOPERI_CORE_HDTP_MEM_ADJUST_REG_core_tp_tra_START (19)
#define SOC_FCM_TOPERI_CORE_HDTP_MEM_ADJUST_REG_core_tp_tra_END (20)
#define SOC_FCM_TOPERI_CORE_HDTP_MEM_ADJUST_REG_core_tp_tselr_hchd_START (21)
#define SOC_FCM_TOPERI_CORE_HDTP_MEM_ADJUST_REG_core_tp_tselr_hchd_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_noc_nsaid : 2;
        unsigned int fcm_noc_mid : 7;
        unsigned int reserved : 23;
    } reg;
} SOC_FCM_TOPERI_FCM_NOC_NSAID_MID_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_NOC_NSAID_MID_fcm_noc_nsaid_START (0)
#define SOC_FCM_TOPERI_FCM_NOC_NSAID_MID_fcm_noc_nsaid_END (1)
#define SOC_FCM_TOPERI_FCM_NOC_NSAID_MID_fcm_noc_mid_START (2)
#define SOC_FCM_TOPERI_FCM_NOC_NSAID_MID_fcm_noc_mid_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 14;
        unsigned int pcr_sd_in : 6;
        unsigned int fvt_sd_in : 12;
    } reg;
} SOC_FCM_TOPERI_KARMA_PCR_SD_CTRL_UNION;
#endif
#define SOC_FCM_TOPERI_KARMA_PCR_SD_CTRL_pcr_sd_in_START (14)
#define SOC_FCM_TOPERI_KARMA_PCR_SD_CTRL_pcr_sd_in_END (19)
#define SOC_FCM_TOPERI_KARMA_PCR_SD_CTRL_fvt_sd_in_START (20)
#define SOC_FCM_TOPERI_KARMA_PCR_SD_CTRL_fvt_sd_in_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int karma_mem_ctrl_ls : 1;
        unsigned int karma_mem_ctrl_ds : 1;
        unsigned int karma_mem_ctrl_sd : 1;
        unsigned int reserved_0 : 1;
        unsigned int karma_mem_ctrl_tselr : 2;
        unsigned int karma_mem_ctrl_tselw : 2;
        unsigned int karma_mem_ctrl_test : 3;
        unsigned int karma_mem_ctrl_tra : 2;
        unsigned int reserved_1 : 19;
    } reg;
} SOC_FCM_TOPERI_KARMA_PCR_FVT_MEM_CTRL_UNION;
#endif
#define SOC_FCM_TOPERI_KARMA_PCR_FVT_MEM_CTRL_karma_mem_ctrl_ls_START (0)
#define SOC_FCM_TOPERI_KARMA_PCR_FVT_MEM_CTRL_karma_mem_ctrl_ls_END (0)
#define SOC_FCM_TOPERI_KARMA_PCR_FVT_MEM_CTRL_karma_mem_ctrl_ds_START (1)
#define SOC_FCM_TOPERI_KARMA_PCR_FVT_MEM_CTRL_karma_mem_ctrl_ds_END (1)
#define SOC_FCM_TOPERI_KARMA_PCR_FVT_MEM_CTRL_karma_mem_ctrl_sd_START (2)
#define SOC_FCM_TOPERI_KARMA_PCR_FVT_MEM_CTRL_karma_mem_ctrl_sd_END (2)
#define SOC_FCM_TOPERI_KARMA_PCR_FVT_MEM_CTRL_karma_mem_ctrl_tselr_START (4)
#define SOC_FCM_TOPERI_KARMA_PCR_FVT_MEM_CTRL_karma_mem_ctrl_tselr_END (5)
#define SOC_FCM_TOPERI_KARMA_PCR_FVT_MEM_CTRL_karma_mem_ctrl_tselw_START (6)
#define SOC_FCM_TOPERI_KARMA_PCR_FVT_MEM_CTRL_karma_mem_ctrl_tselw_END (7)
#define SOC_FCM_TOPERI_KARMA_PCR_FVT_MEM_CTRL_karma_mem_ctrl_test_START (8)
#define SOC_FCM_TOPERI_KARMA_PCR_FVT_MEM_CTRL_karma_mem_ctrl_test_END (10)
#define SOC_FCM_TOPERI_KARMA_PCR_FVT_MEM_CTRL_karma_mem_ctrl_tra_START (11)
#define SOC_FCM_TOPERI_KARMA_PCR_FVT_MEM_CTRL_karma_mem_ctrl_tra_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int noc_peri_port_i_mainnowrpendtrans : 1;
        unsigned int noc_peri_port_i_mainnorpendtrans : 1;
        unsigned int noc_gic_cfg_t_maintimeout : 1;
        unsigned int noc_gic_cfg_t_mainnopendtrans : 1;
        unsigned int noc_fcm_cfg_t_maintimeout : 1;
        unsigned int noc_fcm_cfg_t_mainnopendtrans : 1;
        unsigned int noc_fcm2sys_t_maintimeout : 1;
        unsigned int noc_fcm2sys_t_mainnopendtrans : 1;
        unsigned int noc_cfg2fcm_i_mainnowrpendingtrans : 1;
        unsigned int noc_cfg2fcm_i_mainnordpendingtrans : 1;
        unsigned int fcm_service_target_mainnopendtrans : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_FCM_TOPERI_FCM_LOCAL_STAT0_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT0_noc_peri_port_i_mainnowrpendtrans_START (0)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT0_noc_peri_port_i_mainnowrpendtrans_END (0)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT0_noc_peri_port_i_mainnorpendtrans_START (1)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT0_noc_peri_port_i_mainnorpendtrans_END (1)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT0_noc_gic_cfg_t_maintimeout_START (2)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT0_noc_gic_cfg_t_maintimeout_END (2)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT0_noc_gic_cfg_t_mainnopendtrans_START (3)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT0_noc_gic_cfg_t_mainnopendtrans_END (3)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT0_noc_fcm_cfg_t_maintimeout_START (4)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT0_noc_fcm_cfg_t_maintimeout_END (4)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT0_noc_fcm_cfg_t_mainnopendtrans_START (5)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT0_noc_fcm_cfg_t_mainnopendtrans_END (5)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT0_noc_fcm2sys_t_maintimeout_START (6)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT0_noc_fcm2sys_t_maintimeout_END (6)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT0_noc_fcm2sys_t_mainnopendtrans_START (7)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT0_noc_fcm2sys_t_mainnopendtrans_END (7)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT0_noc_cfg2fcm_i_mainnowrpendingtrans_START (8)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT0_noc_cfg2fcm_i_mainnowrpendingtrans_END (8)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT0_noc_cfg2fcm_i_mainnordpendingtrans_START (9)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT0_noc_cfg2fcm_i_mainnordpendingtrans_END (9)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT0_fcm_service_target_mainnopendtrans_START (10)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT0_fcm_service_target_mainnopendtrans_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pactive_to_sys : 20;
        unsigned int paccept_to_sys : 1;
        unsigned int reserved_0 : 3;
        unsigned int pdeny_to_sys : 1;
        unsigned int reserved_1 : 3;
        unsigned int cluster_can_pd : 1;
        unsigned int reserved_2 : 2;
        unsigned int forced_on_sfonly_complete : 1;
    } reg;
} SOC_FCM_TOPERI_FCM_LOCAL_STAT2_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT2_pactive_to_sys_START (0)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT2_pactive_to_sys_END (19)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT2_paccept_to_sys_START (20)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT2_paccept_to_sys_END (20)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT2_pdeny_to_sys_START (24)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT2_pdeny_to_sys_END (24)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT2_cluster_can_pd_START (28)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT2_cluster_can_pd_END (28)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT2_forced_on_sfonly_complete_START (31)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT2_forced_on_sfonly_complete_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pactive_to_sys : 18;
        unsigned int reserved_0 : 2;
        unsigned int paccept_to_sys : 1;
        unsigned int reserved_1 : 3;
        unsigned int pdeny_to_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core_can_pd : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_FCM_TOPERI_FCM_LOCAL_STAT3_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT3_pactive_to_sys_START (0)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT3_pactive_to_sys_END (17)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT3_paccept_to_sys_START (20)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT3_paccept_to_sys_END (20)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT3_pdeny_to_sys_START (24)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT3_pdeny_to_sys_END (24)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT3_core_can_pd_START (28)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT3_core_can_pd_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pactive_to_sys : 18;
        unsigned int reserved_0 : 2;
        unsigned int paccept_to_sys : 1;
        unsigned int reserved_1 : 3;
        unsigned int pdeny_to_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core_can_pd : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_FCM_TOPERI_FCM_LOCAL_STAT4_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT4_pactive_to_sys_START (0)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT4_pactive_to_sys_END (17)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT4_paccept_to_sys_START (20)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT4_paccept_to_sys_END (20)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT4_pdeny_to_sys_START (24)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT4_pdeny_to_sys_END (24)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT4_core_can_pd_START (28)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT4_core_can_pd_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pactive_to_sys : 18;
        unsigned int reserved_0 : 2;
        unsigned int paccept_to_sys : 1;
        unsigned int reserved_1 : 3;
        unsigned int pdeny_to_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core_can_pd : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_FCM_TOPERI_FCM_LOCAL_STAT5_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT5_pactive_to_sys_START (0)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT5_pactive_to_sys_END (17)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT5_paccept_to_sys_START (20)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT5_paccept_to_sys_END (20)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT5_pdeny_to_sys_START (24)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT5_pdeny_to_sys_END (24)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT5_core_can_pd_START (28)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT5_core_can_pd_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pactive_to_sys : 18;
        unsigned int reserved_0 : 2;
        unsigned int paccept_to_sys : 1;
        unsigned int reserved_1 : 3;
        unsigned int pdeny_to_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core_can_pd : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_FCM_TOPERI_FCM_LOCAL_STAT6_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT6_pactive_to_sys_START (0)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT6_pactive_to_sys_END (17)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT6_paccept_to_sys_START (20)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT6_paccept_to_sys_END (20)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT6_pdeny_to_sys_START (24)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT6_pdeny_to_sys_END (24)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT6_core_can_pd_START (28)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT6_core_can_pd_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pactive_to_sys : 18;
        unsigned int reserved_0 : 2;
        unsigned int paccept_to_sys : 1;
        unsigned int reserved_1 : 3;
        unsigned int pdeny_to_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core_can_pd : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_FCM_TOPERI_FCM_LOCAL_STAT7_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT7_pactive_to_sys_START (0)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT7_pactive_to_sys_END (17)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT7_paccept_to_sys_START (20)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT7_paccept_to_sys_END (20)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT7_pdeny_to_sys_START (24)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT7_pdeny_to_sys_END (24)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT7_core_can_pd_START (28)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT7_core_can_pd_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pactive_to_sys : 18;
        unsigned int reserved_0 : 2;
        unsigned int paccept_to_sys : 1;
        unsigned int reserved_1 : 3;
        unsigned int pdeny_to_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core_can_pd : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_FCM_TOPERI_FCM_LOCAL_STAT8_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT8_pactive_to_sys_START (0)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT8_pactive_to_sys_END (17)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT8_paccept_to_sys_START (20)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT8_paccept_to_sys_END (20)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT8_pdeny_to_sys_START (24)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT8_pdeny_to_sys_END (24)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT8_core_can_pd_START (28)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT8_core_can_pd_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pactive_to_sys : 18;
        unsigned int reserved_0 : 2;
        unsigned int paccept_to_sys : 1;
        unsigned int reserved_1 : 3;
        unsigned int pdeny_to_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core_can_pd : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_FCM_TOPERI_FCM_LOCAL_STAT9_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT9_pactive_to_sys_START (0)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT9_pactive_to_sys_END (17)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT9_paccept_to_sys_START (20)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT9_paccept_to_sys_END (20)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT9_pdeny_to_sys_START (24)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT9_pdeny_to_sys_END (24)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT9_core_can_pd_START (28)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT9_core_can_pd_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pactive_to_sys : 18;
        unsigned int reserved_0 : 2;
        unsigned int paccept_to_sys : 1;
        unsigned int reserved_1 : 3;
        unsigned int pdeny_to_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core_can_pd : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_FCM_TOPERI_FCM_LOCAL_STAT10_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT10_pactive_to_sys_START (0)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT10_pactive_to_sys_END (17)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT10_paccept_to_sys_START (20)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT10_paccept_to_sys_END (20)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT10_pdeny_to_sys_START (24)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT10_pdeny_to_sys_END (24)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT10_core_can_pd_START (28)
#define SOC_FCM_TOPERI_FCM_LOCAL_STAT10_core_can_pd_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cluster_paccept : 1;
        unsigned int cluster_pdeny : 1;
        unsigned int cluster_preq : 1;
        unsigned int reserved_0 : 1;
        unsigned int cluster_pstate : 7;
        unsigned int reserved_1 : 1;
        unsigned int cluster_pactive : 20;
    } reg;
} SOC_FCM_TOPERI_FCM_PCHANNEL_STAT_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_PCHANNEL_STAT_cluster_paccept_START (0)
#define SOC_FCM_TOPERI_FCM_PCHANNEL_STAT_cluster_paccept_END (0)
#define SOC_FCM_TOPERI_FCM_PCHANNEL_STAT_cluster_pdeny_START (1)
#define SOC_FCM_TOPERI_FCM_PCHANNEL_STAT_cluster_pdeny_END (1)
#define SOC_FCM_TOPERI_FCM_PCHANNEL_STAT_cluster_preq_START (2)
#define SOC_FCM_TOPERI_FCM_PCHANNEL_STAT_cluster_preq_END (2)
#define SOC_FCM_TOPERI_FCM_PCHANNEL_STAT_cluster_pstate_START (4)
#define SOC_FCM_TOPERI_FCM_PCHANNEL_STAT_cluster_pstate_END (10)
#define SOC_FCM_TOPERI_FCM_PCHANNEL_STAT_cluster_pactive_START (12)
#define SOC_FCM_TOPERI_FCM_PCHANNEL_STAT_cluster_pactive_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_paccept : 1;
        unsigned int core_pdeny : 1;
        unsigned int core_preq : 1;
        unsigned int reserved_0 : 1;
        unsigned int core_pstate : 7;
        unsigned int reserved_1 : 1;
        unsigned int core_pactive : 18;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_FCM_TOPERI_FCM_CORE0_PCHANNEL_STAT_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_CORE0_PCHANNEL_STAT_core_paccept_START (0)
#define SOC_FCM_TOPERI_FCM_CORE0_PCHANNEL_STAT_core_paccept_END (0)
#define SOC_FCM_TOPERI_FCM_CORE0_PCHANNEL_STAT_core_pdeny_START (1)
#define SOC_FCM_TOPERI_FCM_CORE0_PCHANNEL_STAT_core_pdeny_END (1)
#define SOC_FCM_TOPERI_FCM_CORE0_PCHANNEL_STAT_core_preq_START (2)
#define SOC_FCM_TOPERI_FCM_CORE0_PCHANNEL_STAT_core_preq_END (2)
#define SOC_FCM_TOPERI_FCM_CORE0_PCHANNEL_STAT_core_pstate_START (4)
#define SOC_FCM_TOPERI_FCM_CORE0_PCHANNEL_STAT_core_pstate_END (10)
#define SOC_FCM_TOPERI_FCM_CORE0_PCHANNEL_STAT_core_pactive_START (12)
#define SOC_FCM_TOPERI_FCM_CORE0_PCHANNEL_STAT_core_pactive_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_paccept : 1;
        unsigned int core_pdeny : 1;
        unsigned int core_preq : 1;
        unsigned int reserved_0 : 1;
        unsigned int core_pstate : 7;
        unsigned int reserved_1 : 1;
        unsigned int core_pactive : 18;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_FCM_TOPERI_FCM_CORE1_PCHANNEL_STAT_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_CORE1_PCHANNEL_STAT_core_paccept_START (0)
#define SOC_FCM_TOPERI_FCM_CORE1_PCHANNEL_STAT_core_paccept_END (0)
#define SOC_FCM_TOPERI_FCM_CORE1_PCHANNEL_STAT_core_pdeny_START (1)
#define SOC_FCM_TOPERI_FCM_CORE1_PCHANNEL_STAT_core_pdeny_END (1)
#define SOC_FCM_TOPERI_FCM_CORE1_PCHANNEL_STAT_core_preq_START (2)
#define SOC_FCM_TOPERI_FCM_CORE1_PCHANNEL_STAT_core_preq_END (2)
#define SOC_FCM_TOPERI_FCM_CORE1_PCHANNEL_STAT_core_pstate_START (4)
#define SOC_FCM_TOPERI_FCM_CORE1_PCHANNEL_STAT_core_pstate_END (10)
#define SOC_FCM_TOPERI_FCM_CORE1_PCHANNEL_STAT_core_pactive_START (12)
#define SOC_FCM_TOPERI_FCM_CORE1_PCHANNEL_STAT_core_pactive_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_paccept : 1;
        unsigned int core_pdeny : 1;
        unsigned int core_preq : 1;
        unsigned int reserved_0 : 1;
        unsigned int core_pstate : 7;
        unsigned int reserved_1 : 1;
        unsigned int core_pactive : 18;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_FCM_TOPERI_FCM_CORE2_PCHANNEL_STAT_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_CORE2_PCHANNEL_STAT_core_paccept_START (0)
#define SOC_FCM_TOPERI_FCM_CORE2_PCHANNEL_STAT_core_paccept_END (0)
#define SOC_FCM_TOPERI_FCM_CORE2_PCHANNEL_STAT_core_pdeny_START (1)
#define SOC_FCM_TOPERI_FCM_CORE2_PCHANNEL_STAT_core_pdeny_END (1)
#define SOC_FCM_TOPERI_FCM_CORE2_PCHANNEL_STAT_core_preq_START (2)
#define SOC_FCM_TOPERI_FCM_CORE2_PCHANNEL_STAT_core_preq_END (2)
#define SOC_FCM_TOPERI_FCM_CORE2_PCHANNEL_STAT_core_pstate_START (4)
#define SOC_FCM_TOPERI_FCM_CORE2_PCHANNEL_STAT_core_pstate_END (10)
#define SOC_FCM_TOPERI_FCM_CORE2_PCHANNEL_STAT_core_pactive_START (12)
#define SOC_FCM_TOPERI_FCM_CORE2_PCHANNEL_STAT_core_pactive_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_paccept : 1;
        unsigned int core_pdeny : 1;
        unsigned int core_preq : 1;
        unsigned int reserved_0 : 1;
        unsigned int core_pstate : 7;
        unsigned int reserved_1 : 1;
        unsigned int core_pactive : 18;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_FCM_TOPERI_FCM_CORE3_PCHANNEL_STAT_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_CORE3_PCHANNEL_STAT_core_paccept_START (0)
#define SOC_FCM_TOPERI_FCM_CORE3_PCHANNEL_STAT_core_paccept_END (0)
#define SOC_FCM_TOPERI_FCM_CORE3_PCHANNEL_STAT_core_pdeny_START (1)
#define SOC_FCM_TOPERI_FCM_CORE3_PCHANNEL_STAT_core_pdeny_END (1)
#define SOC_FCM_TOPERI_FCM_CORE3_PCHANNEL_STAT_core_preq_START (2)
#define SOC_FCM_TOPERI_FCM_CORE3_PCHANNEL_STAT_core_preq_END (2)
#define SOC_FCM_TOPERI_FCM_CORE3_PCHANNEL_STAT_core_pstate_START (4)
#define SOC_FCM_TOPERI_FCM_CORE3_PCHANNEL_STAT_core_pstate_END (10)
#define SOC_FCM_TOPERI_FCM_CORE3_PCHANNEL_STAT_core_pactive_START (12)
#define SOC_FCM_TOPERI_FCM_CORE3_PCHANNEL_STAT_core_pactive_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_paccept : 1;
        unsigned int core_pdeny : 1;
        unsigned int core_preq : 1;
        unsigned int reserved_0 : 1;
        unsigned int core_pstate : 7;
        unsigned int reserved_1 : 1;
        unsigned int core_pactive : 18;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_FCM_TOPERI_FCM_CORE4_PCHANNEL_STAT_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_CORE4_PCHANNEL_STAT_core_paccept_START (0)
#define SOC_FCM_TOPERI_FCM_CORE4_PCHANNEL_STAT_core_paccept_END (0)
#define SOC_FCM_TOPERI_FCM_CORE4_PCHANNEL_STAT_core_pdeny_START (1)
#define SOC_FCM_TOPERI_FCM_CORE4_PCHANNEL_STAT_core_pdeny_END (1)
#define SOC_FCM_TOPERI_FCM_CORE4_PCHANNEL_STAT_core_preq_START (2)
#define SOC_FCM_TOPERI_FCM_CORE4_PCHANNEL_STAT_core_preq_END (2)
#define SOC_FCM_TOPERI_FCM_CORE4_PCHANNEL_STAT_core_pstate_START (4)
#define SOC_FCM_TOPERI_FCM_CORE4_PCHANNEL_STAT_core_pstate_END (10)
#define SOC_FCM_TOPERI_FCM_CORE4_PCHANNEL_STAT_core_pactive_START (12)
#define SOC_FCM_TOPERI_FCM_CORE4_PCHANNEL_STAT_core_pactive_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_paccept : 1;
        unsigned int core_pdeny : 1;
        unsigned int core_preq : 1;
        unsigned int reserved_0 : 1;
        unsigned int core_pstate : 7;
        unsigned int reserved_1 : 1;
        unsigned int core_pactive : 18;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_FCM_TOPERI_FCM_CORE5_PCHANNEL_STAT_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_CORE5_PCHANNEL_STAT_core_paccept_START (0)
#define SOC_FCM_TOPERI_FCM_CORE5_PCHANNEL_STAT_core_paccept_END (0)
#define SOC_FCM_TOPERI_FCM_CORE5_PCHANNEL_STAT_core_pdeny_START (1)
#define SOC_FCM_TOPERI_FCM_CORE5_PCHANNEL_STAT_core_pdeny_END (1)
#define SOC_FCM_TOPERI_FCM_CORE5_PCHANNEL_STAT_core_preq_START (2)
#define SOC_FCM_TOPERI_FCM_CORE5_PCHANNEL_STAT_core_preq_END (2)
#define SOC_FCM_TOPERI_FCM_CORE5_PCHANNEL_STAT_core_pstate_START (4)
#define SOC_FCM_TOPERI_FCM_CORE5_PCHANNEL_STAT_core_pstate_END (10)
#define SOC_FCM_TOPERI_FCM_CORE5_PCHANNEL_STAT_core_pactive_START (12)
#define SOC_FCM_TOPERI_FCM_CORE5_PCHANNEL_STAT_core_pactive_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_paccept : 1;
        unsigned int core_pdeny : 1;
        unsigned int core_preq : 1;
        unsigned int reserved_0 : 1;
        unsigned int core_pstate : 7;
        unsigned int reserved_1 : 1;
        unsigned int core_pactive : 18;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_FCM_TOPERI_FCM_CORE6_PCHANNEL_STAT_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_CORE6_PCHANNEL_STAT_core_paccept_START (0)
#define SOC_FCM_TOPERI_FCM_CORE6_PCHANNEL_STAT_core_paccept_END (0)
#define SOC_FCM_TOPERI_FCM_CORE6_PCHANNEL_STAT_core_pdeny_START (1)
#define SOC_FCM_TOPERI_FCM_CORE6_PCHANNEL_STAT_core_pdeny_END (1)
#define SOC_FCM_TOPERI_FCM_CORE6_PCHANNEL_STAT_core_preq_START (2)
#define SOC_FCM_TOPERI_FCM_CORE6_PCHANNEL_STAT_core_preq_END (2)
#define SOC_FCM_TOPERI_FCM_CORE6_PCHANNEL_STAT_core_pstate_START (4)
#define SOC_FCM_TOPERI_FCM_CORE6_PCHANNEL_STAT_core_pstate_END (10)
#define SOC_FCM_TOPERI_FCM_CORE6_PCHANNEL_STAT_core_pactive_START (12)
#define SOC_FCM_TOPERI_FCM_CORE6_PCHANNEL_STAT_core_pactive_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_paccept : 1;
        unsigned int core_pdeny : 1;
        unsigned int core_preq : 1;
        unsigned int reserved_0 : 1;
        unsigned int core_pstate : 7;
        unsigned int reserved_1 : 1;
        unsigned int core_pactive : 18;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_FCM_TOPERI_FCM_CORE7_PCHANNEL_STAT_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_CORE7_PCHANNEL_STAT_core_paccept_START (0)
#define SOC_FCM_TOPERI_FCM_CORE7_PCHANNEL_STAT_core_paccept_END (0)
#define SOC_FCM_TOPERI_FCM_CORE7_PCHANNEL_STAT_core_pdeny_START (1)
#define SOC_FCM_TOPERI_FCM_CORE7_PCHANNEL_STAT_core_pdeny_END (1)
#define SOC_FCM_TOPERI_FCM_CORE7_PCHANNEL_STAT_core_preq_START (2)
#define SOC_FCM_TOPERI_FCM_CORE7_PCHANNEL_STAT_core_preq_END (2)
#define SOC_FCM_TOPERI_FCM_CORE7_PCHANNEL_STAT_core_pstate_START (4)
#define SOC_FCM_TOPERI_FCM_CORE7_PCHANNEL_STAT_core_pstate_END (10)
#define SOC_FCM_TOPERI_FCM_CORE7_PCHANNEL_STAT_core_pactive_START (12)
#define SOC_FCM_TOPERI_FCM_CORE7_PCHANNEL_STAT_core_pactive_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int current_state0 : 4;
        unsigned int core_pstate0 : 6;
        unsigned int reserved_0 : 6;
        unsigned int current_state1 : 4;
        unsigned int core_pstate1 : 6;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_FCM_TOPERI_FCM_CORE01_PCHANNEL_DEBUG_STAT_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_CORE01_PCHANNEL_DEBUG_STAT_current_state0_START (0)
#define SOC_FCM_TOPERI_FCM_CORE01_PCHANNEL_DEBUG_STAT_current_state0_END (3)
#define SOC_FCM_TOPERI_FCM_CORE01_PCHANNEL_DEBUG_STAT_core_pstate0_START (4)
#define SOC_FCM_TOPERI_FCM_CORE01_PCHANNEL_DEBUG_STAT_core_pstate0_END (9)
#define SOC_FCM_TOPERI_FCM_CORE01_PCHANNEL_DEBUG_STAT_current_state1_START (16)
#define SOC_FCM_TOPERI_FCM_CORE01_PCHANNEL_DEBUG_STAT_current_state1_END (19)
#define SOC_FCM_TOPERI_FCM_CORE01_PCHANNEL_DEBUG_STAT_core_pstate1_START (20)
#define SOC_FCM_TOPERI_FCM_CORE01_PCHANNEL_DEBUG_STAT_core_pstate1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int current_state2 : 4;
        unsigned int core_pstate2 : 6;
        unsigned int reserved_0 : 6;
        unsigned int current_state3 : 4;
        unsigned int core_pstate3 : 6;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_FCM_TOPERI_FCM_CORE23_PCHANNEL_DEBUG_STAT_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_CORE23_PCHANNEL_DEBUG_STAT_current_state2_START (0)
#define SOC_FCM_TOPERI_FCM_CORE23_PCHANNEL_DEBUG_STAT_current_state2_END (3)
#define SOC_FCM_TOPERI_FCM_CORE23_PCHANNEL_DEBUG_STAT_core_pstate2_START (4)
#define SOC_FCM_TOPERI_FCM_CORE23_PCHANNEL_DEBUG_STAT_core_pstate2_END (9)
#define SOC_FCM_TOPERI_FCM_CORE23_PCHANNEL_DEBUG_STAT_current_state3_START (16)
#define SOC_FCM_TOPERI_FCM_CORE23_PCHANNEL_DEBUG_STAT_current_state3_END (19)
#define SOC_FCM_TOPERI_FCM_CORE23_PCHANNEL_DEBUG_STAT_core_pstate3_START (20)
#define SOC_FCM_TOPERI_FCM_CORE23_PCHANNEL_DEBUG_STAT_core_pstate3_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int current_state4 : 4;
        unsigned int core_pstate4 : 6;
        unsigned int reserved_0 : 6;
        unsigned int current_state5 : 4;
        unsigned int core_pstate5 : 6;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_FCM_TOPERI_FCM_CORE45_PCHANNEL_DEBUG_STAT_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_CORE45_PCHANNEL_DEBUG_STAT_current_state4_START (0)
#define SOC_FCM_TOPERI_FCM_CORE45_PCHANNEL_DEBUG_STAT_current_state4_END (3)
#define SOC_FCM_TOPERI_FCM_CORE45_PCHANNEL_DEBUG_STAT_core_pstate4_START (4)
#define SOC_FCM_TOPERI_FCM_CORE45_PCHANNEL_DEBUG_STAT_core_pstate4_END (9)
#define SOC_FCM_TOPERI_FCM_CORE45_PCHANNEL_DEBUG_STAT_current_state5_START (16)
#define SOC_FCM_TOPERI_FCM_CORE45_PCHANNEL_DEBUG_STAT_current_state5_END (19)
#define SOC_FCM_TOPERI_FCM_CORE45_PCHANNEL_DEBUG_STAT_core_pstate5_START (20)
#define SOC_FCM_TOPERI_FCM_CORE45_PCHANNEL_DEBUG_STAT_core_pstate5_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int current_state6 : 4;
        unsigned int core_pstate6 : 6;
        unsigned int reserved_0 : 6;
        unsigned int current_state7 : 4;
        unsigned int core_pstate7 : 6;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_FCM_TOPERI_FCM_CORE67_PCHANNEL_DEBUG_STAT_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_CORE67_PCHANNEL_DEBUG_STAT_current_state6_START (0)
#define SOC_FCM_TOPERI_FCM_CORE67_PCHANNEL_DEBUG_STAT_current_state6_END (3)
#define SOC_FCM_TOPERI_FCM_CORE67_PCHANNEL_DEBUG_STAT_core_pstate6_START (4)
#define SOC_FCM_TOPERI_FCM_CORE67_PCHANNEL_DEBUG_STAT_core_pstate6_END (9)
#define SOC_FCM_TOPERI_FCM_CORE67_PCHANNEL_DEBUG_STAT_current_state7_START (16)
#define SOC_FCM_TOPERI_FCM_CORE67_PCHANNEL_DEBUG_STAT_current_state7_END (19)
#define SOC_FCM_TOPERI_FCM_CORE67_PCHANNEL_DEBUG_STAT_core_pstate7_START (20)
#define SOC_FCM_TOPERI_FCM_CORE67_PCHANNEL_DEBUG_STAT_core_pstate7_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cluster_current_state : 6;
        unsigned int cluster_pstate : 7;
        unsigned int reserved_0 : 3;
        unsigned int cluster_current_state_flush_cache : 3;
        unsigned int cluster_off_flush_cache_valid : 1;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_FCM_TOPERI_FCM_FCM_PCHANNEL_DEBUG_STAT_UNION;
#endif
#define SOC_FCM_TOPERI_FCM_FCM_PCHANNEL_DEBUG_STAT_cluster_current_state_START (0)
#define SOC_FCM_TOPERI_FCM_FCM_PCHANNEL_DEBUG_STAT_cluster_current_state_END (5)
#define SOC_FCM_TOPERI_FCM_FCM_PCHANNEL_DEBUG_STAT_cluster_pstate_START (6)
#define SOC_FCM_TOPERI_FCM_FCM_PCHANNEL_DEBUG_STAT_cluster_pstate_END (12)
#define SOC_FCM_TOPERI_FCM_FCM_PCHANNEL_DEBUG_STAT_cluster_current_state_flush_cache_START (16)
#define SOC_FCM_TOPERI_FCM_FCM_PCHANNEL_DEBUG_STAT_cluster_current_state_flush_cache_END (18)
#define SOC_FCM_TOPERI_FCM_FCM_PCHANNEL_DEBUG_STAT_cluster_off_flush_cache_valid_START (19)
#define SOC_FCM_TOPERI_FCM_FCM_PCHANNEL_DEBUG_STAT_cluster_off_flush_cache_valid_END (19)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
