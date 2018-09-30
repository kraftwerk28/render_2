cmake_minimum_required(VERSION 3.12)
project(render_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(render_2 main.cc src/util.cc include/util.h src/sfml_visualizer.cc include/sfml_visualizer.h tests/util_test.cc tests/util_test.h include/file_parser.h src/file_parser.cc include/ray_tracer.h src/ray_tracer.cc include/bsp_tree.h src/bsp_tree.cc)
target_link_libraries(render_2 -lsfml-system -lsfml-window -lsfml-graphics -lpthread)
