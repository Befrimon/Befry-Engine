#include "renderer.h"

#include <iostream>
#include <vector>

bgf::Renderer::COLORS bgf::Renderer::fg_color = DEFAULT;
bgf::Renderer::COLORS bgf::Renderer::bg_color = DEFAULT;

std::unordered_map<std::string, std::shared_ptr<bgf::Scene>> bgf::Renderer::scenes;
std::string bgf::Renderer::current_scene;

void bgf::Renderer::clearScreen()
{
	std::cout << "\033[0m\033[2J\033[1;1f";
}

void bgf::Renderer::drawSymbols(const Vector2 &position, const char &symbol)
{
	std::cout
		<< "\033[" << position.Y << ";" << position.X << "f"
		<< "\033[0;" << 30 + fg_color << ";" << 40 + bg_color << "m"
		<< symbol << "\033[0m";
}

void bgf::Renderer::drawSymbols(const Vector2 &position, const std::string &symbols)
{
	std::cout
		<< "\033[" << position.Y << ";" << position.X << "f"
		<< "\033[0;" << 30 + fg_color << ";" << 40 + bg_color << "m"
		<< symbols << "\033[0m";
}

void bgf::Renderer::drawRect(const Vector2 &pos, const Vector2 &size, const bool &filled)
{
	std::vector<std::string> symbols;
	if (filled) symbols = {"▗", "▝", "▖", "▘", "▐", "▌", "▄", "▀", "█"};
	else symbols = {"┏", "┗", "┓", "┛", "┃", "┃", "━", "━", ""};

	for (int y = 1; y <= size.Y+2; y++)
		for (int x = 1; x <= size.X+2; x++)
		{
			std::cout
				<< "\033[" << pos.Y+y << ";" << pos.X+x << "f"
				<< "\033[" << 30 + fg_color << ";" << 40 + bg_color << "m";
			if (x == 1 && y == 1) std::cout << symbols[0];
			else if (x == 1 && y == size.Y+2) std::cout << symbols[1];
			else if (x == size.X+2 && y == 1) std::cout << symbols[2];
			else if (x == size.X+2 && y == size.Y+2) std::cout << symbols[3];
			else if (x == 1) std::cout << symbols[4];
			else if (x == size.X+2) std::cout << symbols[5];
			else if (y == 1) std::cout << symbols[6];
			else if (y == size.Y+2) std::cout << symbols[7];
			else std::cout << symbols[8];
		}
}

void bgf::Renderer::setFGColor(const COLORS &color)
{ 
	fg_color = color; 
}

void bgf::Renderer::setBGColor(const COLORS &color)
{ 
	bg_color = color; 
}

std::shared_ptr<bgf::Scene> bgf::Renderer::addScene(const std::string &name, const Vector2 &size)
{
	if (scenes.find(name) != scenes.end())
		throw std::invalid_argument("Scene with name `" + name + "` already exists!");
	scenes[name] = std::make_shared<Scene>(Scene(size));
	if (current_scene.empty())
		current_scene = name;
	return scenes[name];
}

std::shared_ptr<bgf::Scene> bgf::Renderer::changeScene(const std::string &name)
{
	if (scenes.find(name) == scenes.end())
		throw std::invalid_argument("Scene with name `" + name + "` not found!");
	current_scene = name;
	return scenes[name];
}

std::shared_ptr<bgf::Scene> bgf::Renderer::getCurrentScene()
{
	return scenes[current_scene];
}

void bgf::Renderer::drawScene()
{

}

