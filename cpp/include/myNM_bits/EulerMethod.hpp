#ifndef EULER_METHOD
#define EULER_METHOD

#include "standard.hpp"
#include "testing.hpp"
#include "RealFunction2D.hpp"

class EulerMethod
{
public:
    EulerMethod() {}

    EulerMethod(unsigned int nSteps, double x0, double y0) : nSteps(nSteps), x0(x0), y0(y0)
    {
        z.resize(nSteps);
        ASSERT(nSteps >= 1);
        z[0] = y0;
    }

    std::vector<double> operator()(double x, RealFunction2D &f)
    {
        double h = (x - x0) / nSteps;
        double yn{};
        ASSERT(nSteps >= 1);
        z[0] = y0;
        for (int i = 1; i < nSteps; i++)
        {

            yn = y0 + h * f(x0, y0);
            y0 = yn;
            x0 += h;
            z[i] = yn;
        }

        return z;
    }

private:
    unsigned int nSteps{1000};
    double x0{0}, y0{1.};
    std::vector<double> z{std::vector<double>(nSteps)};
};

void testEulerMethod();

#endif