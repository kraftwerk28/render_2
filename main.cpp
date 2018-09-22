#include <iostream>
#include "tests/util_test.hpp"
#include "include/sfml_visualizer.hpp"
#include "include/file_parser.hpp"

int main() {
    std::cout << "---------------\n" << "Render 2" << std::endl;
//    util_test::test_vector3();
    sfml_visualizer::create_window();
    auto info = file_parser::parse("kek");

    return 0;

}