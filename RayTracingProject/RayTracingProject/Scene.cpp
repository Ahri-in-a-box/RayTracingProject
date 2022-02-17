#include "Scene.h"

Scene::Scene() {
	this->activeCam = nullptr;
}

Scene::~Scene() {
	for (int i = 0; i < this->Objects.size(); i++)
		delete this->Objects[i];
}