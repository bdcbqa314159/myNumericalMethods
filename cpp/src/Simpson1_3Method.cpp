#include "../include/myNM_bits/Simpson1_3Method.hpp"
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

    Simpson1_3Method mySolver(1, 3, 1000);
    double solution = mySolver(f);

    double exact = 0.25 * (pow(3, 4) - 1);
    ASSERT_APPROX_EQUAL(solution, exact, 0.01);
};

void testSimpson1_3Method()
{
    cout << "\nTesting the Simpson 1/3 Method for Numerical Integration" << endl;
    TEST(testWithSimpleFunction);
}