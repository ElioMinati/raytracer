/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IShape
*/

#ifndef ISHAPE_HPP_
    #define ISHAPE_HPP_
    #include "Math/Ray3D.hpp"
    #include "Color.hpp"

namespace Shapes {
    class IShape {
        public:
            virtual bool hits(const Raytracer::Ray3D &ray, Math::Point3D &point) = 0;
            virtual Color::Rgb getColor() = 0;
            virtual Math::Point3D getOrigin() const = 0;
            virtual ~IShape() = default;
    };
}

#endif /* !ISHAPE_HPP_ */
