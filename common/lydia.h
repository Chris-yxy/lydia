

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