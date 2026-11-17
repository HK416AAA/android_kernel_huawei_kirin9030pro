/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#include "hm_os_sys.h"
#include <securec.h>

void sys_log_print(const char *msg)
{
    pr_info("[touchpad goodix] %s", msg);
}

void sys_delay_ms(int ms)
{
    msleep(ms);
}

int dev_i2c_read(int reg, u8 *data, int len);
int dev_i2c_write(int reg, const u8 *data, int len);

int sys_reg_read(u32 addr, u8 *buf, int len)
{
    return dev_i2c_read(addr, buf, len);
}

int sys_reg_write(u32 addr, const u8 *buf, int len)
{
    return dev_i2c_write(addr, buf, len);
}


void *sys_malloc(u32 size)
{
    void *buf;

    buf = MALLOC(size);
    memset_s(buf, size, 0, size);
    return buf;
}

void sys_free(void *buf)
{
    if (buf != (void *)0) {
        FREE(buf);
    }
}
