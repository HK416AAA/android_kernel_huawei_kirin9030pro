/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: interface header file
 * Author: plat drivers
 */
#ifndef OAL_INTERRUPT_H
#define OAL_INTERRUPT_H


#define IRQ_RETVAL(x)         ((x) != IRQ_NONE)

#define IRQF_TRIGGER_LOW      0x00000008
#define IRQF_TRIGGER_HIGH     0x00000004
#define IRQF_TRIGGER_FALLING  0x00000002
#define IRQF_TRIGGER_RISING   0x00000001
#define IRQF_TRIGGER_NONE     0x00000000
#define IRQF_TRIGGER_MASK     (IRQF_TRIGGER_HIGH | IRQF_TRIGGER_LOW | \
                               IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING)
#define IRQF_PROBE_SHARED     0x00000100

typedef enum oal_irqreturn {
    IRQ_NONE        = (0U << 0),  /* interrupt was not from this device. */
    IRQ_HANDLED     = (1U << 0),  /* interrupt was handled by this device. */
    IRQ_WAKE_THREAD = (1U << 1)   /* handler requests to wake the handler thread. */
} oal_irqreturn_t;

typedef oal_irqreturn_t (*oal_irq_handler_t)(int, void *);

typedef struct oal_irq_args {
    int         iIrq;
    void        *pDevId;
    const char  *pName;
} oal_irq_args_t;

static inline void oal_free_irq(uint32_t irq, void *dev_id)
{
}

int32_t oal_request_irq(uint32_t irq, oal_irq_handler_t handler, uint32_t flags, const char *name, void *dev);
void oal_enable_irq(uint32_t irq);
void oal_disable_irq(uint32_t irq);


#endif
