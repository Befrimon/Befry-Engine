#ifndef DOT_H
#define DOT_H

#include "game_object.h"

namespace befry
{
	class Dot : public GameObject
	{
	public:
		Dot(std::string_view obj_name, Vector2 pos);
		~Dot() override;

		void draw() override;
	};
}

#endif
