#include "Sphere.h"

Sphere::Sphere() : C3DObject() {
	this->size = 1;
}

Sphere::Sphere(Vec3 position) : C3DObject(position) {
	this->size = 1;
}

Sphere::Sphere(float size) : C3DObject() {
	if (size < 0.01)
		throw "Size must be above 0.01";
	this->size = size;
}

Sphere::Sphere(Vec3 position, float size) : C3DObject(position) {
	if (size < 0.01)
		throw "Size must be above 0.01";
	this->size = size;
}