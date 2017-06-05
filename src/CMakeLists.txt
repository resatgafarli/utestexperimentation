project(Example)
cmake_minimum_required(VERSION 3.8)
add_executable(Example main.cpp)
link_directories(D:/GitHub/googletest/build/googlemock D:/GitHub/googletest/build/googlemock/gtest) 
target_link_libraries(Example D:/GitHub/googletest/build/googlemock/gtest/libgtest.a)
target_link_libraries(Example D:/GitHub/googletest/build/googlemock/gtest/libgtest_main.a)
target_link_libraries(Example D:/GitHub/googletest/build/googlemock/libgmock.a)
target_link_libraries(Example D:/GitHub/googletest/build/googlemock/libgmock_main.a)

include_directories(D:/GitHub/googletest/googlemock/include)
include_directories(D:/GitHub/googletest/googletest/include)

