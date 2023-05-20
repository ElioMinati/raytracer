/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Rgb
*/

#include "Rgb.hpp"

Color::Rgb::Rgb() : r(0), g(0), b(0)
{
}

Color::Rgb::Rgb(const Rgb &rgbObject) : r(rgbObject.r), g(rgbObject.g), b(rgbObject.b)
{
}

Color::Rgb &Color::Rgb::operator=(const Rgb &color)
{
    this->r = color.r;
    this->g = color.g;
    this->b = color.b;
    return *this;
}

bool Color::Rgb::operator==(const Rgb &color)
{
    if (this->r == color.r && this->g == color.g && this->b == color.b)
        return true;
    return false;
}

Color::Rgb::Rgb(std::size_t r, std::size_t g, std::size_t b) : r(r), g(g), b(b)
{
}

std::ostream &operator<<(std::ostream &cout, Color::Rgb color)
{
    return cout << "(" << color.r << "," << color.g << "," << color.b << ")";
}
