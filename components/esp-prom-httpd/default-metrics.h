#include "prom.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

prom_counter_t *request_counter;
prom_gauge_t *free_heap_gauge;
prom_gauge_t *min_free_heap_gauge;
prom_gauge_t *task_min_free_stack_gauge;

void default_metrics_init(void);

void get_default_metrics_task(void);