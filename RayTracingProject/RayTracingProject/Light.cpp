#include "Light.h"

Light::Light() {
	this->color = Vec3(255, 255, 255);
	this->intensity = 1;
	this->position = Vec3();
}

Light::Light(Vec3 color) {
	if (color.x < 0 || color.x > 255 || color.y < 0 || color.y > 255 || color.z < 0 || color.z > 255)
		throw "Colors should be between 0 and 255";

	this->color = color;
	this->intensity = 1;
	this->position = Vec3();
}

Light::Light(float intensity) {
	if (intensity < 0 || intensity > 1)
		throw "Intensity should be between 0 and 1";

	this->color = Vec3(255, 255, 255);
	this->intensity = intensity;
	this->position = Vec3();
}

Light::Light(Vec3 color, float intensity) {
	if (color.x < 0 || color.x > 255 || color.y < 0 || color.y > 255 || color.z < 0 || color.z > 255)
		throw "Colors should be between 0 and 255";
	if (intensity < 0 || intensity > 1)
		throw "Intensity should be between 0 and 1";

	this->color = color;
	this->intensity = intensity;
	this->position = Vec3();
}

Light::Light(Vec3 color, Vec3 position) {
	if (color.x < 0 || color.x > 255 || color.y < 0 || color.y > 255 || color.z < 0 || color.z > 255)
		throw "Colors should be between 0 and 255";

	this->color = color;
	this->intensity = 1;
	this->position = position;
}

Light::Light(Vec3 color, float intensity, Vec3 position) {
	if (color.x < 0 || color.x > 255 || color.y < 0 || color.y > 255 || color.z < 0 || color.z > 255)
		throw "Colors should be between 0 and 255";
	if (intensity < 0 || intensity > 1)
		throw "Intensity should be between 0 and 1";

	this->color = color;
	this->intensity = intensity;
	this->position = position;
}