#ifndef MATRIX_H
#define MATRIX_H

#include "standard.hpp"
#include "testing.hpp"

class Matrix
{
private:
    size_t dimLines{}, dimColumns{};
    std::vector<double> data{};

public:
    Matrix(){};

    Matrix(size_t m, size_t n) : dimLines(m), dimColumns(n)
    {
        data.resize(dimLines * dimColumns);
    }

    Matrix(const std::vector<std::vector<double>> &m) : dimLines(m.size()), dimColumns(m[0].size())
    {
        data.resize(dimLines * dimColumns);
        for (int i = 0; i < dimLines; i++)
        {
            for (int j = 0; j < dimColumns; j++)
            {
                data[i * dimColumns + j] = m[i][j];
            }
        }
    }

    // /*
    // Using stl containers and no memory management, allow us to skip:
    // Vector(const Vector& rhs);
    // Vector &operator=(const Vector& rhs);
    // */

    double &operator()(size_t i, size_t j)
    {
        ASSERT(i < dimLines && j < dimColumns);
        return data[i * dimColumns + j];
    }

    double const &operator()(size_t i, size_t j) const
    {
        ASSERT(i < dimLines && j < dimColumns);
        return data[i * dimColumns + j];
    }

    size_t getDimLines() const
    {
        return dimLines;
    }

    size_t getDimColumns() const
    {
        return dimColumns;
    }

    std::vector<double> getData() const
    {
        return data;
    }

    void resize(size_t m, size_t n)
    {
        dimLines = m;
        dimColumns = n;

        data = std::vector<double>(dimLines * dimColumns);
    }
};

void testMatrix();

#endif