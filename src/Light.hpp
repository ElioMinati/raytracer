/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Light
*/

#ifndef LIGHT_HPP_
    #define LIGHT_HPP_
    #include <Math.hpp>
    #include "../src/Utils/Rgb.hpp"

namespace Raytracer {
    class Light {
        public:
            Light() {};
            Light(Math::Point3D position, Math::Vector3D heading, Color::Rgb color, Color::Rgb ambiant);
            ~Light();

            Math::Point3D _position;
            Math::Vector3D _heading;
            Color::Rgb _color;
            Color::Rgb _ambiantLight;
            double _intensity = 0.0;
    };
}

#endif /* !LIGHT_HPP_ */
