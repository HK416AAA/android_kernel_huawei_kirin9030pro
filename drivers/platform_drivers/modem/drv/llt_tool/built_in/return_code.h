#ifndef RETURN_CODE_H
#define RETURN_CODE_H

#define THIS_MODU mod_btest

enum return_code {
    ACORE_SUCCESS = 0,
    ACORE_FAIL,
    NULL_POINTER,
    STRING_LEN_ERROR,
    STRING_FORMAT_FAIL,
    CREATE_FILE_FAIL,
    FILE_NOT_EXIST,
    FILE_READ_TOO_LONG
};

#endif