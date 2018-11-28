//
// Created by kraftwerk28 on 29.09.18.
//

#ifndef RENDER_2_BSP_TREE_H
#define RENDER_2_BSP_TREE_H

#include <algorithm>

#include "util.h"

struct bsp_node
{
  bsp_node *children[8];

  bsp_node();

  ~bsp_node();

  bsp_node(std::vector<uint> _vert_indexes,
           std::pair<vector3, vector3> _bounds);

  std::vector<uint> vert_indexes;

  std::pair<vector3, vector3> bounds;

};

class bsp_tree
{
private:
  std::pair<vector3, vector3> get_bounds(std::vector<uint> indexes);

//    std::pair<float, float> bounds_x(std::vector<uint> indexes, uint count);
//
//    std::pair<float, float> bounds_y(vector<uint> indexes, uint count);
//
//    std::pair<float, float> bounds_z(uint *indexes, uint count);

  void divide(bsp_node *_node);

  std::vector<uint> *
  split_verts(std::vector<uint> &indexes, float avg_x, float avg_y,
              float avg_z);

  obj_data *data = nullptr;

  unsigned int threshold = 0;

  bsp_node *root = nullptr;

public:
  bsp_tree();

  ~bsp_tree();

  void build(obj_data *_obj_data, unsigned int _threshold = 64);

  uint node_counter = 1;
};

#endif //RENDER_2_BSP_TREE_H
