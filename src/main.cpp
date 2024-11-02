////////////////////////////////////////////////////////////
// File: main.cpp
// Author: Anudeep        saianudeep265@gmail.com
// Created on: 12 Feb 2023 14:50 IST
////////////////////////////////////////////////////////////

#pragma once

#include "Utility.h"
#include "Hittable.h"
#include "HittableList.h"
#include "Sphere.h"
#include "Camera.h"
#include "Interval.h"

Color ray_color(const Ray& r, const Hittable& world) {
	HitRecord record;
	if (world.Hit(r, Interval(0, infinity), record))
	{
		return 0.5 * (record.normal + Color(1, 1, 1));
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
	const int samples_per_pixel = 100;

	// camera
	Camera camera;

	// World
	HittableList world;

	world.add(std::make_shared<Sphere>(Point3f(0, 0, -1), 0.5));
	world.add(std::make_shared<Sphere>(Point3f(0, -100.5, -1), 100));

	// Render
	std::cout << "P3\n" << iImageWidth << ' ' << iImageHeight << "\n255\n";

	for (int j = iImageHeight - 1; j >= 0; --j) {
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < iImageWidth; ++i) {
			Color pixel_color(0, 0, 0);
			for (int s = 0; s < samples_per_pixel; ++s)
			{
				float u = (i + random_float()) / (iImageWidth - 1);
				float v = (j + random_float()) / (iImageHeight - 1);
				Ray ray = camera.get_ray(u, v);
				pixel_color += ray_color(ray, world);
			}
			write_color(std::cout, pixel_color, samples_per_pixel);
		}
	}
	std::cerr << "\nDone\n";
}
