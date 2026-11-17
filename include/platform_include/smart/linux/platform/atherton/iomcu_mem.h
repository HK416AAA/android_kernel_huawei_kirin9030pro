/* Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved. 
   extract macros used in imocu from the global_ddr_map and iomcu_ddr_map header files
*/
#ifndef __IOMCU_MEM_H__
#define __IOMCU_MEM_H__
#ifdef CONFIG_HEADER_FILE_REPLACE_EXTRACT

#define SOC_IOMCU_M7_MID                                0x1
#if defined(CONFIG_PRODUCT_GLASSES)
#define RESERVED_SENSORHUB_NPU_PHYMEM_BASE              0x11B80000
#define RESERVED_SENSORHUB_NPU_PHYMEM_SIZE              0x2800000

#define RESERVED_SENSORHUB_DSS_PHYMEM_BASE              0x14380000
#define RESERVED_SENSORHUB_DSS_PHYMEM_SIZE              0x280000

#define RESERVED_SENSORHUB_NSEC_WORK_PHYMEM_BASE        0x14600000
#define RESERVED_SENSORHUB_NSEC_WORK_PHYMEM_SIZE        0x830000

#define RESERVED_SENSORHUB_SEC_WORK_PHYMEM_BASE         0x15A30000
#define RESERVED_SENSORHUB_SEC_WORK_PHYMEM_SIZE         0x25D0000

#else
#define RESERVED_SENSORHUB_NPU_PHYMEM_BASE              0x11B80000
#define RESERVED_SENSORHUB_NPU_PHYMEM_SIZE              0x800000

#define RESERVED_SENSORHUB_DSS_PHYMEM_BASE              0x12380000
#define RESERVED_SENSORHUB_DSS_PHYMEM_SIZE              0x280000

#define RESERVED_SENSORHUB_NSEC_WORK_PHYMEM_BASE        0x12600000
#define RESERVED_SENSORHUB_NSEC_WORK_PHYMEM_SIZE        0x830000
 
#define RESERVED_SENSORHUB_SEC_WORK_PHYMEM_BASE         0x13A30000
#define RESERVED_SENSORHUB_SEC_WORK_PHYMEM_SIZE         0x45D0000
#endif

#define RESERVED_NPU_TINY_PHYMEM_BASE  RESERVED_SENSORHUB_NPU_PHYMEM_BASE
#define RESERVED_NPU_TINY_PHYMEM_SIZE  RESERVED_SENSORHUB_NPU_PHYMEM_SIZE
#define DDR_RESERVE_ADDR_AP            RESERVED_SENSORHUB_IMAGE_PHYMEM_BASE
#define DDR_RESERVE_SIZE               RESERVED_SENSORHUB_IMAGE_PHYMEM_SIZE

/* DEFINITIONS */
#define SENSORHUB_DDR_WINDOW_SIZE            (0x10000000)

/*========================================================================
              SENSORHUB_NSEC 7.1875M None Secure
==========================================================================*/
/*    |------------Total 7.1875M---------|
      |-----128K-----|-----nve-------|
      |-----64K-----|---dpu cmdlist--|
      |-----0.5M-----|---ipc shmem---|
      |-----0.5M-----|-----LOG-------|
      |-----1.0M-----|-----DUMP------|
      |-----5.0M-----|----reserved---|
*/
#define DDR_SHMEMEXT_ADDR_AP                RESERVED_SENSORHUB_NSEC_WORK_PHYMEM_BASE
#define DDR_SHMEMEXT_SIZE                   RESERVED_SENSORHUB_NSEC_WORK_PHYMEM_SIZE
#define DDR_SHMEMEXT_ADDR_END               DDR_SHMEMEXT_ADDR_AP + DDR_SHMEMEXT_SIZE

/* nve share 128k */
#define DDR_NVE_SHMEM_BASE_AP               RESERVED_SENSORHUB_NSEC_WORK_PHYMEM_BASE
#define DDR_NVE_SHMEM_BASE_SIZE             0x20000
#define DDR_NVE_SHMEM_END_AP               (DDR_NVE_SHMEM_BASE_AP + DDR_NVE_SHMEM_BASE_SIZE)

/*========================================================================
                        DPU CMDLIST 64K
==========================================================================*/
#define DDR_DPU_CMDLIST_BASE_AP             DDR_NVE_SHMEM_END_AP
#define DDR_DPU_CMDLIST_SIZE                0x10000
#define DDR_DPU_CMDLIST_END_AP             (DDR_DPU_CMDLIST_BASE_AP + DDR_DPU_CMDLIST_SIZE)

