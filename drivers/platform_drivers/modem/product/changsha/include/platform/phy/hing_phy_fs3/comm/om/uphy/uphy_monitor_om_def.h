

/*
 * 1 Other Header File Including
 */
#ifndef __UPHY_MONITOR_OM_DEF_H__
#define __UPHY_MONITOR_OM_DEF_H__

#include  "uphy_typedef.h"
#include  "uphy_om_def.h"
#include  "uphy_core_interface.h"
#if (UPHY_CPU_ARCH == UPHY_TSP)
#include  "uphy_task_interface.h"
#endif

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack()

/*
 * 2 Macro Definition
 */
#define UPHY_OM_TSP_SP_PEAK_USE_INFO_NUM       32UL
#define UPHY_OM_PSA_SP_PEAK_USE_INFO_NUM       1UL

#define UPHY_OM_TSP_PMU_EVENT_NUM              11UL
#define UPHY_OM_STUB_REG_NUM                   8UL
/*
 * 4 Struct Type Definition
 */
/*
 * Struct Description: freq om switch
 */
typedef struct {
    uint16_t                      freqRptPeriod;        /* 10ms unit */
    UPHY_OM_ReqEnableUint08       freqInfoEna;          /* freq info switch */
    uint8_t                       rsv[1];
} UPHY_OM_FreqSwitch;
/*
 * Struct Description: latencym om switch
 */
typedef struct {
    uint16_t                       latencymEna;          /* latencym info switch */
    uint16_t                       freq;
} UPHY_OM_LatencymSwitch;

/*
 * Struct Description: cpu load om switch
 */
typedef struct {
    uint16_t                      cpuLoadCalcPeriod;  /* cpu load calc task time period, 10ms unit */
    UPHY_OM_ReqEnableUint08       cpuLoadEna;           /* cpu load switch */
    uint8_t                       rsv[1];
} UPHY_OM_CpuLoadSwitch;

/*
 * Struct Description: sp peak used om switch
 */
typedef struct {
    UPHY_OM_ReqEnableUint08       spPeakUseInfoEna;     /* task sp peak use rpt */
    UPHY_OM_ReqEnableUint08       spUseWarningEna;  /* detect sp used over level task */
    uint8_t                       rsv[2];
} UPHY_OM_SpPeakUseSwitch;

/*
 * Struct Description: UPHY_OM_StubRegPara
 */
typedef struct {
    uint32_t rwType;
    uint32_t addr;
    uint32_t lenOrValue;
} UPHY_OM_StubRegPara;

/*
 * Struct Description: UPHY_OM_StubRegSwitch
 */
typedef struct {
    uint8_t                       stubIndex;
    uint8_t                       enableFlag;
    uint8_t                       cmdCnt;
    uint8_t                       rsv;
    UPHY_OM_StubRegPara           stubRegPara[UPHY_OM_STUB_REG_NUM];
} UPHY_OM_StubRegSwitch;

/*
 * Struct Description: UPHY_OM_StubRegRecord
 */
typedef struct {
    uint16_t                      enableFlag;
    uint16_t                      cmdCnt;
    UPHY_OM_StubRegPara           stubRegPara[UPHY_OM_STUB_REG_NUM];
} UPHY_OM_StubRegRecord;

/*
 * Struct Description: tsp freq report
 */
typedef struct {
    uint8_t  threadId;
    uint8_t  ddrActFreqProfile;
    uint16_t ddrActFreqMHz;
    uint16_t ddrExpFreqMHz;
    uint16_t cpuActFreqMHz;
} UPHY_OM_TspFreqRpt;

/*
 * Struct Description: psa freq report
 */
typedef struct {
    uint16_t  threadId;
    uint16_t  cpuActFreqMHz;
} UPHY_OM_PsaFreqRpt;

/*
 * Struct Description: cpu load report
 */
typedef struct {
    uint16_t cpuFreqMHz;
    uint8_t threadId;
    uint8_t cpuLoadPercent;
} UPHY_OM_CpuLoadRpt;

/*
 * Enum Description: sp peak used info
 */
typedef struct {
    union {
        uint8_t taskId;
        uint8_t threadId;
    } spId;
    uint8_t  type;
    uint16_t peakUsed;
} UPHY_OM_SpPeakUsedInfo;

/*
 * Struct Description: sp peak use report struct
 */
typedef struct {
    uint32_t num;
    UPHY_OM_SpPeakUsedInfo spPeakUseInfo[UPHY_OM_TSP_SP_PEAK_USE_INFO_NUM];
} UPHY_OM_TspSpPeakUseInfoRpt;

typedef struct {
    uint32_t num;
    UPHY_OM_SpPeakUsedInfo spPeakUseInfo[UPHY_OM_PSA_SP_PEAK_USE_INFO_NUM];
} UPHY_OM_PsaSpPeakUseInfoRpt;


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif

