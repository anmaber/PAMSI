project(sort)
cmake_minimum_required(VERSION 2.8)

add_compile_options(-c
                    -Wall
                    -Wextra
                    -std=c++14
                    -g)

include_directories(inc)
add_executable(sort src/main.cpp)
