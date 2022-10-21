#ifndef NUMERICAL_DIFFERENTIATION
#define NUMERICAL_DIFFERENTIATION

#include "standard.hpp"
#include "RealFunction.hpp"

class NumericalDifferentiation
{
public:
    virtual ~NumericalDifferentiation() {}
    virtual std::vector<double> approximation(RealFunction &f, double a, double b) = 0;
};

#endif