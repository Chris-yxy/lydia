#ifndef _APDU_H_
#define _APDU_H_

#include <stdint.h>

#define LYDIA_CAPDU_CMD_LEN     4

#define LYDIA_APDU_NOT_PRESENT (0xFFFF)

typedef struct _lydia_capdu_t
{
    uint8_t cmd[LYDIA_CAPDU_CMD_LEN];
    uint16_t lc;
    uint8_t *data;
    uint16_t le;
}lydia_capdu_t;

typedef struct _lydia_apdu_swab_t
{
    uint16_t swab;
    union 
    {
        uint8_t swa;
        uint8_t swb;
    };
}lydia_apdu_swab_t;


typedef struct _lydia_rapdu_t{
    uint16_t len;
    uint8_t *data;
    lydia_apdu_swab_t swab;
}lydia_rapdu_t;



#endif