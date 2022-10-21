#ifndef CENTRAL_DIFFERENTIATION
#define CENTRAL_DIFFERENTIATION

#include "NumericalDifferentiation.hpp"
#include "mathematics.hpp"

class CentralDifferentiation : public NumericalDifferentiation
{
public:
    CentralDifferentiation() {}
    CentralDifferentiation(unsigned int numberOfPoints) : numberOfPoints(numberOfPoints)
    {
        numericalDerivative.resize(numberOfPoints - 2);
    }

    std::vector<double> approximation(RealFunction &f, double a, double b) override
    {
        std::vector<double> x = linspace(a, b, numberOfPoints);
        double h = (b - a) / (numberOfPoints - 1);

        for (int i = 1; i < numberOfPoints - 1; i++)
        {
            numericalDerivative[i - 1] = 0.5 * (f(x[i + 1]) - f(x[i - 1])) / h;
        }

        return numericalDerivative;
    }

private:
    unsigned int numberOfPoints{100};
    std::vector<double> numericalDerivative{98};
};

void testCentralDifferentiation();

#endif