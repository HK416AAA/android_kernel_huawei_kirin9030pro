

#ifndef LPHY_V2X_CYCLE_OM_DEF_H
#define LPHY_V2X_CYCLE_OM_DEF_H

/*
 * 1 其他头文件包含
 */
#include "uphy_om_interface.h"

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

/*
 * 枚举说明: OM RPT ID
 */
enum V2XL_OM_CYCLE_OmRptId {
    V2XL_OM_CYCLE_TASK_RPT = LVPHY_OM_L1MSG_ID(LVPHY_MODULE_ID_CYCLE, 0x0),
    V2XL_OM_CYCLE_RPT_BUTT
};
typedef uint32_t V2XL_OM_CYCLE_OmRptIdUint32;


/*
 * 4 STRUCT定义
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
