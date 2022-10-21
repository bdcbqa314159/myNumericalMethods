#include "../include/myNM_bits/Simpson3_8Method.hpp"
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

    Simpson3_8Method mySolver(1, 3, 10000);
    double solution = mySolver(f);

    double exact = 0.25 * (pow(3, 4) - 1);
    ASSERT_APPROX_EQUAL(solution, exact, 0.01);
};

void testSimpson3_8Method()
{
    cout << "\nTesting the Simpson 3/8 Method for Numerical Integration" << endl;
    TEST(testWithSimpleFunction);
}