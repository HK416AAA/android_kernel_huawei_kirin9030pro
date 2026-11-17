/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: DL SCHED OM接口文件
 */

#ifndef __LPHY_DL_SCHED_OM_DEF_H__
#define __LPHY_DL_SCHED_OM_DEF_H__

/*
 * 1 其他头文件包含
 */
#include "neun_basedef_struct.h"
#include "uphy_basedef_func.h"
#include "uphy_om_interface.h"
#include "uphy_trace_interface.h"
#include "uphy_os_interface.h"
#include "ul1m_phy_msg_interface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#define LPHY_DLSCHED_MBX_FUN_NUM                          25

/*
 * 3. Enumerations declarations
 */

/*
 * 4. Struct Description
 */
/*
 * Struct Description: 邮箱cycle统计
 */
typedef struct {
    UPHY_OS_ModuleIdTypeUint8   moduleIdType;
    UL1M_ComponentTypeUint08    componentType;
    UL1M_ModuleUint08           moduleId;
    uint8_t                     msgId;
    uint32_t                    cycleCount;
} LPHY_SCHED_DlFunInfo;

/*
 * Struct Description: 邮箱cycle统计
 */
typedef struct {
    UPHY_TRACE_Header       header;
    uint8_t                 funcNum;
    uint8_t                 modemId;
    uint16_t                rsv;
    uint32_t                totalCycle;
    LPHY_SCHED_DlFunInfo    func[LPHY_DLSCHED_MBX_FUN_NUM];
} LPHY_SCHED_MailCounter;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __NPHY_DL_SCHED_OM_DEF_H__ */
