#ifndef ISP_IMPROVE_YIELD
#define ISP_IMPROVE_YIELD 
#include "improve_yield_info.h"
#define ISP_IY_NV_INFO_MAX_LENGTH 125
typedef union {
 unsigned char value;
} improve_yield_isp_fail_level;
typedef union {
 unsigned char value;
 struct {
  unsigned char fail_level : 2;
  unsigned char reserved : 4;
  unsigned char pv_flag : 1;
  unsigned char reserved1 : 1;
 } bits;
} improve_yield_isp_nv_flag;
typedef struct {
 improve_yield_isp_fail_level fail_level;
 improve_yield_isp_nv_flag nv_flag;
} improve_yield_isp_info;
typedef union {
 unsigned char value;
} improve_yield_nv_reserved;
typedef union {
 unsigned char value;
 struct {
  unsigned char fail_level : 4;
  unsigned char err_code : 4;
 } bits;
} improve_yield_isp_fail_info;
typedef struct {
 improve_yield_nv_reserved reserved[14];
 improve_yield_isp_fail_info fail_info[5];
} improve_yield_nv_reserved2;
#endif
