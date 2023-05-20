/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** vector3D
*/

#ifndef POINT3D_HPP_
    #define POINT3D_HPP_
    #include <ostream>
    #include "Vector3D.hpp"

namespace Math {
    class Vector3D;
    class Point3D {
        public:
            double x;
            double y;
            double z;
            bool initialized = false;

            Point3D();
            Point3D(const Point3D &);
            Point3D(double x, double y, double z);
            virtual Point3D &operator+=(const Point3D &);
            virtual Point3D &operator+=(const Vector3D &);
            virtual Point3D &operator-=(const Vector3D &);
            virtual Point3D &operator-=(const Point3D &);
            virtual Point3D &operator*=(const Point3D &);
            virtual Point3D &operator/=(const Point3D &);
            virtual Point3D operator+(const Point3D &);
            virtual Point3D operator+(const Vector3D &) const;
            virtual Point3D operator-(const Point3D &);
            virtual Point3D operator-(const Point3D &) const;
            virtual Point3D operator-(const Vector3D &vec) const;
            virtual Point3D operator*(const Point3D &);
            virtual Point3D operator/(const Point3D &);
            virtual Point3D &operator=(const Point3D &);
            virtual Point3D &operator=(const Vector3D &);
            virtual bool operator==(const Point3D &);
            virtual ~Point3D() = default;
        protected:
    };
}

std::ostream& operator<<(std::ostream& os, const Math::Point3D &point);

#endif /* !POINT3D_HPP_ */
