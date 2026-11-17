#ifndef __DICE_STRUCT_H__
#define __DICE_STRUCT_H__ 
#include <stdint.h>
#include <stddef.h>
#define DICE_CERT_VALUE_MAX_SIZE (1024)
#define DICE_CERTS_MAX_NUM (48)
#define DICE_MAGIC (0x45434944)
#define DICE_IMAGE_NAME_SIZE (20)
#define DICE_RESERVE0_BYTES (16)
#define DICE_RESERVE1_BYTES (480)
#define DICE_RESERVE2_BYTES (2)
#define get_dice_cert_offset(index) \
 (offsetof(struct dice_cert_chain, certs) + (index) * sizeof(struct dice_cert_value))
struct dice_cert_value {
 uint8_t value[DICE_CERT_VALUE_MAX_SIZE];
};
struct cert_info {
 uint8_t image_name[DICE_IMAGE_NAME_SIZE];
 uint32_t offset;
 uint32_t size;
 uint8_t layer;
 uint8_t parent;
 uint8_t reserve2[DICE_RESERVE2_BYTES];
};
struct dice_cert_chain {
 uint32_t magic;
 uint32_t version;
 uint32_t certs_num;
 uint32_t certs_max;
 uint8_t reserve0[DICE_RESERVE0_BYTES];
 struct cert_info certs_info[DICE_CERTS_MAX_NUM];
 uint8_t reserve1[DICE_RESERVE1_BYTES];
 struct dice_cert_value certs[DICE_CERTS_MAX_NUM];
} __attribute__((__packed__));
#endif
