#include "../include/myNM_bits/LagrangeInterpolationMethod.hpp"

using namespace std;

static void testWithSimpleFunction()
{
    vector<double> xTest = {5, 7, 11, 13, 17};
    vector<double> yTest = {150, 392, 1452, 2366, 5202};
    LagrangeInterpolationMethod myInterpolator(xTest, yTest);
    double solution = myInterpolator(9);
    double exact = 810;
    ASSERT_APPROX_EQUAL(solution, exact, 0.01);
};

void testLagrangeInterpolationMethod()
{
    cout << "\nTesting the Lagrange Interpolation Method" << endl;
    TEST(testWithSimpleFunction);
}