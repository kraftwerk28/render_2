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
    auto *window_closed = new bool(false);
//    bool window_closed = false;

    if (TEST_MODE)
    {
        util_test::test_vector3();
        return 0;
    }

    srand((unsigned int) time(nullptr));
    const unsigned int w = 400, h = 400;

    auto *img = new sf::Image();
    img->create(w, h);

    std::cout << "---------------\n" << "Render 2" << std::endl;

    auto *data = new obj_data();
    auto *camera1 = new camera(vector3(5, 0.5f, 0), vector3(-1, -0.2f, -0.1f), w, h,
                               60);

    file_parser::parse("sphere.obj", *data);

    std::thread thread;
    thread = std::thread(
        [=] {
            sfml_visualizer::create_window(w, h, img, window_closed);
        });

    ray_tracer::trace_to_image(data, camera1, img);
    img->saveToFile("result.png");
    std::cout << "Image saved!\n";

    thread.join();
    while (!*window_closed);
    std::cout << "Window closed\n";

    delete img;
    delete data;
    delete camera1;
    delete window_closed;

    return 0;

}