#pragma once
#include "3DObject.h"

class Sphere : public C3DObject{
	public:
		float size; //< Représente le rayon de la sphere

		Sphere();
		Sphere(Vec3 position);
		Sphere(float size);
		Sphere(Vec3 position, float size);
};

