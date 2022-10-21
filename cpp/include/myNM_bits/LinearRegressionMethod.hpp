#ifndef LINEAR_REGRESSION_METHOD
#define LINEAR_REGRESSION_METHOD

#include "standard.hpp"
#include "testing.hpp"

class LinearRegressionMethod
{
public:
    LinearRegressionMethod() {}

    LinearRegressionMethod(std::vector<double> x, std::vector<double> y) : x(x), y(y)
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
            sumY += y[i];
            sumXY += x[i] * y[i];
            sumX2 += x[i] * x[i];
        }

        b = (nPoints * sumXY - sumX * sumY) / (nPoints * sumX2 - sumX * sumX);
        a = (sumY - b * sumX) / nPoints;
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

void testLinearRegressionMethod();

#endif