/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Cone
*/

#ifndef CONE_HPP_
    #define CONE_HPP_
    #include "RaytracerObjects.hpp"
    #include "Math/Point3D.hpp"
    #include "Math/Ray3D.hpp"
    #include "Color.hpp"
    #include "AShape.hpp"
    #include "ShapeFactory.hpp"

namespace Shapes {
    class Cone : public AShape {
        public:
            Math::Point3D center;
            double radius;
            double height;

            Cone();
            Cone(const Math::Point3D &point);
            Cone(const Shapes::ShapeParameters &params);
            Cone(const Math::Point3D &point, double radius = 0, Color::Rgb color = Color::Rgb(0, 0, 0));
            virtual bool hits(const Raytracer::Ray3D &ray, Math::Point3D &point) override;
            Math::Point3D getOrigin() const { return center; };
            virtual ~Cone() = default;
    };
}

#endif /* !CONE_HPP_ */