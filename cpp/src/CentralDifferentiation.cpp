#include "../include/myNM_bits/CentralDifferentiation.hpp"
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

    CentralDifferentiation df(N);
    vector<double> y = df.approximation(f, a, b);

    auto trueSolution = [](double x)
    { return 2 * x; };

    // double y_obj{};
    for (int i = 1; i < N - 1; i++)
    {
        // y_obj = trueSolution(x[i]);
        // cout << x[i] << " " << y[i - 1] << " " << y_obj << " " << abs(y[i - 1] - y_obj) << endl;
        ASSERT_APPROX_EQUAL(y[i - 1], trueSolution(x[i]), 0.01);
    }
};

void testCentralDifferentiation()
{
    cout << "\nTesting the Central Differenetiation Method." << endl;
    TEST(testWithSimpleFunction);
}