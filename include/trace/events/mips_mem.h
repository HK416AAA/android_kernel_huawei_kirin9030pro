#undef TRACE_SYSTEM
#define TRACE_SYSTEM mips_mem

#if !defined(_TRACE_MIPS_MEM_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_MIPS_MEM_H

TRACE_EVENT(check_mips_mem_freq_change,
	TP_PROTO(int cpu, const char *name, u64 inst, u64 cycle, u64 core_freq,
		 int refill, int ratio, int freq),

	TP_ARGS(cpu, name, inst, cycle, core_freq, refill, ratio, freq),

	TP_STRUCT__entry(
		__field(	int,	cpu			)
		__array(	char,	name,	16		)
		__field(	u64,	inst			)
		__field(	u64,    cycle			)
		__field(	u64,	core_freq		)
		__field(	u64,	refill			)
		__field(	int,	ratio			)
		__field(	int,	freq			)
	),

	TP_fast_assign(
		__entry->cpu     = cpu;
		strncpy(__entry->name, name, 16);
		__entry->name[15]  = '\0';
		__entry->inst      = inst;
		__entry->cycle     = cycle;
		__entry->core_freq = core_freq;
		__entry->refill    = refill;
		__entry->ratio     = ratio;
		__entry->freq      = freq;
	),
	TP_printk("cpu=%d %s inst=%llu, cycle=%llu refill=%llu "
		  "core_freq=%llu ratio=%d freq=%d",
		  __entry->cpu, __entry->name, __entry->inst, __entry->cycle, __entry->refill,
		  __entry->core_freq, __entry->ratio, __entry->freq)
);
#endif /* _TRACE_CPUFREQ_MIPS_H */

/* This part must be outside protection */
#include <trace/define_trace.h>
