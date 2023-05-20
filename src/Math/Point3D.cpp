/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Point3D
*/

#include "Point3D.hpp"

Math::Point3D::Point3D() : x(0), y(0), z(0)
{
    initialized = false;
}

Math::Point3D::Point3D(const Point3D &point) : x(point.x), y(point.y), z(point.z)
{
    initialized = true;
}

bool Math::Point3D::operator==(const Math::Point3D &point)
{
    if (this->x == point.x && this->y == point.y && this->z == point.z)
        return true;
    return false;
}

Math::Point3D &Math::Point3D::operator=(const Math::Point3D &point)
{
    initialized = true;
    this->x = point.x;
    this->y = point.y;
    this->z = point.z;
    return *this;
}

Math::Point3D &Math::Point3D::operator=(const Math::Vector3D &point)
{
    initialized = true;
    this->x = point.x;
    this->y = point.y;
    this->z = point.z;
    return *this;
}

Math::Point3D &Math::Point3D::operator+=(const Point3D &point)
{
    initialized = true;
    this->x += point.x;
    this->y += point.y;
    this->z += point.z;
    return *this;
}

Math::Point3D &Math::Point3D::operator+=(const Vector3D &vector)
{
    initialized = true;
    this->x += vector.x;
    this->y += vector.y;
    this->z += vector.z;
    return *this;
}

Math::Point3D &Math::Point3D::operator-=(const Vector3D &vector)
{
    initialized = true;
    this->x -= vector.x;
    this->y -= vector.y;
    this->z -= vector.z;
    return *this;
}

Math::Point3D &Math::Point3D::operator-=(const Point3D &point)
{
    initialized = true;
    this->x -= point.x;
    this->y -= point.y;
    this->z -= point.z;
    return *this;
}

Math::Point3D &Math::Point3D::operator*=(const Point3D &point)
{
    initialized = true;
    this->x *= point.x;
    this->y *= point.y;
    this->z *= point.z;
    return *this;
}

Math::Point3D &Math::Point3D::operator/=(const Point3D &point)
{
    initialized = true;
    this->x /= point.x;
    this->y /= point.y;
    this->z /= point.z;
    return *this;
}

Math::Point3D Math::Point3D::operator+(const Point3D &point)
{
    return Point3D(this->x + point.x, this->y + point.y, this->z + point.z);
}

Math::Point3D Math::Point3D::operator+(const Vector3D &vector) const
{
    return Point3D(this->x + vector.x, this->y + vector.y, this->z + vector.z);
}

Math::Point3D Math::Point3D::operator-(const Point3D &point) const
{
    return Point3D(this->x - point.x, this->y - point.y, this->z - point.z);
}

Math::Point3D Math::Point3D::operator-(const Point3D &point)
{
    return Point3D(this->x - point.x, this->y - point.y, this->z - point.z);
}

Math::Point3D Math::Point3D::operator-(const Vector3D &vec) const
{
    return Point3D(this->x - vec.x, this->y - vec.y, this->z - vec.z);
}

Math::Point3D Math::Point3D::operator*(const Point3D &point)
{
    return Point3D(this->x * point.x, this->y * point.y, this->z * point.z);
}

Math::Point3D Math::Point3D::operator/(const Point3D &point)
{
    return Point3D(this->x / point.x, this->y / point.y, this->z / point.z);
}

Math::Point3D::Point3D(double x, double y, double z) : x(x), y(y), z(z)
{
    initialized = true;
}

std::ostream& operator<<(std::ostream& os, const Math::Point3D &point)
{
    os << "{x: " << point.x << ", y: " << point.y << ", z: " << point.z << "}";
    return os;
}
