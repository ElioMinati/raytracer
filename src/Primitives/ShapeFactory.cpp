/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ShapeFactory
*/

#include "ShapeFactory.hpp"
#include "Sphere.hpp"
#include "Cylindre.hpp"
#include "Cone.hpp"
#include "Math/Rectangle3D.hpp"
#include "Rectangle.hpp"

static std::map<std::string, std::function<std::unique_ptr<Shapes::IShape>(Shapes::ShapeParameters)>> generate = {
    {"plane", [](Shapes::ShapeParameters params){ return std::make_unique<Math::Rectangle3D>(params); }},
    {"sphere", [](Shapes::ShapeParameters params){ return std::make_unique<Shapes::Sphere>(params); }},
    {"cylinder", [](Shapes::ShapeParameters params){ return std::make_unique<Shapes::Cylindre>(params); }},
    {"cone", [](Shapes::ShapeParameters params){ return std::make_unique<Shapes::Cone>(params); }},
    {"rectangle", [](Shapes::ShapeParameters params){ return std::make_unique<Shapes::Rectangle>(params);}}
};

Shapes::ShapeParameters::ShapeParameters()
{
}

Shapes::ShapeParameters::ShapeParameters(Math::Point3D &coords, Color::Rgb &color, double height)
{
    this->coords = coords;
    this->color = color;
    this->height = height;
}

Shapes::ShapeFactory::ShapeFactory()
{
}

std::unique_ptr<Shapes::IShape> Shapes::ShapeFactory::createShape(const std::string &shape, const Shapes::ShapeParameters &params)
{
    return generate[shape](params);
}

std::ostream &operator<<(std::ostream &cout, Shapes::ShapeParameters params)
{
    return cout << "\n{\n\tradius: " << params.radius << "\n\tcolor: " << params.color << "\n\tcoords: (" << params.coords.x << ", " << params.coords.y << ", " << params.coords.z << ")\n}" << std::endl;
}
