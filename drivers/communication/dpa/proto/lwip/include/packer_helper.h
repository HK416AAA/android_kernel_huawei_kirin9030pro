#ifndef PACKER_HELPER_H
#define PACKER_HELPER_H
#include "packer.h"

int packer_begin_callback(struct packer_buffer *buffer, unsigned int service_id, unsigned int function_id, void *cb,
                          void *priv);
int packer_begin(struct packer_buffer *buffer, unsigned int service_id, unsigned int function_id);
void packer_end(struct packer_buffer *buffer);

#endif