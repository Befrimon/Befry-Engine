#include "dot.h"
#include "renderer.h"

befry::Dot::Dot(std::string_view obj_name, Vector2 pos)
	:GameObject(obj_name, pos)
{
	name = obj_name;
	position = pos;
}

void befry::Dot::draw()
{
	Renderer::drawSymbol(position, "██");
}

