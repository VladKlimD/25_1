cmake_minimum_required(VERSION 3.23)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(25_1 main.cpp ${MY_INCLUDE_DIR}/operational-tools.h)
target_include_directories(25_1 PUBLIC ${MY_INCLUDE_DIR})