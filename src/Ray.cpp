////////////////////////////////////////////////////////////
// File: Ray.cpp
// Author: Anudeep        saianudeep265@gmail.com
// Created on: 16 Feb 2023 19:10 IST
////////////////////////////////////////////////////////////

#include "Ray.h"

Ray::Ray(const Vec3f& origin, const Vec3f& direction) : m_origin(origin), m_direction(direction) { }

Vec3f Ray::origin() const {
	return m_origin;
}

Vec3f Ray::direction() const {
	return m_direction;
}

Vec3f Ray::at(float t) const {
	return m_origin + (t * m_direction);
}
