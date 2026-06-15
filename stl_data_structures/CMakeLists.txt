
add_executable(lookup_table_benchmarking lookup_table.cpp)

target_link_libraries(lookup_table_benchmarking
    PRIVATE
        benchmark::benchmark_main)