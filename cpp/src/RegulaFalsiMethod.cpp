#include "../include/myNM_bits/RegulaFalsiMethod.hpp"

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
    RegulaFalsiMethod mySolver(tolerance, a, b);
    double answer = mySolver(f);

    ASSERT_APPROX_EQUAL(answer, sqrt(2), 0.001);
};

void testRegulaFalsiMethod()
{
    cout << "\nTesting the Regula Falsi Method" << endl;
    TEST(testWithSimpleFunction);
}