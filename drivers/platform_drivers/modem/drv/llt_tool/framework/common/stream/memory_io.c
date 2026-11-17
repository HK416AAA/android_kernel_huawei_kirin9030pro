#ifdef ST_KERNEL
#else
#include <string.h>
#endif
#include <securec.h>
#include "stream/memory_io.h"

#define LOW_SEVEN 0x7F
#define HIGT_FIRST 0x80
#define BLANK_VALUE 0x00
#define BIT_7_OFFSET 7

struct _memory_fd {
    stream_buffer _buffer;
    unsigned int _pos;
    bool _is_write;
    bool _is_buffer_created;
};

mem_fd open_w(stream_buffer buffer)
{
    mem_fd fd = NULL;

    if (buffer == NULL)
        buffer = create_buffer();
    if (buffer == NULL)
        return NULL;

    fd = (mem_fd)get_default_allocator()->alloc(sizeof(struct _memory_fd));
    if (fd == NULL)
        return NULL;

    fd->_buffer = buffer;
    fd->_is_write = true;
    fd->_pos = 0;
    fd->_is_buffer_created = (buffer == NULL);
    return fd;
}

bool write_char(mem_fd fd, char data)
{
    return write_raw_data(fd, (unsigned char*)&data, sizeof(data));
}

bool write_uchar(mem_fd fd, unsigned char data)
{
    return write_raw_data(fd, (unsigned char*)&data, sizeof(data));
}

bool write_short(mem_fd fd, short data)
{
    return write_raw_data(fd, (unsigned char*)&data, sizeof(data));
}

bool write_ushort(mem_fd fd, unsigned short data)
{
    return write_raw_data(fd, (unsigned char*)&data, sizeof(data));
}

bool write_int(mem_fd fd, int data)
{
    return write_raw_data(fd, (unsigned char*)&data, sizeof(data));
}

bool write_uint(mem_fd fd, unsigned int data)
{
    return write_raw_data(fd, (unsigned char*)&data, sizeof(data));
}

bool write_long(mem_fd fd, long long data)
{
    return write_raw_data(fd, (unsigned char*)&data, sizeof(data));
}

bool write_ulong(mem_fd fd, unsigned long long data)
{
    return write_raw_data(fd, (unsigned char*)&data, sizeof(data));
}

bool write_float(mem_fd fd, float data)
{
    return write_raw_data(fd, (unsigned char*)&data, sizeof(data));
}

bool write_double(mem_fd fd, double data)
{
    return write_raw_data(fd, (unsigned char*)&data, sizeof(data));
}

bool write_7bit_int(mem_fd fd, unsigned int data)
{
    if (data == 0) {
        if (!write_uchar(fd, BLANK_VALUE)) {
            return false;
        }
        return true;
    }
    while (data > 0) {
        unsigned char value_byte = data & LOW_SEVEN;
        data = data >> BIT_7_OFFSET;
        if (data != 0) {
            value_byte = value_byte | HIGT_FIRST;
        }
        if (!write_uchar(fd, value_byte)) {
            return false;
        }
    }
    return true;
}

bool write_raw_data(mem_fd fd, unsigned char *data, unsigned int len)
{
    if (fd == NULL || !fd->_is_write)
        return false;

    if (!reserve_buffer(fd->_buffer, fd->_pos + len))
        return false;

    memset_buffer(fd->_buffer, fd->_pos, data, len);
    fd->_pos += len;
    return true;
}

mem_fd open_r(stream_buffer buffer)
{
    mem_fd fd = NULL;

    if (buffer == NULL)
        return NULL;

    fd = (mem_fd)get_default_allocator()->alloc(sizeof(struct _memory_fd));
    if (fd == NULL)
        return NULL;
    fd->_buffer = buffer;
    fd->_pos = 0;
    fd->_is_buffer_created = false;
    fd->_is_write = false;
    return fd;
}

bool read_char(mem_fd fd, char *data)
{
    return read_raw_data(fd, (unsigned char*)data, sizeof(*data));
}
bool read_uchar(mem_fd fd, unsigned char *data)
{
    return read_raw_data(fd, (unsigned char*)data, sizeof(*data));
}

bool read_short(mem_fd fd, short *data)
{
    return read_raw_data(fd, (unsigned char*)data, sizeof(*data));
}
bool read_ushort(mem_fd fd, unsigned short *data)
{
    return read_raw_data(fd, (unsigned char*)data, sizeof(*data));
}

