#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <vector>

#include "vector2.h"

namespace bgf
{
    struct Texture
    {
        Vector2 size;
        std::vector<std::string> data;

        explicit Texture(const std::string &filepath);
    };
}

#endif
