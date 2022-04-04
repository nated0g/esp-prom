set(prom_dir ${CMAKE_CURRENT_SOURCE_DIR}/prometheus-client-c/prom) 
set(src_dir ${prom_dir}/src)
set(include_dir ${prom_dir}/include)

idf_component_register(
  SRCS 
    ${src_dir}/prom_assert.h
    ${src_dir}/prom_collector.c
    ${src_dir}/prom_collector_registry.c
    ${src_dir}/prom_collector_registry_i.h
    ${src_dir}/prom_collector_registry_t.h
    ${src_dir}/prom_collector_t.h
    ${src_dir}/prom_counter.c
    ${src_dir}/prom_gauge.c
    ${src_dir}/prom_histogram.c
    ${src_dir}/prom_histogram_buckets.c
    ${src_dir}/prom_linked_list.c
    ${src_dir}/prom_linked_list_i.h
    ${src_dir}/prom_linked_list_t.h
    ${src_dir}/prom_log.h
    ${src_dir}/prom_map.c
    ${src_dir}/prom_map_i.h
    ${src_dir}/prom_map_t.h
    ${src_dir}/prom_metric.c
    ${src_dir}/prom_metric_formatter.c
    ${src_dir}/prom_metric_formatter_i.h
    ${src_dir}/prom_metric_formatter_t.h
    ${src_dir}/prom_metric_i.h
    ${src_dir}/prom_metric_sample.c
    ${src_dir}/prom_metric_sample_histogram.c
    ${src_dir}/prom_metric_sample_histogram_i.h
    ${src_dir}/prom_metric_sample_histogram_t.h
    ${src_dir}/prom_metric_sample_i.h
    ${src_dir}/prom_metric_sample_t.h
    ${src_dir}/prom_metric_t.h
    ${src_dir}/prom_process_fds.c
    ${src_dir}/prom_process_fds_i.h
    ${src_dir}/prom_process_fds_t.h
    ${src_dir}/prom_process_limits.c
    ${src_dir}/prom_process_limits_i.h
    ${src_dir}/prom_process_limits_t.h
    ${src_dir}/prom_process_stat.c
    ${src_dir}/prom_process_stat_i.h
    ${src_dir}/prom_process_stat_t.h
    ${src_dir}/prom_procfs_i.h
    ${src_dir}/prom_procfs_t.h
    ${src_dir}/prom_procfs.c
    ${src_dir}/prom_string_builder.c
    ${src_dir}/prom_string_builder_i.h
    ${src_dir}/prom_string_builder_t.h
  INCLUDE_DIRS
    ${include_dir}
  )
                      