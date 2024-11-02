#pragma once

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>
#include <random>

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

template<typename T>
inline T degrees_to_radians(T degrees) {
    return static_cast<T>(degrees * pi / 180.0);
}

// Returns a random real number in [0, 1)
inline float random_float()
{
    static std::uniform_real_distribution<float> distribution(0.0f, 1.0f);
    static std::mt19937 generator;
    return distribution(generator);
}

// Returns a random real number in [min, max)
inline float random_float(float min, float max)
{
    return min + (max - min) * random_float();
}

// Returns a random integer number in [min, max]
inline int random_int(int min, int max)
{
    return int(random_float(min, max + 1));
}

inline float clamp(float x, float min, float max)
{
    if (x < min) return min;
    if (x > max) return max;
    return x;
}

#include "color.h"
#include "ray.h"
#include "vec3.h"
