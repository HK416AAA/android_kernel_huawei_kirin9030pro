

#include "sensor_sdc_mmap.h"
#include "contexthub_route.h"
#include "asm/pgtable.h"
#include <linux/err.h>
#include <platform_include/smart/linux/sdc.h>

int set_sensor_sdc_mmap(struct file *filp, struct vm_area_struct *vma)
{
#ifdef CONFIG_SENSOR_DIRECT_CHANNEL
	hwlog_info("set_sensor_sdc_mmap:%s start.", __func__);
	unsigned long page = 0;
	unsigned long size;
	int ret;
	if ((filp == NULL) || (vma == NULL)) {
		hwlog_err("set_sensor_sdc_mmap:%s: param NULL\n", __func__);
		return -EFAULT;
	}
	if ((vma->vm_start == 0) || (vma->vm_start >= vma->vm_end)) {
		hwlog_err("set_sensor_sdc_mmap:%s: invalid vm address\n", __func__);
		return -EINVAL;
	}
	size = vma->vm_end - vma->vm_start;
	struct sdc_mem_info *imu_info = NULL;
	imu_info = sdc_buf_get();
	if (imu_info == NULL) {
		hwlog_err("set_sensor_sdc_mmap:%s: sdc buffer get fail", __FUNCTION__);
		return -EINVAL;
	}
	if (size != imu_info->size) {
		hwlog_err("set_sensor_sdc_mmap:%s: invalid sensor buffer size[0x%x]\n", __func__, size);
		return -EINVAL;
	}
	page = imu_info->phy_addr;
	vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);  // 设置为non cache
	// vma 用户空间的vma vma->vm_start 目标用户空间的地址起始位置
	// (page >> PAGE_SHIFT) 内核空间的物理地址 size 映射的空间大小 vma->vm_page_prot 映射的保护flg
	ret = remap_pfn_range(vma, vma->vm_start, (page >> PAGE_SHIFT), size, vma->vm_page_prot);
	if (ret != 0) {
		hwlog_err("set_sensor_sdc_mmap:%s: map fail, ret[%d]\n", __func__, ret);
		return -ENOMEM;
	}
	hwlog_info("set_sensor_sdc_mmap:%s: sdc map done, size[0x%x] prot[0x%x]\n",
		__func__,  size, vma->vm_page_prot);
	return 0;
#else
	hwlog_info("set_sensor_sdc_mmap:%s platform not support sdc.", __func__);
	return EINVAL;
#endif
}