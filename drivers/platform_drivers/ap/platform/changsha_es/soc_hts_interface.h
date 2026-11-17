#ifndef __SOC_HTS_INTERFACE_H__
#define __SOC_HTS_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HTS_SRC_ID_ADDR(base) (base)
#define SOC_HTS_UID_ADDR(base) ((base) + 0x004UL)
#define SOC_HTS_STORE_BYPASS_MODE_ADDR(base) ((base) + 0x010UL)
#define SOC_HTS_INITIAL_REQ_ADDR(base) ((base) + 0x020UL)
#define SOC_HTS_INITIAL_ACK_ADDR(base) ((base) + 0x024UL)
#define SOC_HTS_EVENT_IN_CKG_BYPASS_ADDR(base) ((base) + 0x028UL)
#define SOC_HTS_UID_TABLE_CKG_BYPASS_ADDR(base) ((base) + 0x040UL)
#define SOC_HTS_UID_TABLE_MEM_CTRL_ADDR(base) ((base) + 0x070UL)
#define SOC_HTS_EVENT_IN_IBUF_MEM_CTRL_ADDR(base) ((base) + 0x074UL)
#define SOC_HTS_EVENT_PROC_MAPPING_MEM_CTRL_ADDR(base) ((base) + 0x078UL)
#define SOC_HTS_EVENT_PROC_RULE_MEM_CTRL_ADDR(base) ((base) + 0x07cUL)
#define SOC_HTS_EVENT_PROC_STATUS_MEM_CTRL_ADDR(base) ((base) + 0x080UL)
#define SOC_HTS_EVENT_OUT_OBUF_MEM_CTRL_ADDR(base) ((base) + 0x084UL)
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_MEM_CTRL_ADDR(base) ((base) + 0x088UL)
#define SOC_HTS_EVENT_LOCK_ADDR(base,m) ((base) + 0x100 + 0x004 * (m))
#define SOC_HTS_IBUF_EVENT_CNT_CLR_ADDR(base,n) ((base) + 0x200 + 0x004 * (n))
#define SOC_HTS_INT_ADDR(base) ((base) + 0x300UL)
#define SOC_HTS_INT_MASK_ADDR(base) ((base) + 0x304UL)
#define SOC_HTS_INT_MASK_STAT_ADDR(base) ((base) + 0x308UL)
#define SOC_HTS_DBG_EN_ADDR(base) ((base) + 0x400UL)
#define SOC_HTS_EVENT_IN_READ_BACK_0_ADDR(base) ((base) + 0x410UL)
#define SOC_HTS_EVENT_IN_READ_BACK_1_ADDR(base) ((base) + 0x414UL)
#define SOC_HTS_EVENT_IN_READ_BACK_2_ADDR(base) ((base) + 0x418UL)
#define SOC_HTS_EVENT_IN_READ_BACK_3_ADDR(base) ((base) + 0x41cUL)
#define SOC_HTS_EVENT_IN_READ_BACK_4_ADDR(base) ((base) + 0x420UL)
#define SOC_HTS_EVENT_IN_READ_BACK_5_ADDR(base) ((base) + 0x424UL)
#define SOC_HTS_EVENT_PROC_MAPPING_READ_BACK_0_ADDR(base) ((base) + 0x430UL)
#define SOC_HTS_EVENT_PROC_MAPPING_READ_BACK_1_ADDR(base) ((base) + 0x434UL)
#define SOC_HTS_EVENT_PROC_FETCH_READ_BACK_0_ADDR(base) ((base) + 0x440UL)
#define SOC_HTS_EVENT_PROC_FETCH_READ_BACK_1_ADDR(base) ((base) + 0x444UL)
#define SOC_HTS_EVENT_PROC_FETCH_READ_BACK_2_ADDR(base) ((base) + 0x448UL)
#define SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_0_ADDR(base) ((base) + 0x450UL)
#define SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_1_ADDR(base) ((base) + 0x454UL)
#define SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_2_ADDR(base) ((base) + 0x458UL)
#define SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_3_ADDR(base) ((base) + 0x45cUL)
#define SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_4_ADDR(base) ((base) + 0x460UL)
#define SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_5_ADDR(base) ((base) + 0x464UL)
#define SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_0_ADDR(base) ((base) + 0x470UL)
#define SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_1_ADDR(base) ((base) + 0x474UL)
#define SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_2_ADDR(base) ((base) + 0x478UL)
#define SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_3_ADDR(base) ((base) + 0x47cUL)
#define SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_4_ADDR(base) ((base) + 0x480UL)
#define SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_5_ADDR(base) ((base) + 0x484UL)
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_0_ADDR(base) ((base) + 0x490UL)
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_1_ADDR(base) ((base) + 0x494UL)
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_2_ADDR(base) ((base) + 0x49cUL)
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_3_ADDR(base) ((base) + 0x4a0UL)
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_4_ADDR(base) ((base) + 0x4a4UL)
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_5_ADDR(base) ((base) + 0x4a8UL)
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_6_ADDR(base) ((base) + 0x4acUL)
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_7_ADDR(base) ((base) + 0x4b0UL)
#define SOC_HTS_EVENT_OUT_UID_CONCAT_READ_BACK0_ADDR(base) ((base) + (0x4b4UL))
#define SOC_HTS_EVENT_OUT_UID_CONCAT_READ_BACK1_ADDR(base) ((base) + (0x4b8UL))
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_1_ADDR(base) ((base) + (0x4bcUL))
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_2_ADDR(base) ((base) + (0x4c0UL))
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_3_ADDR(base) ((base) + (0x4c4UL))
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_4_ADDR(base) ((base) + (0x4c8UL))
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_5_ADDR(base) ((base) + (0x4ccUL))
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_6_ADDR(base) ((base) + (0x4d0UL))
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_BITMAP_READ_BACK_0_ADDR(base) ((base) + (0x4d4UL))
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_BITMAP_READ_BACK_1_ADDR(base) ((base) + (0x4d8UL))
#define SOC_HTS_EVENT_OUT_ARB_READ_BACK0_ADDR(base) ((base) + (0x4dcUL))
#define SOC_HTS_EVENT_OUT_ARB_READ_BACK1_ADDR(base) ((base) + (0x4e0UL))
#define SOC_HTS_EVENT_IN_ERROR_READ_BACK_0_ADDR(base) ((base) + 0x500UL)
#define SOC_HTS_EVENT_IN_ERROR_READ_BACK_1_ADDR(base) ((base) + 0x504UL)
#define SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_0_ADDR(base) ((base) + 0x510UL)
#define SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_1_ADDR(base) ((base) + 0x514UL)
#define SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_2_ADDR(base) ((base) + 0x518UL)
#define SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_3_ADDR(base) ((base) + 0x51cUL)
#define SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_4_ADDR(base) ((base) + 0x520UL)
#define SOC_HTS_EVENT_OUT_OBUF_ERROR_READ_BACK_0_ADDR(base) ((base) + 0x524UL)
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_ERROR_READ_BACK_0_ADDR(base) ((base) + 0x528UL)
#define SOC_HTS_EVENT_STORE_ADDR(base,e) ((base) + 0x600 + 0x004 * (e))
#define SOC_HTS_OBUF_EVENT_CNT_CLR_ADDR(base,f) ((base) + 0x700 + 0x004 * (f))
#define SOC_HTS_EVENT_IN_SRC_ID_EVENT_CNT_EN0_ADDR(base,g) ((base) + 0x800 + 0x004 * (g))
#define SOC_HTS_EVENT_IN_SRC_ID_EVENT_CNT_READ_BACK0_ADDR(base,h) ((base) + 0x900 + 0x004 * (h))
#define SOC_HTS_EVENT_IN_SRC_ID_EVENT_CNT_CLR_ADDR(base,a) ((base) + 0x1000 + 0x004 * (a))
#define SOC_HTS_EVENT_OUT_DST_ID_EVENT_CNT_EN0_ADDR(base,b) ((base) + 0x1100 + 0x004 * (b))
#define SOC_HTS_EVENT_OUT_DST_ID_EVENT_CNT_READ_BACK0_ADDR(base,c) ((base) + 0x1200 + 0x004 * (c))
#define SOC_HTS_EVENT_OUT_DST_ID_EVENT_CNT_CLR_ADDR(base,d) ((base) + 0x1300 + 0x004 * (d))
#else
#define SOC_HTS_SRC_ID_ADDR(base) (base)
#define SOC_HTS_UID_ADDR(base) ((base) + 0x004)
#define SOC_HTS_STORE_BYPASS_MODE_ADDR(base) ((base) + 0x010)
#define SOC_HTS_INITIAL_REQ_ADDR(base) ((base) + 0x020)
#define SOC_HTS_INITIAL_ACK_ADDR(base) ((base) + 0x024)
#define SOC_HTS_EVENT_IN_CKG_BYPASS_ADDR(base) ((base) + 0x028)
#define SOC_HTS_UID_TABLE_CKG_BYPASS_ADDR(base) ((base) + 0x040)
#define SOC_HTS_UID_TABLE_MEM_CTRL_ADDR(base) ((base) + 0x070)
#define SOC_HTS_EVENT_IN_IBUF_MEM_CTRL_ADDR(base) ((base) + 0x074)
#define SOC_HTS_EVENT_PROC_MAPPING_MEM_CTRL_ADDR(base) ((base) + 0x078)
#define SOC_HTS_EVENT_PROC_RULE_MEM_CTRL_ADDR(base) ((base) + 0x07c)
#define SOC_HTS_EVENT_PROC_STATUS_MEM_CTRL_ADDR(base) ((base) + 0x080)
#define SOC_HTS_EVENT_OUT_OBUF_MEM_CTRL_ADDR(base) ((base) + 0x084)
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_MEM_CTRL_ADDR(base) ((base) + 0x088)
#define SOC_HTS_EVENT_LOCK_ADDR(base,m) ((base) + 0x100 + 0x004 * (m))
#define SOC_HTS_IBUF_EVENT_CNT_CLR_ADDR(base,n) ((base) + 0x200 + 0x004 * (n))
#define SOC_HTS_INT_ADDR(base) ((base) + 0x300)
#define SOC_HTS_INT_MASK_ADDR(base) ((base) + 0x304)
#define SOC_HTS_INT_MASK_STAT_ADDR(base) ((base) + 0x308)
#define SOC_HTS_DBG_EN_ADDR(base) ((base) + 0x400)
#define SOC_HTS_EVENT_IN_READ_BACK_0_ADDR(base) ((base) + 0x410)
#define SOC_HTS_EVENT_IN_READ_BACK_1_ADDR(base) ((base) + 0x414)
#define SOC_HTS_EVENT_IN_READ_BACK_2_ADDR(base) ((base) + 0x418)
#define SOC_HTS_EVENT_IN_READ_BACK_3_ADDR(base) ((base) + 0x41c)
#define SOC_HTS_EVENT_IN_READ_BACK_4_ADDR(base) ((base) + 0x420)
#define SOC_HTS_EVENT_IN_READ_BACK_5_ADDR(base) ((base) + 0x424)
#define SOC_HTS_EVENT_PROC_MAPPING_READ_BACK_0_ADDR(base) ((base) + 0x430)
#define SOC_HTS_EVENT_PROC_MAPPING_READ_BACK_1_ADDR(base) ((base) + 0x434)
#define SOC_HTS_EVENT_PROC_FETCH_READ_BACK_0_ADDR(base) ((base) + 0x440)
#define SOC_HTS_EVENT_PROC_FETCH_READ_BACK_1_ADDR(base) ((base) + 0x444)
#define SOC_HTS_EVENT_PROC_FETCH_READ_BACK_2_ADDR(base) ((base) + 0x448)
#define SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_0_ADDR(base) ((base) + 0x450)
#define SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_1_ADDR(base) ((base) + 0x454)
#define SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_2_ADDR(base) ((base) + 0x458)
#define SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_3_ADDR(base) ((base) + 0x45c)
#define SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_4_ADDR(base) ((base) + 0x460)
#define SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_5_ADDR(base) ((base) + 0x464)
#define SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_0_ADDR(base) ((base) + 0x470)
#define SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_1_ADDR(base) ((base) + 0x474)
#define SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_2_ADDR(base) ((base) + 0x478)
#define SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_3_ADDR(base) ((base) + 0x47c)
#define SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_4_ADDR(base) ((base) + 0x480)
#define SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_5_ADDR(base) ((base) + 0x484)
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_0_ADDR(base) ((base) + 0x490)
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_1_ADDR(base) ((base) + 0x494)
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_2_ADDR(base) ((base) + 0x49c)
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_3_ADDR(base) ((base) + 0x4a0)
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_4_ADDR(base) ((base) + 0x4a4)
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_5_ADDR(base) ((base) + 0x4a8)
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_6_ADDR(base) ((base) + 0x4ac)
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_7_ADDR(base) ((base) + 0x4b0)
#define SOC_HTS_EVENT_OUT_UID_CONCAT_READ_BACK0_ADDR(base) ((base) + (0x4b4))
#define SOC_HTS_EVENT_OUT_UID_CONCAT_READ_BACK1_ADDR(base) ((base) + (0x4b8))
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_1_ADDR(base) ((base) + (0x4bc))
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_2_ADDR(base) ((base) + (0x4c0))
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_3_ADDR(base) ((base) + (0x4c4))
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_4_ADDR(base) ((base) + (0x4c8))
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_5_ADDR(base) ((base) + (0x4cc))
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_6_ADDR(base) ((base) + (0x4d0))
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_BITMAP_READ_BACK_0_ADDR(base) ((base) + (0x4d4))
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_BITMAP_READ_BACK_1_ADDR(base) ((base) + (0x4d8))
#define SOC_HTS_EVENT_OUT_ARB_READ_BACK0_ADDR(base) ((base) + (0x4dc))
#define SOC_HTS_EVENT_OUT_ARB_READ_BACK1_ADDR(base) ((base) + (0x4e0))
#define SOC_HTS_EVENT_IN_ERROR_READ_BACK_0_ADDR(base) ((base) + 0x500)
#define SOC_HTS_EVENT_IN_ERROR_READ_BACK_1_ADDR(base) ((base) + 0x504)
#define SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_0_ADDR(base) ((base) + 0x510)
#define SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_1_ADDR(base) ((base) + 0x514)
#define SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_2_ADDR(base) ((base) + 0x518)
#define SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_3_ADDR(base) ((base) + 0x51c)
#define SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_4_ADDR(base) ((base) + 0x520)
#define SOC_HTS_EVENT_OUT_ERROR_READ_BACK_0_ADDR(base) ((base) + 0x524)
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_ERROR_READ_BACK_0_ADDR(base) ((base) + (0x528))
#define SOC_HTS_EVENT_STORE_ADDR(base,e) ((base) + 0x600 + 0x004 * (e))
#define SOC_HTS_OBUF_EVENT_CNT_CLR_ADDR(base,f) ((base) + 0x700 + 0x004 * (f))
#define SOC_HTS_EVENT_IN_SRC_ID_EVENT_CNT_EN0_ADDR(base,g) ((base) + 0x800 + 0x004 * (g))
#define SOC_HTS_EVENT_IN_SRC_ID_EVENT_CNT_READ_BACK0_ADDR(base,h) ((base) + 0x900 + 0x004 * (h))
#define SOC_HTS_EVENT_IN_SRC_ID_EVENT_CNT_CLR_ADDR(base,a) ((base) + 0x1000 + 0x004 * (a))
#define SOC_HTS_EVENT_OUT_DST_ID_EVENT_CNT_EN0_ADDR(base,b) ((base) + 0x1100 + 0x004 * (b))
#define SOC_HTS_EVENT_OUT_DST_ID_EVENT_CNT_READ_BACK0_ADDR(base,c) ((base) + 0x1200 + 0x004 * (c))
#define SOC_HTS_EVENT_OUT_DST_ID_EVENT_CNT_CLR_ADDR(base,d) ((base) + 0x1300 + 0x004 * (d))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HTS_EVENT_IN_CHECK_ADDR(base,p) ((base) + 0x0004 * (p))
#else
#define SOC_HTS_EVENT_IN_CHECK_ADDR(base,p) ((base) + 0x0004 * (p))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HTS_EVENT_PROC_MAPPING_IDX_ADDR(base,i) ((base) + 0x0004 * (i))
#else
#define SOC_HTS_EVENT_PROC_MAPPING_IDX_ADDR(base,i) ((base) + 0x0004 * (i))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HTS_EVENT_PROC_RULE_ADDR(base,j) ((base) + 0x0004 * (j))
#else
#define SOC_HTS_EVENT_PROC_RULE_ADDR(base,j) ((base) + 0x0004 * (j))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HTS_EVENT_PROC_STATUS_ADDR(base,k) ((base) + 0x0004 * (k))
#else
#define SOC_HTS_EVENT_PROC_STATUS_ADDR(base,k) ((base) + 0x0004 * (k))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HTS_WRAP_OST_CNT_0_ADDR(base) (base)
#define SOC_HTS_IDLE_EN_ADDR(base) ((base) + 0x010UL)
#define SOC_HTS_IDLE_READ_BACK_ADDR(base) ((base) + 0x014UL)
#define SOC_HTS_WRAP_IBUF_CLR_BUS_NOPRESS_CNT_REQ_ADDR(base) ((base) + 0x100UL)
#define SOC_HTS_WRAP_IBUF_CLR_BUS_NOPRESS_CNT_ACK_ADDR(base) ((base) + 0x104UL)
#define SOC_HTS_WRAP_IBUF_CLR_BUS_NOPRESS_CNT_VALUE_ADDR(base) ((base) + 0x108UL)
#define SOC_HTS_WRAP_IBUF_CLR_BUS_NOPRESS_CNT_ADDR(base) ((base) + 0x10cUL)
#define SOC_HTS_WRAP_OBUF_CLR_BUS_NOPRESS_CNT_REQ_ADDR(base) ((base) + 0x200UL)
#define SOC_HTS_WRAP_OBUF_CLR_BUS_NOPRESS_CNT_ACK_ADDR(base) ((base) + 0x204UL)
#define SOC_HTS_WRAP_OBUF_CLR_BUS_NOPRESS_CNT_VALUE_ADDR(base) ((base) + 0x208UL)
#define SOC_HTS_WRAP_OBUF_CLR_BUS_NOPRESS_CNT_ADDR(base) ((base) + 0x20cUL)
#else
#define SOC_HTS_WRAP_OST_CNT_0_ADDR(base) (base)
#define SOC_HTS_IDLE_EN_ADDR(base) ((base) + 0x010)
#define SOC_HTS_IDLE_READ_BACK_ADDR(base) ((base) + 0x014)
#define SOC_HTS_WRAP_IBUF_CLR_BUS_NOPRESS_CNT_REQ_ADDR(base) ((base) + 0x100)
#define SOC_HTS_WRAP_IBUF_CLR_BUS_NOPRESS_CNT_ACK_ADDR(base) ((base) + 0x104)
#define SOC_HTS_WRAP_IBUF_CLR_BUS_NOPRESS_CNT_VALUE_ADDR(base) ((base) + 0x108)
#define SOC_HTS_WRAP_IBUF_CLR_BUS_NOPRESS_CNT_ADDR(base) ((base) + 0x10c)
#define SOC_HTS_WRAP_OBUF_CLR_BUS_NOPRESS_CNT_REQ_ADDR(base) ((base) + 0x200)
#define SOC_HTS_WRAP_OBUF_CLR_BUS_NOPRESS_CNT_ACK_ADDR(base) ((base) + 0x204)
#define SOC_HTS_WRAP_OBUF_CLR_BUS_NOPRESS_CNT_VALUE_ADDR(base) ((base) + 0x208)
#define SOC_HTS_WRAP_OBUF_CLR_BUS_NOPRESS_CNT_ADDR(base) ((base) + 0x20c)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hts_src_id : 6;
        unsigned int reserved_0 : 10;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HTS_SRC_ID_UNION;
