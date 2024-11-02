#pragma once

#include "Ray.h"
#include "AABB.h"

struct Interval;

struct HitRecord
{
	Point3f p;
	Vec3f normal;
	float t;
	bool front_face;

	// Sets the hit record normal vector.
	// NOTE: the parameter `outward_normal` is assumed to have unit length.
	void set_face_normal(const Ray& r, const Vec3f& outward_normal)
	{
		front_face = dot(r.direction(), outward_normal) < 0;
		normal = front_face ? outward_normal : -outward_normal;
	}
};

class Hittable
{
public:
	virtual ~Hittable() = default;

	virtual bool Hit(const Ray& ray, Interval ray_t, HitRecord& hitRecord) const = 0;

	virtual AABB Bounding_box() const = 0;
};
