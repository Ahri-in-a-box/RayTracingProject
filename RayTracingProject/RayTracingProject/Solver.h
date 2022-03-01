#pragma once
#include "Vec3.h"
#include "Plane.h"

/* Vec3 _C12(Plane plane, Vec3 inter);
Vec3 _C13(Plane plane, Vec3 inter);
Vec3 _C21(Plane plane, Vec3 inter);
Vec3 _C23(Plane plane, Vec3 inter);
Vec3 _C31(Plane plane, Vec3 inter);
Vec3 _C32(Plane plane, Vec3 inter); */

Vec3 planePositionToBaseCoord(Plane plane, Vec3 inter);