#include <securec.h>

#include "predef.h"
#include "protocol/call_msg.h"
#include "protocol/func_item.h"
#include "protocol/proto_enum.h"
#include "protocol/return_msg.h"
#include "return_code.h"
#include "stream/memory_io.h"

#ifdef __nocfi
#define NOCFI __nocfi
#else
#define NOCFI
#endif

#if defined(ST_CCORE)
#define PARAM_TYPE int
#else
#define PARAM_TYPE long long
#endif

#define THIS_MODU mod_btest

#define MAX_PARA_NUM 6

typedef PARAM_TYPE (*fun_call_ptr)(PARAM_TYPE arg1, ...);
typedef PARAM_TYPE (*fun_call_ptr0)(void);

extern long long unsigned int get_fun_addr(char *fun_name);
extern int add_return_msg(char *buff, int size);

static int get_fcall_param(call_msg *cmsg, PARAM_TYPE params[], int pnum)
{
    call_param *ppara = get_call_params(cmsg);
    int i = 0;

    if (pnum < 0 || pnum > MAX_PARA_NUM) {
        st_error("param number error\n");
        return -1;
    }

    while (ppara) {
        if (*get_call_param_usetype(ppara) != IN_PARAM ||
            *get_call_param_type(ppara) == ST_STRING ||
            *get_call_param_type(ppara) == ST_BYTE_ARRAY) {
            params[i] = (PARAM_TYPE)get_call_param_data(ppara);
        }
        else {
            memcpy_s(&params[i], sizeof(PARAM_TYPE),
                     get_call_param_data(ppara),
                     get_call_param_length(ppara));
        }

        ppara = iter_call_param(ppara);
        i++;
    }
    return 0;
}

static int NOCFI fun_call(call_msg *cmsg, PARAM_TYPE *fun_ret)
{
    long long unsigned int addr;
    fun_call_ptr fun;
    PARAM_TYPE params[MAX_PARA_NUM] = {0};
    int ret;
    int para_num;

    unsigned char *func_name = get_func_name(cmsg);
    addr = get_fun_addr((char *)func_name);
    if (addr == 0) {
        st_error("get fun %s error, addr = NULL\n", func_name);
        return FUNC_NAME_NOT_FOUND;
    }
    fun = (fun_call_ptr)addr;

    para_num = get_params_num(cmsg);
    ret = get_fcall_param(cmsg, params, para_num);
    if (ret) {
        st_error("parse cmsg failed\n");
        return PARAM_NUMS_ERROR;
    }

    if (para_num == 0) {
        *fun_ret = ((fun_call_ptr0)fun)();
    }
    else if (para_num == 1) {
        *fun_ret = fun(params[0]);
    }
    else if (para_num == 2) {
        *fun_ret = fun(params[0], params[1]);
    }
    else if (para_num == 3) {
        *fun_ret = fun(params[0], params[1], params[2]);
    }
    else if (para_num == 4) {
        *fun_ret = fun(params[0], params[1], params[2], params[3]);
    }
    else if (para_num == 5) {
        *fun_ret = fun(params[0], params[1], params[2], params[3], params[4]);
    }
    else {
        *fun_ret = fun(params[0], params[1], params[2], params[3], params[4], params[5]);
    }

    return 0;
}

int get_call_msg(call_msg **pcmsg, char *buff, int size)
{
    int ret = 0;
    stream_buffer buf;
    mem_fd sock_rfd;

    buf = create_buffer_from_bytes((unsigned char *)buff, size);
    if (buf == NULL) {
        st_error("create buffer failed\n");
        ret = -1;
        goto free_buffer;
    }

    *pcmsg = create_call_msg();
    if (*pcmsg == NULL) {
        st_error("create_call_msg failed\n");
        ret = -1;
        goto free_buffer;
    }

    sock_rfd = open_r(buf);
    if (sock_rfd == NULL) {
        st_error("open_r failed\n");
        ret = -1;
        goto free_sock_rfd;
    }

    if (!read_call_msg(sock_rfd, *pcmsg)) {
        st_error("read_call_msg failed\n");
        ret = -1;
        goto free_sock_rfd;
    }

free_sock_rfd:
    close_memory_io(sock_rfd);
free_buffer:
    detach_buffer(buf);
    destroy_buffer(buf);

    if (ret) {
        destroy_call_msg(*pcmsg);
    }
    return ret;
}

static int add_fun_ret(call_msg *cmsg, PARAM_TYPE fun_ret, unsigned int return_code)
{
    int ret = 0;
    return_param rparam;
    unsigned char rtype;
    stream_buffer return_buffer;
    mem_fd sock_wfd;

    rtype = get_return_type(cmsg);
    if (!return_code) {
        if (rtype == ST_STRING) {
            unsigned char *rdata = (unsigned char *)fun_ret;
            set_return_param(&rparam, rtype,
                             strlen((const char *)rdata) + 1,
                             rdata);
        }
        else {
            set_return_param(&rparam, rtype,
                             get_type_size(rtype),
                             (unsigned char *)&fun_ret);
        }
    }

    return_buffer = create_buffer();
    if (return_buffer == NULL) {
        st_error("create stream_buffer failed\n");
        ret = -1;
        goto free_return_buff;
    }

    sock_wfd = open_w(return_buffer);
    if (sock_wfd == NULL) {
        st_error("open sock wfd failed\n");
        ret = -1;
        goto free_sock_wfd;
    }

    if (!write_return_msg(sock_wfd, cmsg, return_code, &rparam)) {
        st_error("write return msg failed\n");
        ret = -1;
        goto free_sock_wfd;
    }

    ret = add_return_msg((char *)get_buffer_data(return_buffer),
                         get_buffer_length(return_buffer));
    if (ret) {
        st_error("add return msg failed\n");
    }

free_sock_wfd:
    close_memory_io(sock_wfd);
free_return_buff:
    destroy_buffer(return_buffer);

    if (!return_code && rtype == ST_STRING) {
#ifdef ST_KERNEL
        get_default_allocator()->free((const void *)fun_ret);
#else
        get_default_allocator()->free((void *)fun_ret);
#endif
    }
    return ret;
}

int handle_input_stream(char *buff, int size)
{
    int ret;
    call_msg *cmsg = NULL;
    PARAM_TYPE fun_ret = 0;
    unsigned int return_code = 0;

    ret = get_call_msg(&cmsg, buff, size);
    if (ret) {
        st_error("get call msg failed\n");
        return ret;
    }

    return_code = fun_call(cmsg, &fun_ret);

    ret = add_fun_ret(cmsg, fun_ret, return_code);
    if (ret) {
        st_error("add fun ret failed\n");
    }

    destroy_call_msg(cmsg);

    return ret;
}