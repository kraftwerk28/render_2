#include <iostream>
#include "tests/util_test.h"
#include "include/sfml_visualizer.h"
#include "include/file_parser.h"

int main()
{
    srand((unsigned int) time(nullptr));

    std::cout << "---------------\n" << "Render 2" << std::endl;
    obj_data data;
//    util_test::test_vector3();
//    sfml_visualizer::create_window();
    file_parser::parse("cube.obj", data);

    return 0;

}