

/*
 * 1 Other Header File Including
 */
#ifndef __UL1M_HPA_OM_DEF_H__
#define __UL1M_HPA_OM_DEF_H__

#include <stdint.h>

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif

#pragma pack(push, 4)

/*
 * 2 Macro definition
 */

/*
 * 3 Enum definition
 */
enum RTT_HPA_TestMode{
    RTT_HPA_TEST_MODE_DEFAULT,
    RTT_HPA_TEST_MODE_TIME,
    RTT_HPA_TEST_MODE_BUTT
};
typedef uint8_t RTT_HPA_TestModeUint8;

/*
 * 4 Struct definition
 */
/*
 * Struct Description: rtm om ctrl
 */
typedef struct {
    UPHY_OM_ReqEnableUint08     defaultEnable;
    UPHY_OM_ReqEnableUint08     timeEnable;
} UL1M_HPA_OmEnable;

typedef struct {
    uint32_t endFlag;  // just for test now
}RTT_HPA_TestEndRpt;

typedef struct {
    RTT_HPA_TestModeUint8     testMode;
    uint8_t                   rsv1;
    uint8_t                   rsv2;
    uint8_t                   rsv3;
} RTT_HPA_TestModeInitRpt;

/*
 * 5 Union definition
 */
/*
 * 6 Message header definition
 */
/*
 * 7 Message definition
 */
/*
 * 8 Other definition
 */
/*
 * 9 Global variable declarations
 */
/*
 * 10 Function declarations
 */
#pragma pack(pop)

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif


#endif /* #ifndef __UL1M_RTM_OM_DEF_H__ */
