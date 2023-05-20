/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PPMWriter
*/

#ifndef PPMWRITER_HPP_
    #define PPMWRITER_HPP_
    #include <iostream>
    #include <vector>
    #include "Color.hpp"

class PPMWriter {
    public:
        virtual ~PPMWriter() = default;
        static void writeToPPMFile(const std::string path, std::size_t width, std::size_t height, std::vector<std::vector<Color::Rgb>> colorArray);
};

#endif /* !PPMWRITER_HPP_ */
