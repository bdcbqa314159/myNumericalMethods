#include <myNM>

using namespace std;

void testingSoftware()
{
    testStart();
    testTextFunctions();
    testLineChart();
    testMathematics();
    testHistogram();

    cout << "From this the project starts" << endl;
    cout << "Non Linear Solvers" << endl;
    testBissectionMethod();
    testRegulaFalsiMethod();
    testNewtonRaphsonMethod();
    testSecantMethod();
    testPointFixedMethod();

    cout << "Numerical Differentiation" << endl;
    testForwardDifferentiation();
    testBackwardDifferentiation();
    testCentralDifferentiation();

    cout << "Numerical Resolution of ODEs" << endl;
    testEulerMethod();
    testRungeKutta4Method();

    cout << "Numerical Integration" << endl;
    testTrapezoidalMethod();
    testSimpson1_3Method();
    testSimpson3_8Method();

    cout << "Linear Interpolation" << endl;
    testLinearInterpolationMethod();
    testLagrangeInterpolationMethod();

    cout << "Curve Fitting" << endl;
    testLinearInterpolationMethod();
    testPolynomialFittingMethod();
    testExponentialFittingMethod();
}

int main()
{

    testingSoftware();

    return 0;
}
