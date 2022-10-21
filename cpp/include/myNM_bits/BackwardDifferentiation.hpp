#ifndef BACKWARD_DIFFERENTIATION
#define BACKWARD_DIFFERENTIATION

#include "NumericalDifferentiation.hpp"
#include "mathematics.hpp"

class BackwardDifferentiation : public NumericalDifferentiation
{
public:
    BackwardDifferentiation() {}
    BackwardDifferentiation(unsigned int numberOfPoints) : numberOfPoints(numberOfPoints)
    {
        numericalDerivative.resize(numberOfPoints - 1);
    }

    std::vector<double> approximation(RealFunction &f, double a, double b) override
    {
        std::vector<double> x = linspace(a, b, numberOfPoints);
        double h = (b - a) / (numberOfPoints - 1);

        for (int i = 1; i < numberOfPoints; i++)
        {
            numericalDerivative[i - 1] = (f(x[i]) - f(x[i - 1])) / h;
        }

        return numericalDerivative;
    }

private:
    unsigned int numberOfPoints{100};
    std::vector<double> numericalDerivative{99};
};

void testBackwardDifferentiation();

#endif