#endif
#define SOC_HTS_SRC_ID_hts_src_id_START (0)
#define SOC_HTS_SRC_ID_hts_src_id_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hts_uid : 12;
        unsigned int reserved_0: 4;
        unsigned int reserved_1: 16;
    } reg;
} SOC_HTS_UID_UNION;
#endif
#define SOC_HTS_UID_hts_uid_START (0)
#define SOC_HTS_UID_hts_uid_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hts_store_bypass_mode : 1;
        unsigned int reserved_0 : 15;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HTS_STORE_BYPASS_MODE_UNION;
#endif
#define SOC_HTS_STORE_BYPASS_MODE_hts_store_bypass_mode_START (0)
#define SOC_HTS_STORE_BYPASS_MODE_hts_store_bypass_mode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hts_initial_req : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HTS_INITIAL_REQ_UNION;
#endif
#define SOC_HTS_INITIAL_REQ_hts_initial_req_START (0)
#define SOC_HTS_INITIAL_REQ_hts_initial_req_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hts_initial_ack : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HTS_INITIAL_ACK_UNION;
#endif
#define SOC_HTS_INITIAL_ACK_hts_initial_ack_START (0)
#define SOC_HTS_INITIAL_ACK_hts_initial_ack_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hts_event_in_ckg_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HTS_EVENT_IN_CKG_BYPASS_UNION;
#endif
#define SOC_HTS_EVENT_IN_CKG_BYPASS_hts_event_in_ckg_bypass_START (0)
#define SOC_HTS_EVENT_IN_CKG_BYPASS_hts_event_in_ckg_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hts_uid_table_ckg_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HTS_UID_TABLE_CKG_BYPASS_UNION;
#endif
#define SOC_HTS_UID_TABLE_CKG_BYPASS_hts_uid_table_ckg_bypass_START (0)
#define SOC_HTS_UID_TABLE_CKG_BYPASS_hts_uid_table_ckg_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_uid_table : 32;
    } reg;
} SOC_HTS_UID_TABLE_MEM_CTRL_UNION;
#endif
#define SOC_HTS_UID_TABLE_MEM_CTRL_mem_ctrl_uid_table_START (0)
#define SOC_HTS_UID_TABLE_MEM_CTRL_mem_ctrl_uid_table_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_event_in_ibuf : 32;
    } reg;
} SOC_HTS_EVENT_IN_IBUF_MEM_CTRL_UNION;
#endif
#define SOC_HTS_EVENT_IN_IBUF_MEM_CTRL_mem_ctrl_event_in_ibuf_START (0)
#define SOC_HTS_EVENT_IN_IBUF_MEM_CTRL_mem_ctrl_event_in_ibuf_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_mapping : 32;
    } reg;
} SOC_HTS_EVENT_PROC_MAPPING_MEM_CTRL_UNION;
#endif
#define SOC_HTS_EVENT_PROC_MAPPING_MEM_CTRL_mem_ctrl_mapping_START (0)
#define SOC_HTS_EVENT_PROC_MAPPING_MEM_CTRL_mem_ctrl_mapping_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_rule : 32;
    } reg;
} SOC_HTS_EVENT_PROC_RULE_MEM_CTRL_UNION;
#endif
#define SOC_HTS_EVENT_PROC_RULE_MEM_CTRL_mem_ctrl_rule_START (0)
#define SOC_HTS_EVENT_PROC_RULE_MEM_CTRL_mem_ctrl_rule_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_status : 32;
    } reg;
} SOC_HTS_EVENT_PROC_STATUS_MEM_CTRL_UNION;
#endif
#define SOC_HTS_EVENT_PROC_STATUS_MEM_CTRL_mem_ctrl_status_START (0)
#define SOC_HTS_EVENT_PROC_STATUS_MEM_CTRL_mem_ctrl_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_event_out_obuf : 32;
    } reg;
} SOC_HTS_EVENT_OUT_OBUF_MEM_CTRL_UNION;
#endif
#define SOC_HTS_EVENT_OUT_OBUF_MEM_CTRL_mem_ctrl_event_out_obuf_START (0)
#define SOC_HTS_EVENT_OUT_OBUF_MEM_CTRL_mem_ctrl_event_out_obuf_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_ctrl_event_out_ffts_obuf : 32;
    } reg;
} SOC_HTS_EVENT_OUT_FFTS_OBUF_MEM_CTRL_UNION;
#endif
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_MEM_CTRL_mem_ctrl_event_out_ffts_obuf_START (0)
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_MEM_CTRL_mem_ctrl_event_out_ffts_obuf_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hts_event_lock : 16;
        unsigned int bitmasken_1023 : 16;
    } reg;
} SOC_HTS_EVENT_LOCK_UNION;
#endif
#define SOC_HTS_EVENT_LOCK_hts_event_lock_START (0)
#define SOC_HTS_EVENT_LOCK_hts_event_lock_END (15)
#define SOC_HTS_EVENT_LOCK_bitmasken_1023_START (16)
#define SOC_HTS_EVENT_LOCK_bitmasken_1023_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hts_ibuf_event_cnt_clr : 32;
    } reg;
} SOC_HTS_IBUF_EVENT_CNT_CLR_UNION;
#endif
#define SOC_HTS_IBUF_EVENT_CNT_CLR_hts_ibuf_event_cnt_clr_START (0)
#define SOC_HTS_IBUF_EVENT_CNT_CLR_hts_ibuf_event_cnt_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_hts_event_in_event_zero_error_pulse : 1;
        unsigned int int_hts_event_in_check_error_pulse : 1;
        unsigned int int_hts_event_in_ibuf_overflow_error_pulse : 1;
        unsigned int int_hts_event_proc_no_rule_error_pulse : 1;
        unsigned int int_hts_event_proc_rule_illegal_error_pulse : 1;
        unsigned int int_hts_event_proc_process_cnt_overflow_error_pulse : 1;
        unsigned int int_hts_event_out_obuf_overflow_error_pulse : 1;
        unsigned int int_hts_event_out_ffts_obuf_overflow_error_pulse : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_HTS_INT_UNION;
