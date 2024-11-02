#pragma once

#include "Utility.h"

class Camera
{
public:
	Camera()
	{
		const float aspect_ratio = 16.0f / 9.0f;
		const float viewport_height = 2.0f;
		const float viewport_width = viewport_height * aspect_ratio;
		const float focal_length = 1.0f;

		origin = Point3f(0.0f, 0.0f, 0.0f);
		horizontal = Vec3f(viewport_width, 0.0f, 0.0f);
		vertical = Vec3f(0.0f, viewport_height, 0.0f);
		lower_left_corner = origin - (horizontal / 2.0f) - (vertical / 2.0f) - Vec3f(0.0f, 0.0f, focal_length);
	}

	Ray get_ray(float u, float v) const
	{
		return Ray(origin, lower_left_corner + u * horizontal + v * vertical - origin);
	}

private:
	Point3f origin;
	Vec3f horizontal;
	Vec3f vertical;
	Point3f lower_left_corner;
};
