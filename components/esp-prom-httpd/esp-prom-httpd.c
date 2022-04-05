/* HTTP Restful API Server

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <string.h>

#include "esp_check.h"
#include "esp_log.h"
#include "esp_http_server.h"

#ifdef CONFIG_PROM_DEFAULT_METRICS
#include "default-metrics.h"
#endif

#include "prom.h"

#include "esp-prom-httpd.h"


static const char *ESP_PROM_HTTPD_TAG = "esp-prom-httpd";

/* Handler for Prometheus monitoring endpoint */
static esp_err_t prom_metrics_handler(httpd_req_t *req)
{
#ifdef CONFIG_PROM_DEFAULT_METRICS
    prom_counter_inc(request_counter, NULL);
#endif

    const char *buf = prom_collector_registry_bridge(PROM_ACTIVE_REGISTRY);
    httpd_resp_set_type(req, "text/plain");
    httpd_resp_sendstr(req, buf);
    free((void *)buf);
    return ESP_OK;
}

httpd_handle_t esp_prom_start_httpd(httpd_handle_t server)
{
    PROM_ACTIVE_REGISTRY = PROM_COLLECTOR_REGISTRY_DEFAULT;

    #ifdef CONFIG_PROM_DEFAULT_METRICS
    default_metrics_init();
    #endif

    if (!server)
    {
        httpd_config_t config = HTTPD_DEFAULT_CONFIG();
        config.uri_match_fn = httpd_uri_match_wildcard;

        ESP_LOGI(ESP_PROM_HTTPD_TAG, "Starting HTTP Server");
        if (httpd_start(&server, &config) != ESP_OK)
        {
            ESP_LOGE(ESP_PROM_HTTPD_TAG, "Failed to start HTTP Server");
            return ESP_FAIL;
        }
    }

    /* URI handler Prometheus monitoring endpoint */
    httpd_uri_t prom_get_uri = {
        .uri = "/metrics",
        .method = HTTP_GET,
        .handler = prom_metrics_handler,
    };
    httpd_register_uri_handler(server, &prom_get_uri);

    return ESP_OK;
}