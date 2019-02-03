

#include "debug.h"

#define lydia_memset    memset
#define lydia_memcpy    memcpy
#define lydia_memcmp    memcmp

#define CHECK_CONDICTION(cond, expect,msg) do {                                 \
                                              if (cond != expect) {             \
                                                  DBG("%s:%d",msg,cond);        \
                                                  goto out;                     \
                                              }                                 \
                                           } while (0)