/*========================================================================
                  SENSORHUB SHMEM1 FOR IPC 512K
==========================================================================*/
#define DDR_SHMEM1_ADDR_AP                  DDR_DPU_CMDLIST_END_AP
#define DDR_SHMEM1_SIZE                     0x80000
#define DDR_SHMEM1_END_AP                  (DDR_SHMEM1_ADDR_AP + DDR_SHMEM1_SIZE)
/*    |-----Total 512K-----|
      |-----008K-----|---DTS cfg----|
      |-----007K-----|---thermal----|
      |-----004K-----|---loadmonitor|
      |-----493K-----|---largeblk---|
*/
 
/* IOMCU DTS CONFIG */
#define DDR_DTS_CONFIG_ADDR_AP              DDR_SHMEM1_ADDR_AP
#define DDR_DTS_CONFIG_SIZE                 0x2000
 
/*THERMAL*/
#define DDR_THERMAL_SHMEM_PHYMEM_BASE_AP   (DDR_DTS_CONFIG_ADDR_AP + DDR_DTS_CONFIG_SIZE)
#define DDR_THERMAL_SHMEM_PHYMEM_SIZE       0x1C00
 
/*loadmonitor*/
#define DDR_LOADMONITOR_PHYMEM_BASE_AP     (DDR_THERMAL_SHMEM_PHYMEM_BASE_AP + DDR_THERMAL_SHMEM_PHYMEM_SIZE)
#define DDR_LOADMONITOR_PHYMEM_SIZE         0x1000
 
/*large blk share*/
#define DDR_SHMEM_LARGE_BLK_BASE_AP        (DDR_LOADMONITOR_PHYMEM_BASE_AP + DDR_LOADMONITOR_PHYMEM_SIZE)
#define DDR_SHMEM_LARGE_BLK_SIZE           (DDR_SHMEM1_END_AP - DDR_SHMEM_LARGE_BLK_BASE_AP)
 
#define DDR_SHMEM_CH_SEND_ADDR_AP           DDR_SHMEM_LARGE_BLK_BASE_AP
#define DDR_SHMEM_CH_SEND_SIZE             (DDR_SHMEM_LARGE_BLK_SIZE / 2)
#define DDR_SHMEM_AP_SEND_ADDR_AP          (DDR_SHMEM_CH_SEND_ADDR_AP + DDR_SHMEM_CH_SEND_SIZE)
#define DDR_SHMEM_AP_SEND_SIZE             (DDR_SHMEM_LARGE_BLK_SIZE / 2)

/*========================================================================
                   SENSORHUB SHMEM FOR LOG BUFFER 512K
==========================================================================*/
#define DDR_SHMEM_ADDR_AP                   DDR_SHMEM1_END_AP
#define DDR_SHMEM_SIZE                      0x80000
#define DDR_SHMEM_END_AP                   (DDR_SHMEM_ADDR_AP + DDR_SHMEM_SIZE)
/*    |-----Total 512K-----
      |-----004K-----|---reserved---|
      |-----004K-----|---shell dgb--|
      |-----004K-----|---ddr cfg----|
      |-----500K-----|---log buff---|
*/

/* DDR CONFIG */
#define DDR_CONFIG_SIZE                     0x1000
#define DDR_CONFIG_ADDR_AP                  DDR_SHMEM_ADDR_AP
#define DDR_CONFIG_AP_END                  (DDR_CONFIG_ADDR_AP + DDR_CONFIG_SIZE)

/* SHELL_DBG */
#define DDR_SHELL_DBG_SIZE                  0x1000
#define DDR_SHELL_DBG_ADDR_AP               DDR_CONFIG_AP_END
#define DDR_SHELL_DBG_END_AP               (DDR_SHELL_DBG_ADDR_AP + DDR_SHELL_DBG_SIZE)

/* reserved */
#define DDR_IOMCU_RESERVED_SIZE             0x1000
#define DDR_IOMCU_RESERVED_ADDR_AP          DDR_SHELL_DBG_END_AP
#define DDR_IOMCU_RESERVED_END_AP          (DDR_IOMCU_RESERVED_ADDR_AP + DDR_IOMCU_RESERVED_SIZE)

/* LOG BUFFER */
#define DDR_LOG_BUFF_SIZE                   0x7D000
#define DDR_LOG_BUFF_ADDR_AP                DDR_IOMCU_RESERVED_END_AP

/* for load_iomcu_v2.c */
#define RESERVED_SENSORHUB_SHARE_MEM_PHYMEM_BASE DDR_SHMEM_ADDR_AP
#define RESERVED_SENSORHUB_SHARE_MEM_PHYMEM_SIZE DDR_SHMEM_SIZE

