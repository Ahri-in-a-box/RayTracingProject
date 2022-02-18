#include "IntersectionChecker.h"
#include <math.h>

bool IntersectionChecker::checkIntersection(Ray ray, Sphere sphere, Vec3* out, float* dist) {
	//t²*(dx² + dy² + dz²) + 2*t*(X0*dx + Y0*dy + Z0*dz) + (X0² + Y0² + Z0²) - R² = 0
	ray.direction.normalize();

	float X0 = ray.origin.x - sphere.position.x;
	float Y0 = ray.origin.y - sphere.position.y;
	float Z0 = ray.origin.z - sphere.position.z;

	float a = powf(ray.direction.x, 2) + powf(ray.direction.y, 2) + powf(ray.direction.z, 2);
	float b = 2 * (X0 + ray.direction.x + Y0 * ray.direction.y + Z0 * ray.direction.z);
	float c = powf(X0, 2) + powf(Y0, 2) + powf(Z0, 2) - powf(sphere.size, 2);

	float delta = powf(b, 2) - 4*a*c;
	
	if(delta < 0.01)
		return false;

	float x1 = (-b + sqrtf(delta)) / (2 * a);
	float x2 = (-b - sqrtf(delta)) / (2 * a);
	
	*dist = x1 > x2 ? (x2 > 0.01 ? x2 : x1) : (x1 > 0.01 ? x1 : x2);
	*out = ray.origin + ray.direction * (*dist);
	return true;
}

bool IntersectionChecker::checkIntersection(Ray ray, Plane plane, Vec3* out, float* dist) {
	throw "Not implemented yet";
}