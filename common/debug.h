#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define DBG_RAW(...) do {                               \
                            printf(__VA_ARGS__);        \
                        } while (0)


#define DBG(...) do {                                                                              \
                            printf("[%s:%d]", __func__, __LINE__);\
                            printf(__VA_ARGS__);                    \
                        } while (0)

#define HEX_DUMP(hint, ha, l) do{                                               \
                                    int n = 0;                                       \
                                    uint8_t *p = (uint8_t *)(ha);                    \
                                    int sl = (l); \
                                    DBG("%s:[%d]\r\n",(hint),(sl));                       \
                                do {                                               \
                                    for(n = 0 ; n<16; n++){                         \
                                        if(n<sl)                                  \
                                        {                                            \
                                            DBG_RAW("%02X ", p[n]);                       \
                                        }else\
                                        {\
                                            DBG_RAW("   ");                                            \
                                        }\
                                                                                       \
                                    }  \
                                    \
                                     DBG_RAW("      ");                                             \
                                    for(n = 0 ; n<16; n++){                         \
                                        if (n<sl) {                            \
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
                                    sl -= 16;                                      \
                                    p+=16;                                          \
                            } while (sl>0);\
                        }while(0)