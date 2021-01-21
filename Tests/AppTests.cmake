project(KubeAppTests)

get_filename_component(KubeAppTestsDir ${CMAKE_CURRENT_LIST_FILE} PATH)

set(KubeAppTestsSources
    ${KubeAppTestsDir}/tests_Application.cpp
)

add_executable(${CMAKE_PROJECT_NAME} ${KubeAppTestsSources})

add_test(NAME ${CMAKE_PROJECT_NAME} COMMAND ${CMAKE_PROJECT_NAME})

target_link_libraries(${CMAKE_PROJECT_NAME}
PUBLIC
    KubeApp
    GTest::GTest GTest::Main
)

if(KF_COVERAGE)
    target_compile_options(${PROJECT_NAME} PUBLIC --coverage)
    target_link_options(${PROJECT_NAME} PUBLIC --coverage)
endif()