cmake_minimum_required(VERSION 3.15)
project(TEST)

set(CMAKE_CXX_STANDARD 98)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(TEST test.cpp allocator.h person.h)
target_link_libraries(TEST gtest gtest_main pthread)

