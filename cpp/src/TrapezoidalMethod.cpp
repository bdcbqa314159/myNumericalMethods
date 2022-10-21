#include "../include/myNM_bits/TrapezoidalMethod.hpp"
#include "../include/myNM_bits/mathematics.hpp"

using namespace std;

static void testWithSimpleFunction()
{

    class myFunctionTest : public RealFunction
    {
    public:
        myFunctionTest() {}
        double operator()(double x) override
        {
            return x * x * x;
        }
    };

    myFunctionTest f;

    TrapezoidalMethod mySolver(1, 3, 1000);
    double solution = mySolver(f);

    double exact = 0.25 * (pow(3, 4) - 1);
    ASSERT_APPROX_EQUAL(solution, exact, 0.01);
};

void testTrapezoidalMethod()
{
    cout << "\nTesting the Trapezoidal Method for Numerical Integration" << endl;
    TEST(testWithSimpleFunction);
}