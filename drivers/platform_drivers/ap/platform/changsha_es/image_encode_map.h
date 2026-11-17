#ifndef __IMAGE_ENCODE_MAP_H__
#define __IMAGE_ENCODE_MAP_H__ 
#include <stdint.h>
#include "image_id.h"
#include "image_name.h"
#include "image_encode.h"
#ifdef __cplusplus
extern "C" {
#endif
struct image_encode_map {
 char *img_name;
 uint32_t encode;
};
static const struct image_encode_map g_map[] = {
 {
  .img_name = UCE_IMG_NAME,
  .encode = ERROR_IMAGE_UCE,
 },
 {
  .img_name = XLOADER3_IMG_NAME_LPMCU,
  .encode = ERROR_IMAGE_XLOADER3,
 },
 {
  .img_name = BL2_IMG_NAME_UFS,
  .encode = ERROR_IMAGE_BL2,
 },
 {
  .img_name = GXPU_IMG_NAME,
  .encode = ERROR_IMAGE_GXPU,
 },
 {
  .img_name = CXPU_IMG_NAME,
  .encode = ERROR_IMAGE_CXPU,
 },
 {
  .img_name = DDR_XPU_RUNTIME_IMG_NAME,
  .encode = ERROR_IMAGE_DDR_XPU_RUNTIME,
 },
 {
  .img_name = DDR_XPU_BOOT0_IMG_NAME,
  .encode = ERROR_IMAGE_DDR_XPU_BOOT0,
 },
 {
  .img_name = DDR_XPU_BOOT1_IMG_NAME,
  .encode = ERROR_IMAGE_DDR_XPU_BOOT1,
 },
#ifndef CONFIG_UAPP_DFX_IN_XLOADER
 {
  .img_name = MEDIA_XPU_IMG_NAME,
  .encode = ERROR_IMAGE_MEDIA_XPU,
 },
 {
  .img_name = BL31_IMG_NAME,
  .encode = ERROR_IMAGE_BL31,
 },
 {
  .img_name = TEEOS_IMG_NAME,
  .encode = ERROR_IMAGE_TRUSTEDCORE,
 },
 {
  .img_name = THEE_IMG_NAME,
  .encode = ERROR_IMAGE_THEE,
 },
 {
  .img_name = TZSP_IMG_NAME,
  .encode = ERROR_IMAGE_TZSP,
 },
 {
  .img_name = HHEE_IMG_NAME,
  .encode = ERROR_IMAGE_HHEE,
 },
 {
  .img_name = LPM3_IMG_NAME,
  .encode = ERROR_IMAGE_LPM3,
 },
 {
  .img_name = UEFI_IMG_NAME,
  .encode = ERROR_IMAGE_UEFI,
 },
 {
  .img_name = DTBO_IMG_NAME,
  .encode = ERROR_IMAGE_DTBO,
 },
 {
  .img_name = SENSORHUB_IMG_NAME,
  .encode = ERROR_IMAGE_SENSORHUB,
 },
 {
  .img_name = HIFI_IMG_NAME,
  .encode = ERROR_IMAGE_HIFI,
 },
 {
  .img_name = FW_DTB_IMG_NAME,
  .encode = ERROR_IMAGE_FW_DTB,
 },
 {
  .img_name = NPU_FW_IMG_NAME,
  .encode = ERROR_IMAGE_NPU_FW,
 },
 {
  .img_name = DACC_IMG_NAME,
  .encode = ERROR_IMAGE_DACC,
 },
 {
  .img_name = ISP_IMG_NAME,
  .encode = ERROR_IMAGE_ISP,
 },
 {
  .img_name = VBMETA_IMG_NAME,
  .encode = ERROR_IMAGE_VBMETA,
 },
 {
  .img_name = RECOVERY_VBMETA_IMG_NAME,
  .encode = ERROR_IMAGE_RECOVERY_VBMETA,
 },
 {
  .img_name = ERECOVERY_VBMETA_IMG_NAME,
  .encode = ERROR_IMAGE_ERECOVERY_VBMETA,
 },
 {
  .img_name = DT_IMG_NAME,
  .encode = ERROR_IMAGE_DT,
 },
 {
  .img_name = KPATCH_IMG_NAME,
  .encode = ERROR_IMAGE_KPATCH,
 },
 {
  .img_name = FW_UFSDEV_IMG_NAME,
  .encode = ERROR_IMAGE_ORIG_UFS_EMER_FW,
 },
 {
  .img_name = HISEE_IMG_NAME,
  .encode = ERROR_IMAGE_HISEE,
 },
 {
  .img_name = SEPLAT_IMG_NAME,
  .encode = ERROR_IMAGE_SEPLAT,
 },
 {
  .img_name = DFA_IMG_NAME,
  .encode = ERROR_IMAGE_DFA_ALL,
 },
 {
  .img_name = RVT_IMG_NAME,
  .encode = ERROR_IMAGE_RVT,
 },
 {
  .img_name = UPDATE_RVT_IMG_NAME,
  .encode = ERROR_IMAGE_UPDATE_RVT,
 },
 {
  .img_name = UPDATE_BAK_RVT_IMG_NAME,
  .encode = ERROR_IMAGE_UPDATE_BAK_RVT,
 },
#endif
};
#ifdef __cplusplus
}
#endif
#endif
