//
// Created by kraftwerk28 on 22.09.18.
//

#include "../include/sfml_visualizer.h"
#include <unistd.h>
#include <thread>
#include <iostream>
#include <math.h>
#include <functional>

char randcl()
{
    return rand() % 256;
}

void fill_pic(sf::Image *image, sf::Texture *texture, bool &finished)
{
    int _to = image->getSize().y * image->getSize().x;
    for (int i = 0; i < image->getSize().x; i++)
    {
        for (int j = 0; j < image->getSize().y; j++)
        {
            image->setPixel(i, j, sf::Color(
                cosf(i / image->getSize().x * M_2_PI) * 255,
                sinf(i / image->getSize().x * M_2_PI) * 255,
                cosf(j / image->getSize().y * M_2_PI) * 255,
                255));
            usleep(static_cast<__useconds_t>(0.5));
        }
    }

    finished = true;
}

void
sfml_visualizer::create_window(unsigned int w, unsigned int h, sf::Image *image,
                               bool *close_trigger)
{
    auto *window = new sf::RenderWindow(sf::VideoMode(w, h), "render_2");
    Vector2i pos(
        VideoMode::getDesktopMode().width / 2 - window->getSize().x / 2,
        VideoMode::getDesktopMode().height / 2 - window->getSize().y / 2
    );
    window->setPosition(pos);
    window->setActive(false);
    Event event = Event();

    auto *texture = new sf::Texture();
    texture->create(w, h);
    auto *sprite = new sf::Sprite(*texture);

    texture->update(*image);


    while (window->isOpen())
    {
        while (window->pollEvent(event))
        {
            switch (event.type)
            {
                case Event::Closed:
                    window->close();
                    *close_trigger = true;
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
    delete texture;
    delete sprite;
}
