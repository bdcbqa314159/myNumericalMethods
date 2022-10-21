#include "../include/myNM_bits/NewtonRaphsonMethod.hpp"

using namespace std;

static void testWithSimpleFunction()
{

    class myFunctionTest : public RealFunction
    {
    public:
        double operator()(double x) override
        {
            return x * x - 2;
        }
    };

    class myDerivativeFunctionTest : public RealFunction
    {
    public:
        double operator()(double x) override
        {
            return 2 * x;
        }
    };

    myFunctionTest f;
    myDerivativeFunctionTest df;
    double a = 0., b = 2.;
    double tolerance = 0.001;
    NewtonRaphsonMethod mySolver(tolerance, a, b);
    double answer = mySolver(f, df);

    ASSERT_APPROX_EQUAL(answer, sqrt(2), 0.001);
};

void testNewtonRaphsonMethod()
{
    cout << "\nTesting the Newton Raphson Method" << endl;
    TEST(testWithSimpleFunction);
}