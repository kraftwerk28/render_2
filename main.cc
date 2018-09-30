#include <iostream>
#include <thread>
#include <functional>
#include <unistd.h>

#include "tests/util_test.h"
#include "include/sfml_visualizer.h"
#include "include/file_parser.h"
#include "include/ray_tracer.h"

#define TEST_MODE 1

int main()
{
    auto *window_closed = new bool(false);
    auto *render_pending = new bool(true);
    auto *progress = new float(0);
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
    auto *camera1 = new camera(vector3(5, -5, 5),
                               vector3(-1, 1, -1), w, h, 60);

    file_parser::parse("obj/sphere.obj", *data);

    auto *t_sfml_window = new std::thread(
        [=] {
            sfml_visualizer::create_window(w, h, img, window_closed);
        });

    auto t_tracer = new std::thread(
        [=] {
            ray_tracer::trace_to_image(data, camera1, img, progress,
                                       render_pending);
        });

    while (*render_pending)
    {
        std::cout << "\r" << std::roundf(*progress * 100) << " %";
        if (*window_closed)
            *render_pending = false;
    }

    img->saveToFile("result.png");
    std::cout << "\nImage saved!\n";

    t_tracer->join();
    t_sfml_window->join();
    while (!*window_closed);
    std::cout << "Window closed\n";

    delete img;
    delete data;
    delete camera1;
    delete window_closed;
    delete render_pending;
    delete progress;
    delete t_sfml_window;
    delete t_tracer;

    return 0;

}