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
		Vector2 position;

	public:
		GameObject(const Vector2& pos): position(pos) {}
		virtual ~GameObject() = default;

		virtual void draw() = 0;
	};
}

#endif
