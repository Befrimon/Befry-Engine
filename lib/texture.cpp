#include "types/texture.h"

#include <fstream>

bgf::Texture::Texture(const std::string &filepath): size({0, 0})
{
    std::ifstream fin(filepath);
    while (!fin.eof())
    {
        std::string line;
        std::getline(fin, line);
        data.push_back(line);
        size.Y++;
    }
    size.X = data[0].length();
    fin.close();
}
