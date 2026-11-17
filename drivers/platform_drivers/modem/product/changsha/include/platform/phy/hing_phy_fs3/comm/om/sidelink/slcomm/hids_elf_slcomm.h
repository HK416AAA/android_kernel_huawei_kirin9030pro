

#ifndef __HIDS_ELF_SLCOMM_H__
#define __HIDS_ELF_SLCOMM_H__

/*
 * 头文件包含
 */
#include "slun_cycle_om_def.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Time Cycle */
#define SLUN_CYCLE_MAIN \
    enum SLUN_OM_CYCLE_MsgId        enCycleMsgId; \
    SLUN_OM_TaskCycleRpt            taskCycleRpt

#ifdef __cplusplus
        }
#endif
#endif /* end of hids_elf_slcomm.c */

