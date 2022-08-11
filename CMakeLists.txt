cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(220_ContainsDuplicate-III VERSION 1.0.0)

set(SRC_FILES src/solution.cpp)
add_executable(220_ContainsDuplicate-III src/main.cpp ${SRC_FILES})

target_include_directories(220_ContainsDuplicate-III PUBLIC inc)

