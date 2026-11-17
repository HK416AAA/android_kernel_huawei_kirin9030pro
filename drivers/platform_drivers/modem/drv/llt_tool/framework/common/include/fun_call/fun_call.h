#ifndef ST_FUN_CALL_H
#define ST_FUN_CALL_H

#include "protocol/call_msg.h"

#ifdef __cplusplus
extern "C" {
#endif


int handle_input_stream(char *buff, int size);
int get_call_msg(call_msg **pcmsg, char *buff, int size);

#ifdef __cplusplus
}
#endif

#endif