#include <securec.h>

#include "predef.h"
#include "register_fun/fun_reg.h"

#define MAX_FUN_NUM 50

struct fun_info {
    unsigned long long fun_addr;
    char fun_name[FUN_NAME_LEN];
};

static int fun_num = 0;
static struct fun_info funs[MAX_FUN_NUM];

int register_func(unsigned long long fun_addr, char *fun_name)
{
    int name_len = strlen(fun_name);

    if (fun_num >= MAX_FUN_NUM) {
        st_error("register too many fun, need enlarge array\n");
        return -1;
    }
    struct fun_info *new_fun = &funs[fun_num++];
    new_fun->fun_addr = fun_addr;
    int ret = strncpy_s(new_fun->fun_name, FUN_NAME_LEN, fun_name, name_len);
    if (ret) {
        st_error("copy register fun name fail\n");
        return ret;
    }

    return 0;
}

long long unsigned int get_fun_addr(char *fun_name)
{
    int i;
    for (i = 0; i < fun_num; i++) {
        if (strcmp(fun_name, funs[i].fun_name) == 0) {
            return funs[i].fun_addr;
        }
    }
    return 0;
}

