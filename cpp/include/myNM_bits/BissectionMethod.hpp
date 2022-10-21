#ifndef BISSECTION_METHOD
#define BISSECTION_METHOD

#include "RealFunction.hpp"
#include "testing.hpp"

class BissectionMethod
{
public:
    BissectionMethod() {}

    BissectionMethod(double tolerance, double a, double b) : tolerance(tolerance), a(a), b(b)
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
            x = 0.5 * (x_0 + x_1);
            f = function(x);

            if (f_0 * f < 0.)
            {
                x_1 = x;
            }
            else
            {
                x_0 = x;
            }

            iterations++;
            f_0 = function(x_0);
            f_1 = function(x_1);

        } while (std::fabs(f) > tolerance);
        return x;
    }

private:
    double tolerance{1e-10}, a{0.}, b{1.};
};

void testBissectionMethod();

#endif