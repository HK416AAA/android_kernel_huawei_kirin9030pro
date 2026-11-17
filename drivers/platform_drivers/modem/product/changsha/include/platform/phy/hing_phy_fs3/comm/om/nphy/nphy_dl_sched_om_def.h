/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: DL SCHED OM接口文件
 */

#ifndef __NPHY_DL_SCHED_OM_DEF_H__
#define __NPHY_DL_SCHED_OM_DEF_H__


/*
 * 1 其他头文件包含
 */
#include "uphy_om_interface.h"/*lint !e537*/
#include "neun_basedef_macro.h"/*lint !e537*/
#include "uphy_trace_interface.h"/*lint !e537*/
#include "uphy_om_def.h"/*lint !e537*/
#include "uphy_os_interface.h"/*lint !e537*/
#include "ul1m_phy_msg_interface.h"/*lint !e537*/

#ifdef __cplusplus
#if __cplusplus
    extern "C"{
#endif
#endif /* __cplusplus */
/*
 * 2. Macro definitions
 */
#define NPHY_DLSCHED_MBX_FUN_NUM                          40

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
} NPHY_SCHED_DlFunInfo;

/*
 * Struct Description: 邮箱cycle统计
 */
typedef struct {
    UPHY_TRACE_Header       header;
    uint8_t                 funcNum;
    uint8_t                 modemId;
    uint16_t                rsv;
    uint32_t                totalCycle;
    NPHY_SCHED_DlFunInfo    func[NPHY_DLSCHED_MBX_FUN_NUM];
} NPHY_SCHED_MailCounter;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __NPHY_DL_SCHED_OM_DEF_H__ */

