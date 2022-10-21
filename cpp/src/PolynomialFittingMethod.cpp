#include "../include/myNM_bits/PolynomialFittingMethod.hpp"

using namespace std;

static void testWithSimpleFunction()
{
    vector<double> x = {1, 2, 3, 4};
    vector<double> y = {4.9, 40.1, 134.9, 320.1};

    PolynomialFittingMethod solver(x, y);
    solver();
    double exactSlope = 4.92024;
    double exactIntercept = 3.01453;

    ASSERT_APPROX_EQUAL(solver.getSlope(), exactSlope, 0.01);
    ASSERT_APPROX_EQUAL(solver.getIntercept(), exactIntercept, 0.01);
};

void testPolynomialFittingMethod()
{
    cout << "\nTesting the Polynomial Fitting Method with help from Linear Regression Method" << endl;
    TEST(testWithSimpleFunction);
}