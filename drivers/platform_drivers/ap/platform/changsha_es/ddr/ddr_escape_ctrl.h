#include <pmic_interface.h>
#define DDR_ESCAPE_CTRL_PMU_REG PMIC_HRST_REG9_ADDR(0)
typedef union {
 unsigned int value;
 struct {
  unsigned int close_lp : 1;
  unsigned int need_escape : 1;
  unsigned int reserved : 6;
 } reg;
} SOC_ESCAPE_CTRL_PMU_UNION;
#define SOC_ESCAPE_CTRL_PMU_close_lp_START (0)
#define SOC_ESCAPE_CTRL_PMU_close_lp_END (0)
#define SOC_ESCAPE_CTRL_PMU_need_escape_START (1)
#define SOC_ESCAPE_CTRL_PMU_need_escape_END (1)
