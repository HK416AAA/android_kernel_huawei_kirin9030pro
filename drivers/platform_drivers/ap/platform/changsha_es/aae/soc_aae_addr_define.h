#ifndef SOC_AAE_ADDR_DEFINE_H
#define SOC_AAE_ADDR_DEFINE_H 
#ifdef __cplusplus
 #if __cplusplus
  extern "C" {
 #endif
#endif
#define AAE_FFTS_OFFSET 0x0002C000
#define AAE_BASE_ADDR 0xE2500000
#define AAE_CFG_OFFSET 0x00022000
#define LOG_BASR_ADDR 0x00015C30
#define AAE_DACC_XPU_CFG_RISCV_INT_REG_ADDR (AAE_BASE_ADDR + AAE_CFG_OFFSET + (0x1108))
#define AAE_DACC_XPU_CFG_RISCV_LOG_ADDR (AAE_BASE_ADDR + LOG_BASR_ADDR + (0xF0))
#define AAE_DACC_AAE_IMAGE_TIME_DUMP_REG_ADDR(base,index) (base + 0x15C00 + 4*(index))
#define AAE_DACC_FFAP1_INTR_CNT_DUMP_REG_ADDR(base,index) (base + 0x15d00 + 4*(index))
#define AAE_DACC_FFAP1_PAYLOAD_PARSE_DUMP_REG_ADDR(base,index) (base + 0x15d10 + 4*(index))
#define AAE_DACC_INTR_CNT_DUMP_REG_ADDR(base,index) (base + 0x15C80 + 4*(index))
#define AAE_DACC_FRAME_END_INTR_CNT_DUMP_REG_ADDR(base,index) (base + 0x15D28 + 4*(index))
#define AAE_DACC_CMDLIST_CARRY_RESULT_DUMP_REG_ADDR(base,index) (base + (0x15FC4 + 4*(index)))
#define AAE_DACC_LOG_DUMP_REG_ADDR(base,index) (base + (0x15000 + 4*(index)))
#ifdef __cplusplus
 #if __cplusplus
  }
 #endif
#endif
#endif
