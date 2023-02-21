cmake_minimum_required(VERSION 3.10)

add_subdirectory(googletest)
set(gtest_SOURCE_DIR, googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES main_test.cpp TestProdotti.cpp)
add_executable(LaboratorioProgrammazione_test ${TEST_SOURCE_FILES})
target_link_libraries(LaboratorioProgrammazione_test gtest gtest_main core)