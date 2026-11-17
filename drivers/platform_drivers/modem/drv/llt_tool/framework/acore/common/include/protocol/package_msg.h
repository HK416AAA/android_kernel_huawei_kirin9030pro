#ifndef ST_PACKAGE_BUFFER_H
#define ST_PACKAGE_BUFFER_H

#include "stream/memory_io.h"
#include "protocol/func_item.h"

#ifdef __cplusplus
extern "C" {
#endif

stream_buffer unpack_msg(stream_buffer package);

stream_buffer pack_msg(stream_buffer message);

#ifdef __cplusplus
}
#endif

#endif