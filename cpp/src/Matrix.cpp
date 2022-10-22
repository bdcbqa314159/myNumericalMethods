#include "../include/myNM_bits/Matrix.hpp"
#include "../include/myNM_bits/mathematics.hpp"

using namespace std;

static void testInitialization1()
{
    cout << "Default constructor" << endl;
    Matrix m;

    cout << "Lines dimension: " << m.getDimLines() << endl;
    cout << "Columns dimension: " << m.getDimColumns() << endl;
    vector<double> y = m.getData();

    cout << "data vide:" << endl;
    for (auto x : y)
        cout << x << " ";
    cout << endl;
}

static void testInitialization2()
{
    Matrix m(3, 2);

    cout << "Lines dimension: " << m.getDimLines() << endl;
    cout << "Columns dimension: " << m.getDimColumns() << endl;

    cout << "data: " << endl;

    for (int i = 0; i < m.getDimLines(); i++)
    {
        for (int j = 0; j < m.getDimColumns(); j++)
        {
            cout << m(i, j) << " ";
        }
        cout << endl;
    }

    cout << endl;
};

static void testInitialization3()
{

    vector<double> a1 = {1., 3., 5., 9.};
    vector<double> a2 = {4., 1., 12., 7.};
    vector<double> a3 = {1., 4., 5., 0.};
    vector<vector<double>> A = {a1, a2, a3};

    Matrix m(A);
    for (int i = 0; i < m.getDimLines(); i++)
    {
        for (int j = 0; j < m.getDimColumns(); j++)
        {
            cout << m(i, j) << " ";
        }
        cout << endl;
    }
};

static void testInitialization4()
{

    vector<double> a1 = {1., 3., 5., 9.};
    vector<double> a2 = {4., 1., 12., 7.};
    vector<double> a3 = {1., 4., 5., 0.};
    vector<vector<double>> A = {a1, a2, a3};

    Matrix m1(A);
    Matrix m2(m1);

    for (int i = 0; i < m1.getDimLines(); i++)
    {
        for (int j = 0; j < m1.getDimColumns(); j++)
        {
            ASSERT(m1(i, j) == m2(i, j));
        }
    }

    m1(0, 1) = 123.;
    ASSERT(m2(0, 1) == 3.);
    ASSERT(m1(0, 1) == 123.);
};

static void testInitialization5()
{

    vector<double> a1 = {1., 3., 5., 9.};
    vector<double> a2 = {4., 1., 12., 7.};
    vector<double> a3 = {1., 4., 5., 0.};
    vector<vector<double>> A = {a1, a2, a3};

    vector<double> b1 = {1., 2.};
    vector<double> b2 = {89., 12.};
    vector<vector<double>> B = {b1, b2};

    Matrix m1(A);
    Matrix m2(B);

    m1 = m2;

    for (int i = 0; i < m1.getDimLines(); i++)
    {
        for (int j = 0; j < m1.getDimColumns(); j++)
        {
            ASSERT(m1(i, j) == m2(i, j));
        }
    }
};

static void testInitialization6()
{

    vector<double> a1 = {1., 3., 5., 9.};
    vector<double> a2 = {4., 1., 12., 7.};
    vector<double> a3 = {1., 4., 5., 0.};
    vector<vector<double>> A = {a1, a2, a3};

    Matrix m(A);

    m.resize(3, 9);

    for (int i = 0; i < m.getDimLines(); i++)
    {
        for (int j = 0; j < m.getDimColumns(); j++)
        {
            ASSERT(m(i, j) == 0.);
        }
    }

    m.resize(2, 2);

    for (int i = 0; i < m.getDimLines(); i++)
    {
        for (int j = 0; j < m.getDimColumns(); j++)
        {
            ASSERT(m(i, j) == 0.);
        }
    }
};

void testMatrix()
{
    cout << "\nTesting the class Matrix for Linear Algebra" << endl;
    TEST(testInitialization1);
    TEST(testInitialization2);
    TEST(testInitialization3);
    TEST(testInitialization4);
    TEST(testInitialization5);
    TEST(testInitialization6);
}