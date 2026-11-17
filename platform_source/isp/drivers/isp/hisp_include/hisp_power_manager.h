
#ifndef HISP_POWER_MANAGER_H
#define HISP_POWER_MANAGER_H

enum isp_pwstat_e {
	PWSTAT_MEDIA	= 0,
	PWSTAT_ISPSYS	= 1,
	PWSTAT_MAX
};

int hisp_pwr_get_isppwr_state(unsigned int type);

#endif /* HISP_POWER_MANAGER_H */

