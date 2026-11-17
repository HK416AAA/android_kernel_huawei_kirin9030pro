#ifndef ST_REGISTER_FUN_H
#define ST_REGISTER_FUN_H

#ifdef __cplusplus
extern "C" {
#endif

#define FUN_NAME_LEN 50

typedef int (*funptr)(int argc, char **argv);

int register_func(unsigned long long fun_addr, char *fun_name);
long long unsigned int get_fun_addr(char *fun_name);

#define REGIST_FUNCTION(func_addr)                                \
    __attribute__((constructor)) void regist_##func_addr()        \
    {                                                             \
        register_func((unsigned long long)func_addr, #func_addr); \
    }

#ifdef __cplusplus
}
#endif

#endif