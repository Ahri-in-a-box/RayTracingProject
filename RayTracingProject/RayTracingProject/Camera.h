#pragma once
#include "Vec3.h"

class Camera{
	public:
		Vec3 position; //< D�fini la translation depuis la position (0,0,0)
		Vec3 rotation; //< D�fini la rotation depuis le vecteur directionnel de vue (0,0,-1)
		float fov; //< D�fini l'angle de vision de la cam�ra

		Camera();
		Camera(Vec3 position);
		Camera(Vec3 position, Vec3 rotation);
		Camera(float fov, Vec3 position, Vec3 rotation);
		Camera(float fov);
		Camera(float fov, Vec3 position);
};

