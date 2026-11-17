

/*
 * 1 其他头文件包含
 */
#ifndef __LPHY_IRAT_OM_DEF_H__
#define __LPHY_IRAT_OM_DEF_H__

#include "neun_irat_om_def.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(push, 4)

/*
 * 2 宏定义
 */
/*
 * 3 枚举定义
 */
enum LPHY_IRAT_OmReport {
    LPHY_OM_UL1M_IRAT_RPT_START            = LPHY_OM_L1MSG_ID(LPHY_MODULE_ID_IRAT, 0x00),
    LPHY_OM_UL1M_IRAT_SINGFREQ_MEASEND_IND = LPHY_OM_UL1M_IRAT_RPT_START,
    LPHY_OM_UL1M_IRAT_ALLFREQ_MEASEND_IND,
    LPHY_OM_UL1M_IRAT_TIM_DIFF_CAL_IND,
    LPHY_OM_UL1M_IRAT_INT_MSG_INFO,
    LPHY_OM_UL1M_IRAT_PRESCHED_MSG_INFO,
    LPHY_OM_UL1M_IRAT_ARB_PRESCHED_MSG_INFO,
    LPHY_OM_UL1M_IRAT_RPT_BUTT
};
typedef uint32_t LPHY_IRAT_OmReportUint32;

/*
 * 4 消息头定义
 */
/*
 * 5 消息定义
 */
/*
 * 6 STRUCT定义
 */
/*
 * 7 UNION定义
 */
/*
 * 8 OTHERS定义
 */
/*
 * 9 全局变量声明
 */
/*
 * 10 函数声明
 */
#pragma pack(pop)

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif

