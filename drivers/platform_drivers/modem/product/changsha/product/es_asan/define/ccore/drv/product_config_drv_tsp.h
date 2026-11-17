/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2021. All rights reserved.
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of ****** nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#if !defined(__PRODUCT_CONFIG_DRV_TSP_H__)
#define __PRODUCT_CONFIG_DRV_TSP_H__


#ifndef ENABLE_BUILD_VARS
#define ENABLE_BUILD_VARS
#endif


#ifndef CCPU_OS
#define CCPU_OS RTOSCK_SMP
#endif


#ifndef CCPU_TSP_OS
#define CCPU_TSP_OS RTOSCK_TSP_V300
#endif


#ifndef CCPU_ARCH
#define CCPU_ARCH HITSP_V300
#endif


#ifndef CCPU_TSP_OS_PATH
#define CCPU_TSP_OS_PATH tspv300
#endif


#ifndef CCPU_CORE_NUM
#define CCPU_CORE_NUM 2
#endif


#ifndef CCPU_RUN_COREMASK
#define CCPU_RUN_COREMASK 0x5
#endif


#ifndef CCPU_RUN_LOGIC_COREMASK
#define CCPU_RUN_LOGIC_COREMASK 0x3
#endif


#ifndef CCPU_RUN_LOGIC_VEC_COREMASK
#define CCPU_RUN_LOGIC_VEC_COREMASK 0x2
#endif


#ifndef CCPU_DSS_NUM
#define CCPU_DSS_NUM 1
#endif


#ifndef TSP_DSS0_CORE_NUM
#define TSP_DSS0_CORE_NUM 2
#endif


#ifndef TSP_DSS1_CORE_NUM
#define TSP_DSS1_CORE_NUM 0
#endif


#ifndef TSP_DSS2_CORE_NUM
#define TSP_DSS2_CORE_NUM 0
#endif


#ifndef TSP_DSS3_CORE_NUM
#define TSP_DSS3_CORE_NUM 0
#endif


#ifndef MODEM_SCHEDULE_DOMAIN_NUM
#define MODEM_SCHEDULE_DOMAIN_NUM 2
#endif


#ifndef MODEM_SCHEDULE_DOMAIN0
#define MODEM_SCHEDULE_DOMAIN0
#endif


#ifndef MODEM_SCHEDULE_DOMAIN0_TYPE
#define MODEM_SCHEDULE_DOMAIN0_TYPE 1
#endif


#ifndef MODEM_SCHEDULE_DOMAIN0_COREMASK
#define MODEM_SCHEDULE_DOMAIN0_COREMASK 0x1
#endif


#ifndef MODEM_SCHEDULE_DOMAIN0_COREBEGIN
#define MODEM_SCHEDULE_DOMAIN0_COREBEGIN 0
#endif


#ifndef MODEM_SCHEDULE_DOMAIN0_CORENUM
#define MODEM_SCHEDULE_DOMAIN0_CORENUM 1
#endif


#ifndef MODEM_SCHEDULE_DOMAIN1
#define MODEM_SCHEDULE_DOMAIN1
#endif


#ifndef MODEM_SCHEDULE_DOMAIN1_TYPE
#define MODEM_SCHEDULE_DOMAIN1_TYPE 1
#endif


#ifndef MODEM_SCHEDULE_DOMAIN1_COREMASK
#define MODEM_SCHEDULE_DOMAIN1_COREMASK 0x2
#endif


#ifndef MODEM_SCHEDULE_DOMAIN1_COREBEGIN
#define MODEM_SCHEDULE_DOMAIN1_COREBEGIN 1
#endif


#ifndef MODEM_SCHEDULE_DOMAIN1_CORENUM
#define MODEM_SCHEDULE_DOMAIN1_CORENUM 1
#endif


#ifndef MODEM_SCHEDULE_DOMAIN2
#endif


#ifndef MODEM_SCHEDULE_DOMAIN2_TYPE
#define MODEM_SCHEDULE_DOMAIN2_TYPE 0
#endif


#ifndef MODEM_SCHEDULE_DOMAIN2_COREMASK
#define MODEM_SCHEDULE_DOMAIN2_COREMASK 0
#endif


#ifndef MODEM_SCHEDULE_DOMAIN2_COREBEGIN
#define MODEM_SCHEDULE_DOMAIN2_COREBEGIN 0
#endif


#ifndef MODEM_SCHEDULE_DOMAIN2_CORENUM
#define MODEM_SCHEDULE_DOMAIN2_CORENUM 0
#endif


