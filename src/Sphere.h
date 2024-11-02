#pragma once

#include <cmath>

#include "Hittable.h"
#include "vec3.h"

class Sphere : public Hittable
{
public:
	Sphere(const Point3f& center_, float radius_) : center(center_), radius(radius_)
	{
		auto rvec = Vec3f(radius, radius, radius);
		bbox = AABB(center - rvec, center + rvec);
	}

	bool Hit(const Ray& r, Interval ray_t, HitRecord& hitRecord) const override
	{
		auto oc = center - r.origin();
		auto a = r.direction().getSquaredLength();
		auto h = oc.dot(r.direction());
		auto c = oc.getSquaredLength() - radius * radius;

		float discriminant = h * h - a * c;

		if (discriminant < 0)
			return false;

		auto sqrtDiscriminant = std::sqrtf(discriminant);

		// Find the nearest root that lies in the acceptable range
		auto root = (h - sqrtDiscriminant) / a;
		if (root <= ray_t.min || root >= ray_t.max)
		{
			root = (h + sqrtDiscriminant) / a;
			if (root <= ray_t.min || root >= ray_t.max)
				return false;
		}

		hitRecord.t = root;
		hitRecord.p = r.at(root);
		auto outward_normal = (hitRecord.p - center) / radius;
		hitRecord.set_face_normal(r, outward_normal);
		
		return true;
	}

	AABB Bounding_box() const override
	{

	}

private:
	Point3f center;
	float radius;
	AABB bbox;
};