#define DDR_DUMP_BASE_AP                   DDR_SHMEM_END_AP
#define DDR_DUMP_SIZE                      0x100000
#define DDR_DUMP_END_AP                   (DDR_DUMP_BASE_AP + DDR_DUMP_SIZE)

/*========================================================================
                    SENSORHUB RESERVED 6M
==========================================================================*/
#define DDR_NSEC_FOR_WATCH_BASE_AP         DDR_DUMP_END_AP
#define DDR_NSEC_FOR_WATCH_SIZE            0x600000
#define DDR_NSEC_FOR_WATCH_END_AP         (DDR_FOR_WATCH_BASE_AP + DDR_FOR_WATCH_SIZE)

/*========================================================================
      SENSORHUB DDR SEC   0x13A30000 ~ 0x18000000 Secure
==========================================================================*/
#define DDR_SEC_ADDR_AP                    RESERVED_SENSORHUB_SEC_WORK_PHYMEM_BASE
#define DDR_SEC_SIZE                       RESERVED_SENSORHUB_SEC_WORK_PHYMEM_SIZE
/*    |-----Total 69.38125M-----|
      |-----16M------|---ddr code---|  //cacheable,rwe
      |-----8K--|-f2l/str/fp/sc cfg-|  //non-cacheable,rw
      |-----952K-----|---ddr heap---|  //cacheable,rw
      |-----64K------|---ipc shmem--|  //rw
      |-----50M------|---reserved---|  //rw
*/
#define DDR_CODE_BASE_AP                   DDR_SEC_ADDR_AP
#if defined(CONFIG_PRODUCT_WATCH_LITE)
#define DDR_CODE_SIZE                      0x580000
#elif defined(CONFIG_PRODUCT_GLASSES)
#define DDR_CODE_SIZE                      0x1000000
#else
#define DDR_CODE_SIZE                      0x1200000
#endif
#define DDR_CODE_END_AP                    (DDR_CODE_BASE_AP + DDR_CODE_SIZE)

/* ---8K----|--f2l/str/fp/sc cfg--- */   // non-cacheable,rw
#define DDR_SEC_SHARE_CONFIG_ADDR_AP       DDR_CODE_END_AP
#define DDR_SEC_SHARE_CONFIG_END_SIZE      0x2000
#define DDR_SEC_SHARE_CONFIG_END_AP        (DDR_SEC_SHARE_CONFIG_ADDR_AP + DDR_SEC_SHARE_CONFIG_END_SIZE)

#define DDR_F2L_CONFIG_ADDR_AP             DDR_SEC_SHARE_CONFIG_ADDR_AP
#define DDR_F2L_CONFIG_SIZE                0xFB0
#define DDR_F2L_END_AP                     (DDR_F2L_CONFIG_ADDR_AP + DDR_F2L_CONFIG_SIZE)

#define DDR_FP_IMAGE_BASE_AP               DDR_F2L_END_AP
#define DDR_FP_IMAGE_SIZE                  0
#define DDR_FP_IMAGE_END_AP                (DDR_FP_IMAGE_BASE_AP + DDR_FP_IMAGE_SIZE)

#define DDR_F2L_CONFIG_BOARDID             DDR_FP_IMAGE_END_AP
#define DDR_F2L_BOARDID_SIZE               0x20
#define DDR_F2L_END_BOARDID                (DDR_F2L_CONFIG_BOARDID + DDR_F2L_BOARDID_SIZE)

/* iomcu str status infos  */
#define DDR_IOMCU_STR_STATUS_INFO_BASE     DDR_F2L_END_BOARDID
#define DDR_IOMCU_STR_STATUS_INFO_SIZE     0x10
#define DDR_IOMCU_STR_STATUS_INFO_END      (DDR_IOMCU_STR_STATUS_INFO_BASE + DDR_IOMCU_STR_STATUS_INFO_SIZE)

/* soc/iomcu reboot infos  */
#define DDR_IOMCU_REBOOT_INFO_BASE         DDR_IOMCU_STR_STATUS_INFO_END
#define DDR_IOMCU_REBOOT_INFO_SIZE         0x10
#define DDR_IOMCU_REBOOT_INFO_END          (DDR_IOMCU_REBOOT_INFO_BASE + DDR_IOMCU_REBOOT_INFO_SIZE)

/* IOMCU syscache software state record 4K */
#define DDR_SYSCACHE_STAT_BASE             DDR_IOMCU_REBOOT_INFO_END
#define DDR_SYSCACHE_STAT_SIZE             0x1000
#define DDR_SYSCACHE_STAT_END              (DDR_CONFIG_ADDR_AP + DDR_SEC_SHARE_CONFIG_END_SIZE - DDR_IOMCU_REBOOT_INFO_END)