#ifndef MODEM_SCHEDULE_DOMAIN3
#endif


#ifndef MODEM_SCHEDULE_DOMAIN3_TYPE
#define MODEM_SCHEDULE_DOMAIN3_TYPE 0
#endif


#ifndef MODEM_SCHEDULE_DOMAIN3_COREMASK
#define MODEM_SCHEDULE_DOMAIN3_COREMASK 0
#endif


#ifndef MODEM_SCHEDULE_DOMAIN3_COREBEGIN
#define MODEM_SCHEDULE_DOMAIN3_COREBEGIN 0
#endif


#ifndef MODEM_SCHEDULE_DOMAIN3_CORENUM
#define MODEM_SCHEDULE_DOMAIN3_CORENUM 0
#endif


#ifndef MODEM_SCHEDULE_DOMAIN4
#endif


#ifndef MODEM_SCHEDULE_DOMAIN4_TYPE
#define MODEM_SCHEDULE_DOMAIN4_TYPE 0
#endif


#ifndef MODEM_SCHEDULE_DOMAIN4_COREMASK
#define MODEM_SCHEDULE_DOMAIN4_COREMASK 0
#endif


#ifndef MODEM_SCHEDULE_DOMAIN4_COREBEGIN
#define MODEM_SCHEDULE_DOMAIN4_COREBEGIN 0
#endif


#ifndef MODEM_SCHEDULE_DOMAIN4_CORENUM
#define MODEM_SCHEDULE_DOMAIN4_CORENUM 0
#endif


#ifndef CONFIG_DRV_SCHEDULE_DOMAIN
#define CONFIG_DRV_SCHEDULE_DOMAIN MODEM_SCHEDULE_DOMAIN1_COREMASK
#endif


#ifndef CONFIG_PS_SCHEDULE_DOMAIN
#define CONFIG_PS_SCHEDULE_DOMAIN MODEM_SCHEDULE_DOMAIN1_COREMASK
#endif


#ifndef CONFIG_PHY_SCHEDULE_DOMAIN
#define CONFIG_PHY_SCHEDULE_DOMAIN MODEM_SCHEDULE_DOMAIN0_COREMASK
#endif


#ifndef CONFIG_PHY_SCHEDULE_DOMAIN_COREBEGIN
#define CONFIG_PHY_SCHEDULE_DOMAIN_COREBEGIN MODEM_SCHEDULE_DOMAIN0_COREBEGIN
#endif


#ifndef CONFIG_PHY_SCHEDULE_DOMAIN_CORENUM
#define CONFIG_PHY_SCHEDULE_DOMAIN_CORENUM MODEM_SCHEDULE_DOMAIN0_CORENUM
#endif


#ifndef TSP_PL1_MEM_ADDR
#define TSP_PL1_MEM_ADDR 0xF6500000
#endif


#ifndef TSP_PL1_MEM_SIZE
#define TSP_PL1_MEM_SIZE 0x40000
#endif


#ifndef TSP_L1ITCM_ADDR
#define TSP_L1ITCM_ADDR 0xF6580000
#endif


#ifndef TSP_L1ITCM_SIZE
#define TSP_L1ITCM_SIZE 0x30000
#endif


#ifndef TSP_L1DTCM_FUSION
#define TSP_L1DTCM_FUSION
#endif


#ifndef TSP_MPSCU_MP_REG_BASE
#define TSP_MPSCU_MP_REG_BASE 0xF5E00000
#endif


#ifndef TSP_MPSCU_MP_REG_SIZE
#define TSP_MPSCU_MP_REG_SIZE 0x200000
#endif


#ifndef TSP_REGISTER_START_ADDR
#define TSP_REGISTER_START_ADDR 0xE0000000
#endif


#ifndef TSP_REGISTER_SIZE
#define TSP_REGISTER_SIZE 0x20000000
#endif


#ifndef NXDEP_TEXT_ALIGN_SIZE
#define NXDEP_TEXT_ALIGN_SIZE 0x1000
#endif


#ifndef NXDEP_DATA_ALIGN_SIZE
#define NXDEP_DATA_ALIGN_SIZE 0x1000
#endif


#ifndef BSP_CONFIG_ZEBU_EMU_TIMER_CLK
#endif


#ifndef BSP_CONFIG_ZEBU_EMU_TIMER_CLKFREQ
#define BSP_CONFIG_ZEBU_EMU_TIMER_CLKFREQ 1000000
#endif


