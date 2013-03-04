#ifndef ILYOAN_ALGORITHMS_MATH_FFT_H
#define ILYOAN_ALGORITHMS_MATH_FFT_H

#include "polynomial.h"
#include <vector>
using namespace std;

typedef long long int64;

namespace math
{
namespace polynomial
{

// This FFT is unsigned int version
// All of the coefficents must be >= 0
class FFT
{
public:
    vector<int64> w;
    vector<int> leaf;
    vector<int> a, b, c;
    vector<int> A, B, C;
    int n;

public:
    static FFT createFFT(vector<int>& u, vector<int>& v);
    
    FFT(int _n);

    void prepareLeaf();
    void prepareLeaf(int n, int r, int a, int b);
    void dft(vector<int>& u, vector<int>& v);
    void idft(vector<int>& u, vector<int>& v);
    void fft();
};

} // namespace polynomial
} // namespace math
#endif
