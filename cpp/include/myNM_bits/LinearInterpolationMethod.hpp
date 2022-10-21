#ifndef LINEAR_INTERPOLATION_METHOD
#define LINEAR_INTERPOLATION_METHOD

#include "standard.hpp"
#include "testing.hpp"
#include "RealFunction.hpp"

class LinearInterpolationMethod
{
public:
    LinearInterpolationMethod() {}

    LinearInterpolationMethod(double x0, double x1, double y0, double y1) : x0{x0}, x1{x1}, y0{y0}, y1{y1} {}

    double operator()(double x)
    {
        ASSERT(x > x0 && x < x1);
        double y = y0 + (x - x0) * (y1 - y0) / (x1 - x0);
        return y;
    }

private:
    double x0{0.}, x1{1.}, y0{0.}, y1{1.};
};

void testLinearInterpolationMethod();

#endif