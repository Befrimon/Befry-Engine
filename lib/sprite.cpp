#include "game_objects/sprite.h"
#include "renderer.h"

#include <utility>

bgf::Sprite::Sprite(const Vector2 &position, Texture texture) :GameObject(position), texture(std::move(texture)) {}
bgf::Sprite::~Sprite() = default;

void bgf::Sprite::draw()
{
    for (int x = 0; x < texture.size.X; x++)
    for (int y = 0; y < texture.size.Y; y++)
        Renderer::drawSymbols(position + Vector2{x, y}, texture.data[y][x]);
}
void bgf::Sprite::clear()
{
    for (int x = 0; x < texture.size.X; x++)
    for (int y = 0; y < texture.size.Y; y++)
        Renderer::drawSymbols(position + Vector2{x, y}, ' ');
}

void bgf::Sprite::set_texture(const Texture &new_texture)
{
    texture = new_texture;
}
void bgf::Sprite::set_position(const Vector2 &new_position)
{
    position = new_position;
}

bgf::Vector2 bgf::Sprite::get_position() const
{
    return position;
}
bgf::Vector2 bgf::Sprite::get_size() const
{
    return texture.size;
}
