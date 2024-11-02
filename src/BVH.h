#pragma once

#include "Hittable.h"
#include "HittableList.h"
#include "AABB.h"

class BVHNode : public Hittable
{
public:
	BVHNode(HittableList hittableList) : BVHNode(hittableList.objects, 0, hittableList.objects.size())
	{

	}

	BVHNode(std::vector<std::shared_ptr<Hittable>>& objects, size_t start, size_t end)
	{
		int axis = random_int(0, 2);

		auto comparator = axis == 0 ? box_x_compare
			: axis == 1 ? box_y_compare
			: box_z_compare;

		size_t object_span = end - start;

		if (object_span == 1)
		{
			left = right = objects[start];
		}
		else if (object_span == 2)
		{
			left = objects[start];
			right = objects[start + 1];
		}
		else
		{
			std::sort(objects.begin() + start, objects.begin() + end, comparator);

			auto mid = start + object_span / 2;
			left = std::make_shared<BVHNode>(objects, start, mid);
			right = std::make_shared<BVHNode>(objects, mid, end);
		}
	}

	bool Hit(const Ray& ray, Interval ray_t, HitRecord& hitRecord) const override
	{
		if (!bbox.Hit(ray, ray_t))
			return;

		bool hitLeft = left->Hit(ray, ray_t, hitRecord);
		bool hitRight = right->Hit(ray, Interval(ray_t.min, hitLeft ? hitRecord.t : ray_t.max), hitRecord);

		return hitLeft || hitRight;
	}

	AABB Bounding_box() const override
	{
		return bbox;
	}

private:
	static bool box_x_compare(const std::shared_ptr<Hittable> a, const std::shared_ptr<Hittable> b)
	{
		auto a_x_interval = a->Bounding_box().x;
		auto b_x_interval = b->Bounding_box().x;
		return a_x_interval.min < b_x_interval.min;
	}

	static bool box_y_compare(const std::shared_ptr<Hittable> a, const std::shared_ptr<Hittable> b)
	{
		auto a_y_interval = a->Bounding_box().y;
		auto b_y_interval = b->Bounding_box().y;
		return a_y_interval.min < b_y_interval.min;
	}

	static bool box_z_compare(const std::shared_ptr<Hittable> a, const std::shared_ptr<Hittable> b)
	{
		auto a_z_interval = a->Bounding_box().z;
		auto b_z_interval = b->Bounding_box().z;
		return a_z_interval.min < b_z_interval.min;
	}

private:
	std::shared_ptr<Hittable> left;
	std::shared_ptr<Hittable> right;
	AABB bbox;
};

