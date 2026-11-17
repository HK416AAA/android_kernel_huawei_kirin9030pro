

#ifndef SLUN_CYCLE_OM_DEF_H
#define SLUN_CYCLE_OM_DEF_H

/*
 * 1 其他头文件包含
 */
#include "uphy_om_interface.h"
#include "uphy_om_base_def.h"
#include "uphy_trace_interface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(push, 4)
/*
 * 2 宏定义
 */
#define SLUN_SCHED_TASK_FUNC_NUM                      20
/*
 * 3 枚举定义
 */

/*
 * 枚举说明: OM MSG ID
 */
enum SLUN_OM_CYCLE_MsgId {
    SLUN_OM_CYCLE_HL1C_1ST_HIGH_TASK_RPT,
    SLUN_OM_CYCLE_HL1C_2ND_HIGH_TASK_RPT,
    SLUN_OM_CYCLE_LL1C_1ST_HIGH_TASK_RPT,
    SLUN_OM_CYCLE_LL1C_2ND_HIGH_TASK_RPT,
    SLUN_OM_CYCLE_VDL_0_TASK_RPT,
    SLUN_OM_CYCLE_VDL_1_TASK_RPT,
    SLUN_OM_CYCLE_TDL_EVEN_TASK_RPT,
    SLUN_OM_CYCLE_TDL_ODD_TASK_RPT,
    SLUN_OM_CYCLE_RPT_BUTT
};
typedef uint8_t SLUN_OM_CYCLE_MsgIdUint08;

/*
 * 枚举说明: 中断类型
 */
enum SLUN_OM_CYCLE_SymEntryType {
    SLUN_OM_CYCLE_HL1C_TASK     = 0,
    SLUN_OM_CYCLE_LL1C_TASK,
    SLUN_OM_CYCLE_ENTRY_BUTT
};
typedef uint8_t SLUN_OM_CYCLE_SymEntryTypeUint08;
/*
 * 枚举说明: 符号索引 0：sym0 1：sym8
 */
enum SLUN_OM_CYCLE_SymIdx {
    SLUN_OM_CYCLE_SYM_TASK_0     = 0,
    SLUN_OM_CYCLE_SYM_TASK_1,
    SLUN_OM_CYCLE_SYM_IDX_BUTT
};
typedef uint8_t SLUN_OM_CYCLE_SymIdxUint08;

/*
 * 枚举说明: 符号优先级 0：HIGH 1：LOW
 */
enum SLUN_OM_CYCLE_SymPri {
    SLUN_OM_CYCLE_SYM_TASK_HIGH     = 0,
    SLUN_OM_CYCLE_SYM_TASK_LOW,
    SLUN_OM_CYCLE_SYM_TASK_PRI_BUTT
};
typedef uint8_t SLUN_OM_CYCLE_SymPriUint08;

/*
 * 枚举说明: 中断类型
 */
enum SLUN_OM_CYCLE_IntTaskType {
    SLUN_OM_CYCLE_INT_VDL     = 0,
    SLUN_OM_CYCLE_INT_TDL,
    SLUN_OM_CYCLE_INT_TASK_BUTT
};
typedef uint8_t SLUN_OM_CYCLE_IntTaskTypeUint08;
/*
 * 枚举说明: 中断序号 VDL0/1  or TDL EVEN/ODD
 */
enum SLUN_OM_CYCLE_IntIdx {
    SLUN_OM_CYCLE_INT_EVEN_0     = 0,
    SLUN_OM_CYCLE_INT_ODD_1,
    SLUN_OM_CYCLE_INT_IDX_BUTT
};
typedef uint8_t SLUN_OM_CYCLE_IntIdxUint08;


/*
 * 4 STRUCT定义
 */
/*
 * 结构说明: 任务负载统计头结构
 */
typedef struct {
    UPHY_TRACE_Header   header;
    uint32_t            slotHeaderMc;
    uint32_t            dataNum;
} SLUN_TRACE_TaskCycleHeader;

typedef union {
    UPHY_TRACE_TaskData data;
    struct {
        uint32_t                   cycle;
        uint32_t                   startMcTime;
        uint32_t                   endMcTime;
        uint16_t                   sfn;
        uint8_t                    subFrm;
        SLUN_OM_CYCLE_MsgIdUint08  msgId;
    } element;
} SLUN_TRACE_TaskCycleData;

/*
 * 结构说明: 任务负载统计结构体
 */
typedef struct {
    SLUN_TRACE_TaskCycleHeader  header;
    SLUN_TRACE_TaskCycleData    data[SLUN_SCHED_TASK_FUNC_NUM];
} SLUN_OM_TaskCycleRpt;

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
