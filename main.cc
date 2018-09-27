#include <iostream>
#include "tests/util_test.hpp"
#include "include/sfml_visualizer.hpp"
#include "include/file_parser.hpp"

int main() {
    srand(time(nullptr));

    std::cout << "---------------\n" << "Render 2" << std::endl;
    obj_data data;
    util_test::test_vector3();
    sfml_visualizer::create_window();
    parse("cube.obj", data);

    return 0;

}