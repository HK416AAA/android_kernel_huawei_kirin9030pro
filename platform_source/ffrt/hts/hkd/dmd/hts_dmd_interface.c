#include "hts_dmd_interface.h"
#if defined(CONFIG_HUAWEI_DSM) || defined(CONFIG_HISYSEVENT)
#include <dsm/dsm_pub.h>
#endif
#include "hts_kernel_log.h"
#include "securec.h"

#if defined(CONFIG_HUAWEI_DSM) || defined(CONFIG_HISYSEVENT)
static struct dsm_client *hts_dsm_client = NULL;
#endif

#ifdef CONFIG_HISYSEVENT
int hts_errorno_to_str(int error_no, char *str, int bufflen) {
	int i;
	struct error_no_map hts_error_no_map[] = {
		{KERN_HTS_IBUFOVERFLOW_ERROR, "KERN_HTS_IBUFOVERFLOW_ERROR"},
		{KERN_HTS_OBUFOVERFLOW_ERROR, "KERN_HTS_OBUFOVERFLOW_ERROR"},
	};
	size_t hts_error_no_map_len = sizeof(hts_error_no_map) / sizeof(hts_error_no_map[0]);
	errno_t ret = 0;

	for (i = 0; i < hts_error_no_map_len; i++) {
		if (hts_error_no_map[i].error_no == error_no) {
			if (strlen(hts_error_no_map[i].name) >= bufflen) return -1;
			ret = strncpy_s(str, bufflen, hts_error_no_map[i].name, bufflen - 1);
			cond_return_error(ret != EOK, -1, "strncpy_s error.\n");
			hts_drv_err("match ok, str = %s", str);
			return 0;
		}
	}
	return -1;
}

struct dsm_client_ops hts_dsm_ops = {
	.poll_state = NULL,
	.dump_func = NULL,
	.errorno_to_str = hts_errorno_to_str,
};

static struct dsm_dev dev_hts = {
	.name = "DSM_HTS",
	.device_name = NULL,
	.ic_name = NULL,
	.module_name = NULL,
	.fops = &hts_dsm_ops,
	.buff_size = DSM_HTS_BUF_SIZE,
};
#elif defined(CONFIG_HUAWEI_DSM)
struct dsm_client_ops hts_dsm_ops = {
	.poll_state = NULL,
	.dump_func = NULL,
};

static struct dsm_dev dev_hts = {
	.name = "dsm_hts",
	.device_name = NULL,
	.ic_name = NULL,
	.module_name = NULL,
	.fops = NULL,
	.buff_size = DSM_HTS_BUF_SIZE,
};
#endif

static int hts_dmd_record_and_notify(int event_id, const char* record_info)
{
#if defined(CONFIG_HUAWEI_DSM) || defined(CONFIG_HISYSEVENT)
		if (hts_dsm_client != NULL && (dsm_client_ocuppy(hts_dsm_client) == 0)) {
			dsm_client_record(hts_dsm_client, record_info);
			dsm_client_notify(hts_dsm_client, event_id);
			hts_drv_err("[I/DSM] %s dmd report\n", hts_dsm_client->client_name);
		}
#endif
	return 0;
}

int sd_proxy_hts_record_and_notify(unsigned int minor_cmd)
{
	int ret = 0;

#if defined(CONFIG_HUAWEI_OHOS_DSM) || defined(CONFIG_HUAWEI_DSM)
	switch (minor_cmd) {
		case SD_PROXY_MINOR_CMD_FFRT_HTS_DMD_INBUF_OVERFLOW:
			ret = hts_dmd_record_and_notify(KERN_HTS_IBUFOVERFLOW_ERROR, "HTS IBUFOVERFLOW ERROR");
			break;
		case SD_PROXY_MINOR_CMD_FFRT_HTS_DMD_ONBUF_OVERFLOW:
			ret = hts_dmd_record_and_notify(KERN_HTS_OBUFOVERFLOW_ERROR, "HTS OBUFOVERFLOW ERROR");
			break;
		default:
			ret = -1;
			hts_drv_err("hts manor_cmd is invalid, %d\n", minor_cmd);
			break;
	}
#else
	hts_drv_err("not supported dmd\n");
#endif
	return ret;
}

int hts_dmd_init(void)
{
	hts_drv_warn("hts_dmd_init start init\n");
#if defined(CONFIG_HUAWEI_OHOS_DSM) || defined(CONFIG_HUAWEI_DSM)
		if (hts_dsm_client == NULL) {
			hts_dsm_client = dsm_register_client(&dev_hts);
			if (hts_dsm_client == NULL)
				hts_drv_err("dsm register client register fail\n");
		}
#endif
	return 0;
}

void hts_dmd_exit(void)
{
	hts_drv_warn("hts_dmd_init start exit\n");
#if defined(CONFIG_HUAWEI_OHOS_DSM) || defined(CONFIG_HUAWEI_DSM)
		if (hts_dsm_client != NULL) {
			dsm_unregister_client(hts_dsm_client, &dev_hts);
		}
#endif
}