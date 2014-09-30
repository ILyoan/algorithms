#include "kmp.h"

#include <vector>
using namespace std;

namespace sequences
{

vector<int> KMP::PartialMatch(const string& str)
{
    int n = str.size();
    vector<int> pi(n, 0);
    for (int i = 1, j = 0; i < n; ++i) {
        while (j > 0 && str[i] != str[j]) {
            j = pi[j-1];
        }
        if (str[i] == str[j]) {
            pi[i] = ++j;
        } else {
            pi[i] = j;
        }
    }
    return pi;
}


vector<int> KMP::FindMatch(const string& str, const string& pattern)
{
    int n = str.size();
    int m = pattern.size();
    vector<int> pi = PartialMatch(pattern);
    vector<int> res;
    for (int i = 0, j = 0; i < n; ++i) {
        while (j > 0 && str[i] != pattern[j]) {
            j = pi[j-1];
        }
        if (str[i] == pattern[j]) {
            ++j;
            if (j == m) {
                res.push_back(i-m+1);
                j = pi[j-1];
            }
        }
    }
    return res;
}


vector<int> KMP::PrefixSuffix(const string& str)
{
    vector<int> res;
    vector<int> pi = PartialMatch(str);
    int n = str.size();
    while (n > 0) {
        res.push_back(n);
        n = pi[n-1];
    }
    return res;
}


int KMP::MaxOverlap(const string& a, const string& b)
{
    int n = a.size();
    int m = b.size();
    vector<int> pi = PartialMatch(b);
    vector<int> res;
    int i = 0, j = 0;
    while (i < n) {
        while (j > 0 && a[i] != b[j]) {
            j = pi[j-1];
        }
        if (a[i] == b[j]) {
            ++j;
            if (j == m && i < n - 1) {
                j = pi[j-1];
            }
        }
        ++i;
    }
    return j;
}

} // namespace sequences
