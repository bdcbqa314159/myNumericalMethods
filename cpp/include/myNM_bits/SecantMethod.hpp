#ifndef SECANT_METHOD
#define SECANT_METHOD

#include "standard.hpp"
#include "testing.hpp"
#include "RealFunction.hpp"

class SecantMethod
{
public:
    SecantMethod() {}

    SecantMethod(double tolerance, double a, double b) : tolerance(tolerance), a(a), b(b)
    {
        if (a >= b)
        {
            std::swap(a, b);
        }
    }

    double operator()(RealFunction &f)
    {
        double x_0{a}, x_1{b}, x_2{}, f_0{}, f_1{}, f_2{};
        int iterations{1};
        do
        {
            f_0 = f(x_0);
            f_1 = f(x_1);

            ASSERT(f_0 != f_1);

            x_2 = x_1 - (x_1 - x_0) * f_1 / (f_1 - f_0);
            f_2 = f(x_2);

            x_0 = x_1;
            x_1 = x_2;
            f_0 = f_1;
            f_1 = f_2;

        } while (std::abs(f_1) > tolerance);
        return x_2;
    }

private:
    double tolerance{1e-10}, a{0.}, b{1.};
    int threshold{10000};
};

void testSecantMethod();

#endif