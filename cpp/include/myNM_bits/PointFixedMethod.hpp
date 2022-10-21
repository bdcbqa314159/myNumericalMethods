#ifndef POINT_FIXED_METHOD
#define POINT_FIXED_METHOD

#include "standard.hpp"
#include "testing.hpp"
#include "RealFunction.hpp"

class PointFixedMethod
{
public:
    PointFixedMethod() {}

    PointFixedMethod(double tolerance, double a, double b) : tolerance(tolerance), a(a), b(b)
    {
        if (a >= b)
        {
            std::swap(a, b);
        }
    }

    double operator()(RealFunction &f, RealFunction &g)
    {
        double x_0{a}, x_1{};
        int iterations{1};
        do
        {
            x_1 = g(x_0);
            iterations++;
            ASSERT(iterations <= threshold);
            x_0 = x_1;

        } while (f(x_1) > tolerance);
        return x_1;
    }

private:
    double tolerance{1e-10}, a{0.}, b{1.};
    int threshold{10000};
};

void testPointFixedMethod();

#endif