#ifndef __HCK_MERGEIRQ__
#define __HCK_MERGEIRQ__

#include <linux/types.h>
#include <linux/kernel_stat.h>
#include <platform_include/basicplatform/linux/hck_vendor_hooks.h>


DECLARE_HCK_VH(clear_period_divisor,
	TP_PROTO(unsigned int cpu),
	TP_ARGS(cpu));

DECLARE_HCK_VH(set_evt_based_on_divisor,
	TP_PROTO(u32 arch_timer_rate, unsigned long *evt),
	TP_ARGS(arch_timer_rate, evt));


#endif /* __HCK_MERGEIRQ__ */
