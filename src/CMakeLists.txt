cmake_minimum_required(VERSION 3.8)
include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)
ExternalProject_Add(googletest
  SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../googletest
  PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/../googletest_distribution
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
)

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")


project(Example)
add_executable(Example main.cpp)

add_dependencies(Example googletest)
target_link_libraries(Example  libgtest.a libgtest_main.a libgmock.a libgmock_main.a)


find_package(Threads REQUIRED)
target_link_libraries(Example ${CMAKE_THREAD_LIBS_INIT})


