/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: rsicv fault info
 * Author: platform drivers
 */
#include "plat_debug.h"
/* 和 hal/riscv/riscv_common/arch_fault.h保持一致 */
typedef enum {
    OM_INSTRUCTION_ADDRESS_MISALIGNED = 1,
    OM_INSTRUCTION_ACCESS_FAULT,
    OM_ILLEGAL_INSTRUCTION,
    OM_BREAKPOINT,
    OM_LOAD_ADDERSS_MISALIGNED,
    OM_LOAD_ACCESS_FAULT,
    OM_STORE_OR_AMO_ADDRESS_MISALIGNED,
    OM_STORE_OR_AMO_ACCESS_FALUT,
    OM_ENVIRONMENT_CALL_FROM_UMODE,
    OM_ENVIRONMENT_CALL_FROM_SMODE,
    OM_RESERVED_0,
    OM_ENVIRONMENT_CALL_FROM_MMODE,
    OM_INSTRUCTION_PAGE_FAULT,
    OM_LOAD_PAGE_FAULT,
    OM_RESERVED_1,
    OM_STORE_OR_AMO_PAGE_FAULT,
    OM_ASYNCHRONOUS_EXCEPTION,
    OM_NMI_INTERRUPT,
    OM_UNKNOW_FAULT,
} om_fault_type_t;

void cpu_fault_print_exc_info(uint32_t exc_type)
{
    switch (exc_type) {
        case OM_INSTRUCTION_ADDRESS_MISALIGNED:
        case OM_INSTRUCTION_ACCESS_FAULT:
        case OM_ILLEGAL_INSTRUCTION:
            ps_print_err("Instruction fault:%x\n", exc_type);
            break;
        case OM_BREAKPOINT:
            ps_print_err("Breakpoint:%x\n", exc_type);
            break;
        case OM_LOAD_ADDERSS_MISALIGNED:
        case OM_LOAD_ACCESS_FAULT:
            ps_print_err("Load address fault:%x\n", exc_type);
            break;
        case OM_STORE_OR_AMO_ADDRESS_MISALIGNED:
        case OM_STORE_OR_AMO_ACCESS_FALUT:
            ps_print_err("Store/AMO fault:%x\n", exc_type);
            break;
        case OM_ENVIRONMENT_CALL_FROM_UMODE:
        case OM_ENVIRONMENT_CALL_FROM_SMODE:
        case OM_ENVIRONMENT_CALL_FROM_MMODE:
            ps_print_err("Environment call from X-mode:%x\n", exc_type);
            break;
        case OM_INSTRUCTION_PAGE_FAULT:
            ps_print_err("Instruction page fault:%x\n", exc_type);
            break;
        case OM_LOAD_PAGE_FAULT:
            ps_print_err("Load page fault:%x\n", exc_type);
            break;
        case OM_STORE_OR_AMO_PAGE_FAULT:
            ps_print_err("Store or amo page fault:%x\n", exc_type);
            break;
        case OM_NMI_INTERRUPT:
            ps_print_err("NMI-watchdog timeout:%x\n", exc_type);
            break;
        case OM_ASYNCHRONOUS_EXCEPTION:
            ps_print_err("Asynchronous exception:%x\n", exc_type);
            break;
        default:
            ps_print_err("Unknown Fault[%x]\n", exc_type);
    }
}
