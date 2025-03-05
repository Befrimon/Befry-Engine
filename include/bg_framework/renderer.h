#ifndef RENDERER_H
#define RENDERER_H

#include <unordered_map>
#include <memory>
#include <string>

/* Befry Engine includes */
#include "types/vector2.h"
#include "scene.h"

namespace bgf
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

		static std::unordered_map<std::string, std::shared_ptr<Scene>> scenes;
		static std::string current_scene;

	public:
		static void clearScreen();
		static void drawSymbols(const Vector2 &position, const char &symbol);
		static void drawSymbols(const Vector2 &position, const std::string &synbols);
		static void drawRect(const Vector2 &position, const Vector2 &size, const bool &filled);

		static void setFGColor(const COLORS &color);
		static void setBGColor(const COLORS &color);

		static std::shared_ptr<Scene> addScene(const std::string &name, const Vector2 &size);
		static std::shared_ptr<Scene> changeScene(const std::string &name);
		static std::shared_ptr<Scene> getCurrentScene();
		static void drawScene();
	};
}

#endif
