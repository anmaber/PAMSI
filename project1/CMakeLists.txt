project(doubly_linked_list)
cmake_minimum_required(VERSION 2.8)

add_compile_options(-c
                    -Wall
                    -Wextra
                    -pedantic
                    -std=c++14
                    -g)

set(SRC_LIST
	list.hpp
	node.hpp
        main.cpp
)

include_directories(${PROJECT_SOURCE_DIR})
add_library(${PROJECT_NAME}-lib ${SRC_LIST})
add_executable(${PROJECT_NAME} main.cpp)
