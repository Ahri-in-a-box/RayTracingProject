#pragma once
#include "Solver.h"

Vec3 _C12(Plane plane, Vec3 inter) {
	/*
		b1.x * ratio1 + b2.x * ratio2 = inter.x
		b1.y * ratio1 + b2.y * ratio2 = inter.y
		b1.z * ratio1 + b2.z * ratio2 = inter.z

		ratio1 = (inter.x - b2.x * ratio2) / b1.x
		b1.y * ( (inter.x - b2.x * ratio2) / b1.x ) + b2.y * ratio2 = inter.y
		b1.z * ratio1 + b2.z * ratio2 = inter.z

		ratio1 = (inter.x - b2.x * ratio2) / b1.x
		b1.y * inter.x - b2.x * ratio2 + b2.y * ratio2 * b1.x = inter.y * b1.x
		b1.z * ratio1 + b2.z * ratio2 = inter.z

		ratio1 = (inter.x - b2.x * ratio2) / b1.x
		ratio2 * (b2.y * b1.x - b2.x) = inter.y * b1.x - b1.y * inter.x
		b1.z * ratio1 + b2.z * ratio2 = inter.z

		ratio1 = (inter.x - b2.x * ratio2) / b1.x
		ratio2 = (inter.y * b1.x - b1.y * inter.x) / (b2.y * b1.x - b2.x)
		b1.z * ratio1 + b2.z * ratio2 = inter.z
	*/

	float r2 = (inter.y * plane.base[0].x - plane.base[0].y * inter.x) / (plane.base[1].y * plane.base[0].x - plane.base[1].x);
	float r1 = (inter.x - plane.base[1].x * r2) / plane.base[0].x;
	float ver = plane.base[0].z * r1 + plane.base[1].z * r2;

	return Vec3(r1, r2, ver - inter.z < 0.01f && ver - inter.z > -0.01f ? 1 : -1);
}

Vec3 _C13(Plane plane, Vec3 inter) {
	/*
		b1.x * ratio1 + b2.x * ratio2 = inter.x
		b1.y * ratio1 = inter.y
		b1.z * ratio1 + b2.z * ratio2 = inter.z

		ratio1 = (inter.x - b2.x * ratio2) / b1.x
		b1.y * ratio1 = inter.y
		b1.z * ( (inter.x - b2.x * ratio2) / b1.x ) + b2.z * ratio2 = inter.z

		ratio1 = (inter.x - b2.x * ratio2) / b1.x
		b1.y * ratio1 = inter.y
		b1.z * inter.x - b2.x * ratio2 + b2.z * ratio2 * b1.x = inter.z * b1.x

		ratio1 = (inter.x - b2.x * ratio2) / b1.x
		b1.y * ratio1 = inter.y
		ratio2 * (b2.z * b1.x - b2.x) = inter.z * b1.x - b1.z * inter.x

		ratio1 = (inter.x - b2.x * ratio2) / b1.x
		b1.y * ratio1 = inter.y
		ratio2 = (inter.z * b1.x - b1.z * inter.x) / (b2.z * b1.x - b2.x)
	*/

	float r2 = (inter.z * plane.base[0].x - plane.base[0].z * inter.x) / (plane.base[1].z * plane.base[0].x - plane.base[1].x);
	float r1 = (inter.x - plane.base[1].x * r2) / plane.base[0].x;
	float ver = plane.base[0].y * r1;

	return Vec3(r1, r2, ver - inter.z < 0.01f && ver - inter.z > -0.01f ? 1 : -1);
}

Vec3 _C21(Plane plane, Vec3 inter) {
	/*
		b2.x * ratio2 = inter.x
		b1.y * ratio1 + b2.y * ratio2 = inter.y
		b1.z * ratio1 + b2.z * ratio2 = inter.z

		ratio2 = inter.x / b2.x
		b1.y * ratio1 + b2.y * ( inter.x / b2.x ) = inter.y
		b1.z * ratio1 + b2.z * ratio2 = inter.z

		ratio2 = (inter.x - b1.x * ratio1) / b2.x
		b1.y * ratio1 * b2.x + b2.y * inter.x = inter.y * b2.x
		b1.z * ratio1 + b2.z * ratio2 = inter.z

		ratio2 = (inter.x - b1.x * ratio1) / b2.x
		b1.y * ratio1 * b2.x = inter.y * b2.x - b2.y * inter.x
		b1.z * ratio1 + b2.z * ratio2 = inter.z

		ratio2 = (inter.x - b1.x * ratio1) / b2.x
		ratio1 = (inter.y * b2.x - b2.y * inter.x) / (b1.y * b2.x)
		b1.z * ratio1 + b2.z * ratio2 = inter.z
	*/

	float r1 = (inter.y * plane.base[1].x - plane.base[1].y * inter.x) / (plane.base[0].y * plane.base[1].x);
	float r2 = (inter.x - plane.base[0].x * r1) / plane.base[1].x;
	float ver = plane.base[0].z * r1 + plane.base[1].z * r2;


	return Vec3(r1, r2, ver - inter.z < 0.01f && ver - inter.z > -0.01f ? 1 : -1);
}

