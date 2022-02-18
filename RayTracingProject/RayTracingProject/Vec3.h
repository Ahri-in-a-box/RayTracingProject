#pragma once
class Vec3{
	public:
		float x, y, z;

		Vec3();
		Vec3(float x);
		Vec3(float x, float y);
		Vec3(float x, float y, float z);
		~Vec3();



		float getLength();
		Vec3* normalize();
		Vec3 getNormalized();
		Vec3 getReflected(Vec3 normal);



		Vec3 operator-();
		bool operator==(Vec3 other);
		Vec3 operator+(Vec3 other);
		Vec3 operator-(Vec3 other);
		float operator*(Vec3 other);
		Vec3 operator*(float val);
		Vec3 operator/(float val);
		Vec3 operator^(Vec3 other);
		Vec3 operator[](Vec3 other);
};