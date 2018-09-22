//
// Created by kraftwerk28 on 22.09.18.
//

#ifndef RENDER_2_UTIL_H
#define RENDER_2_UTIL_H

#include <cmath>

struct vector3 {
    vector3();

    vector3(float &, float &, float &);

    vector3(float, float, float);

    vector3 operator+(vector3 &vct);

    vector3 operator-(vector3 &vct);

    vector3 operator*(float &num);

    vector3 operator/(float &num);

    static vector3 cross(vector3 &vct1, vector3 &vct2);

    static float dot(vector3 &vct1, vector3 &vct2);

    vector3 norm();

    float length();

    static float angle(vector3 &vct1, vector3 &vct2);

    float x, y, z;
};


#endif //RENDER_2_UTIL_H
