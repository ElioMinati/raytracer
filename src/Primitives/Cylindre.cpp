/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Cylindre
*/

#include "Cylindre.hpp"
#include <cmath>
#include <vector>
#include <iostream>

Shapes::Cylindre::Cylindre() : radius(0)
{
}

Shapes::Cylindre::Cylindre(const Math::Point3D &point) : center(point)
{
}

Shapes::Cylindre::Cylindre(const Shapes::ShapeParameters &params) : center(params.coords), radius(params.radius), height(Math::Vector3D(0, params.height, 0))
{
    _color = params.color;
    if (params.rotation.length() > 0) {
        height.rotate(Math::Vector3D(1, 0, 0), params.rotation.x);
        height.rotate(Math::Vector3D(0, 1, 0), params.rotation.y);
        height.rotate(Math::Vector3D(0, 0, 1), params.rotation.z);
    }
}

Shapes::Cylindre::Cylindre(const Math::Point3D &point, Math::Vector3D height, double radius, Color::Rgb color) : center(point), radius(radius), height(height)
{
    _color = color;
}

bool Shapes::Cylindre::hits(const Raytracer::Ray3D &ray, Math::Point3D &point)
{
    Math::Vector3D normalHeight(this->height); 
    normalHeight.normalize();
    double a = std::pow(ray.direction.x, 2) + std::pow(ray.direction.y, 2) + std::pow(ray.direction.z, 2) - std::pow(ray.direction.dot(normalHeight), 2);
    double b = 2 * (ray.direction.x * (ray.origin.x - this->center.x) + ray.direction.y * (ray.origin.y - this->center.y) + ray.direction.z * (ray.origin.z - this->center.z) - ray.direction.dot(normalHeight) * normalHeight.dot(Math::Vector3D(this->center, ray.origin)));
    double c = std::pow(ray.origin.x - this->center.x, 2) + std::pow(ray.origin.y - this->center.y, 2) + std::pow(ray.origin.z - this->center.z, 2) - std::pow(normalHeight.dot(Math::Vector3D(this->center, ray.origin)), 2) - std::pow(this->radius, 2);
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
        return false;

    double t1 = (-b - std::sqrt(discriminant)) / (2 * a);
    double t2 = (-b + std::sqrt(discriminant)) / (2 * a);

    bool hasPoint = false;
    Math::Point3D tmpPoint;

    if (t1 >= 0) {
        Math::Point3D intersectionPoint(ray.origin.x + t1 * ray.direction.x, ray.origin.y + t1 * ray.direction.y, ray.origin.z + t1 * ray.direction.z);
        double dotProduct = normalHeight.dot(Math::Vector3D(this->center, intersectionPoint));
        if (dotProduct >= 0 && dotProduct <= this->height.length()) {
            tmpPoint = intersectionPoint;
            hasPoint = true;
        }
    }
    if (t2 >= 0) {
        Math::Point3D intersectionPoint(ray.origin.x + t2 * ray.direction.x, ray.origin.y + t2 * ray.direction.y, ray.origin.z + t2 * ray.direction.z);
        double dotProduct = normalHeight.dot(Math::Vector3D(this->center, intersectionPoint));
        if (dotProduct >= 0 && dotProduct <= this->height.length() && hasPoint && Math::Vector3D(ray.origin, intersectionPoint).length() < Math::Vector3D(ray.origin, tmpPoint).length()) {
            tmpPoint = intersectionPoint;
            hasPoint = true;
        } else if (dotProduct >= 0 && dotProduct <= this->height.length() && !hasPoint) {
            tmpPoint = intersectionPoint;
            hasPoint = true;
        }
    }

    if (hasPoint && point.initialized && Math::Vector3D(ray.origin, point).length() > Math::Vector3D(ray.origin, tmpPoint).length()) {
        point = tmpPoint;
        return true;
    } else if (hasPoint && !point.initialized) {
        point = tmpPoint;
        return true;
    }
    return false;
}
