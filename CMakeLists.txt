# Minimum CMake version (could probably be lower tbh)
cmake_minimum_required(VERSION 3.28.3)

# Project + semantic version
project(ProjectParallax VERSION 0.0.1)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Project source structure variables
set(ProjectParallax_SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(ProjectParallax_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(ProjectParallax_HEADER_FILEPATHS
	${ProjectParallax_INCLUDE_DIR}/map.h
)
set(ProjectParallax_SOURCE_FILEPATHS
	${ProjectParallax_SRC_DIR}/main.cpp
	${ProjectParallax_SRC_DIR}/map.cpp
)

# Find ncurses
find_package(Curses REQUIRED)

# Project main executable
add_executable(ProjectParallax ${ProjectParallax_SOURCE_FILEPATHS})

# Link to ncurses
target_link_libraries(ProjectParallax ${CURSES_LIBRARIES})

# Project include directory
target_include_directories(ProjectParallax
	PUBLIC
	${PROJECT_BINARY_DIR}
	${ProjectParallax_INCLUDE_DIR}
	${CURSES_INCUDE_DIR}
)

# Transform config.h
configure_file(${ProjectParallax_INCLUDE_DIR}/config.h.in config.h)

# Include GoogleTest
#include(FetchContent)
#FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip)
#FetchContent_MakeAvailable(googletest)

# Enable testing for this directory and below
#enable_testing()

# Project testing structure variables
#set(ProjectParallax_TESTS_DIR ${PROJECT_SOURCE_DIR}/tests)
#set(ProjectParallax_TEST_FILEPATHS )

# Project tests executable
#add_executable(ProjectParallaxTests ${ProjectParallax_SOURCE_FILEPATHS} ${ProjectParallax_TEST_FILEPATHS})

# Project testing include directories
#target_include_directories(ProjectParallaxTests PUBLIC "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/include")

# Link test executable to GoogleTest
#target_link_libraries(ProjectParallaxTests GTest::gtest_main)

# Load and run GoogleTest CMake stuff
#include(GoogleTest)

# Discover GoogleTest tests
#gtest_discover_tests(ProjectParallaxTests)
