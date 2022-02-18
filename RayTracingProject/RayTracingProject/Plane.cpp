#include "Plane.h"

Plane::Plane() : C3DObject() {
	this->x = this->y = 0;
	this->base[0] = Vec3(1, 0, 0);
	this->base[1] = Vec3(0, -1, 0);
}

Plane::Plane(float x, float y) : C3DObject() {
	if (x < 0 || y < 0)
		throw "Dimension for plane must be positive or null(infinite)";

	this->x = x;
	this->y = y;
	this->base[0] = Vec3(1, 0, 0);
	this->base[1] = Vec3(0, -1, 0);
}

Plane::Plane(Vec3 position, float x, float y) : C3DObject(position) {
	if (x < 0 || y < 0)
		throw "Dimension for plane must be positive or null(infinite)";

	this->x = x;
	this->y = y;
	this->base[0] = Vec3(1, 0, 0);
	this->base[1] = Vec3(0, -1, 0);
}

Plane::Plane(float x, float y, Vec3 base[2]) : C3DObject() {
	if ((base[0].getLength() < 0.01 && base[0].getLength() > -0.01) || (base[1].getLength() < 0.01 && base[1].getLength() > -0.01) || (base[0] * base[1] > 0.01 || base[0] * base[1] < -0.01))
		throw "Invalid base";
	if (x < 0 || y < 0)
		throw "Dimension for plane must be positive or null(infinite)";

	this->x = x;
	this->y = y;
	this->base[0] = base[0];
	this->base[1] = base[1];
}

Plane::Plane(float x, float y, Vec3 base1, Vec3 base2) : C3DObject() {
	if ((base1.getLength() < 0.01 && base1.getLength() > -0.01) || (base2.getLength() < 0.01 && base2.getLength() > -0.01) || (base1 * base2 > 0.01 || base1 * base2 < -0.01))
		throw "Invalid base";
	if (x < 0 || y < 0)
		throw "Dimension for plane must be positive or null(infinite)";

	this->x = x;
	this->y = y;
	this->base[0] = base1;
	this->base[1] = base2;
}

Plane::Plane(Vec3 position, float x, float y, Vec3 base[2]) : C3DObject(position) {
	if ((base[0].getLength() < 0.01 && base[0].getLength() > -0.01) || (base[1].getLength() < 0.01 && base[1].getLength() > -0.01) || (base[0] * base[1] > 0.01 || base[0] * base[1] < -0.01))
		throw "Invalid base";
	if (x < 0 || y < 0)
		throw "Dimension for plane must be positive or null(infinite)";

	this->x = x;
	this->y = y;
	this->base[0] = base[0];
	this->base[1] = base[1];
}

Plane::Plane(Vec3 position, float x, float y, Vec3 base1, Vec3 base2) : C3DObject(position) {
	if ((base1.getLength() < 0.01 && base1.getLength() > -0.01) || (base2.getLength() < 0.01 && base2.getLength() > -0.01) || (base1 * base2 > 0.01 || base1 * base2 < -0.01))
		throw "Invalid base";
	if (x < 0 || y < 0)
		throw "Dimension for plane must be positive or null(infinite)";

	this->x = x;
	this->y = y;
	this->base[0] = base1;
	this->base[1] = base2;
}