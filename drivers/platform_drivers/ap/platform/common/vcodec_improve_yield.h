#ifndef VCODEC_IMPROVE_YIELD
#define VCODEC_IMPROVE_YIELD 
typedef struct {
    unsigned char enabale_flag;
    unsigned char pv_flag;
 unsigned char test_case_number;
} RtbIyParam;
typedef union {
 unsigned char value;
 struct {
  unsigned char vdec_pv_flag : 1;
  unsigned char dpu_pv_flag : 1;
  unsigned char reserved : 4;
  unsigned char pv_flag : 1;
  unsigned char enable_flag : 1;
 } bits;
} improve_yield_vdec_nv_flag;
typedef union {
 unsigned char value;
} improve_yield_vdec_error_flag;
typedef union {
 unsigned char value;
} improve_yield_vdec_reserved;
typedef struct {
    improve_yield_vdec_nv_flag nv_flag;
    improve_yield_vdec_error_flag error_flag;
 improve_yield_vdec_reserved reserved;
} improve_yield_vdec_info;
#endif
