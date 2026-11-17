#ifndef __SOC_HI9030_V200_QIC_FW_CTRL_INTERFACE_H__
#define __SOC_HI9030_V200_QIC_FW_CTRL_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_FW_CTRL0_ADDR(base) (base)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_FW_CTRL1_ADDR(base) ((base) + 0x4UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID0_ADDR(base) ((base) + 0x20UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID1_ADDR(base) ((base) + 0x24UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID2_ADDR(base) ((base) + 0x28UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID3_ADDR(base) ((base) + 0x2cUL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID4_ADDR(base) ((base) + 0x30UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID5_ADDR(base) ((base) + 0x34UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID6_ADDR(base) ((base) + 0x38UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID7_ADDR(base) ((base) + 0x3cUL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_STARTADDR_ADDR(base) ((base) + 0x40UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_ENDADDR_ADDR(base) ((base) + 0x44UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_STARTADDR_ADDR(base) ((base) + 0x48UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_ENDADDR_ADDR(base) ((base) + 0x4cUL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION2_STARTADDR_ADDR(base) ((base) + 0x50UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION2_ENDADDR_ADDR(base) ((base) + 0x54UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION3_STARTADDR_ADDR(base) ((base) + 0x58UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION3_ENDADDR_ADDR(base) ((base) + 0x5cUL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION4_STARTADDR_ADDR(base) ((base) + 0x60UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION4_ENDADDR_ADDR(base) ((base) + 0x64UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION5_STARTADDR_ADDR(base) ((base) + 0x68UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION5_ENDADDR_ADDR(base) ((base) + 0x6cUL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION6_STARTADDR_ADDR(base) ((base) + 0x70UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION6_ENDADDR_ADDR(base) ((base) + 0x74UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION7_STARTADDR_ADDR(base) ((base) + 0x78UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION7_ENDADDR_ADDR(base) ((base) + 0x7cUL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION8_STARTADDR_ADDR(base) ((base) + 0x80UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION8_ENDADDR_ADDR(base) ((base) + 0x84UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION9_STARTADDR_ADDR(base) ((base) + 0x88UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION9_ENDADDR_ADDR(base) ((base) + 0x8cUL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION10_STARTADDR_ADDR(base) ((base) + 0x90UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION10_ENDADDR_ADDR(base) ((base) + 0x94UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION11_STARTADDR_ADDR(base) ((base) + 0x98UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION11_ENDADDR_ADDR(base) ((base) + 0x9cUL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION12_STARTADDR_ADDR(base) ((base) + 0xa0UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION12_ENDADDR_ADDR(base) ((base) + 0xa4UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION13_STARTADDR_ADDR(base) ((base) + 0xa8UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION13_ENDADDR_ADDR(base) ((base) + 0xacUL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION14_STARTADDR_ADDR(base) ((base) + 0xb0UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION14_ENDADDR_ADDR(base) ((base) + 0xb4UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION15_STARTADDR_ADDR(base) ((base) + 0xb8UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION15_ENDADDR_ADDR(base) ((base) + 0xbcUL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION16_STARTADDR_ADDR(base) ((base) + 0xc0UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION16_ENDADDR_ADDR(base) ((base) + 0xc4UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION17_STARTADDR_ADDR(base) ((base) + 0xc8UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION17_ENDADDR_ADDR(base) ((base) + 0xccUL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION18_STARTADDR_ADDR(base) ((base) + 0xd0UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION18_ENDADDR_ADDR(base) ((base) + 0xd4UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION19_STARTADDR_ADDR(base) ((base) + 0xd8UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION19_ENDADDR_ADDR(base) ((base) + 0xdcUL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION20_STARTADDR_ADDR(base) ((base) + 0xe0UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION20_ENDADDR_ADDR(base) ((base) + 0xe4UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION21_STARTADDR_ADDR(base) ((base) + 0xe8UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION21_ENDADDR_ADDR(base) ((base) + 0xecUL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION22_STARTADDR_ADDR(base) ((base) + 0xf0UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION22_ENDADDR_ADDR(base) ((base) + 0xf4UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION23_STARTADDR_ADDR(base) ((base) + 0xf8UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION23_ENDADDR_ADDR(base) ((base) + 0xfcUL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID0_ADDR(base) ((base) + 0x100 + 0x20 * regoion_num)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID1_ADDR(base) ((base) + 0x100UL + 0x20UL * regoion_num + 0x4UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID2_ADDR(base) ((base) + 0x100UL + 0x20UL * regoion_num + 0x8UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID3_ADDR(base) ((base) + 0x100UL + 0x20UL * regoion_num + 0xcUL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID4_ADDR(base) ((base) + 0x100UL + 0x20UL * regoion_num + 0x10UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID5_ADDR(base) ((base) + 0x100UL + 0x20UL * regoion_num + 0x14UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID6_ADDR(base) ((base) + 0x100UL + 0x20UL * regoion_num + 0x18UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID7_ADDR(base) ((base) + 0x100UL + 0x20UL * regoion_num + 0x1cUL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID0_ADDR(base) ((base) + 0x100 + 0x20 * regoion_num)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID1_ADDR(base) ((base) + 0x100UL + 0x20UL * regoion_num + 0x4UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID2_ADDR(base) ((base) + 0x100UL + 0x20UL * regoion_num + 0x8UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID3_ADDR(base) ((base) + 0x100UL + 0x20UL * regoion_num + 0xcUL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID4_ADDR(base) ((base) + 0x100UL + 0x20UL * regoion_num + 0x10UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID5_ADDR(base) ((base) + 0x100UL + 0x20UL * regoion_num + 0x14UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID6_ADDR(base) ((base) + 0x100UL + 0x20UL * regoion_num + 0x18UL)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID7_ADDR(base) ((base) + 0x100UL + 0x20UL * regoion_num + 0x1cUL)
#else
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_FW_CTRL0_ADDR(base) (base)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_FW_CTRL1_ADDR(base) ((base) + 0x4)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID0_ADDR(base) ((base) + 0x20)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID1_ADDR(base) ((base) + 0x24)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID2_ADDR(base) ((base) + 0x28)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID3_ADDR(base) ((base) + 0x2c)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID4_ADDR(base) ((base) + 0x30)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID5_ADDR(base) ((base) + 0x34)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID6_ADDR(base) ((base) + 0x38)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID7_ADDR(base) ((base) + 0x3c)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_STARTADDR_ADDR(base) ((base) + 0x40)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_ENDADDR_ADDR(base) ((base) + 0x44)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_STARTADDR_ADDR(base) ((base) + 0x48)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_ENDADDR_ADDR(base) ((base) + 0x4c)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION2_STARTADDR_ADDR(base) ((base) + 0x50)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION2_ENDADDR_ADDR(base) ((base) + 0x54)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION3_STARTADDR_ADDR(base) ((base) + 0x58)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION3_ENDADDR_ADDR(base) ((base) + 0x5c)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION4_STARTADDR_ADDR(base) ((base) + 0x60)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION4_ENDADDR_ADDR(base) ((base) + 0x64)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION5_STARTADDR_ADDR(base) ((base) + 0x68)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION5_ENDADDR_ADDR(base) ((base) + 0x6c)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION6_STARTADDR_ADDR(base) ((base) + 0x70)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION6_ENDADDR_ADDR(base) ((base) + 0x74)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION7_STARTADDR_ADDR(base) ((base) + 0x78)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION7_ENDADDR_ADDR(base) ((base) + 0x7c)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION8_STARTADDR_ADDR(base) ((base) + 0x80)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION8_ENDADDR_ADDR(base) ((base) + 0x84)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION9_STARTADDR_ADDR(base) ((base) + 0x88)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION9_ENDADDR_ADDR(base) ((base) + 0x8c)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION10_STARTADDR_ADDR(base) ((base) + 0x90)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION10_ENDADDR_ADDR(base) ((base) + 0x94)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION11_STARTADDR_ADDR(base) ((base) + 0x98)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION11_ENDADDR_ADDR(base) ((base) + 0x9c)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION12_STARTADDR_ADDR(base) ((base) + 0xa0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION12_ENDADDR_ADDR(base) ((base) + 0xa4)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION13_STARTADDR_ADDR(base) ((base) + 0xa8)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION13_ENDADDR_ADDR(base) ((base) + 0xac)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION14_STARTADDR_ADDR(base) ((base) + 0xb0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION14_ENDADDR_ADDR(base) ((base) + 0xb4)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION15_STARTADDR_ADDR(base) ((base) + 0xb8)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION15_ENDADDR_ADDR(base) ((base) + 0xbc)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION16_STARTADDR_ADDR(base) ((base) + 0xc0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION16_ENDADDR_ADDR(base) ((base) + 0xc4)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION17_STARTADDR_ADDR(base) ((base) + 0xc8)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION17_ENDADDR_ADDR(base) ((base) + 0xcc)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION18_STARTADDR_ADDR(base) ((base) + 0xd0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION18_ENDADDR_ADDR(base) ((base) + 0xd4)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION19_STARTADDR_ADDR(base) ((base) + 0xd8)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION19_ENDADDR_ADDR(base) ((base) + 0xdc)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION20_STARTADDR_ADDR(base) ((base) + 0xe0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION20_ENDADDR_ADDR(base) ((base) + 0xe4)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION21_STARTADDR_ADDR(base) ((base) + 0xe8)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION21_ENDADDR_ADDR(base) ((base) + 0xec)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION22_STARTADDR_ADDR(base) ((base) + 0xf0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION22_ENDADDR_ADDR(base) ((base) + 0xf4)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION23_STARTADDR_ADDR(base) ((base) + 0xf8)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION23_ENDADDR_ADDR(base) ((base) + 0xfc)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID0_ADDR(base) ((base) + 0x100 + 0x20 * regoion_num)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID1_ADDR(base) ((base) + 0x100 + 0x20 * regoion_num + 0x4)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID2_ADDR(base) ((base) + 0x100 + 0x20 * regoion_num + 0x8)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID3_ADDR(base) ((base) + 0x100 + 0x20 * regoion_num + 0xc)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID4_ADDR(base) ((base) + 0x100 + 0x20 * regoion_num + 0x10)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID5_ADDR(base) ((base) + 0x100 + 0x20 * regoion_num + 0x14)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID6_ADDR(base) ((base) + 0x100 + 0x20 * regoion_num + 0x18)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID7_ADDR(base) ((base) + 0x100 + 0x20 * regoion_num + 0x1c)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID0_ADDR(base) ((base) + 0x100 + 0x20 * regoion_num)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID1_ADDR(base) ((base) + 0x100 + 0x20 * regoion_num + 0x4)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID2_ADDR(base) ((base) + 0x100 + 0x20 * regoion_num + 0x8)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID3_ADDR(base) ((base) + 0x100 + 0x20 * regoion_num + 0xc)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID4_ADDR(base) ((base) + 0x100 + 0x20 * regoion_num + 0x10)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID5_ADDR(base) ((base) + 0x100 + 0x20 * regoion_num + 0x14)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID6_ADDR(base) ((base) + 0x100 + 0x20 * regoion_num + 0x18)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID7_ADDR(base) ((base) + 0x100 + 0x20 * regoion_num + 0x1c)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lock : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_FW_CTRL0_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_FW_CTRL0_lock_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_FW_CTRL0_lock_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fw_mode : 2;
        unsigned int qtp_fw_hide : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_FW_CTRL1_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_FW_CTRL1_fw_mode_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_FW_CTRL1_fw_mode_END (1)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_FW_CTRL1_qtp_fw_hide_START (2)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_FW_CTRL1_qtp_fw_hide_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_31_0 : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID0_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID0_mid_31_0_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID0_mid_31_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_63_32 : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID1_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID1_mid_63_32_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID1_mid_63_32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_95_64 : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID2_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID2_mid_95_64_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID2_mid_95_64_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_127_96 : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID3_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID3_mid_127_96_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID3_mid_127_96_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_159_128 : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID4_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID4_mid_159_128_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID4_mid_159_128_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_191_160 : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID5_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID5_mid_191_160_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID5_mid_191_160_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_223_192 : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID6_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID6_mid_223_192_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID6_mid_223_192_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_255_224 : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID7_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID7_mid_255_224_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_COMMON_MID7_mid_255_224_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0_region0_start_addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_STARTADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_STARTADDR_tb0_region0_start_addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_STARTADDR_tb0_region0_start_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0_region0_end_addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_ENDADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_ENDADDR_tb0_region0_end_addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_ENDADDR_tb0_region0_end_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region1 start addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_STARTADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_STARTADDR_tb0 region1 start addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_STARTADDR_tb0 region1 start addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region1 end addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_ENDADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_ENDADDR_tb0 region1 end addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_ENDADDR_tb0 region1 end addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region2 start addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION2_STARTADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION2_STARTADDR_tb0 region2 start addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION2_STARTADDR_tb0 region2 start addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region2 end addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION2_ENDADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION2_ENDADDR_tb0 region2 end addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION2_ENDADDR_tb0 region2 end addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region3 start addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION3_STARTADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION3_STARTADDR_tb0 region3 start addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION3_STARTADDR_tb0 region3 start addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region3 end addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION3_ENDADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION3_ENDADDR_tb0 region3 end addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION3_ENDADDR_tb0 region3 end addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region4 start addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION4_STARTADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION4_STARTADDR_tb0 region4 start addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION4_STARTADDR_tb0 region4 start addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region4 end addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION4_ENDADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION4_ENDADDR_tb0 region4 end addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION4_ENDADDR_tb0 region4 end addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region5 start addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION5_STARTADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION5_STARTADDR_tb0 region5 start addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION5_STARTADDR_tb0 region5 start addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region5 end addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION5_ENDADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION5_ENDADDR_tb0 region5 end addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION5_ENDADDR_tb0 region5 end addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region6 start addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION6_STARTADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION6_STARTADDR_tb0 region6 start addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION6_STARTADDR_tb0 region6 start addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region6 end addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION6_ENDADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION6_ENDADDR_tb0 region6 end addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION6_ENDADDR_tb0 region6 end addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region7 start addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION7_STARTADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION7_STARTADDR_tb0 region7 start addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION7_STARTADDR_tb0 region7 start addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region7 end addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION7_ENDADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION7_ENDADDR_tb0 region7 end addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION7_ENDADDR_tb0 region7 end addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region8 start addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION8_STARTADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION8_STARTADDR_tb0 region8 start addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION8_STARTADDR_tb0 region8 start addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region8 end addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION8_ENDADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION8_ENDADDR_tb0 region8 end addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION8_ENDADDR_tb0 region8 end addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region9 start addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION9_STARTADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION9_STARTADDR_tb0 region9 start addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION9_STARTADDR_tb0 region9 start addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region9 end addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION9_ENDADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION9_ENDADDR_tb0 region9 end addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION9_ENDADDR_tb0 region9 end addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region10 start addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION10_STARTADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION10_STARTADDR_tb0 region10 start addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION10_STARTADDR_tb0 region10 start addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region10 end addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION10_ENDADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION10_ENDADDR_tb0 region10 end addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION10_ENDADDR_tb0 region10 end addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region11 start addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION11_STARTADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION11_STARTADDR_tb0 region11 start addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION11_STARTADDR_tb0 region11 start addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region11 end addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION11_ENDADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION11_ENDADDR_tb0 region11 end addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION11_ENDADDR_tb0 region11 end addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region12 start addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION12_STARTADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION12_STARTADDR_tb0 region12 start addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION12_STARTADDR_tb0 region12 start addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region12 end addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION12_ENDADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION12_ENDADDR_tb0 region12 end addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION12_ENDADDR_tb0 region12 end addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region13 start addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION13_STARTADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION13_STARTADDR_tb0 region13 start addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION13_STARTADDR_tb0 region13 start addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region13 end addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION13_ENDADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION13_ENDADDR_tb0 region13 end addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION13_ENDADDR_tb0 region13 end addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region14 start addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION14_STARTADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION14_STARTADDR_tb0 region14 start addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION14_STARTADDR_tb0 region14 start addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region14 end addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION14_ENDADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION14_ENDADDR_tb0 region14 end addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION14_ENDADDR_tb0 region14 end addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region15 start addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION15_STARTADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION15_STARTADDR_tb0 region15 start addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION15_STARTADDR_tb0 region15 start addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region15 end addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION15_ENDADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION15_ENDADDR_tb0 region15 end addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION15_ENDADDR_tb0 region15 end addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region16 start addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION16_STARTADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION16_STARTADDR_tb0 region16 start addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION16_STARTADDR_tb0 region16 start addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region16 end addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION16_ENDADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION16_ENDADDR_tb0 region16 end addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION16_ENDADDR_tb0 region16 end addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region17 start addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION17_STARTADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION17_STARTADDR_tb0 region17 start addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION17_STARTADDR_tb0 region17 start addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region17 end addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION17_ENDADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION17_ENDADDR_tb0 region17 end addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION17_ENDADDR_tb0 region17 end addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region18 start addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION18_STARTADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION18_STARTADDR_tb0 region18 start addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION18_STARTADDR_tb0 region18 start addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region18 end addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION18_ENDADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION18_ENDADDR_tb0 region18 end addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION18_ENDADDR_tb0 region18 end addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region19 start addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION19_STARTADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION19_STARTADDR_tb0 region19 start addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION19_STARTADDR_tb0 region19 start addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region19 end addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION19_ENDADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION19_ENDADDR_tb0 region19 end addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION19_ENDADDR_tb0 region19 end addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region20 start addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION20_STARTADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION20_STARTADDR_tb0 region20 start addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION20_STARTADDR_tb0 region20 start addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region20 end addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION20_ENDADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION20_ENDADDR_tb0 region20 end addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION20_ENDADDR_tb0 region20 end addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region21 start addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION21_STARTADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION21_STARTADDR_tb0 region21 start addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION21_STARTADDR_tb0 region21 start addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region21 end addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION21_ENDADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION21_ENDADDR_tb0 region21 end addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION21_ENDADDR_tb0 region21 end addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region22 start addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION22_STARTADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION22_STARTADDR_tb0 region22 start addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION22_STARTADDR_tb0 region22 start addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0 region22 end addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION22_ENDADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION22_ENDADDR_tb0 region22 end addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION22_ENDADDR_tb0 region22 end addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0_region23_start_addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION23_STARTADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION23_STARTADDR_tb0_region23_start_addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION23_STARTADDR_tb0_region23_start_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb0_region23_end_addr : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION23_ENDADDR_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION23_ENDADDR_tb0_region23_end_addr_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION23_ENDADDR_tb0_region23_end_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_31_0 : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID0_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID0_mid_31_0_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID0_mid_31_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_63_32 : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID1_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID1_mid_63_32_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID1_mid_63_32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_95_64 : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID2_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID2_mid_95_64_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID2_mid_95_64_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_127_96 : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID3_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID3_mid_127_96_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID3_mid_127_96_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_159_128 : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID4_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID4_mid_159_128_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID4_mid_159_128_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_191_160 : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID5_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID5_mid_191_160_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID5_mid_191_160_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_223_192 : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID6_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID6_mid_223_192_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID6_mid_223_192_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_255_224 : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID7_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID7_mid_255_224_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION0_MID7_mid_255_224_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_31_0 : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID0_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID0_mid_31_0_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID0_mid_31_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_63_32 : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID1_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID1_mid_63_32_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID1_mid_63_32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_95_64 : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID2_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID2_mid_95_64_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID2_mid_95_64_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_127_96 : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID3_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID3_mid_127_96_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID3_mid_127_96_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_159_128 : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID4_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID4_mid_159_128_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID4_mid_159_128_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_191_160 : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID5_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID5_mid_191_160_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID5_mid_191_160_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_223_192 : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID6_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID6_mid_223_192_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID6_mid_223_192_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_255_224 : 32;
    } reg;
} SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID7_UNION;
#endif
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID7_mid_255_224_START (0)
#define SOC_Hi9030_V200_QIC_FW_CTRL_TB0_REGION1_MID7_mid_255_224_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
