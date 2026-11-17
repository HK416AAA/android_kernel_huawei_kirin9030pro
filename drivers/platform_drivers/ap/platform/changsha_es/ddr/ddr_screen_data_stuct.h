#ifndef __DDR_SCREEN_DATA_STUCT_H__
#define __DDR_SCREEN_DATA_STUCT_H__ 
struct ddrtest_process_record {
 unsigned int fsm_magic_num;
 unsigned int volt_magic_num;
 unsigned int fsm_current_status;
 unsigned int fsm_type : 1;
 unsigned int err_occur : 1;
 unsigned int fsm_idle : 1;
 unsigned int fsm_test : 1;
 unsigned int fsm_analyse : 1;
 unsigned int fsm_ppr : 1;
 unsigned int fsm_check_ppr : 1;
 unsigned int fsm_biastest : 1;
 unsigned int fsm_done : 1;
 unsigned int reserved : 23;
 unsigned int fsm_vref_item : 4;
 unsigned int fsm_vref_up_down : 4;
 unsigned int fsm_vref_bias_value : 8;
 unsigned int fsm_algo_reserved : 16;
 unsigned int samsung_1x : 1;
};
#endif
