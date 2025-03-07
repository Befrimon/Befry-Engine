#ifndef SPRITE_H
#define SPRITE_H

#include "game_object.h"
#include "../types/texture.h"

namespace bgf
{
    class Sprite : public GameObject
    {
    protected:
        Texture texture;

    public:
        Sprite(const Vector2 &position, const std::string &texture_path);
        ~Sprite() override;

        void draw() const override;
        void clear() const;

        void set_position(const Vector2 &new_position);
        void set_texture(const std::string &new_texture);

        [[nodiscard]]
        Vector2 get_size() const;
    };
}

#endif
