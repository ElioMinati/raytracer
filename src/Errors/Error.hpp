/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Error
*/

#ifndef ERROR_HPP_
    #define ERROR_HPP_
    #include <exception>

namespace Errors {
    class Error : public std::exception {
        public:
            Error() {};
            virtual ~Error() = default;
            const char *what() const noexcept = 0;
    };
}

#endif /* !ERROR_HPP_ */