#ifndef STACK_CANARY_COMPILE
#define STACK_CANARY_COMPILE
#endif


#ifndef CONFIG_NVIM
#define CONFIG_NVIM
#endif


#ifndef FEATURE_NV_SEC_ON
#define FEATURE_NV_SEC_ON
#endif


#ifndef CONFIG_DIAG_SYSTEM
#define CONFIG_DIAG_SYSTEM
#endif


#ifndef CONFIG_DIAG_CPCNFCH_SIZE
#define CONFIG_DIAG_CPCNFCH_SIZE 262144
#endif


#ifndef CONFIG_DIAG_CPLOGCH_SIZE
#define CONFIG_DIAG_CPLOGCH_SIZE 1048576
#endif


#ifndef DIAG_VERSION_ENG
#define DIAG_VERSION_ENG
#endif


#ifndef CONFIG_DIAG_MEM_L1DTCM
#define CONFIG_DIAG_MEM_L1DTCM
#endif


#ifndef ENABLE_BUILD_ODT
#define ENABLE_BUILD_ODT
#endif


#ifndef CONFIG_BBPDS
#define CONFIG_BBPDS
#endif


#ifndef CONFIG_DS_FDBG_V312
#define CONFIG_DS_FDBG_V312
#endif


#ifndef CONFIG_TRACE
#define CONFIG_TRACE
#endif


#ifndef CONFIG_DS_TRACE_V300
#define CONFIG_DS_TRACE_V300
#endif


#ifndef ENABLE_BUILD_PRINT
#define ENABLE_BUILD_PRINT
#endif


#ifndef ENABLE_BUILD_OM
#define ENABLE_BUILD_OM
#endif


#ifndef CONFIG_MODEM_MINI_DUMP
#define CONFIG_MODEM_MINI_DUMP
#endif


#ifndef CONFIG_MODEM_FULL_DUMP
#define CONFIG_MODEM_FULL_DUMP
#endif


#ifndef CONFIG_MODULE_RRT
#define CONFIG_MODULE_RRT 102
#endif


#ifndef CONFIG_RRT_BASE_ADDR
#define CONFIG_RRT_BASE_ADDR 0xF4235000
#endif


#ifndef CONFIG_BUS_ERR
#define CONFIG_BUS_ERR
#endif


#ifndef CONFIG_QIC_V2
#define CONFIG_QIC_V2
#endif


#ifndef CONFIG_PDLOCK
#define CONFIG_PDLOCK
#endif


#ifndef CONFIG_MID
#define CONFIG_MID
#endif


#ifndef ENABLE_ADMON_MDM
#define ENABLE_ADMON_MDM
#endif


#ifndef CONFIG_SCI
#define CONFIG_SCI
#endif


#ifndef MAX_SCI_NUMBER
#define MAX_SCI_NUMBER 3
#endif


#ifndef CONFIG_SIMC
#define CONFIG_SIMC
#endif


#ifndef CONFIG_SCI_DECP
#define CONFIG_SCI_DECP
#endif


#ifndef CONFIG_OCD
#define CONFIG_OCD
#endif


#ifndef CONFIG_LTRACE
#define CONFIG_LTRACE
#endif


#ifndef ENABLE_MON_TOOL
#define ENABLE_MON_TOOL
#endif


#ifndef CONFIG_SYSVIEW
#define CONFIG_SYSVIEW
#endif


#ifndef CONFIG_CCORE_WDT
#define CONFIG_CCORE_WDT
#endif


#ifndef CONFIG_WDOG_V500
#define CONFIG_WDOG_V500
#endif


#ifndef CONFIG_WDOG_NO_BYPASS
#endif


#ifndef CONFIG_GPIO_HIV500
#define CONFIG_GPIO_HIV500
#endif


#ifndef CONFIG_ONOFF
#define CONFIG_ONOFF
#endif


#ifndef CONFIG_MLOADER
#define CONFIG_MLOADER
#endif


#ifndef CONFIG_MLOADER_COLD_PATCH
#define CONFIG_MLOADER_COLD_PATCH
#endif


#ifndef CONFIG_LOAD_SEC_IMAGE
#define CONFIG_LOAD_SEC_IMAGE
#endif


#ifndef CONFIG_DFXCERT_VERIFY
#endif


#ifndef CONFIG_MLOADER_SEG_HEAD
#define CONFIG_MLOADER_SEG_HEAD
#endif


