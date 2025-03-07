#ifndef STATIC_BODY_H
#define STATIC_BODY_H

#include "physics_body.h"

namespace bgf
{
	class StaticBody : public PhysicsBody
	{
	public:
		explicit StaticBody(const Vector2 &position, CollisionShape shape);

		void move(const Vector2 &delta) override;
	};
}

#endif
