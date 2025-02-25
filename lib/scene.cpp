#include "scene.h"
#include "renderer.h"

#include <iostream>

befry::Scene::Scene(const Vector2& size): size(size)
{
	redraw();
}
befry::Scene::~Scene() = default;

void befry::Scene::render() const
{
	for (const auto& child : children)
		child->draw();
}

void befry::Scene::redraw() const
{
	Renderer::clearScreen();
	Renderer::drawRect({0, 0}, size, false);
}

void befry::Scene::addChild(std::shared_ptr<GameObject> child)
{
	children.push_back(child);
}


