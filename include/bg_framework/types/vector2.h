#ifndef TYPES_H
#define TYPES_H

namespace bgf
{
	struct Vector2
	{
		int X;
		int Y;
		bool doubledx;

		Vector2(const int &X, const int &Y);
		[[nodiscard]]
		float length() const;

		/* Assigment operators */
		Vector2 &operator=(const Vector2 &right);
		Vector2 &operator+=(const Vector2 &right);
		Vector2 &operator-=(const Vector2 &right);
		Vector2 &operator*=(const Vector2 &right);
		Vector2 &operator*=(const int &right);
		Vector2 &operator/=(const Vector2 &right);
		Vector2 &operator/=(const int &right);
	};

	/* Vector2 math operators */
	Vector2 operator+(const Vector2 &left, const Vector2 &right);
	Vector2 operator-(const Vector2 &left, const Vector2 &right);
	Vector2 operator-(Vector2 &left);
	Vector2 operator*(const int &left, Vector2 &right);
	Vector2 operator*(const Vector2 &left, const int &right);
	Vector2 operator*(const Vector2 &left, const Vector2 &right);
	Vector2 operator/(const Vector2 &left, const int &right);
	Vector2 operator/(const Vector2 &left, const Vector2 &right);

	/* Vector2 bool operators */
	bool operator==(const Vector2 &left, const Vector2 &right);
	bool operator!=(const Vector2 &left, const Vector2 &right);
}

#endif
