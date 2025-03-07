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

void bgf::Renderer::drawSymbols(const Vector2 &position, const char &symbol, const bool &ignore_scene)
{
	if (!ignore_scene)
		if (
			const Vector2 scene_size = scenes[current_scene]->get_size();
			position.X <= 1	|| position.Y <= 1 || position.X >= scene_size.X+2 || position.Y >= scene_size.Y+2
		) return;
	std::cout
		<< "\033[" << position.Y << ";" << position.X << "f"
		<< "\033[0;" << 30 + fg_color << ";" << 40 + bg_color << "m"
		<< symbol << "\033[0m";
}

void bgf::Renderer::drawSymbols(const Vector2 &position, const std::string &symbols, const bool &ignore_scene)
{
	Vector2 scene_size{0, 0};
	if (!ignore_scene) scene_size = getCurrentScene()->get_size();
	if (
		!ignore_scene &&
		(position.Y <= 1 || position.Y >= scene_size.Y+2 ||
		position.X+symbols.length() <= 1 || position.X >= scene_size.X+2)
	) return;
	if (!ignore_scene && position.X <= 1)
		std::cout
			<< "\033[" << position.Y << ";2f"
			<< "\033[0;" << 30 + fg_color << ";" << 40 + bg_color << "m"
			<< symbols.substr(2-position.X, symbols.length()+position.X-2) << "\033[0m";
	else if (!ignore_scene && position.X + symbols.length() >= scene_size.X+2)
		std::cout
			<< "\033[" << position.Y << ";" << position.X << "f"
			<< "\033[0;" << 30 + fg_color << ";" << 40 + bg_color << "m"
			<< symbols.substr(0, scene_size.X+2 - position.X) << "\033[0m";
	else
		std::cout
			<< "\033[" << position.Y << ";" << position.X << "f"
			<< "\033[0;" << 30 + fg_color << ";" << 40 + bg_color << "m"
			<< symbols << "\033[0m";

}

void bgf::Renderer::drawRect(const Vector2 &position, const Vector2 &size, const bool &filled, const bool &ignore_scene)
{
	std::vector<std::string> symbols;
	if (filled) symbols = {"▗", "▝", "▖", "▘", "▐", "▌", "▄", "▀", "█"};
	else symbols = {"┏", "┗", "┓", "┛", "┃", "┃", "━", "━"};

	for (int y = 1; y <= size.Y+2; y++)
		for (int x = 1; x <= size.X+2; x++)
			if (x == 1 && y == 1) drawSymbols(position + Vector2{x, y}, symbols[0], ignore_scene);
			else if (x == 1 && y == size.Y+2) drawSymbols(position + Vector2{x, y}, symbols[1], ignore_scene);
			else if (x == size.X+2 && y == 1) drawSymbols(position + Vector2{x, y}, symbols[2], ignore_scene);
			else if (x == size.X+2 && y == size.Y+2) drawSymbols(position + Vector2{x, y}, symbols[3], ignore_scene);
			else if (x == 1) drawSymbols(position + Vector2{x, y}, symbols[4], ignore_scene);
			else if (x == size.X+2) drawSymbols(position + Vector2{x, y}, symbols[5], ignore_scene);
			else if (y == 1) drawSymbols(position + Vector2{x, y}, symbols[6], ignore_scene);
			else if (y == size.Y+2) drawSymbols(position + Vector2{x, y}, symbols[7], ignore_scene);
			else if (filled) drawSymbols(position + Vector2{x, y}, symbols[8], ignore_scene);
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
	scenes.insert(std::make_pair<std::string, std::shared_ptr<Scene>>(name.data(), std::make_shared<Scene>(size)));
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
