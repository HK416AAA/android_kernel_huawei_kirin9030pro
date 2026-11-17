
#ifndef __SENSOR_SDC_MMAP_H__
#define __SENSOR_SDC_MMAP_H__

#include <linux/fs.h>
#include <linux/mm.h>

int set_sensor_sdc_mmap(struct file *filp, struct vm_area_struct *vma);

#endif