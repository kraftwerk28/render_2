//
// Created by kraftwerk28 on 22.09.18.
//

#include "../include/util.hpp"

float to_rad(float deg)
{
    return (float) (deg * M_PI / 180);
}

float to_deg(float rad)
{
    return (float) (rad * 180 / M_PI);
}

// region vector3

vector3::vector3()
    : x(0), y(0), z(0) {}

vector3::vector3(float &_x, float &_y, float &_z)
    : x(_x), y(_y), z(_z) {}

vector3::vector3(float _x, float _y, float _z)
    : x(_x), y(_y), z(_z) {}

vector3 vector3::operator+(vector3 &vct)
{
    return vector3(x + vct.x, y + vct.y, z + vct.z);
}

vector3 vector3::operator-(vector3 &vct)
{
    return vector3(x - vct.x, y - vct.y, z - vct.z);
}

vector3 vector3::operator*(float &num)
{
    return vector3();
}

vector3 vector3::operator/(float &num)
{
    return vector3(x / num, y / num, z / num);
}

vector3 vector3::cross(vector3 &vct1, vector3 &vct2)
{
    return vector3(
        vct1.y * vct2.z - vct1.z * vct2.y,
        vct1.z * vct2.x - vct1.x * vct2.z,
        vct1.x * vct2.y - vct1.y * vct2.x
    );
}

float vector3::dot(vector3 &vct1, vector3 &vct2)
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

float vector3::length()
{
    return (float) std::sqrt(
        std::pow(x, 2.0) +
        std::pow(y, 2.0) +
        std::pow(z, 2.0)
    );
}

float vector3::angle(vector3 &vct1, vector3 &vct2)
{
    return acosf(
        vector3::dot(vct1, vct2) /
        (vct1.length() * vct2.length())
    );
}

// endregion


// region plane

plane::plane()
    : v1(new vector3()), v2(new vector3()), v3(new vector3()) {}

plane::plane(vector3 &_v1, vector3 &_v2, vector3 &_v3)
    : v1(&_v1), v2(&_v2), v3(&_v3) {}
// endregion


// region camera


// endregion


camera::camera(vector3 _pos, vector3 _dir, int _res_x = 512, int _res_y = 512,
               float _fov = 60, float _size = 1)
    : position(_pos),
      look_direction(_dir),
      resolution_x(_res_x),
      resolution_y(_res_y),
      fov(_fov),
      size(_size) {}

light_source::light_source()
{

}
