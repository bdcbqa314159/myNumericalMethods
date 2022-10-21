#ifndef POLYNOMIAL_FITTING_METHOD
#define POLYNOMIAL_FITTING_METHOD

#include "standard.hpp"
#include "testing.hpp"

class PolynomialFittingMethod
{
public:
    PolynomialFittingMethod() {}

    PolynomialFittingMethod(std::vector<double> x, std::vector<double> y) : x(x), y(y)
    {
        ASSERT(x.size() == y.size());
        nPoints = x.size();
    }

    void operator()()
    {
        double sumX{}, sumX2{}, sumY{}, sumXY{};
        for (int i = 0; i < nPoints; i++)
        {
            sumX += std::log(x[i]);
            sumY += std::log(y[i]);
            sumXY += std::log(x[i]) * std::log(y[i]);
            sumX2 += std::log(x[i]) * std::log(x[i]);
        }

        b = (nPoints * sumXY - sumX * sumY) / (nPoints * sumX2 - sumX * sumX);
        double A = (sumY - b * sumX) / nPoints;
        a = std::exp(A);
    }

    double getSlope() const
    {
        return a;
    }

    double getIntercept() const
    {
        return b;
    }

private:
    unsigned int nPoints{5};
    std::vector<double> x{std::vector<double>(nPoints)}, y{std::vector<double>(nPoints)};
    double a{0.}, b{0.};
};

void testPolynomialFittingMethod();

#endif