
#include "lydia_core.h"
#include "lydia.h"


int32_t lydia_metadata_init(lydia_metadata_list_t *list, uint16_t size, uint16_t repo_size)
{
    int32_t ret = 0;

    CHECK_CONDICTION(size <= 0|| repo_size <= 0, LYDIA_ERR_PARAM, "lydia_metadata_init invalid parameters");

    if (NULL == list) {
        list = (lydia_metadata_list_t *)lydia_alloc(sizeof(lydia_metadata_list_t));
        CHECK_CONDICTION(list == NULL, LYDIA_ERR_OOM, "lydia_metadata_init list OOM");
    }
    memset(list, 0x00, sizeof(lydia_metadata_list_t));

    list->data = (lydia_metadata_t *)lydia_alloc(size * sizeof(lydia_metadata_t));
    CHECK_CONDICTION_OUT_POINT(list->data == NULL, LYDIA_ERR_OOM, "lydia_metadata_init data OOM",cleanup);
    memset(list->data, 0x00, size * sizeof(lydia_metadata_t));
    list->size = size;

    list->repo.len = repo_size;
    list->repo.buf = (uint8_t *)lydia_alloc(size * sizeof(uint8_t));
    CHECK_CONDICTION_OUT_POINT(list->repo.buf == NULL, LYDIA_ERR_OOM, "lydia_metadata_init repo OOM",cleanup);
    memset(list->repo.buf, 0x00, list->repo.len);
    return ret;

    cleanup:
    lydia_free(list);
    out:
    return ret;
}

int32_t lydia_application_init(lydia_as_app_list_t *list, uint8_t size)
{
    int32_t ret = 0;

    CHECK_CONDICTION(list == NULL || size <= 0, LYDIA_ERR_PARAM, "lydia_application_init invalid parameters");
    list = (lydia_as_app_list_t *)lydia_alloc(sizeof(lydia_as_app_list_t));
    CHECK_CONDICTION(list == NULL, LYDIA_ERR_OOM, "lydia_metadata_init OOM");
    memset(list, 0x00, sizeof(lydia_metadata_list_t));
    list->apps = (lydia_as_app_t *)lydia_alloc(size * sizeof(lydia_as_app_t));
    CHECK_CONDICTION_OUT_POINT(list->apps == NULL, LYDIA_ERR_OOM, "lydia_application_init OOM",cleanup);
    memset(list->apps, 0x00, size * sizeof(lydia_as_app_t));
    list->size = size;
    return ret;

    cleanup:
    lydia_free(list);
    out:
    return ret;
}

int32_t lydia_ca_certs_init(lydia_ca_cert_list_t *list, uint8_t size)
{
    int32_t ret = 0;

    CHECK_CONDICTION(list == NULL || size <= 0, LYDIA_ERR_PARAM, "lydia_metadata_init invalid parameters");
    list = (lydia_ca_cert_list_t *)lydia_alloc(sizeof(lydia_ca_cert_list_t));
    CHECK_CONDICTION(list == NULL, LYDIA_ERR_OOM, "lydia_metadata_init OOM");
    memset(list, 0x00, sizeof(lydia_ca_cert_list_t));
    list->certs = (lydia_ca_cert_t *)lydia_alloc(size * sizeof(lydia_ca_cert_t));
    CHECK_CONDICTION_OUT_POINT(list->certs == NULL, LYDIA_ERR_OOM, "lydia_metadata_init OOM",cleanup);
    memset(list->certs, 0x00, size * sizeof(lydia_ca_cert_t));
    list->size = size;
    return ret;

    cleanup:
    lydia_free(list);
    out:
    return ret;
}

int32_t lydia_init_context(lydia_context_t *ctx,uint16_t metadata_size, uint8_t app_size, uint8_t certs_size)
{
    int32_t ret = 0;

    CHECK_CONDICTION(ctx == NULL || metadata_size <= 0|| app_size <= 0|| certs_size <= 0, LYDIA_ERR_PARAM, "lydia_init_context invalid parameters");
    ctx->metadata_list = lydia_alloc(sizeof(lydia_metadata_list_t));
    CHECK_CONDICTION(ctx->metadata_list == NULL, LYDIA_ERR_OOM, "lydia_init_context alloc metadata_list OOM");
    ret = lydia_metadata_init(ctx->metadata_list, metadata_size);
    CHECK_CONDICTION(0 != ret, LYDIA_ERR_OOM, "lydia_metadata_init failed");

    ctx->app_list = lydia_alloc(sizeof(lydia_as_app_list_t));
    CHECK_CONDICTION(ctx->app_list == NULL, LYDIA_ERR_OOM, "lydia_init_context alloc app_list OOM");
    ret = lydia_application_init(ctx->app_list, app_size);
    CHECK_CONDICTION(0 != ret, LYDIA_ERR_OOM, "lydia_metadata_init failed");

    ctx->ca_cert_list = lydia_alloc(sizeof(lydia_ca_cert_list_t));
    CHECK_CONDICTION(ctx->ca_cert_list == NULL, LYDIA_ERR_OOM, "lydia_init_context alloc ca_cert_list OOM");
    ret = lydia_ca_certs_init(ctx->ca_cert_list, certs_size);

    CHECK_CONDICTION(0 != ret, LYDIA_ERR_OOM, "lydia_metadata_init failed");
    
    return ret;

    cleanup:
    lydia_free(ctx->metadata_list);
    lydia_free(ctx->app_list);
    lydia_free(ctx->ca_cert_list);
    out:
    return ret;
}