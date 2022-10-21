#include "../include/myNM_bits/LinearInterpolationMethod.hpp"

using namespace std;

static void testWithSimpleFunction()
{
    LinearInterpolationMethod myInterpolator;
    double solution = myInterpolator(0.5);
    double exact = 0.5;
    ASSERT_APPROX_EQUAL(solution, exact, 0.01);
};

void testLinearInterpolationMethod()
{
    cout << "\nTesting the Linear Interpolation Method" << endl;
    TEST(testWithSimpleFunction);
}