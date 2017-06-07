cmake_minimum_required(VERSION 3.8)
include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

# Google Test External Project Settings 
ExternalProject_Add(googletest
  SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../googletest
  PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/../googletest_distribution
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../googletest_distribution/include)
link_directories (${CMAKE_CURRENT_SOURCE_DIR}/../googletest_distribution/lib)

# LDAF Source Code Inclusion
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../ldaf/src/LDAF)
file(GLOB LDAF_SRC  ${CMAKE_CURRENT_SOURCE_DIR}/../ldaf/src/LDAF/ "*.cpp")



# Main Project Definition LDAF Source Code Inclusion
project(LDAF_Tester)
add_executable(LDAF_Tester main.cpp ${LDAF_SRC})

# Goole Test Dependency Definition
add_dependencies(LDAF_Tester googletest)
target_link_libraries(LDAF_Tester  libgtest.a libgtest_main.a libgmock.a libgmock_main.a)

# Thread Dependency Definition
find_package(Threads REQUIRED)
target_link_libraries(LDAF_Tester ${CMAKE_THREAD_LIBS_INIT})

#QT Library Definition/Inclusion
#!!! QT bin path should be added in PATH list 
set(CMAKE_AUTOMOC ON)
find_package(Qt5Core)
target_link_libraries(LDAF_Tester Qt5::Core)


