#ifndef __HISI_WD_APB_IF_C_UNION_DEFINE_H__
#define __HISI_WD_APB_IF_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int lock : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_LOCK;
typedef union {
    struct {
        unsigned int wd_en : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_WD_EN;
typedef union {
    struct {
        unsigned int wd_kick_pulse : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_WD_KICK;
typedef union {
    struct {
        unsigned int intr_wd_clr_pulse : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_INTR_WD_CLR;
typedef union {
    struct {
        unsigned int intr_wd_mask : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_INTR_WD_MASK;
typedef union {
    struct {
        unsigned int wd_rst_mask : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_WD_RST_MASK;
typedef union {
    struct {
        unsigned int intr_wd_raw : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_INTR_WD_RAW;
typedef union {
    struct {
        unsigned int intr_wd : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_INTR_WD;
typedef union {
    struct {
        unsigned int st_clk_wd_gate : 1 ;
        unsigned int wd_dbg_bypass : 1 ;
        unsigned int reserved_0 : 30 ;
    } bits;
    unsigned int u32;
} U_CLK_GATE;
typedef struct {
    volatile unsigned int LOCKEN ;
    volatile unsigned int LOCKDIS ;
    volatile U_LOCK LOCK ;
    volatile unsigned int CNT_INTR_TIME ;
    volatile unsigned int CNT_RST_TIME ;
    volatile U_WD_EN WD_EN ;
    volatile U_WD_KICK WD_KICK ;
    volatile U_INTR_WD_CLR INTR_WD_CLR ;
    volatile U_INTR_WD_MASK INTR_WD_MASK ;
    volatile U_WD_RST_MASK WD_RST_MASK ;
    volatile U_INTR_WD_RAW INTR_WD_RAW ;
    volatile U_INTR_WD INTR_WD ;
    volatile unsigned int WD_CNT ;
    volatile U_CLK_GATE CLK_GATE ;
    volatile unsigned int reserved_0[1009] ;
    volatile unsigned int WD_ID ;
} S_HISI_WD_APB_IF_REGS_TYPE;
#endif
