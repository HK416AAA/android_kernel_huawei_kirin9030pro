#ifndef __SOC_FFAP1_INTERFACE_H__
#define __SOC_FFAP1_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_FFAP1_CKG_CTRL_ADDR(base) ((base) + (0x1000UL))
#define SOC_FFAP1_CMN_CTRL0_ADDR(base) ((base) + (0x1004UL))
#define SOC_FFAP1_CMN_CTRL1_ADDR(base) ((base) + (0x1080UL))
#define SOC_FFAP1_LINK_CTRL_PT_ADDR(base) ((base) + (0x1008UL))
#define SOC_FFAP1_LINK_CTRL_TD_ADDR(base) ((base) + (0x100CUL))
#define SOC_FFAP1_DFX_HW_LINK_ST_ADDR(base) ((base) + (0x1010UL))
#define SOC_FFAP1_CONNECT_ST_ADDR(base) ((base) + (0x1014UL))
#define SOC_FFAP1_DRAIN_TH_ADDR(base) ((base) + (0x1018UL))
#define SOC_FFAP1_DFX_COMM_ADDR(base) ((base) + (0x101CUL))
#define SOC_FFAP1_DFX_PT_CNT_ADDR(base) ((base) + (0x1020UL))
#define SOC_FFAP1_DFX_TD_CNT_ADDR(base) ((base) + (0x1024UL))
#define SOC_FFAP1_DFX_RECORD_CTRL_ADDR(base) ((base) + (0x1028UL))
#define SOC_FFAP1_DFX_PUSHTASK_ADDR(base,PT_NUM) ((base) + ((PT_NUM)*4+0x102CUL))
#define SOC_FFAP1_DFX_TASKDONE_ADDR(base) ((base) + (0x1038UL))
#define SOC_FFAP1_DFX_CREDIT_OST_ADDR(base) ((base) + (0x103CUL))
#define SOC_FFAP1_CKB_TASKDONE_PLD_ADDR(base) ((base) + (0x1040UL))
#define SOC_FFAP1_CKB_TASKDONE_CTRL_ADDR(base) ((base) + (0x1044UL))
#define SOC_FFAP1_DFX_MASK_ADDR(base) ((base) + (0x1048UL))
#define SOC_FFAP1_DFX_CLR_ADDR(base) ((base) + (0x104CUL))
#define SOC_FFAP1_DFX_ORG_STATUS_ADDR(base) ((base) + (0x1050UL))
#define SOC_FFAP1_DFX_MASK_STATUS_ADDR(base) ((base) + (0x1054UL))
#define SOC_FFAP1_DFX_TYPE_ADDR(base) ((base) + (0x1058UL))
#define SOC_FFAP1_DFX_INFO_ADDR(base,CORE_DFXINFO_NUM) ((base) + ((CORE_DFXINFO_NUM)*4+0x1060UL))
#else
#define SOC_FFAP1_CKG_CTRL_ADDR(base) ((base) + (0x1000))
#define SOC_FFAP1_CMN_CTRL0_ADDR(base) ((base) + (0x1004))
#define SOC_FFAP1_CMN_CTRL1_ADDR(base) ((base) + (0x1080))
#define SOC_FFAP1_LINK_CTRL_PT_ADDR(base) ((base) + (0x1008))
#define SOC_FFAP1_LINK_CTRL_TD_ADDR(base) ((base) + (0x100C))
#define SOC_FFAP1_DFX_HW_LINK_ST_ADDR(base) ((base) + (0x1010))
#define SOC_FFAP1_CONNECT_ST_ADDR(base) ((base) + (0x1014))
#define SOC_FFAP1_DRAIN_TH_ADDR(base) ((base) + (0x1018))
#define SOC_FFAP1_DFX_COMM_ADDR(base) ((base) + (0x101C))
#define SOC_FFAP1_DFX_PT_CNT_ADDR(base) ((base) + (0x1020))
#define SOC_FFAP1_DFX_TD_CNT_ADDR(base) ((base) + (0x1024))
#define SOC_FFAP1_DFX_RECORD_CTRL_ADDR(base) ((base) + (0x1028))
#define SOC_FFAP1_DFX_PUSHTASK_ADDR(base,PT_NUM) ((base) + ((PT_NUM)*4+0x102C))
#define SOC_FFAP1_DFX_TASKDONE_ADDR(base) ((base) + (0x1038))
#define SOC_FFAP1_DFX_CREDIT_OST_ADDR(base) ((base) + (0x103C))
#define SOC_FFAP1_CKB_TASKDONE_PLD_ADDR(base) ((base) + (0x1040))
#define SOC_FFAP1_CKB_TASKDONE_CTRL_ADDR(base) ((base) + (0x1044))
#define SOC_FFAP1_DFX_MASK_ADDR(base) ((base) + (0x1048))
#define SOC_FFAP1_DFX_CLR_ADDR(base) ((base) + (0x104C))
#define SOC_FFAP1_DFX_ORG_STATUS_ADDR(base) ((base) + (0x1050))
#define SOC_FFAP1_DFX_MASK_STATUS_ADDR(base) ((base) + (0x1054))
#define SOC_FFAP1_DFX_TYPE_ADDR(base) ((base) + (0x1058))
#define SOC_FFAP1_DFX_INFO_ADDR(base,CORE_DFXINFO_NUM) ((base) + ((CORE_DFXINFO_NUM)*4+0x1060))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_FFAP1_CPUIF_CKG_CTRL_ADDR(base) ((base) + (0x1800UL))
#define SOC_FFAP1_CPUIF_LINK_PT_ADDR(base) ((base) + (0x1804UL))
#define SOC_FFAP1_CPUIF_LINK_TD_ADDR(base) ((base) + (0x1808UL))
#define SOC_FFAP1_CPUIF_PUSHTASK_POP_ADDR(base) ((base) + (0x180CUL))
#define SOC_FFAP1_CPUIF_PUSHTASK_ADDR(base,PT_NUM) ((base) + ((PT_NUM)*4+0x1814UL))
#define SOC_FFAP1_CPUIF_TASKDONE_ADDR(base) ((base) + (0x1820UL))
#define SOC_FFAP1_CPUIF_ABNORMAL_ADDR(base) ((base) + (0x1824UL))
#define SOC_FFAP1_CPUIF_DRAIN_UID_ADDR(base) ((base) + (0x1828UL))
#define SOC_FFAP1_CPUIF_WKINTR_CTRL_ADDR(base) ((base) + (0x182CUL))
#define SOC_FFAP1_CPUIF_WKINTR_ST_ADDR(base) ((base) + (0x1830UL))
#define SOC_FFAP1_CPUIF_WKINTR_CLR_ADDR(base) ((base) + (0x1834UL))
#define SOC_FFAP1_CPUIF_INTR_EN_ADDR(base) ((base) + (0x1838UL))
#define SOC_FFAP1_CPUIF_INTR_ST_ADDR(base) ((base) + (0x183CUL))
#define SOC_FFAP1_CPUIF_INTR_CLR_ADDR(base) ((base) + (0x1840UL))
#define SOC_FFAP1_CPUIF_DBG_RD_ADDR(base) ((base) + (0x1844UL))
#define SOC_FFAP1_CPUIF_DBG_INFO0_ADDR(base) ((base) + (0x1848UL))
#define SOC_FFAP1_CPUIF_DBG_INFO1_ADDR(base) ((base) + (0x184CUL))
#define SOC_FFAP1_CPUIF_DBG_INFO2_ADDR(base) ((base) + (0x1850UL))
#define SOC_FFAP1_CPUIF_DFX_TASK_ADDR(base) ((base) + (0x1854UL))
#define SOC_FFAP1_CPUIF_DFX_MASK_ADDR(base) ((base) + (0x1858UL))
#define SOC_FFAP1_CPUIF_DFX_CLR_ADDR(base) ((base) + (0x185CUL))
#define SOC_FFAP1_CPUIF_DFX_ORG_STATUS_ADDR(base) ((base) + (0x1860UL))
#define SOC_FFAP1_CPUIF_DFX_MASK_STATUS_ADDR(base) ((base) + (0x1864UL))
#define SOC_FFAP1_CPUIF_DFX_TYPE_ADDR(base) ((base) + (0x1868UL))
#define SOC_FFAP1_CPUIF_DFX_INFO_ADDR(base,CPUIF_DFXINFO_NUM) ((base) + ((CPUIF_DFXINFO_NUM)*4+0x186CUL))
#define SOC_FFAP1_CPUIF_RESUME_EN_ADDR(base) ((base) + (0x1880UL))
#define SOC_FFAP1_CPUIF_RESUME_INFO0_ADDR(base) ((base) + (0x1884UL))
#define SOC_FFAP1_CPUIF_RESUME_INFO1_ADDR(base) ((base) + (0x1888UL))
#define SOC_FFAP1_CPUIF_RESUME_INFO2_ADDR(base) ((base) + (0x188CUL))
#define SOC_FFAP1_CPUIF_DFX_BUSY_ADDR(base) ((base) + (0x1890UL))
#else
#define SOC_FFAP1_CPUIF_CKG_CTRL_ADDR(base) ((base) + (0x1800))
#define SOC_FFAP1_CPUIF_LINK_PT_ADDR(base) ((base) + (0x1804))
#define SOC_FFAP1_CPUIF_LINK_TD_ADDR(base) ((base) + (0x1808))
#define SOC_FFAP1_CPUIF_PUSHTASK_POP_ADDR(base) ((base) + (0x180C))
#define SOC_FFAP1_CPUIF_PUSHTASK_ADDR(base,PT_NUM) ((base) + ((PT_NUM)*4+0x1814))
#define SOC_FFAP1_CPUIF_TASKDONE_ADDR(base) ((base) + (0x1820))
#define SOC_FFAP1_CPUIF_ABNORMAL_ADDR(base) ((base) + (0x1824))
#define SOC_FFAP1_CPUIF_DRAIN_UID_ADDR(base) ((base) + (0x1828))
#define SOC_FFAP1_CPUIF_WKINTR_CTRL_ADDR(base) ((base) + (0x182C))
#define SOC_FFAP1_CPUIF_WKINTR_ST_ADDR(base) ((base) + (0x1830))
#define SOC_FFAP1_CPUIF_WKINTR_CLR_ADDR(base) ((base) + (0x1834))
#define SOC_FFAP1_CPUIF_INTR_EN_ADDR(base) ((base) + (0x1838))
#define SOC_FFAP1_CPUIF_INTR_ST_ADDR(base) ((base) + (0x183C))
#define SOC_FFAP1_CPUIF_INTR_CLR_ADDR(base) ((base) + (0x1840))
#define SOC_FFAP1_CPUIF_DBG_RD_ADDR(base) ((base) + (0x1844))
#define SOC_FFAP1_CPUIF_DBG_INFO0_ADDR(base) ((base) + (0x1848))
#define SOC_FFAP1_CPUIF_DBG_INFO1_ADDR(base) ((base) + (0x184C))
#define SOC_FFAP1_CPUIF_DBG_INFO2_ADDR(base) ((base) + (0x1850))
#define SOC_FFAP1_CPUIF_DFX_TASK_ADDR(base) ((base) + (0x1854))
#define SOC_FFAP1_CPUIF_DFX_MASK_ADDR(base) ((base) + (0x1858))
#define SOC_FFAP1_CPUIF_DFX_CLR_ADDR(base) ((base) + (0x185C))
#define SOC_FFAP1_CPUIF_DFX_ORG_STATUS_ADDR(base) ((base) + (0x1860))
#define SOC_FFAP1_CPUIF_DFX_MASK_STATUS_ADDR(base) ((base) + (0x1864))
#define SOC_FFAP1_CPUIF_DFX_TYPE_ADDR(base) ((base) + (0x1868))
#define SOC_FFAP1_CPUIF_DFX_INFO_ADDR(base,CPUIF_DFXINFO_NUM) ((base) + ((CPUIF_DFXINFO_NUM)*4+0x186C))
#define SOC_FFAP1_CPUIF_RESUME_EN_ADDR(base) ((base) + (0x1880))
#define SOC_FFAP1_CPUIF_RESUME_INFO0_ADDR(base) ((base) + (0x1884))
#define SOC_FFAP1_CPUIF_RESUME_INFO1_ADDR(base) ((base) + (0x1888))
#define SOC_FFAP1_CPUIF_RESUME_INFO2_ADDR(base) ((base) + (0x188C))
#define SOC_FFAP1_CPUIF_DFX_BUSY_ADDR(base) ((base) + (0x1890))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ckg_bypass : 1;
        unsigned int ckg_ext : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_FFAP1_CKG_CTRL_UNION;
