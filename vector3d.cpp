#include "vector3d.h"

#include <cmath>
#include <stdexcept>

#define VECTOR_SIZE 3

Vector3D::Vector3D() : std::valarray<double>(VECTOR_SIZE) 
{
    this->operator[](0) = 0.0;
    this->operator[](1) = 0.0;
    this->operator[](2) = 0.0;
}

Vector3D::Vector3D(const Vector3D& other) : std::valarray<double>(other) {}

Vector3D::Vector3D(std::initializer_list<double> list) : std::valarray<double>(VECTOR_SIZE) 
{
    if (list.size() != VECTOR_SIZE) 
    {
        throw std::invalid_argument("Vector must contain exactly 3 elements.");
    }
    
    const double* data = list.begin();
    
    for (size_t i = 0; i < list.size(); ++i) 
    {
        this->operator[](i) = data[i];
    }
}

Vector3D& Vector3D::operator=(const Vector3D& other)
{
    if (this != &other) 
    {
        std::valarray<double>::operator=(other);
    }
    return *this;
}

Vector3D Vector3D::operator+(const Vector3D& other) const 
{
    return Vector3D(*this) += other;
}

Vector3D Vector3D::operator*(double scalar) const 
{
    Vector3D result(*this);
    for (size_t i = 0; i < VECTOR_SIZE; ++i) 
    {
        result[i] *= scalar;
    }
    return result;
}

Vector3D Vector3D::operator+(double scalar) const 
{
    Vector3D result(*this);
    result[3] += scalar;
    return result;
}

Vector3D& Vector3D::operator+=(const Vector3D& other) 
{
    for (size_t i = 0; i < VECTOR_SIZE; ++i) 
    {
        (*this)[i] += other[i];
    }
    return *this;
}

int Vector3D::norm(int p)
{
    Vector3D vector(*this);

    return std::pow(
        std::pow(std::abs(vector[0]), p) + 
        std::pow(std::abs(vector[1]), p) + 
        std::pow(std::abs(vector[2]), p) ,
        1 / p
    );
}

Vector3D operator * (int scalar, const Vector3D& vector3d) 
{
    return vector3d * (double)scalar;
}

Vector3D operator + (int scalar, const Vector3D& vector3d) 
{
    return vector3d + (double)scalar;
}

std::ostream& operator << (std::ostream& os, const Vector3D& vector3d)
{
    os << "(" << vector3d[0] << ", " << vector3d[1] << ", " << vector3d[2] << ")";
    return os;
}


int main() 
{
    Vector3D u, v{1, 2, 3}, w{v};
    Vector3D z{3 * w};
    z = w;

        // 2 * w = 2 * {1, 2, 3}            = {2,  4,  6}
        // v * 3 = {1, 2, 3} * 3            = {3,  6,  9}
        // {2, 4, 6} + {3, 6, 9}            = {5, 10, 15}

        // z += w = {5, 10, 15} + {1, 2, 3} = {6, 12, 18}

    z = 2 * w + v * 3; 
    z += w;
    cout << z << endl;
    cout << z.norm(2) << endl;

    return 0;
}