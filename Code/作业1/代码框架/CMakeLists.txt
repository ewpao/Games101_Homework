cmake_minimum_required(VERSION 3.10)
project(Rasterizer)

set(CMAKE_CXX_STANDARD 17)

set(OpenCV_DIR "C:/Opencv/opencv/build/x64/vc16/lib")

set(Eigen_DIR "C:/eigen-3.4.0")

include_directories(${Eigen_DIR})

find_package(OpenCV REQUIRED)

add_executable(Rasterizer main.cpp rasterizer.hpp rasterizer.cpp Triangle.hpp Triangle.cpp)
target_link_libraries(Rasterizer ${OpenCV_LIBS})
