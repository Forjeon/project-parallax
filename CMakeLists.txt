cmake_minimum_required(VERSION 3.28.3)

project(ProjectParallax VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(ProjectParallax main.cpp)

target_include_directories(ProjectParallax PUBLIC "${PROJECT_BINARY_DIR}")

configure_file(config.h.in config.h)
