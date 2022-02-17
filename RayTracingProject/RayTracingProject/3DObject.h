#pragma once
#include "Vec3.h"
#include "Material.h"

class C3DObject{
	public:
		Vec3 position; //< Représente la position de l'object à partir du point d'origine (0,0,0)
		Material* material;

		C3DObject();
		C3DObject(Vec3 position);
};

