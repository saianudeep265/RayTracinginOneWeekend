////////////////////////////////////////////////////////////
// File: color.h
// Author: Anudeep        saianudeep265@gmail.com
// Created on: 12 Feb 2023 19:05 IST
////////////////////////////////////////////////////////////

#pragma once

#include <iostream>

#include "vec3.h"

typedef Vec3<float> Color;

void write_color(std::ostream& out, const Color& v, int samples_per_pixel) {
	auto r = v.X() / samples_per_pixel;
	auto g = v.Y() / samples_per_pixel;
	auto b = v.Z() / samples_per_pixel;

	out << static_cast<int>(256 * clamp(r, 0.0f, 0.999f)) << ' '
		<< static_cast<int>(256 * clamp(g, 0.0f, 0.999f)) << ' '
		<< static_cast<int>(256 * clamp(b, 0.0f, 0.999f)) << '\n';
}
