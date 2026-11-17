/* Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved. 
   extract macros used in imocu from the global_ddr_map and iomcu_ddr_map header files
*/

#ifndef __IOMCU_MEM_H__
#define __IOMCU_MEM_H__

#define IOM3_DDR_BANDWIDTH 30595

#ifdef CONFIG_HEADER_FILE_REPLACE_EXTRACT

#define RESERVED_SENSORHUB_SHMEMEXT_PHYMEM_BASE        0x10000000
#define RESERVED_SENSORHUB_SHMEMEXT_PHYMEM_SIZE        (0x300000)

#define RESERVED_SENSORHUB_SHMEM_PHYMEM_BASE           0x10300000
#define RESERVED_SENSORHUB_SHMEM_PHYMEM_SIZE           (0x40000)

#define RESERVED_SENSORHUB_SHARE_MEM_PHYMEM_BASE       0x10340000
#define RESERVED_SENSORHUB_SHARE_MEM_PHYMEM_SIZE       (0x380000)

#define RESERVED_NPU_TINY_PHYMEM_BASE                  0x18280000
#define RESERVED_NPU_TINY_PHYMEM_SIZE                  (0x800000)

#define RESERVED_SENSORHUB_SDC_BASE                    0x18A80000
#define RESERVED_SENSORHUB_SDC_SIZE                    (0x100000)

#define RESERVED_SENSORHUB_PHYMEM_BASE                 0x18B80000
#define RESERVED_SENSORHUB_PHYMEM_SIZE                 (0xCF0000)


#define DDR_SHMEMEXT_ADDR_AP                RESERVED_SENSORHUB_SHMEMEXT_PHYMEM_BASE
#define DDR_SHMEMEXT_SIZE                   RESERVED_SENSORHUB_SHMEMEXT_PHYMEM_SIZE

/*========================================================================
      SENSORHUB SHMEMEXT None Secure 0x10000000 ~ 0x10300000 = 3M rw non-cache
==========================================================================*/
/*    |-----Total 3M-----
      |-----1.5M-----|---FLP-------------|
      |-----1.0M-----|---dump------------|
      |-----128K-----|---JPEGD LB BUFFER-|
      |-----64K------|---DPU CMDLIST-----|
      |-----320K-----|---IGS SCAN CODE-----|
*/
#define DDR_SHMEMEXT_ADDR_AP                RESERVED_SENSORHUB_SHMEMEXT_PHYMEM_BASE
#define DDR_SHMEMEXT_SIZE                   RESERVED_SENSORHUB_SHMEMEXT_PHYMEM_SIZE

/* 1.5M FLP */
#define DDR_FLP_BASE_AP                   DDR_SHMEMEXT_ADDR_AP
#define DDR_FLP_SIZE                      (0x180000)
#define DDR_FLP_END_AP                    (DDR_SHMEMEXT_ADDR_AP + DDR_FLP_SIZE)
#define OFFLINE_CELL_MMAP_SIZE            (0x180000)

/* 1M DUMP */
#define DDR_DUMP_BASE_AP                   DDR_FLP_END_AP
#define DDR_DUMP_SIZE                      (0x88C00)
#define DDR_DUMP_END_AP                    (DDR_DUMP_BASE_AP + DDR_DUMP_SIZE)

/* 1K NEARLINK persist storage */
#define DDR_NL_BASE_AP                     DDR_DUMP_END_AP
#define DDR_NL_SIZE                        (0x400)
#define DDR_NL_END_AP                      (DDR_NL_BASE_AP + DDR_NL_SIZE)

/* 140K Push AOD */
#define DDR_PUSH_AOD_START_AP              DDR_NL_END_AP
#define DDR_PUSH_AOD_SIZE                  (0x23000)
#define DDR_PUSH_AOD_END_AP                (DDR_PUSH_AOD_START_AP + DDR_PUSH_AOD_SIZE)

/* 40k MAP OFFLOAD GNSS BUFFER */
#define DDR_MAP_BUFFER_BASE_AP             DDR_PUSH_AOD_END_AP
#define DDR_MAP_BUFFER_SIZE                (0xA000)
#define DDR_MAP_BUFFER_END_AP              (DDR_MAP_BUFFER_BASE_AP + DDR_MAP_BUFFER_SIZE)

