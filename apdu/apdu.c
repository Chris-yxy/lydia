#include <stdint.h>

#include "lydia.h"
#include "debug.h"
#include "apdu.h"

static int32_t ladia_apdu_capdu_to_raw(uint8_t *capdu_stream, uint16_t *len, lydia_capdu_t *capdu)
{
    int32_t ret = 0;
    int16_t offset = 0;
    CHECK_CONDICTION((capdu_stream==NULL) || (len==NULL) || (capdu == NULL) ||
                 (*len < (LYDIA_CAPDU_CMD_LEN + 1 + capdu->lc + 1), 
            LYDIA_ERR_PARAM, "ladia_apdu_capdu_to_raw invalid parameters");

    memcpy(capdu_stream, capdu->cmd, LYDIA_CAPDU_CMD_LEN);
    offset += LYDIA_CAPDU_CMD_LEN;

    if (capdu->lc > 0) {
        capdu_stream[offset++] =  capdu->lc & 0xFF;
        memcpy(capdu_stream+offset, capdu->data, capdu->lc);
        offset += capdu->lc;
    }

    if (capdu->le != LYDIA_APDU_NOT_PRESENT) {
        capdu_stream[offset++] = capdu->le & 0xFF;
    }

    ret = 0;
    *len = offset;
    HEX_DUMP("raw capdu:", capdu_stream, *len);
    out:
    return ret;
}

static int32_t _lydia_apdu_raw_to_rapdu(uint8_t *raw, int16_t len, lydia_rapdu_t *rapdu)
{
    int32_t ret = 0;

    CHECK_CONDICTION((raw==NULL) || (len==0) || (rapdu == NULL) ||
                 (len < (2), 
            LYDIA_ERR_PARAM, "_lydia_apdu_raw_to_rapdu invalid parameters");
    HEX_DUMP("raw rapdu:", raw, len);
    rapdu->len = len - 2;
    rapdu->data = raw;
    // rapdu.swab.swa = raw[len-2];
    // rapdu.swab.swb = raw[len-1];
    rapdu.swab.swab = (raw[len-2]<< 8) | (raw[len-1]);
    out:
    return ret;
}
