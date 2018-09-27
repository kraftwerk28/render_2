//
// Created by kraftwerk28 on 22.09.18.
//

#ifndef RENDER_2_FILE_PARSER_HPP
#define RENDER_2_FILE_PARSER_HPP

#include <fstream>
#include <iostream>
#include <string.h>
#include "file_parser.h"
#include "util.h"

class file_parser
{
private:
    static std::vector<std::string> splitstr(std::string, const char);

    static vector3 parse_vector(std::string);

public:
    static void parse(const char *, obj_data &);
};


#endif //RENDER_2_FILE_PARSER_HPP
