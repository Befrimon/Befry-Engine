#include "game_objects/sprite.h"
#include "renderer.h"

bgf::Sprite::Sprite(const Vector2 &position, const std::string &texture_path) :GameObject(position), texture(Texture(texture_path)) {}
bgf::Sprite::~Sprite() = default;

void bgf::Sprite::draw() const
{
    //for (int x = 0; x < texture.size.X; x++)
    for (int y = 0; y < texture.size.Y; y++)
        Renderer::drawSymbols(position + Vector2{0, y}, texture.data[y]);
}
void bgf::Sprite::clear() const
{
    for (int x = 0; x < texture.size.X; x++)
    for (int y = 0; y < texture.size.Y; y++)
        Renderer::drawSymbols(position + Vector2{x, y}, ' ');
}

void bgf::Sprite::set_texture(const std::string &new_texture)
{
    texture = Texture(new_texture);
}
void bgf::Sprite::set_position(const Vector2 &new_position)
{
    position = new_position;
}

bgf::Vector2 bgf::Sprite::get_size() const
{
    return texture.size;
}
