#ifndef __DDR_REG_OP_QICE_EXTERN_H__
#define __DDR_REG_OP_QICE_EXTERN_H__ 
#define QICE_LOCAL_INDEX_OFFSET 0x1000
#define SEC_START_INDEX 208
#define SEC_END_INDEX 225
#define QICE_SEC_PORT_MAX (SEC_END_INDEX - SEC_START_INDEX + 1)
#define SET_MEMBER_FLUSH_QICE_IBXE(reg_val,offset) \
do { \
 volatile unsigned int __i; \
 for(__i = IBXE_START_INDEX; __i <= IBXE_END_INDEX; __i += 1) { \
  SET_MEMBER_FLUSH_QICE_IBXE_EACH(reg_val, offset, __i) \
  ddr_writel(reg_val, SOC_QICE_##offset##_ADDR(SOC_QICE_BASE_ADDR + __i * QICE_LOCAL_INDEX_OFFSET)); \
 } \
} while (0)
#define SET_MEMBER_FLUSH_QICE_SEC(reg_val,offset) \
do { \
 volatile unsigned int __i; \
 for(__i = SEC_START_INDEX; __i <= SEC_END_INDEX; __i += 1) { \
  ddr_writel(reg_val, SOC_QICE_SEC_##offset##_ADDR(SOC_QICE_BASE_ADDR + __i * QICE_LOCAL_INDEX_OFFSET)); \
 } \
} while (0)
#define GET_MEMBER_QICE_IB(reg_val,offset,ib) \
do { \
 reg_val = ddr_readl(SOC_QICE_##offset##_ADDR(SOC_QICE_BASE_ADDR + (ib) * QICE_LOCAL_INDEX_OFFSET)); \
} while (0)
#define GET_MEMBER_QICE_IB_X(reg_val,offset,ib,rgn) \
do { \
 reg_val = ddr_readl(SOC_QICE_##offset##_ADDR(SOC_QICE_BASE_ADDR + (ib) * QICE_LOCAL_INDEX_OFFSET, rgn)); \
} while (0)
#define SET_MEMBER_CACHE_QICE_SEC(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(QICE_SEC, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_QICE_KPU(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(QICE_KPU, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_QICE(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(QICE, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_QICE_IB(reg_val,offset,ib) \
do { \
 ddr_writel(reg_val, SOC_QICE_##offset##_ADDR(SOC_QICE_BASE_ADDR + (ib) * QICE_LOCAL_INDEX_OFFSET)); \
} while (0)
#define SET_MEMBER_FLUSH_QICE_IB_X(reg_val,offset,ib,rgn) \
do { \
 ddr_writel(reg_val, SOC_QICE_##offset##_ADDR(SOC_QICE_BASE_ADDR + (ib) * QICE_LOCAL_INDEX_OFFSET, rgn)); \
} while (0)
#define GET_MEMBER_CACHE_QICE(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(QICE, reg_val, offset, member, result)
#define GET_MEMBER_CACHE_QICE_KPU(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(QICE_KPU, reg_val, offset, member, result)
#define SC_LOCAL_INDEX_OFFSET 0x1000
#define GET_MEMBER_SC(reg_val,offset,idx) \
 do { \
  reg_val = ddr_readl(SOC_QICE_##offset##_ADDR(SOC_ACPU_SC_CFG_BASE_ADDR + (idx) * SC_LOCAL_INDEX_OFFSET));\
 } while (0)
#define GET_MEMBER_REG(reg_val,offset,idx) \
 do { \
  if (idx == SEC_SC_IDX ) { \
   GET_MEMBER_SC(reg_val, offset, idx); \
  } else { \
   GET_MEMBER_QICE_IB(reg_val, offset, idx); \
  } \
 } while (0)
#define GET_MEMBER_SC_X(reg_val,offset,idx,rgn) \
  do { \
    reg_val = ddr_readl(SOC_QICE_##offset##_ADDR(SOC_ACPU_SC_CFG_BASE_ADDR + (idx) * SC_LOCAL_INDEX_OFFSET, rgn));\
  } while (0)
#define GET_MEMBER_REG_X(reg_val,offset,idx,rgn) \
 do { \
  if (idx == SEC_SC_IDX ) { \
   GET_MEMBER_SC_X(reg_val, offset, idx, rgn); \
  } else { \
   GET_MEMBER_QICE_IB_X(reg_val, offset, idx, rgn); \
  } \
 } while (0)
#define SET_MEMBER_FLUSH_SC(reg_val,offset,idx) \
 do { \
  ddr_writel(reg_val, SOC_QICE_##offset##_ADDR(SOC_ACPU_SC_CFG_BASE_ADDR + (idx) * SC_LOCAL_INDEX_OFFSET));\
 } while (0)
#define SET_MEMBER_FLUSH_REG(reg_val,offset,idx) \
 do { \
  if (idx == SEC_SC_IDX ) { \
   SET_MEMBER_FLUSH_SC(reg_val, offset, idx); \
  } else { \
   SET_MEMBER_FLUSH_QICE_IB(reg_val, offset, idx); \
  } \
 } while (0)
#define SET_MEMBER_FLUSH_SC_X(reg_val,offset,rgn,idx) \
 do { \
  ddr_writel(reg_val, SOC_QICE_##offset##_ADDR(SOC_ACPU_SC_CFG_BASE_ADDR + (idx) * SC_LOCAL_INDEX_OFFSET, rgn));\
 } while (0)
#define SET_MEMBER_FLUSH_REG_X(reg_val,offset,idx,rgn) \
 do { \
  if (idx == SEC_SC_IDX ) { \
   SET_MEMBER_FLUSH_SC_X(reg_val, offset, rgn, idx); \
  } else { \
   SET_MEMBER_FLUSH_QICE_IB_X(reg_val, offset, idx, rgn); \
  } \
 } while (0)
#endif
