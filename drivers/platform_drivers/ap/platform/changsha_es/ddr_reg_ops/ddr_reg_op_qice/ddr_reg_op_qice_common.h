#include "./../ddr_reg_op_logic.h"
#include <soc_ddr_qice_baseaddr_interface.h>
#define QICE_MODULE_OFFSET 0x1000
#define QICE_MODULE_INDEX(module) (SOC_QICE_ ##module ##_BASE_ADDR / QICE_MODULE_OFFSET)
#define QICE_MODULE_BASE_ADDR(local_idx) (SOC_QICE_BASE_ADDR + local_idx * 0x1000)
#define QICE_REG_MODULE(module) (SOC_QICE_BASE_ADDR + SOC_QICE_ ##module ##_BASE_ADDR)
#define GET_MEMBER_QICE(reg_val,offset,module_type,module) \
 do { \
  reg_val = ddr_readl(SOC_QICE_##module_type##_##offset##_ADDR(QICE_REG_MODULE(module))); \
 } while (0)
#define GET_MEMBER_QICE_X(reg_val,offset,module_type,module,x) \
 do { \
  reg_val = ddr_readl(SOC_QICE_##module_type##_##offset##_ADDR(QICE_REG_MODULE(module), x)); \
 } while (0)
#define SET_MEMBER_FLUSH_QICE(reg_val,offset,module_type,module) \
 ddr_writel(reg_val, SOC_QICE_##module_type##_##offset##_ADDR(QICE_REG_MODULE(module)))
#define SET_MEMBER_FLUSH_QICE_X(reg_val,offset,module_type,module,x) \
 ddr_writel(reg_val, SOC_QICE_##module_type##_##offset##_ADDR(QICE_REG_MODULE(module), x))
#define WAIT_MEMBER_QICE_STAT(offset,member,expect_val,module_type,module) \
 do { \
  volatile unsigned int __val; \
  unsigned int __result; \
  unsigned int __reg_val; \
  do { \
   GET_MEMBER_QICE(__reg_val, offset, module_type, module); \
   GET_MEMBER_CACHE(QICE, __reg_val, offset, member, __result); \
   __val = (unsigned int)(!!(__result != (expect_val))); \
  } while (__val); \
 } while (0)
#define CHECK_MEMBER_QICE_STAT(offset,member,expect_val,result,module_type,module) \
 do { \
  unsigned int __reg_val; \
  GET_MEMBER_QICE(__reg_val, offset, module_type, module); \
  GET_MEMBER_CACHE(QICE, __reg_val, offset, member, result); \
  (result) = (unsigned int)(!!((result) != (expect_val))); \
 } while (0)
#define CHECK_REGVAL_QICE_STAT(offset,expect_val,result,module_type,module) \
 do { \
  unsigned int __reg_val; \
  GET_MEMBER_QICE(__reg_val, offset, module_type, module); \
  (result) = (unsigned int)(!!((__reg_val) != (expect_val))); \
 } while (0)
#define WAIT_REGVAL_QICE_STAT(offset,expect_val,module_type,module) \
 do { \
  unsigned int __reg_val; \
  do { \
   GET_MEMBER_QICE(__reg_val, offset, module_type, module); \
  } while (__reg_val != (unsigned int)(expect_val)); \
 } while (0)
#define WAIT_REGVAL_QICE_STAT_X(offset,expect_val,module_type,module,x) \
 do { \
  unsigned int __reg_val; \
  do { \
   GET_MEMBER_QICE_X(__reg_val, offset, module_type, module, x); \
  } while (__reg_val != (unsigned int)(expect_val)); \
 } while (0)
