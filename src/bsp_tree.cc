//
// Created by kraftwerk28 on 29.09.18.
//

#include "../include/bsp_tree.h"

using std::pair;
using std::vector;

bsp_node::bsp_node() = default;

bsp_node::bsp_node(vector<uint> _vert_indexes,
                   std::pair<vector3, vector3> _bounds)
  : vert_indexes(std::move(_vert_indexes)),
    bounds(std::move(_bounds))
{}

bsp_node::~bsp_node()
{
  for (let &i : children)
  {
    delete i;
  }
}

bsp_tree::bsp_tree() = default;

bsp_tree::~bsp_tree()
{
  delete data;
  delete root;
}

void bsp_tree::divide(bsp_node *_node)
{
  const let bnds = get_bounds(_node->vert_indexes);

  const float
    avg_x = (bnds.first.x + bnds.second.x) / 2,
    avg_y = (bnds.first.y + bnds.second.y) / 2,
    avg_z = (bnds.first.z + bnds.second.z) / 2;

  vector<uint> *parts = split_verts(
    _node->vert_indexes,
    avg_x,
    avg_y,
    avg_z);

  using std::make_pair;
  pair<vector3, vector3> calc_bounds[8] = { // NOT SECURE !!!
    make_pair(bnds.first,
              vector3(avg_x, avg_y, avg_z)),
    make_pair(vector3(bnds.first.x, avg_y, bnds.first.z),
              vector3(avg_x, bnds.second.y, avg_z)),
    make_pair(vector3(avg_x, avg_y, bnds.first.z),
              vector3(bnds.second.x, bnds.second.y, avg_z)),
    make_pair(vector3(avg_x, bnds.first.y, bnds.first.z),
              vector3(bnds.second.x, avg_y, avg_z)),

    make_pair(vector3(bnds.first.x, bnds.first.y, avg_z),
              vector3(avg_x, avg_y, bnds.second.z)),
    make_pair(vector3(bnds.first.x, avg_y, avg_z),
              vector3(avg_x, bnds.second.y, bnds.second.z)),
    make_pair(vector3(avg_x, avg_y, avg_z),
              vector3(bnds.second.x, bnds.second.y, bnds.second.z)),
    make_pair(vector3(avg_x, bnds.first.y, avg_z),
              vector3(bnds.second.x, avg_y, bnds.second.z))
  };

  for (int i = 0; i < 8; ++i)
  {
    node_counter++;
    _node->children[i] = new bsp_node(parts[i],
                                      calc_bounds[i]);
    if (_node->children[i]->vert_indexes.size() > threshold)
    {
      divide(_node->children[i]);
    }
  }

}

void bsp_tree::build(obj_data *_obj_data, uint _threshold)
{
  data = _obj_data;
  threshold = _threshold;
  let boilerplate = vector<uint>();
  boilerplate.reserve(data->vertices.size());
  for (size_t i = 0; i < data->vertices.size(); ++i)
  {
    boilerplate.push_back((uint) i);
  }

  let bounds = get_bounds(boilerplate);


  let node = new bsp_node(boilerplate,
                          bounds);


  root = node;
  divide(root);
}

std::vector<uint> *
bsp_tree::split_verts(
  vector<uint> &indexes,
  float avg_x,
  float avg_y,
  float avg_z
)
{
  let result = new vector<uint>[8];

  for (int i = 0; i < 8; ++i)
  {
    result[i] = vector<uint>();
  }

  for (size_t i = 0; i < indexes.size(); ++i)
  {
    let *d = &data->vertices[i];
    if (d->z > avg_z)
    {
      if (d->x > avg_x && d->y > avg_y)
        result[0].push_back((uint) i);
      else if (d->x > avg_x && d->y < avg_y)
        result[1].push_back((uint) i);
      else if (d->x < avg_x && d->y < avg_y)
        result[2].push_back((uint) i);
      else if (d->x < avg_x && d->y > avg_y)
        result[3].push_back((uint) i);
    } else
    {
      if (d->x > avg_x && d->y > avg_y)
        result[4].push_back((uint) i);
      else if (d->x > avg_x && d->y < avg_y)
        result[5].push_back((uint) i);
      else if (d->x < avg_x && d->y < avg_y)
        result[6].push_back((uint) i);
      else if (d->x < avg_x && d->y > avg_y)
        result[7].push_back((uint) i);
    }


  }
  return result;

}

std::pair<vector3, vector3> bsp_tree::get_bounds(std::vector<uint> indexes)
{
  const let bind = [&indexes]
    (std::function<bool(uint v1, uint v2)> functor) {
    return std::max_element(indexes.begin(), indexes.end(), functor);
  };

  const float
    max_x = *bind([this](uint v1, uint v2) {
    return data->vertices[v1].x < data->vertices[v2].x;
  }),
    min_x = *bind([&](uint v1, uint v2) {
    return data->vertices[v1].x > data->vertices[v2].x;
  }),

    max_y = *bind([&](uint v1, uint v2) {
    return data->vertices[v1].y < data->vertices[v2].y;
  }),
    min_y = *bind([&](uint v1, uint v2) {
    return data->vertices[v1].y > data->vertices[v2].y;
  }),

    max_z = *bind([&](uint v1, uint v2) {
    return data->vertices[v1].z > data->vertices[v2].z;
  }),
    min_z = *bind([&](uint v1, uint v2) {
    return data->vertices[v1].z < data->vertices[v2].z;
  });


  return pair<vector3, vector3>(
    vector3(min_x, min_y, min_z),
    vector3(max_x, max_y, max_z)
  );
}
