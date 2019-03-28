project(sort)
cmake_minimum_required(VERSION 2.8)

add_compile_options(-c
                    -Wall
                    -Wextra
                    -pedantic
                    -std=c++14
                    -g)

include_directories(inc)
add_executable(mergeSort src/merge.cpp)
