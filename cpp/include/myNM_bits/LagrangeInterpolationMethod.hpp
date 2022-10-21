#ifndef LAGRANGE_INTERPOLATION_METHOD
#define LAGRANGE_INTERPOLATION_METHOD

#include "standard.hpp"
#include "testing.hpp"

class LagrangeInterpolationMethod
{
public:
    LagrangeInterpolationMethod() {}

    LagrangeInterpolationMethod(std::vector<double> x, std::vector<double> y) : x(x), y(y)
    {
        ASSERT(x.size() == y.size());
        nPoints = x.size();
    }

    double operator()(double t)
    {
        double z{};
        for (int i = 1; i <= nPoints; i++)
        {
            double p{1.};
            for (int j = 1; j <= nPoints; j++)
            {
                if (i != j)
                {
                    p *= (t - x[j]) / (x[i] - x[j]);
                }
            }
            z += p * y[i];
        }
        return z;
    }

private:
    unsigned int nPoints{5};
    std::vector<double> x{std::vector<double>(nPoints)}, y{std::vector<double>(nPoints)};
};

void testLagrangeInterpolationMethod();

#endif