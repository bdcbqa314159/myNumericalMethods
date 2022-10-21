#ifndef NEWTON_RAPHSON_METHOD
#define NEWTON_RAPHSON_METHOD

#include "standard.hpp"
#include "testing.hpp"
#include "RealFunction.hpp"

class NewtonRaphsonMethod
{
public:
    NewtonRaphsonMethod() {}

    NewtonRaphsonMethod(double tolerance, double a, double b) : tolerance(tolerance), a(a), b(b)
    {
        if (a >= b)
        {
            std::swap(a, b);
        }
        initialGuess = 0.5 * (a + b);
    }

    double operator()(RealFunction &f, RealFunction &df)
    {
        double x_0{initialGuess}, x_1{}, f_0{}, f_1{}, df_0{};
        int iterations{1};
        do
        {
            f_0 = f(x_0);
            df_0 = df(x_0);
            ASSERT(df_0 != 0.);

            x_1 = x_0 - f_0 / df_0;
            x_0 = x_1;

            iterations++;
            ASSERT(iterations <= threshold);

            f_1 = f_0;

        } while (std::abs(f_1) > tolerance);
        return x_1;
    }

private:
    double tolerance{1e-10}, a{0.}, b{1.};
    int threshold{10000};
    double initialGuess{0.5};
};

void testNewtonRaphsonMethod();

#endif