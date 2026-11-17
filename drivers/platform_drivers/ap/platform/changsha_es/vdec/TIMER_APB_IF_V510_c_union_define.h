#ifndef __TIMER_APB_IF_V510_C_UNION_DEFINE_H__
#define __TIMER_APB_IF_V510_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int cnt_timer_en_bypass : 1 ;
        unsigned int cnt_timer_en_sel : 1 ;
        unsigned int dbg_timer_en_bypass : 1 ;
        unsigned int reserved_0 : 13 ;
        unsigned int bitmasken : 16 ;
    } bits;
    unsigned int u32;
} U_TIMER_CLK_CTRL;
typedef union {
    struct {
        unsigned int timer_en : 1 ;
        unsigned int timer_size : 1 ;
        unsigned int timer_stop : 1 ;
        unsigned int timer_reload_sel : 1 ;
        unsigned int timer_int_mask : 1 ;
        unsigned int reserved_0 : 11 ;
        unsigned int bitmasken : 16 ;
    } bits;
    unsigned int u32;
} U_TIMER_CTRL;
typedef union {
    struct {
        unsigned int intr_timer : 1 ;
        unsigned int intr_timer_raw : 1 ;
        unsigned int reserved_0 : 30 ;
    } bits;
    unsigned int u32;
} U_INTR_TIMER;
typedef union {
    struct {
        unsigned int intr_timer_clr : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_INTR_TIMER_CLR;
typedef struct {
    volatile U_TIMER_CLK_CTRL TIMER_CLK_CTRL ;
    volatile unsigned int TIMER_INIT ;
    volatile U_TIMER_CTRL TIMER_CTRL ;
    volatile U_INTR_TIMER INTR_TIMER ;
    volatile U_INTR_TIMER_CLR INTR_TIMER_CLR ;
    volatile unsigned int COUNT_VALUE ;
    volatile unsigned int TIMER_PERIOD_INIT ;
    volatile unsigned int reserved_0[34] ;
    volatile unsigned int TIMER_VERSION ;
} S_TIMER_APB_IF_V510_REGS_TYPE;
#endif
