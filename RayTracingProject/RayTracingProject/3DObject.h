#pragma once
#include "Vec3.h"
#include "Material.h"

class C3DObject{
	public:
		Vec3 position; //< Repr�sente la position de l'object � partir du point d'origine (0,0,0)
		
		C3DObject();
		C3DObject(Vec3 position);

		C3DObject* setMaterial(Material* mat);
		C3DObject* removeMaterial();

	protected:
		Material* material;
};

