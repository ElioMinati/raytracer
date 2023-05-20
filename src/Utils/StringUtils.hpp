/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** StringUtils
*/

#ifndef STRINGUTILS_HPP_
    #define STRINGUTILS_HPP_
    #include <iostream>
    #include <vector>

class StringUtils {
    public:
        static std::vector<std::string> splitString(const std::string str, const std::string charsToLookFor);
        static std::vector<std::string> splitStringOnFirstOccurence(const std::string str, const std::string charsToLookFor);
        static std::string replaceAll(std::string str, char toReplace, std::string replaceWith);
        static int countCharacters(const std::string &, char);
};

#endif /* !STRINGUTILS_HPP_ */