#endif
#define SOC_FFAP1_CKG_CTRL_ckg_bypass_START (0)
#define SOC_FFAP1_CKG_CTRL_ckg_bypass_END (0)
#define SOC_FFAP1_CKG_CTRL_ckg_ext_START (1)
#define SOC_FFAP1_CKG_CTRL_ckg_ext_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int link_ctrl_sel : 1;
        unsigned int cfg_hw_td_link_ack : 1;
        unsigned int cfg_hw_pt_link_ack : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_FFAP1_CMN_CTRL0_UNION;
#endif
#define SOC_FFAP1_CMN_CTRL0_link_ctrl_sel_START (0)
#define SOC_FFAP1_CMN_CTRL0_link_ctrl_sel_END (0)
#define SOC_FFAP1_CMN_CTRL0_cfg_hw_td_link_ack_START (1)
#define SOC_FFAP1_CMN_CTRL0_cfg_hw_td_link_ack_END (1)
#define SOC_FFAP1_CMN_CTRL0_cfg_hw_pt_link_ack_START (2)
#define SOC_FFAP1_CMN_CTRL0_cfg_hw_pt_link_ack_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int link_notify_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FFAP1_CMN_CTRL1_UNION;
#endif
#define SOC_FFAP1_CMN_CTRL1_link_notify_en_START (0)
#define SOC_FFAP1_CMN_CTRL1_link_notify_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_pt_link_req : 1;
        unsigned int cfg_pt_link_ack : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_FFAP1_LINK_CTRL_PT_UNION;
