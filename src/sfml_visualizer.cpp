//
// Created by kraftwerk28 on 22.09.18.
//

#include "../include/sfml_visualizer.hpp"

void sfml_visualizer::create_window(unsigned int w, unsigned int h) {
    auto *window = new sf::Window(sf::VideoMode(w, h), "render_2");
    Vector2i pos(
        VideoMode::getDesktopMode().width / 2 - window->getSize().x / 2,
        VideoMode::getDesktopMode().height / 2 - window->getSize().y / 2
    );
//    window->setPosition(pos);
    Event event = Event();

    while (window->isOpen()) {
        while (window->pollEvent(event)) {
            switch (event.type) {
                case Event::Closed:
                    window->close();
                    break;
                default:
                    break;
            }
        }

        window->display();
    }

    delete window;
}
