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



//R?cup?re la norme du vecteur
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

//Renvoie le vecteur normalis? dans un autre vecteur
Vec3 Vec3::getNormalized() {
	float factor = this->getLength();
	return this->operator/(factor);
}

Vec3 Vec3::getReflected(Vec3 normal) {
	throw "Not implemented yet";
	//Normalisation des deux vecteurs
	//Calcul du produit scalaire
	//Calcul de l'angle
	//Calcul du r?fl?chi
}



Vec3 Vec3::operator-(){
	return Vec3(-this->x, -this->y, -this->z);
}

Vec3 Vec3::operator+(Vec3 other) {
	return Vec3(this->x + other.x, this->y + other.y, this->z + other.z);
}

Vec3 Vec3::operator-(Vec3 other) {
	return Vec3(this->x - other.x, this->y - other.y, this->z - other.z);
}

Vec3 Vec3::operator*(float val) {
	return Vec3(this->x * val, this->y * val, this->z * val);
}

Vec3 Vec3::operator/(float val) {
	return Vec3(this->x / val, this->y / val, this->z / val);
}

float Vec3::operator*(Vec3 other) {
	return this->x * other.x + this->y * other.y + this->z * other.z;
}

Vec3 Vec3::operator^(Vec3 other) {
	throw "Not implemented yet";
}