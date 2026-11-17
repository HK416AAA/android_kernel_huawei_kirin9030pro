#ifdef ST_KERNEL
#else
#include <string.h>
#endif

#include "predef.h"
#include "protocol/proto_enum.h"
#include "protocol/func_item.h"
#include "protocol/return_msg.h"

static bool _check_params(mem_fd fd, call_msg *cmsg)
{
    if (fd == NULL) {
        st_error("fd is NULL\n");
        return false;
    }
    if (cmsg == NULL) {
        st_error("cmsg is NULL\n");
        return false;
    }
    return true;
}

static bool _write_return_number(mem_fd fd, call_msg *cmsg)
{
    unsigned char number = 1;
    call_param *current_param = get_call_params(cmsg);
    call_param *next_param = NULL;
    while (current_param != NULL) {
        unsigned char *usetype = get_call_param_usetype(current_param);
        next_param = iter_call_param(current_param);
        current_param = next_param;
        if (*usetype == IN_PARAM) {
            continue;
        }
        number++;
    }

    if (!write_return_param_num(fd, number)) {
        st_error("write return_number failed\n");
        return false;
    }
    return true;
}

bool write_return_msg(mem_fd fd, call_msg *cmsg, unsigned int return_code, return_param *param)
{
    call_param *current_param = get_call_params(cmsg);
    call_param *next_param = NULL;

    if (!_check_params(fd, cmsg)) {
        return false;
    }

    if (!write_uuid(fd, get_st_uuid(cmsg))) {
        st_error("write uuid failed\n");
        return false;
    }
    if (!write_return_code(fd, return_code)) {
        st_error("write return_code failed\n");
        return false;
    }
    if (!_write_return_number(fd, cmsg)) {
        st_error("write return_number failed\n");
        return false;
    }
    if (!write_return_param(fd, param)) {
        st_error("write return_param failed\n");
        return false;
    }

    while (current_param != NULL) {
        if (!write_call_param(fd, current_param)) {
            st_error("write param failed\n");
            return false;
        }
        next_param = iter_call_param(current_param);
        current_param = next_param;
    }

    return true;
}
