#include "esp_http_server.h"

/**
 * @brief Starts Prometheus endpoint at @c /metrics
 * Pass in an @p server if you have an exising server handle, otherwise pass
 * @c NULL and a server will be created with default config values.
 * @param server Optional 
 * @return Returns a server handle if successful, @c NULL on failure.
 */

httpd_handle_t esp_prom_start_httpd(httpd_handle_t server);
