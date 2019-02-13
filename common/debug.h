#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define DBG_RAW(...) do {                               \
                            printf(__VA_ARGS__);        \
                        } while (0)


#define DBG(...) do {                                                                              \
                            printf("[%s:%s:%d]", __FILE__, __func__, __LINE__, ##__VA_ARGS__);                    \
                        } while (0)

#define HEX_DUMP(hint, ha, l) do {                                               \
                                int n = 0;                                       \
                                uint8_t *p = (uint8_t *)(ha);                    \
                                DBG("%s:[%d]",(hint),(l));                       \
                                for(n = 0 ; n<16; n++){                         \
                                    if(n<(l))                                   \
                                    {                                            \
                                        DBG_RAW("%02X ", p[n]);                       \
                                    }                                               \
                                }                                                \
                                for(n = 0 ; n<16; n++){                         \
                                    if (n<(l)) {                            \
                                        if(isprint(p[n]))                          \
                                        {                                            \
                                            DBG_RAW("%c", p[n]);                       \
                                        }else                                        \
                                        {                                            \
                                            DBG_RAW(".");                               \
                                        }                                            \
                                    }else                                               \
                                    {                                               \
                                        DBG_RAW(" ");                                   \
                                    }                                                       \
                                }                                                \
                                DBG_RAW("\n");                                  \
                                (l) -= 16;                                      \
                                p+=16;                                          \
                            } while (((l)>0))