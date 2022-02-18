#pragma once
#include "3DObjects.h"
#include "Ray.h"

class IntersectionChecker{
	public:
		bool checkIntersection(Ray ray, Sphere sphere, Vec3* out, float* dist);
		bool checkIntersection(Ray ray, Plane plane, Vec3* out, float* dist);
		bool checkIntersection(Ray ray, Triangle triangle, Vec3* out, float* dist);
};

