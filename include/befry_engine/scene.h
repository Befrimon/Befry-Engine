#ifndef SCENE_H
#define SCENE_H

#include <memory>
#include <unordered_map>
#include <stdexcept>

/* Befry Engine includes */
#include "types.h"
#include "game_object.h"

namespace befry
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

		template<typename T, typename... Args>
		void addChild(std::string name, Args... args)
		{
			if (children.find(name) != children.end())
				throw std::invalid_argument("Children with name `" + name + "` already exists in this scene!");
			children[name] = std::make_shared<T>(args...);
		}

		template<typename T>
		std::shared_ptr<T> getChild(std::string name)
		{
			return std::static_pointer_cast<T>(children[name]);
		}
	};
}

#endif
