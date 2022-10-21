#ifndef TRAPEZOIDAL_METHOD
#define TRAPEZOIDAL_METHOD

#include "standard.hpp"
#include "testing.hpp"
#include "RealFunction.hpp"

class TrapezoidalMethod
{
public:
    TrapezoidalMethod() {}

    TrapezoidalMethod(double a, double b, unsigned int nSteps) : a(a), b(b), nSteps(nSteps) {}

    double operator()(RealFunction &f)
    {
        double h = (b - a) / nSteps;
        double integral = f(a) + f(b);
        for (int i = 0; i < nSteps; i++)
        {
            double xi = a + i * h;
            integral += 2 * f(xi);
        }
        integral *= h / 2;

        return integral;
    }

private:
    unsigned int nSteps{1000};
    double a{0.}, b{1.};
};

void testTrapezoidalMethod();

#endif