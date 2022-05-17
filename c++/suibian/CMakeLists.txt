# Copyright(c) 2019 spdlog authors Distributed under the MIT License (http://opensource.org/licenses/MIT)
#use spdlog 模板
cmake_minimum_required(VERSION 3.10)
project(spdlog_examples CXX)
set(CMAKE_CXX_STANDARD 14)

find_package(spdlog REQUIRED)
find_package(Boost COMPONENTS thread system REQUIRED)
# ---------------------------------------------------------------------------------------
# Example of using pre-compiled library
# ---------------------------------------------------------------------------------------
add_executable(2.out 2.cpp)
target_link_libraries(2.out PRIVATE spdlog::spdlog Boost::thread gtest)
add_executable(3.out gtest.cpp)
target_link_libraries(3.out gtest)
# ---------------------------------------------------------------------------------------
# Example of using header-only library
# ---------------------------------------------------------------------------------------
#if(SPDLOG_BUILD_EXAMPLE_HO)
  #  add_executable(example_header_only example.cpp)
 #   target_link_libraries(example_header_only PRIVATE spdlog::spdlog_header_only)
#endif()