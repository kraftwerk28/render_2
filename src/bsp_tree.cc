//
// Created by kraftwerk28 on 29.09.18.
//

#include "../include/bsp_tree.h"

using std::pair;
using std::vector;

bsp_node::bsp_node() = default;

bsp_node::bsp_node(vector<vector3> *vertices, _uint _vert_start,
                   _uint _vert_count,
                   vector3 bound1, vector3 bound2)
    : vertices_count(_vert_start),
      vertices(nullptr),
      bounds(pair(bound1, bound2))
{

}


void bsp_tree::divide(bsp_node *_node)
{
    const auto
        b_x = bounds_x(0, 0),
        b_y = bounds_y(0, 0),
        b_z = bounds_z(0, 0);

    const float
        avg_x = (b_x.first + b_x.second) / 2,
        avg_y = (b_y.first + b_y.second) / 2,
        avg_z = (b_z.first + b_z.second) / 2;



    // implement !!!
}

bsp_tree::bsp_tree() = default;

void bsp_tree::build(obj_data *_obj_data, unsigned int _threshold)
{

    data = _obj_data;
    threshold = _threshold;

    auto
        b_x = bounds_x(0, (_uint) data->vertices.size()),
        b_y = bounds_y(0, (_uint) data->vertices.size()),
        b_z = bounds_z(0, (_uint) data->vertices.size());

    auto *node = new bsp_node(
        &data->vertices,
        0,
        (_uint) data->vertices.size(),
        vector3(b_x.first, b_y.first, b_z.first),
        vector3(b_x.second, b_y.second, b_z.second));


}


std::pair<float, float> bsp_tree::bounds_x(_uint start, _uint count)
{
    return pair(
        std::max_element(
            data->vertices.begin() + start,
            data->vertices.begin() + start + count,
            [](vector3 v1, vector3 v2) {
                return v1.x < v2.x;
            })->x,

        std::max_element(
            data->vertices.begin() + start,
            data->vertices.begin() + start + count,
            [](vector3 v1, vector3 v2) {
                return v1.x > v2.x;
            })->x
    );
}

std::pair<float, float> bsp_tree::bounds_y(_uint start, _uint count)
{
    return pair(
        std::max_element(
            data->vertices.begin() + start,
            data->vertices.begin() + start + count,
            [](vector3 v1, vector3 v2) {
                return v1.y < v2.y;
            })->y,

        std::max_element(
            data->vertices.begin() + start,
            data->vertices.begin() + start + count,
            [](vector3 v1, vector3 v2) {
                return v1.y > v2.y;
            })->y
    );
}

std::pair<float, float> bsp_tree::bounds_z(_uint start, _uint count)
{
    return pair(
        std::max_element(
            data->vertices.begin() + start,
            data->vertices.begin() + start + count,
            [](vector3 v1, vector3 v2) {
                return v1.z > v2.z;
            })->z,
        std::max_element(
            data->vertices.begin() + start,
            data->vertices.begin() + start + count,
            [](vector3 v1, vector3 v2) {
                return v1.z < v2.z;
            })->z
    );
}
