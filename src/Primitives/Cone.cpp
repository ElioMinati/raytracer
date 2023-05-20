/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Cone
*/

#include "Cone.hpp"
#include <cmath>
#include <iostream>
#include "Math.hpp"

Shapes::Cone::Cone() : radius(0)
{
}

Shapes::Cone::Cone(const Math::Point3D &point) : center(point)
{
}

Shapes::Cone::Cone(const Shapes::ShapeParameters &params) : center(params.coords), radius(params.radius), height(params.height)
{
    _color = params.color;
}

Shapes::Cone::Cone(const Math::Point3D &point, double radius, Color::Rgb color) : center(point), radius(radius)
{
    _color = color;
}

bool Shapes::Cone::hits(const Raytracer::Ray3D &ray, Math::Point3D &point)
{
    Math::Vector3D rayToSphere(ray.origin.x - center.x, ray.origin.y - center.y, ray.origin.z - center.z);

    double a = std::pow(ray.direction.x, 2) + std::pow(ray.direction.y, 2) - std::pow(ray.direction.z, 2) * std::pow(radius / height, 2);
    double b = 2.0 * (rayToSphere.x * ray.direction.x + rayToSphere.y * ray.direction.y - rayToSphere.z * ray.direction.z * std::pow(radius / height, 2));
    double c = std::pow(rayToSphere.x, 2) + std::pow(rayToSphere.y, 2) - std::pow(rayToSphere.z, 2) * std::pow(radius / height, 2);
    double discriminant = std::pow(b, 2) - 4 * a * c;

    if (discriminant < 0)
        return false;

    double t1 = (-b - std::sqrt(discriminant)) / (2 * a);
    double t2 = (-b + std::sqrt(discriminant)) / (2 * a);

    double z1 = rayToSphere.z + t1 * ray.direction.z;
    double z2 = rayToSphere.z + t2 * ray.direction.z;

    if ((z1 >= 0 && z1 <= height) || (z2 >= 0 && z2 <= height))
        return true;

    return false;
}
