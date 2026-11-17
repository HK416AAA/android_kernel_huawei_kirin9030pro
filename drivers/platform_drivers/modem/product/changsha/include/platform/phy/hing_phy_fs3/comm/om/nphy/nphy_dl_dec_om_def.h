

#ifndef __NPHY_DL_DEC_OM_DEF_H__
#define __NPHY_DL_DEC_OM_DEF_H__


/*
 * 1 其他头文件包含
 */
#include "nphy_dl_dec_pds_om_def.h"               //lint !e537
#include "nphy_dl_dec_pdc_om_def.h"               //lint !e537
#include "nphy_hal_dem_comm_interface.h"

#ifdef __cplusplus
#if __cplusplus
    extern "C"{
#endif
#endif /* __cplusplus */

enum NPHY_DEC_FALSE_ALARM_RPT_TYPE {
    NPHY_DEC_PRE_FAKE_ALRAM    = 0,
    NPHY_DEC_PARSE_FAKE_ALRAM  = 1,
};
typedef uint8_t NPHY_DEC_OmFalseAlarmRptTypeUint8;

typedef struct {
    NPHY_DEC_PreWarnTypeUint8       preFakeIdx[4];
} NPHY_DEC_OmPreWranRptReg;

typedef struct {
    NPHY_DEC_OmPreWranRptReg        preWranRptReg[4];
    DciPwrReg                       dciPwrReg[8];
} NPHY_DEC_OmPreFake;

typedef struct {
    NPHY_DEC_PdeWarnTypeUint8       pdeWarnType;
    uint8_t                         rsv[3];
    DspBypass5                      dspBypass5;                          /* 20 */
    NpdcDecRptInfo                  decRptInfo;
    NpdcDecRptData0                 decRptData0;
    NpdcDecRptData1                 decRptData1;
    NpdcDecRptData2                 decRptData2;
    NpdcDecRptData3                 decRptData3;
    NpdcDecRptData4                 decRptData4;
} NPHY_DEC_OmParseFake;

typedef union {
    NPHY_DEC_OmPreFake              preFake;
    NPHY_DEC_OmParseFake            parseFake;
} NPHY_DEC_OmFakeInfo;

typedef struct {
    NPHY_DEC_OmFalseAlarmRptTypeUint8   fakeType;
    uint8_t                             pdcEndSymb;
    uint8_t                             slot;
    uint8_t                             rsv;
    NPHY_DEC_OmFakeInfo                 fakeInfo;
} NPHY_DEC_OmPdeFalseAlarm;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __NPHY_DL_DEC_OM_DEF_H__ */


