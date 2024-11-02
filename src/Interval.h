#pragma once

#include "Utility.h"

struct Interval
{
	Interval(): min(static_cast<float>(+infinity)), max(static_cast<float>(-infinity))
	{ }

	Interval(float min_, float max_) : min(min_), max(max_)
	{ }

	Interval(const Interval& it1, const Interval& it2)
	{
		min = it1.min <= it2.min ? it1.min : it2.min;
		max = it1.max >= it2.max ? it1.max : it2.max;
	}

	float size() const
	{
		return max - min;
	}

	bool contains(float x)
	{
		return min <= x && x <= max;
	}

	bool surrounds(float x)
	{
		return min < x && x < max;
	}

	Interval expand(float delta) const
	{
		auto padding = delta / 2;
		return Interval(min - padding, max + padding);
	}

	float min, max;

	static const Interval empty, universe;
};

const Interval Interval::empty = Interval(+infinity, -infinity);
const Interval Interval::universe = Interval(-infinity, +infinity);
