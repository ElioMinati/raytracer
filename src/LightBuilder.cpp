/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** LightBuilder
*/

#include "LightBuilder.hpp"

Raytracer::LightBuilder::LightBuilder()
{
}

void Raytracer::LightBuilder::buildLight(const Math::Point3D &position, Color::Rgb color)
{
    _light._position = position;
    _light._color = color;
}

void Raytracer::LightBuilder::buildAmbiantLight(Color::Rgb color)
{
    _light._ambiantLight = color;
}

void Raytracer::LightBuilder::buildIntensity(double intensity)
{
    _light._intensity = intensity;
}
