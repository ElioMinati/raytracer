/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CameraBuilder
*/

#include <cmath>
#include "CameraBuilder.hpp"
#include "Math/Point3D.hpp"
#include "Math/Vector3D.hpp"
#include "Math/MathUtils.hpp"

Raytracer::CameraBuilder::CameraBuilder()
{
}

void Raytracer::CameraBuilder::buildLens(const Math::Point3D &position, const Math::Vector3D &rotation)
{
    _camera.origin = position;
    cameraHeading = Math::Vector3D::getDirectionVector(position, rotation);
}

void Raytracer::CameraBuilder::buildScreen(const int width, const int height)
{
    _cameraWidth = width;
    _cameraHeight = height;
    _camera.screen = Camera::createScreen(_camera.origin, cameraHeading, width, height);
}

void Raytracer::CameraBuilder::buildFov(const int fov)
{
    double newDistance = static_cast<double>(_cameraWidth) / (2 * tan(Math::Utils::rad(fov) / 2));
    Math::Vector3D normalheading = Math::Vector3D::getParallelVector(cameraHeading, fov) * -1;

    _camera.origin = _camera.origin + (normalheading.normalize() * newDistance);
}

Raytracer::Camera Raytracer::CameraBuilder::getCamera()
{
    return _camera;
}
