######################### General Settings ######################
cmake_minimum_required(VERSION 3.8.2)
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
######################## End Of General Settings ################

################## Qt AUTOMOC Settings ##########################
#!!!!Caution: Should Be defined at top of CMakeLists.txt 
#QT Library Definition/Inclusion 
#First install QT and set bin path to PATH list
#Be shure insalled sudo apt-get install mesa-common-dev
#The build and install cmake from source ./bootstrap --qt-gui, make, make install
#QT_DIR  - root directory (bin,libs,include) where qt is installed. 
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${QT_DIR}})
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
################# End of Qt AUTOMOC SETTINGS #######################


#################### External Projects Settings ########################
include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)
# Google Test External Project Settings 
ExternalProject_Add(googletest
  SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../googletest
  PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/../googletest_distribution
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../googletest_distribution/include)
link_directories (${CMAKE_CURRENT_SOURCE_DIR}/../googletest_distribution/lib)
#################### End of External Projects Settings ########################

############################ LDAF Settings ###################################
# LDAF Source Code Inclusion
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../ldaf/src/LDAF)
set (SOURCES  ${SOURCES} 
    ../ldaf/src/LDAF/ldafbase.cpp
)
 

############################ Main Executable Project Settings #################### 
# Main Project Definition LDAF Source Code Inclusion
project(ldaf_tester)
set (SOURCES  ${SOURCES} main.cpp tst_ldaf.cpp )
add_executable(${PROJECT_NAME} ${SOURCES})
############################ End of Main Executable Project Settings ############# 

######################### Dependency And Link Settings ##########################
# Goole Test Dependency and Link
add_dependencies(${PROJECT_NAME} googletest)
target_link_libraries(${PROJECT_NAME}  libgtest.a libgtest_main.a libgmock.a libgmock_main.a)

# Thread Link
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})

# Qt Link
find_package(Qt5Core REQUIRED)
target_link_libraries(${PROJECT_NAME} Qt5::Core)
######################### End of Dependency And Link Settings ##########################

######################### Testing Section ##############################################
add_custom_command(TARGET ${PROJECT_NAME}
                   POST_BUILD
                   COMMAND ${PROJECT_NAME})
######################### End of Testing Section #######################################


