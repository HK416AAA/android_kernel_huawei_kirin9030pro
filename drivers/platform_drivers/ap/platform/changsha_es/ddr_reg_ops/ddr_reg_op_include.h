#ifndef __DDR_REG_OP_INCLUDE_H__
#define __DDR_REG_OP_INCLUDE_H__ 
unsigned int check_member_status_ddrsys_reg(unsigned int ch0_addr, unsigned int member_mask, unsigned int expect_val_mask);
unsigned int check_member_status_ddrsys_reg_base_mask(unsigned int ch0_addr, unsigned int member_mask, unsigned int expect_val_mask, unsigned int base_mask);
unsigned int check_member_status_ddrsys_reg_single(unsigned int ch0_addr, unsigned int member_mask, unsigned int expect_val_mask, unsigned int ch);
void wait_member_status_ddrsys_reg(unsigned int ch0_addr, unsigned int member_mask, unsigned int expect_val_mask);
void wait_member_status_ddrsys_reg_base_mask(unsigned int ch0_addr, unsigned int member_mask, unsigned int expect_val_mask, unsigned int base_mask);
void wait_member_status_ddrsys_reg_single(unsigned int ch0_addr, unsigned int member_mask, unsigned int expect_val_mask, unsigned int ch);
void write_ddrsys_reg_all(unsigned int reg_val, unsigned int ch0_addr);
void write_ddrsys_reg_base_mask(unsigned int reg_val, unsigned int ch0_addr, unsigned int base_mask);
void write_ddrsys_reg_broadcast(unsigned int reg_val, unsigned int ch0_addr);
void write_ddrsys_reg_single(unsigned int reg_val, unsigned int ch0_addr, unsigned int ch);
void write_dbc_reg_all(unsigned int reg_val, unsigned int ch0_addr);
void write_dbc_reg_base_mask(unsigned int reg_val, unsigned int ch0_addr, unsigned int base_mask);
void write_dbc_reg_single(unsigned int reg_val, unsigned int ch0_addr, unsigned int ch);
void wait_member_status_dbc_reg(unsigned int ch0_addr, unsigned int member_mask, unsigned int expect_val_mask);
void wait_member_status_dbc_reg_base_mask(unsigned int ch0_addr, unsigned int member_mask, unsigned int expect_val_mask, unsigned int base_mask);
void wait_member_status_dbc_reg_single(unsigned int ch0_addr, unsigned int member_mask, unsigned int expect_val_mask, unsigned int ch);
unsigned int check_member_status_dbc_reg(unsigned int ch0_addr, unsigned int member_mask, unsigned int expect_val_mask);
unsigned int check_member_status_dbc_reg_base_mask(unsigned int ch0_addr, unsigned int member_mask, unsigned int expect_val_mask, unsigned int base_mask);
unsigned int check_member_status_dbc_reg_single(unsigned int ch0_addr, unsigned int member_mask, unsigned int expect_val_mask, unsigned int ch);
void write_dmub_reg_all(unsigned int reg_val, unsigned int ch0_addr);
void write_dmub_reg_single(unsigned int reg_val, unsigned int ch0_addr, unsigned int ch);
#endif
