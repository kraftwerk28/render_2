#include <iostream>
#include <thread>
#include <functional>

#include "tests/util_test.h"
#include "include/sfml_visualizer.h"
#include "include/file_parser.h"
#include "include/ray_tracer.h"

#define TEST_MODE 0

int main()
{
    bool *window_closed = new bool(false);

    if (TEST_MODE)
    {
        util_test::test_vector3();
        return 0;
    }

    srand((unsigned int) time(nullptr));

    auto *img = new sf::Image();
    img->create(400, 400);

    std::cout << "---------------\n" << "Render 2" << std::endl;

    auto *data = new obj_data();
    auto *camera1 = new camera(vector3(-2, 0, 0), vector3(1, 0, 0), 400, 400);

    file_parser::parse("cube.obj", *data);

    std::thread thread;
    thread = std::thread(
        [=] { sfml_visualizer::create_window(400, 400, img, window_closed); });

    ray_tracer::trace_to_image(data, camera1, img);
    img->saveToFile("result.png");

    thread.join();
    while (!*window_closed);

    delete img;
    delete data;
    delete camera1;
    delete window_closed;

    return 0;

}