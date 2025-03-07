#include "physics_engine/physics_body.h"
#include "physics_engine/physics.h"

#include <memory>
#include <utility>

bgf::PhysicsBody::PhysicsBody(const Vector2 &position, CollisionShape shape)
	:GameObject(position), shape(std::move(shape))
{
	Physics::registerBody(std::shared_ptr<PhysicsBody>(this));
}
bgf::PhysicsBody::~PhysicsBody() = default;

void bgf::PhysicsBody::draw() const { /* It's just physics object, heh */ }

bgf::Vector2 bgf::PhysicsBody::get_gravity() const
{
	return Vector2{0, gravity_scale};
}
bgf::CollisionShape bgf::PhysicsBody::get_shape() const
{
	return shape;
}

