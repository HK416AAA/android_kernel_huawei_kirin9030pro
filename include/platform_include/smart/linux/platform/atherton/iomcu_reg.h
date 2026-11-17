/* Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved. 
   extract macros used in imocu from the soc_mid,soc_sctrl_interface,bbox_diaginfo_id_def,soc_syscounter_interface header files
*/
 
#ifndef __IOMCU_REG_H__
#define __IOMCU_REG_H__
#ifdef CONFIG_HEADER_FILE_REPLACE_EXTRACT

#ifndef __SOC_H_FOR_ASM__
#define SOC_SCTRL_SCBAKDATA27_ADDR(base)                      ((base) + (0x478UL))
#define SOC_SCTRL_SCBAKDATA3_MSK_ADDR(base)                   ((base) + (0x4CCUL))
#define SOC_SCTRL_SCBAKDATA6_MSK_ADDR(base)                   ((base) + (0x4D8UL))
#define SOC_SYSCOUNTER_CNTCV_L32_NS_ADDR(base)                ((base) + 0x1008UL)
#define SOC_SYSCOUNTER_CNTCV_H32_NS_ADDR(base)                ((base) + 0x100CUL)
#else
#define SOC_SCTRL_SCBAKDATA27_ADDR(base)                      ((base) + (0x478))
#define SOC_SCTRL_SCBAKDATA3_MSK_ADDR(base)                   ((base) + (0x4CC))
#define SOC_SCTRL_SCBAKDATA6_MSK_ADDR(base)                   ((base) + (0x4D8))
#define SOC_SYSCOUNTER_CNTCV_L32_NS_ADDR(base)                ((base) + 0x1008)
#define SOC_SYSCOUNTER_CNTCV_H32_NS_ADDR(base)                ((base) + 0x100C)
#endif

#endif
#endif