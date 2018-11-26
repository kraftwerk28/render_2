//
// Created by kraftwerk28 on 22.09.18.
//

#ifndef RENDER_2_FILE_PARSER_HPP
#define RENDER_2_FILE_PARSER_HPP

#include <fstream>
#include <iostream>
#include <string.h>
#include "file_parser.hpp"
#include "util.hpp"

class file_parser
{
private:
    static std::vector<std::string> splitstr(std::string, char);

    static vector3 parse_vector(std::string &);
    static plane parse_plane(std::string &, obj_data *);

public:
    static void parse(const char *, obj_data &);
};


#endif //RENDER_2_FILE_PARSER_HPP
