/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
    #define SPHERE_HPP_
    #include "RaytracerObjects.hpp"
    #include "Math/Point3D.hpp"
    #include "Math/Ray3D.hpp"
    #include "Color.hpp"
    #include "AShape.hpp"
    #include "ShapeFactory.hpp"

namespace Shapes {
    class Sphere : public AShape {
        public:
            Math::Point3D center;
            double radius;

            Sphere();
            Sphere(const Math::Point3D &point);
            Sphere(const Shapes::ShapeParameters &params);
            Sphere(const Math::Point3D &point, double radius = 0, Color::Rgb color = Color::Rgb(0, 0, 0));
            virtual bool hits(const Raytracer::Ray3D &ray, Math::Point3D &point) override;
            Math::Point3D getOrigin() const override { return center; };
            virtual ~Sphere() = default;
    };
}

#endif /* !SPHERE_HPP_ */
