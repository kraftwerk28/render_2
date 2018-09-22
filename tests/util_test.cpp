//
// Created by kraftwerk28 on 22.09.18.
//

#include "util_test.h"

#define VECTOR_COUNT 1000000

void util_test::test_vector3() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<float> r(0.0, 10.0);

    for (int i = 0; i < VECTOR_COUNT; i++) {
        auto *z = new vector3(r(mt), r(mt), r(mt));
        std::cout << z->x << " " << z->y << " " << z->z << std::endl;
        delete z;
    }

}
