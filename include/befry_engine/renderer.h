#ifndef RENDERER_H
#define RENDERER_H

#include <string_view>

/* Befry Engine includes */
#include "types.h"

namespace befry
{
	class Renderer
	{
	public:
		enum COLORS
		{
			BLACK, RED, GREEN, YELLOW, BLUE,
			PURPLE, CYAN, GRAY, __TODO, DEFAULT
		};

	protected:
		static COLORS fg_color;
		static COLORS bg_color;

	public:
		static void clearScreen();
		static void drawSymbol(const Vector2& pos, std::string_view sym);
		static void drawRect(const Vector2& pos, const Vector2& size, const bool& filled);

		static void setFGColor(const COLORS& color);
		static void setBGColor(const COLORS& color);
	};
}

#endif
