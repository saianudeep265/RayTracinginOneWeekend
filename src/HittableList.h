#pragma once

#include <memory>
#include <vector>

#include "Hittable.h"
#include "Interval.h"

class HittableList : public Hittable
{
public:
	HittableList() = default;

	void add(std::shared_ptr<Hittable> object)
	{
		objects.emplace_back(object);
		bbox = AABB(bbox, object->Bounding_box());
	}

	void clear()
	{
		objects.clear();
	}

	bool Hit(const Ray& ray, Interval ray_t, HitRecord& hitRecord) const override
	{
		HitRecord tempHitRecord;
		bool hitAnything(false);
		float closestSoFar(ray_t.max);

		for (const auto& object: objects)
		{
			if (object->Hit(ray, Interval(ray_t.min, closestSoFar), tempHitRecord))
			{
				hitAnything = true;
				closestSoFar = tempHitRecord.t;
				hitRecord = tempHitRecord;
			}
		}

		return hitAnything;
	}

	AABB Bounding_box() const override
	{
		return bbox;
	}

public:
	std::vector<std::shared_ptr<Hittable>> objects;

	AABB bbox;
};
