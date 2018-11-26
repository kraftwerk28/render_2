//
// Created by kraftwerk28 on 22.09.18.
//

#include "../include/file_parser.h"

#define VECTOR_DESCR "v"
#define PLANE_DESCR "f"
#define WHITESPACE ' '
#define SLASH '/'

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::stoi;

void file_parser::parse(const char *path, obj_data &data)
{
  std::ifstream file_stream(std::string("../") + path);
  std::string line;

  if (file_stream.is_open())
  {
    std::cout << "Opening file...\n";
    while (std::getline(file_stream, line))
    {
      string descriptor = line.substr(0, line.find_first_of(WHITESPACE));
      if (descriptor == VECTOR_DESCR)
      {
        vector3 v = file_parser::parse_vector(line);
        data.vertices.push_back(v);
      } else if (descriptor == PLANE_DESCR)
      {
        plane p = file_parser::parse_plane(line, &data);
        data.planes.push_back(p);
      }
    }
  } else
  {
    cout << "File does not exist\n";
  }

  data.planes.shrink_to_fit();
  data.vertices.shrink_to_fit();

  cout << "Parsing finished\n";
  cout << "total vertices: " << data.vertices.size() << ";\ntotal facets: "
       << data.planes.size() << ";\n";

  file_stream.close();
}

vector3 file_parser::parse_vector(string &str)
{
  const let spl = splitstr(str, WHITESPACE);

  const let
    sx = (float) strtod(spl[1].c_str(), nullptr),
    sy = (float) strtod(spl[2].c_str(), nullptr),
    sz = (float) strtod(spl[3].c_str(), nullptr);

//    cout << sx << " " << sy << " " << sz << endl;

  return vector3(sx, sy, sz);
}

plane file_parser::parse_plane(std::string &str, obj_data *data)
{
  const let spl = splitstr(str, WHITESPACE);
  unsigned int v_inds[3];

  for (size_t i = 1; i < 4; ++i)
  {
    v_inds[i - 1] = (unsigned int) stoi(splitstr(spl[i], SLASH)[0]);
  }

  return plane(data->vertices[v_inds[0] - 1],
               data->vertices[v_inds[1] - 1],
               data->vertices[v_inds[2] - 1]);
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

//    result.shrink_to_fit(); // maybe remove
  return result;
}
