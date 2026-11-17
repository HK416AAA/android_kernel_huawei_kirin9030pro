#ifndef ST_PRE_DEFINE_H
#define ST_PRE_DEFINE_H

#ifdef ST_KERNEL

#include <bsp_print.h>

#define THIS_MODU mod_btest

#define true 1
#define false 0
#ifndef bool
#define bool unsigned char
#endif

#ifndef SEEK_SET
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2
#endif

#define st_info(...) bsp_info(__VA_ARGS__)
#define st_warn(...) bsp_wrn(__VA_ARGS__)
#define st_error(...) bsp_err(__VA_ARGS__)

#elif defined(ST_HIBOOT)
#include <libc.h>
#define st_info(...) cprintf(__VA_ARGS__)
#define st_warn(...) cprintf(__VA_ARGS__)
#define st_error(...) cprintf(__VA_ARGS__)


#else
#include <stdio.h>
#include <stdbool.h>

#define st_info(...) printf(__VA_ARGS__)
#define st_warn(...) printf(__VA_ARGS__)
#define st_error(...) printf(__VA_ARGS__)

#endif

#ifdef ST_DPA
#include <stdio.h>
#define bsp_err(fmt, ...) do { \
    bsp_print("<%d> " fmt, __LINE__, ##__VA_ARGS__); \
} while (0)

#define bsp_info(fmt, ...) do { \
    bsp_print("<%d> " fmt, __LINE__, ##__VA_ARGS__); \
} while (0)
#endif

#endif