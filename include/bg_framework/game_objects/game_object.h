#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

/* Befry Engine includes */
#include "../types/vector2.h"

namespace bgf
{
	class GameObject
	{
	protected:
		Vector2 position;

	public:
		explicit GameObject(const Vector2& position): position(position) {}
		virtual ~GameObject() = default;

		virtual void draw() = 0;
	};
}

#endif
