//
// Created by kraftwerk28 on 29.09.18.
//

#include "../include/bsp_tree.h"

using std::pair;
using std::vector;

bsp_node::bsp_node() = default;

bsp_node::bsp_node(_uint *_vert_indexes, _uint _vert_count, vector3 bound1,
                   vector3 bound2)
    : vert_indexes(_vert_indexes),
      verts_count(_vert_count),
      bounds(pair(bound1, bound2)) {}

bsp_node::~bsp_node()
{
    for (bsp_node &i : children)
    {
        delete i;
    }
}

void bsp_tree::divide(bsp_node *_node)
{
    const auto
        b_x = bounds_x(_node->vert_indexes, _node->verts_count),
        b_y = bounds_y(_node->verts_start, _node->verts_count),
        b_z = bounds_z(_node->verts_start, _node->verts_count);

    const auto
        avg_x = (b_x.first + b_x.second) / 2,
        avg_y = (b_y.first + b_y.second) / 2,
        avg_z = (b_z.first + b_z.second) / 2;



    // implement !!!
}

bsp_tree::bsp_tree() = default;

bsp_tree::~bsp_tree()
{
    delete data;
    delete root;
}

void bsp_tree::build(obj_data *_obj_data, unsigned int _threshold)
{
    data = _obj_data;
    threshold = _threshold;

    auto
        b_x = bounds_x(&*data->vertices.begin(), (_uint) data->vertices.size()),
        b_y = bounds_y(&*data->vertices.begin(), (_uint) data->vertices.size()),
        b_z = bounds_z(&*data->vertices.begin(), (_uint) data->vertices.size());

    auto *node = new bsp_node(
        &data->vertices,
        (_uint) data->vertices.size(),
        vector3(b_x.first, b_y.first, b_z.first),
        vector3(b_x.second, b_y.second, b_z.second)
    );

    root = node;
}


std::pair<float, float> bsp_tree::bounds_x(vector3 *ptr, _uint count)
{
    return pair(
        get_max<vector3>(
            ptr,
            count,
            [](vector3 v1, vector3 v2) {
                return v1.x < v2.x;
            })->x,

        get_max<vector3>(
            data->vertices.begin() + ptr,
            data->vertices.begin() + ptr + count,
            [](vector3 v1, vector3 v2) {
                return v1.x > v2.x;
            })->x
    );
}

std::pair<float, float> bsp_tree::bounds_y(vector3 *ptr, _uint count)
{
    return pair(
        get_max<vector3>(
            ptr,
            count,
            [](vector3 v1, vector3 v2) {
                return v1.y < v2.y;
            })->y,

        get_max<vector3>(
            ptr,
            count,
            [](vector3 v1, vector3 v2) {
                return v1.y > v2.y;
            })->y
    );
}

std::pair<float, float> bsp_tree::bounds_z(vector3 *ptr, _uint count)
{
    return pair(
        get_max<vector3>(
            ptr,
            count,
            [](vector3 v1, vector3 v2) {
                return v1.z > v2.z;
            })->z,
        get_max<vector3>(
            ptr,
            count,
            [](vector3 v1, vector3 v2) {
                return v1.z < v2.z;
            })->z
    );
}
