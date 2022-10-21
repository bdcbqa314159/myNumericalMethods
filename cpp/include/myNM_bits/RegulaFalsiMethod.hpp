#ifndef REGULA_FALSI_METHOD
#define REGULA_FALSI_METHOD

#include "standard.hpp"
#include "testing.hpp"
#include "RealFunction.hpp"

class RegulaFalsiMethod
{
public:
    RegulaFalsiMethod() {}

    RegulaFalsiMethod(double tolerance, double a, double b) : tolerance(tolerance), a(a), b(b)
    {
        if (a >= b)
        {
            std::swap(a, b);
        }
    }

    double operator()(RealFunction &function)
    {
        double f_0{function(a)}, f_1{function(b)};
        double x_0 = a, x_1 = b;
        double f{}, x{};
        int iterations{};
        ASSERT(f_0 * f_1 < 0.);

        do
        {
            x = x_0 - (x_0 - x_1) * f_0 / (f_0 - f_1);
            f = function(x);

            if (f_0 * f < 0.)
            {
                x_1 = x;
                f_1 = f;
            }
            else
            {
                x_0 = x;
                f_0 = f;
            }

            iterations++;

        } while (std::fabs(f) > tolerance);
        return x;
    }

private:
    double tolerance{1e-10}, a{0.}, b{1.};
};

void testRegulaFalsiMethod();

#endif