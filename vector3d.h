#pragma once

#ifndef VECTOR_3D
#define VECTOR_3D

#include <ostream>
#include <valarray>
#include <initializer_list>

struct Vector3D : std::valarray<double> 
{
    Vector3D();
    Vector3D(const Vector3D& other);
    Vector3D(std::initializer_list<double> list);

    Vector3D&   operator += (const Vector3D& other);
    Vector3D&   operator =  (const Vector3D& other);
    Vector3D    operator +  (const Vector3D& other)    const;
    Vector3D    operator *  (double scalar)            const;
    Vector3D    operator +  (double scalar)            const;

    int         norm(int p);
};

Vector3D        operator *  (int scalar,        const Vector3D& vector3d);
Vector3D        operator +  (int scalar,        const Vector3D& vector3d);
std::ostream&   operator << (std::ostream& os,  const Vector3D& vector3d);

#endif // VECTOR_3D