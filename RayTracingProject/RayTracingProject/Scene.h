#pragma once
#include "Camera.h"
#include "Light.h"
#include "3DObject.h"
#include <vector>

class Scene{
	public:
		Camera* activeCam;
		std::vector<Camera> alternativeCam;
		std::vector<Light> lights;
		std::vector<C3DObject*> Objects; //< Tableau contenant les objets 3D de la scene

		Scene();
		~Scene();
};

