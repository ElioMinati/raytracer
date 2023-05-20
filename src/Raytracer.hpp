/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Raytracer
*/

#ifndef RAYTRACER_HPP_
    #define RAYTRACER_HPP_
    #include <vector>
    #include "Utils/ConfigParser.hpp"
    #include "Math/Point3D.hpp"
    #include "Math/Vector3D.hpp"
    #include "Math/Rectangle3D.hpp"
    #include "Primitives/IShape.hpp"
    #include "Camera.hpp"
    #include "Light.hpp"

namespace Raytracer {
    class Core {
        public:
            Core(std::string configFilePath);
            virtual ~Core() = default;

        private:
            ConfigParser _config;
            Camera _camera;
            Light _light;
            Math::Point3D _postition;
            Math::Point3D _heading;
            Math::Rectangle3D _screen;
            std::vector<std::unique_ptr<Shapes::IShape>> primitives {};
    };
}

#endif /* !RAYTRACER_HPP_ */
