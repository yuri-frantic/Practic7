cmake_minimum_required(VERSION 3.18)
project(
    Matrix
    VERSION 0.0.1
    DESCRIPTION "Matrix_lib"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)

set(MATH_USE_DOUBLE_PRECISION "Use doble precision" ON)

set(sources
    src/matrix.h
    src/matrix.cpp
    src/export.h
    src/c/c_api.h
    src/c/c_api.cpp
)

include(GenerateExportHeader)

add_library(static-matrix_lib STATIC ${sources})


target_include_directories(static-matrix_lib
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)
target_compile_definitions(
    static-matrix_lib
    PUBLIC
        MATH_STATIC_DEFINE
        "$<$<BOOL:${MATH_USE_DOUBLE_PRECISION}>:MATH_DOUBLE_PREC_DEFINE>"
)

set_target_properties(static-matrix_lib PROPERTIES PREFIX "")

generate_export_header(
    static-matrix_lib
    EXPORT_FILE_NAME "${PROJECT_BINARY_DIR}/export_static.h"
    BASE_NAME matrix_lib
)








add_library(shared-matrix_lib SHARED ${sources})

target_include_directories(shared-matrix_lib
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)

target_compile_definitions(
    shared-matrix_lib
    PUBLIC
        "$<$<BOOL:${MATH_USE_DOUBLE_PRECISION}>:MATH_DOUBLE_PREC_DEFINE>"
)

set_target_properties(shared-matrix_lib PROPERTIES PREFIX "")

generate_export_header(
    shared-matrix_lib
    EXPORT_FILE_NAME "${PROJECT_BINARY_DIR}/export_shared.h"
    BASE_NAME matrix_lib
)




