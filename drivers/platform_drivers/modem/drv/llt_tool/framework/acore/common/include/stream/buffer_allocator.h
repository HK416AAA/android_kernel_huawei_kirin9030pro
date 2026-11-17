#ifndef ST_MEMORY_BUFFER_ALLOCATOR_H
#define ST_MEMORY_BUFFER_ALLOCATOR_H

#include "predef.h"


#ifdef __cplusplus
extern "C" {
#endif

#if defined(ST_KERNEL) && defined(ST_DPA)
    typedef void *(*_alloc_buffer)(unsigned int size);
    typedef void (*_free_buffer)(const void *buffer);
#elif defined(ST_KERNEL)
    typedef void *(*_alloc_buffer)(uint32_t size);
    typedef void (*_free_buffer)(const void *buffer);
#elif defined(ST_HIBOOT)
    typedef void *(*_alloc_buffer)(unsigned long int size);
    typedef void (*_free_buffer)(void *buffer);
#else
    #include <stdint.h>
    typedef void *(*_alloc_buffer)(size_t size);
    typedef void (*_free_buffer)(void *buffer);
#endif

typedef struct _allocator {
    _alloc_buffer alloc;
    _free_buffer free;
} *buffer_allocator;

buffer_allocator get_default_allocator(void);

#ifdef __cplusplus
}
#endif

#endif
