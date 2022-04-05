cmake_minimum_required(VERSION 3.5)
set(EXTRA_COMPONENT_DIRS ./esp-prom ./esp-prom-httpd)
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(esp-prom)