#endif
#define SOC_FFAP1_LINK_CTRL_PT_cfg_pt_link_req_START (0)
#define SOC_FFAP1_LINK_CTRL_PT_cfg_pt_link_req_END (0)
#define SOC_FFAP1_LINK_CTRL_PT_cfg_pt_link_ack_START (1)
#define SOC_FFAP1_LINK_CTRL_PT_cfg_pt_link_ack_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_td_link_req : 1;
        unsigned int cfg_td_link_ack : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_FFAP1_LINK_CTRL_TD_UNION;
#endif
#define SOC_FFAP1_LINK_CTRL_TD_cfg_td_link_req_START (0)
#define SOC_FFAP1_LINK_CTRL_TD_cfg_td_link_req_END (0)
#define SOC_FFAP1_LINK_CTRL_TD_cfg_td_link_ack_START (1)
#define SOC_FFAP1_LINK_CTRL_TD_cfg_td_link_ack_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hw_pt_link_req : 1;
        unsigned int hw_pt_link_ack : 1;
        unsigned int hw_td_link_req : 1;
        unsigned int hw_td_link_ack : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_FFAP1_DFX_HW_LINK_ST_UNION;
#endif
#define SOC_FFAP1_DFX_HW_LINK_ST_hw_pt_link_req_START (0)
#define SOC_FFAP1_DFX_HW_LINK_ST_hw_pt_link_req_END (0)
#define SOC_FFAP1_DFX_HW_LINK_ST_hw_pt_link_ack_START (1)
#define SOC_FFAP1_DFX_HW_LINK_ST_hw_pt_link_ack_END (1)
#define SOC_FFAP1_DFX_HW_LINK_ST_hw_td_link_req_START (2)
#define SOC_FFAP1_DFX_HW_LINK_ST_hw_td_link_req_END (2)
#define SOC_FFAP1_DFX_HW_LINK_ST_hw_td_link_ack_START (3)
#define SOC_FFAP1_DFX_HW_LINK_ST_hw_td_link_ack_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pushtask_link_st : 2;
        unsigned int taskdone_link_st : 2;
        unsigned int reserved : 28;
    } reg;
} SOC_FFAP1_CONNECT_ST_UNION;
#endif
#define SOC_FFAP1_CONNECT_ST_pushtask_link_st_START (0)
#define SOC_FFAP1_CONNECT_ST_pushtask_link_st_END (1)
#define SOC_FFAP1_CONNECT_ST_taskdone_link_st_START (2)
#define SOC_FFAP1_CONNECT_ST_taskdone_link_st_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int td_drain_th : 8;
        unsigned int pt_drain_th1 : 8;
        unsigned int pt_drain_th0 : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_FFAP1_DRAIN_TH_UNION;
