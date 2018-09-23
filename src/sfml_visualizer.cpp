//
// Created by kraftwerk28 on 22.09.18.
//

#include "../include/sfml_visualizer.hpp"
#include <unistd.h>
#include <thread>
#include <iostream>
#include <functional>

void fill_pic(sf::Image *image, sf::Texture *texture)
{
    int _to = image->getSize().y * image->getSize().x;
    for (int i = 0; i < image->getSize().x; i++)
    {
        for (int j = 0; j < image->getSize().y; j++)
        {
            image->setPixel(i, j, sf::Color::Cyan);
            usleep(20);
        }
    }
}

void sfml_visualizer::create_window(unsigned int w, unsigned int h)
{
    auto *window = new sf::RenderWindow(sf::VideoMode(w, h), "render_2");
    Vector2i pos(
        VideoMode::getDesktopMode().width / 2 - window->getSize().x / 2,
        VideoMode::getDesktopMode().height / 2 - window->getSize().y / 2
    );
    window->setPosition(pos);
    window->setActive(false);
    Event event = Event();

    auto *image = new sf::Image();
    image->create(w, h);
    auto *texture = new sf::Texture();
    texture->create(w, h);
    auto *sprite = new sf::Sprite(*texture);

    texture->update(*image);

//    auto *th = new sf::Thread([=] { return fill_pic(image, texture); });
//    th->launch();
    auto *t = new std::thread(fill_pic, image, texture);
//    t->join();
    t->detach();

    while (window->isOpen())
    {
        while (window->pollEvent(event))
        {
            switch (event.type)
            {
                case Event::Closed:
                    window->close();
                    break;
                case Event::MouseMoved:
//                    image->setPixel(
//                        (unsigned int) event.mouseMove.x,
//                        (unsigned int) event.mouseMove.y,
//                        sf::Color::Green);
//                    texture->update(*image);
                    break;
                default:
                    break;
            }
        }
        window->clear();
        texture->update(*image);
        window->draw(*sprite);
        window->display();

    }

    delete window;
    delete image;
    delete texture;
    delete sprite;
//    delete t;
}
