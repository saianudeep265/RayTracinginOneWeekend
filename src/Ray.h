////////////////////////////////////////////////////////////
// File: Ray.h
// Author: Anudeep        saianudeep265@gmail.com
// Created on: 14 Feb 2023 17:45 IST
////////////////////////////////////////////////////////////

#pragma once

#include "vec3.h"

class Ray {
public:
	Ray() = default;
	Ray(const Vec3f& origin, const Vec3f& direction);

	virtual ~Ray() = default;

	Vec3f origin() const;
	Vec3f direction() const;
	Vec3f at(float t) const;

private:
	Vec3f m_origin;
	Vec3f m_direction;
};