/* 4k DFA used */
#define DDR_DFA_BASE_AP                   DDR_MAP_BUFFER_END_AP
#define DDR_DFA_SIZE                      (0x1000)
#define DDR_DFA_END_AP                    (DDR_DFA_BASE_AP + DDR_DFA_SIZE)

/* LPP LOG BUFFER 256K */
#define DDR_LPP_LOG_BUFF_BASE_AP           DDR_DFA_END_AP
#define DDR_LPP_LOG_BUFF_SIZE              (0x40000)
#define DDR_LPP_LOG_BUFF_END_AP            (DDR_LPP_LOG_BUFF_BASE_AP + DDR_LPP_LOG_BUFF_SIZE)

/* 36k LPP half_offload rs buffer */
#define DDR_LPP_RS_RB_BASE_AP               DDR_LPP_LOG_BUFF_END_AP
#define DDR_LPP_RS_RB_SIZE                  (0x9000)
#define DDR_LPP_RS_END_AP                   (DDR_LPP_RS_RB_BASE_AP + DDR_LPP_RS_RB_SIZE)

/* 128K LPP half_offload vdec RB BUFFER */
#define DDR_VDEC2SHB_RB_BASE_AP            DDR_LPP_RS_END_AP
#define DDR_LPP_RB_SIZE                    (0x10000)
#define DDR_SHB2VDEC_RB_BASE_AP            (DDR_VDEC2SHB_RB_BASE_AP + DDR_LPP_RB_SIZE)
#define DDR_LPP_RB_END_AP                  (DDR_SHB2VDEC_RB_BASE_AP + DDR_LPP_RB_SIZE)

/* 64K DPU CMDLIST */
#define DDR_DPU_CMDLIST_BASE_AP            DDR_LPP_RB_END_AP
#define DDR_DPU_CMDLIST_SIZE               (0x10000)
#define DDR_DPU_CMDLIST_END_AP             (DDR_DPU_CMDLIST_BASE_AP + DDR_DPU_CMDLIST_SIZE)

/* 312K IGS SCAN CODE BUFFER */
#define DDR_IGS_SCAN_CODE_BASE_AP            DDR_DPU_CMDLIST_END_AP
#define DDR_IGS_SCAN_CODE_SIZE               (0x4E000)
#define DDR_IGS_SCAN_CODE_END_AP             (DDR_IGS_SCAN_CODE_BASE_AP + DDR_IGS_SCAN_CODE_SIZE)

/* 8K IGS SCREEN UNDERSTAND OCR INFO BUFFER */
#define DDR_IGS_SCRUD_BASE_AP                DDR_IGS_SCAN_CODE_END_AP
#define DDR_IGS_SCRUD_SIZE                   (0x2000)
#define DDR_IGS_SCRUD_END_AP                 (DDR_IGS_SCRUD_BASE_AP + DDR_IGS_SCRUD_SIZE)
/*========================================================================
      SENSORHUB SHMEM1 FOR IPC 0x10300000 ~ 0x10340000 = 256K rw non-cache
==========================================================================*/
#define DDR_SHMEM1_ADDR_AP                  RESERVED_SENSORHUB_SHMEM_PHYMEM_BASE
#define DDR_SHMEM1_SIZE                     RESERVED_SENSORHUB_SHMEM_PHYMEM_SIZE

/*    |-----Total 256K-----|
      |-----020K-----|---DTS cfg----|
      |-----007K-----|---thermal----|
      |-----004K-----|---loadmonitor|
      |-----225K-----|---largeblk---|
*/

/* IOMCU DTS CONFIG */
#define DDR_DTS_CONFIG_ADDR_AP              DDR_SHMEM1_ADDR_AP
#define DDR_DTS_CONFIG_SIZE                 (0x5000)