#ifndef CONFIG_TRNG_SEED
#define CONFIG_TRNG_SEED
#endif


#ifndef CONFIG_CRYPTO_KDF
#endif


#ifndef CONFIG_RTC_ON_SOC
#define CONFIG_RTC_ON_SOC
#endif


#ifndef CONFIG_ANTEN
#define CONFIG_ANTEN
#endif


#ifndef CONFIG_ANTEN_EXTRA
#define CONFIG_ANTEN_EXTRA
#endif


#ifndef CONFIG_RFILE_ON
#define CONFIG_RFILE_ON
#endif


#ifndef CONFIG_EFUSE
#define CONFIG_EFUSE
#endif


#ifndef CONFIG_MODEM_PINCTRL
#define CONFIG_MODEM_PINCTRL
#endif


#ifndef SEG_HEAD_MEM_SIZE
#define SEG_HEAD_MEM_SIZE 0x4000
#endif


#ifndef CONFIG_ADC_SOFT_LOOP
#define CONFIG_ADC_SOFT_LOOP
#endif


#ifndef CONFIG_ADC_HARD_LOOP
#define CONFIG_ADC_HARD_LOOP
#endif


#ifndef CONFIG_ADC_6421BV100
#define CONFIG_ADC_6421BV100
#endif


#ifndef CONFIG_ADC_65320100_SGL_RESISTANCE
#define CONFIG_ADC_65320100_SGL_RESISTANCE
#endif


#ifndef CONFIG_ADC_CHAN_MAX
#define CONFIG_ADC_CHAN_MAX 32
#endif


#ifndef CONFIG_NV_FUSION
#define CONFIG_NV_FUSION
#endif


#ifndef CONFIG_NV_PHONE_TYPE
#define CONFIG_NV_PHONE_TYPE
#endif


#ifndef CONFIG_MXU_MAX_ALIGN_SIZE
#define CONFIG_MXU_MAX_ALIGN_SIZE 0x4000
#endif


#ifndef CONFIG_VECBASE_ALIGN_SIZE
#define CONFIG_VECBASE_ALIGN_SIZE 0x400
#endif


#ifndef CONFIG_LPM3_CCPU_START_DTS
#define CONFIG_LPM3_CCPU_START_DTS
#endif


#ifndef CONFIG_OF
#define CONFIG_OF
#endif


#ifndef CONFIG_ENABLE_DTO
#define CONFIG_ENABLE_DTO
#endif


#ifndef CONFIG_TIMER_COMM
#define CONFIG_TIMER_COMM
#endif


#ifndef CONFIG_TIMER_LITE
#endif


#ifndef CONFIG_USE_TIMER_STAMP
#define CONFIG_USE_TIMER_STAMP
#endif


#ifndef CONFIG_MODULE_TIMER
#define CONFIG_MODULE_TIMER
#endif


#ifndef CONFIG_MODEM_TIMER
#define CONFIG_MODEM_TIMER
#endif


#ifndef CONFIG_TSP_HWLOCK
#define CONFIG_TSP_HWLOCK
#endif


#ifndef CONFIG_MODEM_EDMA
#endif


#ifndef CONFIG_HWADP
#define CONFIG_HWADP
#endif


#ifndef CONFIG_HWADP_V200
#define CONFIG_HWADP_V200
#endif


#ifndef CONFIG_SHARED_MEMORY
#define CONFIG_SHARED_MEMORY
#endif


#ifndef CONFIG_NMI
#define CONFIG_NMI
#endif


#ifndef CONFIG_MODEM_L2CACHE
#define CONFIG_MODEM_L2CACHE
#endif


#ifndef CONFIG_MEMORY_LAYOUT
#define CONFIG_MEMORY_LAYOUT
#endif


#ifndef CONFIG_MODEM_RELOC
#define CONFIG_MODEM_RELOC
#endif


#ifndef CONFIG_MODEM_ASLR
#define CONFIG_MODEM_ASLR
#endif


#ifndef CONFIG_MODEM_ASLR_DEBUG
#define CONFIG_MODEM_ASLR_DEBUG
#endif


#ifndef CONFIG_TSP_PROT_DBG
#define CONFIG_TSP_PROT_DBG
#endif


#ifndef CONFIG_SEC_SERVICE_DBG
#define CONFIG_SEC_SERVICE_DBG
#endif


#ifndef CONFIG_PFA
#endif


