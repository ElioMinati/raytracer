/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Cylindre
*/

#ifndef CYLINDRE_HPP_
    #define CYLINDRE_HPP_
    #include "AShape.hpp"
    #include "RaytracerObjects.hpp"
    #include "Math/Point3D.hpp"
    #include "Math/Ray3D.hpp"
    #include "Color.hpp"

namespace Shapes {
    class Cylindre : public AShape {
        public:
            Math::Point3D center;
            double radius;
            Math::Vector3D height;

            Cylindre();
            Cylindre(const Math::Point3D &point);
            Cylindre(const Shapes::ShapeParameters &params);
            Cylindre(const Math::Point3D &point, Math::Vector3D height = Math::Vector3D(0, 100, 0), double radius = 0, Color::Rgb color = Color::Rgb(0, 0, 0));
            bool hits(const Raytracer::Ray3D &ray, Math::Point3D &point) override;
            Math::Point3D getOrigin() const { return center; };
            ~Cylindre() = default;
    };
}

#endif /* !CYLINDRE_HPP_ */
