#pragma once
#include "Vec3.h"
#include "Material.h"

class C3DObject{
	public:
		Vec3 position; //< Représente la position de l'object à partir du point d'origine (0,0,0)
		
		C3DObject();
		C3DObject(Vec3 position);
		virtual ~C3DObject();

		C3DObject* setMaterial(Material* mat);
		C3DObject* removeMaterial();
		Material getMaterial();

	protected:
		Material* material;
};

