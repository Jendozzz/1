# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

project ("lab1")

# Включите подпроекты.
#add_subdirectory ("lab1")

add_executable (lab1 "lab1.cpp" "cpp-rational.cpp" "cpp-rational.h" "c-rational.cpp" "c-rational.h")