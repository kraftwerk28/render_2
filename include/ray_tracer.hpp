//
// Created by kraftwerk28 on 24.09.18.
//

#ifndef RENDER_2_RAY_TRACER_HPP
#define RENDER_2_RAY_TRACER_HPP

#include <SFML/Graphics/Image.hpp>
#include <math.h>
#include <tuple>

#include "util.hpp"
#include "bsp_tree.hpp"

class ray_tracer
{
public:
    static void
    trace_to_image(obj_data *, camera *, sf::Image *,
                   float *progres = nullptr,
                   bool *render_pending = nullptr);
};

#endif //RENDER_2_RAY_TRACER_HPP
