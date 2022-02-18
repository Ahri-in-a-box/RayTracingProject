#pragma once
#include "3DObject.h"

class Plane : public C3DObject{
	public:
		Vec3 base[2]; //< Repr�sente la base du plan (espace 2D)
		float x, y; //< Repr�sente la taille du plan selon ses vecteurs g�n�rateur

		Plane();
		Plane(float x, float y);
		Plane(Vec3 position, float x, float y);
		Plane(float x, float y, Vec3 base[2]);
		Plane(float x, float y, Vec3 base1, Vec3 base2);
		Plane(Vec3 position, float x, float y, Vec3 base[2]);
		Plane(Vec3 position, float x, float y, Vec3 base1, Vec3 base2);
};

