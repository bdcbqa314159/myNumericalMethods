#include "../include/myNM_bits/ExponentialFittingMethod.hpp"

using namespace std;

static void testWithSimpleFunction()
{
    vector<double> x = {0, 1, 2, 3, 4};
    vector<double> y = {3, 6, 12, 24, 48};

    ExponentialFittingMethod solver(x, y);
    solver();
    double exactSlope = 3;
    double exactIntercept = 2;

    ASSERT_APPROX_EQUAL(solver.getSlope(), exactSlope, 0.01);
    ASSERT_APPROX_EQUAL(solver.getIntercept(), exactIntercept, 0.01);
};

void testExponentialFittingMethod()
{
    cout << "\nTesting the Exponential Fitting Method with help from Linear Regression Method" << endl;
    TEST(testWithSimpleFunction);
}