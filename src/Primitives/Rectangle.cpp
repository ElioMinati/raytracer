/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Rectangle
*/

#include "Rectangle.hpp"
#include "Errors.hpp"

// return self.x ** 2 + self.y ** 2 + self.z ** 2

Shapes::Rectangle::Rectangle()
{
    _color = Color::Rgb(0, 0, 0);
}

Color::Rgb Shapes::Rectangle::getColor()
{   
    double tile_width = bottomSide.length() / (bottomSide.length() / 100);
    double tile_height = leftSide.length() / (bottomSide.length() / 100);
    if (this->chessboard and lastPointHit.initialized) {
        Math::Vector3D normalized_bottomSide(bottomSide);
        Math::Vector3D normalized_leftSide(leftSide);

        normalized_bottomSide.normalize();
        normalized_leftSide.normalize();
        double distance_left = Math::Vector3D(origin, lastPointHit).dot(normalized_bottomSide) / normalized_bottomSide.dot(normalized_bottomSide);
        double distance_up = Math::Vector3D(origin, lastPointHit).dot(normalized_leftSide) / normalized_leftSide.dot(normalized_leftSide);
        int tile_x = static_cast<int>(distance_left / tile_width);
        int tile_y = static_cast<int>(distance_up / tile_height);
        if ((tile_x + tile_y) % 2 == 0)
            return Color::Rgb(0, 0, 0);
    }
    return _color;
}

Shapes::Rectangle::Rectangle(const Rectangle &rect) : origin(rect.origin), bottomSide(rect.bottomSide), leftSide(rect.leftSide)
{
    _color = Color::Rgb(0, 0, 0);
}

Shapes::Rectangle::Rectangle(const Math::Point3D &point, const Math::Vector3D &bottomSide, const Math::Vector3D &leftSide, Color::Rgb color) : origin(point), bottomSide(bottomSide), leftSide(leftSide)
{
    _color = color;
}

Shapes::Rectangle::Rectangle(const Shapes::ShapeParameters &params) : origin(params.coords), bottomSide(params.bottomSide), leftSide(params.leftSide), rightSide(params.rightSide)
{
    _color = params.color;
    if (params.rotation.length() > 0) {
        bottomSide.rotate(Math::Vector3D(1, 0, 0), params.rotation.x);
        leftSide.rotate(Math::Vector3D(1, 0, 0), params.rotation.x);
        bottomSide.rotate(Math::Vector3D(0, 1, 0), params.rotation.y);
        leftSide.rotate(Math::Vector3D(0, 1, 0), params.rotation.y);
        bottomSide.rotate(Math::Vector3D(0, 0, 1), params.rotation.z);
        leftSide.rotate(Math::Vector3D(0, 0, 1), params.rotation.z);
    }
    if (!params.texture.empty() && params.texture == "chessboard") {
        chessboard = true;
    }
}

bool Shapes::Rectangle::hits(const Raytracer::Ray3D &ray, Math::Point3D &point)
{
    // Math::Vector3D planeNormal = this->bottomSide.cross(this->leftSide);
    // double d = 0;
    // double res = 0;

    // planeNormal.normalize();
    // d = planeNormal.dot(ray.direction);
    // if (std::abs(d) < 0.0001) {
    //     return false;
    // }
    // res = planeNormal.dot(this->origin - ray.origin) / d;
    // if (res < 0) {
    //     return false;
    // }

    // Math::Point3D tmpPoint = ray.origin + ray.direction * res;
    // if (point.initialized && Math::Vector3D(ray.origin, point).length() > Math::Vector3D(ray.origin, tmpPoint).length()) {
    //     point = tmpPoint;
    //     lastPointHit = point;
    //     return true;
    // } else if (!point.initialized) {
    //     point = tmpPoint;
    //     lastPointHit = point;
    //     return true;
    // }
    // return false;

    Math::Vector3D planeNormal = this->bottomSide.cross(this->leftSide);
    double d = 0;
    double res = 0;

    planeNormal.normalize();
    d = planeNormal.dot(ray.direction);
    if (std::abs(d) < 0.0001) {
        return false;
    }
    res = planeNormal.dot(this->origin - ray.origin) / d;
    if (res < 0) {
        return false;
    }

    Math::Point3D tmpPoint = ray.origin + ray.direction * res;

    Math::Vector3D v1 = tmpPoint - this->origin;
    double dot1 = v1.dot(this->leftSide);
    if (dot1 < 0 || dot1 > this->leftSide.length()) {
        return false;
    }
    Math::Vector3D v2 = tmpPoint - this->origin;
    double dot2 = v2.dot(this->bottomSide);
    if (dot2 < 0 || dot2 > this->bottomSide.length()) {
        return false;
    }

    point = tmpPoint;
    return true;
}

Math::Point3D Shapes::Rectangle::pointAt(double u, double v)
{
    Math::Vector3D dest;

    if (u < 0 || u > 1 || v < 0 || v > 1)
        throw Errors::OutOfRangeException("ERROR: retrieving pointAt rectangle, u & v must be in range [0, 1].");
    dest.x = u * bottomSide.x + v * leftSide.x;
    dest.y = u * bottomSide.y + v * leftSide.y;
    dest.z = u * bottomSide.z + v * leftSide.z;
    return origin + dest;
}

Shapes::Rectangle &Shapes::Rectangle::operator=(const Shapes::Rectangle &rect)
{
    this->origin = rect.origin;
    this->leftSide = rect.leftSide;
    this->bottomSide = rect.bottomSide;
    return *this;
}
