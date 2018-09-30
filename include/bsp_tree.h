//
// Created by kraftwerk28 on 29.09.18.
//

#ifndef RENDER_2_BSP_TREE_H
#define RENDER_2_BSP_TREE_H

#include <cmath>
#include <algorithm>

#include "util.h"

struct bsp_node
{
    bsp_node *children[4];

    bsp_node();

    bsp_node(unsigned int _vertices_count, vector3 *_vertices_ptr,
             vector3 bound1, vector3 bound2);

    unsigned int vertices_count = 0;

    vector3 *vertices = nullptr;

    std::pair<vector3, vector3> bounds;
};

class bsp_tree
{
private:
    void divide(bsp_node *_node);

public:
    bsp_tree();

    void build(const obj_data &_obj_data, int vert_threshold = 64);
};

#endif //RENDER_2_BSP_TREE_H
