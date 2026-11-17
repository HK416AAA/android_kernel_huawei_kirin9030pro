/* Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved. 
   extract macros used in imocu from the global_ddr_map and iomcu_ddr_map header files
*/

#ifndef __IOMCU_MEM_H__
#define __IOMCU_MEM_H__

#ifdef CONFIG_HEADER_FILE_REPLACE_EXTRACT

#define RESERVED_SENSORHUB_SHMEMEXT_PHYMEM_BASE     0x10000000
#define RESERVED_SENSORHUB_SHMEMEXT_PHYMEM_SIZE     (0x600000)

#define RESERVED_SENSORHUB_SHMEM_PHYMEM_BASE        0x10600000
#define RESERVED_SENSORHUB_SHMEM_PHYMEM_SIZE        (0x40000)

#define RESERVED_SENSORHUB_SHARE_MEM_PHYMEM_BASE    0x10640000
#define RESERVED_SENSORHUB_SHARE_MEM_PHYMEM_SIZE    (0x80000)

#define RESERVED_SENSORHUB_PHYMEM_BASE              0x12900000
#define RESERVED_SENSORHUB_PHYMEM_SIZE              (0xD00000)

#define RESERVED_SENSORHUB_SDC_BASE                 0x14500000
#define RESERVED_SENSORHUB_SDC_SIZE                 (0x100000)

#define SOC_IOMCU_M7_MID                            (0x1)
#define SOC_IOMCU_DMA_MID                           (0x1A)

/*========================================================================
      SENSORHUB SHMEMEXT None Secure 0x10000000 ~ 0x10600000 = 6M
==========================================================================*/
/*    |-----Total 6M-----
      |-----1.5M-----|---cell location---|
      |-----0.5M-----|---flp heap alloc--| // flp_batching_loc_data & ddr map data
      |-----1.0M-----|---dump------------|  //rw
      |-----3.0M-----|---AOD-------------|
*/
#define DDR_SHMEMEXT_ADDR_AP              RESERVED_SENSORHUB_SHMEMEXT_PHYMEM_BASE
#define DDR_SHMEMEXT_SIZE                 RESERVED_SENSORHUB_SHMEMEXT_PHYMEM_SIZE

/* 2M FLP */
#define DDR_FLP_BASE_AP                   DDR_SHMEMEXT_ADDR_AP
#define DDR_FLP_SIZE                      (0x200000)
#define DDR_FLP_END_AP                    (DDR_SHMEMEXT_ADDR_AP + DDR_FLP_SIZE)

#define OFFLINE_CELL_MMAP_SIZE            (0x180000)

/* 1M - 64K DUMP */
#define DDR_DUMP_BASE_AP                   DDR_FLP_END_AP
#define DDR_DUMP_SIZE                      (0x100000 - 0x10000)
#define DDR_DUMP_END_AP                    (DDR_DUMP_BASE_AP + DDR_DUMP_SIZE)

/* 64K DPU CMDLIST */
#define DDR_DPU_CMDLIST_BASE_AP            DDR_DUMP_END_AP
#define DDR_DPU_CMDLIST_SIZE               (0x10000)
#define DDR_DPU_CMDLIST_END_AP             (DDR_DPU_CMDLIST_BASE_AP + DDR_DPU_CMDLIST_SIZE)

/* 3M AOD */
#define DDR_AOD_BASE_AP                    DDR_DPU_CMDLIST_END_AP
#define DDR_AOD_SIZE                       (0x300000)
#define DDR_AOD_END_AP                     (DDR_AOD_BASE_AP + DDR_AOD_SIZE)

/* 0K IGS SCAN CODE BUFFER */
#define DDR_IGS_SCAN_CODE_BASE_AP            DDR_AOD_END_AP
#define DDR_IGS_SCAN_CODE_SIZE               (0x0)
#define DDR_IGS_SCAN_CODE_END_AP             (DDR_IGS_SCAN_CODE_BASE_AP + DDR_IGS_SCAN_CODE_SIZE)
/*========================================================================
      SENSORHUB SHMEM1 FOR IPC 10600000 ~ 10640000 = 256K
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
      SENSORHUB SHMEM FOR LOG BUFFER  0x10640000 ~ 0x106C0000 = 512K
==========================================================================*/
#define DDR_SHMEM_ADDR_AP                   RESERVED_SENSORHUB_SHARE_MEM_PHYMEM_BASE
#define DDR_SHMEM_SIZE                      RESERVED_SENSORHUB_SHARE_MEM_PHYMEM_SIZE

