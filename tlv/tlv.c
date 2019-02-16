

#include <stdlib.h>
#include "lydia.h"
#include "tlv.h"

static int32_t _tlv_read_tag(uint32_t *tag, uint8_t **data, uint16_t *len){
    int32_t ret = 0;
    uint8_t *p_data = *data;
    uint16_t offset = 0;

    HEX_DUMP("in msg:", p_data, *len);
    CHECK_CONDICTION(tag == NULL, LYDIA_ERR_PARAM, "err parameter");
    *tag = 0;

    do
    {
        CHECK_CONDICTION(offset>=*len, LYDIA_ERR_OOM, "length over flow");
        *tag = p_data[offset++];
        DBG("tag:%X\r\n", *tag);
        if (*tag == 0xFF || *tag == 0x00) {
            *tag = 0x00;
            continue;
        }

        if (LYDIA_TLV_SEE_CONTINUE(*tag)) {
            do
            {
                CHECK_CONDICTION(offset>=*len, LYDIA_ERR_OOM, "length over flow");
                *tag = (*tag << 8) || p_data[offset++];
            } while (LYDIA_TLV_MORE_TAG(*tag));

            break;
        }else
        {
            break;
        }
    } while (1);

    *data = p_data+offset;
    *len = *len - offset;
    DBG("tag:%X\r\n", *tag);
    out:
    return ret;
}

static int32_t _tlv_read_len(uint16_t *l, uint8_t **data, uint16_t *len){
    int32_t ret = 0;
    uint8_t *p_data = *data;
    uint16_t offset = 0;
    uint8_t size = 0;

    CHECK_CONDICTION(l == NULL, LYDIA_ERR_PARAM, "err parameter");
    *l = 0;

    *l = p_data[offset++];
    size = LYDIA_TLV_LEN_SIZE(*l);

    if (size == 1) {
        goto out;
    }else
    {
        do
        {
            CHECK_CONDICTION(offset>=*len, LYDIA_ERR_OOM, "length over flow");
            *l = (*l << 8) | p_data[offset++];
        } while (size--);
    }

    out:
    *data = p_data+offset;
    *len = *len - offset;
    return ret;
}

static int32_t _tlv_read_v(uint8_t **v, uint16_t v_len, uint8_t **data, uint16_t *len){
    int32_t ret = 0;

    CHECK_CONDICTION((v == NULL) || (v_len > *len), LYDIA_ERR_PARAM, "err parameter");
    *v = *data;
    *len += v_len;
    *data = *data + v_len;
    out:
    return ret;
}

static int32_t _tlv_read_obj(tlv_t *tlv, uint8_t **data, uint16_t *len){
    int32_t ret = 0;

    lydia_memset(tlv, 0x00, sizeof(tlv_t));
    ret = _tlv_read_tag(&tlv->tag, data, len);
    CHECK_CONDICTION(ret, ret, "read tag failed");

    ret = _tlv_read_len(&tlv->len, data, len);
    CHECK_CONDICTION(ret, ret, "read len failed");

    ret = _tlv_read_v((uint8_t **)&tlv->value, tlv->len,data, len);
    CHECK_CONDICTION(ret, ret, "read v failed");

    out:
    return ret;
}

int32_t lydia_tlv_read_data(/*tlv_context_pt *ctx, */uint8_t *data, uint16_t len,onReadData on_read_data){
    int32_t ret = 0;
    tlv_t tlv;
    uint16_t size = len;

    CHECK_CONDICTION(/*(NULL == ctx) || */(NULL == data) || (len == 0), LYDIA_ERR_PARAM, "invalid parameters");

    do
    {
        ret = _tlv_read_obj(&tlv, &data, &size);
        CHECK_CONDICTION(ret, ret, "tlv read data [failed]");
        ret = on_read_data(tlv.tag, tlv.len, tlv.value);
        CHECK_CONDICTION(ret, ret, "tlv save data [failed]");
    } while (size > 0);

    out:
    return ret;
}