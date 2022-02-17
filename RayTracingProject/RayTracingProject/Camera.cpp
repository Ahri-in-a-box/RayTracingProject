#include "Camera.h"

Camera::Camera() {
	this->position = this->rotation = Vec3();
	this->fov = 68;
}

Camera::Camera(Vec3 position) {
	this->position = position;
	this->rotation = Vec3();
	this->fov = 68;
}

Camera::Camera(Vec3 position, Vec3 rotation) {
	this->position = position;
	this->rotation = rotation;
	this->fov = 68;
}

Camera::Camera(float fov, Vec3 position, Vec3 rotation) {
	if (fov < 50 || fov > 120)
		throw "FOV must be between 50 and 120";

	this->position = position;
	this->rotation = rotation;
	this->fov = fov;
}

Camera::Camera(float fov) {
	if (fov < 50 || fov > 120)
		throw "FOV must be between 50 and 120";

	this->position = this->rotation = Vec3();
	this->fov = fov;
}

Camera::Camera(float fov, Vec3 position) {
	if (fov < 50 || fov > 120)
		throw "FOV must be between 50 and 120";

	this->position = position;
	this->rotation = Vec3();
	this->fov = fov;
}