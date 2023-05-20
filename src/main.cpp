/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** main
*/

#include "GlobalVars.hpp"
#include "Errors.hpp"
#include "Raytracer.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "ERROR: Invalid Arguments" << std::endl;
        return EXIT_RAYTRACER_FAILURE;
    }
    if (std::string(argv[1]) == "--help") {
        printf("USAGE: ./raytracer <SCENE_FILE>\n  SCENE_FILE: scene configuration\n");
        return EXIT_SUCCESS;
    }
    try {
        Raytracer::Core(std::string(argv[1]));
    } catch (const Errors::ConfigFileError &err) {
        std::cerr << err.what() << std::endl;
        return EXIT_RAYTRACER_FAILURE;
    }
    return EXIT_SUCCESS;
}