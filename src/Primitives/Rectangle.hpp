/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Rectangle
*/

#ifndef RECTANGLE_HPP_
    #define RECTANGLE_HPP_
    #include "AShape.hpp"
    #include "ShapeFactory.hpp"

namespace Shapes {
    class Rectangle : public AShape {
        public:
            Math::Point3D origin;
            Math::Vector3D bottomSide;
            Math::Vector3D leftSide;
            Math::Vector3D rightSide;
            Math::Point3D lastPointHit;
            bool chessboard = false;

            Rectangle();
            Rectangle(const Rectangle &);
            Rectangle(const Math::Point3D &, const Math::Vector3D &, const Math::Vector3D &, Color::Rgb color = Color::Rgb(0, 0, 0));
            Rectangle(const Shapes::ShapeParameters &params);
            Math::Point3D pointAt(double u, double v);
            virtual Color::Rgb getColor() override;
            Rectangle &operator=(const Rectangle &);
            virtual bool hits(const Raytracer::Ray3D &ray, Math::Point3D &point) override;
            Math::Point3D getOrigin() const { return origin; }
            virtual ~Rectangle() = default;
    };
}

#endif /* !RECTANGLE_HPP_ */
