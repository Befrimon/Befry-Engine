#include "renderer.h"

#include <iostream>
#include <vector>

befry::Renderer::COLORS befry::Renderer::fg_color = DEFAULT;
befry::Renderer::COLORS befry::Renderer::bg_color = DEFAULT;

void befry::Renderer::clearScreen()
{
	std::cout << "\033[0m\033[2J\033[1;1f";
}


void befry::Renderer::drawSymbol(const Vector2& pos, std::string_view sym)
{
	std::cout
		<< "\033[" << pos.Y << ";" << pos.X << "f"
		<< "\033[0;" << 30 + fg_color << ";" << 40 + bg_color << "m"
		<< sym << "\033[0m";
}

void befry::Renderer::drawRect(const Vector2& pos, const Vector2& size, const bool& filled)
{
	std::vector<std::string> symbols;
	if (filled) symbols = {"▗", "▝", "▖", "▘", "▐", "▌", "▄", "▀", "█"};
	else symbols = {"┏", "┗", "┓", "┛", "┃", "┃", "━", "━", " "};

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

void befry::Renderer::setFGColor(const COLORS& color)
{ fg_color = color; }

void befry::Renderer::setBGColor(const COLORS& color)
{ bg_color = color; }

