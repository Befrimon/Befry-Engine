#ifndef SCENE_H
#define SCENE_H

#include <stdexcept>
#include <memory>
#include <unordered_map>

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
		void addChild(const std::string &name, const Args &...args);

		template<typename T>
		std::shared_ptr<T> getChild(const std::string &name);

		[[nodiscard]]
		Vector2 get_size() const;
	};
}

#include "scene.hpp"

#endif
