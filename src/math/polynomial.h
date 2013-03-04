#ifndef ILYOAN_ALGORITHMS_MATH_POLYNOMIAL_H
#define ILYOAN_ALGORITHMS_MATH_POLYNOMIAL_H

#include <vector>
using namespace std;

namespace math
{
namespace polynomial
{

// trim trailing zero
void trim(vector<int>& a);

// normalize `a` as if `a` is a `base` based number
void normalize(vector<int>& a, int base);

// a = a + b*(10^k)
void addTo(vector<int>& a, const vector<int>& b, int k);

// a = a + b
void addTo(vector<int>& a, const vector<int>& b);

// a = a - b
// a must be greater than b
void subFrom(vector<int>& a, const vector<int>& b);

// c = a * b
vector<int> multiply(const vector<int>& a, const vector<int>& b);

// karatsuba algorithm
vector<int> karatsuba(const vector<int>& a, const vector<int>& b);

} // namespace polynomial
} // namespace math
#endif
