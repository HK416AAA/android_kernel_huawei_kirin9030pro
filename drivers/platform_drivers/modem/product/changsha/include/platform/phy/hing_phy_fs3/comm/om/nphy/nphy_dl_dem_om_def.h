/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description: DEM OM接口文件
 * Author: 张景旺/414126
 * Create: 2017年11月25日
 * History: 1. 2017年11月25日，张景旺/414126，创建文件
 */

#ifndef __NPHY_DL_DEM_OM_DEF_H__
#define __NPHY_DL_DEM_OM_DEF_H__


/*
 * 1 其他头文件包含
 */
#include "nphy_dl_dem_om_base_def.h"

#ifdef __cplusplus
#if __cplusplus
    extern "C"{
#endif
#endif /* __cplusplus */

/*
 * 2 宏定义
 */
#define NPHY_DEM_OM_MAX_REG_NUM                     10
#define NPHY_DEM_CC_OFFSET                          0x800000
#define NPHY_DEM_SOFT_BIT_BASE_ADDR(CCIDX)          (0xf1191084 + (CCIDX) * NPHY_DEM_CC_OFFSET)
#define NPHY_DEM_REG_SIZE                           4
#define NPHY_DEM_DCI_CYCLE_MAX_CNT                  20
#define NPHY_DEM_PDS_SCHED_RECORD_NUM               8
#define NPHY_DL_MSG_PROC_CYCLE_CNT_BUTT             25
#define NPHY_MAX_RB_SECTION_NUM                     9
#define NPHY_DEM_OM_MAX_RX_NUM                      4
#define NPHY_DEM_OM_MAX_INFO_NUM                    3
#define NPHY_DEM_MAX_DMRS_SYM_NUM                   4
#define NPHY_DEM_RUU_RPT_MAX_NUM                    2

/*
 * 3 枚举定义
 */

/*
 * 4 消息头定义
 */
/*
 * 5 消息定义
 */
/*
 * 6 STRUCT定义
 */

#define NPHY_DL_MAX_TCI_NUM_PER_SLOT 2 // for multiTrp only

typedef struct {
    uint32_t                  curSlotTciNum;
    NPHY_CHE_QclCurrSlot      curSlotInfo[NPHY_DL_MAX_TCI_NUM_PER_SLOT]; // support max 2 layer^M
} NPHY_CHE_QclCurrSlotInfo;

/* 速率匹配参数完全配置上报 */

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

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __NPHY_DL_DEM_OM_DEF_H__ */