#endif
#define SOC_FFAP1_DRAIN_TH_td_drain_th_START (0)
#define SOC_FFAP1_DRAIN_TH_td_drain_th_END (7)
#define SOC_FFAP1_DRAIN_TH_pt_drain_th1_START (8)
#define SOC_FFAP1_DRAIN_TH_pt_drain_th1_END (15)
#define SOC_FFAP1_DRAIN_TH_pt_drain_th0_START (16)
#define SOC_FFAP1_DRAIN_TH_pt_drain_th0_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_credit_num : 8;
        unsigned int dfx_connnect_fsm : 4;
        unsigned int dfx_busy : 1;
        unsigned int dfx_busy_all : 7;
        unsigned int reserved : 12;
    } reg;
} SOC_FFAP1_DFX_COMM_UNION;
#endif
#define SOC_FFAP1_DFX_COMM_dfx_credit_num_START (0)
#define SOC_FFAP1_DFX_COMM_dfx_credit_num_END (7)
#define SOC_FFAP1_DFX_COMM_dfx_connnect_fsm_START (8)
#define SOC_FFAP1_DFX_COMM_dfx_connnect_fsm_END (11)
#define SOC_FFAP1_DFX_COMM_dfx_busy_START (12)
#define SOC_FFAP1_DFX_COMM_dfx_busy_END (12)
#define SOC_FFAP1_DFX_COMM_dfx_busy_all_START (13)
#define SOC_FFAP1_DFX_COMM_dfx_busy_all_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_pushtask_cnt : 16;
        unsigned int dfx_pushtask_cnt_en : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_FFAP1_DFX_PT_CNT_UNION;
