#ifndef __SOC_PERCHIP_VMIN_H__
#define __SOC_PERCHIP_VMIN_H__ 
#define SOC_PERCHIP_VMIN_INFO_ADDR (0x109A0000)
#define SOC_PERCHIP_VMIN_INFO_SIZE (0x2000)
#define SOC_DIEID_GROUP_WIDTH 5
#define POWER_DOMAIN_MAX_MODULE_NUM 5
#define PERCHIP_VMIN_VECTOR_TEST_TIMEOUT 60
#define VMIN_VALUE_INVAILED 0xFFFFFFFF
#define PERCHIP_VMIN_MAGIC_NUMBER_START 0xDEADBEEF
#define PERCHIP_VMIN_MAGIC_NUMBER_END 0xBADFACE0
#define PERCHIP_VMIN_VERSION_NUMBER 1
#define POWER_DOMAIN_CPUL_PROFILE_NUM 13
#define POWER_DOMAIN_CPUM_PROFILE_NUM 16
#define POWER_DOMAIN_GPU_PROFILE_NUM 20
#define POWER_DOMAIN_NPU_PROFILE_NUM 10
#define POWER_DOMAIN_MED1_PROFILE_NUM 10
#define POWER_DOMAIN_MED2_PROFILE_NUM 10
#define POWER_DOMAIN_MDM_PROFILE_NUM 10
#define POWER_DOMAIN_PERI_PROFILE_NUM 10
#define POWER_DOMAIN_ISP_CPU_PROFILE_NUM 10
#define POWER_DOMAIN_All_PROFILE_NUM \
 (POWER_DOMAIN_CPUL_PROFILE_NUM + POWER_DOMAIN_CPUM_PROFILE_NUM + POWER_DOMAIN_GPU_PROFILE_NUM + \
  POWER_DOMAIN_NPU_PROFILE_NUM + POWER_DOMAIN_MED1_PROFILE_NUM + POWER_DOMAIN_MED2_PROFILE_NUM + \
  POWER_DOMAIN_MDM_PROFILE_NUM + POWER_DOMAIN_PERI_PROFILE_NUM + POWER_DOMAIN_ISP_CPU_PROFILE_NUM)
