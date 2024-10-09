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

bool hit_sphere(const Vec3f& center, float radius, const Ray& r) {
	auto oc = r.origin() - center;
	auto a = r.direction().dot(r.direction());
	auto b = 2.0f * oc.dot(r.direction());
	auto c = oc.dot(oc) - radius * radius;
	float discriminant = b * b - 4 * a * c;
	return discriminant >= 0;
}

Color ray_color(const Ray& r) {
	if (hit_sphere(Vec3f(0.0f, 0.0f, -1.0f), 0.5, r))
		return Color(1.0f, 0.0f, 0.0f);

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
