/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Rgb
*/

#ifndef RGB_HPP_
    #define RGB_HPP_
    #include <iostream>

namespace Color {
    class Rgb {
        public:
            std::size_t r;
            std::size_t g;
            std::size_t b;

            Rgb();
            Rgb(const Rgb &);
            Rgb(std::size_t, std::size_t, std::size_t);
            virtual bool operator==(const Rgb &);
            virtual Rgb &operator=(const Rgb &);
            virtual ~Rgb() = default;

    };
}

std::ostream &operator<<(std::ostream &cout, Color::Rgb color);

#endif /* !RGB_HPP_ */
