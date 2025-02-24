#include "scene.h"
#include "renderer.h"

befry::Scene::Scene(const Vector2 size): size(size)
{
	Renderer::clearScreen();
	Renderer::drawRect({0, 0}, size, false);
}
befry::Scene::~Scene() = default;

void befry::Scene::render()
{
	//for (GameObject child : children)
	//	child.draw();
}