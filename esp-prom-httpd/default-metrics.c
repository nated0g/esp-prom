#include "default-metrics.h"
#include "prom.h"

void request_counter_init(void) {
  request_counter = prom_collector_registry_must_register_metric(
    prom_counter_new("esp_prom_requests_total", "counts requests to /metrics", 0, NULL));
}