/*THERMAL*/
#define DDR_THERMAL_SHMEM_PHYMEM_BASE_AP    (DDR_DTS_CONFIG_ADDR_AP + DDR_DTS_CONFIG_SIZE)
#define DDR_THERMAL_SHMEM_PHYMEM_SIZE       (0x1C00)

/*loadmonitor*/
#define DDR_LOADMONITOR_PHYMEM_BASE_AP      (DDR_THERMAL_SHMEM_PHYMEM_BASE_AP + DDR_THERMAL_SHMEM_PHYMEM_SIZE)
#define DDR_LOADMONITOR_PHYMEM_SIZE         (0x1000)

/*large blk share*/
#define DDR_SHMEM_LARGE_BLK_BASE_AP         (DDR_LOADMONITOR_PHYMEM_BASE_AP + DDR_LOADMONITOR_PHYMEM_SIZE)
#define DDR_SHMEM_LARGE_BLK_SIZE            (DDR_SHMEM1_ADDR_AP + DDR_SHMEM1_SIZE - DDR_SHMEM_LARGE_BLK_BASE_AP)

#define DDR_SHMEM_CH_SEND_ADDR_AP           DDR_SHMEM_LARGE_BLK_BASE_AP
#define DDR_SHMEM_CH_SEND_SIZE              (DDR_SHMEM_LARGE_BLK_SIZE - DDR_IPCNS_SHM_RX_SIZE)
#define DDR_SHMEM_AP_SEND_ADDR_AP           (DDR_SHMEM_CH_SEND_ADDR_AP + DDR_SHMEM_CH_SEND_SIZE)
#define DDR_SHMEM_AP_SEND_SIZE              (DDR_IPCNS_SHM_RX_SIZE)

/*========================================================================
      SENSORHUB SHMEM FOR LOG BUFFER  0x10340000 ~ 0x103C0000 = 512K rw non-cache
==========================================================================*/
#define DDR_SHMEM_ADDR_AP                   RESERVED_SENSORHUB_SHARE_MEM_PHYMEM_BASE
#define DDR_SHMEM_SIZE                      RESERVED_SENSORHUB_SHARE_MEM_PHYMEM_SIZE

/*    |-----Total 512K-----
      |-----004K-----|---reserved---|
      |-----004K-----|---shell dgb--|
      |-----004K-----|---ddr cfg----|
      |-----500K-----|---log buff---|
      |-----3M----  -|---aod buff---|
*/
#define DDR_SHMEM_END_AP                   (DDR_SHMEM_ADDR_AP + DDR_SHMEM_SIZE)

/* reserved */
#define DDR_IOMCU_RESERVED_ADDR_AP         (DDR_SHMEM_ADDR_AP)
#define DDR_IOMCU_RESERVED_SIZE            (0x1000)

/* SHELL_DBG */
#define DDR_SHELL_DBG_ADDR_AP              (DDR_IOMCU_RESERVED_ADDR_AP + DDR_IOMCU_RESERVED_SIZE)
#define DDR_SHELL_DBG_SIZE                 (0x1000)

/* DDR CONFIG */
#define DDR_CONFIG_ADDR_AP                 (DDR_SHELL_DBG_ADDR_AP + DDR_SHELL_DBG_SIZE)
#define DDR_CONFIG_SIZE                    (0x1000)

/* LOG BUFFER */
#define DDR_LOG_BUFF_ADDR_AP               (DDR_CONFIG_ADDR_AP + DDR_CONFIG_SIZE)
#define DDR_LOG_BUFF_SIZE                  (0x7D000)

/* AOD BUFFER */
#define DDR_AOD_BASE_AP                    (DDR_LOG_BUFF_ADDR_AP + DDR_LOG_BUFF_SIZE)
#define DDR_AOD_SIZE                       (0x300000)

/*========================================================================
      SENSORHUB DDR RESERVED   0x12900000 ~ 0x13600000  13M Secure
==========================================================================*/
#define DDR_RESERVE_ADDR_AP                 RESERVED_SENSORHUB_PHYMEM_BASE
#define DDR_RESERVE_SIZE                    RESERVED_SENSORHUB_PHYMEM_SIZE