#define POWER_DOMAIN_CPUL_MODULE_NUM 1
#define POWER_DOMAIN_CPUM_MODULE_NUM 2
#define POWER_DOMAIN_GPU_MODULE_NUM 1
#define POWER_DOMAIN_NPU_MODULE_NUM 1
#define POWER_DOMAIN_MED1_MODULE_NUM 5
#define POWER_DOMAIN_MED2_MODULE_NUM 5
#define POWER_DOMAIN_MDM_MODULE_NUM 2
#define POWER_DOMAIN_PERI_MODULE_NUM 5
#define POWER_DOMAIN_ISP_CPU_MODULE_NUM 1
enum power_domain_idx {
 POWER_DOMAIN_START = 0,
 POWER_DOMAIN_CPUL = POWER_DOMAIN_START,
 POWER_DOMAIN_CPUM,
 POWER_DOMAIN_GPU,
 POWER_DOMAIN_NPU,
 POWER_DOMAIN_MED1,
 POWER_DOMAIN_MED2,
 POWER_DOMAIN_MDM,
 POWER_DOMAIN_PERI,
 POWER_DOMAIN_ISP_CPU,
 POWER_DOMAIN_MAX,
};
enum perchip_vmin_module_idx {
 PERCHIP_VMIN_MODULE_START = 0,
 PERCHIP_VMIN_MODULE_CPUL = PERCHIP_VMIN_MODULE_START,
 PERCHIP_VMIN_MODULE_CPUM_1,
 PERCHIP_VMIN_MODULE_CPUM_2,
 PERCHIP_VMIN_MODULE_GPU,
 PERCHIP_VMIN_MODULE_NPU,
 PERCHIP_VMIN_MODULE_AAE,
 PERCHIP_VMIN_MODULE_DSS,
 PERCHIP_VMIN_MODULE_MEDIA1,
 PERCHIP_VMIN_MODULE_VDEC,
 PERCHIP_VMIN_MODULE_VENC,
 PERCHIP_VMIN_MODULE_ISP_GROUP1,
 PERCHIP_VMIN_MODULE_ISP_FE1,
 PERCHIP_VMIN_MODULE_ISP_FE2,
 PERCHIP_VMIN_MODULE_ISP_FE3,
 PERCHIP_VMIN_MODULE_MEDIA2,
 PERCHIP_VMIN_MODULE_MODEM_BBP_AND_PDEA,
 PERCHIP_VMIN_MODULE_MODEM_SUBSYS_AND_TSP_CORE,
 PERCHIP_VMIN_MODULE_ISP_SUBSYS_QIC,
 PERCHIP_VMIN_MODULE_IPP_SUBSYS,
 PERCHIP_VMIN_MODULE_MODEM_PERI,
 PERCHIP_VMIN_MODULE_MODEM_DPA,
 PERCHIP_VMIN_MODULE_MM_LB,
 PERCHIP_VMIN_MODULE_ISP_CPU,
 PERCHIP_VMIN_MODULE_MAX,
};
enum vmin_test_stage {
 VMIN_TEST_STAGE_NOT_STARTED = 0,
 VMIN_TEST_STAGE_ONGOING,
 VMIN_TEST_STAGE_COMPELETED,
 VMIN_TEST_STAGE_MAX,
};
enum vector_test_status {
 VECTOR_TEST_DONE = 0,
 VECTOR_TEST_ONGOING,
 VECTOR_TEST_STAUS_MAX,
};
enum vmin_test_type {
 VMIN_TEST_TYPE_LOGIC_VMIN = 0,
 VMIN_TEST_TYPE_MEM_VMIN,
 VMIN_TEST_TYPE_MEM_VMAX,
 VMIN_TEST_TYPE_MAX,
};
struct perchip_vmin_test_point {
 unsigned int module_index;
 enum power_domain_idx power_domain;
 unsigned int profile;
 unsigned int vmin_high;
 unsigned int vmin_low;
 unsigned int vmin_mid;
 enum vmin_test_type test_type;
 unsigned int is_module_power_on_compeleted;
 enum vector_test_status is_module_test_ongoing;
 enum vector_test_status is_profile_test_ongoing;
};
struct perchip_vmin_value {
 unsigned int logic_vmin;
 unsigned int mem_vmin;
 unsigned int mem_vmax;
};
struct perchip_vmin_save_info {
 unsigned int magic_number_start;
 unsigned int version;
 unsigned int soc_dieid[SOC_DIEID_GROUP_WIDTH];
 enum vmin_test_stage test_stage;
 struct perchip_vmin_test_point test_point;
 struct perchip_vmin_value all_vmin[POWER_DOMAIN_All_PROFILE_NUM][POWER_DOMAIN_MAX_MODULE_NUM];
 unsigned int magic_number_end;
};
struct powe_domain_info_desc {
 char *name;
 unsigned int profile_num;
 unsigned int module_num;
};
static const struct powe_domain_info_desc g_power_domain_info_tbl[] = {
 [POWER_DOMAIN_CPUL] =
  {
   .name = "CPUL",
   .profile_num = POWER_DOMAIN_CPUL_PROFILE_NUM,
   .module_num = POWER_DOMAIN_CPUL_MODULE_NUM,
  },
 [POWER_DOMAIN_CPUM] =
  {
   .name = "CPUM",
   .profile_num = POWER_DOMAIN_CPUM_PROFILE_NUM,
   .module_num = POWER_DOMAIN_CPUM_MODULE_NUM,
  },
 [POWER_DOMAIN_GPU] =
  {
   .name = "GPU",
   .profile_num = POWER_DOMAIN_GPU_PROFILE_NUM,
   .module_num = POWER_DOMAIN_GPU_MODULE_NUM,
  },
 [POWER_DOMAIN_NPU] =
  {
   .name = "NPU",
   .profile_num = POWER_DOMAIN_NPU_PROFILE_NUM,
   .module_num = POWER_DOMAIN_NPU_MODULE_NUM,
  },
 [POWER_DOMAIN_MED1] =
  {
   .name = "MEDIA1",
   .profile_num = POWER_DOMAIN_MED1_PROFILE_NUM,
   .module_num = POWER_DOMAIN_MED1_MODULE_NUM,
  },
 [POWER_DOMAIN_MED2] =
  {
   .name = "MEDIA2",
   .profile_num = POWER_DOMAIN_MED2_PROFILE_NUM,
   .module_num = POWER_DOMAIN_MED2_MODULE_NUM,
  },
 [POWER_DOMAIN_MDM] =
  {
   .name = "MDM",
   .profile_num = POWER_DOMAIN_MDM_PROFILE_NUM,
   .module_num = POWER_DOMAIN_MDM_MODULE_NUM,
  },
 [POWER_DOMAIN_PERI] =
  {
   .name = "PERI",
   .profile_num = POWER_DOMAIN_PERI_PROFILE_NUM,
   .module_num = POWER_DOMAIN_PERI_MODULE_NUM,
  },
 [POWER_DOMAIN_ISP_CPU] =
  {
   .name = "ISP_CPU",
   .profile_num = POWER_DOMAIN_ISP_CPU_PROFILE_NUM,
   .module_num = POWER_DOMAIN_ISP_CPU_MODULE_NUM,
  },
};
static const char *g_module_name_tbl[PERCHIP_VMIN_MODULE_MAX] = {
 [PERCHIP_VMIN_MODULE_CPUL] = "CPUL",
 [PERCHIP_VMIN_MODULE_CPUM_1] = "CPUM_1",
 [PERCHIP_VMIN_MODULE_CPUM_2] = "CPUM_2",
 [PERCHIP_VMIN_MODULE_GPU] = "GPU",
 [PERCHIP_VMIN_MODULE_NPU] = "NPU",
 [PERCHIP_VMIN_MODULE_AAE] = "AAE",
 [PERCHIP_VMIN_MODULE_DSS] = "DSS",
 [PERCHIP_VMIN_MODULE_MEDIA1] = "MEDIA1",
 [PERCHIP_VMIN_MODULE_VDEC] = "VDEC",
 [PERCHIP_VMIN_MODULE_VENC] = "VENC",
 [PERCHIP_VMIN_MODULE_ISP_GROUP1] = "ISP_GROUP1",
 [PERCHIP_VMIN_MODULE_ISP_FE1] = "ISP_FE1",
 [PERCHIP_VMIN_MODULE_ISP_FE2] = "ISP_FE2",
 [PERCHIP_VMIN_MODULE_ISP_FE3] = "ISP_FE3",
 [PERCHIP_VMIN_MODULE_MEDIA2] = "MEDIA2",
 [PERCHIP_VMIN_MODULE_MODEM_BBP_AND_PDEA] = "MODEM_BBP_AND_PDEA",
 [PERCHIP_VMIN_MODULE_MODEM_SUBSYS_AND_TSP_CORE] = "MODEM_SUBSYS_AND_TSP_CORE",
 [PERCHIP_VMIN_MODULE_ISP_SUBSYS_QIC] = "ISP_SUBSYS_QIC",
 [PERCHIP_VMIN_MODULE_IPP_SUBSYS] = "IPP_SUBSYS",
 [PERCHIP_VMIN_MODULE_MODEM_PERI] = "MODEM_PERI",
 [PERCHIP_VMIN_MODULE_MODEM_DPA] = "MODEM_DPA",
 [PERCHIP_VMIN_MODULE_MM_LB] = "MM_LB",
 [PERCHIP_VMIN_MODULE_ISP_CPU] = "ISP_CPU",
};
static inline unsigned int get_power_domain_profile_store_info_offest(enum power_domain_idx power_domain)
{
 unsigned int offset = 0, i = 0;
 for (i = POWER_DOMAIN_START; i < (unsigned int)power_domain; i++)
  offset += g_power_domain_info_tbl[i].profile_num;
 return offset;
}
static inline unsigned int get_power_domain_module_store_info_offest(
 enum power_domain_idx power_domain, enum perchip_vmin_module_idx module)
{
 unsigned int offset = 0, i = 0;
 int diff;
 for (i = PERCHIP_VMIN_MODULE_START; i < (unsigned int)power_domain; i++)
  offset += g_power_domain_info_tbl[i].module_num;
 diff = (unsigned int)module - offset;
 if (diff < 0 || (unsigned int)diff >= g_power_domain_info_tbl[power_domain].module_num)
  return VMIN_VALUE_INVAILED;
 return (unsigned int)diff;
}
static inline const char *get_module_name(enum power_domain_idx power_domain, unsigned int idx_in_pd)
{
 unsigned int offset = 0, i = 0;
 for (i = PERCHIP_VMIN_MODULE_START; i < (unsigned int)power_domain; i++)
  offset += g_power_domain_info_tbl[i].module_num;
 return g_module_name_tbl[offset + idx_in_pd];
}
static inline struct perchip_vmin_value get_power_domain_profile_vmin(
 enum power_domain_idx pd_idx, enum perchip_vmin_module_idx module, unsigned int profile)
{
 unsigned int power_domain_offset = 0, module_offset = 0;
 struct perchip_vmin_save_info *vmin_save_info = (struct perchip_vmin_save_info *)SOC_PERCHIP_VMIN_INFO_ADDR;
 struct perchip_vmin_value invalid_info = {VMIN_VALUE_INVAILED, VMIN_VALUE_INVAILED, VMIN_VALUE_INVAILED};
 if (pd_idx >= POWER_DOMAIN_MAX || profile >= g_power_domain_info_tbl[pd_idx].profile_num) {
  return invalid_info;
 }
 if (vmin_save_info->test_stage != VMIN_TEST_STAGE_COMPELETED) {
  return invalid_info;
 }
 if (vmin_save_info->magic_number_start != PERCHIP_VMIN_MAGIC_NUMBER_START ||
  vmin_save_info->magic_number_end != PERCHIP_VMIN_MAGIC_NUMBER_END) {
  return invalid_info;
 }
 power_domain_offset = get_power_domain_profile_store_info_offest(pd_idx);
 module_offset = get_power_domain_module_store_info_offest(pd_idx, module);
 return vmin_save_info->all_vmin[power_domain_offset + profile][module_offset];
}
static inline unsigned int get_profile_vmin_info_version(void)
{
 struct perchip_vmin_save_info *vmin_save_info = (struct perchip_vmin_save_info *)SOC_PERCHIP_VMIN_INFO_ADDR;
 if (vmin_save_info->test_stage != VMIN_TEST_STAGE_COMPELETED) {
  return VMIN_VALUE_INVAILED;
 }
 if (vmin_save_info->magic_number_start != PERCHIP_VMIN_MAGIC_NUMBER_START ||
  vmin_save_info->magic_number_end != PERCHIP_VMIN_MAGIC_NUMBER_END) {
  return VMIN_VALUE_INVAILED;
 }
 return vmin_save_info->version;
}
#endif
