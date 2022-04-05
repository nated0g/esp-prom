#include "prom.h"

prom_counter_t *request_counter;
prom_gauge_t *free_heap_gauge;
prom_gauge_t *min_free_heap_gauge;
void request_counter_init(void);