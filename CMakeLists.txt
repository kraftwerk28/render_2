cmake_minimum_required(VERSION 3.12)
project(render_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(render_2 main.cc src/util.cpp include/util.hpp src/sfml_visualizer.cpp include/sfml_visualizer.hpp tests/util_test.cc tests/util_test.h include/file_parser.hpp src/file_parser.cpp include/ray_tracer.hpp src/ray_tracer.cpp include/bsp_tree.hpp src/bsp_tree.cpp)
target_link_libraries(render_2 -lsfml-system -lsfml-window -lsfml-graphics -lpthread)
