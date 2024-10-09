////////////////////////////////////////////////////////////
// File: main.cpp
// Author: Anudeep        saianudeep265@gmail.com
// Created on: 12 Feb 2023 14:50 IST
////////////////////////////////////////////////////////////

#pragma once

#include "vec3.h"
#include "color.h"
#include "Ray.h"

#include <iostream>

float hit_sphere(const Vec3f& center, float radius, const Ray& r) {
	float t(-1.0f);
	auto oc = center - r.origin();
	auto a = r.direction().getSquaredLength();
	auto h = oc.dot(r.direction());
	auto c = oc.getSquaredLength() - radius * radius;
	float discriminant = h * h - a * c;
	if (!(discriminant < 0.0f))
	{
		t = (h - std::sqrtf(discriminant)) / a;
	}
	return t;
}

Color ray_color(const Ray& r) {
	auto t = hit_sphere(Vec3f(0.0f, 0.0f, -1.0f), 0.5, r);
	if (t > 0.0f)
	{
		auto n = unit_vector(r.at(t) - Vec3f(0.0f, 0.0f, -1.0f));
		return 0.5f * Color(n.X() + 1.0f, n.Y() + 1.0f, n.Z() + 1.0f);
	}

	Vec3f unit_direction = unit_vector(r.direction());
	auto a = 0.5f * (unit_direction.Y() + 1.0f);
	return (1.0f - a) * Color(1.0f, 1.0f, 1.0f) + a * Color(0.5f, 0.7f, 1.0f);
}

int main() {

	// Image
	const float aspect_ratio = 16.0f / 9.0f;
	const int iImageHeight = 400;
	const int iImageWidth = static_cast<int>(iImageHeight * aspect_ratio);

	// camera
	const float viewport_height = 2.0f;
	const float viewport_width = viewport_height * aspect_ratio;
	const float focal_length = 1.0f;

	const Vec3f origin(0.0f, 0.0f, 0.0f);
	const Vec3f horizontal(viewport_width, 0.0f, 0.0f);
	const Vec3f vertical(0.0f, viewport_height, 0.0f);
	const Vec3f lower_left_corner = origin - (horizontal / 2.0f) - (vertical / 2.0f) - Vec3f(0.0f, 0.0f, focal_length);

	// Render
	std::cout << "P3\n" << iImageWidth << ' ' << iImageHeight << "\n255\n";

	for (int j = iImageHeight - 1; j >= 0; --j) {
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < iImageWidth; ++i) {
			float u = float(i) / float(iImageWidth - 1);
			float v = float(j) / float(iImageHeight - 1);
			Ray ray(origin, lower_left_corner + u * horizontal + v * vertical - origin);
			write_color(std::cout, ray_color(ray));
		}
	}
	std::cerr << "\nDone\n";
}