/*    |-----Total 13M-----|
      |----6M-8K-----|---image---------|  //r, non-cache
      |-----8K-------|f2l+rand data+rsv|  //r, non-cache: f2l(4K-4byte) + random data(4byte) + reserved(4K)
      |-----4.0M-----|---ddr code------|  //cacheable: (ddr data:rw cache)+(ddr code:re cache)
      |---2.5M-437K--|---ddr heap------|  //cacheable,rw cache
      |-----308K-----|---push heap-----|  //rw, non-cache
      |-----128K-----|---ipc shmem-----|  //rw, non-cache
      |-----0.5M-----|---fp image------|  //rw, non-cache
      |-----1K-------|---io die--------|  //rw, non-cache

*/
#define DDR_IMAGE_BASE_AP                  (DDR_RESERVE_ADDR_AP + 0x5DF000)
#define DDR_IMAGE_SIZE                     (0x5FE000)
#define DDR_IMAGE_END_AP                   (DDR_IMAGE_BASE_AP + DDR_IMAGE_SIZE)

#define DDR_CODE_BASE_AP                   DDR_RESERVE_ADDR_AP
#define DDR_CODE_SIZE                      (0x400000)
#define DDR_CODE_END_AP                    (DDR_CODE_BASE_AP + DDR_CODE_SIZE)

#define DDR_HEAP_START_AP                  DDR_CODE_END_AP
#define DDR_HEAP_SIZE                      (0x5DD000)
#define DDR_HEAP_END_AP                    (DDR_HEAP_START_AP + DDR_HEAP_SIZE)

#define DDR_ONCE_LOADER_BASE_AP           (DDR_HEAP_END_AP)
#define DDR_ONCE_LOADER_SIZE              (0x200000)
#define DDR_ONCE_LOADER_END_AP             (DDR_ONCE_LOADER_BASE_AP + DDR_ONCE_LOADER_SIZE)

/* IOMCU FASTBOOT_TO_LPM3 CONFIG, keep same with fastboot & lpm3 */
#define DDR_F2L_CONFIG_ADDR_AP             DDR_ONCE_LOADER_END_AP
#define DDR_F2L_CONFIG_SIZE                (0xFFC)
#define DDR_F2L_CONFIG_END_AP              (DDR_F2L_CONFIG_ADDR_AP + DDR_F2L_CONFIG_SIZE)

#define DDR_LAST_LOGBUFF_ADDR_AP           (DDR_F2L_CONFIG_ADDR_AP + 0x800)
#define DDR_LAST_LOGBUFF_SIZE              (0x2000)

#define DDR_F2L_RANDOM_DATA_AP             DDR_F2L_CONFIG_END_AP
#define DDR_F2L_RANDOM_DATA_SIZE           (0x4)
#define DDR_F2L_RANDOM_DATA_END_AP         (DDR_F2L_RANDOM_DATA_AP + DDR_F2L_RANDOM_DATA_SIZE)

#define DDR_RESERVED_8K_SIZE               (0x2000)
#define DDR_RESERVED_END_AP                (DDR_F2L_RANDOM_DATA_END_AP + DDR_RESERVED_8K_SIZE)

#define DDR_IPCNS_SHM_RX_START_AP          DDR_RESERVED_END_AP
#define DDR_IPCNS_SHM_RX_SIZE              (0x11C00)
#define DDR_IPCNS_SHM_RX_END_AP            (DDR_IPCNS_SHM_RX_START_AP + DDR_IPCNS_SHM_RX_SIZE)

#define DDR_IOMCU_IO_DIE_CFG_BASE_AP       DDR_IPCNS_SHM_RX_END_AP
#define DDR_IOMCU_IO_DIE_CFG_SIZE          (0x1000)
#define DDR_IOMCU_IO_DIE_CFG_END_AP        (DDR_IOMCU_IO_DIE_CFG_BASE_AP + DDR_IOMCU_IO_DIE_CFG_SIZE)

#define DDR_PUSH_START_AP                  DDR_IOMCU_IO_DIE_CFG_END_AP
#define DDR_PUSH_SIZE                      (0x40000)
#define DDR_PUSH_END_AP                    (DDR_PUSH_START_AP + DDR_PUSH_SIZE)

