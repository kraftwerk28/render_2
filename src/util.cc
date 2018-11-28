//
// Created by kraftwerk28 on 22.09.18.
//
#include "../include/util.h"

using namespace std;
using std::function;

// region stuff

float to_rad(float deg)
{
  return (float) (deg * M_PI / 180);
}

float to_deg(float rad)
{
  return (float) (rad * 180 / M_PI);
}

std::tuple<bool, vector3, vector3>
intersection(vector3 &origin, vector3 &direction, plane &facet)
{
  const float E = 1e-5f;
  float
    x0 = facet.v1->x,
    y0 = facet.v1->y,
    z0 = facet.v1->z,
    x1 = facet.v2->x,
    y1 = facet.v2->y,
    z1 = facet.v2->z,
    x2 = facet.v3->x,
    y2 = facet.v3->y,
    z2 = facet.v3->z,

    A = (y1 - y0) * (z2 - z0) - (y2 - y0) * (z1 - z0),
    B = (x2 - x0) * (z1 - z0) - (x1 - x0) * (z2 - z0),
    C = (x1 - x0) * (y2 - y0) - (y1 - y0) * (x2 - x0),
    D =
    x0 * ((y2 - y0) * (z1 - z0) - (y1 - y0) * (z2 - z0)) +
    y0 * ((x1 - x0) * (z2 - z0) - (x2 - x0) * (z1 - z0)) +
    z0 * ((y1 - y0) * (x2 - x0) - (x1 - x0) * (y2 - y0)),
    t =
    -(A * origin.x + B * origin.y + C * origin.z + D) /
    (A * direction.x + B * direction.y + C * direction.z),

    x = t * direction.x + origin.x,
    y = t * direction.y + origin.y,
    z = t * direction.z + origin.z;


  vector3 normal(A, B, C);
  normal = normal.norm();

  vector3 res(x, y, z);
  vector3 edge1 = *facet.v2 - *facet.v1,
    edge2 = *facet.v3 - *facet.v1,
    h = vector3::cross(direction, edge2);

  float a = vector3::dot(edge1, h);

  if (a > -E && a < E)
  {
    return {false, res, normal};
  }


  float f = 1 / a;
  vector3 s = origin - *facet.v1;
  float u = f * vector3::dot(s, h);

  if (u < 0.0 || u > 1.0)
  {
    return {false, res, normal};
  }


  vector3 q = vector3::cross(s, edge1);
  float v = f * vector3::dot(direction, q);
  if (v < 0.0 || u + v > 1.0)
  {
    return {false, res, normal};
  }


  float tt = f * vector3::dot(edge2, q);

  return {tt > E, res, normal};
}

bool box_intersection(std::pair<vector3, vector3> &bounds, vector3 &origin,
                      vector3 &direction)
{
  vector3 min = bounds.first, max = bounds.second;
  float
    tmin = (min.x - origin.x) / direction.x,
    tmax = (max.x - origin.x) / direction.x;

  if (tmin > tmax)
    _swap(tmin, tmax);

  float
    tymin = (min.y - origin.y) / direction.y,
    tymax = (max.y - origin.y) / direction.y;

  if (tymin > tymax)
    _swap(tymin, tymax);

  if ((tmin > tymax) || (tymin > tmax))
    return false;

  if (tymin > tmin)
    tmin = tymin;

  if (tymax < tmax)
    tmax = tymax;

  float
    tzmin = (min.z - origin.z) / direction.z,
    tzmax = (max.z - origin.z) / direction.z;

  if (tzmin > tzmax)
    _swap<float>(tzmin, tzmax);

  if ((tmin > tzmax) || (tzmin > tmax))
    return false;

  if (tzmin > tmin)
    tmin = tzmin;

  if (tzmax < tmax)
    tmax = tzmax;

  return true;
}

template<class t>
void _swap(t &val1, t &val2)
{
  t temp = val1;
  val1 = val2;
  val2 = temp;
}

// endregion

// region vector3

vector3::vector3()
  : x(0), y(0), z(0)
{}

vector3::vector3(const float _x, const float _y, const float _z)
  : x(_x), y(_y), z(_z)
{}

//vector3::vector3(const float &_x, const float &_y, const float &_z)
//    : x(_x), y(_y), z(_z) {}

vector3::vector3(const vector3 &vec)
  : x(vec.x), y(vec.y), z(vec.z)
{
//    cout << "copy call\n";
}

vector3 vector3::operator+(const vector3 &vct)
{
  return vector3(x + vct.x, y + vct.y, z + vct.z);
}

vector3 vector3::operator-(const vector3 &vct)
{
  return vector3(x - vct.x, y - vct.y, z - vct.z);
}

vector3 vector3::operator*(const float &num)
{
  return vector3(x * num, y * num, z * num);
}

vector3 vector3::operator/(const float &num)
{
  return vector3(x / num, y / num, z / num);
}

bool vector3::operator==(const vector3 &v)
{
  return x == v.x && y == v.y && z == v.z;
}

vector3 vector3::cross(const vector3 &vct1, const vector3 &vct2)
{
  return vector3(
    vct1.y * vct2.z - vct1.z * vct2.y,
    vct1.z * vct2.x - vct1.x * vct2.z,
    vct1.x * vct2.y - vct1.y * vct2.x
  );
}

float vector3::dot(const vector3 &vct1, const vector3 &vct2)
{
  return
    vct1.x * vct2.x +
    vct1.y * vct2.y +
    vct1.z * vct2.z;
}

vector3 vector3::norm()
{
  float l = length();
  return vector3(x / l, y / l, z / l);
}

float vector3::length() const
{
  return (float) std::sqrt(x * x + y * y + z * z);
}

float vector3::angle(const vector3 &vct1, const vector3 &vct2)
{
  return acosf(
    vector3::dot(vct1, vct2) /
    (vct1.length() * vct2.length())
  );
}

void vector3::print()
{
  cout << x << " " << y << " " << z << endl;
}

// endregion

// region plane

plane::plane()
  : v1(new vector3()), v2(new vector3()), v3(new vector3())
{}

plane::plane(vector3 &_v1, vector3 &_v2, vector3 &_v3)
  : v1(&_v1), v2(&_v2), v3(&_v3)
{}

plane::plane(const plane &p) = default;
// endregion


// region camera

camera::camera(vector3 _pos, vector3 _dir, int _res_x, int _res_y,
               float _fov, float _size)
  : position(_pos),
    look_direction(_dir),
    resolution_x(_res_x),
    resolution_y(_res_y),
    fov(_fov),
    size(_size),
    upwards(vector3(0, 0, 1))
{}

// endregion

lightSource::lightSource()
= default;


