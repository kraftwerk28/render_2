//
// Created by kraftwerk28 on 29.09.18.
//

#ifndef RENDER_2_BSP_TREE_H
#define RENDER_2_BSP_TREE_H

#include <cmath>
#include <algorithm>
#include <functional>

#include "util.hpp"

typedef unsigned int _uint;

struct bsp_node
{
    bsp_node *children[8];

    bsp_node();

    ~bsp_node();

    bsp_node(std::vector<_uint> _vert_indexes,
             std::pair<vector3, vector3> _bounds);

    std::vector<_uint> vert_indexes;

    std::pair<vector3, vector3> bounds;

};

class bsp_tree
{
private:
    std::pair<vector3, vector3> get_bounds(std::vector<_uint> indexes);

//    std::pair<float, float> bounds_x(std::vector<_uint> indexes, _uint count);
//
//    std::pair<float, float> bounds_y(vector<_uint> indexes, _uint count);
//
//    std::pair<float, float> bounds_z(_uint *indexes, _uint count);

    void divide(bsp_node *_node);

    std::vector<_uint> *
    split_verts(std::vector<_uint> &indexes, float avg_x, float avg_y,
                float avg_z);

    obj_data *data = nullptr;

    unsigned int threshold = 0;

    bsp_node *root = nullptr;

public:
    bsp_tree();

    ~bsp_tree();

    void build(obj_data *_obj_data, unsigned int _threshold = 64);

    _uint node_counter = 1;
};

#endif //RENDER_2_BSP_TREE_H
