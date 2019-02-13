
#include "lydia_core.h"
#include "lydia.h"


int32_t lydia_metadata_init(lydia_metadata_list_t *list, uint16_t size)
{
    int32_t ret = 0;

    CHECK_CONDICTION(list == NULL || size <= 0, LYDIA_ERR_PARAM, "lydia_metadata_init invalid parameters");
    list = (lydia_metadata_list_t *)lydia_alloc(sizeof(lydia_metadata_list_t));
    CHECK_CONDICTION(list == NULL, LYDIA_ERR_OOM, "lydia_metadata_init OOM");
    memset(list, 0x00, sizeof(lydia_metadata_list_t));
    list->data = (lydia_metadata_t *)lydia_alloc(size * sizeof(lydia_metadata_t));
    CHECK_CONDICTION_OUT_POINT(list->data == NULL, LYDIA_ERR_OOM, "lydia_metadata_init OOM",cleanup);
    memset(list->data, 0x00, size * sizeof(lydia_metadata_t));
    list->size = size;
    return ret;

    cleanup:
    lydia_free(list);
    out:
    return ret;
}