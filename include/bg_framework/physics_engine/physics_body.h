#ifndef PHYSICS_BODY_H
#define PHYSICS_BODY_H

#include "../game_objects/game_object.h"
#include "collision_shape.h"

namespace bgf
{
	class PhysicsBody : public GameObject
	{
	protected:
		CollisionShape shape;
		int gravity_scale = 1;
		float mass = 1;

	public:
		explicit PhysicsBody(const Vector2& position, CollisionShape shape);
		~PhysicsBody() override;

		void draw() const override;
		virtual void move(const Vector2 &delta) = 0;

		[[nodiscard]]
		Vector2 get_gravity() const;
		[[nodiscard]]
		CollisionShape get_shape() const;
	};
}

#endif
