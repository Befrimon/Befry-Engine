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
			PURPLE, CYAN, GRAY, _TODO_, DEFAULT
		};

	protected:
		static COLORS fg_color;
		static COLORS bg_color;

	public:
		static void clearScreen();
		static void drawSymbol(Vector2 pos, std::string_view sym);
		static void drawRect(Vector2 pos, Vector2 size, bool filled);

		static void setFGColor(const COLORS& color);
		static void setBGColor(const COLORS& color);
	};
}

#endif
