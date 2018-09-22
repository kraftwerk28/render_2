//
// Created by kraftwerk28 on 22.09.18.
//

#ifndef RENDER_2_FILE_PARSER_HPP
#define RENDER_2_FILE_PARSER_HPP

#include <fstream>
#include <iostream>
#include "../include/file_parser.hpp"
#include "util.hpp"

class file_parser {
public:
    static std::pair<vector3 *, long int> parse(const char *file_path);
};

#endif //RENDER_2_FILE_PARSER_HPP
