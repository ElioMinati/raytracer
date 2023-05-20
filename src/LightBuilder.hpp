/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** LightBuilder
*/

#ifndef LIGHTBUILDER_HPP_
    #define LIGHTBUILDER_HPP_
    #include "Light.hpp"

namespace Raytracer {

    class LightBuilder {
        public:
            LightBuilder();
            virtual Light getLight() const { return _light; };
            virtual void buildLight(const Math::Point3D &position, Color::Rgb color);
            virtual void buildAmbiantLight(Color::Rgb color);
            virtual void buildIntensity(double intensity);
            virtual ~LightBuilder() = default;
        private:
            Light _light;
    };
}

#endif /* !LIGHTBUILDER_HPP_ */
