project(Graphs)
cmake_minimum_required(VERSION 2.8)

set (CMAKE_BUILD_TYPE debug)
set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-c
    -Wall
    -Wextra
    -g)

set (SRC_LIST src/Graph.cpp
    src/ListGraph.cpp
    src/MatrixGraph.cpp
    src/Tester.cpp
    )


include_directories(inc)
add_library(${PROJECT_NAME}-lib ${SRC_LIST})
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
