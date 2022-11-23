cmake_minimum_required(VERSION 3.10)

project(rename)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 14)

add_executable(rename Rename-img.cpp)
target_link_libraries(rename ${OpenCV_LIBS})
