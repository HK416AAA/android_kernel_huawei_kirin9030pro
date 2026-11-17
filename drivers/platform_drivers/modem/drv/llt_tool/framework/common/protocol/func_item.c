#ifdef ST_KERNEL
#else
#include <string.h>
#endif
#include <securec.h>
#include "predef.h"
#include "protocol/proto_enum.h"
#include "protocol/func_item.h"

#define MAX_OUT_PARAM_BUFFER_SIZE 512

struct _st_call_param {
    unsigned char *usetype;
    unsigned char *type;
    unsigned int length;
    unsigned char *data;
    struct _st_call_param *next;
};

call_param *create_call_param(void)
{
    call_param *param = (call_param *)get_default_allocator()->alloc(sizeof(call_param));
    if (param == NULL) {
        st_error("call param alloc fail\n");
        return NULL;
    }

    param->usetype = NULL;
    param->type = NULL;
    param->length = 0;
    param->data = NULL;
    param->next = NULL;
    return param;
}

void destroy_call_param(call_param *param)
{
    if (param == NULL) {
        return;
    }
    get_default_allocator()->free(param);
}

bool add_next_call_param(call_param *param, call_param *next_param)
{
    if (param == NULL) {
        return false;
    }
    param->next = next_param;
    return true;
}

call_param *iter_call_param(call_param *param)
{
    return (param == NULL) ? NULL : param->next;
}

unsigned char *get_call_param_usetype(call_param *param)
{
    return (param == NULL) ? NULL : param->usetype;
}

unsigned char *get_call_param_type(call_param *param)
{
    return (param == NULL) ? NULL : param->type;
}

unsigned int get_call_param_length(call_param *param)
{
    return (param == NULL) ? 0 : param->length;
}

unsigned char *get_call_param_data(call_param *param)
{
    return (param == NULL) ? NULL : param->data;
}

int type_size[ST_TYPE_MAX] = 
{
    0, 1, 
    sizeof(char), sizeof(unsigned char),
    sizeof(short), sizeof(unsigned short),
    sizeof(int), sizeof(unsigned int),
    sizeof(long long), sizeof(unsigned long long),
    sizeof(float), sizeof(double), 
    0, 0
};

int get_type_size(unsigned char type)
{
    return type < ST_TYPE_MAX ? type_size[type] : 0;
}

bool set_return_param(return_param *param, unsigned char type, unsigned int length, unsigned char *data)
{
    if (param == NULL) {
        st_error("return param is NULL in set func");
        return false;
    }
    param->type = type;
    param->length = length;
    param->data = data;
    return true;
}

bool write_uuid(mem_fd fd, unsigned char *uuid)
{
    return write_raw_data(fd, uuid, ST_UUID_SIZE);
}

bool write_return_code(mem_fd fd, unsigned int return_code)
{
    return write_uint(fd, return_code);
}

bool write_return_param_num(mem_fd fd, unsigned char number)
{
    return write_uchar(fd, number);
}

bool write_return_param(mem_fd fd, return_param *param)
{
    if (param == NULL) {
        st_error("return param is NULL\n");
        return false;
    }

    if (!write_uchar(fd, param->type) ||
        !write_7bit_int(fd, param->length) ||
        !write_raw_data(fd, param->data, param->length)) {
        st_error("write return param failed\n");
        return false;
    }
    return true;
}

bool write_call_param(mem_fd fd, call_param *param)
{
    if (param == NULL) {
        st_error("return param is NULL\n");
        return false;
    }
    if (*(param->usetype) == IN_PARAM) {
        return true;
    }

    if (!write_uchar(fd, *(param->type)) ||
        !write_7bit_int(fd, param->length) ||
        !write_raw_data(fd, param->data, param->length)) {
        st_error("write return param failed\n");
        return false;
    }

    return true;
}


static unsigned char *_tell_addr(mem_fd fd)
{
    unsigned int pos = tell_p(fd);
    unsigned char *start_addr = get_buffer_data(get_mem_buffer(fd));
    if (start_addr == NULL) {
        return NULL;
    }

    return start_addr + pos;
}

static bool _read_func_item(mem_fd fd, void **pitem, unsigned int size)
{
    *pitem = (void*)_tell_addr(fd);
    if (*pitem == NULL) {
        return false;
    }
    return io_seek(fd, tell_p(fd) + size, SEEK_SET);
}

bool read_uuid(mem_fd fd, unsigned char **uuid)
{
    return _read_func_item(fd, (void**)uuid, ST_UUID_SIZE);
}

bool read_func_loc(mem_fd fd, unsigned char **func_loc)
{
    return _read_func_item(fd, (void**)func_loc, sizeof(unsigned char));
}

bool read_func_name(mem_fd fd, char **func_name)
{
    unsigned int length = 0;
    if (!read_7bit_int(fd, &length)) {
        st_error("read func_name length failed\n");
        return false;
    }

    return _read_func_item(fd, (void**)func_name, length);
}

bool read_return_type(mem_fd fd, unsigned char **type)
{
    return _read_func_item(fd, (void**)type, sizeof(unsigned char));
}

bool read_call_param_num(mem_fd fd, unsigned char **number)
{
    return _read_func_item(fd, (void**)number, sizeof(unsigned char));
}

bool read_call_param(mem_fd fd, call_param *param)
{
    if (param == NULL) {
        st_error("call param is NULL\n");
        return false;
    }

    if (!_read_func_item(fd, (void**)&param->usetype, sizeof(unsigned char)) ||
        !_read_func_item(fd, (void**)&param->type, sizeof(unsigned char)) ||
        !read_7bit_int(fd, &param->length)) {
        st_error("read return param failed\n");
        return false;
    }

    if (param->length != 0) {
        return _read_func_item(fd, (void**)&param->data, param->length);
    }
    return true;
}
