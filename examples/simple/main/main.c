#include "sdkconfig.h"
#include "driver/gpio.h"
#include "esp_netif.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "protocol_examples_common.h"
#include "prom.h"
#include "esp-prom-httpd.h"
#include "default-metrics.h"

static const char *TAG = "esp-idf-prom-test";

void app_main(void)
{
    prom_collector_registry_default_init();
    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    ESP_ERROR_CHECK(example_connect());
    esp_prom_start_httpd(NULL);
}
