#include "dot.h"
#include "renderer.h"

befry::Dot::Dot(std::string_view obj_name, Vector2 pos) :GameObject(obj_name, pos) {}
befry::Dot::~Dot() = default;

void befry::Dot::draw()
{
	Renderer::drawSymbol(position, "██");
}

