

/*
 * 1 其他头文件包含
 */
#ifndef __LPHY_DSDS_OM_DEF_H__
#define __LPHY_DSDS_OM_DEF_H__

#include "neun_dsds_om_interface.h"

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
enum LPHY_DSDS_OmMsgType {
    LPHY_DSDS_COMM_STATUS      = LPHY_OM_L1MSG_ID(LPHY_MODULE_ID_DSDS, 0x00),
    LPHY_DSDS_LOGIN,
    LPHY_DSDS_LOGOUT,
    LPHY_DSDS_SRS_STATUS,
    LPHY_DSDS_CONCURRENCE_STATE_IND,
    LPHY_DSDS_OM_RPT_BUTT      = LPHY_OM_L1MSG_ID(LPHY_MODULE_ID_DSDS, 0x80),
};
typedef uint32_t LPHY_DSDS_OmMsgTypeUint32;

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

