cmake_minimum_required(VERSION 3.10)
project(LaboratorioProgrammazione)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

set(SOURCE_FILES main.cpp Product.cpp Product.h List.cpp List.h ListManager.cpp ListManager.h ProductList.cpp ProductList.h Cart.cpp Cart.h )
add_executable(LaboratorioProgrammazione main.cpp Product.cpp Product.h List.cpp List.h ListManager.cpp ListManager.h ProductList.cpp ProductList.h Cart.cpp Cart.h)
add_library(core ${SOURCE_FILES})
target_link_libraries(LaboratorioProgrammazione core)