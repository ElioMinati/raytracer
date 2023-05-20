/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Ray3D
*/

#ifndef RAY3D_HPP_
    #define RAY3D_HPP_
    #include "Math/Point3D.hpp"
    #include "Math/Vector3D.hpp"

namespace Raytracer {
    class Ray3D {
        public:
            Math::Point3D origin;
            Math::Vector3D direction;

            Ray3D();
            Ray3D(const Ray3D &ray);
            Ray3D(Math::Point3D origin, Math::Vector3D direction);
            virtual Ray3D &operator=(const Ray3D &);
            virtual ~Ray3D() = default;
    };
}

#endif /* !RAY3D_HPP_ */
