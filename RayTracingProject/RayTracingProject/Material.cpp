#include "Material.h"

Material::Material() {
	this->color = Vec3(255, 255, 255);
	this->ambiance = 0.2;
	this->diffuse = 0.5;
	this->specular = 0.3;
}

Material::Material(Vec3 color) {
	if (color.x < 0 || color.x > 255 || color.y < 0 || color.y > 255 || color.z < 0 || color.z > 255)
		throw "Colors should be between 0 and 255";

	this->color = color;
	this->ambiance = 0.2;
	this->diffuse = 0.5;
	this->specular = 0.3;
}

Material::Material(float ambiance, float diffuse, float specular) {
	if (ambiance > 1 || ambiance < 0)
		throw "Ambiance should be between 0 and 1";
	if (diffuse > 1 || diffuse < 0)
		throw "Diffuse should be between 0 and 1";
	if (specular > 1 || specular < 0)
		throw "Specular should be between 0 and 1";

	this->color = Vec3(255, 255, 255);
	this->ambiance = ambiance;
	this->diffuse = diffuse;
	this->specular = specular;
}

Material::Material(Vec3 color, float ambiance, float diffuse, float specular) {
	if (color.x < 0 || color.x > 255 || color.y < 0 || color.y > 255 || color.z < 0 || color.z > 255)
		throw "Colors should be between 0 and 255";
	if (ambiance > 1 || ambiance < 0)
		throw "Ambiance should be between 0 and 1";
	if (diffuse > 1 || diffuse < 0)
		throw "Diffuse should be between 0 and 1";
	if (specular > 1 || specular < 0)
		throw "Specular should be between 0 and 1";

	this->color = color;
	this->ambiance = ambiance;
	this->diffuse = diffuse;
	this->specular = specular;
}