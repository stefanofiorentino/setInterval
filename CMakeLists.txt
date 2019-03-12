cmake_minimum_required(VERSION 3.13)
project(setInterval)

set(CMAKE_CXX_STANDARD 14)

add_executable(setTimeout src/main.cpp)
target_link_libraries(setTimeout pthread)