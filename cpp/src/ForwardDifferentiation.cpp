#include "../include/myNM_bits/ForwardDifferentiation.hpp"
#include "../include/myNM_bits/testing.hpp"

using namespace std;

static void testWithSimpleFunction()
{

    class myFunctionTest : public RealFunction
    {
    public:
        double operator()(double x) override
        {
            return x * x - 2;
        }
    };

    myFunctionTest f;
    double a = 0., b = 2.;
    unsigned int N = 1000;

    vector<double> x = linspace(a, b, N);

    ForwardDifferentiation df(N);
    vector<double> y = df.approximation(f, a, b);

    auto trueSolution = [](double x)
    { return 2 * x; };

    for (int i = 0; i < N - 1; i++)
    {
        // cout << x[i] << " " << y[i] << " " << trueSolution(x[i]) << endl;
        ASSERT_APPROX_EQUAL(y[i], trueSolution(x[i]), 0.01);
    }
};

void testForwardDifferentiation()
{
    cout << "\nTesting the Forward Differenetiation Method." << endl;
    TEST(testWithSimpleFunction);
}