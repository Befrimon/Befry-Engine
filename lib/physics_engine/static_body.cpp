#include "physics_engine/static_body.h"
#include "physics_engine/physics.h"


bgf::StaticBody::StaticBody(const Vector2 &position, CollisionShape shape)
	:PhysicsBody(position, shape) {}

void bgf::StaticBody::move(const Vector2 &delta)
{
	position += delta;
	auto collide = Physics::whoCollideWith(*this);
}