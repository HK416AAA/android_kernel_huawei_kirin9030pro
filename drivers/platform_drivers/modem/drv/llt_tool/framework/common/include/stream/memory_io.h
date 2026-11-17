#ifndef ST_MEMORY_IO_H
#define ST_MEMORY_IO_H

#include "predef.h"
#include "stream/stream_buffer.h"

#ifdef __cplusplus
extern "C" {
#endif

struct _memory_fd;
typedef struct _memory_fd *mem_fd;

/* write interface */
mem_fd open_w(stream_buffer buffer);

bool write_char(mem_fd fd, char data);
bool write_uchar(mem_fd fd, unsigned char data);

bool write_short(mem_fd fd, short data);
bool write_ushort(mem_fd fd, unsigned short data);

bool write_int(mem_fd fd, int data);
bool write_uint(mem_fd fd, unsigned int data);

bool write_long(mem_fd fd, long long data);
bool write_ulong(mem_fd fd, unsigned long long data);

bool write_float(mem_fd fd, float data);
bool write_double(mem_fd fd, double data);
bool write_7bit_int(mem_fd fd, unsigned int data);

bool write_raw_data(mem_fd fd, unsigned char *data, unsigned int len);

/* read interface */
mem_fd open_r(stream_buffer buffer);

bool read_char(mem_fd fd, char *data);
bool read_uchar(mem_fd fd, unsigned char *data);

bool read_short(mem_fd fd, short *data);
bool read_ushort(mem_fd fd, unsigned short *data);

bool read_int(mem_fd fd, int *data);
bool read_uint(mem_fd fd, unsigned int *data);

bool read_long(mem_fd fd, long long *data);
bool read_ulong(mem_fd fd, unsigned long long *data);

bool read_float(mem_fd fd, float *data);
bool read_double(mem_fd fd, double *data);
bool read_7bit_int(mem_fd fd, unsigned int *data);

bool read_raw_data(mem_fd fd, unsigned char *data, unsigned int len);


stream_buffer get_mem_buffer(mem_fd fd);
bool io_seek(mem_fd fd, int distance, int whence);
unsigned int tell_p(mem_fd fd);
void close_memory_io(mem_fd fd);

#ifdef __cplusplus
}
#endif

#endif