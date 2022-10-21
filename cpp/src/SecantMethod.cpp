#include "../include/myNM_bits/SecantMethod.hpp"

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

    myFunctionTest f;

    double a = 0., b = 2.;
    double tolerance = 0.001;
    SecantMethod mySolver(tolerance, a, b);
    double answer = mySolver(f);

    ASSERT_APPROX_EQUAL(answer, sqrt(2), 0.001);
};

void testSecantMethod()
{
    cout << "\nTesting the Secant Method" << endl;
    TEST(testWithSimpleFunction);
}