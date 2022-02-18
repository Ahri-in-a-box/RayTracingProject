#include "3DObject.h"

C3DObject::C3DObject() {
	this->position = Vec3();
	this->material = nullptr;
}

C3DObject::C3DObject(Vec3 position) {
	this->position = position;
	this->material = nullptr;
}

C3DObject* C3DObject::setMaterial(Material* material) {
	if (!material)
		throw "Invalid material";
	this->material = material;
	return this;
}

C3DObject* C3DObject::removeMaterial() {
	this->material = nullptr;
	return this;
}