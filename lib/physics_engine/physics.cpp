#include "physics_engine/physics.h"

std::vector<std::shared_ptr<bgf::PhysicsBody>> bgf::Physics::physics_bodies;

void bgf::Physics::registerBody(const std::shared_ptr<PhysicsBody> &body)
{
	physics_bodies.push_back(body);
}

bool bgf::Physics::isCollide(const PhysicsBody &body1, const PhysicsBody &body2)
{
	const Vector2 position1 = body1.get_position(), size1 = body1.get_shape().size;
	const Vector2 position2 = body2.get_position(), size2 = body1.get_shape().size;
	return
		(position1.X < position2.X && position2.X < position1.X+size1.X &&
			position1.Y < position2.Y && position2.Y < position1.Y+size1.Y) ||
		(position1.X < position2.X+size2.X && position2.X+size2.X < position1.X+size1.X &&
			position1.Y < position2.Y+size2.Y && position2.Y+size2.Y < position1.Y+size1.Y);
}
bool bgf::Physics::isCollide(const PhysicsBody &body)
{
	for (const std::shared_ptr<PhysicsBody> &other : physics_bodies)
		if (isCollide(body, *other)) return true;
	return false;
}
std::shared_ptr<bgf::PhysicsBody> bgf::Physics::whoCollideWith(const PhysicsBody &body)
{
	for (const std::shared_ptr<PhysicsBody> &other : physics_bodies)
		if (isCollide(body, *other)) return other;
	return nullptr;
}