#endif
#define SOC_FFAP1_DFX_PT_CNT_dfx_pushtask_cnt_START (0)
#define SOC_FFAP1_DFX_PT_CNT_dfx_pushtask_cnt_END (15)
#define SOC_FFAP1_DFX_PT_CNT_dfx_pushtask_cnt_en_START (16)
#define SOC_FFAP1_DFX_PT_CNT_dfx_pushtask_cnt_en_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_taskdone_cnt : 16;
        unsigned int dfx_taskdone_cnt_en : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_FFAP1_DFX_TD_CNT_UNION;
#endif
#define SOC_FFAP1_DFX_TD_CNT_dfx_taskdone_cnt_START (0)
#define SOC_FFAP1_DFX_TD_CNT_dfx_taskdone_cnt_END (15)
#define SOC_FFAP1_DFX_TD_CNT_dfx_taskdone_cnt_en_START (16)
#define SOC_FFAP1_DFX_TD_CNT_dfx_taskdone_cnt_en_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_taskdone_record : 1;
        unsigned int dfx_pushtask_record : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_FFAP1_DFX_RECORD_CTRL_UNION;
#endif
#define SOC_FFAP1_DFX_RECORD_CTRL_dfx_taskdone_record_START (0)
#define SOC_FFAP1_DFX_RECORD_CTRL_dfx_taskdone_record_END (0)
#define SOC_FFAP1_DFX_RECORD_CTRL_dfx_pushtask_record_START (1)
#define SOC_FFAP1_DFX_RECORD_CTRL_dfx_pushtask_record_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_pushtask_data : 32;
    } reg;
} SOC_FFAP1_DFX_PUSHTASK_UNION;
#endif
#define SOC_FFAP1_DFX_PUSHTASK_dfx_pushtask_data_START (0)
#define SOC_FFAP1_DFX_PUSHTASK_dfx_pushtask_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_taskdone_data : 32;
    } reg;
} SOC_FFAP1_DFX_TASKDONE_UNION;
#endif
#define SOC_FFAP1_DFX_TASKDONE_dfx_taskdone_data_START (0)
#define SOC_FFAP1_DFX_TASKDONE_dfx_taskdone_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_credit_ostd : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_FFAP1_DFX_CREDIT_OST_UNION;
#endif
#define SOC_FFAP1_DFX_CREDIT_OST_dfx_credit_ostd_START (0)
#define SOC_FFAP1_DFX_CREDIT_OST_dfx_credit_ostd_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int taskdone_send_pld : 32;
    } reg;
} SOC_FFAP1_CKB_TASKDONE_PLD_UNION;
#endif
#define SOC_FFAP1_CKB_TASKDONE_PLD_taskdone_send_pld_START (0)
#define SOC_FFAP1_CKB_TASKDONE_PLD_taskdone_send_pld_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int taskdone_send_vld : 1;
        unsigned int taskdone_send_busy : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_FFAP1_CKB_TASKDONE_CTRL_UNION;
#endif
#define SOC_FFAP1_CKB_TASKDONE_CTRL_taskdone_send_vld_START (0)
#define SOC_FFAP1_CKB_TASKDONE_CTRL_taskdone_send_vld_END (0)
#define SOC_FFAP1_CKB_TASKDONE_CTRL_taskdone_send_busy_START (1)
#define SOC_FFAP1_CKB_TASKDONE_CTRL_taskdone_send_busy_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_int_mask : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_FFAP1_DFX_MASK_UNION;
#endif
#define SOC_FFAP1_DFX_MASK_dfx_int_mask_START (0)
#define SOC_FFAP1_DFX_MASK_dfx_int_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_int_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FFAP1_DFX_CLR_UNION;
#endif
#define SOC_FFAP1_DFX_CLR_dfx_int_clr_START (0)
#define SOC_FFAP1_DFX_CLR_dfx_int_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_int_org_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_FFAP1_DFX_ORG_STATUS_UNION;
#endif
#define SOC_FFAP1_DFX_ORG_STATUS_dfx_int_org_status_START (0)
#define SOC_FFAP1_DFX_ORG_STATUS_dfx_int_org_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_int_mask_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_FFAP1_DFX_MASK_STATUS_UNION;
#endif
#define SOC_FFAP1_DFX_MASK_STATUS_dfx_int_mask_status_START (0)
#define SOC_FFAP1_DFX_MASK_STATUS_dfx_int_mask_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_int_type : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_FFAP1_DFX_TYPE_UNION;
#endif
#define SOC_FFAP1_DFX_TYPE_dfx_int_type_START (0)
#define SOC_FFAP1_DFX_TYPE_dfx_int_type_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_int_info : 32;
    } reg;
} SOC_FFAP1_DFX_INFO_UNION;
#endif
#define SOC_FFAP1_DFX_INFO_dfx_int_info_START (0)
#define SOC_FFAP1_DFX_INFO_dfx_int_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpuif_ckg_bypass : 1;
        unsigned int cpuif_ckg_ext : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_FFAP1_CPUIF_CKG_CTRL_UNION;
