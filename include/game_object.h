#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <string>
#include <string_view>

/* Befry Engine includes */
#include "types.h"

namespace befry
{
	class GameObject
	{
	protected:
		std::string name;
		Vector2 position;

	public:
		GameObject(std::string_view obj_name, Vector2 pos);
		virtual ~GameObject() = default;

		virtual void draw();
	};
}

#endif
