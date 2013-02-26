#include "fft.h"

bool test_fft()
{
    vector<int> a;
    vector<int> b;
    for (int i = 0; i < 5; i++) a.push_back(i+1);
    for (int i = 0; i < 5; i++) b.push_back(i+1);

    FFT fft = FFT::createFFT(a, b);
    vector<int> c = fft.c;
    for (int i = 0; i < c.size(); i++) {
        printf("%d: %d\n", i, c[i]);
    }
    return true;
}

