#ifndef __DDR_REG_OP_BDL_H__
#define __DDR_REG_OP_BDL_H__ 
#include "ddr_reg_op_packphy.h"
enum rdq_bdl {
    RDQBDL0 = 0,
    RDQBDL1,
    RDQBDL2,
    RDQBDL3,
    RDQBDL4,
    RDQBDL5,
    RDQBDL6,
    RDQBDL7,
    RDMBDL,
    RDQBDL_MAX_NUM
};
enum wdq_bdl {
    WDQBDL0 = 0,
    WDQBDL1,
    WDQBDL2,
    WDQBDL3,
    WDQBDL4,
    WDQBDL5,
    WDQBDL6,
    WDQBDL7,
    WDMBDL,
    WDQBDL_MAX_NUM
};
enum ca_bdl {
    CABDL0 = 0,
    CABDL1,
    CABDL2,
    CABDL3,
    CABDL4,
    CABDL5,
    CABDL6,
    CABDL_MAX_NUM
};
#define GET_RDQ_BDL_REG_ADDR(ch,offset,rank,bytelane,evenodd) \
    DDR_REG_PACK(ch) + offset + DDR_REG_RANK_OFFSET(rank) + DDR_REG_BYTELANE_OFFSET(bytelane) + DDR_REG_EVENODD_OFFSET(evenodd)
#define _RDQ_BDL_REG_ITEM(x,y) \
    {SOC_DDR_PACK_##x##_ADDR(0, 0, 0, 0), SOC_DDR_PACK_##x##_##y##_START, SOC_DDR_PACK_##x##_##y##_END}
#define RDQ_BDL_REG_LIST \
    [RDQBDL0] = _RDQ_BDL_REG_ITEM(DXNRDQNBDL0, rdq0bdl), \
    [RDQBDL1] = _RDQ_BDL_REG_ITEM(DXNRDQNBDL1, rdq1bdl), \
    [RDQBDL2] = _RDQ_BDL_REG_ITEM(DXNRDQNBDL2, rdq2bdl), \
    [RDQBDL3] = _RDQ_BDL_REG_ITEM(DXNRDQNBDL3, rdq3bdl), \
    [RDQBDL4] = _RDQ_BDL_REG_ITEM(DXNRDQNBDL4, rdq4bdl), \
    [RDQBDL5] = _RDQ_BDL_REG_ITEM(DXNRDQNBDL5, rdq5bdl), \
    [RDQBDL6] = _RDQ_BDL_REG_ITEM(DXNRDQNBDL6, rdq6bdl), \
    [RDQBDL7] = _RDQ_BDL_REG_ITEM(DXNRDQNBDL7, rdq7bdl), \
    [RDMBDL] = _RDQ_BDL_REG_ITEM(DXNRDQNBDL8, rdmbdl), \
#define GET_WDQ_BDL_REG_ADDR(ch,offset,rank,bytelane) \
    DDR_REG_PACK(ch) + offset + DDR_REG_RANK_OFFSET(rank) + DDR_REG_BYTELANE_OFFSET(bytelane)
#define _WDQ_BDL_REG_ITEM(x,y) \
    {SOC_DDR_PACK_##x##_ADDR(0, 0, 0), SOC_DDR_PACK_##x##_##y##_START, SOC_DDR_PACK_##x##_##y##_END}
#define WDQ_BDL_REG_LIST \
    [WDQBDL0] = _WDQ_BDL_REG_ITEM(DXNWDQNBDL0, wdq0bdl), \
    [WDQBDL1] = _WDQ_BDL_REG_ITEM(DXNWDQNBDL1, wdq1bdl), \
    [WDQBDL2] = _WDQ_BDL_REG_ITEM(DXNWDQNBDL2, wdq2bdl), \
    [WDQBDL3] = _WDQ_BDL_REG_ITEM(DXNWDQNBDL3, wdq3bdl), \
    [WDQBDL4] = _WDQ_BDL_REG_ITEM(DXNWDQNBDL4, wdq4bdl), \
    [WDQBDL5] = _WDQ_BDL_REG_ITEM(DXNWDQNBDL5, wdq5bdl), \
    [WDQBDL6] = _WDQ_BDL_REG_ITEM(DXNWDQNBDL6, wdq6bdl), \
    [WDQBDL7] = _WDQ_BDL_REG_ITEM(DXNWDQNBDL7, wdq7bdl), \
    [WDMBDL] = _WDQ_BDL_REG_ITEM(DXNWDQNBDL8, wdmbdl), \
#define GET_CA_BDL_REG_ADDR(ch,offset) \
    DDR_REG_PACK(ch) + offset
#define _CA_BDL_REG_ITEM(x,y) \
    {SOC_DDR_PACK_##x##_ADDR(0), SOC_DDR_PACK_##x##_##y##_START, SOC_DDR_PACK_##x##_##y##_END}
#define CA_BDL_REG_LIST \
    [CABDL0] = _CA_BDL_REG_ITEM(ACADDRBDL0, addr0_bdl), \
    [CABDL1] = _CA_BDL_REG_ITEM(ACADDRBDL1, addr1_bdl), \
    [CABDL2] = _CA_BDL_REG_ITEM(ACADDRBDL2, addr2_bdl), \
    [CABDL3] = _CA_BDL_REG_ITEM(ACADDRBDL3, addr3_bdl), \
    [CABDL4] = _CA_BDL_REG_ITEM(ACADDRBDL4, addr4_bdl), \
    [CABDL5] = _CA_BDL_REG_ITEM(ACADDRBDL5, addr5_bdl), \
    [CABDL6] = _CA_BDL_REG_ITEM(ACADDRBDL6, addr6_bdl), \
typedef struct {
    unsigned int reg_offset;
    unsigned int member_start;
    unsigned int member_end;
} bdl_reg_str;
#endif
