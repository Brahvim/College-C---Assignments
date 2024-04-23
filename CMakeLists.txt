cmake_minimum_required(VERSION 3.28.3)

project(CollegeAdvancedCpp)

# CMake-specific variables:
set(BOOL EXPORT_COMPILE_COMMANDS true)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

# Paths:
set(src_dir "${PROJECT_SOURCE_DIR}/src")
set(include_dir "${PROJECT_SOURCE_DIR}/include")

# `GLOB` patterns:
file(GLOB cpp_files "${src_dir}/*.cpp")
file(GLOB hpp_files "${include_dir}/*.hpp")

# Build commands:
include_directories(${include_dir})
add_executable(CollegeAdvancedCpp ${hpp_files} ${cpp_files})
target_compile_features(CollegeAdvancedCpp PUBLIC cxx_std_23)
