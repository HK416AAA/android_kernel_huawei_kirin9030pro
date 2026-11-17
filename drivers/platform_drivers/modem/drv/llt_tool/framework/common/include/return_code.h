#ifndef ST_RETURN_CODE_H
#define ST_RETURN_CODE_H

#ifdef __cplusplus
extern "C" {
#endif

enum STReturnCode {
    ST_SUCCESS = 0,

    //fun call error
    FUNC_NAME_NOT_FOUND = 10,
    PARAM_NUMS_ERROR,

    //st_stream start
    ALLOC_FAIL = 50,
    IO_FAIL,
    //st_stream end

    // st_protocol start
    ADD_TO_RECV_QUEUE_FAIL = 150,
    // st_protocol end

    // st_socket start
    SERVER_IS_NULL = 200,
    CLIENT_IS_NULL,

    SERVER_IS_RUNNING,
    SERVER_IS_STOPPED,

    NO_AVAILABLE_CLIENT,

    ACCEPT_FAIL,
    SEND_FAIL,
    RECV_FAIL,
    INVALID_FD,

    CLIENT_CLOSE,
    // st_socket end

    // st_testnode start
    // st_testnode end

    // built-in start
    COMMAND_EXEC_FAIL,
    COMMAND_TOO_LONG,
    NULL_POINTER,
    INVALID_COMMAND,

    FD_OPEN_FAIL,
    FD_CLOSE_FAIL,
    FD_SEEK_FAIL,
    FD_READ_FAIL,
    FD_WRITE_FAIL,

    INVALID_OFFSET,
    PROCESS_EXIT_FAIL,
    // built-in end
};

#ifdef __cplusplus
}
#endif

#endif