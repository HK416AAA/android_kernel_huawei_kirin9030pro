#ifdef ST_KERNEL
#else
#include <string.h>
#endif
#include <securec.h>

#include "predef.h"
#include "protocol/proto_enum.h"
#include "protocol/call_msg.h"

struct _st_call_msg {
    unsigned char *uuid;
    unsigned char *func_loc;
    char *func_name;
    unsigned char *return_type;
    unsigned char *param_number;
    call_param *params;
};

call_msg *create_call_msg(void)
{
    call_msg *cmsg = (call_msg *)get_default_allocator()->alloc(sizeof(call_msg));
    if (cmsg == NULL) {
        st_error("cmsg alloc fail\n");
        return NULL;
    }
    cmsg->uuid = NULL;
    cmsg->func_loc = NULL;
    cmsg->func_name = NULL;
    cmsg->return_type = NULL;
    cmsg->param_number = NULL;
    cmsg->params = NULL;
    return cmsg;
}

void destroy_call_msg(call_msg *cmsg)
{
    call_param *current_param = NULL;
    call_param *next_param = NULL;

    if (cmsg == NULL) {
        return;
    }

    current_param = cmsg->params;

    while (current_param != NULL) {
        next_param = iter_call_param(current_param);
        destroy_call_param(current_param);
        current_param = next_param;
    }
    get_default_allocator()->free(cmsg);
}

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

static bool _add_call_param(call_msg *cmsg, call_param *param)
{
    call_param *current_param = cmsg->params;
    call_param *pre_param = NULL;
    while (current_param) {
        pre_param = current_param;
        current_param = iter_call_param(current_param);
    }
    if (pre_param == NULL) {
        cmsg->params = param;
    }
    else {
        add_next_call_param(pre_param, param);
    }
    return true;
}

bool read_call_msg(mem_fd fd, call_msg *cmsg)
{
    int i;

    if (!_check_params(fd, cmsg)) {
        return false;
    }

    if (!read_uuid(fd, &cmsg->uuid) ||
        !read_func_loc(fd, &cmsg->func_loc) ||
        !read_func_name(fd, &cmsg->func_name) ||
        !read_return_type(fd, &cmsg->return_type) ||
        !read_call_param_num(fd, &cmsg->param_number)) {
        st_error("read call_msg before param failed\n");
        return false;
    }

    for (i = 0; i < *cmsg->param_number; i++) {
        call_param *param = create_call_param();
        if (param == NULL) {
            return false;
        }
        if (!read_call_param(fd, param) || !_add_call_param(cmsg, param)) {
            destroy_call_param(param);
            return false;
        }
    }
    return true;
}

unsigned char *get_st_uuid(call_msg *cmsg)
{
    return (cmsg == NULL) ? NULL : cmsg->uuid;
}

unsigned char *get_func_name(call_msg *cmsg)
{
    return (cmsg == NULL) ? NULL : (unsigned char *)cmsg->func_name;
}

unsigned char get_return_type(call_msg *cmsg)
{
    return (cmsg == NULL || cmsg->return_type == NULL) ? 0 : *(cmsg->return_type);
}

unsigned char get_params_num(call_msg *cmsg)
{
    return (cmsg == NULL || cmsg->param_number == NULL) ? 0 : *(cmsg->param_number);
}

call_param *get_call_params(call_msg *cmsg)
{
    return (cmsg == NULL) ? NULL : cmsg->params;
}

unsigned char *get_uuid_from_buffer(mem_fd fd, unsigned int *size)
{
    unsigned char *buffer;

    if (fd == NULL) {
        st_error("fd is NULL for uuid\n");
        return NULL;
    }
    buffer = get_buffer_data(get_mem_buffer(fd));
    if (buffer == NULL) {
        st_error("get buffer from fd for uuid failed\n");
        return NULL;
    }
    *size = ST_UUID_SIZE;
    return buffer; // 校验数据是否包含uuid
}

unsigned char get_func_loc_from_buffer(mem_fd fd)
{
    unsigned char *buffer;

    if (fd == NULL) {
        st_error("fd is NULL for func_loc\n");
        return (unsigned char)(-1);
    }
    buffer = get_buffer_data(get_mem_buffer(fd));
    if (buffer == NULL) {
        st_error("get buffer from fd for uuid failed\n");
        return (unsigned char)(-1);
    }
    return *(unsigned char *)(buffer + ST_UUID_SIZE); // 校验数据是否包含func_loc
}
