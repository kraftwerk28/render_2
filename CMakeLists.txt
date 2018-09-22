cmake_minimum_required(VERSION 3.12)
project(render_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(render_2 main.cpp src/util.cpp include/util.hpp src/sfml_visualizer.cpp include/sfml_visualizer.hpp tests/util_test.cpp tests/util_test.hpp include/file_parser.hpp src/file_parser.cpp)