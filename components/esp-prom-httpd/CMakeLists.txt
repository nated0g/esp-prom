idf_component_register(
    SRCS
        esp-prom-httpd.c
        default-metrics.c
    INCLUDE_DIRS .
    REQUIRES esp-prom esp_http_server
)