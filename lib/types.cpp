#include "types.h"

befry::Vector2::Vector2(const int& X, const int& Y): X(X*2), Y(Y) {}

/* Assigment operators */
befry::Vector2& befry::Vector2::operator=(const Vector2& right)
{
    if (this != &right)
    {
        X = right.X*2;
        Y = right.Y;
    }
    return *this;
}

befry::Vector2& befry::Vector2::operator+=(const Vector2& right)
{
    X += right.X;
    Y += right.Y;
    return *this;
}

befry::Vector2& befry::Vector2::operator-=(const Vector2& right)
{
    X -= right.X;
    Y -= right.Y;
    return *this;
}

befry::Vector2& befry::Vector2::operator*=(const int& right)
{
    X *= right;
    Y *= right;
    return *this;
}

befry::Vector2& befry::Vector2::operator*=(const Vector2& right)
{
    X *= right.X;
    Y *= right.Y;
    return *this;
}

befry::Vector2& befry::Vector2::operator/=(const int& right)
{
    X *= right;
    Y *= right;
    return *this;
}

befry::Vector2& befry::Vector2::operator/=(const Vector2& right)
{
    X /= right.X;
    Y /= right.Y;
    return *this;
}

/* Math operators */
befry::Vector2 befry::operator+(Vector2& left, const Vector2& right)
{
    left += right;
    return left;
}

befry::Vector2 befry::operator-(Vector2& left, const Vector2& right)
{
    left -= right;
    return left;
}

befry::Vector2 befry::operator-(Vector2& left)
{
    left *= -1;
    return left;
}

befry::Vector2 befry::operator*(const int& left, Vector2& right)
{
    right *= left;
    return right;
}

befry::Vector2 befry::operator*(Vector2& left, const int& right)
{
    left *= right;
    return left;
}

befry::Vector2 befry::operator*(Vector2& left, const Vector2& right)
{
    left *= right;
    return left;
}

befry::Vector2 befry::operator/(Vector2& left, const int& right)
{
    left /= right;
    return left;
}

befry::Vector2 befry::operator/(Vector2& left, const Vector2& right)
{
    left /= right;
    return left;
}

/* Bool operators */
bool befry::operator==(const Vector2& left, const Vector2& right)
{
    return left.X == right.X && left.Y == right.Y;
}
bool befry::operator!=(const Vector2& left, const Vector2& right)
{
    return !(left == right);
}