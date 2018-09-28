//
// Created by kraftwerk28 on 24.09.18.
//

#ifndef RENDER_2_RAY_TRACER_HPP
#define RENDER_2_RAY_TRACER_HPP

#include <SFML/Graphics/Image.hpp>
#include "util.h"
#include <math.h>
#include <tuple>

class ray_tracer
{
public:
    static void trace_to_image(obj_data *, camera *, sf::Image *);
};

#endif //RENDER_2_RAY_TRACER_HPP
