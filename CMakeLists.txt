cmake_minimum_required(VERSION 3.8)
project(flv2mp4)

set(CMAKE_CXX_STANDARD 11)

set(FLV2MP4_SOURCE_FILE src/Box.h)
add_executable(flv2mp4 ${FLV2MP4_SOURCE_FILE})
