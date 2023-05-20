/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** AShape
*/

#ifndef ASHAPE_HPP_
    #define ASHAPE_HPP_
    #include "IShape.hpp"

namespace Shapes {
    class AShape : public IShape {
        public:
            virtual Color::Rgb getColor();
            virtual Math::Point3D getOrigin() const = 0;
            virtual ~AShape() = default;

        protected:
            Color::Rgb _color;
    };
}

#endif /* !ASHAPE_HPP_ */
