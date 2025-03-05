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
        Sprite(const Vector2 &position, Texture texture);
        ~Sprite() override;

        void draw() override;
        void clear();

        void set_position(const Vector2 &new_position);
        void set_texture(const Texture &new_texture);

        Vector2 get_position() const;
        Vector2 get_size() const;
    };
}

#endif