/*    |-----Total 512K-----
      |-----500K-----|---log buff---|
      |-----004K-----|---reserved---|
      |-----004K-----|---shell dgb--|
      |-----004K-----|---ddr cfg----|
*/
#define DDR_SHMEM_END_AP                   (DDR_SHMEM_ADDR_AP + DDR_SHMEM_SIZE)

/* DDR CONFIG */
#define DDR_CONFIG_SIZE                    (0x1000)
#define DDR_CONFIG_ADDR_AP                 (DDR_SHMEM_END_AP - DDR_CONFIG_SIZE)

/* SHELL_DBG */
#define DDR_SHELL_DBG_SIZE                 (0x1000)
#define DDR_SHELL_DBG_ADDR_AP              (DDR_CONFIG_ADDR_AP - DDR_SHELL_DBG_SIZE)

/* reserved */
#define DDR_IOMCU_RESERVED_SIZE            (0x1000)
#define DDR_IOMCU_RESERVED_ADDR_AP         (DDR_SHELL_DBG_ADDR_AP - DDR_IOMCU_RESERVED_SIZE)

/* LOG BUFFER */
#define DDR_LOG_BUFF_SIZE                  (DDR_IOMCU_RESERVED_ADDR_AP - DDR_SHMEM_ADDR_AP)
#define DDR_LOG_BUFF_ADDR_AP               (DDR_SHMEM_ADDR_AP)

/*========================================================================
      SENSORHUB DDR RESERVED   0x12900000 ~ 0x13600000  13M Secure
==========================================================================*/
#define DDR_RESERVE_ADDR_AP                 RESERVED_SENSORHUB_PHYMEM_BASE
#define DDR_RESERVE_SIZE                    RESERVED_SENSORHUB_PHYMEM_SIZE

/*    |-----Total 13M-----|
      |-----4.0M------------|---ddr code------|  //cacheable,rwe
      |---2.5M-128K-112.5K--|---ddr heap------|  //cacheable,rw
      |-----112.5K----------|-ipc ap secureshm|  //cacheable,rw
      |-----128K------------|---ipc shmem-----|  //rw
      |-----0.5M------------|---fp image------|  //rw
      |----6M-4K------------|---image---------|  //r
      |-----3K-4byte--------|---f2l-----------|  //r
      |-----4byte-----------|---random data---|  //r
      |-----1K--------------|---io die--------|  //r
*/
#define DDR_CODE_BASE_AP                   DDR_RESERVE_ADDR_AP
#define DDR_CODE_SIZE                      (0x400000)
#define DDR_CODE_END_AP                    (DDR_CODE_BASE_AP + DDR_CODE_SIZE)

#define DDR_HEAP_START_AP                  DDR_CODE_END_AP
#define DDR_HEAP_SIZE                      (0x243e00)
#define DDR_HEAP_END_AP                    (DDR_HEAP_START_AP + DDR_HEAP_SIZE)

#define DDR_IPCNS_SHM_RX_START_AP          DDR_HEAP_END_AP
#define DDR_IPCNS_SHM_RX_SIZE              (0x1c200)
#define DDR_IPCNS_SHM_RX_END_AP            (DDR_IPCNS_SHM_RX_START_AP + DDR_IPCNS_SHM_RX_SIZE)

/* ipc share memory for teeos */
#define DDR_IPC_SHMEM_CH_TEE_BASE_AP       DDR_IPCNS_SHM_RX_END_AP
#define DDR_IPC_SHMEM_CH_TEE_SIZE          (0x20000)
#define DDR_IPC_SHMEM_CH_TEE_END_AP        (DDR_IPC_SHMEM_CH_TEE_BASE_AP + DDR_IPC_SHMEM_CH_TEE_SIZE)

