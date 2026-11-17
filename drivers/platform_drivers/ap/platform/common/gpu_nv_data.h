#ifndef __GPU_NV_DATA_H__
#define __GPU_NV_DATA_H__ 
#ifdef __cplusplus
extern "C" {
#endif
#define HVGR_FAC_PV_INFO_SIZE 8u
#define HVGR_FAC_PV_VOLT_SIZE 20u
struct hvgr_fac_gpu_nv_data {
    union {
        uint8_t value;
        struct {
   uint8_t reserve : 4;
   uint8_t dfv_mark : 1;
   uint8_t dfv_en : 1;
            uint8_t pv_mark : 1;
            uint8_t en : 1;
        } bit;
    } cfg;
    uint8_t info[HVGR_FAC_PV_INFO_SIZE];
    uint8_t volt[HVGR_FAC_PV_VOLT_SIZE];
};
#ifdef __cplusplus
}
#endif
#endif
