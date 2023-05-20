/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** OutOfRangeException
*/

#ifndef OUTOFRANGEEXCEPTION_HPP_
    #define OUTOFRANGEEXCEPTION_HPP_
    #include <iostream>
    #include "Error.hpp"

namespace Errors {
    class OutOfRangeException : public Error {
        public:
            OutOfRangeException(std::string msg) : _msg(msg) {}
            virtual ~OutOfRangeException() = default;
            const char *what() const noexcept override { return _msg.c_str(); }

        private:
            std::string _msg;
    };
}

#endif /* !OUTOFRANGEEXCEPTION_HPP_ */
