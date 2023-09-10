#pragma once

class Vector3D
{
public:
	float x, y, z;

	Vector3D()
	{
		x = y = z = 0;
	}

	Vector3D(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector3D& operator+(Vector3D arg)
	{
		x += arg.x;
		y += arg.y;
		z += arg.z;
		return *this;
	}

	Vector3D& operator-(Vector3D arg)
	{
		x -= arg.x;
		y -= arg.y;
		z -= arg.z;
		return *this;
	}

	Vector3D& operator/(Vector3D arg)
	{
		x /= arg.x;
		y /= arg.y;
		z /= arg.z;
		return *this;
	}

	Vector3D& operator*(Vector3D arg)
	{
		x *= arg.x;
		y *= arg.y;
		z *= arg.z;
		return *this;
	}
};