#define DDR_DMA_START_AP                  DDR_PUSH_END_AP
#define DDR_DMA_SIZE                      (0xD000)
#define DDR_DMA_END_AP                    (DDR_DMA_START_AP + DDR_DMA_SIZE)

/* ipc share memory for teeos */
#define DDR_IPC_SHMEM_CH_TEE_BASE_AP       DDR_DMA_END_AP
#define DDR_IPC_SHMEM_CH_TEE_SIZE          (0x20000)
#define DDR_IPC_SHMEM_CH_TEE_END_AP        (DDR_IPC_SHMEM_CH_TEE_BASE_AP + DDR_IPC_SHMEM_CH_TEE_SIZE)

#define DDR_IPC_SHMEM_CH_SEND_TEE_ADDR_AP  DDR_IPC_SHMEM_CH_TEE_BASE_AP
#define DDR_IPC_SHMEM_CH_SEND_TEE_SIZE     (0xB000)
#define DDR_IPC_SHMEM_TEE_SEND_CH_ADDR_AP  (DDR_IPC_SHMEM_CH_SEND_TEE_ADDR_AP + DDR_IPC_SHMEM_CH_SEND_TEE_SIZE)
#define DDR_IPC_SHMEM_TEE_SEND_CH_SIZE     (0x5000)
#define DDR_IPC_SHMEM_CH_SEND_TEE_LOCATION_ADDR_AP  DDR_IPC_SHMEM_TEE_SEND_CH_ADDR_AP + DDR_IPC_SHMEM_TEE_SEND_CH_SIZE
#define DDR_IPC_SHMEM_CH_SEND_TEE_LOCATION_SIZE     (0x104)

#define DDR_FP_IMAGE_BASE_AP               DDR_IPC_SHMEM_CH_TEE_END_AP
#define DDR_FP_IMAGE_SIZE                  (0x80000)
#define DDR_FP_IMAGE_END_AP                (DDR_FP_IMAGE_BASE_AP + DDR_FP_IMAGE_SIZE)

#define DDR_RESERVED_USED_END              DDR_FP_IMAGE_END_AP
#if DDR_RESERVED_USED_END > (DDR_RESERVE_ADDR_AP + DDR_RESERVE_SIZE)
    #error "DDR_RESERVED_USED overflow"
#endif


/*========================================================================
      NPU_TINY DDR RESERVED  0x13600000 ~ 0x13E00000 rw non-cache
==========================================================================*/

/*    |-----Total 8M-----|
      |-----8.0M-----|---reserve----|
*/
#define DDR_TINY_RESERVE_ADDR_AP            RESERVED_NPU_TINY_PHYMEM_BASE
#define DDR_TINY_RESERVE_SIZE               RESERVED_NPU_TINY_PHYMEM_SIZE

/*========================================================================
      SDC shared DDR 0x14500000 ~ 0x14600000 = 1M
==========================================================================*/
#define DDR_SHMEM_SDC_ACC_ADDR_AP           RESERVED_SENSORHUB_SDC_BASE
#define DDR_SHMEM_SDC_ACC_SIZE              0xF000

#define DDR_SHMEM_SDC_MAG_ADDR_AP           (DDR_SHMEM_SDC_ACC_ADDR_AP + DDR_SHMEM_SDC_ACC_SIZE)
#define DDR_SHMEM_SDC_MAG_SIZE              0xF000

#define DDR_SHMEM_SDC_ORIENTATION_ADDR_AP   (DDR_SHMEM_SDC_MAG_ADDR_AP + DDR_SHMEM_SDC_MAG_SIZE)
#define DDR_SHMEM_SDC_ORIENTATION_SIZE      0xF000

#define DDR_SHMEM_SDC_GYRO_ADDR_AP          (DDR_SHMEM_SDC_ORIENTATION_ADDR_AP + DDR_SHMEM_SDC_ORIENTATION_SIZE)
#define DDR_SHMEM_SDC_GYRO_SIZE             0xF000

