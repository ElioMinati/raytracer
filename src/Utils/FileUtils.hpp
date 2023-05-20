/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** FileUtils
*/

#ifndef FILEUTILS_HPP_
    #define FILEUTILS_HPP_
    #include <iostream>
    #include <vector>

class FileUtils {
    public:
        FileUtils();
        ~FileUtils();
        static bool FileExists(std::string filename);
        static std::string readFromFile(std::string filename);
        static std::vector<std::string> readDirectory(std::string dirpath);
        static std::vector<std::string> readFromFileToVector(std::string filename);
};

#endif /* !FILEUTILS_HPP_ */
