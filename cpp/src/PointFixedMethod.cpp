#include "../include/myNM_bits/PointFixedMethod.hpp"

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

    class myAuxiliarFunctionTest : public RealFunction
    {
    public:
        double operator()(double x) override
        {
            return 0.5 * (2 / x + x);
        }
    };

    myFunctionTest f;
    myAuxiliarFunctionTest g;
    /*

    Framework: from f(x) = 0;
    We transform the equation into g(x) = x;
    IMPORTANT g must verify abs(dg(x))<1 and this must be checked with pen and paper. (Picard theorem)

    */

    double a = 0., b = 2.;
    double epsilon = 0.0001;
    double tolerance = 0.001;
    PointFixedMethod mySolver(tolerance, a + epsilon, b);
    double answer = mySolver(f, g);

    ASSERT_APPROX_EQUAL(answer, sqrt(2), 0.001);
};

void testPointFixedMethod()
{
    cout << "\nTesting the Point Fixed Method" << endl;
    TEST(testWithSimpleFunction);
}