#ifndef ST_STREAM_BUFFER_H
#define ST_STREAM_BUFFER_H

#include "predef.h"
#include "stream/buffer_allocator.h"

#ifdef __cplusplus
extern "C" {
#endif

struct _stream_buf;
typedef struct _stream_buf *stream_buffer;

stream_buffer create_buffer(void);
stream_buffer create_buffer_from_bytes(unsigned char *data, unsigned int len);

void destroy_buffer(stream_buffer handle);
void *detach_buffer(stream_buffer handle);
void set_buffer_allocator(stream_buffer handle, buffer_allocator allocator);

bool reserve_buffer(stream_buffer handle, unsigned int size);
bool resize_buffer(stream_buffer handle, unsigned int size);
bool append_buffer(stream_buffer handle, unsigned char *data, unsigned int len);
bool pop_from_end(stream_buffer handle, unsigned int len);
bool pop_from_front(stream_buffer handle, unsigned int len);
void print_uuid_from_buffer(stream_buffer handle);
bool memset_buffer(stream_buffer handle, unsigned int offset, unsigned char *data, unsigned int len);

unsigned int get_buffer_length(stream_buffer handle);
unsigned int get_buffer_capacity(stream_buffer handle);
unsigned char *get_buffer_data(stream_buffer handle);

#ifdef __cplusplus
}
#endif

#endif