//
// Created by kraftwerk28 on 29.09.18.
//

#ifndef RENDER_2_BSP_TREE_H
#define RENDER_2_BSP_TREE_H

#include <cmath>
#include <algorithm>

#include "util.h"

typedef unsigned int _uint;

struct bsp_node
{
    bsp_node *children[4];

    bsp_node();

    bsp_node(std::vector <vector3> *vertices, _uint _vert_start, _uint _vert_count,
                 vector3 bound1, vector3 bound2);

    unsigned int vertices_count = 0;

    vector3 *vertices = nullptr;

    std::pair<vector3, vector3> bounds;
};

class bsp_tree
{
private:
    std::pair<float, float> bounds_x(_uint start, _uint count);

    std::pair<float, float> bounds_y(_uint start, _uint count);

    std::pair<float, float> bounds_z(_uint start, _uint count);

    void divide(bsp_node *_node);

    obj_data *data = nullptr;

    unsigned int threshold = 0;

    bsp_node *root = nullptr;

public:
    bsp_tree();

    void build(obj_data *_obj_data, unsigned int _threshold = 64);
};

#endif //RENDER_2_BSP_TREE_H
