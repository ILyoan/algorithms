#include "polynomial.h"

#include <cmath>
#include <vector>
using namespace std;

namespace math
{
namespace polynomial
{

// trim trailing zero
void trim(vector<int>& a)
{
    while (a.size() > 0 && a.back() == 0) a.pop_back();
}

// normalize `a` as if `a` is a `base` based number
void normalize(vector<int>& a, int base) 
{
    a.push_back(0);
    for (int i = 0; i < a.size(); i++) {
        if (a[i] < 0) {
            int borrow = (abs(a[i]) + base - 1) / base;
            a[i+1] -= borrow;
            a[i] += borrow * base;
        }
        else {
            a[i+1] += a[i] / base;
            a[i] %= base;
        }
    }
    trim(a);
}

// a = a + b*(10^k)
void addTo(vector<int>& a, const vector<int>& b, int k)
{
    if (a.size() < b.size() + k) a.resize(b.size() + k);
    for (int i = 0; i < b.size(); i++) a[i+k] += b[i];
}

// a = a + b
void addTo(vector<int>& a, const vector<int>& b)
{
    addTo(a, b, 0);
}


// a = a - b
// a must be greater than b
void subFrom(vector<int>& a, const vector<int>& b)
{
    for (int i = 0; i < b.size(); i++) a[i] -= b[i];
}

// c = a * b
vector<int> multiply(const vector<int>& a, const vector<int>& b)
{
    vector<int> c(a.size() + b.size() + 1, 0);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            c[i+j] += a[i] * b[j];
        }
    }
    trim(c);
    return c;
}

} // namespace polynomial
} // namespace math
