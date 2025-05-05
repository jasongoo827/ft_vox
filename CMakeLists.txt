cmake_minimum_required(VERSION 3.20)
project(ft_minecraft)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# M1 맥북 최적화 (ARM64)
if(APPLE AND CMAKE_SYSTEM_PROCESSOR MATCHES "arm64")
    message(STATUS "Configuring for Apple Silicon")
    set(CMAKE_OSX_ARCHITECTURES arm64)
endif()

# 소스 디렉토리
add_subdirectory(src)
