#ifndef __PMU_PARA_STRUCT_H__
#define __PMU_PARA_STRUCT_H__ 
struct pmc_para {
        unsigned short vol_upsteptime;
        unsigned short vol_dnsteptime;
        unsigned short pmu_up_holdtime;
        unsigned short pmu_down_holdtime;
        unsigned char buck_id;
        unsigned char mode_config;
        unsigned char pa_fast;
        unsigned char pa_slow;
};
struct pmu_init_para{
        unsigned char slave_num;
        unsigned char buck_num;
        unsigned int pll_lock_time;
        unsigned char sys_pmu_id;
};
struct pmu_slave_para {
        unsigned short state_addr;
        unsigned char pmu_type;
        unsigned char slave_addr;
        unsigned short rst_gpio;
        unsigned short irq_gpio;
        unsigned char state_reg_num;
        unsigned char volt_step;
        unsigned short volt_base;
        unsigned char bus_type;
        unsigned char mode_cfg;
        unsigned char irq_fer;
        unsigned char fer_pie_bit;
};
struct pmu_buck_para {
        unsigned short vol_addr;
        unsigned short ctrl_addr;
        unsigned short en_state_addr;
        unsigned short on_delay;
        unsigned short off_delay;
        unsigned char slave_id;
        unsigned char en_mask;
        unsigned char vol_mask;
        unsigned char en_state_mask;
        unsigned char mode_cfg;
        unsigned char avs_channel_id;
        unsigned char default_en_value;
        unsigned char reserved1;
        unsigned short reserved2;
};
#define PMU_CLUSTER_NUM 12
#define SLAVE_NUM 5
#define PMU_MAGIC_WORD 0x00756D70
#define DUMP_REG_SIZE 21
struct pmu_dump {
 unsigned int magic_word;
 unsigned char slave_addr;
 unsigned char pmu_type;
 unsigned char power_mask;
 unsigned char reg[DUMP_REG_SIZE];
};
#endif
