#include "../include/myNM_bits/LinearRegressionMethod.hpp"

using namespace std;

static void testWithSimpleFunction()
{
    vector<double> x = {0, 2, 5, 7};
    vector<double> y = {-1, 5, 12, 20};

    LinearRegressionMethod solver(x, y);
    solver();
    double exactSlope = 2.89655;
    double exactIntercept = -1.13793;

    ASSERT_APPROX_EQUAL(solver.getSlope(), exactSlope, 0.01);
    ASSERT_APPROX_EQUAL(solver.getIntercept(), exactIntercept, 0.01);
};

void testLinearRegressionMethod()
{
    cout << "\nTesting the Linear Regression Method" << endl;
    TEST(testWithSimpleFunction);
}