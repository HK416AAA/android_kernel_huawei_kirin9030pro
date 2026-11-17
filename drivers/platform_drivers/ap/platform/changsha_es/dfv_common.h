#ifndef __DFV_COMMON_H__
#define __DFV_COMMON_H__ 
#define MAX_DFV_VOLT 8
#define MAX_SAMPLE_NUM 4
#define DFV_MAX_PROFILE 16
#define DFV_MAX_NAME_LEN 8
#define PERCHIP_DFV_INVAILD 0xFF
#define PERCHIP_DFV_VALID 0xFC
#define DFV_INVAILD 0xFA
enum dfv_runtime_mode {
 DFV_RT_DISABLE = 0,
 DFV_RT_ENABLE,
 DFV_RT_TRACE,
};
enum perchip_dfv_para_mode {
 PIM_DELTA = 0,
 VOLT_LIMIT,
 DFV_PARA_MODE_MAX,
};
enum dfv_cluster {
 DFV_LITTLE,
 DFV_MIDDLE,
 DFV_BIG,
 DFV_CPU_MAX,
 DFV_GPU = DFV_CPU_MAX,
 DFV_MAX_CLUSTER,
};
#define GPU_LOM_MAGIC 0xDEADA55A
#define GPU_LOM_DATA_NUM 2
struct lom_data_gpu {
 unsigned int magic;
 unsigned char inited;
 unsigned char ratio[GPU_LOM_DATA_NUM];
 unsigned int reg_data[3];
};
#endif
