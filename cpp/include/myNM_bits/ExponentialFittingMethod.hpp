#ifndef EXPONENTIAL_FITTING_METHOD
#define EXPONENTIAL_FITTING_METHOD

#include "standard.hpp"
#include "testing.hpp"

class ExponentialFittingMethod
{
public:
    ExponentialFittingMethod() {}

    ExponentialFittingMethod(std::vector<double> x, std::vector<double> y) : x(x), y(y)
    {
        ASSERT(x.size() == y.size());
        nPoints = x.size();
    }

    void operator()()
    {
        double sumX{}, sumX2{}, sumY{}, sumXY{};
        for (int i = 0; i < nPoints; i++)
        {
            sumX += x[i];
            sumY += std::log(y[i]);
            sumXY += x[i] * log(y[i]);
            sumX2 += x[i] * x[i];
        }

        double B = (nPoints * sumXY - sumX * sumY) / (nPoints * sumX2 - sumX * sumX);
        double A = (sumY - B * sumX) / nPoints;
        a = std::exp(A);
        b = std::exp(B);
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

void testExponentialFittingMethod();

#endif