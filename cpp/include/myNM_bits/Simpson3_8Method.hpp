#ifndef SIMPSON_3_8_METHOD
#define SIMPSON_3_8_METHOD

#include "standard.hpp"
#include "testing.hpp"
#include "RealFunction.hpp"

class Simpson3_8Method
{
public:
    Simpson3_8Method() {}

    Simpson3_8Method(double a, double b, unsigned int nSteps) : a(a), b(b), nSteps(nSteps) {}

    double operator()(RealFunction &f)
    {
        double h = (b - a) / nSteps;
        double integral = f(a) + f(b);
        double coefficient{3. / 8};
        for (int i = 0; i < nSteps; i++)
        {
            double xi = a + i * h;
            if (i % 3 == 0)
            {
                integral += 2 * f(xi);
            }
            else
            {
                integral += 3 * f(xi);
            }
        }
        integral *= coefficient * h;

        return integral;
    }

private:
    unsigned int nSteps{1000};
    double a{0.}, b{1.};
};

void testSimpson3_8Method();

#endif