#endif
#define SOC_HTS_INT_int_hts_event_in_event_zero_error_pulse_START (0)
#define SOC_HTS_INT_int_hts_event_in_event_zero_error_pulse_END (0)
#define SOC_HTS_INT_int_hts_event_in_check_error_pulse_START (1)
#define SOC_HTS_INT_int_hts_event_in_check_error_pulse_END (1)
#define SOC_HTS_INT_int_hts_event_in_ibuf_overflow_error_pulse_START (2)
#define SOC_HTS_INT_int_hts_event_in_ibuf_overflow_error_pulse_END (2)
#define SOC_HTS_INT_int_hts_event_proc_no_rule_error_pulse_START (3)
#define SOC_HTS_INT_int_hts_event_proc_no_rule_error_pulse_END (3)
#define SOC_HTS_INT_int_hts_event_proc_rule_illegal_error_pulse_START (4)
#define SOC_HTS_INT_int_hts_event_proc_rule_illegal_error_pulse_END (4)
#define SOC_HTS_INT_int_hts_event_proc_process_cnt_overflow_error_pulse_START (5)
#define SOC_HTS_INT_int_hts_event_proc_process_cnt_overflow_error_pulse_END (5)
#define SOC_HTS_INT_int_hts_event_out_obuf_overflow_error_pulse_START (6)
#define SOC_HTS_INT_int_hts_event_out_obuf_overflow_error_pulse_END (6)
#define SOC_HTS_INT_int_hts_event_out_ffts_obuf_overflow_error_pulse_START (7)
#define SOC_HTS_INT_int_hts_event_out_ffts_obuf_overflow_error_pulse_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_hts_event_in_event_zero_error_mask : 1;
        unsigned int int_hts_event_in_check_error_mask : 1;
        unsigned int int_hts_event_in_ibuf_overflow_error_mask : 1;
        unsigned int int_hts_event_proc_no_rule_error_mask : 1;
        unsigned int int_hts_event_proc_rule_illegal_error_mask : 1;
        unsigned int int_hts_event_proc_process_cnt_overflow_error_mask : 1;
        unsigned int int_hts_event_out_obuf_overflow_error_mask : 1;
        unsigned int int_hts_event_out_ffts_obuf_overflow_error_mask : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_HTS_INT_MASK_UNION;
