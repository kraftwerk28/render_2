//
// Created by kraftwerk28 on 22.09.18.
//

#include "util.h"

// region vector3

vector3::vector3()
    : x(0), y(0), z(0) {}

vector3::vector3(float &_x, float &_y, float &_z)
    : x(_x), y(_y), z(_z) {}

vector3::vector3(float _x, float _y, float _z)
    : x(_x), y(_y), z(_z) {}

vector3 vector3::operator+(vector3 &vct) {
    return vector3(x + vct.x, y + vct.y, z + vct.z);
}

vector3 vector3::operator-(vector3 &vct) {
    return vector3(x - vct.x, y - vct.y, z - vct.z);
}

vector3 vector3::operator*(float &num) {
    return vector3();
}

vector3 vector3::operator/(float &num) {
    return vector3(x / num, y / num, z / num);
}

vector3 vector3::cross(vector3 &vct1, vector3 &vct2) {
    return vector3(
        vct1.y * vct2.z - vct1.z * vct2.y,
        vct1.z * vct2.x - vct1.x * vct2.z,
        vct1.x * vct2.y - vct1.y * vct2.x
    );
}

float vector3::dot(vector3 &vct1, vector3 &vct2) {
    return
        vct1.x * vct2.x +
        vct1.y * vct2.y +
        vct1.z * vct2.z;
}

vector3 vector3::norm() {
    float l = length();
    return vector3(x / l, y / l, z / l);
}

float vector3::length() {
    return (float) std::sqrt(
        std::pow(x, 2.0) +
        std::pow(y, 2.0) +
        std::pow(z, 2.0)
    );
}

float vector3::angle(vector3 &vct1, vector3 &vct2) {
    return acosf(
        vector3::dot(vct1, vct2) /
        (vct1.length() * vct2.length())
    );
}

// endregion
