cmake_minimum_required(VERSION 3.12)
project(render_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(render_2 main.cpp src/util.cpp src/util.h src/sfml_visualizer.cpp src/sfml_visualizer.h tests/util_test.cpp tests/util_test.h)