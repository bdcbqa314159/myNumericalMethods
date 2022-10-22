#include "../include/myNM_bits/Vector.hpp"
#include "../include/myNM_bits/mathematics.hpp"

using namespace std;

static void testInitialization1()
{
    cout << "Default constructor" << endl;
    Vector v;

    cout << "dimension: " << v.getSize() << endl;
    vector<double> y = v.getData();

    cout << "data vide:" << endl;
    for (auto x : y)
        cout << x << " ";
    cout << endl;
}
static void testInitialization2()
{
    Vector v(10);

    cout << "dimension: " << v.getSize() << endl;
    cout << "data: " << endl;
    for (auto x : v.getData())
    {
        cout << x << " ";
    }
    cout << endl;
};

static void testInitialization3()
{

    vector<double> test = {1., 3., 5., 9.};

    Vector v(test);

    ASSERT(v.getSize() == test.size());
    for (int i = 0; i < test.size(); i++)
    {
        ASSERT(v[i] == test[i]);
    }
};

static void testInitialization4()
{

    vector<double> test = {1., 3., 5., 9.};
    // vector<double> test1 = {1., 3., 13., 999.};

    Vector v(test);
    Vector v1(v);

    ASSERT(v.getSize() == v1.getSize());
    for (int i = 0; i < v.getSize(); i++)
    {
        ASSERT(v[i] == v1[i]);
    }

    v[0] = 34.;
    ASSERT(v[0] == 34.);
    ASSERT(v1[0] == 1.);
};

static void testInitialization5()
{

    vector<double> test = {1., 3., 5.};
    vector<double> test1 = {1., 3., 13., 999.};

    Vector v(test);
    Vector v1(test1);

    v = v1;

    ASSERT(v.getSize() == v1.getSize() && v.getSize() == 4);

    for (int i = 0; i < v.getSize(); i++)
    {
        ASSERT(v[i] == v1[i]);
    }
};

static void testInitialization6()
{

    vector<double> test = {1., 3., 5.};
    vector<double> test1 = {1., 3., 13., 999.};

    Vector v(test);
    Vector v1(test1);

    v = v1;

    ASSERT(v.getSize() == v1.getSize() && v.getSize() == 4);

    for (int i = 0; i < v.getSize(); i++)
    {
        ASSERT(v[i] == v1[i]);
    }

    v1[2] = 345.;
    ASSERT(v1[2] == 345.);
};

static void testInitialization7()
{

    vector<double> test = {1., 3., 13., 999.};

    Vector v(test);

    v.resize(10);

    for (int i = 0; i < v.getSize(); i++)
    {
        cout << v[i] << endl;
        // ASSERT(v[i] == 0.);
    }

    v.resize(2);
    for (int i = 0; i < v.getSize(); i++)
    {
        ASSERT(v[i] == 0.);
    }
};

void testVector()
{
    cout << "\nTesting the class Vector for Linear Algebra" << endl;
    TEST(testInitialization1);
    TEST(testInitialization2);
    TEST(testInitialization3);
    TEST(testInitialization4);
    TEST(testInitialization5);
    TEST(testInitialization6);
    TEST(testInitialization7);
}