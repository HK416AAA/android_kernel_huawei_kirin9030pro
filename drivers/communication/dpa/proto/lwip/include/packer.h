#ifndef PACKER_H
#define PACKER_H

#include <linux/types.h>

#ifdef __cplusplus
extern "C" {
#endif

struct packer_buffer {
    unsigned char *base;
    unsigned int size;
    unsigned int curr;
};
static inline void packer_buffer_init(struct packer_buffer *buf, unsigned char *base, unsigned int size)
{
    buf->base = base;
    buf->size = size;
    buf->curr = 0;
}

#define PACKER_BUFFER(name, base, size) struct packer_buffer name = { base, size, 0 }

static inline unsigned int packer_buffer_avail(struct packer_buffer *buf)
{
    return buf->size - buf->curr;
}

#define PACKER_BUFFER_APPEND(TYPE)                                                      \
    static inline void packer_buffer_append_##TYPE(struct packer_buffer *buf, TYPE val) \
    {                                                                                   \
        *((TYPE *)(buf->base + buf->curr)) = val;                                       \
        buf->curr += sizeof(TYPE);                                                      \
    }

#define PACKER_BUFFER_POP(TYPE)                                                       \
    static inline void packer_buffer_pop_##TYPE(struct packer_buffer *buf, TYPE *val) \
    {                                                                                 \
        *val = *((TYPE *)(buf->base + buf->curr));                                    \
        buf->curr += sizeof(TYPE);                                                    \
    }

PACKER_BUFFER_APPEND(u8);
PACKER_BUFFER_APPEND(s8);
PACKER_BUFFER_APPEND(u16);
PACKER_BUFFER_APPEND(s16);
PACKER_BUFFER_APPEND(u32);
PACKER_BUFFER_APPEND(s32);
PACKER_BUFFER_APPEND(u64);
PACKER_BUFFER_APPEND(s64);
PACKER_BUFFER_POP(u8);
PACKER_BUFFER_POP(s8);
PACKER_BUFFER_POP(u16);
PACKER_BUFFER_POP(s16);
PACKER_BUFFER_POP(u32);
PACKER_BUFFER_POP(s32);
PACKER_BUFFER_POP(u64);
PACKER_BUFFER_POP(s64);
static inline void packer_buffer_append_ptr(struct packer_buffer *buf, void *val)
{
    packer_buffer_append_u64(buf, (unsigned long long)(uintptr_t)val);
}
static inline void packer_buffer_pop_ptr(struct packer_buffer *buf, void **val)
{
    packer_buffer_pop_u64(buf, (unsigned long long *)(uintptr_t)val);
}
int packer_buffer_append_array(struct packer_buffer *buf, u8 *p, unsigned int size);
int packer_buffer_pop_array(struct packer_buffer *buf, u8 *p, unsigned int size);
int packer_buffer_pop_array_nocopy(struct packer_buffer *buf, u8 **p, unsigned int *size);

#ifdef __cplusplus
}
#endif

#endif
