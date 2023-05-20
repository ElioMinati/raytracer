/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Vector3D
*/

#ifndef VECTOR3D_HPP_
    #define VECTOR3D_HPP_
    #include <ostream>
    #include "Point3D.hpp"

namespace Math {
    class Point3D;
    class Vector3D {
        public:
            double x;
            double y;
            double z;

            Vector3D();
            Vector3D(double, double, double);
            Vector3D(const Vector3D &vector);
            Vector3D(const Point3D &p1);
            Vector3D(const Point3D &p1, const Point3D &p2);
            static Vector3D getDirectionVector(const Vector3D &, const Vector3D &);
            static Vector3D getParallelVector(const Vector3D &vector, double len);
            virtual ~Vector3D() = default;
            virtual Vector3D &operator+=(const Vector3D &);
            virtual Vector3D &operator-=(const Vector3D &);
            virtual Vector3D &operator*=(const Vector3D &);
            virtual Vector3D &operator/=(const Vector3D &);
            virtual Vector3D operator+(const Vector3D &) const;
            virtual Vector3D operator-(const Vector3D &);
            virtual Vector3D operator*(const Vector3D &);
            virtual Vector3D operator*(const double &) const;
            virtual Vector3D operator/(const Vector3D &);
            virtual Vector3D &operator=(const Vector3D &);
            virtual Vector3D &rotate(const Math::Vector3D &axis, double angle);
            virtual bool operator==(const Vector3D &);
            virtual double length() const;
            virtual Vector3D &normalize();
            virtual double dot(const Math::Vector3D &) const;
            virtual Vector3D cross(const Vector3D &vector) const;
        protected:
    };
}

std::ostream& operator<<(std::ostream& os, const Math::Vector3D &vector);

#endif /* !VECTOR3D_HPP_ */
