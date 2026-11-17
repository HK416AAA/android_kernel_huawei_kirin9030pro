/*
 * sysfs.c
 *
 * Description: add sysfs interface for exfat
 *
 * Copyright (c) 2024-2024 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include <linux/slab.h>
#include <linux/kobject.h>
#include <linux/atomic.h>
 
#include "exfat_raw.h"
#include "exfat_fs.h"
 
struct exfat_attr {
    struct attribute attr;
};
 
#define EXFAT_RO_ATTR(_name) \
static struct exfat_attr exfat_attr_##_name = { \
    .attr = {.name =  __stringify(_name), .mode = 0444}, \
}
 
EXFAT_RO_ATTR(need_format);
 
/*
 * Note that there is one attribute now:
 * 1) /sys/fs/exfat/<devname>/need_format
 *   : indicate whether the filesystem need format.
 * 
 * We may add other attributes in the future.
 */
#define ATTR_LIST(name) (&exfat_attr_##name.attr)
static struct attribute *exfat_attrs[] = {
    ATTR_LIST(need_format),
    NULL,
};
ATTRIBUTE_GROUPS(exfat);
 
static ssize_t exfat_attr_show(struct kobject *kobj,
			      struct attribute *attr, char *buf)
{
    struct exfat_sb_info *sbi = container_of(kobj, struct exfat_sb_info, s_kobj);
    return sprintf(buf, "%u\n", (unsigned int)atomic_read(&sbi->is_need_format));
}
 
static ssize_t exfat_attr_store(struct kobject *kobj,
           struct attribute *attr,
           const char *buf, size_t len)
{
    return 0;
}
 
static void exfat_sysfs_release(struct kobject *kobj)
{
    struct exfat_sb_info *sbi = container_of(kobj, struct exfat_sb_info, s_kobj);
    complete(&sbi->s_kobj_unregister);
}
 
static const struct sysfs_ops exfat_sysfs_ops = {
	.show	= exfat_attr_show,
	.store	= exfat_attr_store,
};
 
static struct kobj_type exfat_ktype = {
    .default_groups = exfat_groups,
    .sysfs_ops = &exfat_sysfs_ops,
    .release = exfat_sysfs_release,
};
 
static struct kset *exfat_root;
 
int exfat_register_sysfs(struct super_block *sb)
{
    struct exfat_sb_info *sbi = EXFAT_SB(sb);
    int err;
 
    sbi->s_kobj.kset = exfat_root;
    init_completion(&sbi->s_kobj_unregister);
    err = kobject_init_and_add(&sbi->s_kobj, &exfat_ktype, NULL, "%s", sb->s_id);
    if (err) {
        pr_err("kobject_init_and_add failed\n");
        kobject_put(&sbi->s_kobj);
        wait_for_completion(&sbi->s_kobj_unregister);
        return err;
    }
 
    return 0;
}
 
void exfat_unregister_sysfs(struct exfat_sb_info *sbi)
{
    kobject_del(&sbi->s_kobj);
    kobject_put(&sbi->s_kobj);
    wait_for_completion(&sbi->s_kobj_unregister);
}
 
int exfat_sysfs_init(void)
{
    exfat_root = kset_create_and_add("exfat", NULL, fs_kobj);
    return exfat_root == NULL ? -ENOMEM : 0;
}
 
void exfat_sysfs_exit(void)
{
    if (exfat_root != NULL) {
        kset_unregister(exfat_root);
    }
}