#include <securec.h>
#include "packer.h"

int packer_buffer_append_array(struct packer_buffer *buf, u8 *p, unsigned int size)
{
    if (packer_buffer_avail(buf) <= (size + sizeof(unsigned int))) {
        return -1;
    }
    packer_buffer_append_u32(buf, size);
    memcpy_s(buf->base + buf->curr, packer_buffer_avail(buf), p, size);
    buf->curr += size;
    return 0;
}
int packer_buffer_pop_array(struct packer_buffer *buf, u8 *p, unsigned int size)
{
    unsigned int tmp;
    tmp = *((unsigned int *)(buf->base + buf->curr));
    if (tmp > size) {
        return -1;
    }
    packer_buffer_pop_u32(buf, &tmp);
    memcpy_s(p, size, buf->base + buf->curr, tmp);
    buf->curr += tmp;
    return 0;
}

int packer_buffer_pop_array_nocopy(struct packer_buffer *buf, u8 **p, unsigned int *size)
{
    packer_buffer_pop_u32(buf, size);
    *p = buf->base + buf->curr;
    buf->curr += *size;
    return 0;
}