#endif
#define SOC_FFAP1_CPUIF_CKG_CTRL_cpuif_ckg_bypass_START (0)
#define SOC_FFAP1_CPUIF_CKG_CTRL_cpuif_ckg_bypass_END (0)
#define SOC_FFAP1_CPUIF_CKG_CTRL_cpuif_ckg_ext_START (1)
#define SOC_FFAP1_CPUIF_CKG_CTRL_cpuif_ckg_ext_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pushtask_link_req : 1;
        unsigned int pushtask_link_ack : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_FFAP1_CPUIF_LINK_PT_UNION;
#endif
#define SOC_FFAP1_CPUIF_LINK_PT_pushtask_link_req_START (0)
#define SOC_FFAP1_CPUIF_LINK_PT_pushtask_link_req_END (0)
#define SOC_FFAP1_CPUIF_LINK_PT_pushtask_link_ack_START (1)
#define SOC_FFAP1_CPUIF_LINK_PT_pushtask_link_ack_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int taskdone_link_req : 1;
        unsigned int taskdone_link_ack : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_FFAP1_CPUIF_LINK_TD_UNION;
#endif
#define SOC_FFAP1_CPUIF_LINK_TD_taskdone_link_req_START (0)
#define SOC_FFAP1_CPUIF_LINK_TD_taskdone_link_req_END (0)
#define SOC_FFAP1_CPUIF_LINK_TD_taskdone_link_ack_START (1)
#define SOC_FFAP1_CPUIF_LINK_TD_taskdone_link_ack_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pushtask_rd_vld : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FFAP1_CPUIF_PUSHTASK_POP_UNION;
#endif
#define SOC_FFAP1_CPUIF_PUSHTASK_POP_pushtask_rd_vld_START (0)
#define SOC_FFAP1_CPUIF_PUSHTASK_POP_pushtask_rd_vld_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pushtask_rd_data : 32;
    } reg;
} SOC_FFAP1_CPUIF_PUSHTASK_UNION;
#endif
#define SOC_FFAP1_CPUIF_PUSHTASK_pushtask_rd_data_START (0)
#define SOC_FFAP1_CPUIF_PUSHTASK_pushtask_rd_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int taskdone_taskidx : 16;
        unsigned int taskdone_type : 1;
        unsigned int taskdone_error : 1;
        unsigned int taskdone_errprocess : 1;
        unsigned int taskdone_vld : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_FFAP1_CPUIF_TASKDONE_UNION;
#endif
#define SOC_FFAP1_CPUIF_TASKDONE_taskdone_taskidx_START (0)
#define SOC_FFAP1_CPUIF_TASKDONE_taskdone_taskidx_END (15)
#define SOC_FFAP1_CPUIF_TASKDONE_taskdone_type_START (16)
#define SOC_FFAP1_CPUIF_TASKDONE_taskdone_type_END (16)
#define SOC_FFAP1_CPUIF_TASKDONE_taskdone_error_START (17)
#define SOC_FFAP1_CPUIF_TASKDONE_taskdone_error_END (17)
#define SOC_FFAP1_CPUIF_TASKDONE_taskdone_errprocess_START (18)
#define SOC_FFAP1_CPUIF_TASKDONE_taskdone_errprocess_END (18)
#define SOC_FFAP1_CPUIF_TASKDONE_taskdone_vld_START (19)
#define SOC_FFAP1_CPUIF_TASKDONE_taskdone_vld_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnormal_ctrl_en : 1;
        unsigned int abnormal_ctrl_st : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_FFAP1_CPUIF_ABNORMAL_UNION;
