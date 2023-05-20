/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** JsonParser
*/

#include <fstream>
#include "GlobalVars.hpp"
#include "ConfigParser.hpp"
#include "FileUtils.hpp"
#include "StringUtils.hpp"
#include "Primitives/ShapeFactory.hpp"

ConfigParser::ConfigParser(std::string filePath)
{
    std::vector<std::string> fileContent {};
    std::vector<std::string> tmpKeyVal {};
    std::string tmp_val = "";

    if (!FileUtils::FileExists(filePath))
        throw Errors::ConfigFileError(std::string("ERROR: File '") + filePath + std::string("' not found."));
    fileContent = FileUtils::readFromFileToVector(filePath);
    fileContent = ConfigParser::trimComments(fileContent);
    for (std::string &line : fileContent) {
        line = StringUtils::replaceAll(line, ' ', "");
        tmpKeyVal = StringUtils::splitStringOnFirstOccurence(line, "=");
        if (StringUtils::countCharacters(line, '=') != 1 && StringUtils::countCharacters(line, '[') == 0 && StringUtils::countCharacters(line, '{') == 0)
            throw Errors::ConfigFileError(std::string("ERROR: Invalid format for Config file.\nInvalid format for line '") + line + "'.");
        _configValues[tmpKeyVal[0]] = tmpKeyVal[1];
    }
}

std::vector<std::string> ConfigParser::trimComments(std::vector<std::string> &fileContent)
{
    std::string tmpLine = "";
    std::vector<std::string> newContent {};

    for (const std::string &line : fileContent) {
        if (line[0] == COMMENT_CHAR)
            continue;
        for (const char &c: line) {
            if (c == COMMENT_CHAR) {
                break;
            }
            tmpLine.push_back(c);
        }
        newContent.push_back(tmpLine);
        tmpLine = "";
    }
    fileContent = newContent;
    return newContent;
}

std::string ConfigParser::getStringForAttribute(std::string attribute)
{
    if (_configValues.find(attribute) == _configValues.end())
        throw Errors::ConfigFileError(std::string("ERROR: Config attribute '") + attribute + std::string("' not found."));
    return _configValues[attribute];
}

std::unique_ptr<Shapes::IShape> ConfigParser::getPlaneObject(std::unordered_map<std::string, std::string> config, Math::Point3D coords, Color::Rgb color)
{
    if (config.find("width") == config.end())
        throw Errors::ConfigFileError("ERROR: Plane object must have 'width' attribute");
    if (config.find("length") == config.end())
        throw Errors::ConfigFileError("ERROR: Plane object must have 'length' attribute");
    Math::Vector3D bottomSide(stod(config["width"]), 0, 0);
    Math::Vector3D leftSide(0, 0, stod(config["length"]));
    Shapes::ShapeParameters params(coords, color);
    std::vector<std::string> rot;

    params.bottomSide = bottomSide;
    params.leftSide = leftSide;
    if (config.find("rot") != config.end()) {
        rot = StringUtils::splitString(config["rot"], ",");
        params.rotation = Math::Vector3D(std::stod(rot[0]), std::stod(rot[1]), std::stod(rot[2]));
    }
    if (config.find("texture") != config.end()) {
        params.texture = config["texture"];
    }
    return Shapes::ShapeFactory::createShape("plane", params);
}

std::unique_ptr<Shapes::IShape> ConfigParser::getSphereObject(std::unordered_map<std::string, std::string> config, Math::Point3D coords, Color::Rgb color)
{
    if (config.find("radius") == config.end())
            throw Errors::ConfigFileError("ERROR: Sphere object must have 'radius' attribute");
    Shapes::ShapeParameters params(coords, color);
    std::vector<std::string> rot;

    if (config.find("rot") != config.end()) {
        rot = StringUtils::splitString(config["rot"], ",");
        params.rotation = Math::Vector3D(std::stod(rot[0]), std::stod(rot[1]), std::stod(rot[2]));
    }
    params.radius = stod(config["radius"]);
    return Shapes::ShapeFactory::createShape("sphere", params);
}

