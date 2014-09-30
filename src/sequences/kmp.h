#ifndef ILYOAN_ALGORITHMS_SEQUENCES_KMP_H
#define ILYOAN_ALGORITHMS_SEQUENCES_KMP_H

#include <vector>
using namespace std;

namespace sequences
{

class KMP
{
public:
    // Returns a vector A s.t. A[i] is length of the longest substring
    // that is prefix and also suffix of 'str[..i]`.
    static vector<int> PartialMatch(const string& str);
    // Returns a vector of matching indices of `str` with `pattern`.
    static vector<int> FindMatch(const string& str, const string& pattern);
    // Returns a vector of lengths of substring that is prefix and also surfix of `str`.
    static vector<int> PrefixSuffix(const string& str);
    // Returns length of the longest substring that is suffix of `a and prefix of `b`.
    static int MaxOverlap(const string& a, const string& b);
};

} // namespace sequences

#endif