#define DDR_SHMEM_SDC_LINEAR_ACC_ADDR_AP    (DDR_SHMEM_SDC_GYRO_ADDR_AP + DDR_SHMEM_SDC_GYRO_SIZE)
#define DDR_SHMEM_SDC_LINEAR_ACC_SIZE       0xF000

#define DDR_SHMEM_SDC_ROTATION_VECTOR_ADDR_AP  (DDR_SHMEM_SDC_LINEAR_ACC_ADDR_AP + DDR_SHMEM_SDC_LINEAR_ACC_SIZE)
#define DDR_SHMEM_SDC_ROTATION_VECTOR_SIZE  0xF000

#define DDR_SHMEM_SDC_GRAVITY_ADDR_AP           (DDR_SHMEM_SDC_ROTATION_VECTOR_ADDR_AP + DDR_SHMEM_SDC_ROTATION_VECTOR_SIZE)
#define DDR_SHMEM_SDC_GRAVITY_SIZE              0xF000

#define DDR_SHMEM_SDC_MAG_UNCALI_ADDR_AP           (DDR_SHMEM_SDC_GRAVITY_ADDR_AP + DDR_SHMEM_SDC_GRAVITY_SIZE)
#define DDR_SHMEM_SDC_MAG_UNCALI_SIZE              0xF000

#define DDR_SHMEM_SDC_GEOMAGNETIC_RV_ADDR_AP           (DDR_SHMEM_SDC_MAG_UNCALI_ADDR_AP + DDR_SHMEM_SDC_MAG_UNCALI_SIZE)
#define DDR_SHMEM_SDC_GEOMAGNETIC_RV_SIZE              0xF000

#define DDR_SHMEM_SDC_GYRO_UNCALI_ADDR_AP           (DDR_SHMEM_SDC_GEOMAGNETIC_RV_ADDR_AP + DDR_SHMEM_SDC_GEOMAGNETIC_RV_SIZE)
#define DDR_SHMEM_SDC_GYRO_UNCALI_SIZE              0xF000

#define DDR_SHMEM_SDC_ACC_UNCALI_ADDR_AP           (DDR_SHMEM_SDC_GYRO_UNCALI_ADDR_AP + DDR_SHMEM_SDC_GYRO_UNCALI_SIZE)
#define DDR_SHMEM_SDC_ACC_UNCALI_SIZE              0xF000

#define DDR_SHMEM_SDC_ACC1_ADDR_AP           (DDR_SHMEM_SDC_ACC_UNCALI_ADDR_AP + DDR_SHMEM_SDC_ACC_UNCALI_SIZE)
#define DDR_SHMEM_SDC_ACC1_SIZE              0xF000

#define DDR_SHMEM_SDC_GYRO1_ADDR_AP           (DDR_SHMEM_SDC_ACC1_ADDR_AP + DDR_SHMEM_SDC_ACC1_SIZE)
#define DDR_SHMEM_SDC_GYRO1_SIZE              0xF000

#define DDR_SHMEM_SDC_ACC2_ADDR_AP           (DDR_SHMEM_SDC_GYRO1_ADDR_AP + DDR_SHMEM_SDC_GYRO1_SIZE)
#define DDR_SHMEM_SDC_ACC2_SIZE              0xF000

#define DDR_SHMEM_SDC_GYRO2_ADDR_AP           (DDR_SHMEM_SDC_ACC2_ADDR_AP + DDR_SHMEM_SDC_ACC2_SIZE)
#define DDR_SHMEM_SDC_GYRO2_SIZE              0xF000

#define DDR_SHMEM_SDC_GAME_RV_ADDR_AP         (DDR_SHMEM_SDC_GYRO2_ADDR_AP + DDR_SHMEM_SDC_GYRO2_SIZE)
#define DDR_SHMEM_SDC_GAME_RV_SIZE            0xF000

#define DDR_SHMEM_SDC_PRESSURE_ADDR_AP        (DDR_SHMEM_SDC_GAME_RV_ADDR_AP + DDR_SHMEM_SDC_GAME_RV_SIZE)
#define DDR_SHMEM_SDC_PRESSURE_SIZE           0xF000

#endif
#endif
