#ifndef ST_FUNC_ITEM_H
#define ST_FUNC_ITEM_H

#include "stream/memory_io.h"

#ifdef __cplusplus
extern "C" {
#endif

/* -------------------------- Call Param Start ------------------------------------ */

typedef struct _st_call_param call_param;

call_param *create_call_param(void);
void destroy_call_param(call_param *param);

bool add_next_call_param(call_param *param, call_param *next_param);
call_param *iter_call_param(call_param *param);

unsigned char *get_call_param_usetype(call_param *param);
unsigned char *get_call_param_type(call_param *param);
unsigned int get_call_param_length(call_param *param);
unsigned char *get_call_param_data(call_param *param);

/* -------------------------- Call Param End -------------------------------------- */

/* -------------------------- Return Param Start ------------------------------------ */

typedef struct _st_return_param {
    unsigned char type;
    unsigned int length;
    unsigned char *data;
} return_param;

int get_type_size(unsigned char type);
bool set_return_param(return_param *param, unsigned char type, unsigned int length, unsigned char *data);

/* -------------------------- Return Param End -------------------------------------- */

/* -------------------------- Func Item Encoding Start ------------------------------------ */

bool write_uuid(mem_fd fd, unsigned char *uuid);
bool write_return_code(mem_fd fd, unsigned int return_code);
bool write_return_param_num(mem_fd fd, unsigned char number);
bool write_return_param(mem_fd fd, return_param *param);
bool write_call_param(mem_fd fd, call_param *param);

/* -------------------------- Func Item Encoding End ------------------------------------ */

/* -------------------------- Func Item Decoding Start ------------------------------------ */

bool read_uuid(mem_fd fd, unsigned char **uuid);
bool read_func_loc(mem_fd fd, unsigned char **func_loc);
bool read_func_name(mem_fd fd, char **func_name);
bool read_return_type(mem_fd fd, unsigned char **type);
bool read_call_param_num(mem_fd fd, unsigned char **number);
bool read_call_param(mem_fd fd, call_param *param);

/* -------------------------- Func Item Decoding End ------------------------------------ */

#ifdef __cplusplus
}
#endif

#endif