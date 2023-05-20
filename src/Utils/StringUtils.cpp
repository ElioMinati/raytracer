/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** StringUtils
*/

#include "StringUtils.hpp"

std::vector<std::string> StringUtils::splitString(const std::string str, const std::string charsToLookFor)
{
    std::string tmpString = "";
    std::vector<std::string> destVector = {};

    for (const char &c : str) {
        if (charsToLookFor.find(c) == std::string::npos)
            tmpString.push_back(c);
        else {
            destVector.push_back(tmpString);
            tmpString = "";
        }
    }
    if (!tmpString.empty())
        destVector.push_back(tmpString);
    return destVector;
}

std::string StringUtils::replaceAll(std::string str, char toReplace, std::string replaceWith)
{
    std::string dest = "";

    for (const char &c : str) {
        if (c == toReplace) {
            for (const char &cr : replaceWith)
                dest.push_back(cr);
            continue;
        }
        dest.push_back(c);
    }
    return dest;
}

std::vector<std::string> StringUtils::splitStringOnFirstOccurence(const std::string str, const std::string charsToLookFor)
{
    bool split = false;
    std::string tmpString = "";
    std::vector<std::string> destVector = {};

    for (const char &c : str) {
        if (charsToLookFor.find(c) == std::string::npos || split)
            tmpString.push_back(c);
        else {
            destVector.push_back(tmpString);
            tmpString = "";
            split = true;
        }
    }
    if (!tmpString.empty())
        destVector.push_back(tmpString);
    return destVector;
}

int StringUtils::countCharacters(const std::string &str, char c)
{
    int counter = 0;

    for (const char &ch : str)
        counter += (ch == c ? 1 : 0);
    return counter;
}
