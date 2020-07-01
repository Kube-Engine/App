project(KubeAppBenchmarks)

get_filename_component(KubeAppBenchmarksDir ${CMAKE_CURRENT_LIST_FILE} PATH)

set(KubeAppBenchmarksSources
    ${KubeAppBenchmarksDir}/Main.cpp
)

add_executable(${CMAKE_PROJECT_NAME} ${KubeAppBenchmarksSources})

target_link_libraries(${CMAKE_PROJECT_NAME}
PUBLIC
    KubeApp
    benchmark::benchmark
)