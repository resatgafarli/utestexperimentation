cmake_minimum_required(VERSION 3.8)
include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)

ExternalProject_Add(googletest
  URL ../googletest
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/../googletest_distribution
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/../googletest_distribution/include)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/../googletest_distribution/include)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/../googletest_distribution/lib) 

project(Example)
add_executable(Example main.cpp)
target_link_libraries(Example ${CMAKE_CURRENT_BINARY_DIR}/../googletest_distribution/lib/libgtest.a libgtest_main.a libgmock.a libgmock_main.a)


