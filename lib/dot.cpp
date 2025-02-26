#include "dot.h"
#include "renderer.h"

befry::Dot::Dot(Vector2 pos) :GameObject(pos) {}
befry::Dot::~Dot() = default;

void befry::Dot::draw()
{
	Renderer::drawSymbol(position, "██");
}

void befry::Dot::move(Vector2 delta)
{
	Renderer::drawSymbol(position, "  ");
	position += delta;
}


