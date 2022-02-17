#pragma once
#include "Vec3.h"

class Camera{
	public:
		Vec3 position; //< Défini la translation depuis la position (0,0,0)
		Vec3 rotation; //< Défini la rotation depuis le vecteur directionnel de vue (0,0,-1)
		float fov; //< Défini l'angle de vision de la caméra

		Camera();
		Camera(Vec3 position);
		Camera(Vec3 position, Vec3 rotation);
		Camera(float fov, Vec3 position, Vec3 rotation);
		Camera(float fov);
		Camera(float fov, Vec3 position);
};

