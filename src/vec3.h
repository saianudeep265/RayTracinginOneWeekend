////////////////////////////////////////////////////////////
// File: vec3.h
// Author: Anudeep        saianudeep265@gmail.com
// Created on: 12 Feb 2023 16:10 IST
////////////////////////////////////////////////////////////

#pragma once

#include <iostream>
#include <cmath>

template<typename T>
class Vec3
{
public:
	Vec3(T x_ = 0, T y_ = 0, T z_ = 0) : x(x_), y(y_), z(z_) {}

	T X() const { return x; }
	T Y() const { return y; }
	T Z() const { return z; }

	inline Vec3<T> operator-() const { return Vec3<T>(-x, -y, -z); }

	inline Vec3<T>& operator+=(const Vec3<T>& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;

		return *this;
	}

	template<typename U>
	inline Vec3<T>& operator*=(U val)
	{
		x *= val;
		y *= val;
		z *= val;

		return *this;
	}

	template<typename U>
	inline Vec3<T>& operator/=(U val)
	{
		return *this *= 1 / val;
	}

	inline T& operator[](int index)
	{
		if (index == 0) return x;
		if (index == 1) return y;
		if (index == 2) return z;
		return x;
	}

	inline T operator[](int index) const
	{
		if (index == 0) return x;
		if (index == 1) return y;
		if (index == 2) return z;
		return x;
	}

	inline auto length() const
	{
		return std::sqrt(getSquaredLength());
	}

	inline T getSquaredLength() const
	{
		return x * x + y * y + z * z;
	}

	inline T dot(const Vec3<T>& v) const
	{
		return x * v.x + y * v.y + z * v.z;
	}

	inline Vec3<T> cross(const Vec3<T>& v) const
	{
		return Vec3<T>(y * v.z - z * v.y,
			z * v.x - x * v.z,
			x * v.y - y * v.x);
	}

protected:
	T x;
	T y;
	T z;
};

typedef Vec3<float> Vec3f;
typedef Vec3<float> Point3f;

template<typename T>
inline Vec3<T> operator+(const Vec3<T>& v1, const Vec3<T>& v2)
{
	return Vec3<T>(v1.X() + v2.X(), v1.Y() + v2.Y(), v1.Z() + v2.Z());
}

template<typename T>
inline Vec3<T> operator-(const Vec3<T>& v1, const Vec3<T>& v2)
{
	return Vec3<T>(v1.X() - v2.X(), v1.Y() - v2.Y(), v1.Z() - v2.Z());
}

template<typename T>
inline Vec3<T> operator*(const Vec3<T>& v1, const Vec3<T>& v2)
{
	return Vec3<T>(v1.X() * v2.X(), v1.Y() * v2.Y(), v1.Z() * v2.Z());
}

template<typename T>
inline Vec3<T> operator/(const Vec3<T>& v1, const Vec3<T>& v2)
{
	return Vec3<T>(v1.X() / v2.X(), v1.Y() / v2.Y(), v1.Z() / v2.Z());
}

template<typename T, typename U>
inline Vec3<T> operator*(const Vec3<T>& v, U val)
{
	return Vec3<T>(v.X() * val, v.Y() * val, v.Z() * val);
}

template<typename T, typename U>
inline Vec3<T> operator/(const Vec3<T>& v, U val)
{
	return v * (1 / val);
}

template<typename T, typename U>
inline Vec3<T> operator*(U val, const Vec3<T>& v)
{
	return v * val;
}

template<typename T, typename U>
inline Vec3<T> operator/(U val, const Vec3<T>& v)
{
	return v * (1 / val);
}

template<typename T>
inline Vec3<T> unit_vector(const Vec3<T>& v) {
	return v / v.length();
}

template<typename T>
inline T dot(const Vec3<T>& v1, const Vec3<T>& v2)
{
	return v1.X() * v2.X() + v1.Y() * v2.Y() + v1.Z() * v2.Z();
}
