/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Raytracer
*/

#include <cmath>
#include <vector>
#include "Utils/PPMWriter.hpp"
#include "Raytracer.hpp"
#include "Light.hpp"
#include "CameraBuilder.hpp"
#include "LightBuilder.hpp"
#include "Utils/LightCalculator.hpp"

Raytracer::Core::Core(std::string configFilePath) : _config(configFilePath)
{
    CameraBuilder cameraBuilder;
    LightBuilder lightBuilder;
    int screenWidth = _config.getAttribute<int>("screenWidth");
    int screenHeight = _config.getAttribute<int>("screenHeight");
    Color::Rgb backgroundColor = _config.getRgbForAttribute("backgroundColor");
    std::vector<std::vector<Color::Rgb>> rgbColors {};

    primitives = _config.getShapeArray("primitives");
    cameraBuilder.buildLens(_config.getPointForAttribute("position"), _config.getPointForAttribute("heading"));
    cameraBuilder.buildScreen(screenWidth, screenHeight);
    cameraBuilder.buildFov(_config.getAttribute<int>("fov"));
    _camera = cameraBuilder.getCamera();
    lightBuilder.buildLight(_config.getPointForAttribute("lightPosition"), _config.getRgbForAttribute("lightColor"));
    lightBuilder.buildAmbiantLight(_config.getRgbForAttribute("ambiantLightColor"));
    lightBuilder.buildIntensity(_config.getAttribute<double>("lightPower"));
    _light = lightBuilder.getLight();
    for (double i = 0; i < screenHeight ; i++) {
        rgbColors.push_back({});
        for (double j = 0; j < screenWidth; j++) {
            Ray3D ray = _camera.ray(j / static_cast<double>(screenWidth), i / static_cast<double>(screenHeight));
            Color::Rgb pixelColor(backgroundColor);
            Math::Point3D point;
            for (std::size_t k = 0; k < primitives.size(); k++) {
                pixelColor = (primitives[k]->hits(ray, point) ? (Color::LightCalculator::computeLight(point, primitives[k].get(), _light, Math::Vector3D(ray.origin + ray.direction), &primitives)) : pixelColor);
            }
            rgbColors[static_cast<int>(i)].push_back(pixelColor);
        }
    }
    PPMWriter::writeToPPMFile(_config.getAttribute<std::string>("outputFile"), screenWidth, screenHeight, rgbColors);
}
