/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ConfigFileError
*/

#ifndef CONFIGFILEERROR_HPP_
    #define CONFIGFILEERROR_HPP_
    #include <iostream>
    #include "Error.hpp"

namespace Errors {
    class ConfigFileError : public Error {
        public:
            ConfigFileError(std::string msg) : _msg(msg) {}
            virtual ~ConfigFileError() = default;
            const char *what() const noexcept override { return _msg.c_str(); }

        private:
            std::string _msg;
    };
}

#endif /* !CONFIGFILEERROR_HPP_ */
