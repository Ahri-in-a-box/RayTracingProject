#pragma once
#include "Vec3.h"

class Material{
	public:
		Vec3 color;
		float ambiance, diffuse, specular;

		Material();
		Material(Vec3 color);
		Material(float ambiance, float diffuse, float specular);
		Material(Vec3 color, float ambiance, float diffuse, float specular);
};

