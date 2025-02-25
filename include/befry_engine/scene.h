#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <memory>

/* Befry Engine includes */
#include "types.h"
#include "game_object.h"

namespace befry
{
	class Scene
	{
	protected:
		Vector2 size;
		std::vector<std::shared_ptr<GameObject>> children;

	public:
		explicit Scene(const Vector2& size);
		~Scene();

		void render() const;
		void redraw() const;

		void addChild(std::shared_ptr<GameObject> child);
	};
}

#endif
