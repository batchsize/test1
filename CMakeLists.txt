cmake_minimum_required(VERSION 3.2)
PROJECT (TEST1)
set(CMAKE_BUILD_TYPE "Release")

add_definitions (-std=c++11 -O2 -fomit-frame-pointer -g -Wall)
MESSAGE (STATUS "Build Option: -std=c++11 -O2 -fomit-frame-pointer -g -Wall")


include_directories (
    "./src"
    "/usr/local/include"
    "../../../projects/tools/opencv4.3.0/opencv/build/install/include/opencv4"
    "../../../Json/jsoncpp-src-0.5.0/include"
)

link_directories(
    "../../../projects/tools/opencv4.3.0/opencv/build/install/lib"
    "../../../Json/jsoncpp-src-0.5.0/libs/linux-gcc-7"
)

add_executable(demo main.cpp)
target_link_libraries(demo opencv_world json_linux-gcc-7_libmt) 