#endif
#define SOC_HTS_INT_MASK_int_hts_event_in_event_zero_error_mask_START (0)
#define SOC_HTS_INT_MASK_int_hts_event_in_event_zero_error_mask_END (0)
#define SOC_HTS_INT_MASK_int_hts_event_in_check_error_mask_START (1)
#define SOC_HTS_INT_MASK_int_hts_event_in_check_error_mask_END (1)
#define SOC_HTS_INT_MASK_int_hts_event_in_ibuf_overflow_error_mask_START (2)
#define SOC_HTS_INT_MASK_int_hts_event_in_ibuf_overflow_error_mask_END (2)
#define SOC_HTS_INT_MASK_int_hts_event_proc_no_rule_error_mask_START (3)
#define SOC_HTS_INT_MASK_int_hts_event_proc_no_rule_error_mask_END (3)
#define SOC_HTS_INT_MASK_int_hts_event_proc_rule_illegal_error_mask_START (4)
#define SOC_HTS_INT_MASK_int_hts_event_proc_rule_illegal_error_mask_END (4)
#define SOC_HTS_INT_MASK_int_hts_event_proc_process_cnt_overflow_error_mask_START (5)
#define SOC_HTS_INT_MASK_int_hts_event_proc_process_cnt_overflow_error_mask_END (5)
#define SOC_HTS_INT_MASK_int_hts_event_out_obuf_overflow_error_mask_START (6)
#define SOC_HTS_INT_MASK_int_hts_event_out_obuf_overflow_error_mask_END (6)
#define SOC_HTS_INT_MASK_int_hts_event_out_ffts_obuf_overflow_error_mask_START (7)
#define SOC_HTS_INT_MASK_int_hts_event_out_ffts_obuf_overflow_error_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int int_hts_event_in_event_zero_error_mask_stat : 1;
        unsigned int int_hts_event_in_check_error_mask_stat : 1;
        unsigned int int_hts_event_in_ibuf_overflow_error_mask_stat : 1;
        unsigned int int_hts_event_proc_no_rule_error_mask_stat : 1;
        unsigned int int_hts_event_proc_rule_illegal_error_mask_stat : 1;
        unsigned int int_hts_event_proc_process_cnt_overflow_error_mask_stat : 1;
        unsigned int int_hts_event_out_obuf_overflow_error_mask_stat : 1;
        unsigned int int_hts_event_out_ffts_obuf_overflow_error_mask_stat : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_HTS_INT_MASK_STAT_UNION;