#endif
#define SOC_FFAP1_CPUIF_ABNORMAL_abnormal_ctrl_en_START (0)
#define SOC_FFAP1_CPUIF_ABNORMAL_abnormal_ctrl_en_END (0)
#define SOC_FFAP1_CPUIF_ABNORMAL_abnormal_ctrl_st_START (1)
#define SOC_FFAP1_CPUIF_ABNORMAL_abnormal_ctrl_st_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int drain_uid : 12;
        unsigned int drain_uid_st : 1;
        unsigned int ckb_drain_req_intr_en : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_FFAP1_CPUIF_DRAIN_UID_UNION;
#endif
#define SOC_FFAP1_CPUIF_DRAIN_UID_drain_uid_START (0)
#define SOC_FFAP1_CPUIF_DRAIN_UID_drain_uid_END (11)
#define SOC_FFAP1_CPUIF_DRAIN_UID_drain_uid_st_START (12)
#define SOC_FFAP1_CPUIF_DRAIN_UID_drain_uid_st_END (12)
#define SOC_FFAP1_CPUIF_DRAIN_UID_ckb_drain_req_intr_en_START (13)
#define SOC_FFAP1_CPUIF_DRAIN_UID_ckb_drain_req_intr_en_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wkup_intr_en_set : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FFAP1_CPUIF_WKINTR_CTRL_UNION;
#endif
#define SOC_FFAP1_CPUIF_WKINTR_CTRL_wkup_intr_en_set_START (0)
#define SOC_FFAP1_CPUIF_WKINTR_CTRL_wkup_intr_en_set_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wkup_intr_st : 1;
        unsigned int wkup_intr_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_FFAP1_CPUIF_WKINTR_ST_UNION;
#endif
#define SOC_FFAP1_CPUIF_WKINTR_ST_wkup_intr_st_START (0)
#define SOC_FFAP1_CPUIF_WKINTR_ST_wkup_intr_st_END (0)
#define SOC_FFAP1_CPUIF_WKINTR_ST_wkup_intr_en_START (1)
#define SOC_FFAP1_CPUIF_WKINTR_ST_wkup_intr_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wkup_intr_st_clr : 1;
        unsigned int wkup_intr_en_clr : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_FFAP1_CPUIF_WKINTR_CLR_UNION;
#endif
#define SOC_FFAP1_CPUIF_WKINTR_CLR_wkup_intr_st_clr_START (0)
#define SOC_FFAP1_CPUIF_WKINTR_CLR_wkup_intr_st_clr_END (0)
#define SOC_FFAP1_CPUIF_WKINTR_CLR_wkup_intr_en_clr_START (1)
#define SOC_FFAP1_CPUIF_WKINTR_CLR_wkup_intr_en_clr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int misc_intr_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FFAP1_CPUIF_INTR_EN_UNION;
#endif
#define SOC_FFAP1_CPUIF_INTR_EN_misc_intr_en_START (0)
#define SOC_FFAP1_CPUIF_INTR_EN_misc_intr_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int misc_intr_st : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FFAP1_CPUIF_INTR_ST_UNION;
#endif
#define SOC_FFAP1_CPUIF_INTR_ST_misc_intr_st_START (0)
#define SOC_FFAP1_CPUIF_INTR_ST_misc_intr_st_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int misc_intr_st_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FFAP1_CPUIF_INTR_CLR_UNION;
#endif
#define SOC_FFAP1_CPUIF_INTR_CLR_misc_intr_st_clr_START (0)
#define SOC_FFAP1_CPUIF_INTR_CLR_misc_intr_st_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_rd_addr : 8;
        unsigned int dbg_rd_en : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_FFAP1_CPUIF_DBG_RD_UNION;
