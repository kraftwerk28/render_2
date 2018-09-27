//
// Created by kraftwerk28 on 24.09.18.
//

#include "../include/ray_tracer.h"

void trace_to_image(obj_data *_obj_data, camera *_camera, sf::Image *_sf_image)
{
    int w = _camera->resolution_x, h = _camera->resolution_y;
    float distance = _camera->size / (2 * tanf(to_rad(_camera->fov) / 2));

}

