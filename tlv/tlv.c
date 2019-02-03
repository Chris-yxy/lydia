

#include <stdlib.h>
#include "lydia.h"
#include "tlv.h"

static int32_t _tlv_read_tag(uint32_t *tag, uint8_t **data, uint16_t *len){
    int32_t ret = 0;

    out:
    return ret;
}

static int32_t _tlv_read_len(uint16_t *l, uint8_t **data, uint16_t *len){
    int32_t ret = 0;

    out:
    return ret;
}

static int32_t _tlv_read_v(uint32_t *tag, uint8_t **data, uint16_t *len){
    int32_t ret = 0;

    out:
    return ret;
}

static int32_t _tlv_read_obj(tlv_t *tlv, uint8_t **data, uint16_t *len){
    int32_t ret = 0;

    lydia_memset(tlv, 0x00, sizeof(tlv_t));
    ret = _tlv_read_tag(&tlv->tag, data, len);
    CHECK_CONDICTION(ret, 0, "read tag failed");

    ret = _tlv_read_len(&tlv->tag, data, len);
    CHECK_CONDICTION(ret, 0, "read len failed");

    ret = _tlv_read_v(&tlv->tag, data, len);
    CHECK_CONDICTION(ret, 0, "read v failed");

    out:
    return ret;
}

int32_t tlv_read_data(tlv_context_pt *ctx, uint8_t *data, uint16_t len,onReadData on_read_data){
    int32_t ret = 0;
    tlv_t tlv;

    if (NULL ==ctx ||
        NULL == data ||
        len==0) {
        ret = -1;
        goto out;
    }


    out:
    return ret;
}