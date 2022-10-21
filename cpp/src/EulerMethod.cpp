#include "../include/myNM_bits/EulerMethod.hpp"
#include "../include/myNM_bits/mathematics.hpp"

using namespace std;

static void testWithSimpleFunction()
{

    class myFunctionTest : public RealFunction2D
    {
    public:
        myFunctionTest() {}
        myFunctionTest(double r) : r(r) {}
        double operator()(double x, double y) override
        {
            return r * y;
        }

    private:
        double r{1.};
    };

    myFunctionTest f;

    EulerMethod mySolver;
    double x = 1.;
    vector<double> solution = mySolver(x, f);

    vector<double> xi = linspace(0., 1., 1000);

    for (int i = 0; i < 1000; i++)
    {
        double exact = exp(1. * xi[i]);
        ASSERT_APPROX_EQUAL(solution[i], exact, 0.01);
    }
};

void testEulerMethod()
{
    cout << "\nTesting the ODE resolution with Euler Method" << endl;
    TEST(testWithSimpleFunction);
}