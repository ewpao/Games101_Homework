cmake_minimum_required(VERSION 3.10)
project(Rasterizer)

set(CMAKE_CXX_STANDARD 17)

# Eigen
set(EIGEN3_INCLUDE_DIR "C:/eigen-3.4.0")
include_directories(${EIGEN3_INCLUDE_DIR})

# OpenCV
set(OpenCV_DIR "C:/Opencv/opencv/build/x64/mingw")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(Rasterizer main.cpp rasterizer.hpp rasterizer.cpp global.hpp Triangle.hpp Triangle.cpp Texture.hpp Texture.cpp Shader.hpp OBJ_Loader.h)
target_link_libraries(Rasterizer ${OpenCV_LIBRARIES})