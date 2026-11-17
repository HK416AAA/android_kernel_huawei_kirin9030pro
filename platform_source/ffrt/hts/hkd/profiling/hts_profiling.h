#ifndef __HTS_PROFILING_H
#define __HTS_PROFILING_H

#include <linux/types.h>

enum hts_dump_info {
	HTS_DUMP_EVENT_IN_INFO,
	HTS_DUMP_EVENT_PROC_INFO,
	HTS_DUMP_EVENT_OUT_INFO,
	HTS_DUMP_FFTS_EVENT_OUT_INFO,
	HTS_DUMP_RESOURCE_INFO,
};

typedef void (*diff_modules_func)(void);

struct opt_mod {
	char *name;
	diff_modules_func func;
};

#define MAX_EVENT_STORE_REG_NUM  64

struct store_info {
	uint32_t idx;
	uint32_t store_flag;
};

void hts_info_readback(uint32_t id);
void hts_record_key_info(void);

#endif