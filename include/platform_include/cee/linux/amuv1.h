#ifndef AMU_V1_H
#define AMU_V1_H

#include <linux/types.h>

// Add an AMU event.
int amu_counter_enable(u32 event);

// Remove an AMU event.
int amu_counter_disable(u32 event);

// Read the value of an AMU event.
u64 amu_read_counter(u32 event);

#endif
