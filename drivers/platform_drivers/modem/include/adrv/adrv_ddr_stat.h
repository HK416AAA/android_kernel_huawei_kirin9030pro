/* Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved. */
#ifndef ADRV_DDR_STAT_H
#define ADRV_DDR_STAT_H
 /**
 * @brief ddr record bandwidth mntn info
 *
 * @par 描述:
 * ddr record bandwidth mntn info
 */
extern void ddr_stat_bandwidth_mntn(void);

/**
 * @brief ddr record bandwidth mntn info to sram for modem
 *
 * @par 描述:
 * ddr record bandwidth mntn info for modem
 *
 * @param[in/out]  buffer store the bandwidth mntn info
 * @param[in]  size calculated in char of the buffer
 *
 * @retval >0 SUCCESS
 * @retval <0 FAIL
 */
extern int ddr_stat_bandwidth_record_for_modem(unsigned int* value, unsigned int length);

#endif
