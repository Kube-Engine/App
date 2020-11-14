project(KubeApp)

get_filename_component(KubeAppDir ${CMAKE_CURRENT_LIST_FILE} PATH)

set(KubeAppSources
    ${KubeAppDir}/Application.hpp
    ${KubeAppDir}/Application.cpp
    ${KubeAppDir}/SDLInitializer.hpp
    ${KubeAppDir}/SDLInitializer.cpp
)

add_library(${PROJECT_NAME} ${KubeAppSources})

target_link_libraries(${PROJECT_NAME}
PUBLIC
    KubeGraphics KubeECS
)

if(${KF_TESTS})
    include(${KubeAppDir}/Tests/AppTests.cmake)
endif()

if(${KF_BENCHMARKS})
    include(${KubeAppDir}/Benchmarks/AppBenchmarks.cmake)
endif()