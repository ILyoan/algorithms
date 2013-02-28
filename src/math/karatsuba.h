#ifndef ILYOAN_ALGORITHMS_MATH_KARATSUBA_H
#define ILYOAN_ALGORITHMS_MATH_KARATSUBA_H

#include "polynomial.h"
#include <vector>
using namespace std;

namespace math 
{
namespace polynomial
{

vector<int> karatsuba(const vector<int>& a, const vector<int>& b)
{
    int alen = a.size();
    int blen = b.size();
    if (alen == 0 || blen == 0) return vector<int>();
    if (alen < blen) return karatsuba(b, a);
    if (alen < 50) return multiply(a, b);

    int half = alen / 2;
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(blen, half));
    vector<int> b1(b.begin() + min<int>(blen, half), b.end());

    vector<int> z0 = karatsuba(a0, b0);
    vector<int> z2 = karatsuba(a1, b1);
    addTo(a0, a1);
    addTo(b0, b1);
    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);

    vector<int> res;
    addTo(res, z0);
    addTo(res, z1, half);
    addTo(res, z2, half + half);
    
    trim(res);
    return res;
}

} // namespace polynomial
} // namespace math

#endif