/* -----952K-----|---ddr heap--- */  // cacheable,rw
#define DDR_HEAP_START_AP                  DDR_SEC_SHARE_CONFIG_END_AP
#define DDR_HEAP_SIZE                      0xEE000
#define DDR_HEAP_END_AP                    (DDR_HEAP_START_AP + DDR_HEAP_SIZE)

/* ipc share memory for teeos */
#define DDR_IPC_SHMEM_CH_TEE_BASE_AP       DDR_HEAP_END_AP
#define DDR_IPC_SHMEM_CH_TEE_SIZE          0x10000
#define DDR_IPC_SHMEM_CH_TEE_END_AP        (DDR_IPC_SHMEM_CH_TEE_BASE_AP + DDR_IPC_SHMEM_CH_TEE_SIZE)

#define DDR_IPC_SHMEM_CH_SEND_TEE_ADDR_AP  DDR_IPC_SHMEM_CH_TEE_BASE_AP
#define DDR_IPC_SHMEM_CH_SEND_TEE_SIZE     0xB000
#define DDR_IPC_SHMEM_TEE_SEND_CH_ADDR_AP  (DDR_IPC_SHMEM_CH_SEND_TEE_ADDR_AP + DDR_IPC_SHMEM_CH_SEND_TEE_SIZE)
#define DDR_IPC_SHMEM_TEE_SEND_CH_SIZE     0x5000

#define DDR_SEC_FOR_WATCH_BASE_AP          DDR_IPC_SHMEM_CH_TEE_END_AP
#define DDR_SEC_FOR_WATCH_SIZE             (DDR_SEC_ADDR_AP + DDR_SEC_SIZE - DDR_SEC_FOR_WATCH_BASE_AP)
#define DDR_SEC_FOR_WATCH_END_AP           (DDR_SEC_FOR_WATCH_BASE_AP + DDR_SEC_FOR_WATCH_SIZE)

#define IOMCU_SYNC_BUFFER_VADDR            DDR_SEC_FOR_WATCH_END_AP
#ifdef CONFIG_SYNCBUFFER_CUSTOMIZED
#define IOMCU_SYNC_BUFFER_PADDR            0xC0000000
#define IOMCU_SYNC_BUFFER_SIZE             0x180000
#else
#define IOMCU_SYNC_BUFFER_PADDR            0xC0180000
#define IOMCU_SYNC_BUFFER_SIZE             0x280000
#endif

/*========================================================================
      SENSORHUB_IMAGE 20M Secure
==========================================================================*/
#define DDR_IMAGE_SIZE                     0x1400000
#define DDR_IMAGE_BASE_AP                  (DDR_SEC_FOR_WATCH_END_AP - DDR_IMAGE_SIZE)
#define DDR_IMAGE_END_AP                   (DDR_IMAGE_BASE_AP + DDR_IMAGE_SIZE)

#define RESERVED_SENSORHUB_PHYMEM_BASE     DDR_IMAGE_BASE_AP
#define RESERVED_SENSORHUB_PHYMEM_SIZE     DDR_IMAGE_SIZE

/* for TEE load image */
#define DDR_F2L_IN_IMAGE_AREA_SIZE         0

/* for bl31 memory map */
#define CUSTOM_SENSORHUB_IMAGE_BASE        RESERVED_SENSORHUB_SEC_WORK_PHYMEM_BASE
#define CUSTOM_SENSORHUB_IMAGE_SIZE        RESERVED_SENSORHUB_SEC_WORK_PHYMEM_SIZE

#define DDR_RESERVED_USED_END              DDR_SEC_FOR_WATCH_END_AP
#if DDR_RESERVED_USED_END > (DDR_SEC_ADDR_AP + DDR_SEC_SIZE)
	#error "DDR_RESERVED_USED overflow"
#endif

/*========================================================================
      NPU_TINY DDR RESERVED  0x12800000 ~ 0x13000000
==========================================================================*/
/*    |-----Total 8M-----|
      |-----8.0M-----|---reserve----|
*/
#define DDR_TINY_RESERVE_ADDR_AP            RESERVED_NPU_TINY_PHYMEM_BASE
#define DDR_TINY_RESERVE_SIZE               RESERVED_NPU_TINY_PHYMEM_SIZE

/*========================================================================
      OTHER DEFINITION
==========================================================================*/
/* 0k */
#define DDR_AOD_BASE_AP                    (0x0)
#define DDR_AOD_SIZE                       (0x0)
#define DDR_AOD_END_AP                     (DDR_AOD_BASE_AP + DDR_AOD_SIZE)

#endif
#endif