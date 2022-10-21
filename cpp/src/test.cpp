#include "../include/myNM_bits/test.hpp"
#include "../include/myNM_bits/standard.hpp"
#include "../include/myNM_bits/testing.hpp"

using namespace std;

static void message()
{
    cout << endl;
    cout << "myNumericalMethods project -> testing everything is OK!" << endl;
}

void testStart()
{
    TEST(message);
}
