#include "default-metrics.h"
#include "prom.h"

void default_metrics_init(void) {
  request_counter = prom_collector_registry_must_register_metric(
    prom_counter_new("esp_prom_requests_total", "counts requests to /metrics", 0, NULL));
  free_heap_gauge = prom_collector_registry_must_register_metric(
    prom_gauge_new("esp_free_heap_size", "current free heap", 0, NULL));
  min_free_heap_gauge = prom_collector_registry_must_register_metric(
    prom_gauge_new("esp_min_free_heap_size", "minimum free heap counted during execution", 0, NULL));
}
