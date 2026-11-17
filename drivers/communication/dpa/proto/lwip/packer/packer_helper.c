#include <bsp_dpa_client.h>
#include <securec.h>
#include "packer_helper.h"

int packer_begin_callback(struct packer_buffer *packer, unsigned int service_id, unsigned int function_id, void *cb,
                          void *priv)
{
    struct dpa_service_msg msg = {
        .service_id = service_id,
        .sub_id = function_id,
        .type = DPA_SERVICE_TYPE_REQUEST_CB,
        .cb.cb = (unsigned long long)(uintptr_t)cb,
        .cb.priv = (unsigned long long)(uintptr_t)priv,
    };

    if (memcpy_s(packer->base + packer->curr, packer_buffer_avail(packer), &msg, sizeof(msg))) {
        return -1;
    }
    packer->curr += sizeof(msg);
    return 0;
}

int packer_begin(struct packer_buffer *packer, unsigned int service_id, unsigned int function_id)
{
    return packer_begin_callback(packer, service_id, function_id, NULL, NULL);
}

void packer_end(struct packer_buffer *packer)
{
    struct dpa_service_msg *hdr = (struct dpa_service_msg *)packer->base;
    hdr->data.len = packer->curr - sizeof(*hdr);
}
