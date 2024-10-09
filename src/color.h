////////////////////////////////////////////////////////////
// File: color.h
// Author: Anudeep        saianudeep265@gmail.com
// Created on: 12 Feb 2023 19:05 IST
////////////////////////////////////////////////////////////

#pragma once

#include <iostream>

#include "vec3.h"

typedef Vec3<float> Color;

void write_color(std::ostream& out, const Color& v) {
	out << static_cast<int>(255.999 * v.X()) << ' '
		<< static_cast<int>(255.999 * v.Y()) << ' '
		<< static_cast<int>(255.999 * v.Z()) << '\n';
}
