#ifndef PHYSICS_H
#define PHYSICS_H

#include <vector>
#include <memory>

#include "physics_body.h"

namespace bgf
{
	class Physics
	{
	protected:
		static std::vector<std::shared_ptr<PhysicsBody>> physics_bodies;

	public:
		static void registerBody(const std::shared_ptr<PhysicsBody> &body);

		static bool isCollide(const PhysicsBody &body1, const PhysicsBody &body2);
		static bool isCollide(const PhysicsBody &body);
		static std::shared_ptr<PhysicsBody> whoCollideWith(const PhysicsBody &body);
	};
}

#endif
