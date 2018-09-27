#include <utility>

//
// Created by kraftwerk28 on 22.09.18.
//

#include "../include/file_parser.h"

#define VECTOR_SYMBOL 'v'
#define PLANE_SYMBOL 'f'
#define WHITESPACE ' '

using std::string;
using std::vector;
using std::cout;
using std::endl;

void file_parser::parse(const char *path, obj_data &data)
{
    std::ifstream file_stream(std::string("../") + path);
    std::string line;

    if (file_stream.is_open())
    {
        std::cout << "opening file...\n";
        while (std::getline(file_stream, line))
        {
            switch (line[0])
            {
                case VECTOR_SYMBOL:
                {
                    vector3 v = file_parser::parse_vector(line);
                    data.vectices.push_back(v);
                    break;
                }

                case PLANE_SYMBOL:
                {

                    break;
                }

                default:
                    break;
            }
        }
    } else
    {
        cout << "File does not exist\n";
    }


}

vector3 file_parser::parse_vector(string str)
{
    const auto spl = splitstr(std::move(str), ' ');

    const auto sx = (float) strtod(spl[1].c_str(), nullptr);
    const auto sy = (float) strtod(spl[2].c_str(), nullptr);
    const auto sz = (float) strtod(spl[3].c_str(), nullptr);

    cout << sx << " " << sy << " " << sz << endl;

    return vector3(sx, sy, sz);
}

std::vector<std::string> file_parser::splitstr(string str, const char delim)
{
    vector<string> result;
    unsigned long pos = 0;
    while (str.length())
    {
        pos = str.find_first_of(delim);
        if (pos == -1)
        {
            result.push_back(str);
            break;
        }
        result.push_back(str.substr(0, pos));
        str = str.substr(pos + 1, str.length());

    }

    result.shrink_to_fit(); // maybe remove
    return result;
}