std::unique_ptr<Shapes::IShape> ConfigParser::getCylindreObject(std::unordered_map<std::string, std::string> config, Math::Point3D coords, Color::Rgb color)
{
    if (config.find("radius") == config.end())
            throw Errors::ConfigFileError("ERROR: Cylindre object must have 'radius' attribute");
    if (config.find("height") == config.end())
        throw Errors::ConfigFileError("ERROR: Cylindre object must have 'length' attribute");
    Shapes::ShapeParameters params(coords, color);
    std::vector<std::string> rot;

    if (config.find("rot") != config.end()) {
        rot = StringUtils::splitString(config["rot"], ",");
        params.rotation = Math::Vector3D(std::stod(rot[0]), std::stod(rot[1]), std::stod(rot[2]));
    }
    params.radius = stod(config["radius"]);
    params.height = stod(config["height"]);
    return Shapes::ShapeFactory::createShape("cylinder", params);
}

std::unique_ptr<Shapes::IShape> ConfigParser::getConeObject(std::unordered_map<std::string, std::string> config, Math::Point3D coords, Color::Rgb color)
{
    if (config.find("radius") == config.end())
            throw Errors::ConfigFileError("ERROR: Cone object must have 'radius' attribute");
    if (config.find("height") == config.end())
        throw Errors::ConfigFileError("ERROR: Cone object must have 'length' attribute");
    Shapes::ShapeParameters params(coords, color);
    std::vector<std::string> rot;

    if (config.find("rot") != config.end()) {
        rot = StringUtils::splitString(config["rot"], ",");
        params.rotation = Math::Vector3D(std::stod(rot[0]), std::stod(rot[1]), std::stod(rot[2]));
    }
    params.radius = stod(config["radius"]);
    params.height = stod(config["height"]);
    return Shapes::ShapeFactory::createShape("cone", params);
}

std::unique_ptr<Shapes::IShape> ConfigParser::getRectangleObject(std::unordered_map<std::string, std::string> config, Math::Point3D coords, Color::Rgb color)
{
    if (config.find("width") == config.end())
        throw Errors::ConfigFileError("ERROR: Rectangle object must have 'width' attribute");
    if (config.find("length") == config.end())
        throw Errors::ConfigFileError("ERROR: Rectangle object must have 'length' attribute");
    Math::Vector3D bottomSide(stod(config["width"]), 0, 0);
    Math::Vector3D leftSide(0, 0, stod(config["length"]));
    Math::Vector3D rightSide(0, stod(config["depth"]), 0);
    Shapes::ShapeParameters params(coords, color);
    std::vector<std::string> rot;

    params.bottomSide = bottomSide;
    params.leftSide = leftSide;
    params.rightSide = rightSide;
    if (config.find("rot") != config.end()) {
        rot = StringUtils::splitString(config["rot"], ",");
        params.rotation = Math::Vector3D(std::stod(rot[0]), std::stod(rot[1]), std::stod(rot[2]));
    }
    if (config.find("texture") != config.end()) {
        params.texture = config["texture"];
    }
    return Shapes::ShapeFactory::createShape("rectangle", params);
}

