#ifndef ST_PROTO_ENUM_H
#define ST_PROTO_ENUM_H

#ifdef __cplusplus
extern "C" {
#endif

#define ST_UUID_SIZE 8

enum FunctionLocation {
    HIBOOT = 0,
    ACORE_USER,
    ACORE_KERNEL,
    MCORE,
    CCORE_MREE,
    CCORE_MTEE,
    DPA,
    TEEOS,
    LOCATION_MAX
};

enum DataType {
    ST_VOID = 0,
    ST_BOOL,
    ST_CHAR,
    ST_UNSIGNED_CHAR,
    ST_SHORT_INT,
    ST_UNSIGNED_SHORT,
    ST_INT,
    ST_UNSIGNED_INT,
    ST_LONG_LONG_INT,
    ST_UNSIGNED_LONG_LONG,
    ST_FLOAT,
    ST_DOUBLE,

    ST_STRING,
    ST_BYTE_ARRAY,
    ST_TYPE_MAX
};

enum UseType {
    IN_PARAM = 0,
    OUT_PARAM,
    INOUT_PARAM
};

#ifdef __cplusplus
}
#endif

#endif