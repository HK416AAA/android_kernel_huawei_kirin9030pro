#ifndef __IODIE_DDR_CONFIG_H__
#define __IODIE_DDR_CONFIG_H__ 
#define IODIE_APB0_AO_REGION_NUM 6
#define IODIE_APB1_AO_REGION_NUM 6
#define IODIE_FW_PERI_REGION_NUM 22
#define IODIE_IOMUX_NUM 127
#define IODIE_IOMUX_ELEMENT_NUM 7
#define IODIE_MAX_MID 15
#define IODIE_MID_GROUP_NUM 4
#define IODIE_4K_BASED_NUM 25
#define IODIE_ADDR_REGION_NUM 128
#define IODIE_CONFIG_VALID_FLAG 0xCACACA01
#define IODIE_CONFIG_INVALID_FLAG 0xCACACA00
struct iodie_base_config {
 unsigned char iodie_type;
 unsigned char lowpower_type;
 unsigned char iodie_clk;
 unsigned char irq_gpio_pinmut;
 unsigned int irq_gpio_ap;
 unsigned int irq_gpio_sh;
 unsigned int rst_gpio_ap;
 unsigned char board_type;
};
union iodie_mid_map {
 unsigned int value;
 struct {
  unsigned int mid0 : 8;
  unsigned int mid1 : 8;
  unsigned int mid2 : 8;
  unsigned int mid3 : 8;
 } reg;
};
struct iodie_axi_user_map {
 unsigned int user;
 unsigned int mid;
 unsigned int addr_id;
};
struct iodie_hiphyio_config {
 unsigned int ecc_mode;
 unsigned int ecc_scramble_en;
 unsigned int data_scramble_en;
 unsigned int encode_en;
 unsigned int lane_num;
 unsigned int log_level;
 unsigned int i3c_debug;
 unsigned int iomux_hiphy;
 unsigned int iomux_1to3;
 unsigned int spi_used;
 unsigned int spi_cs01_sec;
 unsigned int spi_clk_div0;
 unsigned int spi_clk_div1;
 unsigned int spi_cs2_sec;
 unsigned int i2s_used;
 union iodie_mid_map mid_map[IODIE_MID_GROUP_NUM];
 struct iodie_axi_user_map axi_map[IODIE_4K_BASED_NUM];
};
struct iodie_mid_region {
 unsigned int start_addr;
 unsigned int end_addr;
 unsigned int mid;
};
struct iodie_sec_config {
 unsigned int status;
 unsigned int tzpc_ao;
 unsigned int tzpc_peri;
 unsigned int tzpc_ram;
 unsigned int tzpc_ioc0;
 unsigned int tzpc_ioc1;
 unsigned int tzpc_ioc2;
 unsigned int tzpc_peri_unlock;
 unsigned int tzpc_lock;
 unsigned int fw_apb0_ao_cfg;
 unsigned int fw_apb0_ao_lock;
 unsigned int fw_apb1_ao_cfg;
 unsigned int fw_apb1_ao_lock;
 unsigned int fw_peri_cfg;
 unsigned int fw_peri_lock;
 unsigned int fw_ram_cfg;
 unsigned int fw_ram_lock;
 unsigned int fw_apb_peri_cfg;
 unsigned int fw_apb_peri_lock;
 unsigned int dma_cfg;
 struct iodie_mid_region apb0_ao_region[IODIE_APB0_AO_REGION_NUM];
 struct iodie_mid_region apb1_ao_region[IODIE_APB1_AO_REGION_NUM];
 struct iodie_mid_region fw_peri_region[IODIE_FW_PERI_REGION_NUM];
};
struct iodie_iomux_config {
 unsigned int schmidt : 4;
 unsigned int driver : 4;
 unsigned int slew_rate : 4;
 unsigned int pull_type : 4;
 unsigned int func : 8;
 unsigned int gpio_dir : 4;
 unsigned int output_val : 4;
};
struct iodie_drv_config {
 unsigned char clk_delay_flag;
};
struct iodie_config {
 struct iodie_base_config base;
 unsigned int valid_flag;
 struct iodie_hiphyio_config hiphyio;
 struct iodie_sec_config sec;
 struct iodie_iomux_config iomux[IODIE_IOMUX_NUM];
 struct iodie_drv_config drv;
};
#endif
