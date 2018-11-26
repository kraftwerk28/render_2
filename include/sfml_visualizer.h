//
// Created by kraftwerk28 on 22.09.18.
//

#ifndef RENDER_2_SFML_VISUALIZER_H
#define RENDER_2_SFML_VISUALIZER_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "util.h"

using sf::Window;
using sf::Event;
using sf::VideoMode;
using sf::Vector2i;

class sfml_visualizer
{
public:
  static void
  create_window(unsigned int w,
                unsigned int h,
                sf::Image *image,
                bool *close_trigger);
};


#endif //RENDER_2_SFML_VISUALIZER_H
