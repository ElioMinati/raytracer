/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Vector3D
*/

#include <cmath>
#include <iostream>
#include "MathUtils.hpp"
#include "Vector3D.hpp"

Math::Vector3D::Vector3D() : x(0), y(0), z(0)
{
}

Math::Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z)
{
}

Math::Vector3D::Vector3D(const Vector3D &vector) : x(vector.x), y(vector.y), z(vector.z)
{
}

Math::Vector3D::Vector3D(const Point3D &p1, const Point3D &p2) : x(p2.x - p1.x), y(p2.y - p1.y), z(p2.z - p1.z)
{
}

Math::Vector3D::Vector3D(const Point3D &p) : x(p.x), y(p.y), z(p.z)
{
}

double Math::Vector3D::dot(const Math::Vector3D &vector) const
{
    return (this->x * vector.x + this->y * vector.y + this->z * vector.z);
}

Math::Vector3D Math::Vector3D::cross(const Math::Vector3D &vector) const
{
    return Vector3D(this->y * vector.z - this->z * vector.y, this->z * vector.x - this->x * vector.z, this->x * vector.y - this->y * vector.x);
}

double Math::Vector3D::length() const
{
    return std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2));
}

bool Math::Vector3D::operator==(const Math::Vector3D &point)
{
    if (this->x == point.x && this->y == point.y && this->z == point.z)
        return true;
    return false;
}

Math::Vector3D &Math::Vector3D::operator=(const Math::Vector3D &point)
{
    this->x = point.x;
    this->y = point.y;
    this->z = point.z;
    return *this;
}

Math::Vector3D &Math::Vector3D::operator+=(const Vector3D &point)
{
    this->x += point.x;
    this->y += point.y;
    this->z += point.z;
    return *this;
}

Math::Vector3D &Math::Vector3D::operator-=(const Vector3D &point)
{
    this->x -= point.x;
    this->y -= point.y;
    this->z -= point.z;
    return *this;
}

Math::Vector3D &Math::Vector3D::operator*=(const Vector3D &point)
{
    this->x *= point.x;
    this->y *= point.y;
    this->z *= point.z;
    return *this;
}

Math::Vector3D &Math::Vector3D::operator/=(const Vector3D &point)
{
    this->x /= point.x;
    this->y /= point.y;
    this->z /= point.z;
    return *this;
}

Math::Vector3D Math::Vector3D::operator+(const Vector3D &point) const
{
    return Vector3D(this->x + point.x, this->y + point.y, this->z + point.z);
}

Math::Vector3D Math::Vector3D::operator-(const Vector3D &point)
{
    return Vector3D(this->x - point.x, this->y - point.y, this->z - point.z);
}

Math::Vector3D Math::Vector3D::operator*(const Vector3D &point)
{
    return Vector3D(this->x * point.x, this->y * point.y, this->z * point.z);
}

Math::Vector3D Math::Vector3D::operator*(const double &nb) const
{
    return Vector3D(this->x * nb, this->y * nb, this->z * nb);
}

Math::Vector3D &Math::Vector3D::rotate(const Math::Vector3D &axis, double angle)
{
    double ux = axis.x * this->x;
    double uy = axis.x * this->y;
    double uz = axis.x * this->z;
    double vx = axis.y * this->x;
    double vy = axis.y * this->y;
    double vz = axis.y * this->z;
    double wx = axis.z * this->x;
    double wy = axis.z * this->y;
    double wz = axis.z * this->z;
    double newX = (axis.x * (ux + vy + wz) + (this->x * (axis.y * axis.y + axis.z * axis.z) - axis.x * (vy + wz)) * cosf(angle) + (-wy + vz) * sinf(angle));
    double newY = (axis.y * (ux + vy + wz) + (this->y * (axis.x * axis.x + axis.z * axis.z) - axis.y * (ux + wz)) * cosf(angle) + (wx - uz) * sinf(angle));
    double newZ = (axis.z * (ux + vy + wz) + (this->z * (axis.x * axis.x + axis.y * axis.y) - axis.z * (ux + vy)) * cosf(angle) + (-vx + uy) * sinf(angle));

    this->x = newX;
    this->y = newY;
    this->z = newZ;
    return *this;
}

Math::Vector3D Math::Vector3D::operator/(const Vector3D &point)
{
    return Vector3D(this->x / point.x, this->y / point.y, this->z / point.z);
}

Math::Vector3D Math::Vector3D::getDirectionVector(const Vector3D &origin, const Vector3D &rotation)
{
    Vector3D direction(0, 0, 1);
    Vector3D newRotation(Math::Utils::rad(rotation.x), Math::Utils::rad(rotation.y), Math::Utils::rad(rotation.z));

    direction.rotate(Vector3D(1, 0, 0), newRotation.x);
    direction.rotate(Vector3D(0, 1, 0), newRotation.y);
    direction.rotate(Vector3D(0, 0, 1), newRotation.z);
    direction.normalize();
    return direction;
}

Math::Vector3D &Math::Vector3D::normalize()
{
    double len = this->length();

    if (len != 0) {
        x /= len;
        y /= len;
        z /= len;
    }
    return *this;
}

Math::Vector3D Math::Vector3D::getParallelVector(const Vector3D &vector, double len) {
    double scale = len / vector.length();

    return Vector3D(vector.x * scale, vector.y * scale, vector.z * scale);
}

std::ostream& operator<<(std::ostream& os, const Math::Vector3D &vector)
{
    os << "{x: " << vector.x << ", y: " << vector.y << ", z: " << vector.z << "}";
    return os;
}