#define DDR_IPC_SHMEM_CH_SEND_TEE_ADDR_AP  DDR_IPC_SHMEM_CH_TEE_BASE_AP
#define DDR_IPC_SHMEM_CH_SEND_TEE_SIZE     (0xB000)
#define DDR_IPC_SHMEM_TEE_SEND_CH_ADDR_AP  (DDR_IPC_SHMEM_CH_SEND_TEE_ADDR_AP + DDR_IPC_SHMEM_CH_SEND_TEE_SIZE)
#define DDR_IPC_SHMEM_TEE_SEND_CH_SIZE     (0x5000)

#define DDR_IPC_SHMEM_CH_SEND_TEE_LOCATION_ADDR_AP  DDR_IPC_SHMEM_TEE_SEND_CH_ADDR_AP + DDR_IPC_SHMEM_TEE_SEND_CH_SIZE
#define DDR_IPC_SHMEM_CH_SEND_TEE_LOCATION_SIZE     (0x104)

#define DDR_F2I_GEOFENCE_BASE_AP           DDR_IPC_SHMEM_CH_SEND_TEE_LOCATION_ADDR_AP + DDR_IPC_SHMEM_CH_SEND_TEE_LOCATION_SIZE
#define DDR_F2I_GEOFENCE_SIZE              (0x500)
#define DDR_F2I_GEOFENCE_END_AP            (DDR_F2I_GEOFENCE_BASE_AP + DDR_F2I_GEOFENCE_SIZE)
 
#define DDR_F2I_WIFIFENCE_BASE_AP           DDR_F2I_GEOFENCE_END_AP
#define DDR_F2I_WIFIFENCE_SIZE              (0xC00)
#define DDR_F2I_WIFIFENCE_END_AP            (DDR_F2I_WIFIFENCE_BASE_AP + DDR_F2I_WIFIFENCE_SIZE)

#define DDR_FP_IMAGE_BASE_AP               DDR_IPC_SHMEM_CH_TEE_END_AP
#define DDR_FP_IMAGE_SIZE                  (0x80000)
#define DDR_FP_IMAGE_END_AP                (DDR_FP_IMAGE_BASE_AP + DDR_FP_IMAGE_SIZE)

#define DDR_IMAGE_BASE_AP                  DDR_FP_IMAGE_END_AP
#define DDR_IMAGE_SIZE                     (0x5FF000)
#define DDR_IMAGE_END_AP                   (DDR_IMAGE_BASE_AP + DDR_IMAGE_SIZE)

/* IOMCU FASTBOOT_TO_LPM3 CONFIG, keep same with fastboot & lpm3 */
#define DDR_F2L_CONFIG_ADDR_AP             DDR_IMAGE_END_AP
#define DDR_F2L_CONFIG_SIZE                (0xBFC)
#define DDR_F2L_CONFIG_END_AP              (DDR_F2L_CONFIG_ADDR_AP + DDR_F2L_CONFIG_SIZE)

#define DDR_F2L_RANDOM_DATA_AP             DDR_F2L_CONFIG_END_AP
#define DDR_F2L_RANDOM_DATA_SIZE           (0x4)
#define DDR_F2L_RANDOM_DATA_END_AP         (DDR_F2L_RANDOM_DATA_AP + DDR_F2L_RANDOM_DATA_SIZE)

#define DDR_IOMCU_IO_DIE_CFG_BASE_AP       DDR_F2L_RANDOM_DATA_END_AP
#define DDR_IOMCU_IO_DIE_CFG_SIZE          (0x400)
#define DDR_IOMCU_IO_DIE_CFG_END_AP        (DDR_IOMCU_IO_DIE_CFG_BASE_AP + DDR_IOMCU_IO_DIE_CFG_SIZE)

#define DDR_RESERVED_USED_END              DDR_IOMCU_IO_DIE_CFG_END_AP
#if DDR_RESERVED_USED_END > (DDR_RESERVE_ADDR_AP + DDR_RESERVE_SIZE)
	#error "DDR_RESERVED_USED overflow"
#endif

/*========================================================================
      NPU_TINY DDR RESERVED  0x13600000 ~ 0x13E00000
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