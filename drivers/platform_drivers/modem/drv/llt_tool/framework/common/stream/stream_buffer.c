#ifdef ST_KERNEL
#else
#include <string.h>
#include <stdio.h>
#endif
#include <securec.h>
#include "stream/stream_buffer.h"

#define ST_UUID_SIZE 8
static const unsigned int min_grow_size = 256;
static const unsigned int max_grow_size = 256  *32;

struct _stream_buf {
    unsigned char *_data;
    unsigned char *_end;
    unsigned int _capacity;
    buffer_allocator _allocator;
};

static buffer_allocator _get_allocator(stream_buffer handle);
static bool _realloc_data(stream_buffer handle, int min_size);

void set_buffer_allocator(stream_buffer handle, buffer_allocator allocator)
{
    handle->_allocator = allocator;
}

stream_buffer create_buffer(void)
{
    return create_buffer_from_bytes(NULL, 0);
}

stream_buffer create_buffer_from_bytes(unsigned char *data, unsigned int len)
{
    stream_buffer buff = (stream_buffer)get_default_allocator()->alloc(sizeof(struct _stream_buf));
    if (!buff)
        return buff;
    buff->_data = data;
    buff->_end = buff->_data + len;
    buff->_capacity = len;
    buff->_allocator = get_default_allocator();
    return buff;
}

void destroy_buffer(stream_buffer handle)
{
    if (handle == NULL) {
        return;
    }
    if (handle->_data != NULL) {
        _get_allocator(handle)->free(handle->_data);
        handle->_data = NULL;
    }
    handle->_end = NULL;
    handle->_capacity = 0;
    _get_allocator(handle)->free(handle);
}

void *detach_buffer(stream_buffer handle)
{
    unsigned char *data = NULL;
    if (handle == NULL) {
        return NULL;
    }

    data = handle->_data;
    handle->_data = NULL;
    handle->_end = NULL;
    handle->_capacity = 0;
    return data;
}

bool reserve_buffer(stream_buffer handle, unsigned int size)
{
    return _realloc_data(handle, size);
}

bool resize_buffer(stream_buffer handle, unsigned int size)
{
    if (!reserve_buffer(handle, size))
        return false;
    handle->_end = get_buffer_data(handle) + size;
    return true;
}

bool append_buffer(stream_buffer handle, unsigned char *data, unsigned int len)
{
    int size = 0;
    int remain_size = 0;
    bool ret = false;

    size = get_buffer_length(handle);
    remain_size = handle->_capacity - size;
    if (remain_size < (int)len) {
        ret = _realloc_data(handle, size + len);
        if (!ret)
            return false;
    }

    memcpy_s(handle->_end, len, data, len);
    handle->_end += len;
    return true;
}

bool pop_from_end(stream_buffer handle, unsigned int len)
{
    int size = 0;

    size = get_buffer_length(handle);
    if ((int)len > size)
        return false;

    handle->_end -= len;
    return true;
}

void print_uuid_from_buffer(stream_buffer handle) 
{
    unsigned char ptr[ST_UUID_SIZE] = {0};
    unsigned int size = 0, ret, i;
    unsigned char *input = NULL;
    if(handle == NULL){
        return;
    }
    size = get_buffer_length(handle);
    if (size < ST_UUID_SIZE) {
        return;
    }
    input = get_buffer_data(handle);

    ret = memcpy_s(ptr, ST_UUID_SIZE, input, ST_UUID_SIZE);
    if (ret != 0) {
        st_error("read_uuid_faild!\n");
        return;
    }
    st_error("read uuid from buffer:");
    for (i = 0; i < ST_UUID_SIZE; i++) {
        st_error("%02X ", ptr[i]);
    }
    st_error("\n");
    return;
}


bool pop_from_front(stream_buffer handle, unsigned int len)
{
    int size = 0;

    size = get_buffer_length(handle);
    if ((int)len > size)
        return false;

    if ((int)len == size)
        handle->_end = handle->_data;
    else {
        memmove_s(handle->_data, size, handle->_data + len, size - len);
        handle->_end = handle->_data + size - len;
    }
    return true;
}

bool memset_buffer(stream_buffer handle, unsigned int offset, unsigned char *data, unsigned int len)
{
    unsigned char *p_data = NULL;

    if (!reserve_buffer(handle, offset + len))
        return false;

    p_data = get_buffer_data(handle);
    if (p_data == NULL)
        return false;

    if (memcpy_s(p_data + offset, len, data, len) != 0)
        return false;

    if (handle->_end < p_data + offset + len)
        handle->_end = p_data + offset + len;
    return true;
}

unsigned int get_buffer_length(stream_buffer handle)
{
    return handle->_end - handle->_data;
}

unsigned int get_buffer_capacity(stream_buffer handle)
{
    return handle->_capacity;
}

unsigned char *get_buffer_data(stream_buffer handle)
{
    return handle->_data;
}

static buffer_allocator _get_allocator(stream_buffer handle)
{
    if (handle->_allocator)
        return handle->_allocator;

    return get_default_allocator();
}

static bool _realloc_data(stream_buffer handle, int min_size)
{
    unsigned char *new_data = NULL;
    int new_cap = 0;
    int size = get_buffer_length(handle);
    int capacity = get_buffer_capacity(handle);
    if (capacity >= min_size)
        return true;

    if (min_size < (int)min_grow_size) {
        new_cap = min_grow_size;
    }
    else if (min_size < (int)max_grow_size) {
        new_cap = min_size  *2;
    } else {
        new_cap = min_size + max_grow_size;
    }
    new_data = (unsigned char*)_get_allocator(handle)->alloc(new_cap);
    if (new_data == NULL)
        return false;
    memset_s(new_data, new_cap, 0, new_cap);

    if (size > 0)
        memcpy_s(new_data, size, handle->_data, size);
    if(capacity > 0)
        _get_allocator(handle)->free(handle->_data);


    handle->_data = new_data;
    handle->_end = handle->_data + size;
    handle->_capacity = new_cap;
    return true;
}