//
// Created by kraftwerk28 on 22.09.18.
//

#include "../include/file_parser.hpp"

void parse(const char *path, obj_data &data)
{
    std::ifstream file_stream(path);
    char *line = new char[256];

    std::cout << "parsing file...\n";
    while (file_stream.getline(line, 256))
    {
        std::cout << line << std::endl;
    }

}
