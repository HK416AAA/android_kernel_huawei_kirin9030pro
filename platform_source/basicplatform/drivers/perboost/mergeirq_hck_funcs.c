#include <linux/percpu.h>
#include <linux/uaccess.h>
#include <platform_include/basicplatform/linux/hck/mergeirq/hck_mergeirq.h>

#ifdef CONFIG_MERGE_TIMER_IRQ
DECLARE_PER_CPU(int, period_divisor);
#endif

static void hck_clear_period_divisor(unsigned int cpu)
{
#ifdef CONFIG_MERGE_TIMER_IRQ
	if (*per_cpu_ptr(&period_divisor, cpu) != 0)
		*per_cpu_ptr(&period_divisor, cpu)  = 0;

#endif
}

static void hck_set_evt_based_on_divisor(u32 arch_timer_rate, unsigned long *evt)
{
#ifdef CONFIG_MERGE_TIMER_IRQ
	int divisor = *this_cpu_ptr(&period_divisor);
	if (divisor != 0)
		*evt = arch_timer_rate / MSEC_PER_SEC / divisor;
#endif
}

static int __init mergeirq_hck_init(void)
{
	REGISTER_HCK_VH(clear_period_divisor, hck_clear_period_divisor);
	REGISTER_HCK_VH(set_evt_based_on_divisor, hck_set_evt_based_on_divisor);
	return 0;
}
early_initcall(mergeirq_hck_init);

