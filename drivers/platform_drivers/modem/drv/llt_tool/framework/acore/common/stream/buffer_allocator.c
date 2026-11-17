#if defined(ST_KERNEL) && defined(ST_DPA)
#include <bsp_memory.h>
static void *st_dpa_malloc(unsigned int size)
{
    return mdrv_mem_alloc(size, MDRV_MEM_ALIGN_004);
}

static void st_dpa_free(const void *p)
{
    mdrv_sram_free(p);
}
#elif defined(ST_KERNEL)
#include <osl_malloc.h>
#else
#include <stdlib.h>
#endif
#include "stream/buffer_allocator.h"

buffer_allocator get_default_allocator(void)
{
#if defined(ST_KERNEL) && defined(ST_DPA)
    static struct _allocator g_allocator = {st_dpa_malloc, st_dpa_free};
#elif defined(ST_KERNEL)
    static struct _allocator g_allocator = {osl_malloc, osl_free};
#else
    static struct _allocator g_allocator = {malloc, free};
#endif
    return &g_allocator;
}