#ifndef CONFIG_PFA_TFT_V2
#define CONFIG_PFA_TFT_V2
#endif


#ifndef CONFIG_PFA_V200
#define CONFIG_PFA_V200
#endif


#ifndef CONFIG_L2DLE_V2
#define CONFIG_L2DLE_V2
#endif


#ifndef CONFIG_L2DLE_V210
#define CONFIG_L2DLE_V210
#endif


#ifndef CONFIG_FSTM_FDDL_V210
#define CONFIG_FSTM_FDDL_V210
#endif


#ifndef CONFIG_ECIPHER
#endif


#ifndef CONFIG_ECIPHER_TSP
#endif


#ifndef CONFIG_ULCIPHER
#define CONFIG_ULCIPHER
#endif


#ifndef CONFIG_ULCIPHER_V500
#define CONFIG_ULCIPHER_V500
#endif


#ifndef CONFIG_ULCIPHER_V310
#endif


#ifndef CONFIG_ULCIPHER_V400
#endif


#ifndef CONFIG_ULCIPHER_DBG
#define CONFIG_ULCIPHER_DBG
#endif


#ifndef CONFIG_BBP_STU
#define CONFIG_BBP_STU
#endif


#ifndef CONFIG_BBP_STU_V1
#define CONFIG_BBP_STU_V1
#endif


#ifndef CONFIG_NET_OM
#define CONFIG_NET_OM
#endif


#ifndef CONFIG_DRA
#define CONFIG_DRA
#endif


#ifndef CONFIG_DRA_V3
#define CONFIG_DRA_V3
#endif


#ifndef CONFIG_DRA_TSP
#define CONFIG_DRA_TSP
#endif


#ifndef CONFIG_DRA_FOR_PHY
#define CONFIG_DRA_FOR_PHY
#endif


#ifndef CONFIG_DRA_NORST
#define CONFIG_DRA_NORST
#endif


#ifndef CONFIG_SC_GID_CTRL
#define CONFIG_SC_GID_CTRL
#endif


#ifndef CONFIG_BTEST
#define CONFIG_BTEST
#endif


#ifndef CONFIG_VCOM
#define CONFIG_VCOM
#endif


#ifndef CONFIG_VDEV
#define CONFIG_VDEV
#endif


#ifndef CONFIG_VDEV_PHONE
#define CONFIG_VDEV_PHONE
#endif


#ifndef CONFIG_VDEV_DEBUG
#define CONFIG_VDEV_DEBUG
#endif


#ifndef CONFIG_MCI_CUST_CHN
#endif


#ifndef CONFIG_VBAT
#define CONFIG_VBAT
#endif


#ifndef CONFIG_UART_V510
#define CONFIG_UART_V510
#endif


#ifndef CONFIG_CONSOLE
#define CONFIG_CONSOLE
#endif


#ifndef CONFIG_SHELL_SYMBOL_REG
#endif


#ifndef CONFIG_MODULE_IPC_FUSION
#endif


#ifndef CONFIG_MODULE_IPCMSG
#define CONFIG_MODULE_IPCMSG
#endif


#ifndef CONFIG_FIPC_V200
#define CONFIG_FIPC_V200
#endif


#ifndef CONFIG_MODEM_MSG
#define CONFIG_MODEM_MSG
#endif


#ifndef CONFIG_SYSCTRL
#define CONFIG_SYSCTRL
#endif


#ifndef CONFIG_CPU_HARD_LOAD
#define CONFIG_CPU_HARD_LOAD
#endif


#ifndef CONFIG_CCLK
#define CONFIG_CCLK
#endif


#ifndef CONFIG_CCLK_DEBUG
#define CONFIG_CCLK_DEBUG
#endif


#ifndef CONFIG_PMCTRL_V200
#define CONFIG_PMCTRL_V200
#endif


#ifndef THERMAL_ACTION
#define THERMAL_ACTION V200
#endif


#ifndef THERMAL_HTEMP_PROTECT
#define THERMAL_HTEMP_PROTECT
#endif


#ifndef CONFIG_MODEM_RESET
#define CONFIG_MODEM_RESET
#endif


#ifndef CONFIG_PRELINK_ON
#define CONFIG_PRELINK_ON
#endif


#ifndef CONFIG_PERFSTAT
#define CONFIG_PERFSTAT FEATURE_ON
#endif


#ifndef CONFIG_CMPNT_MANAGER
#define CONFIG_CMPNT_MANAGER
#endif