std::unique_ptr<Shapes::IShape> ConfigParser::getShapeFromConfig(std::unordered_map<std::string, std::string> config)
{
    Math::Point3D coords;
    Color::Rgb color;
    std::vector<std::string> rawValues {};

    if (config.find("type") == config.end())
        throw Errors::ConfigFileError("ERROR: Shape object must have 'type' attribute '");
    if (config.find("coords") == config.end())
        throw Errors::ConfigFileError("ERROR: Shape object must have 'coords' attribute '");
    if (config.find("color") == config.end())
        config["color"] = "255,255,255";
    rawValues = StringUtils::splitString(config["coords"], ",");
    if (rawValues.size() != 3)
        throw Errors::ConfigFileError(std::string("ERROR: Invalid format for coords: '") + config["coords"] + std::string("'."));
    coords = Math::Point3D(std::stod(rawValues[0]), std::stod(rawValues[1]), std::stod(rawValues[2]));
    rawValues = StringUtils::splitString(config["color"], ",");
    if (rawValues.size() != 3)
        throw Errors::ConfigFileError(std::string("ERROR: Invalid format for color: '") + config["color"] + std::string("'."));
    color = Color::Rgb(std::stoi(rawValues[0]), std::stoi(rawValues[1]), std::stoi(rawValues[2]));
    if (config["type"] == "sphere")
        return getSphereObject(config, coords, color);
    if (config["type"] == "plane")
        return getPlaneObject(config, coords, color);
    if (config["type"] == "cylinder")
        return getCylindreObject(config, coords, color);
    if (config["type"] == "cone")
        return getConeObject(config, coords, color);
    if (config["type"] == "rectangle")
        return getRectangleObject(config, coords, color);
    return nullptr;
}

std::vector<std::unique_ptr<Shapes::IShape>> ConfigParser::getShapeArray(std::string attribute)
{
    std::vector<std::unique_ptr<Shapes::IShape>> shapeArray {};
    std::vector<std::string> shapes {};
    std::vector<std::string> tmpLines {};
    std::vector<std::string> tmpKeyVal {};
    std::unordered_map<std::string, std::string> objectKeyVals {};

    if (_configValues.find(attribute) == _configValues.end())
        throw Errors::ConfigFileError(std::string("ERROR: Config attribute '") + attribute + std::string("' not found."));
    if (StringUtils::countCharacters(_configValues[attribute], '[') == 0 || StringUtils::countCharacters(_configValues[attribute], ']') == 0)
        throw Errors::ConfigFileError(std::string("ERROR: Shape array '") + attribute + std::string("' must be an array of shapes."));
    shapes = StringUtils::splitString(_configValues[attribute], "{}");
    for (const std::string &rawShape : shapes) {
        if (StringUtils::countCharacters(rawShape, '=') == 0)
            continue;
        tmpLines = StringUtils::splitString(rawShape, "\n");
        for (std::string &line : tmpLines) {
            if (StringUtils::countCharacters(line, '=') == 0)
                continue;
            line = StringUtils::replaceAll(line, ' ', "");
            tmpKeyVal = StringUtils::splitString(line, "=");
            objectKeyVals[tmpKeyVal[0]] = tmpKeyVal[1];
        }
        shapeArray.push_back(std::unique_ptr<Shapes::IShape>(ConfigParser::getShapeFromConfig(objectKeyVals)));
    }
    return shapeArray;
}

Color::Rgb ConfigParser::getRgbForAttribute(std::string attribute)
{
    std::vector<std::string> rgbRawValues {};

    if (_configValues.find(attribute) == _configValues.end())
        throw Errors::ConfigFileError(std::string("ERROR: Config attribute '") + attribute + std::string("' not found."));
    
    rgbRawValues = StringUtils::splitString(_configValues[attribute], ",");

    return Color::Rgb(std::stoi(rgbRawValues[0]), std::stoi(rgbRawValues[1]), std::stoi(rgbRawValues[2]));
}

Math::Point3D ConfigParser::getPointForAttribute(std::string attribute)
{
    std::vector<std::string> pointRawValues {};

    if (_configValues.find(attribute) == _configValues.end())
        throw Errors::ConfigFileError(std::string("ERROR: Config attribute '") + attribute + std::string("' not found."));
    
    pointRawValues = StringUtils::splitString(_configValues[attribute], ",");

    return Math::Point3D(std::stod(pointRawValues[0]), std::stod(pointRawValues[1]), std::stod(pointRawValues[2]));
}
