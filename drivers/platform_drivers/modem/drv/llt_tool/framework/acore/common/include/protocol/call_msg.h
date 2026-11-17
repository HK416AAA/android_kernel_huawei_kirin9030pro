#ifndef ST_CALL_MSG_H
#define ST_CALL_MSG_H

#include "stream/memory_io.h"
#include "protocol/func_item.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
Function Call Format: Unit(byte)
    ┌─────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
    | (start_flag)     | uuid | func_location | func_name:len | func_name:value | func_return_datatype | param_number |
    |─────────────────────────────────────────────────────────────────────────────────────────────────────────────────|...
    | (  1  )          |  8   | 1             | 7bit[encode]  | <-              | 1                    | 1            |
    └─────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
       ┌─────────────────────────────────────────────────────────────────────────────────┐
       | param: usetype *| param:datatype *| param:type_len  | param:value *| (end_flag) |
    ...|─────────────────────────────────────────────────────────────────────────────────|
       | 1               | 1               | 7bit[encode]    | <-           | (  1  )    |
       └─────────────────────────────────────────────────────────────────────────────────┘
PS:
    "<-": the value is determined by the value of the previous field.
    "*" : repeat [param_number] times.
*/

typedef struct _st_call_msg call_msg;

call_msg *create_call_msg(void);
void destroy_call_msg(call_msg *cmsg);

// decoding
bool read_call_msg(mem_fd fd, call_msg *cmsg);

unsigned char *get_st_uuid(call_msg *cmsg);
unsigned char *get_func_name(call_msg *cmsg);
unsigned char get_return_type(call_msg *cmsg);
unsigned char get_params_num(call_msg *cmsg);
call_param *get_call_params(call_msg *cmsg);

unsigned char *get_uuid_from_buffer(mem_fd fd, unsigned int *size);
unsigned char get_func_loc_from_buffer(mem_fd fd);

#ifdef __cplusplus
}
#endif

#endif