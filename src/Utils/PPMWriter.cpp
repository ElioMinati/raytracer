/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PPMWriter
*/

#include <fstream>
#include "PPMWriter.hpp"

void PPMWriter::writeToPPMFile(const std::string path, std::size_t width, std::size_t height, std::vector<std::vector<Color::Rgb>> colorArray)
{
    std::ofstream file(path);

    file << "P3" << std::endl;
    file << width << " " << height << std::endl;
    file << "255" << std::endl;
    for (const std::vector<Color::Rgb> &line : colorArray)
        for (const Color::Rgb &color : line)
            file << color.r << " " << color.g << " " << color.b << std::endl;
    file.close();
}
