#include "fft.h"

using namespace math;
using namespace polynomial;

static const int MOD = 2013265921;
static const int G = 31;
static const int BINV = 1006632961;

int pow(int a, int r, int mod)
{
    if (r == 0) return 1;
    if (r == 1) return a;
    int64 res = pow(a, r / 2, mod);
    res = (res * res) % mod;
    if (r & 1) res = (res * a) % MOD;
    return (int)res;
}

FFT FFT::createFFT(vector<int>& u, vector<int>& v)
{
    int n = 1;
    int len = max(u.size(), v.size());
    while (n < len) n *= 2;
    n *= 2;
    FFT fft(n);
    for (int i = 0; i < u.size(); i++) fft.a[i] = u[i];
    for (int i = 0; i < v.size(); i++) fft.b[i] = v[i];
    fft.fft();
    return fft;
}


FFT::FFT(int _n) : n(_n)
        , w(_n, 0), leaf(_n, 0)
        , a(_n, 0), b(_n, 0), c(_n, 0)
        , A(_n, 0), B(_n, 0), C(_n, 0)
{
    prepareLeaf();
}

void FFT::prepareLeaf()
{
    prepareLeaf(this->n, 1, 0, 0);
}

void FFT::prepareLeaf(int n, int r, int a, int b)
{
    if (n == 1) this->leaf[a] = b;
    else {
        prepareLeaf(n >> 1, r << 1, a << 1, b);
        prepareLeaf(n >> 1, r << 1, 1 + (a << 1), b + r);
    }
}

void FFT::dft(vector<int>& u, vector<int>& v)
{
    int n = this->n;
    for (int i = 0; i < n; i++) {
        v[i] = u[this->leaf[i]];
    }
    for (int len = 1; len < n; len *= 2) {
        int step = n / (len + len);
        for (int i = 0; i < n; i += len+len) {
            for (int j = 0, k = 0; j < len; j++) {
                int64 L = v[i + j];
                int64 R = v[i + j + len] * this->w[k];
                v[i + j] = (L + R) % MOD;
                v[i + j + len] = (L - R) % MOD;
                k = (k + step) & (n - 1);
            }
        }
    }
}

void FFT::idft(vector<int>& u, vector<int>& v) {
    int n = this->n;
    for (int i = 0; i < n; i++) {
        v[i] = u[this->leaf[i]];
    }
    for (int len = 1; len < n; len *= 2) {
        int step = n - n / (len + len);
        for (int i = 0; i < n; i += len+len) {
            for (int j = 0, k = 0; j < len; j++) {
                int64 L = v[i + j];
                int64 R = v[i + j + len] * this->w[k];
                v[i + j] = (L + R) % MOD;
                v[i + j + len] = (L - R) % MOD;
                k = (k + step) & (n - 1);
            }
        }
    }
    int64 INV = 1;
    for (int i = 1; i != n; i *= 2) INV = (INV * BINV) % MOD;
    for (int i = 0; i < n; i++) v[i] = (v[i] * INV) % MOD;
}

void FFT::fft()
{
    int n = this->n;
    int64 W = pow(G, (MOD-1) / n, MOD);
    this->w[0] = 1;
    for (int i = 1; i < n; i++) {
        this->w[i] = this->w[i-1] * W % MOD;
    }
    dft(this->a, this->A);
    dft(this->b, this->B);
    for (int i = 0; i < n; i++) {
        this->C[i] = ((int64)this->A[i] * this->B[i]) % MOD;
    }
    idft(this->C, this->c);
    for (int i = 0; i < n; i++) {
        if (this->c[i] < 0) this->c[i] += MOD;
    }
    trim(this->c);
}
