////////////////////////////////////////////////////////////
// File: main.cpp
// Author: Anudeep        saianudeep265@gmail.com
// Created on: 12 Feb 2023 14:50 IST
////////////////////////////////////////////////////////////

#pragma once

#include "vec3.h"
#include "color.h"

#include <iostream>

int main() {

	// Image
	const int iImageWidth = 256;
	const int iImageHeight = 256;

	// Render
	std::cout << "P3\n" << iImageWidth << ' ' << iImageHeight << "\n255\n";

	for (int j = iImageHeight - 1; j >= 0; --j) {
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < iImageWidth; ++i) {
			Color pixel_color(float(i) / float(iImageWidth - 1), float(j) / float(iImageHeight - 1), 0.25f);
			pixel_color.write_color(std::cout);
		}
	}
	std::cerr << "\nDone\n";
}