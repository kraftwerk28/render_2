//
// Created by kraftwerk28 on 22.09.18.
//

#include "util_test.h"

#define VECTOR_COUNT 1000000

using namespace std;

void util_test::test_vector3()
{
    vector3 v1(3, 8, 10), v2(6, 7, -11);
    cout << (vector3::cross(v1, v2) == vector3(-158, 93, -27)) << endl;
    cout << (vector3(98123, -1237, 18).norm().length() == 1) << endl;
}
