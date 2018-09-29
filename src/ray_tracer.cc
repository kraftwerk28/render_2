//
// Created by kraftwerk28 on 24.09.18.
//

#include "../include/ray_tracer.h"

typedef unsigned int _uint;

using std::tuple;
using std::get;

void ray_tracer::trace_to_image(obj_data *_obj_data, camera *_camera,
                                sf::Image *_sf_image)
{
    int w = _camera->resolution_x, h = _camera->resolution_y;
    float distance = _camera->size / (2 * tanf(to_rad(_camera->fov) / 2));
    vector3
        plane_vec = _camera->look_direction.norm() * distance,
        right = vector3::cross(_camera->look_direction,
                               _camera->upwards).norm();

    for (int y = 0; y < _camera->resolution_y; y++)
    {
        for (int x = 0; x < _camera->resolution_x; x++)
        {
            float
                real_x = (x - w / 2.0f) / (float) w,

                real_y = (y - h / 2.0f) / (float) h;

            vector3
                dx = right * real_x,

                dy =
                vector3::cross(right, _camera->look_direction).norm() * real_y,

                ray_dir = dx + dy + _camera->look_direction;

            size_t i = 0;

            for (; i < _obj_data->planes.size(); i++)
            {
                const auto res = intersection(
                    _camera->position,
                    ray_dir,
                    _obj_data->planes[i]
                );

                if (get<0>(res) &&
                    vector3::angle(get<2>(res), ray_dir) > M_PI_2)
                {
                    const auto k =
                        (sf::Uint8) (
                            (float) vector3::angle(get<2>(res), ray_dir) /
                            (float) M_PI *
                            255);
                    auto color = sf::Color(k, k, k);
                    _sf_image->setPixel((_uint) x, (_uint) y, color);
                    break;
                }
            }
            if (i >= _obj_data->planes.size())
            {
                _sf_image->setPixel((_uint) x, (_uint) y, sf::Color::Black);
            }
        }
    }
}

