/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** LightCalculator
*/

#ifndef LIGHTCALCULATOR_HPP_
    #define LIGHTCALCULATOR_HPP_
    #include "Rgb.hpp"
    #include "Shapes.hpp"
    #include "Light.hpp"

namespace Color {

    class LightCalculator {
        private:
            LightCalculator() {};
            ~LightCalculator() {};
        public:
            static Rgb computeLight(Math::Point3D point, Shapes::IShape *shape, Raytracer::Light light, Math::Vector3D cameraRay, std::vector<std::unique_ptr<Shapes::IShape>> *primitives);
    };
}

#endif /* !LIGHTCALCULATOR_HPP_ */
