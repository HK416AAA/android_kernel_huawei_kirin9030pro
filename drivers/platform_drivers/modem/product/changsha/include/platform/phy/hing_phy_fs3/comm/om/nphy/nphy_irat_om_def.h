

/*
 * 1 其他头文件包含
 */
#ifndef __NPHY_IRAT_OM_DEF_H__
#define __NPHY_IRAT_OM_DEF_H__

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
enum NPHY_IRAT_OmReport {
    NPHY_OM_UL1M_IRAT_RPT_START        = NPHY_OM_L1MSG_ID(NPHY_MODULE_ID_IRAT, 0x00),
    NPHY_OM_UL1M_IRAT_TIM_DIFF_CAL_IND = NPHY_OM_UL1M_IRAT_RPT_START,
    NPHY_OM_UL1M_IRAT_INT_MSG_INFO,
    NPHY_OM_UL1M_IRAT_PRESCHED_MSG_INFO,
    NPHY_OM_UL1M_IRAT_DSDS_ARB_PRESCHED_MSG_INFO,
    NPHY_OM_UL1M_IRAT_RPT_BUTT
};
typedef uint32_t NPHY_IRAT_OmReportUint32;

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