#endif
#define SOC_HTS_INT_MASK_STAT_int_hts_event_in_event_zero_error_mask_stat_START (0)
#define SOC_HTS_INT_MASK_STAT_int_hts_event_in_event_zero_error_mask_stat_END (0)
#define SOC_HTS_INT_MASK_STAT_int_hts_event_in_check_error_mask_stat_START (1)
#define SOC_HTS_INT_MASK_STAT_int_hts_event_in_check_error_mask_stat_END (1)
#define SOC_HTS_INT_MASK_STAT_int_hts_event_in_ibuf_overflow_error_mask_stat_START (2)
#define SOC_HTS_INT_MASK_STAT_int_hts_event_in_ibuf_overflow_error_mask_stat_END (2)
#define SOC_HTS_INT_MASK_STAT_int_hts_event_proc_no_rule_error_mask_stat_START (3)
#define SOC_HTS_INT_MASK_STAT_int_hts_event_proc_no_rule_error_mask_stat_END (3)
#define SOC_HTS_INT_MASK_STAT_int_hts_event_proc_rule_illegal_error_mask_stat_START (4)
#define SOC_HTS_INT_MASK_STAT_int_hts_event_proc_rule_illegal_error_mask_stat_END (4)
#define SOC_HTS_INT_MASK_STAT_int_hts_event_proc_process_cnt_overflow_error_mask_stat_START (5)
#define SOC_HTS_INT_MASK_STAT_int_hts_event_proc_process_cnt_overflow_error_mask_stat_END (5)
#define SOC_HTS_INT_MASK_STAT_int_hts_event_out_obuf_overflow_error_mask_stat_START (6)
#define SOC_HTS_INT_MASK_STAT_int_hts_event_out_obuf_overflow_error_mask_stat_END (6)
#define SOC_HTS_INT_MASK_STAT_int_hts_event_out_ffts_obuf_overflow_error_mask_stat_START (7)
#define SOC_HTS_INT_MASK_STAT_int_hts_event_out_ffts_obuf_overflow_error_mask_stat_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hts_dbg_en : 1;
        unsigned int reserved_0 : 15;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HTS_DBG_EN_UNION;
#endif
#define SOC_HTS_DBG_EN_hts_dbg_en_START (0)
#define SOC_HTS_DBG_EN_hts_dbg_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_in_last_rcv_event : 10;
        unsigned int event_in_last_rcv_src_id : 6;
        unsigned int event_in_last_rcv_uid : 12;
        unsigned int reserved : 4;
    } reg;
} SOC_HTS_EVENT_IN_READ_BACK_0_UNION;
#endif
#define SOC_HTS_EVENT_IN_READ_BACK_0_event_in_last_rcv_event_START (0)
#define SOC_HTS_EVENT_IN_READ_BACK_0_event_in_last_rcv_event_END (9)
#define SOC_HTS_EVENT_IN_READ_BACK_0_event_in_last_rcv_src_id_START (10)
#define SOC_HTS_EVENT_IN_READ_BACK_0_event_in_last_rcv_src_id_END (15)
#define SOC_HTS_EVENT_IN_READ_BACK_0_event_in_last_rcv_uid_START (16)
#define SOC_HTS_EVENT_IN_READ_BACK_0_event_in_last_rcv_uid_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_in_rcv_event_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HTS_EVENT_IN_READ_BACK_1_UNION;
#endif
#define SOC_HTS_EVENT_IN_READ_BACK_1_event_in_rcv_event_cnt_START (0)
#define SOC_HTS_EVENT_IN_READ_BACK_1_event_in_rcv_event_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_in_ibuf_last_rcv_event : 10;
        unsigned int reserved_0 : 6;
        unsigned int event_in_ibuf_last_rcv_vp_event : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_HTS_EVENT_IN_READ_BACK_2_UNION;
#endif
#define SOC_HTS_EVENT_IN_READ_BACK_2_event_in_ibuf_last_rcv_event_START (0)
#define SOC_HTS_EVENT_IN_READ_BACK_2_event_in_ibuf_last_rcv_event_END (9)
#define SOC_HTS_EVENT_IN_READ_BACK_2_event_in_ibuf_last_rcv_vp_event_START (16)
#define SOC_HTS_EVENT_IN_READ_BACK_2_event_in_ibuf_last_rcv_vp_event_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_in_ibuf_rcv_event_cnt : 16;
        unsigned int event_in_ibuf_rcv_vp_event_cnt : 16;
    } reg;
} SOC_HTS_EVENT_IN_READ_BACK_3_UNION;
#endif
#define SOC_HTS_EVENT_IN_READ_BACK_3_event_in_ibuf_rcv_event_cnt_START (0)
#define SOC_HTS_EVENT_IN_READ_BACK_3_event_in_ibuf_rcv_event_cnt_END (15)
#define SOC_HTS_EVENT_IN_READ_BACK_3_event_in_ibuf_rcv_vp_event_cnt_START (16)
#define SOC_HTS_EVENT_IN_READ_BACK_3_event_in_ibuf_rcv_vp_event_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_in_ibuf_bitmap_rd_back_sel : 5;
        unsigned int reserved_0 : 11;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HTS_EVENT_IN_READ_BACK_4_UNION;
#endif
#define SOC_HTS_EVENT_IN_READ_BACK_4_event_in_ibuf_bitmap_rd_back_sel_START (0)
#define SOC_HTS_EVENT_IN_READ_BACK_4_event_in_ibuf_bitmap_rd_back_sel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_in_ibuf_bitmap_rd_back : 32;
    } reg;
} SOC_HTS_EVENT_IN_READ_BACK_5_UNION;
#endif
#define SOC_HTS_EVENT_IN_READ_BACK_5_event_in_ibuf_bitmap_rd_back_START (0)
#define SOC_HTS_EVENT_IN_READ_BACK_5_event_in_ibuf_bitmap_rd_back_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_proc_mapping_last_rcv_event : 10;
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HTS_EVENT_PROC_MAPPING_READ_BACK_0_UNION;
#endif
#define SOC_HTS_EVENT_PROC_MAPPING_READ_BACK_0_event_proc_mapping_last_rcv_event_START (0)
#define SOC_HTS_EVENT_PROC_MAPPING_READ_BACK_0_event_proc_mapping_last_rcv_event_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_proc_mapping_rcv_event_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HTS_EVENT_PROC_MAPPING_READ_BACK_1_UNION;
#endif
#define SOC_HTS_EVENT_PROC_MAPPING_READ_BACK_1_event_proc_mapping_rcv_event_cnt_START (0)
#define SOC_HTS_EVENT_PROC_MAPPING_READ_BACK_1_event_proc_mapping_rcv_event_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_proc_fetch_last_rcv_event : 10;
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HTS_EVENT_PROC_FETCH_READ_BACK_0_UNION;
#endif
#define SOC_HTS_EVENT_PROC_FETCH_READ_BACK_0_event_proc_fetch_last_rcv_event_START (0)
#define SOC_HTS_EVENT_PROC_FETCH_READ_BACK_0_event_proc_fetch_last_rcv_event_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_proc_fetch_last_rcv_rule_addr : 10;
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HTS_EVENT_PROC_FETCH_READ_BACK_1_UNION;
#endif
#define SOC_HTS_EVENT_PROC_FETCH_READ_BACK_1_event_proc_fetch_last_rcv_rule_addr_START (0)
#define SOC_HTS_EVENT_PROC_FETCH_READ_BACK_1_event_proc_fetch_last_rcv_rule_addr_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_proc_fetch_rcv_event_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HTS_EVENT_PROC_FETCH_READ_BACK_2_UNION;
#endif
#define SOC_HTS_EVENT_PROC_FETCH_READ_BACK_2_event_proc_fetch_rcv_event_cnt_START (0)
#define SOC_HTS_EVENT_PROC_FETCH_READ_BACK_2_event_proc_fetch_rcv_event_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_proc_process_last_rcv_event : 10;
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_0_UNION;
#endif
#define SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_0_event_proc_process_last_rcv_event_START (0)
#define SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_0_event_proc_process_last_rcv_event_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_proc_process_last_rcv_rule_h : 32;
    } reg;
} SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_1_UNION;
#endif
#define SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_1_event_proc_process_last_rcv_rule_h_START (0)
#define SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_1_event_proc_process_last_rcv_rule_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_proc_process_last_rcv_rule_l : 32;
    } reg;
} SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_2_UNION;
#endif
#define SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_2_event_proc_process_last_rcv_rule_l_START (0)
#define SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_2_event_proc_process_last_rcv_rule_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_proc_process_last_rcv_status : 14;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_3_UNION;
#endif
#define SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_3_event_proc_process_last_rcv_status_START (0)
#define SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_3_event_proc_process_last_rcv_status_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_proc_process_last_snd_status : 14;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_4_UNION;
#endif
#define SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_4_event_proc_process_last_snd_status_START (0)
#define SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_4_event_proc_process_last_snd_status_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_proc_proces_rcv_event_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_5_UNION;
#endif
#define SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_5_event_proc_proces_rcv_event_cnt_START (0)
#define SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_5_event_proc_proces_rcv_event_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_out_dispatch_last_rcv_event : 10;
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_0_UNION;
#endif
#define SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_0_event_out_dispatch_last_rcv_event_START (0)
#define SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_0_event_out_dispatch_last_rcv_event_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_out_dispatch_rcv_event_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_1_UNION;
#endif
#define SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_1_event_out_dispatch_rcv_event_cnt_START (0)
#define SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_1_event_out_dispatch_rcv_event_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_out_dispatch_last_snd_event : 10;
        unsigned int reserved_0 : 6;
        unsigned int event_out_dispatch_last_snd_vp_event : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_2_UNION;
