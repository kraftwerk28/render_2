//
// Created by kraftwerk28 on 29.09.18.
//

#include "../include/bsp_tree.h"

using std::pair;

bsp_node::bsp_node() = default;

bsp_node::bsp_node(unsigned int _vertices_count, vector3 *_vertices_ptr,
                   vector3 bound1, vector3 bound2)
    : vertices_count(_vertices_count),
      vertices(_vertices_ptr),
      bounds(pair(bound1, bound2)) {}


void bsp_tree::divide(bsp_node *_node)
{
//    std::max_element()
}

bsp_tree::bsp_tree() = default;

void bsp_tree::build(const obj_data &_obj_data, int vert_threshold)
{

}
