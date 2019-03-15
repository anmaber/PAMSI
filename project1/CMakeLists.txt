project(structures)
cmake_minimum_required(VERSION 2.8)

add_compile_options(-c
                    -Wall
                    -Wextra
                    -pedantic
                    -std=c++14
                    -g)

include_directories(inc/list)
add_executable(doubly_linked_list src/list.cpp)

include_directories(inc/stack)
add_executable(stack src/stack.cpp)

include_directories(inc/queue)
add_executable(queue src/queue.cpp)

include_directories(inc/priority_queue)
add_executable(priority_queue src/priorityQueue.cpp)

include_directories(inc/map)
add_executable(map src/map.cpp)
