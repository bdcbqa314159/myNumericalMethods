#ifndef FORWARD_DIFFERENTIATION
#define FORWARD_DIFFERENTIATION

#include "NumericalDifferentiation.hpp"
#include "mathematics.hpp"

class ForwardDifferentiation : public NumericalDifferentiation
{
public:
    ForwardDifferentiation() {}
    ForwardDifferentiation(unsigned int numberOfPoints) : numberOfPoints(numberOfPoints)
    {
        numericalDerivative.resize(numberOfPoints - 1);
    }

    std::vector<double> approximation(RealFunction &f, double a, double b) override
    {
        std::vector<double> x = linspace(a, b, numberOfPoints);
        double h = (b - a) / (numberOfPoints - 1);

        for (int i = 0; i < numberOfPoints - 1; i++)
        {
            numericalDerivative[i] = (f(x[i + 1]) - f(x[i])) / h;
        }

        return numericalDerivative;
    }

private:
    unsigned int numberOfPoints{100};
    std::vector<double> numericalDerivative{99};
};

void testForwardDifferentiation();

#endif