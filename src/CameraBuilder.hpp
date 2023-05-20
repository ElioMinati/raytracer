/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CameraBuilder
*/

#ifndef CAMERABUILDER_HPP_
    #define CAMERABUILDER_HPP_
    #include "Camera.hpp"

namespace Raytracer {
    class CameraBuilder {
        public:
            CameraBuilder();
            virtual Camera getCamera();
            virtual void buildLens(const Math::Point3D &position, const Math::Vector3D &rotation);
            virtual void buildScreen(const int width, const int height);
            virtual void buildFov(const int fov);
            virtual ~CameraBuilder() = default;
        
        private:
            Camera _camera;
            int _cameraWidth;
            int _cameraHeight;
            Math::Vector3D cameraHeading;

    };
}

#endif /* !CAMERABUILDER_HPP_ */
