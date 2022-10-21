#ifndef SIMPSON_1_3_METHOD
#define SIMPSON_1_3_METHOD

#include "standard.hpp"
#include "testing.hpp"
#include "RealFunction.hpp"

class Simpson1_3Method
{
public:
    Simpson1_3Method() {}

    Simpson1_3Method(double a, double b, unsigned int nSteps) : a(a), b(b), nSteps(nSteps) {}

    double operator()(RealFunction &f)
    {
        double h = (b - a) / nSteps;
        double integral = f(a) + f(b);
        for (int i = 0; i < nSteps; i++)
        {
            double xi = a + i * h;
            if (i % 2 == 0)
            {
                integral += 2 * f(xi);
            }
            else
            {
                integral += 4 * f(xi);
            }
        }
        integral *= h / 3;

        return integral;
    }

private:
    unsigned int nSteps{1000};
    double a{0.}, b{1.};
};

void testSimpson1_3Method();

#endif