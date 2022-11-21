cmake_minimum_required(VERSION 3.17)
project(VisualSorting)

set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5 COMPONENTS system window graphics)

add_executable(VisualSorting main.cpp)
target_link_libraries(VisualSorting sfml-system sfml-window sfml-graphics)