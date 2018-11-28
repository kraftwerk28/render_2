//
// Created by kraftwerk28 on 22.09.18.
//

#include "util_test.h"

#define VECTOR_COUNT 1000000

using namespace std;

void util_test::test_vector3()
{
  vector3 v1(3, 8, 10), v2(6, 7, -11);
  cout << boolalpha << (vector3::cross(v1, v2) == vector3(-158, 93, -27))
       << endl;
  cout << boolalpha << (vector3(98123, -1237, 18).norm().length() == 1)
       << endl;

  auto pr = pair<vector3, vector3>(vector3(-1, -1, -1), vector3(1, 1, 1));
  auto orig = vector3(1.009, 0, 0),
    dir = vector3(-1, -1, 0);


  vector<int> vct = {2, 23, 2, 2, 123, 4};
  auto mx = std::max_element(vct.begin(), vct.end(),
                             [](int one, int two) {
                               return one < two;
                             });
  cout << *mx << endl;

  cout << boolalpha << box_intersection(pr, orig, dir) << endl;
}
