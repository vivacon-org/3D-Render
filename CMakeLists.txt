cmake_minimum_required(VERSION 3.1.0...3.27.0)

project(ray_tracing LANGUAGES CXX)

# Set to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Source
set(RAY_TRACING
        src/ray_tracing/main.cpp
        src/ray_tracing/color.h
        src/ray_tracing/vec3.h
        src/ray_tracing/ray.h
)

include_directories(src)

# Executables
add_executable(ray_tracing ${RAY_TRACING})