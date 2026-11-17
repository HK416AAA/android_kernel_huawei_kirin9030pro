#include "hts_tzsp.h"
#include "hts_kernel_log.h"
#include <linux/arm-smccc.h>

noinline int tzsp_service_hts_smc(uint64_t _service_id, uint64_t _cmd, uint64_t _arg1, uint64_t _arg2)
{
	int ret;
	struct ffa_send_direct_data args = {
		.data0 = (unsigned long)_service_id,
		.data1 = (unsigned long)_cmd,
		.data2 = (unsigned long)_arg1,
		.data3 = (unsigned long)_arg2,
		.data4 = 0
	};

	ret = ffa_platdrv_send_msg(&args);
	if (ret != 0 || args.data4 != 0) {
		hts_drv_err("ffa platdrv send msg error, service_id = 0x%llx, ret = %d, data4 = 0x%llx\n",
			_service_id, ret, args.data4);
		return (int)args.data4;
	}
	return ret;
}