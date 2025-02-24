#ifndef SCENE_H
#define SCENE_H

#include <vector>

/* Befry Engine includes */
#include "types.h"
#include "game_object.h"

namespace befry
{
	class Scene
	{
	protected:
		Vector2 size;
		// std::vector<GameObject> children;

	public:
		explicit Scene(Vector2 size);
		~Scene();

		void render();
	};
}

#endif
