/*
 * resume.c
 *
 * hibernate resume driver for power
 *
 * Copyright (c) 2023-2024 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/kobject.h>
#include <platform_include/basicplatform/linux/nve/nve_ap_kernel_interface.h>
#include <securec.h>

#define RESUME "STD_PARA"
#define RESUME_NV_NUM 464

#define RESUME_LEN 60

static struct kobject *resume_kobj;

static ssize_t resume_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
    int ret;
    int len;
    uint64_t offset;
    char resume[RESUME_LEN] = {0};
    char nvData[NVE_NV_DATA_SIZE] = {0};
    struct opt_nve_info_user nve;

    ret = sscanf_s(buf, "%llu:%s", &offset, resume, RESUME_LEN - 1);
    if (ret != 2) {
        pr_err("[%s] sscanf buf failed!\n", __func__);
        return ret;
    }

    len = snprintf_s(nvData, NVE_NV_DATA_SIZE, NVE_NV_DATA_SIZE - 1, "resume=%s resume_offset=%llu ", resume, offset);
    if ((len < 0) || (len > (sizeof(nve.nv_data) -1))) {
        pr_err("[%s] snprintf resume and resume offset failed!\n", __func__);
		return len;
    }

    ret = memset_s(&nve, sizeof(nve), 0, sizeof(nve));
    if (ret != 0) {
        pr_err("[%s] memset nve failed!\n", __func__);
		return ret;
	}

    nve.nv_number = RESUME_NV_NUM;
	nve.valid_size = len;
    nve.nv_operation = NV_WRITE;
    ret = strncpy_s(nve.nv_name, NV_NAME_LENGTH, RESUME, NV_NAME_LENGTH - 1);
    if (ret != 0) {
        pr_err("[%s] strncpy nv name failed!\n", __func__);
		return ret;
	}
    ret = memcpy_s(nve.nv_data, sizeof(nve.nv_data), nvData, len);
	if (ret != 0) {
        pr_err("[%s] memcpy resume info failed!\n", __func__);
		return ret;
	}

    ret = nve_direct_access_interface(&nve);
    if (ret) {
        pr_err("[%s]write resume to nv failed, ret = %d\n", __func__, ret);
        return ret;
    }

    return count;
}

#define mm_vltmm_attr_rw(_name, _mode, _show, _store) \
struct kobj_attribute _name##_attr = {   \
	.attr	= {                                 \
		    .name = __stringify(_name),         \
		    .mode = _mode,                      \
	},                                          \
	.show	= _show,                            \
	.store	= _store,                           \
}
static mm_vltmm_attr_rw(resume, 0660, NULL, resume_store);

static struct attribute *resume_dev_attrs[] = {
    &resume_attr.attr,
	NULL,
};

static const struct attribute_group resume_sysfs_attr_group = {
	.attrs = resume_dev_attrs,
};

static int __init resume_init(void)
{
    int ret;

	resume_kobj = kobject_create_and_add("hibernate", NULL);
    if (!resume_kobj) {
        pr_err("[%s] create kobject failed\n", __func__);
		return -ENOMEM;
    }

    ret = sysfs_create_group(resume_kobj, &resume_sysfs_attr_group);
	if (ret < 0) {
		pr_err("[%s] register sysfs resume failed\n", __func__);
        kobject_put(resume_kobj);
    }

	return 0;
}

static void __exit resume_exit(void)
{
	sysfs_remove_group(resume_kobj, &resume_sysfs_attr_group);
}

module_init(resume_init);
module_exit(resume_exit);

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");