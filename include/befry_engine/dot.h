#ifndef DOT_H
#define DOT_H

#include "game_object.h"

namespace befry
{
	class Dot : public GameObject
	{
	public:
		Dot(Vector2 pos);
		~Dot() override;

		void draw() override;
		void move(Vector2 delta);
	};
}

#endif
