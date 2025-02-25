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
		GameObject(std::string_view obj_name, const Vector2& pos): name(obj_name), position(pos) {}
		virtual ~GameObject() = default;

		virtual void draw() = 0;
	};
}

#endif
