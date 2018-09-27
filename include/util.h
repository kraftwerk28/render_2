//
// Created by kraftwerk28 on 22.09.18.
//

#ifndef RENDER_2_UTIL_H
#define RENDER_2_UTIL_H

#include <cmath>

float to_rad(float);

float to_deg(float);

struct vector3
{
    vector3();

    vector3(float &, float &, float &);

    vector3(float, float, float);

    vector3 operator+(vector3 &);

    vector3 operator-(vector3 &);

    vector3 operator*(float &);

    vector3 operator/(float &);

    static vector3 cross(vector3 &, vector3 &);

    static float dot(vector3 &, vector3 &);

    vector3 norm();

    float length();

    static float angle(vector3 &, vector3 &);

    float x, y, z;
};

struct plane
{
    plane();

    plane(vector3 &, vector3 &, vector3 &);

    vector3 *v1, *v2, *v3;

};

struct camera
{
    vector3 position, look_direction, upwards;
    int resolution_x, resolution_y;
    float fov, size;

    camera(vector3, vector3, int, int, float, float);
};

struct light_source
{
    light_source();

    vector3 position;
    float strength;
};

struct obj_data
{
    long int vertices_count;
    vector3 *vertices;
    long int planes_count;
    plane *planes;
};

#endif //RENDER_2_UTIL_H
