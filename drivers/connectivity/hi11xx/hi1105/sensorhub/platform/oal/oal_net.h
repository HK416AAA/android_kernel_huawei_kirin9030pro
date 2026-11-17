/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: platform_utils.c header file
 * Author: plat drivers
 */

#ifndef __PLATFORM_UTILS_H__
#define __PLATFORM_UTILS_H__

/* 其他头文件包含 */
#include "plat_type.h"
#include "sh_utils.h"
#include "hal_gpio.h"
#include "hal_uart.h"
#include "uart.h"

#define max_t(type, a, b) max(((type) (a)), ((type) (b)))

/* 内存相关接口 */
#define GFP_KERNEL    (0)
#define GFP_ATOMIC    (0)
void *oal_kmalloc(size_t size, int flags);
void *oal_kzalloc(size_t size, int flags);
void *oal_vmalloc(size_t size);
void oal_kfree(void *ptr);
void oal_vfree(void *ptr);
void *oal_large_malloc(uint32_t size);
void oal_large_free(void *ptr);
int32_t oal_get_ddr_vote_cnt(void);
/* netbuf消息相关接口 */
#define SMP_CACHE_BYTES 32
#define OAL_NETBUF_DATA_ALIGN(X) (((X) + (SMP_CACHE_BYTES - 1)) & ~(SMP_CACHE_BYTES - 1))
#define WRITE_ONCE(x, val)						        \
    do {									            \
        *(volatile typeof(x) *)&(x) = (val);			\
    } while (0)

struct sk_buff_head {
    struct sk_buff      *next;
    struct sk_buff      *prev;
    unsigned int        qlen;
};

struct sk_buff {
    struct sk_buff      *next;
    struct sk_buff      *prev;
    struct sk_buff_head *list;
    unsigned char       *head;
    unsigned char       *data;
    unsigned char       *tail;
    unsigned char       *end;
    unsigned int        len;
};

typedef struct sk_buff oal_netbuf_stru;
typedef struct sk_buff_head oal_netbuf_head_stru;

static inline void oal_netbuf_queue_head_init(struct sk_buff_head *list)
{
    list->prev = list->next = (oal_netbuf_stru *)list;
    list->qlen = 0;
}

static inline uint32_t oal_netbuf_queue_len(const struct sk_buff_head *list_)
{
    return list_->qlen;
}

static inline int oal_netbuf_queue_empty(const struct sk_buff_head *list)
{
    return list->next == (const oal_netbuf_stru *) list;
}

oal_netbuf_stru *oal_netbuf_alloc(unsigned int size, int gfp_mask);
void oal_netbuf_free(oal_netbuf_stru *pst_netbuf);
void *oal_netbuf_put(oal_netbuf_stru *pst_netbuf, unsigned int len);
void *oal_netbuf_pull(oal_netbuf_stru *pst_netbuf, unsigned int len);
oal_netbuf_stru *oal_netbuf_dequeue(struct sk_buff_head *list);
oal_netbuf_stru *oal_netbuf_dequeue_tail(struct sk_buff_head *list);
void oal_netbuf_queue_head(struct sk_buff_head *list, oal_netbuf_stru *newsk);
void oal_netbuf_queue_tail(struct sk_buff_head *list, oal_netbuf_stru *newsk);
unsigned char *oal_netbuf_tail_pointer(const oal_netbuf_stru *pst_netbuf);
int oal_netbuf_tailroom(const oal_netbuf_stru *pst_netbuf);
void oal_netbuf_queue_purge(struct sk_buff_head *list);

/* gpio相关接口适配 */
static inline int gpio_request(unsigned gpio, const char *label)
{
    return 0;
}

static inline int gpio_request_one(unsigned gpio, unsigned long flags, const char *label)
{
    return 0;
}

static inline void gpio_free(unsigned gpio)
{
}

static inline int gpio_direction_input(uint32_t gpio)
{
    hal_gpio_direction_input(gpio);
    return 0;
}

static inline int gpio_direction_output(uint32_t gpio, int value)
{
    hal_gpio_direction_output(gpio);
    hal_gpio_set_value(gpio, value);
    return 0;
}

static inline int gpio_get_value(uint32_t gpio)
{
    return hal_gpio_get_value(gpio);
}

static inline void gpio_set_value(uint32_t gpio, int value)
{
    hal_gpio_set_value(gpio, value);
}

static inline int32_t gpio_to_irq(uint32_t gpio)
{
    return hal_gpio_to_irq(gpio);
}

/* 适配tty结构体 */

struct tty_operations {
    int (*write)(struct bus* bus, char* buf, int len, int type);
    int (*read)(struct bus* bus, char* buf, int len, int type);
    int (*change_baud_rate)(struct bus* bus, uint32_t baud_rate, uint8_t enable_flowctl);
};

struct tty_struct {
    struct bus *bus;
    struct uart_adapter *adapter;
    uint32_t baud_rate;
    uint8_t uart;
    uint8_t flow_cntrl;
};

#endif /* end of oal_net.h */