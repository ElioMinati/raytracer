/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** JsonParser
*/

#ifndef JSONPARSER_HPP_
    #define JSONPARSER_HPP_
    #include <iostream>
    #include <unordered_map>
    #include <sstream>
    #include <vector>
    #include <memory>
    #include "Primitives/Sphere.hpp"
    #include "Math.hpp"
    #include "Color.hpp"
    #include "Errors.hpp"

class ConfigParser {
    private:
        std::unordered_map<std::string, std::string> _configValues;
    public:
        ConfigParser(std::string filePath);
        virtual ~ConfigParser() = default;
        virtual Math::Point3D getPointForAttribute(std::string attribute);
        virtual Color::Rgb getRgbForAttribute(std::string attribute);
        virtual std::string getStringForAttribute(std::string attribute);
        virtual std::vector<std::unique_ptr<Shapes::IShape>> getShapeArray(std::string attribute);
        static std::vector<std::string> trimComments(std::vector<std::string> &fileContent);
        static std::unique_ptr<Shapes::IShape> getPlaneObject(std::unordered_map<std::string, std::string> config, Math::Point3D coords, Color::Rgb color);
        static std::unique_ptr<Shapes::IShape> getSphereObject(std::unordered_map<std::string, std::string> config, Math::Point3D coords, Color::Rgb color);
        static std::unique_ptr<Shapes::IShape> getCylindreObject(std::unordered_map<std::string, std::string> config, Math::Point3D coords, Color::Rgb color);
        static std::unique_ptr<Shapes::IShape> getConeObject(std::unordered_map<std::string, std::string> config, Math::Point3D coords, Color::Rgb color);
        static std::unique_ptr<Shapes::IShape> getRectangleObject(std::unordered_map<std::string, std::string> config, Math::Point3D coords, Color::Rgb color);
        static std::unique_ptr<Shapes::IShape> getShapeFromConfig(std::unordered_map<std::string, std::string>);

        template <typename T>
        T getAttribute(std::string attribute) {
            T retVal;

            if (_configValues.find(attribute) == _configValues.end())
                throw Errors::ConfigFileError(std::string("ERROR: Config attribute '") + attribute + std::string("' not found."));
            std::stringstream ss(_configValues[attribute]);
            ss >> retVal;
            return retVal;
        };
};

#endif /* !JSONPARSER_HPP_ */