#endif
#define SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_2_event_out_dispatch_last_snd_event_START (0)
#define SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_2_event_out_dispatch_last_snd_event_END (9)
#define SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_2_event_out_dispatch_last_snd_vp_event_START (16)
#define SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_2_event_out_dispatch_last_snd_vp_event_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_out_dispatch_snd_event_cnt : 16;
        unsigned int event_out_dispatch_snd_vp_event_cnt : 16;
    } reg;
} SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_3_UNION;
#endif
#define SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_3_event_out_dispatch_snd_event_cnt_START (0)
#define SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_3_event_out_dispatch_snd_event_cnt_END (15)
#define SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_3_event_out_dispatch_snd_vp_event_cnt_START (16)
#define SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_3_event_out_dispatch_snd_vp_event_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_out_lock_last_snd_event : 10;
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_4_UNION;
#endif
#define SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_4_event_out_lock_last_snd_event_START (0)
#define SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_4_event_out_lock_last_snd_event_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_out_lock_snd_event_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_5_UNION;
#endif
#define SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_5_event_out_lock_snd_event_cnt_START (0)
#define SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_5_event_out_lock_snd_event_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_out_obuf_bitmap_rd_back_sel : 5;
        unsigned int reserved_0 : 11;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HTS_EVENT_OUT_OBUF_READ_BACK_0_UNION;
#endif
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_0_event_out_obuf_bitmap_rd_back_sel_START (0)
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_0_event_out_obuf_bitmap_rd_back_sel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_out_obuf_bitmap_rd_back : 32;
    } reg;
} SOC_HTS_EVENT_OUT_OBUF_READ_BACK_1_UNION;
#endif
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_1_event_out_obuf_bitmap_rd_back_START (0)
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_1_event_out_obuf_bitmap_rd_back_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_out_obuf_mux_last_snd_event : 10;
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HTS_EVENT_OUT_OBUF_READ_BACK_2_UNION;
#endif
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_2_event_out_obuf_mux_last_snd_event_START (0)
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_2_event_out_obuf_mux_last_snd_event_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_out_obuf_mux_snd_event_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HTS_EVENT_OUT_OBUF_READ_BACK_3_UNION;
#endif
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_3_event_out_obuf_mux_snd_event_cnt_START (0)
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_3_event_out_obuf_mux_snd_event_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_out_obuf_dispatch_last_snd_event : 10;
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HTS_EVENT_OUT_OBUF_READ_BACK_4_UNION;
#endif
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_4_event_out_obuf_dispatch_last_snd_event_START (0)
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_4_event_out_obuf_dispatch_last_snd_event_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_out_obuf_dispatch_snd_event_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HTS_EVENT_OUT_OBUF_READ_BACK_5_UNION;
#endif
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_5_event_out_obuf_dispatch_snd_event_cnt_START (0)
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_5_event_out_obuf_dispatch_snd_event_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_out_obuf_arb_last_snd_event : 10;
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HTS_EVENT_OUT_OBUF_READ_BACK_6_UNION;
#endif
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_6_event_out_obuf_arb_last_snd_event_START (0)
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_6_event_out_obuf_arb_last_snd_event_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_out_obuf_arb_snd_event_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HTS_EVENT_OUT_OBUF_READ_BACK_7_UNION;
#endif
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_7_event_out_obuf_arb_snd_event_cnt_START (0)
#define SOC_HTS_EVENT_OUT_OBUF_READ_BACK_7_event_out_obuf_arb_snd_event_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_out_uid_concat_last_snd_event : 10;
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HTS_EVENT_OUT_UID_CONCAT_READ_BACK0_UNION;
#endif
#define SOC_HTS_EVENT_OUT_UID_CONCAT_READ_BACK0_event_out_uid_concat_last_snd_event_START (0)
#define SOC_HTS_EVENT_OUT_UID_CONCAT_READ_BACK0_event_out_uid_concat_last_snd_event_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_out_uid_concat_snd_event_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HTS_EVENT_OUT_UID_CONCAT_READ_BACK1_UNION;
#endif
#define SOC_HTS_EVENT_OUT_UID_CONCAT_READ_BACK1_event_out_uid_concat_snd_event_cnt_START (0)
#define SOC_HTS_EVENT_OUT_UID_CONCAT_READ_BACK1_event_out_uid_concat_snd_event_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_out_ffts_obuf_mux_last_snd_event : 10;
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_1_UNION;
#endif
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_1_event_out_ffts_obuf_mux_last_snd_event_START (0)
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_1_event_out_ffts_obuf_mux_last_snd_event_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_out_ffts_obuf_mux_snd_event_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_2_UNION;
#endif
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_2_event_out_ffts_obuf_mux_snd_event_cnt_START (0)
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_2_event_out_ffts_obuf_mux_snd_event_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_out_ffts_obuf_dispatch_last_snd_event : 10;
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_3_UNION;
#endif
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_3_event_out_ffts_obuf_dispatch_last_snd_event_START (0)
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_3_event_out_ffts_obuf_dispatch_last_snd_event_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_out_ffts_obuf_dispatch_snd_event_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_4_UNION;
#endif
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_4_event_out_ffts_obuf_dispatch_snd_event_cnt_START (0)
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_4_event_out_ffts_obuf_dispatch_snd_event_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_out_ffts_obuf_arb_last_snd_event : 10;
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_5_UNION;
#endif
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_5_event_out_ffts_obuf_arb_last_snd_event_START (0)
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_5_event_out_ffts_obuf_arb_last_snd_event_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_out_ffts_obuf_arb_snd_event_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_6_UNION;
#endif
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_6_event_out_ffts_obuf_arb_snd_event_cnt_START (0)
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_6_event_out_ffts_obuf_arb_snd_event_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_out_ffts_obuf_bitmap_rd_back_sel : 5;
        unsigned int reserved_0 : 11;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HTS_EVENT_OUT_FFTS_OBUF_BITMAP_READ_BACK_0_UNION;
