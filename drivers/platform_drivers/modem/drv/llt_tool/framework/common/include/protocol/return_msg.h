#ifndef ST_RETURN_MSG_H
#define ST_RETURN_MSG_H

#include "stream/memory_io.h"
#include "protocol/func_item.h"
#include "protocol/call_msg.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
Function Return Message Format: Unit(byte)
    ┌───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
    | start_flag | uuid | func_return_code | return_number | return:type *| return:type_len *| return:value *| end_flag |
    |───────────────────────────────────────────────────────────────────────────────────────────────────────────────────|
    | (1)        | 8    | 4                | 1             | 1            | [7bit]            | <-            | (1)     |
    └───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
PS:
    "<-": the value is determined by the value of the previous field.
    "*" : repeat [param_number] times.

*/

// encoding
bool write_return_msg(mem_fd fd, call_msg *cmsg, unsigned int return_code, return_param *param);

#ifdef __cplusplus
}
#endif

#endif