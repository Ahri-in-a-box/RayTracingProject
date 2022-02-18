#include "Triangle.h"

Triangle::Triangle() {
	this->position = Vec3(0, 0.5, 0);
	this->points[0] = Vec3(0, 0.5, 0);
	this->points[1] = Vec3(0, -0.5, -0.5);
	this->points[2] = Vec3(0, -0.5, 0.5);
}

Triangle::Triangle(Vec3 points[3]) {
	this->position = Vec3();
	for (int i = 0; i < 3; i++) {
		this->points[i] = points[i];
		this->position = this->position + points[i];
	}

	this->position = this->position / 3;
}

Triangle::Triangle(Vec3 point1, Vec3 point2, Vec3 point3) {
	this->position = this->points[0] = point1;
	this->position = this->position + (this->points[1] = point2);
	this->position = this->position + (this->points[2] = point3);

	this->position = this->position / 3;
}