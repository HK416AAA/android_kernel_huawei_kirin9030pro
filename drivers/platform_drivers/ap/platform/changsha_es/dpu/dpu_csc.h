#ifndef DPU_CSC_H
#define DPU_CSC_H 
#include "dpu_ov.h"
#define init_csc_coe(coe) { .value = (coe), }
static struct dpu_ov_csc_coef g_unit_matrix = {
 .idc0 = {
  .reg = {
   .csc_idc0 = 0x000,
   .csc_idc1 = 0x000,
  },
 },
 .idc2 = init_csc_coe(0),
 .odc0 = {
  .reg = {
   .csc_odc0 = 0x000,
   .csc_odc1 = 0x000,
  },
 },
 .odc2 = init_csc_coe(0x000),
 .p00 = init_csc_coe(0x4000),
 .p01 = init_csc_coe(0x0000),
 .p02 = init_csc_coe(0x0000),
 .p10 = init_csc_coe(0x0000),
 .p11 = init_csc_coe(0x4000),
 .p12 = init_csc_coe(0x0000),
 .p20 = init_csc_coe(0x0000),
 .p21 = init_csc_coe(0x0000),
 .p22 = init_csc_coe(0x4000),
};
static struct dpu_ov_csc_coef g_yuv_2_rgb_601wide = {
 .idc0 = {
  .reg = {
   .csc_idc0 = 0x600,
   .csc_idc1 = 0x600,
  },
 },
 .idc2 = init_csc_coe(0),
 .odc0 = {
  .reg = {
   .csc_odc0 = 0x000,
   .csc_odc1 = 0x000,
  },
 },
 .odc2 = init_csc_coe(0x000),
 .p00 = init_csc_coe(0x4000),
 .p01 = init_csc_coe(0x0000),
 .p02 = init_csc_coe(0x059ba),
 .p10 = init_csc_coe(0x4000),
 .p11 = init_csc_coe(0x1e9fa),
 .p12 = init_csc_coe(0x1d24c),
 .p20 = init_csc_coe(0x4000),
 .p21 = init_csc_coe(0x07168),
 .p22 = init_csc_coe(0x00000),
};
static struct dpu_ov_csc_coef g_yuv_2_rgb_601narrow = {
 .idc0 = {
  .reg = {
   .csc_idc0 = 0x600,
   .csc_idc1 = 0x600,
  },
 },
 .idc2 = init_csc_coe(0x7c0),
 .odc0 = {
  .reg = {
   .csc_odc0 = 0x000,
   .csc_odc1 = 0x000,
  },
 },
 .odc2 = init_csc_coe(0x000),
 .p00 = init_csc_coe(0x4a85),
 .p01 = init_csc_coe(0x00000),
 .p02 = init_csc_coe(0x06625),
 .p10 = init_csc_coe(0x4a85),
 .p11 = init_csc_coe(0x1e6ed),
 .p12 = init_csc_coe(0x1cbf8),
 .p20 = init_csc_coe(0x4a85),
 .p21 = init_csc_coe(0x0811a),
 .p22 = init_csc_coe(0x00000),
};
static struct dpu_ov_csc_coef g_yuv_2_rgb_709wide = {
 .idc0 = {
  .reg = {
   .csc_idc0 = 0x600,
   .csc_idc1 = 0x600,
  },
 },
 .idc2 = init_csc_coe(0x000),
 .odc0 = {
  .reg = {
   .csc_odc0 = 0x000,
   .csc_odc1 = 0x000,
  },
 },
 .odc2 = init_csc_coe(0x000),
 .p00 = init_csc_coe(0x4000),
 .p01 = init_csc_coe(0x00000),
 .p02 = init_csc_coe(0x064ca),
 .p10 = init_csc_coe(0x4000),
 .p11 = init_csc_coe(0x1f403),
 .p12 = init_csc_coe(0x1e20a),
 .p20 = init_csc_coe(0x4000),
 .p21 = init_csc_coe(0x076c2),
 .p22 = init_csc_coe(0x00000),
};
static struct dpu_ov_csc_coef g_yuv_2_rgb_709narrow = {
 .idc0 = {
  .reg = {
   .csc_idc0 = 0x600,
   .csc_idc1 = 0x600,
  },
 },
 .idc2 = init_csc_coe(0x7c0),
 .odc0 = {
  .reg = {
   .csc_odc0 = 0x000,
   .csc_odc1 = 0x000,
  },
 },
 .odc2 = init_csc_coe(0x000),
 .p00 = init_csc_coe(0x4a85),
 .p01 = init_csc_coe(0x00000),
 .p02 = init_csc_coe(0x072bc),
 .p10 = init_csc_coe(0x4a85),
 .p11 = init_csc_coe(0x1f25a),
 .p12 = init_csc_coe(0x1dde5),
 .p20 = init_csc_coe(0x4a85),
 .p21 = init_csc_coe(0x08732),
 .p22 = init_csc_coe(0x00000),
};
static struct dpu_ov_csc_coef g_yuv_2_p3_601wide = {
 .idc0 = {
  .reg = {
   .csc_idc0 = 0x600,
   .csc_idc1 = 0x600,
  },
 },
 .idc2 = init_csc_coe(0x000),
 .odc0 = {
  .reg = {
   .csc_odc0 = 0x000,
   .csc_odc1 = 0x000,
  },
 },
 .odc2 = init_csc_coe(0x000),
 .p00 = init_csc_coe(0x4000),
 .p01 = init_csc_coe(0x1fc17),
 .p02 = init_csc_coe(0x041af),
 .p10 = init_csc_coe(0x4000),
 .p11 = init_csc_coe(0x1e6cc),
 .p12 = init_csc_coe(0x1d6cb),
 .p20 = init_csc_coe(0x4000),
 .p21 = init_csc_coe(0x065aa),
 .p22 = init_csc_coe(0x1fe39),
};
static struct dpu_ov_csc_coef g_yuv_2_p3_601narrow = {
 .idc0 = {
  .reg = {
   .csc_idc0 = 0x600,
   .csc_idc1 = 0x600,
  },
 },
 .idc2 = init_csc_coe(0x7c0),
 .odc0 = {
  .reg = {
   .csc_odc0 = 0x00000,
   .csc_odc1 = 0x00000,
  },
 },
 .odc2 = init_csc_coe(0x00000),
 .p00 = init_csc_coe(0x4a85),
 .p01 = init_csc_coe(0x1fb8c),
 .p02 = init_csc_coe(0x04ac6),
 .p10 = init_csc_coe(0x4a85),
 .p11 = init_csc_coe(0x1e7c2),
 .p12 = init_csc_coe(0x1d116),
 .p20 = init_csc_coe(0x4a85),
 .p21 = init_csc_coe(0x073bc),
 .p22 = init_csc_coe(0x1fdfa),
};
static struct dpu_ov_csc_coef g_yuv_2_p3_709wide = {
 .idc0 = {
  .reg = {
   .csc_idc0 = 0x600,
   .csc_idc1 = 0x600,
  },
 },
 .idc2 = init_csc_coe(0x000),
 .odc0 = {
  .reg = {
   .csc_odc0 = 0x000,
   .csc_odc1 = 0x000,
  },
 },
 .odc2 = init_csc_coe(0x000),
 .p00 = init_csc_coe(0x4000),
 .p01 = init_csc_coe(0x1fddf),
 .p02 = init_csc_coe(0x04d93),
 .p10 = init_csc_coe(0x4000),
 .p11 = init_csc_coe(0x1f469),
 .p12 = init_csc_coe(0x1e661),
 .p20 = init_csc_coe(0x4000),
 .p21 = init_csc_coe(0x06b43),
 .p22 = init_csc_coe(0x1ff8d),
};
static struct dpu_ov_csc_coef g_yuv_2_p3_709narrow = {
 .idc0 = {
  .reg = {
   .csc_idc0 = 0x600,
   .csc_idc1 = 0x600,
  },
 },
 .idc2 = init_csc_coe(0x7c0),
 .odc0 = {
  .reg = {
   .csc_odc0 = 0x000,
   .csc_odc1 = 0x000,
  },
 },
 .odc2 = init_csc_coe(0x000),
 .p00 = init_csc_coe(0x4a85),
 .p01 = init_csc_coe(0x1fd94),
 .p02 = init_csc_coe(0x0584f),
 .p10 = init_csc_coe(0x4a85),
 .p11 = init_csc_coe(0x1f2ce),
 .p12 = init_csc_coe(0x1e2d6),
 .p20 = init_csc_coe(0x4a85),
 .p21 = init_csc_coe(0x07a1c),
 .p22 = init_csc_coe(0x1ff7e),
};
static struct dpu_ov_csc_coef g_yuv_2_rgb_bt2020 = {
 .idc0 = {
  .reg = {
   .csc_idc0 = 0x00600,
   .csc_idc1 = 0x00600,
  },
 },
 .idc2 = init_csc_coe(0x007C0),
 .odc0 = {
  .reg = {
   .csc_odc0 = 0x00000,
   .csc_odc1 = 0x00000,
  },
 },
 .odc2 = init_csc_coe(0x00000),
 .p00 = init_csc_coe(0x04A85),
 .p01 = init_csc_coe(0x00000),
 .p02 = init_csc_coe(0x06B6F),
 .p10 = init_csc_coe(0x04A85),
 .p11 = init_csc_coe(0x1F402),
 .p12 = init_csc_coe(0x1D65F),
 .p20 = init_csc_coe(0x04A85),
 .p21 = init_csc_coe(0x08912),
 .p22 = init_csc_coe(0x00000),
};
static struct dpu_ov_csc_coef g_yuv_2_rgb_bt2020wide = {
 .idc0 = {
  .reg = {
   .csc_idc0 = 0x00600,
   .csc_idc1 = 0x00600,
  },
 },
 .idc2 = init_csc_coe(0x000),
 .odc0 = {
  .reg = {
   .csc_odc0 = 0x00000,
   .csc_odc1 = 0x00000,
  },
 },
 .odc2 = init_csc_coe(0x00000),
 .p00 = init_csc_coe(0x04000),
 .p01 = init_csc_coe(0x00000),
 .p02 = init_csc_coe(0x05E5F),
 .p10 = init_csc_coe(0x04000),
 .p11 = init_csc_coe(0x1F579),
 .p12 = init_csc_coe(0x1DB70),
 .p20 = init_csc_coe(0x04000),
 .p21 = init_csc_coe(0x07868),
 .p22 = init_csc_coe(0x00000),
};
static struct dpu_ov_csc_coef g_yuv_2_rgb_bt2020narrow = {
 .idc0 = {
  .reg = {
   .csc_idc0 = 0x00600,
   .csc_idc1 = 0x00600,
  },
 },
 .idc2 = init_csc_coe(0x007C0),
 .odc0 = {
  .reg = {
   .csc_odc0 = 0x00000,
   .csc_odc1 = 0x00000,
  },
 },
 .odc2 = init_csc_coe(0x00000),
 .p00 = init_csc_coe(0x04ABD),
 .p01 = init_csc_coe(0x00000),
 .p02 = init_csc_coe(0x06BC0),
 .p10 = init_csc_coe(0x04ABD),
 .p11 = init_csc_coe(0x1F3FA),
 .p12 = init_csc_coe(0x1D641),
 .p20 = init_csc_coe(0x04ABD),
 .p21 = init_csc_coe(0x0897A),
 .p22 = init_csc_coe(0x00000),
};
static struct dpu_ov_csc_coef g_rgb_2_yuv_601wide = {
 .idc0 = {
  .reg = {
   .csc_idc0 = 0x000,
   .csc_idc1 = 0x000,
  },
 },
 .idc2 = init_csc_coe(0),
 .odc0 = {
  .reg = {
   .csc_odc0 = 0x200,
   .csc_odc1 = 0x200,
  },
 },
 .odc2 = init_csc_coe(0x000),
 .p00 = init_csc_coe(0x01323),
 .p01 = init_csc_coe(0x02591),
 .p02 = init_csc_coe(0x0074c),
 .p10 = init_csc_coe(0x1f533),
 .p11 = init_csc_coe(0x1eacd),
 .p12 = init_csc_coe(0x02000),
 .p20 = init_csc_coe(0x02000),
 .p21 = init_csc_coe(0x1e534),
 .p22 = init_csc_coe(0x1facc),
};
static struct dpu_ov_csc_coef g_rgb_2_yuv_601narrow = {
 .idc0 = {
  .reg = {
   .csc_idc0 = 0x000,
   .csc_idc1 = 0x000,
  },
 },
 .idc2 = init_csc_coe(0x000),
 .odc0 = {
  .reg = {
   .csc_odc0 = 0x200,
   .csc_odc1 = 0x200,
  },
 },
 .odc2 = init_csc_coe(0x040),
 .p00 = init_csc_coe(0x0106f),
 .p01 = init_csc_coe(0x02044),
 .p02 = init_csc_coe(0x00644),
 .p10 = init_csc_coe(0x1f684),
 .p11 = init_csc_coe(0x1ed60),
 .p12 = init_csc_coe(0x01c1c),
 .p20 = init_csc_coe(0x01c1c),
 .p21 = init_csc_coe(0x1e876),
 .p22 = init_csc_coe(0x1fb6e),
};
static struct dpu_ov_csc_coef g_rgb_2_yuv_709wide = {
 .idc0 = {
  .reg = {
   .csc_idc0 = 0x000,
   .csc_idc1 = 0x000,
  },
 },
 .idc2 = init_csc_coe(0x000),
 .odc0 = {
  .reg = {
   .csc_odc0 = 0x200,
   .csc_odc1 = 0x200,
  },
 },
 .odc2 = init_csc_coe(0x000),
 .p00 = init_csc_coe(0x00d9b),
 .p01 = init_csc_coe(0x02dc6),
 .p02 = init_csc_coe(0x0049f),
 .p10 = init_csc_coe(0x1f8ab),
 .p11 = init_csc_coe(0x1e755),
 .p12 = init_csc_coe(0x02000),
 .p20 = init_csc_coe(0x02000),
 .p21 = init_csc_coe(0x1e2ef),
 .p22 = init_csc_coe(0x1fd11),
};
static struct dpu_ov_csc_coef g_rgb_2_yuv_709narrow = {
 .idc0 = {
  .reg = {
   .csc_idc0 = 0x000,
   .csc_idc1 = 0x000,
  },
 },
 .idc2 = init_csc_coe(0x000),
 .odc0 = {
  .reg = {
   .csc_odc0 = 0x200,
   .csc_odc1 = 0x200,
  },
 },
 .odc2 = init_csc_coe(0x040),
 .p00 = init_csc_coe(0x00baf),
 .p01 = init_csc_coe(0x02750),
 .p02 = init_csc_coe(0x003f8),
 .p10 = init_csc_coe(0x1f98f),
 .p11 = init_csc_coe(0x1ea55),
 .p12 = init_csc_coe(0x01c1c),
 .p20 = init_csc_coe(0x01c1c),
 .p21 = init_csc_coe(0x1e678),
 .p22 = init_csc_coe(0x1fd6c),
};
static struct dpu_ov_csc_coef g_rgb_2_yuv_bt2020 = {
 .idc0 = {
  .reg = {
   .csc_idc0 = 0x00600,
   .csc_idc1 = 0x00600,
  },
 },
 .idc2 = init_csc_coe(0x00000),
 .odc0 = {
  .reg = {
   .csc_odc0 = 0x00000,
   .csc_odc1 = 0x00000,
  },
 },
 .odc2 = init_csc_coe(0x00000),
 .p00 = init_csc_coe(0x04000),
 .p01 = init_csc_coe(0x00000),
 .p02 = init_csc_coe(0x00000),
 .p10 = init_csc_coe(0x00000),
 .p11 = init_csc_coe(0x04000),
 .p12 = init_csc_coe(0x00000),
 .p20 = init_csc_coe(0x00000),
 .p21 = init_csc_coe(0x00000),
 .p22 = init_csc_coe(0x04000),
};
static struct dpu_ov_csc_coef g_rgb_2_yuv_2020wide = {
 .idc0 = {
  .reg = {
   .csc_idc0 = 0x000,
   .csc_idc1 = 0x000,
  },
 },
 .idc2 = init_csc_coe(0x000),
 .odc0 = {
  .reg = {
   .csc_odc0 = 0x200,
   .csc_odc1 = 0x200,
  },
 },
 .odc2 = init_csc_coe(0x000),
 .p00 = init_csc_coe(0x010D0),
 .p01 = init_csc_coe(0x02B65),
 .p02 = init_csc_coe(0x003CB),
 .p10 = init_csc_coe(0x1F710),
 .p11 = init_csc_coe(0x1E8EF),
 .p12 = init_csc_coe(0x02000),
 .p20 = init_csc_coe(0x02000),
 .p21 = init_csc_coe(0x1E292),
 .p22 = init_csc_coe(0x1FD6D),
};
static struct dpu_ov_csc_coef g_rgb_2_yuv_2020narrow = {
 .idc0 = {
  .reg = {
   .csc_idc0 = 0x000,
   .csc_idc1 = 0x000,
  },
 },
 .idc2 = init_csc_coe(0x000),
 .odc0 = {
  .reg = {
   .csc_odc0 = 0x200,
   .csc_odc1 = 0x200,
  },
 },
 .odc2 = init_csc_coe(0x040),
 .p00 = init_csc_coe(0x00E65),
 .p01 = init_csc_coe(0x02529),
 .p02 = init_csc_coe(0x00340),
 .p10 = init_csc_coe(0x1F82C),
 .p11 = init_csc_coe(0x1EBCD),
 .p12 = init_csc_coe(0x01C07),
 .p20 = init_csc_coe(0x01C07),
 .p21 = init_csc_coe(0x1E63A),
 .p22 = init_csc_coe(0x1FDBF),
};
static struct dpu_ov_csc_coef g_srgb_2_p3 = {
 .idc0 = {
  .reg = {
   .csc_idc0 = 0x00000,
   .csc_idc1 = 0x00000,
  },
 },
 .idc2 = init_csc_coe(0x00000),
 .odc0 = {
  .reg = {
   .csc_odc0 = 0x00000,
   .csc_odc1 = 0x00000,
  },
 },
 .odc2 = init_csc_coe(0x00000),
 .p00 = init_csc_coe(0x034A3),
 .p01 = init_csc_coe(0x00B5D),
 .p02 = init_csc_coe(0x00000),
 .p10 = init_csc_coe(0x00220),
 .p11 = init_csc_coe(0x03DE0),
 .p12 = init_csc_coe(0x00000),
 .p20 = init_csc_coe(0x00118),
 .p21 = init_csc_coe(0x004A2),
 .p22 = init_csc_coe(0x03A46),
};
struct CscCoef {
    DPU_VSCF_CSC_IDC0_UNION idc0;
    DPU_VSCF_CSC_IDC2_UNION idc2;
    DPU_VSCF_CSC_ODC0_UNION odc0;
    DPU_VSCF_CSC_ODC2_UNION odc2;
    DPU_VSCF_CSC_P00_UNION p00;
    DPU_VSCF_CSC_P01_UNION p01;
    DPU_VSCF_CSC_P02_UNION p02;
    DPU_VSCF_CSC_P10_UNION p10;
    DPU_VSCF_CSC_P11_UNION p11;
    DPU_VSCF_CSC_P12_UNION p12;
    DPU_VSCF_CSC_P20_UNION p20;
    DPU_VSCF_CSC_P21_UNION p21;
    DPU_VSCF_CSC_P22_UNION p22;
};
#endif
