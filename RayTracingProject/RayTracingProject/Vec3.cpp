#include "Vec3.h"
#include <math.h>


Vec3::Vec3() {
	this->x = this->y = this->z = 0;
}

Vec3::Vec3(float x) {
	this->x = x;
	this->y = this->z = 0;
}

Vec3::Vec3(float x, float y) {
	this->x = x;
	this->y = y;
	this->z = 0;
}

Vec3::Vec3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vec3::~Vec3() {

}



//Récupère la norme du vecteur
float Vec3::getLength() {
	return sqrtf(powf(this->x, 2) + powf(this->y, 2) + powf(this->z, 2));
}

//Normalise le vecteur
Vec3* Vec3::normalize() {
	float factor = this->getLength();

	this->x /= factor;
	this->y /= factor;
	this->z /= factor;

	return this;
}

//Renvoie le vecteur normalisé dans un autre vecteur
Vec3 Vec3::getNormalized() {
	float factor = this->getLength();
	return this->operator/(factor);
}

Vec3 Vec3::getReflected(Vec3 normal) {
	Vec3 normalized = this->operator-().getNormalized();
	normal.normalize();
	
	return normal * 2 * (normal * normalized) - normalized;

}



Vec3 Vec3::operator-(){
	return Vec3(-this->x, -this->y, -this->z);
}

bool Vec3::operator==(Vec3 other) {
	return (this->x < other.x + 0.01 && this->x > other.x - 0.01) && (this->y < other.y + 0.01 && this->y > other.y - 0.01) && (this->z < other.z + 0.01 && this->z > other.z - 0.01);
}

Vec3 Vec3::operator+(Vec3 other) {
	return Vec3(this->x + other.x, this->y + other.y, this->z + other.z);
}

Vec3 Vec3::operator-(Vec3 other) {
	return Vec3(this->x - other.x, this->y - other.y, this->z - other.z);
}

float Vec3::operator*(Vec3 other) {
	return this->x * other.x + this->y * other.y + this->z * other.z;
}

Vec3 Vec3::operator*(float val) {
	return Vec3(this->x * val, this->y * val, this->z * val);
}

Vec3 Vec3::operator/(float val) {
	return Vec3(this->x / val, this->y / val, this->z / val);
}

Vec3 Vec3::operator^(Vec3 other) {
	return Vec3(this->y * other.z - this->z * other.y, this->z * other.x - this->x * other.z, this->x * other.y - this->y * other.x);
}

Vec3 Vec3::operator[](Vec3 other) {
	return Vec3(this->x * other.x, this->y * other.y, this->z * other.z);
}

Vec3 clampColor(Vec3 color) {
	if (color.x > 255)
		color.x = 255;
	if (color.x < 0.01)
		color.x = 0;
	if (color.y > 255)
		color.y = 255;
	if (color.y < 0.01)
		color.y = 0;
	if (color.z > 255)
		color.z = 255;
	if (color.z < 0.01)
		color.z = 0;
	return color;
}