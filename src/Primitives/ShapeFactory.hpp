/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ShapeFactory
*/

#ifndef SHAPEFACTORY_HPP_
    #define SHAPEFACTORY_HPP_
    #include <iostream>
    #include <memory>
    #include <functional>
    #include <map>
    #include "IShape.hpp"
    #include "Math/Vector3D.hpp"
    #include "Math/Point3D.hpp"
    #include "Color.hpp"

namespace Shapes {
    class ShapeParameters {
        public:
            ShapeParameters();
            ShapeParameters(Math::Point3D &coords, Color::Rgb &color, double height = 100.0);
            virtual ~ShapeParameters() = default;
            Math::Point3D coords;
            Math::Vector3D leftSide;
            Math::Vector3D bottomSide;
            Math::Vector3D rightSide;
            Color::Rgb color;
            Math::Vector3D rotation;
            std::string texture;
            double radius;
            double height;
    };
    class ShapeFactory {
        public:
            ShapeFactory();
            virtual ~ShapeFactory() = default;
            static std::unique_ptr<Shapes::IShape> createShape(const std::string &shape, const ShapeParameters &params);
    };
}

std::ostream &operator<<(std::ostream &cout, Shapes::ShapeParameters params);

#endif /* !SHAPEFACTORY_HPP_ */
