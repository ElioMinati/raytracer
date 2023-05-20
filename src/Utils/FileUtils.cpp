/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** FileUtils
*/


#include <fstream>
#include <cctype>
#include "FileUtils.hpp"

FileUtils::FileUtils()
{
}

bool FileUtils::FileExists(const std::string filepath)
{
    std::ifstream file(filepath.c_str());

    return file.good();
}

std::string FileUtils::readFromFile(std::string filepath)
{
    std::ifstream fileStream(filepath.c_str());
    std::string fileContent = "";
    char c;

    while (!fileStream.eof() && (c = fileStream.get()) != fileStream.eof())
        fileContent.push_back(c);
    return fileContent;
}

std::vector<std::string> FileUtils::readFromFileToVector(std::string filepath)
{
    int inArray = 0;
    std::ifstream fileStream(filepath.c_str());
    std::string fileContent = "";
    std::vector<std::string> destVector = {};
    char c;

    while (!fileStream.eof() && (c = fileStream.get()) != fileStream.eof()) {
        if (c == '[')
            inArray++;
        if (c == ']')
            inArray--;
        if (inArray == 0 && c == '\n' && !fileContent.empty()) {
            destVector.push_back(fileContent);
            fileContent = "";
            continue;
        }
        fileContent.push_back(c);
        if (inArray == 0 && c == '\n') {
            fileContent = "";
            continue;
        }
    }
    if (!fileContent.empty() && std::isprint(fileContent[0]))
        destVector.push_back(fileContent);
    return destVector;
}

FileUtils::~FileUtils()
{
}
