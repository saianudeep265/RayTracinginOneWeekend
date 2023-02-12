////////////////////////////////////////////////////////////
// File: color.h
// Author: Anudeep        saianudeep265@gmail.com
// Created on: 12 Feb 2023 19:05 IST
////////////////////////////////////////////////////////////

#pragma once

#include "vec3.h"

#include <iostream>

class Color : public vec3 {
public:
	Color(float dVecx = 0.0f, float dVecy = 0.0f, float dVecz = 0.0f) : vec3(dVecx , dVecy , dVecz) {}

	void write_color(std::ostream& out) {
		out << static_cast<int>(255.999 * m_dVec3[0]) << ' '
			<< static_cast<int>(255.999 * m_dVec3[1]) << ' '
			<< static_cast<int>(255.999 * m_dVec3[2]) << '\n';
	}
};
