//
// Created by kraftwerk28 on 22.09.18.
//

#include "../include/file_parser.hpp"

std::pair<vector3 *, long int> file_parser::parse(const char *file_path) {
    vector3 *res;
    std::ifstream file;
    file.open(file_path);


    file.close();
    return std::pair<vector3 *, long>();
}
