#pragma once
#include "Vec3.h"

class Light{
	public:
		Vec3 position; //< Représente la translation depuis le point d'origine (0,0,0)
		Vec3 color; //< Représente la couleur de la source lumineuse au format RGB
		float intensity;

		Light();
		Light(Vec3 color);
		Light(float intensity);
		Light(Vec3 color, float intensity);
		Light(Vec3 color, Vec3 position);
		Light(Vec3 color, float intensity, Vec3 position);
};

