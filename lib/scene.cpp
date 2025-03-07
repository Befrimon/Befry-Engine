#include "scene.h"

#include "renderer.h"

#include <iostream>
#include <termios.h>
#include <unistd.h>

bgf::Scene::Scene(const Vector2& size): size(size)
{
	termios oldt;
	tcgetattr(STDIN_FILENO, &oldt);
	termios newt = oldt;
	newt.c_lflag &= ~ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	system("stty raw");
	std::cout << "\e[?25l";
	redraw();
}
bgf::Scene::~Scene() = default;

void bgf::Scene::render() const
{
	Renderer::drawRect({0, 0}, size, false, true);
	for (const std::pair<std::string, std::shared_ptr<GameObject>> child : children)
		child.second->draw();
	std::cout << "\033[" << size.Y+2 << ";" << size.X+2 << "f";
}

void bgf::Scene::redraw() const
{
	Renderer::clearScreen();
	Renderer::drawRect({0, 0}, size, false, true);
}

void bgf::Scene::close() const
{
	system("stty cooked");
	std::cout << "\e[?25h";
}

bgf::Vector2 bgf::Scene::get_size() const
{
	return size;
}