Vec3 _C23(Plane plane, Vec3 inter) {
	/*
		0 = inter.x
		b1.y * ratio1 + b2.y * ratio2 = inter.y
		b1.z * ratio1 + b2.z * ratio2 = inter.z

		0 = inter.x
		ratio1 = (inter.y - b2.y * ratio2) / b1.y
		b1.z * ( (inter.y - b2.y * ratio2) / b1.y ) + b2.z * ratio2 = inter.z

		0 = inter.x
		ratio1 = (inter.y - b2.y * ratio2) / b1.y
		b1.z * inter.y - b2.y * ratio2 + b2.z * ratio2 * b1.y = inter.z * b1.y

		0 = inter.x
		ratio1 = (inter.y - b2.y * ratio2) / b1.y
		ratio2 * (b2.z * b1.y - b2.y) = inter.z * b1.y - b1.z * inter.y

		0 = inter.x
		ratio1 = (inter.y - b2.y * ratio2) / b1.y
		ratio2 = (inter.z * b1.y - b1.z * inter.y) / (b2.z * b1.y - b2.y)
	*/

	float r2 = (inter.z * plane.base[0].y - plane.base[0].z * inter.y) / (plane.base[1].z * plane.base[0].y - plane.base[1].y);
	float r1 = (inter.y - plane.base[1].y * r2) / plane.base[0].y;

	return Vec3(r1, r2, inter.z < 0.01 && inter.z > -0.01 ? 1 : -1);
}

Vec3 _C31(Plane plane, Vec3 inter) {
	/*
		b2.x * ratio2 = inter.x
		b2.y * ratio2 = inter.y
		b1.z * ratio1 + b2.z * ratio2 = inter.z

		ratio2 = inter.x / b2.x
		b2.y * ratio2 = inter.y
		b1.z * ratio1 + inter.x / b2.x = inter.z

		ratio2 = inter.x / b2.x
		b2.y * ratio2 = inter.y
		b1.z * ratio1 * b2.x + inter.x = inter.z * b2.x

		ratio2 = inter.x / b2.x
		b2.y * ratio2 = inter.y
		ratio1 = (inter.z * b2.x - inter.x) / (b1.z * b2.x)
	*/

	float r2 = inter.x / plane.base[1].x;
	float r1 = (inter.z * plane.base[1].x - inter.x) / (plane.base[0].z * plane.base[1].x);
	float ver = plane.base[1].z * r2;

	return Vec3(r1, r2, ver - inter.z < 0.01f && ver - inter.z > -0.01f ? 1 : -1);
}

Vec3 _C32(Plane plane, Vec3 inter) {
	/*
		0 = inter.x
		b2.y * ratio2 = inter.y
		b1.z * ratio1 + b2.z * ratio2 = inter.z

		0 = inter.x
		ratio2 = inter.y / b2.y
		b1.z * ratio1 + b2.z * inter.y / b2.y = inter.z

		0 = inter.x
		ratio2 = inter.y / b2.y
		b1.z * ratio1 * b2.y + b2.z * inter.y = inter.z * b2.y

		0 = inter.x
		ratio2 = inter.y / b2.y
		b1.z * ratio1 * b2.y = inter.z * b2.y - b2.z * inter.y

		0 = inter.x
		ratio2 = inter.y / b2.y
		ratio1 = (inter.z * b2.y - b2.z * inter.y) / (b1.z * b2.y)
	*/

	float r2 = inter.y / plane.base[1].y;
	float r1 = (inter.x - plane.base[1].x * r2) / plane.base[0].x;

	return Vec3(r1, r2, inter.z < 0.01 && inter.z > -0.01 ? 1 : -1);
}

//La réponse est un vec3 ou x = r1, y = r2 et z > 0 si tout est bon z < 0 sinon
Vec3 planePositionToBaseCoord(Plane plane, Vec3 inter) {
	bool r1[3], r2[3];

	r1[0] = plane.base[0].x > 0.01 || plane.base[0].x < 0.01;
	r1[1] = plane.base[0].y > 0.01 || plane.base[0].y < 0.01;
	r1[2] = plane.base[0].y > 0.01 || plane.base[0].y < 0.01;

	r2[0] = plane.base[1].x > 0.01 || plane.base[1].x < 0.01;
	r2[1] = plane.base[1].y > 0.01 || plane.base[1].y < 0.01;
	r2[2] = plane.base[1].y > 0.01 || plane.base[1].y < 0.01;

	if (r1[0] && r2[1])
		return _C12(plane, inter);
	if (r1[0] && r2[2])
		return _C13(plane, inter);
	if (r1[1] && r2[0])
		return _C21(plane, inter);
	if (r1[1] && r2[2])
		return _C23(plane, inter);
	if (r1[2] && r2[0])
		return _C31(plane, inter);
	if (r1[2] && r2[1])
		return _C32(plane, inter);

	throw "Invalid plane base";
}