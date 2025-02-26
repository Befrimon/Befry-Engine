#include "scene.h"

#include "renderer.h"

#include <iostream>
#include <termios.h>
#include <unistd.h>

befry::Scene::Scene(const Vector2& size): size(size)
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
befry::Scene::~Scene() = default;

void befry::Scene::render() const
{
	for (const auto&[key, child] : children)
		child->draw();
	std::cout << "\033[" << size.Y+2 << ";" << size.X+2 << "f";
}

void befry::Scene::redraw() const
{
	Renderer::clearScreen();
	Renderer::drawRect({0, 0}, size, false);
}
