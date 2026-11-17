/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : pps驱动特性状态机
 * 作    者 : wifi
 * 创建日期 : 2021年3月31日
 */

#include "hmac_pps_fsm.h"
#include "oam_ext_if.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_PPS_FSM_C

void hmac_pps_fsm_handle_event(uint8_t event, hmac_pps_fsm_stru *fsm, uint8_t fsm_type)
{
    uint8_t entry;

    for (entry = 0; entry < fsm->entry_num; entry++) {
        if (fsm->fsm_table[entry].current_state != oal_atomic_read(&g_pps_fsm_atomic_res[fsm_type].current_state) ||
            fsm->fsm_table[entry].event != event) {
            continue;
        }

        if (fsm->fsm_table[entry].action && fsm->fsm_table[entry].action() != OAL_SUCC) {
            break;
        }

        oal_atomic_set(&g_pps_fsm_atomic_res[fsm_type].current_state, fsm->fsm_table[entry].next_state);

        oam_warning_log4(0, OAM_SF_DPA, "{hmac_pps_fsm_handle_event::fsm[%d][0:SWITCH 1:SCH] event[%d][0:H2D 1:D2H] \
            trigger state[%d] to state[%d][0:H 1:D 2:NONE 3-4:H2D ing 5-6:D2H ing][0:TRIGGER 1:LOOP]}",
            fsm->id, event, fsm->fsm_table[entry].current_state, fsm->fsm_table[entry].next_state);
        break;
    }
}

