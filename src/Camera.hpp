/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
    #define CAMERA_HPP_
    #include "RaytracerObjects.hpp"
    #include "Math/Point3D.hpp"
    #include "Math/Vector3D.hpp"
    #include "Math/Rectangle3D.hpp"
    #include "Math/Ray3D.hpp"

namespace Raytracer {
    class Camera {
        public:
            Math::Point3D origin;
            Math::Rectangle3D screen;

            Camera();
            Camera(const Math::Point3D &, const Math::Rectangle3D &);
            static Math::Rectangle3D createScreen(const Math::Point3D &position, const Math::Vector3D &heading, int width, int height);
            virtual Ray3D ray(double u, double v);
            virtual ~Camera() = default;

    };
}

#endif /* !CAMERA_HPP_ */
