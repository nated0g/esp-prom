#include "default-metrics.h"
#include "prom.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void default_metrics_init(void) {

  request_counter = prom_collector_registry_must_register_metric(
    prom_counter_new("esp_prom_requests_total", "counts requests to /metrics", 0, NULL));

  free_heap_gauge = prom_collector_registry_must_register_metric(
    prom_gauge_new("esp_free_heap_size", "current free heap", 0, NULL));

  min_free_heap_gauge = prom_collector_registry_must_register_metric(
    prom_gauge_new("esp_min_free_heap_size", "minimum free heap counted during execution", 0, NULL));

  task_min_free_stack_gauge = prom_collector_registry_must_register_metric(
    prom_gauge_new("esp_task_min_free_stack_size", "minimum free stack for default metrics task", 0, NULL));

  xTaskCreate(get_default_metrics_task,
              "prom_default_metrics",
              4096, 
              NULL,
              5,
              NULL);
}

void get_default_metrics_task(void)
{
  while (1) {
    prom_gauge_set(free_heap_gauge, esp_get_free_heap_size(), NULL);
    prom_gauge_set(min_free_heap_gauge, esp_get_minimum_free_heap_size(), NULL);
    prom_gauge_set(task_min_free_stack_gauge, uxTaskGetStackHighWaterMark(NULL), NULL);
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}
