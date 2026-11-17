#ifndef __DDR_REG_OP_H__
#define __DDR_REG_OP_H__ 
#include "ddr_reg_op_include.h"
#include "ddr_reg_op_sys.h"
#include "ddr_reg_op_dmss.h"
#include "ddr_reg_op_exmbist.h"
#include "ddr_reg_op_dmc.h"
#include "ddr_reg_op_packphy.h"
#include "ddr_reg_op_uce.h"
#include "ddr_reg_op_xpu.h"
#include "ddr_reg_op_qice_extend.h"
#include "ddr_reg_op_qice/ddr_reg_op_qice_total.h"
#define PHASE_64_48_mission(n) ((((n)>>2) - ((((n)>>2)+1)>>2))<<2)
#endif
