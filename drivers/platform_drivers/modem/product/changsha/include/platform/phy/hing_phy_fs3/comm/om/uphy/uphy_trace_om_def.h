

/*
 * 1 Other Header File Including
 */
#ifndef __UPHY_TRACE_OM_DEF_H__
#define __UPHY_TRACE_OM_DEF_H__

#include  "uphy_typedef.h"
#include  "uphy_om_def.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(push, 4)

/*
 * 2 Macro Definition
 */
#define UPHY_TRACE_OM_COMM_ISR_NODE_NUM         64UL
#define UPHY_TRACE_OM_SCHED_TRIGGER_COUNTER_NUM 16UL
#define UPHY_OM_TRACE_NODE_NUM                  128UL
#define UPHY_OM_TRACE_SYMBOL_NUM                2UL

/*
 * 4 Struct Type Definition
 */
/*
 * Struct Description: uphy trace function switch
 */
typedef struct {
    UPHY_OM_ReqEnableUint08       osTaskTraceRptEna;  /* os task trace switch */
} UPHY_OM_TraceSwitch;

/*
 * Struct Description: sched comm isr trace param
 */
typedef struct {
    uint16_t type;
    uint16_t usrId;
    uint32_t usrData;
    uint32_t isrStart; /* comm isr start */
    uint32_t isrEnd;   /* comm isr end */
    uint32_t cbStart;  /* call back start */
    uint32_t cbEnd;    /* call back end */
} UPHY_TRACE_CommIsrParam;

/*
 * Struct Description: comm isr rpt struct
 */
typedef struct {
    uint32_t threadId;
    UPHY_TRACE_CommIsrParam node[UPHY_TRACE_OM_COMM_ISR_NODE_NUM];
} UPHY_Trace_CommIsrRpt;

/*
 * Struct Description: comm isr rpt info
 */
typedef struct {
    uint32_t idx;
    UPHY_Trace_CommIsrRpt rptNode;
} UPHY_TRACE_CommIsrRptInfo;

/*
 * Struct Description: SymbIdxTime
 */
typedef struct {
    uint32_t tsCntStart;
    uint32_t tsCntEnd;
} UPHY_TRACE_TsCnt;

/*
 * Struct Description: om ts count rpt struct
 */
typedef struct {
    uint32_t subFrmNum;
    UPHY_TRACE_TsCnt tsCnt;
} UPHY_OM_TraceTsCntRpt;

/*
 * Struct Description: om trace node
 */
typedef struct {
    uint32_t cCount;
    uint32_t recInfo;
} UPHY_OM_TraceNode;

/*
 * Struct Description: om trace rpt
 */
typedef struct {
    uint32_t threadId;
    UPHY_OM_TraceNode node[UPHY_OM_TRACE_NODE_NUM];
} UPHY_OM_TraceRecRpt;

#pragma pack(pop)

#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif

