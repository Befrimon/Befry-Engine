#include "types/vector2.h"
#include <cmath>

bgf::Vector2::Vector2(const int& X, const int& Y): X(X), Y(Y) {}

float bgf::Vector2::length() const
{
    return std::sqrtf(std::pow(X, 2) + std::pow(Y, 2));
}


/* Assigment operators */
bgf::Vector2& bgf::Vector2::operator=(const Vector2& right)
{
    if (this != &right)
    {
		X = right.X;
        Y = right.Y;
    }
    return *this;
}

bgf::Vector2& bgf::Vector2::operator+=(const Vector2& right)
{
    X += right.X;
    Y += right.Y;
    return *this;
}

bgf::Vector2& bgf::Vector2::operator-=(const Vector2& right)
{
    X -= right.X;
    Y -= right.Y;
    return *this;
}

bgf::Vector2& bgf::Vector2::operator*=(const int& right)
{
    X *= right;
    Y *= right;
    return *this;
}

bgf::Vector2& bgf::Vector2::operator*=(const Vector2& right)
{
    X *= right.X;
    Y *= right.Y;
    return *this;
}

bgf::Vector2& bgf::Vector2::operator/=(const int& right)
{
    X *= right;
    Y *= right;
    return *this;
}

bgf::Vector2& bgf::Vector2::operator/=(const Vector2& right)
{
    X /= right.X;
    Y /= right.Y;
    return *this;
}

/* Math operators */
bgf::Vector2 bgf::operator+(const Vector2& left, const Vector2& right)
{
	return Vector2{left.X + right.X, left.Y + right.Y};
}

bgf::Vector2 bgf::operator-(const Vector2& left, const Vector2& right)
{
    return Vector2{left.X - right.X, left.Y - right.Y};
}

bgf::Vector2 bgf::operator-(Vector2& left)
{
    left *= -1;
    return left;
}

bgf::Vector2 bgf::operator*(const int& left, Vector2& right)
{
    return Vector2{left * right.X, left * right.Y};
}

bgf::Vector2 bgf::operator*(const Vector2& left, const int& right)
{
    return Vector2{left.X * right, left.Y * right};
}

bgf::Vector2 bgf::operator*(const Vector2& left, const Vector2& right)
{
    return Vector2{left.X * right.X, left.Y * right.Y};
}

bgf::Vector2 bgf::operator/(const Vector2& left, const int& right)
{
    return Vector2{left.X / right, left.Y / right};
}

bgf::Vector2 bgf::operator/(const Vector2& left, const Vector2& right)
{
    return Vector2{left.X / right.X, left.Y / right.Y};
}

/* Bool operators */
bool bgf::operator==(const Vector2& left, const Vector2& right)
{
    return left.X == right.X && left.Y == right.Y;
}
bool bgf::operator!=(const Vector2& left, const Vector2& right)
{
    return !(left == right);
}
