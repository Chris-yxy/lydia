
#include<stdint.h>
#include<string.h>

#include "debug.h"

#define lydia_memset    memset
#define lydia_memcpy    memcpy
#define lydia_memcmp    memcmp

#define CHECK_CONDICTION(cond, err, msg) do{                                             \
                                                if (cond) {                              \
                                                    DBG("%s:[%d]\r\n", msg, err);        \
                                                    ret = err;                           \
                                                    goto out;                            \
                                                }                                        \
                                            }while(0)

typedef enum _lydia_err_t{
    LYDIA_ERR_PARAM = -2019,
    LYDIA_ERR_OOM,
}lydia_err_t;

#define LYDIA_FALSE         (0)
#define LYDIA_TRUE          (!LYDIA_FALSE) 

/**********************************************************
 * 
 * TLV module export APIs
 * 
 * *******************************************************/
typedef int32_t (*onReadData)(uint32_t tag, uint16_t len, uint8_t *v);

int32_t lydia_tlv_read_data(/*tlv_context_pt *ctx,*/ uint8_t *data, uint16_t len,onReadData on_read_data);
