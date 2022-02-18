#pragma once
#include "3DObject.h"

class Triangle : public C3DObject {
	public:
		Vec3 points[3];

		Triangle();
		Triangle(float radius);
		Triangle(Vec3 position, float radius);
		Triangle(Vec3 points[3]);
		Triangle(Vec3 point1, Vec3 point2, Vec3 point3);
};

