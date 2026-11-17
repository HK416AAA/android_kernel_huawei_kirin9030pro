
#ifndef HISP_CLOCK_MANAGER_H
#define HISP_CLOCK_MANAGER_H

#define ISP_CPU_CLK       0
#define ISP_FUNC_CLK      1
#define ISP_FUNC2_CLK     2
#define ISP_FUNC3_CLK     3

int hisp_clock_manager_init(struct device *dev);
int hisp_clock_manager_deinit(struct device *dev);

int hisp_clock_pwr_enable(void);
void hisp_clock_pwr_disable(void);

int hisp_clock_set_rate(unsigned int type, unsigned int rate);

#endif /* HISP_CLOCK_MANAGER_H */

