/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Sphere
*/

#include <cmath>
#include <iostream>
#include "Math.hpp"
#include "Sphere.hpp"

Shapes::Sphere::Sphere() : radius(0)
{
}

Shapes::Sphere::Sphere(const Math::Point3D &point) : center(point)
{
}

Shapes::Sphere::Sphere(const Shapes::ShapeParameters &params) : center(params.coords), radius(params.radius)
{
    _color = params.color;
}

Shapes::Sphere::Sphere(const Math::Point3D &point, double radius, Color::Rgb color) : center(point), radius(radius)
{
    _color = color;
}

bool Shapes::Sphere::hits(const Raytracer::Ray3D &ray, Math::Point3D &point)
{
    Math::Vector3D rayToSphere(ray.origin.x - center.x, ray.origin.y - center.y, ray.origin.z - center.z);
    double a = ray.direction.x * ray.direction.x + ray.direction.y * ray.direction.y + ray.direction.z * ray.direction.z;
    double b = 2 * (ray.direction.x * rayToSphere.x + ray.direction.y * rayToSphere.y + ray.direction.z * rayToSphere.z);
    double c = std::pow(rayToSphere.x, 2) + std::pow(rayToSphere.y, 2) + std::pow(rayToSphere.z, 2) - std::pow(radius, 2);
    double d = std::pow(b, 2) - (4 * a * c);

    if (d < 0)
        return false;
    double t1 = (-b + sqrt(d)) / (2.0 * a);
    double t2 = (-b - sqrt(d)) / (2.0 * a);
    double t = t1 < t2 ? t1 : t2;
    if (t < 0.0) {
        return false;
    }
    Math::Point3D tmpPoint = ray.origin + ray.direction * t;
    if (point.initialized && Math::Vector3D(ray.origin, point).length() > Math::Vector3D(ray.origin, tmpPoint).length()) {
        point = tmpPoint;
        return true;
    } else if (!point.initialized) {
        point = tmpPoint;
        return true;
    }
    return false;
}
