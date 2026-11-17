#ifndef __AO_VOLT_COMMON_H_
#define __AO_VOLT_COMMON_H_ 
#include <peri_ao_volt.h>
#include <soc_sctrl_interface.h>
#include <pmic_interface.h>
#include <soc_ao_crg_interface.h>
#define AO_VOLT_REG_ADDR PMIC_LDO0_VSET_ADDR(0)
#define AO_VOLT_ECO_REG_ADDR PMIC_LDO0_VSET_ECO_ADDR(0)
#define AO_VOLT_STEP 10
#define AO_VOLT_STEP_UV 10000
#define AO_VOLT_BASE 500
#define ao_volt_mv2code(mv) pmu_mv2code(mv, AO_VOLT_BASE, AO_VOLT_STEP)
#define ao_volt_code2mv(code) pmu_code2mv(code, AO_VOLT_BASE, AO_VOLT_STEP)
#define AO_AVS_DNLIMIT 600
#define AO_HOLD_TIME 25
#define RAMP_RATIO 60
enum ao_volt_level {
 AO_VOLT_LEVEL0,
 AO_VOLT_LEVEL1,
 AO_VOLT_LEVEL2,
 AO_VOLT_LEVEL_MAX,
};
#define AO_VOL_LOWTEMP AO_VOLT_LEVEL2
enum ao_vote_module {
 AO_VOTE_MODULE_IOMCU,
 AO_VOTE_MODULE_ASP,
 AO_VOTE_MODULE_LOWTEMP,
 AO_VOTE_MODULE_STD,
 AO_VOTE_MODULE_MAX
};
enum ao_avs_page {
 AO_AVS_STD,
 AO_AVS_IOMCU,
 AO_AVS_ASP,
 AO_AVS_END,
};
#define AO_AVS_BASE AO_AVS_IOMCU
union ao_vote_reg {
 unsigned int value;
 struct {
  unsigned int vote0: 2;
  unsigned int vote1: 2;
  unsigned int vote2: 2;
  unsigned int vote3: 2;
  unsigned int vote4: 2;
  unsigned int vote5: 2;
  unsigned int vote6: 2;
  unsigned int vote7: 2;
  unsigned int valid0: 1;
  unsigned int valid1: 1;
  unsigned int valid2: 1;
  unsigned int valid3: 1;
  unsigned int valid4: 1;
  unsigned int valid5: 1;
  unsigned int valid6: 1;
  unsigned int valid7: 1;
  unsigned int rsv: 5;
  unsigned int avs_done: 1;
  unsigned int vote_result: 2;
 } reg;
};
#define AO_VOTE_MASK 0x3
#define ao_vote_offset(vote) ((unsigned int)(vote) * 2)
#define ao_vote_clr(src,vote) ((src) &= (~(unsigned int)(AO_VOTE_MASK << ao_vote_offset(vote))))
#define ao_vote_get(src,vote) (((src) >> ao_vote_offset(vote)) & AO_VOTE_MASK)
#define ao_vote_set(src,vote,lvl) do { \
 ao_vote_clr(src, vote); \
 (src) |= ((lvl) & AO_VOTE_MASK) << ao_vote_offset(vote); \
} while (0)
#define ao_valid_offset(vote) ((unsigned int)(vote) + 16)
#define ao_vote_enable(src,vote) ((src) |= (1 << ao_valid_offset(vote)))
#define ao_vote_disable(src,vote) ((src) &= (~(unsigned int)(1 << ao_valid_offset(vote))))
#define ao_vote_is_enable(src,vote) ((src >> ao_valid_offset(vote)) & 0x1)
#define ao_vote_reg_addr(cpu,vote) (SOC_SCTRL_SCBAKDATA17_ADDR(SOC_ ##cpu ##_SCTRL_BASE_ADDR))
#define NOC_AOBUS_MK_MASK_VAL(val,msk) \
  MK_MASK_VAL(val, msk, SOC_AO_CRG_SCCLKDIV2_SEC_div_aonoc_div_START)
#define NOC_AOBUS_LEVEL2_RATE NOC_AOBUS_MK_MASK_VAL(0x3, 0x3F)
#define NOC_AOBUS_LEVEL1_RATE NOC_AOBUS_MK_MASK_VAL(0x6, 0x3F)
#define NOC_AOBUS_LEVEL0_BANNED 0x0
struct ao_bus_freq {
 unsigned int freq[AO_VOLT_LEVEL_MAX];
 unsigned int addr;
};
#define AOCRG_REG_ADDR(reg,master) SOC_AO_CRG_SC ##reg ##_SEC_ADDR(SOC_ ##master ##_AO_CRG_BASE_ADDR)
#define AOCRG_REG_PTR(reg,master) (volatile SOC_AO_CRG_SC ##reg ##_SEC_UNION *)(uintptr_t)(AOCRG_REG_ADDR(reg, master))
#define NOC_AOBUS_DIV_REG_ADDR(cpu) AOCRG_REG_ADDR(CLKDIV2, cpu)
#define NOC_AOBUS_DIV_REG_PTR(cpu) AOCRG_REG_PTR(CLKDIV2, cpu)
#endif
