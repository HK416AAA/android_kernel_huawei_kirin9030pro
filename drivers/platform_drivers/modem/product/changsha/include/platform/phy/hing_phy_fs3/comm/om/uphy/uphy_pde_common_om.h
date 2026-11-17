

#ifndef __UPHY_COMMON_H__
#define __UPHY_COMMON_H__


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

typedef union {
    struct {
        unsigned int sst_sys_sym_id         : 4;     /*  3:0  */
        unsigned int sst_sys_frm_slot_id    : 7;     /* 10:4 */
        unsigned int sst_sys_ts_cnt         : 1;     /* 11:11 */
        unsigned int rsv                    : 20;    /* 31:12 */
    } bits;
    unsigned int u32;
} U_BBP_SST_NL;


typedef union {
    struct {
        unsigned int basecnt_sym_cnt         : 4;    /*  3:0  */
        unsigned int basecnt_slot_cnt        : 4;    /*  7:4  */
        unsigned int d_slot_cnt              : 4;    /* 11:8  */
        unsigned int d_sfn_cnt               : 12;   /* 23:12 */
        unsigned int f_slot_cnt              : 4;    /* 27:24 */
        unsigned int f_sfn_cnt               : 4;    /* 31:28 */
    } bits;
    unsigned int u32;
} U_BBP_SST_UMTS;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
