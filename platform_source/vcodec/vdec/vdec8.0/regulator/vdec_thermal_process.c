#include "platform_include/cee/linux/thermal_interact_lpmcu.h"
#include "dbg.h"
#include "vcodec_vdec.h"
#include "vcodec_vdec_regulator.h"
#include "vcodec_vdec_plat.h"
#include "vdec_thermal_process.h"

#ifdef ENABLE_VDEC_LOW_TEMP

static void vdec_lowtemp_work(struct work_struct *work __attribute__((__unused__)))
{
	uint32_t clk_level = VDEC_CLK_RATE_LEVEL_MAX;
	uint32_t target_clk_level;
	vdec_entry *vdec = vdec_get_entry();

	vdec_mutex_lock(&vdec->vdec_mutex);
	if (vdec->power_state == false) {
		vdec_mutex_unlock(&vdec->vdec_mutex);
		return;
	}
	clk_level = get_clk_rate();
	target_clk_level = clk_level;
	vdec_plat_get_target_clk_rate(&target_clk_level);
	dprint(PRN_ALWS, "lowtemp clk rate %u", clk_level);
	if (vdec_plat_regulator_set_clk_rate(target_clk_level) != 0) {
		vdec_mutex_unlock(&vdec->vdec_mutex);
		return;
	}
	vdec_plat_set_static_clk_rate(clk_level);
	vdec_mutex_unlock(&vdec->vdec_mutex);
}

static DECLARE_WORK(g_vdec_lowtemp_work, vdec_lowtemp_work);

static int32_t vdec_lowtemp_handler(unsigned int level)
{
	vdec_plat *plt = vdec_plat_get_entry();

	dprint(PRN_ALWS, "device %s low temperature", level ? "into" : "out of");
	plt->low_temp_flag = level ? 1 : 0;
	if (!schedule_work(&g_vdec_lowtemp_work))
		dprint(PRN_ERROR, "schedule work failed");

	return 0;
}

static struct thermal_lpmcu_ops g_thermal_lpmcu_ops = {
	.name = "vdec_lowtemp",
	.lowtemp_thermal_handler = vdec_lowtemp_handler,
};

int32_t vdec_thermal_init(void)
{
    int32_t ret;

    ret = thermal_lpmcu_ops_register(&g_thermal_lpmcu_ops);
    if (ret)
        dprint(PRN_ERROR, "register thermal lpm ops failed");
    else
        dprint(PRN_ALWS, "register thermal lpm ops finish");

    return ret;
}

void vdec_thermal_deinit(void)
{
	thermal_lpmcu_ops_unregister(&g_thermal_lpmcu_ops);
    dprint(PRN_ALWS, "unregister thermal lpm ops finish");
}

#else
int32_t vdec_thermal_init(void){return 0;};
void vdec_thermal_deinit(void){};
#endif