bool read_int(mem_fd fd, int *data)
{
    return read_raw_data(fd, (unsigned char*)data, sizeof(*data));
}
bool read_uint(mem_fd fd, unsigned int *data)
{
    return read_raw_data(fd, (unsigned char*)data, sizeof(*data));
}

bool read_long(mem_fd fd, long long *data)
{
    return read_raw_data(fd, (unsigned char*)data, sizeof(*data));
}
bool read_ulong(mem_fd fd, unsigned long long *data)
{
    return read_raw_data(fd, (unsigned char*)data, sizeof(*data));
}

bool read_float(mem_fd fd, float *data)
{
    return read_raw_data(fd, (unsigned char*)data, sizeof(*data));
}
bool read_double(mem_fd fd, double *data)
{
    return read_raw_data(fd, (unsigned char*)data, sizeof(*data));
}


bool read_7bit_int(mem_fd fd, unsigned int *data)
{
    unsigned char value_byte;
    bool continue_flg = true;
    int shift = 0;

    *data = 0;
    while (continue_flg) {
        if (!read_uchar(fd, &value_byte)) {
            return false;
        }
        *data |= (value_byte & LOW_SEVEN) << shift;
        shift += BIT_7_OFFSET;

        if ((value_byte & HIGT_FIRST) == 0) {
            continue_flg = false;
        }
    }
    return true;
}

bool read_raw_data(mem_fd fd, unsigned char *data, unsigned int len)
{
    unsigned int size = 0;
    unsigned char *input = NULL;
    if (fd == NULL || fd->_is_write || fd->_buffer == NULL)
        return false;
    
    size = get_buffer_length(fd->_buffer);
    if (fd->_pos + len > size)
        return false;

    input = get_buffer_data(fd->_buffer);

    if (data != NULL) {
        memcpy_s(data, len, input + fd->_pos, len);
    }
    
    fd->_pos += len;
    return true;
}

stream_buffer get_mem_buffer(mem_fd fd)
{
    return fd->_buffer;
}

void close_memory_io(mem_fd fd)
{
    if (fd == NULL) {
        return;
    }
    
    if (fd->_is_buffer_created)
        destroy_buffer(fd->_buffer);
    fd->_buffer = NULL;
    fd->_pos = 0;
    fd->_is_buffer_created = false;
    get_default_allocator()->free(fd);
}

unsigned int tell_p(mem_fd fd)
{
    return ((mem_fd)fd)->_pos;
}

static bool seek_w(mem_fd fd, int distance, int whence)
{
    unsigned int size = get_buffer_length(fd->_buffer);

    if (whence == 0) { /* SEEK_SET */
        if (distance < 0 || !reserve_buffer(fd->_buffer, distance))
            return false;
        fd->_pos = distance;
    } else if (whence == 1) { /* SEEK_CUR */
        if (distance + (int)fd->_pos < 0 || !reserve_buffer(fd->_buffer, distance + fd->_pos))
            return false;
        fd->_pos = distance + fd->_pos;
    } else if (whence == 2) { /* SEEK_END */
        if ((int)size + distance < 0 || !reserve_buffer(fd->_buffer, distance + size))
            return false;
        fd->_pos = distance + size;
    }
    if (size < fd->_pos)
        resize_buffer(fd->_buffer, fd->_pos);
    return true;
}

static bool seek_r(mem_fd fd, int distance, int whence)
{
    int end = get_buffer_length(fd->_buffer);

    if (whence == 0) { /* SEEK_SET */
        if (distance < 0 || distance > end)
            return false;
        fd->_pos = distance;
    } else if (whence == 1) { /* SEEK_CUR */
        if (distance + (int)fd->_pos < 0 || distance + (int)fd->_pos > end)
            return false;
        fd->_pos = distance + fd->_pos;
    } else if (whence == 2) { /* SEEK_END */
        if (end + distance < 0 || distance + end > end)
            return false;
        fd->_pos = end + distance;
    }
    return true;
}

bool io_seek(mem_fd fd, int distance, int whence)
{
    if (!fd)
        return false;
    if (fd->_is_write)
        return seek_w(fd, distance, whence);
    else
        return seek_r(fd, distance, whence);
}