#ifndef _LYDIA_CORE_H_
#define _LYDIA_CORE_H_

#ifdef _c_plus_plus
    extern "C"{
#endif
#include <stdint.h>


/***********************************************
 *  lydia metadata define
 * ********************************************/
    typedef enum{
        LYDIA_METADATA_SRC_CARD,
        LYDIA_METADATA_SRC_ENTRY_POINT,
        LYDIA_METADATA_SRC_CARD,
        LYDIA_METADATA_SRC_CARD,
    }lydia_metadata_src_t;
    
    typedef enum{

    }lydia_metadata_fmt_t;

    typedef enum{

    }lydia_metadata_tpl_t;

    typedef enum{

    }lydia_metadata_len_attr_t;

    typedef enum{

    }lydia_metadata_updater_t;

    typedef struct _lydia_metadata_attr_t
    {
        char *name;
        char *desc;
        lydia_metadata_src_t scr;
        lydia_metadata_fmt_t fmt;
        lydia_metadata_tpl_t tpl;
        lydia_metadata_len_attr_t len_attr;
        lydia_metadata_updater_t daupter;
    }lydia_metadata_attr_t;

    typedef struct _lydia_metadata_t{
        uint32_t tag;
        lydia_metadata_attr_t attr;
        uint16_t l;
        uint8_t *v;
    }lydia_metadata_t;

    typedef struct _lydia_metadata_list_t{
        lydia_metadata_t *list;
        uint16_t size;
    }lydia_metadata_list_t;

    typedef struct _lydia_context_t{
        lydia_metadata_list_t *metadata_list;
    }lydia_context_t;
#ifdef _c_plus_plus
    }
#endif
#endif