cmake_minimum_required(VERSION 3.10)
project(Matrix)

set(CMAKE_CXX_STANDARD 11)

# Указываем путь к библиотеке
set(MATRIX_LIB_PATH "${CMAKE_SOURCE_DIR}/libs/matrixlib")

# Находим библиотеку
find_library(MATRIX_LIB shared-matrix_lib PATHS ${MATRIX_LIB_PATH})

# Добавляем исполняемый файл
add_executable(MatrixApp src/test-shared-matrix.cpp)

# Линкуем библиотеку с исполняемым файлом
target_link_libraries(MatrixApp ${MATRIX_LIB})