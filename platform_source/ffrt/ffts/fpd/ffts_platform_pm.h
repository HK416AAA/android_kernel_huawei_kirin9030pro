#ifndef _FFTS_PLATFORM_PM_H_
#define _FFTS_PLATFORM_PM_H_

#include <linux/types.h>

int ffts_plat_pm_powerup(uint32_t mode);
int ffts_plat_pm_powerdown(void);

#endif