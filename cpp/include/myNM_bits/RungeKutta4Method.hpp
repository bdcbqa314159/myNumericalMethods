#ifndef RUNGE_KUTTA_4_METHOD
#define RUNGE_KUTTA_4_METHOD

#include "standard.hpp"
#include "testing.hpp"
#include "RealFunction2D.hpp"

class RungeKutta4Method
{
public:
    RungeKutta4Method() {}

    RungeKutta4Method(unsigned int nSteps, double x0, double y0) : nSteps(nSteps), x0(x0), y0(y0)
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
        double k1{}, k2{}, k3{}, k4{}, k{};

        for (int i = 1; i < nSteps; i++)
        {
            k1 = h * f(x0, y0);
            k2 = h * f((x0 + h / 2), (y0 + k1 / 2));
            k3 = h * f((x0 + h / 2), (y0 + k2 / 2));
            k4 = h * f((x0 + h), (y0 + k3));
            k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
            yn = y0 + k;

            x0 = x0 + h;
            y0 = yn;
            z[i] = yn;
        }
        return z;
    }

private:
    unsigned int nSteps{1000};
    double x0{0}, y0{1.};
    std::vector<double> z{std::vector<double>(nSteps)};
};

void testRungeKutta4Method();

#endif