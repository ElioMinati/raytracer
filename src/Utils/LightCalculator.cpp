/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** LightCalculator
*/

#include "LightCalculator.hpp"
#include <cmath>
#include <vector>
#include <algorithm>

Color::Rgb Color::LightCalculator::computeLight(Math::Point3D point, Shapes::IShape *shape, Raytracer::Light light, Math::Vector3D cameraRay, std::vector<std::unique_ptr<Shapes::IShape>> *primitives)
{
    Color::Rgb color;
    Math::Vector3D light_direction = Math::Vector3D(light._position, point);
    double lightMult = (light._intensity - light_direction.length()) / light._intensity;
    if (lightMult < (static_cast<double>(light._ambiantLight.r /255.0)))
        lightMult = static_cast<double>(light._ambiantLight.r /255.0);
    Raytracer::Ray3D ray(light._position, light_direction);
    Math::Point3D testPoint;
    for (std::size_t k = 0; k < primitives->size(); k++) {
        (*primitives)[k]->hits(ray, testPoint);
    }
    if (Math::Vector3D(point, testPoint).length() < 0.01) {
        color.r = ((shape->getColor().r + light._color.r) / 2) * lightMult;
        color.g = ((shape->getColor().g + light._color.g) / 2) * lightMult;
        color.b = ((shape->getColor().b + light._color.b) / 2) * lightMult;
    } else {
        color.r = static_cast<double>(shape->getColor().r) * (static_cast<double>(light._ambiantLight.r) / 255.0);
        color.g = static_cast<double>(shape->getColor().g) * (static_cast<double>(light._ambiantLight.g) / 255.0);
        color.b = static_cast<double>(shape->getColor().b) * (static_cast<double>(light._ambiantLight.b) / 255.0);
    }
    return color;
}