#ifndef CONFIG_CMPNT_NEED_REG_SYMBOL
#define CONFIG_CMPNT_NEED_REG_SYMBOL
#endif


#ifndef MDM_SANTIZIER_MEM_SIZE
#define MDM_SANTIZIER_MEM_SIZE 0x02000000
#endif


#ifndef MDM_SANTIZIER_MEM_ADDR
#define MDM_SANTIZIER_MEM_ADDR 0xAD000000
#endif


#ifndef MDM_SANTIZIER_ADDR
#define MDM_SANTIZIER_ADDR 0xA0000000
#endif


#ifndef MDM_SANTIZIER_SIZE
#define MDM_SANTIZIER_SIZE 0xD000000
#endif


#ifndef MODEM_SANITIZER_ADDR_OFFSET
#define MODEM_SANITIZER_ADDR_OFFSET 0x99000000
#endif


#ifndef MMU_TABLE_SIZE
#define MMU_TABLE_SIZE 0x0
#endif


#ifndef SYS_STACK_SIZE
#define SYS_STACK_SIZE 0x4000
#endif


#ifndef MEM_LAYOUT_RTT
#endif


#ifndef CONFIG_MPERF_PMU
#define CONFIG_MPERF_PMU
#endif


#ifndef CONFIG_SPPM
#define CONFIG_SPPM
#endif


#ifndef CONFIG_CSHELL
#define CONFIG_CSHELL
#endif


#ifndef DDR_MDM_TEE_ADDR
#define DDR_MDM_TEE_ADDR 0xACF00000
#endif


#ifndef DDR_MDM_TEE_SIZE
#define DDR_MDM_TEE_SIZE 0x00100000
#endif


#ifndef DDR_MDM_SANTIZIER_TEE_SIZE
#define DDR_MDM_SANTIZIER_TEE_SIZE 0x00800000
#endif


#ifndef DDR_MDM_SANTIZIER_TEE_ADDR
#define DDR_MDM_SANTIZIER_TEE_ADDR 0x95000000
#endif


#ifndef DDR_MDM_TEE_ADDR_OFFSET
#define DDR_MDM_TEE_ADDR_OFFSET 0x9C600000
#endif


#ifndef CONFIG_TSP_MPU_TYPE
#define CONFIG_TSP_MPU_TYPE
#endif


#ifndef CONFIG_MPU_ATTR_DEF_DEBUG
#define CONFIG_MPU_ATTR_DEF_DEBUG
#endif


#ifndef NVC_FILE_SIZE
#define NVC_FILE_SIZE 0x1000
#endif


#ifndef CONFIG_TSP_SUPPORT_MTEE_MODE
#define CONFIG_TSP_SUPPORT_MTEE_MODE
#endif


#ifndef TSP_DDR_CACHE_SPINLOCK_SIZE
#define TSP_DDR_CACHE_SPINLOCK_SIZE 0x4000
#endif


#ifndef ODT_RTT
#endif


#ifndef CONFIG_AVS_YIELD
#define CONFIG_AVS_YIELD V200
#endif


#ifndef CONFIG_AVS_FORMULA_MODE
#define CONFIG_AVS_FORMULA_MODE V100
#endif


#ifndef CONFIG_AVS_PERCHIP_UPDATE
#define CONFIG_AVS_PERCHIP_UPDATE
#endif


#ifndef CONFIG_AVS_CHR_VERSION
#define CONFIG_AVS_CHR_VERSION V100
#endif


#ifndef CONFIG_AVS_MITIGATION_MODE
#define CONFIG_AVS_MITIGATION_MODE
#endif


#ifndef CONFIG_AVS_TEST
#endif


#ifndef MEM_LAYOUT_TYPE
#define MEM_LAYOUT_TYPE 0
#endif


#ifndef CONFIG_MODEM_AGING
#endif


#ifndef CONFIG_HEATING_CALIBRATION
#define CONFIG_HEATING_CALIBRATION
#endif


#ifndef CONFIG_XSTAR_GNSS
#define CONFIG_XSTAR_GNSS
#endif


#ifndef CONFIG_SENSORHUB_RST
#define CONFIG_SENSORHUB_RST
#endif


#ifndef CONFIG_XSTAR_QUATERNION
#define CONFIG_XSTAR_QUATERNION
#endif


#ifndef CONFIG_FAC_REPORT
#define CONFIG_FAC_REPORT
#endif

#endif /* __PRODUCT_CONFIG_H__ */
