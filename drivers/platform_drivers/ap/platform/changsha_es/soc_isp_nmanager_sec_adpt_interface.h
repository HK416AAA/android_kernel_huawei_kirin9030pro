#ifndef __SOC_ISP_NMANAGER_SEC_ADPT_INTERFACE_H__
#define __SOC_ISP_NMANAGER_SEC_ADPT_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_ISP_nManager_SEC_ADPT_swid_cfg_ns_ADDR(base,n) ((base) + (0x000+(n)*4UL))
#define SOC_ISP_NMANAGER_SEC_ADPT_GLB_NS_ADDR(base) ((base) + (0x7FCUL))
#define SOC_ISP_nManager_SEC_ADPT_swid_cfg_s_ADDR(base,n) ((base) + (0x800+(n)*4UL))
#define SOC_ISP_NMANAGER_SEC_ADPT_GLB_CFG_S_ADDR(base) ((base) + (0xFFCUL))
#else
#define SOC_ISP_nManager_SEC_ADPT_swid_cfg_ns_ADDR(base,n) ((base) + (0x000+(n)*4))
#define SOC_ISP_NMANAGER_SEC_ADPT_GLB_NS_ADDR(base) ((base) + (0x7FC))
#define SOC_ISP_nManager_SEC_ADPT_swid_cfg_s_ADDR(base,n) ((base) + (0x800+(n)*4))
#define SOC_ISP_NMANAGER_SEC_ADPT_GLB_CFG_S_ADDR(base) ((base) + (0xFFC))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user_def_ns : 16;
        unsigned int ssid_ns : 12;
        unsigned int ssidv_ns : 1;
        unsigned int reserved : 3;
    } reg;
} SOC_ISP_nManager_SEC_ADPT_swid_cfg_ns_UNION;
#endif
#define SOC_ISP_nManager_SEC_ADPT_swid_cfg_ns_user_def_ns_START (0)
#define SOC_ISP_nManager_SEC_ADPT_swid_cfg_ns_user_def_ns_END (15)
#define SOC_ISP_nManager_SEC_ADPT_swid_cfg_ns_ssid_ns_START (16)
#define SOC_ISP_nManager_SEC_ADPT_swid_cfg_ns_ssid_ns_END (27)
#define SOC_ISP_nManager_SEC_ADPT_swid_cfg_ns_ssidv_ns_START (28)
#define SOC_ISP_nManager_SEC_ADPT_swid_cfg_ns_ssidv_ns_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int glb_ns : 32;
    } reg;
} SOC_ISP_NMANAGER_SEC_ADPT_GLB_NS_UNION;
#endif
#define SOC_ISP_NMANAGER_SEC_ADPT_GLB_NS_glb_ns_START (0)
#define SOC_ISP_NMANAGER_SEC_ADPT_GLB_NS_glb_ns_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int user_def_s : 16;
        unsigned int secsid_s : 1;
        unsigned int ssid_s : 12;
        unsigned int ssidv_s : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_ISP_nManager_SEC_ADPT_swid_cfg_s_UNION;
#endif
#define SOC_ISP_nManager_SEC_ADPT_swid_cfg_s_user_def_s_START (0)
#define SOC_ISP_nManager_SEC_ADPT_swid_cfg_s_user_def_s_END (15)
#define SOC_ISP_nManager_SEC_ADPT_swid_cfg_s_secsid_s_START (16)
#define SOC_ISP_nManager_SEC_ADPT_swid_cfg_s_secsid_s_END (16)
#define SOC_ISP_nManager_SEC_ADPT_swid_cfg_s_ssid_s_START (17)
#define SOC_ISP_nManager_SEC_ADPT_swid_cfg_s_ssid_s_END (28)
#define SOC_ISP_nManager_SEC_ADPT_swid_cfg_s_ssidv_s_START (29)
#define SOC_ISP_nManager_SEC_ADPT_swid_cfg_s_ssidv_s_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int glb_aid_s : 32;
    } reg;
} SOC_ISP_NMANAGER_SEC_ADPT_GLB_CFG_S_UNION;
#endif
#define SOC_ISP_NMANAGER_SEC_ADPT_GLB_CFG_S_glb_aid_s_START (0)
#define SOC_ISP_NMANAGER_SEC_ADPT_GLB_CFG_S_glb_aid_s_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
