/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Light
*/

#include "Light.hpp"

Raytracer::Light::Light(Math::Point3D position, Math::Vector3D heading, Color::Rgb color, Color::Rgb ambiant) : _position(position), _heading(heading), _color(color), _ambiantLight(ambiant)
{
}

Raytracer::Light::~Light()
{
}
