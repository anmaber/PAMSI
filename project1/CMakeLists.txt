project(doubly_linked_list)
cmake_minimum_required(VERSION 2.8)

add_compile_options(-c
                    -Wall
                    -Wextra
                    -pedantic
		    -Werror
                    -std=c++14
                    -g)



include_directories(inc)
add_executable(${PROJECT_NAME} src/main.cpp)
