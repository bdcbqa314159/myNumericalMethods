#ifndef VECTOR_H
#define VECTOR_H

#include "standard.hpp"
#include "testing.hpp"

class Vector
{
private:
    size_t dimension{};
    std::vector<double> data{};

public:
    Vector(){};

    Vector(size_t n) : dimension(n)
    {
        data.resize(n);
    }

    Vector(const std::vector<double> &v) : dimension(v.size()), data(v)
    {
    }

    /*
    Using stl containers and no memory management, allow us to skip:
    Vector(const Vector& rhs);
    Vector &operator=(const Vector& rhs);
    */

    double &operator[](size_t i)
    {
        ASSERT(i < dimension);
        return data[i];
    }

    double const &operator[](size_t i) const
    {
        ASSERT(i < dimension);
        return data[i];
    }

    size_t getSize() const
    {
        return dimension;
    }

    std::vector<double> getData() const
    {
        return data;
    }

    void resize(size_t n)
    {
        dimension = n;
        data.resize(n);
    }
};

void testVector();

#endif