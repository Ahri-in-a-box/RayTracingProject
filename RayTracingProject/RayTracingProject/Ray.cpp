#include "Ray.h"

Ray::Ray(Vec3 direction) {
	this->direction = direction;
	this->origin = Vec3();
}

Ray::Ray(Vec3 direction, Vec3 origin) {
	this->direction = direction;
	this->origin = origin;
}