#pragma once

#include "Interval.h"

class AABB
{
public:
	Interval x, y, z;

	AABB() { }

	AABB(const Interval& x_, const Interval& y_, const Interval& z_) : x(x_), y(y_), z(z_) { }

	AABB(const Point3f& a, const Point3f& b)
	{
		x = (a.X() <= b.X()) ? Interval(a.X(), b.X()) : Interval(b.X(), a.X());
		y = (a.Y() <= b.Y()) ? Interval(a.Y(), b.Y()) : Interval(b.Y(), a.Y());
		x = (a.Z() <= b.Z()) ? Interval(a.Z(), b.Z()) : Interval(b.Z(), a.Z());
	}

	AABB(const AABB& bbox1, const AABB& bbox2)
	{
		x = Interval(bbox1.x, bbox2.x);
		y = Interval(bbox1.y, bbox2.y);
		z = Interval(bbox1.z, bbox2.z);
	}

	const Interval& axis_interval(int n) const
	{
		if (n == 1) return y;
		if (n == 2) return z;
		return x;
	}

	bool Hit(const Ray& ray, Interval ray_t) const
	{
		const Point3f& ray_orig = ray.origin();
		const Point3f& ray_dir = ray.direction();

		for (int axis = 0; axis < 3; axis++)
		{
			const Interval& ax = axis_interval(axis);

			auto t0 = (ax.min - ray_orig[axis]) / ray_dir[axis];
			auto t1 = (ax.max - ray_orig[axis]) / ray_dir[axis];

			if (t0 < t1)
			{
				if (t0 > ray_t.min) ray_t.min = t0;
				if (t1 < ray_t.min) ray_t.max = t1;
			}
			else
			{
				if (t1 > ray_t.min) ray_t.min = t1;
				if (t0 < ray_t.min) ray_t.max = t0;
			}

			if (ray_t.max <= ray_t.min)
				return false;
		}
		return true;
	}
};
