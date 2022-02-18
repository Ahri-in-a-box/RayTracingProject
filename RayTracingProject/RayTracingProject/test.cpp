#include <stdio.h>
#include "3DObjects.h"
#include "Ray.h"
#include "IntersectionChecker.h"

int main() {
	Ray ray1 = { Vec3(0, 0, 0), Vec3(0, 0, -1) }, ray2 = { Vec3(0, 0, 0), Vec3(0, 0.5, -1) };
	Sphere sphere = Sphere(Vec3(0, 0, -5), 3);
	Vec3 pos;
	float dist;

	if (IntersectionChecker().checkIntersection(ray1, sphere, &pos, &dist))
		printf("Ray1 x Sphere: pos: (%.2f, %.2f, %.2f) (%.2f)\n", pos.x, pos.y, pos.z, dist);
	if (IntersectionChecker().checkIntersection(ray2, sphere, &pos, &dist))
		printf("Ray2 x Sphere: pos: (%.2f, %.2f, %.2f) (%.2f)\n", pos.x, pos.y, pos.z, dist);


	printf("\n");


	ray1.origin = Vec3(-1, -1, 0);
	Plane plane1 = Plane(Vec3(0, 0, -3), 800, 450, Vec3(1, 0, 0), Vec3(0, -1, 0));
	Plane plane2 = Plane(Vec3(0, 0, -3), 800, 450, Vec3(1, 0, -1), Vec3(0, -1, 0));

	if (IntersectionChecker().checkIntersection(ray1, plane1, &pos, &dist))
		printf("Ray x Plane1: pos: (%.2f, %.2f, %.2f) (%.2f)\n", pos.x, pos.y, pos.z, dist);
	if (IntersectionChecker().checkIntersection(ray1, plane2, &pos, &dist))
		printf("Ray x Plane2: pos: (%.2f, %.2f, %.2f) (%.2f)\n", pos.x, pos.y, pos.z, dist);

	return 0;
}