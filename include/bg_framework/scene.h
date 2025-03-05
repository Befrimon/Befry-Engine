#ifndef SCENE_H
#define SCENE_H

#include <memory>
#include <unordered_map>
#include <stdexcept>

/* Befry Engine includes */
#include "types/vector2.h"
#include "game_objects/game_object.h"

namespace bgf
{
	class Scene
	{
	protected:
		Vector2 size;
		std::unordered_map<std::string, std::shared_ptr<GameObject>> children;

	public:
		explicit Scene(const Vector2& size);
		~Scene();

		void render() const;
		void redraw() const;
		void close() const;

		template<typename T, typename... Args>
		void addChild(const std::string &name, Args... args);

		template<typename T>
		std::shared_ptr<T> getChild(const std::string &name);
	};
}

#include "scene.hpp"

#endif
