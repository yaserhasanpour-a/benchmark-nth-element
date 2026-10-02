cmake_minimum_required(VERSION 3.16)
project(benchmark_nth_element LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(bench benchmark_nth_element.cpp)

# Reasonable warnings
target_compile_options(bench PRIVATE -Wall -Wextra -Wpedantic)
