cmake_minimum_required(VERSION 3.5)

set (ESP_PROM_COMPONENT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../components)

# This example uses an extra component for common functions such as Wi-Fi and Ethernet connection.
set(EXTRA_COMPONENT_DIRS 
  $ENV{IDF_PATH}/examples/common_components/protocol_examples_common
  ${ESP_PROM_COMPONENT_DIR}/esp-prom
  ${ESP_PROM_COMPONENT_DIR}/esp-prom-httpd
)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(esp-prom-example)
