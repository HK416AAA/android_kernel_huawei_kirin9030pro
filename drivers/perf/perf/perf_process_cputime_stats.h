
#ifndef PERF_CPU_USAGE_STATS_H
#define PERF_CPU_USAGE_STATS_H

#include <linux/sched.h>

long perf_ioctl_process_cputime(unsigned int cmd, void __user *argp);

#endif

