/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Rectangle3D
*/

#ifndef RECTANGLE3D_HPP_
    #define RECTANGLE3D_HPP_
    #include "Color.hpp"
    #include "../Primitives/AShape.hpp"
    #include "Ray3D.hpp"
    #include "Primitives/ShapeFactory.hpp"

namespace Math {
    class Rectangle3D : public Shapes::AShape {
        public:
            Point3D origin;
            Vector3D bottomSide;
            Vector3D leftSide;
            Point3D lastPointHit;
            bool chessboard = false;

            Rectangle3D();
            Rectangle3D(const Rectangle3D &);
            Rectangle3D(const Point3D &, const Vector3D &, const Vector3D &, Color::Rgb color = Color::Rgb(0, 0, 0));
            Rectangle3D(const Shapes::ShapeParameters &params);
            Point3D pointAt(double u, double v);
            virtual Color::Rgb getColor() override;
            Rectangle3D &operator=(const Math::Rectangle3D &);
            virtual bool hits(const Raytracer::Ray3D &ray, Math::Point3D &point) override;
            Point3D getOrigin() const { return origin; }
            virtual ~Rectangle3D() = default;

    };
}

#endif /* !RECTANGLE3D_HPP_ */
