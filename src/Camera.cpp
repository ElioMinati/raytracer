/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Camera
*/

#include <cmath>
#include <iostream>
#include "Camera.hpp"

Raytracer::Camera::Camera()
{
}

Raytracer::Camera::Camera(const Math::Point3D &origin, const Math::Rectangle3D &screen) : origin(origin), screen(screen)
{
}

Math::Rectangle3D Raytracer::Camera::createScreen(const Math::Point3D &position, const Math::Vector3D &heading, int width, int height)
{
    Math::Vector3D headingNorm(heading);
    Math::Vector3D screenPos;

    headingNorm.normalize();
    screenPos = Math::Vector3D(position.x + headingNorm.x, position.y + headingNorm.y, position.z + headingNorm.z);
    Math::Vector3D screenRight(headingNorm.z, 0, -headingNorm.x);
    screenRight.normalize();
    Math::Vector3D screenUp = screenRight.cross(heading);
    screenUp.normalize();
    Math::Vector3D screenWidthVec(screenRight.x * width, screenRight.y * width, screenRight.z * width);
    Math::Vector3D screenHeightVec(screenUp.x * height, screenUp.y * height, screenUp.z * height);
    Math::Point3D finalPos(screenPos.x - screenWidthVec.x / 2.0f - screenHeightVec.x / 2.0f,
                        screenPos.y - screenWidthVec.y / 2.0f - screenHeightVec.y / 2.0f,
                        screenPos.z - screenWidthVec.z / 2.0f - screenHeightVec.z / 2.0f);
    return Math::Rectangle3D(finalPos, screenWidthVec, screenHeightVec);
}

Raytracer::Ray3D Raytracer::Camera::ray(double u, double v)
{
    Math::Point3D screenPoint = screen.pointAt(u, v);
    Math::Vector3D direction(origin, screenPoint);

    direction.normalize();
    return Ray3D(screenPoint, direction);
}