#endif
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_BITMAP_READ_BACK_0_event_out_ffts_obuf_bitmap_rd_back_sel_START (0)
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_BITMAP_READ_BACK_0_event_out_ffts_obuf_bitmap_rd_back_sel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_out_ffts_obuf_bitmap_rd_back : 32;
    } reg;
} SOC_HTS_EVENT_OUT_FFTS_OBUF_BITMAP_READ_BACK_1_UNION;
#endif
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_BITMAP_READ_BACK_1_event_out_ffts_obuf_bitmap_rd_back_START (0)
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_BITMAP_READ_BACK_1_event_out_ffts_obuf_bitmap_rd_back_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_out_arb_last_snd_event : 10;
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HTS_EVENT_OUT_ARB_READ_BACK0_UNION;
#endif
#define SOC_HTS_EVENT_OUT_ARB_READ_BACK0_event_out_arb_last_snd_event_START (0)
#define SOC_HTS_EVENT_OUT_ARB_READ_BACK0_event_out_arb_last_snd_event_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_out_arb_snd_event_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HTS_EVENT_OUT_ARB_READ_BACK1_UNION;
#endif
#define SOC_HTS_EVENT_OUT_ARB_READ_BACK1_event_out_arb_snd_event_cnt_START (0)
#define SOC_HTS_EVENT_OUT_ARB_READ_BACK1_event_out_arb_snd_event_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_in_check_error_last_event : 10;
        unsigned int event_in_check_error_last_src_id : 6;
        unsigned int event_in_check_error_last_uid : 12;
        unsigned int reserved : 4;
    } reg;
} SOC_HTS_EVENT_IN_ERROR_READ_BACK_0_UNION;
#endif
#define SOC_HTS_EVENT_IN_ERROR_READ_BACK_0_event_in_check_error_last_event_START (0)
#define SOC_HTS_EVENT_IN_ERROR_READ_BACK_0_event_in_check_error_last_event_END (9)
#define SOC_HTS_EVENT_IN_ERROR_READ_BACK_0_event_in_check_error_last_src_id_START (10)
#define SOC_HTS_EVENT_IN_ERROR_READ_BACK_0_event_in_check_error_last_src_id_END (15)
#define SOC_HTS_EVENT_IN_ERROR_READ_BACK_0_event_in_check_error_last_uid_START (16)
#define SOC_HTS_EVENT_IN_ERROR_READ_BACK_0_event_in_check_error_last_uid_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_in_ibuf_overflow_error_last_event : 10;
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HTS_EVENT_IN_ERROR_READ_BACK_1_UNION;
#endif
#define SOC_HTS_EVENT_IN_ERROR_READ_BACK_1_event_in_ibuf_overflow_error_last_event_START (0)
#define SOC_HTS_EVENT_IN_ERROR_READ_BACK_1_event_in_ibuf_overflow_error_last_event_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_proc_mapping_no_rule_error_last_event : 10;
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_0_UNION;
#endif
#define SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_0_event_proc_mapping_no_rule_error_last_event_START (0)
#define SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_0_event_proc_mapping_no_rule_error_last_event_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_proc_process_illegal_rule_error_last_rule_h : 32;
    } reg;
} SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_1_UNION;
#endif
#define SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_1_event_proc_process_illegal_rule_error_last_rule_h_START (0)
#define SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_1_event_proc_process_illegal_rule_error_last_rule_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_proc_process_illegal_rule_error_last_rule_l : 32;
    } reg;
} SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_2_UNION;
#endif
#define SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_2_event_proc_process_illegal_rule_error_last_rule_l_START (0)
#define SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_2_event_proc_process_illegal_rule_error_last_rule_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_proc_process_illegal_rule_error_last_event : 10;
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_3_UNION;
#endif
#define SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_3_event_proc_process_illegal_rule_error_last_event_START (0)
#define SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_3_event_proc_process_illegal_rule_error_last_event_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_proc_process_status_overflow_error_last_event : 10;
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_4_UNION;
#endif
#define SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_4_event_proc_process_status_overflow_error_last_event_START (0)
#define SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_4_event_proc_process_status_overflow_error_last_event_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_out_obuf_overflow_error_last_event : 10;
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HTS_EVENT_OUT_OBUF_ERROR_READ_BACK_0_UNION;
#endif
#define SOC_HTS_EVENT_OUT_OBUF_ERROR_READ_BACK_0_event_out_obuf_overflow_error_last_event_START (0)
#define SOC_HTS_EVENT_OUT_OBUF_ERROR_READ_BACK_0_event_out_obuf_overflow_error_last_event_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_out_ffts_obuf_overflow_error_last_event : 10;
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HTS_EVENT_OUT_FFTS_OBUF_ERROR_READ_BACK_0_UNION;
#endif
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_ERROR_READ_BACK_0_event_out_ffts_obuf_overflow_error_last_event_START (0)
#define SOC_HTS_EVENT_OUT_FFTS_OBUF_ERROR_READ_BACK_0_event_out_ffts_obuf_overflow_error_last_event_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hts_event_store : 16;
        unsigned int bitmasken_1023 : 16;
    } reg;
} SOC_HTS_EVENT_STORE_UNION;
#endif
#define SOC_HTS_EVENT_STORE_hts_event_store_START (0)
#define SOC_HTS_EVENT_STORE_hts_event_store_END (15)
#define SOC_HTS_EVENT_STORE_bitmasken_1023_START (16)
#define SOC_HTS_EVENT_STORE_bitmasken_1023_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hts_obuf_event_cnt_clr : 32;
    } reg;
} SOC_HTS_OBUF_EVENT_CNT_CLR_UNION;
#endif
#define SOC_HTS_OBUF_EVENT_CNT_CLR_hts_obuf_event_cnt_clr_START (0)
#define SOC_HTS_OBUF_EVENT_CNT_CLR_hts_obuf_event_cnt_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hts_event_in_src_id_event_cnt_en : 16;
        unsigned int bitmasken_64 : 16;
    } reg;
} SOC_HTS_EVENT_IN_SRC_ID_EVENT_CNT_EN0_UNION;
#endif
#define SOC_HTS_EVENT_IN_SRC_ID_EVENT_CNT_EN0_hts_event_in_src_id_event_cnt_en_START (0)
#define SOC_HTS_EVENT_IN_SRC_ID_EVENT_CNT_EN0_hts_event_in_src_id_event_cnt_en_END (15)
#define SOC_HTS_EVENT_IN_SRC_ID_EVENT_CNT_EN0_bitmasken_64_START (16)
#define SOC_HTS_EVENT_IN_SRC_ID_EVENT_CNT_EN0_bitmasken_64_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hts_event_in_src_id_event_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HTS_EVENT_IN_SRC_ID_EVENT_CNT_READ_BACK0_UNION;
#endif
#define SOC_HTS_EVENT_IN_SRC_ID_EVENT_CNT_READ_BACK0_hts_event_in_src_id_event_cnt_START (0)
#define SOC_HTS_EVENT_IN_SRC_ID_EVENT_CNT_READ_BACK0_hts_event_in_src_id_event_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hts_event_in_src_id_event_cnt_clr : 32;
    } reg;
} SOC_HTS_EVENT_IN_SRC_ID_EVENT_CNT_CLR_UNION;
#endif
#define SOC_HTS_EVENT_IN_SRC_ID_EVENT_CNT_CLR_hts_event_in_src_id_event_cnt_clr_START (0)
#define SOC_HTS_EVENT_IN_SRC_ID_EVENT_CNT_CLR_hts_event_in_src_id_event_cnt_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hts_event_out_dst_id_event_cnt_en : 16;
        unsigned int bitmasken_64 : 16;
    } reg;
} SOC_HTS_EVENT_OUT_DST_ID_EVENT_CNT_EN0_UNION;
#endif
#define SOC_HTS_EVENT_OUT_DST_ID_EVENT_CNT_EN0_hts_event_out_dst_id_event_cnt_en_START (0)
#define SOC_HTS_EVENT_OUT_DST_ID_EVENT_CNT_EN0_hts_event_out_dst_id_event_cnt_en_END (15)
#define SOC_HTS_EVENT_OUT_DST_ID_EVENT_CNT_EN0_bitmasken_64_START (16)
#define SOC_HTS_EVENT_OUT_DST_ID_EVENT_CNT_EN0_bitmasken_64_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hts_event_out_dst_id_event_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HTS_EVENT_OUT_DST_ID_EVENT_CNT_READ_BACK0_UNION;
#endif
#define SOC_HTS_EVENT_OUT_DST_ID_EVENT_CNT_READ_BACK0_hts_event_out_dst_id_event_cnt_START (0)
#define SOC_HTS_EVENT_OUT_DST_ID_EVENT_CNT_READ_BACK0_hts_event_out_dst_id_event_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hts_event_out_dst_id_event_cnt_clr : 32;
    } reg;
} SOC_HTS_EVENT_OUT_DST_ID_EVENT_CNT_CLR_UNION;
#endif
#define SOC_HTS_EVENT_OUT_DST_ID_EVENT_CNT_CLR_hts_event_out_dst_id_event_cnt_clr_START (0)
#define SOC_HTS_EVENT_OUT_DST_ID_EVENT_CNT_CLR_hts_event_out_dst_id_event_cnt_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_mapping_idx : 32;
    } reg;
} SOC_HTS_EVENT_IN_CHECK_UNION;
#endif
#define SOC_HTS_EVENT_IN_CHECK_cfg_mapping_idx_START (0)
#define SOC_HTS_EVENT_IN_CHECK_cfg_mapping_idx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_mapping_idx : 32;
    } reg;
} SOC_HTS_EVENT_PROC_MAPPING_IDX_UNION;
#endif
#define SOC_HTS_EVENT_PROC_MAPPING_IDX_cfg_mapping_idx_START (0)
#define SOC_HTS_EVENT_PROC_MAPPING_IDX_cfg_mapping_idx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_rule : 32;
    } reg;
} SOC_HTS_EVENT_PROC_RULE_UNION;
#endif
#define SOC_HTS_EVENT_PROC_RULE_cfg_rule_START (0)
#define SOC_HTS_EVENT_PROC_RULE_cfg_rule_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_status_read_back : 32;
    } reg;
} SOC_HTS_EVENT_PROC_STATUS_UNION;
#endif
#define SOC_HTS_EVENT_PROC_STATUS_cfg_status_read_back_START (0)
#define SOC_HTS_EVENT_PROC_STATUS_cfg_status_read_back_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int total_ost_cnt : 5;
        unsigned int reserved_0 : 3;
        unsigned int gpu_ost_cnt : 5;
        unsigned int reserved_1 : 3;
        unsigned int npu_hwts_ost_cnt : 5;
        unsigned int reserved_2 : 3;
        unsigned int npu_tscpu_ost_cnt : 5;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_HTS_WRAP_OST_CNT_0_UNION;
