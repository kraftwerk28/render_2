//
// Created by kraftwerk28 on 22.09.18.
//

#ifndef RENDER_2_UTIL_H
#define RENDER_2_UTIL_H

#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>

float to_rad(float);

float to_deg(float);

struct vector3
{
    vector3();

    vector3(float, float, float);

//    vector3(const float &, const float &, const float &);

    vector3(const vector3 &);

    vector3 operator+(const vector3 &);

    vector3 operator-(const vector3 &);

    vector3 operator*(const float &);

    vector3 operator/(const float &);

    bool operator==(const vector3 &);

    static vector3 cross(const vector3 &, const vector3 &);

    static float dot(const vector3 &, const vector3 &);

    vector3 norm();

    float length();

    static float angle(vector3 &, vector3 &);

    void print();

    float x, y, z;
};

struct plane
{
    plane();

    plane(const plane &);

    plane(vector3 &, vector3 &, vector3 &);

    vector3 *v1, *v2, *v3;

};

struct camera
{
    vector3 position, look_direction, upwards;
    int resolution_x, resolution_y;
    float fov, size;

    camera(vector3 _pos, vector3 _dir, int _res_x = 512, int _res_y = 512,
           float _fov = 60, float _size = 1);
};

struct light_source
{
    light_source();

    vector3 position;
    float strength;
};

struct obj_data
{
    std::vector<vector3> vertices;
    std::vector<plane> planes;
};

std::tuple<bool, vector3, vector3>
intersection(vector3 &origin, vector3 &direction, plane &facet);

#endif //RENDER_2_UTIL_H
