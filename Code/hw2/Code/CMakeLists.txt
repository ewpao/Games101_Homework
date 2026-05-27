cmake_minimum_required(VERSION 3.10)
project(Rasterizer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Eigen (local install)
set(EIGEN3_INCLUDE_DIR "C:/Eigen/eigen3/include/eigen3")
include_directories(${EIGEN3_INCLUDE_DIR})

# OpenCV (MinGW build)
set(OpenCV_DIR "C:/opencv/opencv/build/x64/mingw/install/x64/mingw/lib")
find_package(OpenCV REQUIRED)

add_executable(Rasterizer
    main.cpp
    rasterizer.cpp
    Triangle.cpp
)

target_link_libraries(Rasterizer ${OpenCV_LIBS})
target_include_directories(Rasterizer PRIVATE ${OpenCV_INCLUDE_DIRS})

# Copy required DLLs to build directory
set(OPENCV_BIN_DIR "C:/opencv/opencv/build/x64/mingw/install/x64/mingw/bin")
set(MINGW_BIN_DIR "C:/x86_64-16.1.0-release-win32-seh-ucrt-rt_v14-rev0/mingw64/bin")

add_custom_command(TARGET Rasterizer POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${OPENCV_BIN_DIR}/libopencv_core4120.dll"
        "${OPENCV_BIN_DIR}/libopencv_imgproc4120.dll"
        "${OPENCV_BIN_DIR}/libopencv_imgcodecs4120.dll"
        "${OPENCV_BIN_DIR}/libopencv_highgui4120.dll"
        "${MINGW_BIN_DIR}/libgcc_s_seh-1.dll"
        "${MINGW_BIN_DIR}/libstdc++-6.dll"
        "${MINGW_BIN_DIR}/libwinpthread-1.dll"
        $<TARGET_FILE_DIR:Rasterizer>
    COMMENT "Copying DLLs to build directory..."
)
