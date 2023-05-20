/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Ray3D
*/

#include "Ray3D.hpp"

Raytracer::Ray3D::Ray3D()
{
}

Raytracer::Ray3D::Ray3D(Math::Point3D origin, Math::Vector3D direction) : origin(origin), direction(direction)
{

}

Raytracer::Ray3D::Ray3D(const Ray3D &ray) : origin(ray.origin), direction(ray.direction)
{

}

Raytracer::Ray3D &Raytracer::Ray3D::operator=(const Ray3D &ray)
{
    this->origin = ray.origin;
    this->direction = ray.direction;
    return *this;
}
