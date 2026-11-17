
#include "protocol/package_msg.h"

#define MESG_FLAG 0x7e
#define TURN_FLAG 0x7d
#define TURN_FLAG_E 0x5e
#define TURN_FLAG_D 0x5d

stream_buffer unpack_msg(stream_buffer package)
{
    bool start_flag = false;
    bool end_flag = false;
    mem_fd read_fd;
    mem_fd write_fd;
    int read_len;
    unsigned char temp_uchar;
    stream_buffer message = create_buffer();
    if (message == NULL) {
        st_error("stream_buffer name message alloc fail\n");
        return NULL;
    }

    read_fd = open_r(package);
    if (read_fd == NULL) {
        st_error("open memio in unpacking msg\n");
        return NULL;
    }

    write_fd = open_w(message); 
    if (write_fd == NULL) {
        st_error("open memio in unpacking msg\n");
        goto close_memio;
    }

    while (read_uchar(read_fd, &temp_uchar)) {
        if(temp_uchar == MESG_FLAG) {
            start_flag = true;
            break;
        }
    } 

    while (read_uchar(read_fd, &temp_uchar)) {
        if (temp_uchar == MESG_FLAG) {
            end_flag = true;
            break;
        }
        else if (temp_uchar == TURN_FLAG) {
            if (read_uchar(read_fd, &temp_uchar)) {
                if (temp_uchar == TURN_FLAG_E) {
                    temp_uchar = MESG_FLAG;
                }
                else if (temp_uchar == TURN_FLAG_D) {
                    temp_uchar = TURN_FLAG;
                }
                else {
                    st_error("0x7d only in msg in unpacking msg\n");
                    break;
                }
            }
            else
                break;
        }
        if (!write_uchar(write_fd, temp_uchar)) {
            st_error("write msg fail in unpacking msg\n");
            break;
        }
    }

    close_memory_io(write_fd);

    if (!(start_flag && end_flag)) {
        st_error("msg not complete \n");
        goto close_memio;
    }

    read_len = tell_p(read_fd);
    if (!pop_from_front(package, read_len)) {
        st_error("pop client data in recv task fail\n");
        goto close_memio;
    }
    close_memory_io(read_fd);
    return message;

close_memio:
    close_memory_io(read_fd);
    destroy_buffer(message);
    return NULL;
}


stream_buffer pack_msg(stream_buffer message)
{   
    mem_fd read_fd;
    mem_fd write_fd;
    unsigned char temp_uchar;
    stream_buffer package = create_buffer();
    if (package == NULL) {
        st_error("stream_buffer name message alloc fail\n");
        return NULL;
    }

    read_fd = open_r(message);
    if (read_fd == NULL) {
        st_error("open memio in packing msg\n");
        return NULL;
    }

    write_fd = open_w(package);
    if (write_fd == NULL) {
        st_error("open memio in packing msg\n");
        goto close_memio;
    }

    if (!write_uchar(write_fd, MESG_FLAG)) {
        st_error("write msg fail in packing msg\n");
        goto close_memio_all;
    }
    while (read_uchar(read_fd, &temp_uchar)) {
        if (temp_uchar == MESG_FLAG || temp_uchar == TURN_FLAG) {
            if (!write_uchar(write_fd, TURN_FLAG)) {
                st_error("write msg fail in packing msg\n");
                goto close_memio_all;
            }
            temp_uchar = (temp_uchar == MESG_FLAG) ? TURN_FLAG_E : TURN_FLAG_D ;
            if (!write_uchar(write_fd, temp_uchar)) {
                st_error("write msg fail in packing msg\n");
                goto close_memio_all;
            }
        }
        else {
            if (!write_uchar(write_fd, temp_uchar)) {
                st_error("write msg fail in packing msg\n");
                goto close_memio_all;
            }
        }
    }
    if (tell_p(read_fd) != get_buffer_length(message)) {
        st_error("read message fail in packing message\n ");
        goto close_memio_all;
    }
    if(!write_uchar(write_fd, MESG_FLAG)){
        st_error("write msg fail in packing msg\n");
        goto close_memio_all;
    }
    close_memory_io(write_fd);
    close_memory_io(read_fd);
    destroy_buffer(message);
    return package;

close_memio_all:
    close_memory_io(write_fd);
close_memio:
    close_memory_io(read_fd);
    destroy_buffer(package);
    return NULL;
}