/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2018-2025. All rights reserved.
 * ospm_printf.h
 */

#ifndef OSPM_PRINTF
#define OSPM_PRINTF

/*
 * Message printing priorities: printk(KERN_EMERG []
 * LEVEL 0 KERN_EMERG (highest priority)
 * LEVEL 1 KERN_ALERT
 * LEVEL 2 KERN_CRIT
 * LEVEL 3 KERN_ERR
 * LEVEL 4 KERN_WARNING
 * LEVEL 5 KERN_NOTICE
 * LEVEL 6 KERN_INFO
 * LEVEL 7 KERN_DEBUG (Lowest priority)
 */
#define echub_debug(fmt, args...)do { printk(KERN_DEBUG   "[ospm]" fmt, ## args); } while (0)
#define echub_info(fmt, args...) do { printk(KERN_INFO    "[ospm]" fmt, ## args); } while (0)
#define echub_warn(fmt, args...) do { printk(KERN_WARNING "[ospm]" fmt, ## args); } while (0)
#define echub_err(fmt, args...)  do { printk(KERN_ERR     "[ospm]" fmt, ## args); } while (0)

#define NUM_2   2
#define NUM_3   3
#define NUM_4   4
#define NUM_5   5
#define NUM_6   6
#define NUM_8   8
#define NUM_10  10
#define NUM_16  16
#define NUM_24  24
#define NUM_100 100

#endif