#endif
#define SOC_FFAP1_CPUIF_DBG_RD_dbg_rd_addr_START (0)
#define SOC_FFAP1_CPUIF_DBG_RD_dbg_rd_addr_END (7)
#define SOC_FFAP1_CPUIF_DBG_RD_dbg_rd_en_START (8)
#define SOC_FFAP1_CPUIF_DBG_RD_dbg_rd_en_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_rd_info0 : 32;
    } reg;
} SOC_FFAP1_CPUIF_DBG_INFO0_UNION;
#endif
#define SOC_FFAP1_CPUIF_DBG_INFO0_dbg_rd_info0_START (0)
#define SOC_FFAP1_CPUIF_DBG_INFO0_dbg_rd_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_rd_info1 : 32;
    } reg;
} SOC_FFAP1_CPUIF_DBG_INFO1_UNION;
#endif
#define SOC_FFAP1_CPUIF_DBG_INFO1_dbg_rd_info1_START (0)
#define SOC_FFAP1_CPUIF_DBG_INFO1_dbg_rd_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_rd_info2 : 32;
    } reg;
} SOC_FFAP1_CPUIF_DBG_INFO2_UNION;
#endif
#define SOC_FFAP1_CPUIF_DBG_INFO2_dbg_rd_info2_START (0)
#define SOC_FFAP1_CPUIF_DBG_INFO2_dbg_rd_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_buf_ostd_vld : 16;
        unsigned int dfx_buf_task_vld : 16;
    } reg;
} SOC_FFAP1_CPUIF_DFX_TASK_UNION;
#endif
#define SOC_FFAP1_CPUIF_DFX_TASK_dfx_buf_ostd_vld_START (0)
#define SOC_FFAP1_CPUIF_DFX_TASK_dfx_buf_ostd_vld_END (15)
#define SOC_FFAP1_CPUIF_DFX_TASK_dfx_buf_task_vld_START (16)
#define SOC_FFAP1_CPUIF_DFX_TASK_dfx_buf_task_vld_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpuif_dfx_int_mask : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_FFAP1_CPUIF_DFX_MASK_UNION;
#endif
#define SOC_FFAP1_CPUIF_DFX_MASK_cpuif_dfx_int_mask_START (0)
#define SOC_FFAP1_CPUIF_DFX_MASK_cpuif_dfx_int_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpuif_dfx_int_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FFAP1_CPUIF_DFX_CLR_UNION;
#endif
#define SOC_FFAP1_CPUIF_DFX_CLR_cpuif_dfx_int_clr_START (0)
#define SOC_FFAP1_CPUIF_DFX_CLR_cpuif_dfx_int_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpuif_dfx_int_org_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_FFAP1_CPUIF_DFX_ORG_STATUS_UNION;
#endif
#define SOC_FFAP1_CPUIF_DFX_ORG_STATUS_cpuif_dfx_int_org_status_START (0)
#define SOC_FFAP1_CPUIF_DFX_ORG_STATUS_cpuif_dfx_int_org_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpuif_dfx_int_mask_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_FFAP1_CPUIF_DFX_MASK_STATUS_UNION;
#endif
#define SOC_FFAP1_CPUIF_DFX_MASK_STATUS_cpuif_dfx_int_mask_status_START (0)
#define SOC_FFAP1_CPUIF_DFX_MASK_STATUS_cpuif_dfx_int_mask_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpuif_dfx_int_type : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_FFAP1_CPUIF_DFX_TYPE_UNION;
#endif
#define SOC_FFAP1_CPUIF_DFX_TYPE_cpuif_dfx_int_type_START (0)
#define SOC_FFAP1_CPUIF_DFX_TYPE_cpuif_dfx_int_type_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpuif_dfx_int_info : 32;
    } reg;
} SOC_FFAP1_CPUIF_DFX_INFO_UNION;
#endif
#define SOC_FFAP1_CPUIF_DFX_INFO_cpuif_dfx_int_info_START (0)
#define SOC_FFAP1_CPUIF_DFX_INFO_cpuif_dfx_int_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buf_set_idx : 8;
        unsigned int buf_set_en : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_FFAP1_CPUIF_RESUME_EN_UNION;
#endif
#define SOC_FFAP1_CPUIF_RESUME_EN_buf_set_idx_START (0)
#define SOC_FFAP1_CPUIF_RESUME_EN_buf_set_idx_END (7)
#define SOC_FFAP1_CPUIF_RESUME_EN_buf_set_en_START (8)
#define SOC_FFAP1_CPUIF_RESUME_EN_buf_set_en_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buf_set_info0 : 32;
    } reg;
} SOC_FFAP1_CPUIF_RESUME_INFO0_UNION;
#endif
#define SOC_FFAP1_CPUIF_RESUME_INFO0_buf_set_info0_START (0)
#define SOC_FFAP1_CPUIF_RESUME_INFO0_buf_set_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buf_set_info1 : 32;
    } reg;
} SOC_FFAP1_CPUIF_RESUME_INFO1_UNION;
#endif
#define SOC_FFAP1_CPUIF_RESUME_INFO1_buf_set_info1_START (0)
#define SOC_FFAP1_CPUIF_RESUME_INFO1_buf_set_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buf_set_info2 : 32;
    } reg;
} SOC_FFAP1_CPUIF_RESUME_INFO2_UNION;
#endif
#define SOC_FFAP1_CPUIF_RESUME_INFO2_buf_set_info2_START (0)
#define SOC_FFAP1_CPUIF_RESUME_INFO2_buf_set_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_cpuif_busy : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_FFAP1_CPUIF_DFX_BUSY_UNION;
#endif
#define SOC_FFAP1_CPUIF_DFX_BUSY_dfx_cpuif_busy_START (0)
#define SOC_FFAP1_CPUIF_DFX_BUSY_dfx_cpuif_busy_END (7)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
