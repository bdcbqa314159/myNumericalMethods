#include "../include/myNM_bits/BissectionMethod.hpp"

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
    BissectionMethod mySolver(tolerance, a, b);
    double answer = mySolver(f);

    ASSERT_APPROX_EQUAL(answer, sqrt(2), 0.001);
};

void testBissectionMethod()
{
    cout << "\nTesting the Bissection Method" << endl;
    TEST(testWithSimpleFunction);
}