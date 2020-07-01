project(KubeApp)

get_filename_component(KubeAppDir ${CMAKE_CURRENT_LIST_FILE} PATH)

set(KubeAppSources
    ${KubeAppDir}/Dummy.cpp
)

add_library(${PROJECT_NAME} ${KubeAppSources})

target_link_libraries(${PROJECT_NAME}
PUBLIC
    KubeCore
)

if(${KF_TESTS})
    include(${KubeAppDir}/Tests/AppTests.cmake)
endif()

if(${KF_BENCHMARKS})
    include(${KubeAppDir}/Benchmarks/AppBenchmarks.cmake)
endif()