#endif
#define SOC_HTS_WRAP_OST_CNT_0_total_ost_cnt_START (0)
#define SOC_HTS_WRAP_OST_CNT_0_total_ost_cnt_END (4)
#define SOC_HTS_WRAP_OST_CNT_0_gpu_ost_cnt_START (8)
#define SOC_HTS_WRAP_OST_CNT_0_gpu_ost_cnt_END (12)
#define SOC_HTS_WRAP_OST_CNT_0_npu_hwts_ost_cnt_START (16)
#define SOC_HTS_WRAP_OST_CNT_0_npu_hwts_ost_cnt_END (20)
#define SOC_HTS_WRAP_OST_CNT_0_npu_tscpu_ost_cnt_START (24)
#define SOC_HTS_WRAP_OST_CNT_0_npu_tscpu_ost_cnt_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hts_wrap_idle_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HTS_IDLE_EN_UNION;
#endif
#define SOC_HTS_IDLE_EN_hts_wrap_idle_en_START (0)
#define SOC_HTS_IDLE_EN_hts_wrap_idle_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hts_idle : 1;
        unsigned int hts_wrap_mst_to_qsp_idle : 1;
        unsigned int hts_wrap_apb_dec_idle : 1;
        unsigned int hts_wrap_idle : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_HTS_IDLE_READ_BACK_UNION;
#endif
#define SOC_HTS_IDLE_READ_BACK_hts_idle_START (0)
#define SOC_HTS_IDLE_READ_BACK_hts_idle_END (0)
#define SOC_HTS_IDLE_READ_BACK_hts_wrap_mst_to_qsp_idle_START (1)
#define SOC_HTS_IDLE_READ_BACK_hts_wrap_mst_to_qsp_idle_END (1)
#define SOC_HTS_IDLE_READ_BACK_hts_wrap_apb_dec_idle_START (2)
#define SOC_HTS_IDLE_READ_BACK_hts_wrap_apb_dec_idle_END (2)
#define SOC_HTS_IDLE_READ_BACK_hts_wrap_idle_START (3)
#define SOC_HTS_IDLE_READ_BACK_hts_wrap_idle_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ibuf_clr_bus_nopress_cnt_req : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HTS_WRAP_IBUF_CLR_BUS_NOPRESS_CNT_REQ_UNION;
#endif
#define SOC_HTS_WRAP_IBUF_CLR_BUS_NOPRESS_CNT_REQ_ibuf_clr_bus_nopress_cnt_req_START (0)
#define SOC_HTS_WRAP_IBUF_CLR_BUS_NOPRESS_CNT_REQ_ibuf_clr_bus_nopress_cnt_req_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ibuf_clr_bus_nopress_cnt_ack : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HTS_WRAP_IBUF_CLR_BUS_NOPRESS_CNT_ACK_UNION;
#endif
#define SOC_HTS_WRAP_IBUF_CLR_BUS_NOPRESS_CNT_ACK_ibuf_clr_bus_nopress_cnt_ack_START (0)
#define SOC_HTS_WRAP_IBUF_CLR_BUS_NOPRESS_CNT_ACK_ibuf_clr_bus_nopress_cnt_ack_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ibuf_clr_bus_nopress_cnt_value : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HTS_WRAP_IBUF_CLR_BUS_NOPRESS_CNT_VALUE_UNION;
#endif
#define SOC_HTS_WRAP_IBUF_CLR_BUS_NOPRESS_CNT_VALUE_ibuf_clr_bus_nopress_cnt_value_START (0)
#define SOC_HTS_WRAP_IBUF_CLR_BUS_NOPRESS_CNT_VALUE_ibuf_clr_bus_nopress_cnt_value_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ibuf_clr_bus_nopress_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HTS_WRAP_IBUF_CLR_BUS_NOPRESS_CNT_UNION;
#endif
#define SOC_HTS_WRAP_IBUF_CLR_BUS_NOPRESS_CNT_ibuf_clr_bus_nopress_cnt_START (0)
#define SOC_HTS_WRAP_IBUF_CLR_BUS_NOPRESS_CNT_ibuf_clr_bus_nopress_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int obuf_clr_bus_nopress_cnt_req : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HTS_WRAP_OBUF_CLR_BUS_NOPRESS_CNT_REQ_UNION;
#endif
#define SOC_HTS_WRAP_OBUF_CLR_BUS_NOPRESS_CNT_REQ_obuf_clr_bus_nopress_cnt_req_START (0)
#define SOC_HTS_WRAP_OBUF_CLR_BUS_NOPRESS_CNT_REQ_obuf_clr_bus_nopress_cnt_req_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int obuf_clr_bus_nopress_cnt_ack : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HTS_WRAP_OBUF_CLR_BUS_NOPRESS_CNT_ACK_UNION;
#endif
#define SOC_HTS_WRAP_OBUF_CLR_BUS_NOPRESS_CNT_ACK_obuf_clr_bus_nopress_cnt_ack_START (0)
#define SOC_HTS_WRAP_OBUF_CLR_BUS_NOPRESS_CNT_ACK_obuf_clr_bus_nopress_cnt_ack_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int obuf_clr_bus_nopress_cnt_value : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HTS_WRAP_OBUF_CLR_BUS_NOPRESS_CNT_VALUE_UNION;
#endif
#define SOC_HTS_WRAP_OBUF_CLR_BUS_NOPRESS_CNT_VALUE_obuf_clr_bus_nopress_cnt_value_START (0)
#define SOC_HTS_WRAP_OBUF_CLR_BUS_NOPRESS_CNT_VALUE_obuf_clr_bus_nopress_cnt_value_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int obuf_clr_bus_nopress_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HTS_WRAP_OBUF_CLR_BUS_NOPRESS_CNT_UNION;
#endif
#define SOC_HTS_WRAP_OBUF_CLR_BUS_NOPRESS_CNT_obuf_clr_bus_nopress_cnt_START (0)
#define SOC_HTS_WRAP_OBUF_CLR_BUS_NOPRESS_CNT_obuf_clr_bus_nopress_cnt_END (15)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
